//
// OmeroReader.java
//

/*
OME database I/O package for communicating with OME and OMERO servers.
Copyright (C) 2005-@year@ Melissa Linkert, Curtis Rueden and Philip Huettl.

This program is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*/

package loci.ome.io;

import Glacier2.CannotCreateSessionException;
import Glacier2.PermissionDeniedException;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

import loci.formats.FormatException;
import loci.formats.FormatReader;
import loci.formats.FormatTools;
import loci.formats.MetadataTools;
import loci.formats.meta.MetadataStore;
import loci.formats.tools.ImageInfo;
import omero.ServerError;
import omero.api.GatewayPrx;
import omero.api.RawPixelsStorePrx;
import omero.api.ServiceFactoryPrx;
import omero.model.Image;
import omero.model.Pixels;

/**
 * Implementation of {@link loci.formats.IFormatReader}
 * for use in export from an OMERO Beta 4.2.x database.
 *
 * <dl><dt><b>Source code:</b></dt>
 * <dd><a href="http://dev.loci.wisc.edu/trac/java/browser/trunk/components/ome-io/src/loci/ome/io/OmeroReader.java">Trac</a>,
 * <a href="http://dev.loci.wisc.edu/svn/java/trunk/components/ome-io/src/loci/ome/io/OmeroReader.java">SVN</a></dd></dl>
 */
public class OmeroReader extends FormatReader {

  // -- Constants --

  public static final int DEFAULT_PORT = 4064;

  // -- Fields --

  private String server;
  private String username;
  private String password;
  private int thePort = DEFAULT_PORT;

  private RawPixelsStorePrx store;
  private Pixels pix;

  // -- Constructors --

  public OmeroReader() {
    super("OMERO", "*");
  }

  // -- OmeroReader methods --

  public void setServer(String server) {
    this.server = server;
  }

  public void setPort(int port) {
    thePort = port;
  }

  public void setUsername(String username) {
    this.username = username;
  }

  public void setPassword(String password) {
    this.password = password;
  }

  // -- IFormatReader methods --

  @Override
  public boolean isThisType(String name, boolean open) {
    return name.startsWith("omero:");
  }

  @Override
  public byte[] openBytes(int no, byte[] buf, int x1, int y1, int w1, int h1)
    throws FormatException, IOException
  {
    FormatTools.assertId(currentId, true, 1);
    FormatTools.checkPlaneNumber(this, no);
    FormatTools.checkBufferSize(this, buf.length);

    final int[] zct = FormatTools.getZCTCoords(this, no);

    final byte[] plane;
    try {
      plane = store.getPlane(zct[0], zct[1], zct[2]);
    }
    catch (ServerError e) {
      throw new FormatException(e);
    }

    final int len = getSizeX() * getSizeY() *
      FormatTools.getBytesPerPixel(getPixelType());
    System.arraycopy(plane, 0, buf, 0, len);

    return buf;
  }

  @Override
  public void close() throws IOException {
    super.close();
    // TODO close last session
  }

  @Override
  protected void initFile(String id) throws FormatException, IOException {
    LOGGER.debug("OmeroReader.initFile({})", id);

    super.initFile(id);

    if (!id.startsWith("omero:")) {
      throw new IllegalArgumentException("Not an OMERO id: " + id);
    }

    // parse credentials from id string

    LOGGER.info("Parsing credentials");

    String address = server, user = username, pass = password;
    int port = thePort;
    long pid = -1;

    final String[] tokens = id.substring(6).split("\n");
    for (String token : tokens) {
      final int equals = token.indexOf("=");
      if (equals < 0) continue;
      final String key = token.substring(0, equals);
      final String val = token.substring(equals + 1);
      if (key.equals("server")) address = val;
      else if (key.equals("user")) user = val;
      else if (key.equals("pass")) pass = val;
      else if (key.equals("port")) {
        try {
          port = Integer.parseInt(val);
        }
        catch (NumberFormatException exc) { }
      }
      else if (key.equals("pid")) {
        try {
          pid = Long.parseLong(val);
        }
        catch (NumberFormatException exc) { }
      }
    }

    if (address == null) {
      throw new FormatException("Invalid server address");
    }
    if (user == null) {
      throw new FormatException("Invalid username");
    }
    if (pass == null) {
      throw new FormatException("Invalid password");
    }
    if (pid < 0) {
      throw new FormatException("Invalid pixels ID");
    }

    try {
      // authenticate with OMERO server

      LOGGER.info("Logging in");

      omero.client client = new omero.client(server, port);
      final ServiceFactoryPrx serviceFactory = client.createSession(user, pass);

      // get raw pixels store and pixels

      store = serviceFactory.createRawPixelsStore();
      store.setPixelsId(pid, false);

      final GatewayPrx gateway = serviceFactory.createGateway();
      pix = gateway.getPixels(pid);
      final int sizeX = pix.getSizeX().getValue();
      final int sizeY = pix.getSizeY().getValue();
      final int sizeZ = pix.getSizeZ().getValue();
      final int sizeC = pix.getSizeC().getValue();
      final int sizeT = pix.getSizeT().getValue();
      final String pixelType = pix.getPixelsType().getValue().getValue();

      // populate metadata

      LOGGER.info("Populating metadata");

      core[0].sizeX = sizeX;
      core[0].sizeY = sizeY;
      core[0].sizeZ = sizeZ;
      core[0].sizeC = sizeC;
      core[0].sizeT = sizeT;
      core[0].rgb = false;
      core[0].littleEndian = false;
      core[0].dimensionOrder = "XYZCT";
      core[0].imageCount = sizeZ * sizeC * sizeT;
      core[0].pixelType = FormatTools.pixelTypeFromString(pixelType);

      // CTR TODO this is wrong
      double px = pix.getSizeX().getValue();
      double py = pix.getSizeY().getValue();
      double pz = pix.getSizeZ().getValue();

      Image image = pix.getImage();

      String name = image.getName().getValue();
      String description = image.getDescription().getValue();

      MetadataStore store = getMetadataStore();
      store.setImageName(name, 0);
      store.setImageDescription(description, 0);
      MetadataTools.populatePixels(store, this);

      store.setPixelsPhysicalSizeX(new Double(px), 0);
      store.setPixelsPhysicalSizeY(new Double(py), 0);
      store.setPixelsPhysicalSizeZ(new Double(pz), 0);
    }
    catch (CannotCreateSessionException e) {
      throw new FormatException(e);
    }
    catch (PermissionDeniedException e) {
      throw new FormatException(e);
    }
    catch (ServerError e) {
      throw new FormatException(e);
    }
  }

  /** A simple command line tool for downloading images from OMERO. */
  public static void main(String[] args) throws Exception {
    // parse OMERO credentials
    BufferedReader con = new BufferedReader(new InputStreamReader(System.in));

    System.out.print("Server? ");
    final String server = con.readLine();

    System.out.printf("Port [%d]? ", DEFAULT_PORT);
    final String portString = con.readLine();
    final int port = portString.equals("") ? DEFAULT_PORT :
      Integer.parseInt(portString);

    System.out.print("Username? ");
    final String user = con.readLine();

    System.out.print("Password? ");
    final String pass = new String(con.readLine());

    System.out.print("Pixels ID? ");
    final int pixelsId = Integer.parseInt(con.readLine());
    System.out.print("\n\n");

    // construct the OMERO reader
    final OmeroReader omeroReader = new OmeroReader();
    omeroReader.setUsername(user);
    omeroReader.setPassword(pass);
    omeroReader.setServer(server);
    omeroReader.setPort(port);
    final String id = "omero:pid=" + pixelsId;
    omeroReader.setId(id);
    omeroReader.close();

    // delegate the heavy lifting to Bio-Formats ImageInfo utility
    final ImageInfo imageInfo = new ImageInfo();
    imageInfo.setReader(omeroReader); // override default image reader
    if (!imageInfo.testRead(args)) System.exit(1);
  }

}
