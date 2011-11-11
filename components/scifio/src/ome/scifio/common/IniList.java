//
// IniList.java
//

/*
LOCI Common package: utilities for I/O, reflection and miscellaneous tasks.
Copyright (C) 2005-@year@ Melissa Linkert, Curtis Rueden and Chris Allan.

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

package ome.scifio.common;

import java.util.ArrayList;
import java.util.HashMap;

/**
 * A data structure containing a parsed list of INI key/value tables.
 *
 * <dl><dt><b>Source code:</b></dt>
 * <dd><a href="http://trac.openmicroscopy.org.uk/ome/browser/bioformats.git/components/common/src/loci/common/IniList.java">Trac</a>,
 * <a href="http://git.openmicroscopy.org/?p=bioformats.git;a=blob;f=components/common/src/loci/common/IniList.java;hb=HEAD">Gitweb</a></dd></dl>
 *
 * @author Curtis Rueden ctrueden at wisc.edu
 */
public class IniList extends ArrayList<IniTable> {

  // -- IniList methods --

  /** Gets the table with the given name (header). */
  public IniTable getTable(String tableName) {
    for (IniTable table : this) {
      String header = table.get(IniTable.HEADER_KEY);
      if (tableName.equals(header)) return table;
    }
    return null;
  }

  /**
   * Flattens all of the INI tables into a single HashMap whose keys are
   * of the format "[table name] table key".
   */
  public HashMap<String, String> flattenIntoHashMap() {
    HashMap<String, String> h = new HashMap<String, String>();
    for (IniTable table : this) {
      String tableName = table.get(IniTable.HEADER_KEY);
      for (String key : table.keySet()) {
        if (!key.equals(IniTable.HEADER_KEY)) {
          h.put("[" + tableName + "] " + key, table.get(key));
        }
      }
    }
    return h;
  }

}
