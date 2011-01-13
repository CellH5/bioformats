//
// bio-formats.h
//

/*
OME Bio-Formats C++ bindings for native access to Bio-Formats Java library.
Copyright (c) 2008-2011, UW-Madison LOCI.
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:
    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above copyright
      notice, this list of conditions and the following disclaimer in the
      documentation and/or other materials provided with the distribution.
    * Neither the name of the UW-Madison LOCI nor the
      names of its contributors may be used to endorse or promote products
      derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY UW-MADISON LOCI ''AS IS'' AND ANY
EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL UW-MADISON LOCI BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

/*
IMPORTANT NOTE: Although this software is distributed according to a
"BSD-style" license, it requires the Bio-Formats Java library to do
anything useful, which is licensed under the GPL v2 or later.
As such, if you wish to distribute this software with Bio-Formats itself,
your combined work must be distributed under the terms of the GPL.
*/

/*-----------------------------------------------------------------------------
 *
 * THIS IS AUTOMATICALLY GENERATED CODE.  DO NOT MODIFY.
 * Created by hinerm via JaceHeaderAutogen on Jan 13, 2011 2:39:13 PM CST
 *
 *-----------------------------------------------------------------------------
 */

#ifndef BIO_FORMATS_H
#define BIO_FORMATS_H

#include "jace.h"

#include "jace/proxy/loci/formats/AxisGuesser.h"
#include "jace/proxy/loci/formats/ChannelFiller.h"
#include "jace/proxy/loci/formats/ChannelMerger.h"
#include "jace/proxy/loci/formats/ChannelSeparator.h"
#include "jace/proxy/loci/formats/ClassList.h"
#include "jace/proxy/loci/formats/CoreMetadata.h"
#include "jace/proxy/loci/formats/DelegateReader.h"
#include "jace/proxy/loci/formats/DimensionSwapper.h"
#include "jace/proxy/loci/formats/FileInfo.h"
#include "jace/proxy/loci/formats/FilePattern.h"
#include "jace/proxy/loci/formats/FilePatternBlock.h"
#include "jace/proxy/loci/formats/FileStitcher.h"
#include "jace/proxy/loci/formats/FormatException.h"
#include "jace/proxy/loci/formats/FormatHandler.h"
#include "jace/proxy/loci/formats/FormatReader.h"
#include "jace/proxy/loci/formats/FormatTools.h"
#include "jace/proxy/loci/formats/FormatWriter.h"
#include "jace/proxy/loci/formats/IFormatHandler.h"
#include "jace/proxy/loci/formats/IFormatReader.h"
#include "jace/proxy/loci/formats/IFormatWriter.h"
#include "jace/proxy/loci/formats/IMetadataConfigurable.h"
#include "jace/proxy/loci/formats/ImageReader.h"
#include "jace/proxy/loci/formats/ImageTools.h"
#include "jace/proxy/loci/formats/ImageWriter.h"
#include "jace/proxy/loci/formats/MetadataTools.h"
#include "jace/proxy/loci/formats/MinMaxCalculator.h"
#include "jace/proxy/loci/formats/MissingLibraryException.h"
#include "jace/proxy/loci/formats/NumberFilter.h"
#include "jace/proxy/loci/formats/ReaderWrapper.h"
#include "jace/proxy/loci/formats/UnknownFormatException.h"
#include "jace/proxy/loci/formats/WriterWrapper.h"
//using namespace jace::proxy::loci::formats;

#include "jace/proxy/loci/formats/cache/ByteArraySource.h"
#include "jace/proxy/loci/formats/cache/Cache.h"
#include "jace/proxy/loci/formats/cache/CacheEvent.h"
#include "jace/proxy/loci/formats/cache/CacheException.h"
#include "jace/proxy/loci/formats/cache/CacheListener.h"
#include "jace/proxy/loci/formats/cache/CacheReporter.h"
#include "jace/proxy/loci/formats/cache/CacheSource.h"
#include "jace/proxy/loci/formats/cache/CacheStrategy.h"
#include "jace/proxy/loci/formats/cache/CacheUpdater.h"
#include "jace/proxy/loci/formats/cache/CrosshairStrategy.h"
#include "jace/proxy/loci/formats/cache/ICacheSource.h"
#include "jace/proxy/loci/formats/cache/ICacheStrategy.h"
#include "jace/proxy/loci/formats/cache/RectangleStrategy.h"
//using namespace jace::proxy::loci::formats::cache;

#include "jace/proxy/loci/formats/codec/Base64Codec.h"
#include "jace/proxy/loci/formats/codec/BaseCodec.h"
#include "jace/proxy/loci/formats/codec/BitBuffer.h"
#include "jace/proxy/loci/formats/codec/BitWriter.h"
#include "jace/proxy/loci/formats/codec/ByteVector.h"
#include "jace/proxy/loci/formats/codec/Codec.h"
#include "jace/proxy/loci/formats/codec/CodecOptions.h"
#include "jace/proxy/loci/formats/codec/HuffmanCodec.h"
#include "jace/proxy/loci/formats/codec/HuffmanCodecOptions.h"
#include "jace/proxy/loci/formats/codec/JPEG2000Codec.h"
#include "jace/proxy/loci/formats/codec/JPEG2000CodecOptions.h"
#include "jace/proxy/loci/formats/codec/JPEGCodec.h"
#include "jace/proxy/loci/formats/codec/LZOCodec.h"
#include "jace/proxy/loci/formats/codec/LZWCodec.h"
#include "jace/proxy/loci/formats/codec/LosslessJPEGCodec.h"
#include "jace/proxy/loci/formats/codec/LuraWaveCodec.h"
#include "jace/proxy/loci/formats/codec/MJPBCodec.h"
#include "jace/proxy/loci/formats/codec/MJPBCodecOptions.h"
#include "jace/proxy/loci/formats/codec/MSRLECodec.h"
#include "jace/proxy/loci/formats/codec/MSVideoCodec.h"
#include "jace/proxy/loci/formats/codec/NikonCodec.h"
#include "jace/proxy/loci/formats/codec/NikonCodecOptions.h"
#include "jace/proxy/loci/formats/codec/PackbitsCodec.h"
#include "jace/proxy/loci/formats/codec/PassthroughCodec.h"
#include "jace/proxy/loci/formats/codec/QTRLECodec.h"
#include "jace/proxy/loci/formats/codec/RPZACodec.h"
#include "jace/proxy/loci/formats/codec/TargaRLECodec.h"
#include "jace/proxy/loci/formats/codec/ZlibCodec.h"
//using namespace jace::proxy::loci::formats::codec;

#include "jace/proxy/loci/formats/gui/AWTImageTools.h"
#include "jace/proxy/loci/formats/gui/BufferedImageReader.h"
#include "jace/proxy/loci/formats/gui/BufferedImageSource.h"
#include "jace/proxy/loci/formats/gui/BufferedImageWriter.h"
#include "jace/proxy/loci/formats/gui/CacheComponent.h"
#include "jace/proxy/loci/formats/gui/CacheIndicator.h"
#include "jace/proxy/loci/formats/gui/ComboFileFilter.h"
#include "jace/proxy/loci/formats/gui/DataConverter.h"
#include "jace/proxy/loci/formats/gui/ExtensionFileFilter.h"
#include "jace/proxy/loci/formats/gui/FormatFileFilter.h"
#include "jace/proxy/loci/formats/gui/GUITools.h"
#include "jace/proxy/loci/formats/gui/ImageViewer.h"
#include "jace/proxy/loci/formats/gui/Index16ColorModel.h"
#include "jace/proxy/loci/formats/gui/LegacyQTTools.h"
#include "jace/proxy/loci/formats/gui/NoExtensionFileFilter.h"
#include "jace/proxy/loci/formats/gui/PreviewPane.h"
#include "jace/proxy/loci/formats/gui/SignedByteBuffer.h"
#include "jace/proxy/loci/formats/gui/SignedColorModel.h"
#include "jace/proxy/loci/formats/gui/SignedShortBuffer.h"
#include "jace/proxy/loci/formats/gui/TwoChannelColorSpace.h"
#include "jace/proxy/loci/formats/gui/UnsignedIntBuffer.h"
#include "jace/proxy/loci/formats/gui/UnsignedIntColorModel.h"
#include "jace/proxy/loci/formats/gui/XMLCellRenderer.h"
#include "jace/proxy/loci/formats/gui/XMLWindow.h"
//using namespace jace::proxy::loci::formats::gui;

#include "jace/proxy/loci/formats/in/AIMReader.h"
#include "jace/proxy/loci/formats/in/APLReader.h"
#include "jace/proxy/loci/formats/in/APNGReader.h"
#include "jace/proxy/loci/formats/in/ARFReader.h"
#include "jace/proxy/loci/formats/in/AVIReader.h"
#include "jace/proxy/loci/formats/in/AliconaReader.h"
#include "jace/proxy/loci/formats/in/AmiraReader.h"
#include "jace/proxy/loci/formats/in/AnalyzeReader.h"
#include "jace/proxy/loci/formats/in/BDReader.h"
#include "jace/proxy/loci/formats/in/BIFormatReader.h"
#include "jace/proxy/loci/formats/in/BMPReader.h"
#include "jace/proxy/loci/formats/in/BaseTiffReader.h"
#include "jace/proxy/loci/formats/in/BioRadGelReader.h"
#include "jace/proxy/loci/formats/in/BioRadReader.h"
#include "jace/proxy/loci/formats/in/BurleighReader.h"
#include "jace/proxy/loci/formats/in/CellWorxReader.h"
#include "jace/proxy/loci/formats/in/CellomicsReader.h"
#include "jace/proxy/loci/formats/in/DefaultMetadataOptions.h"
#include "jace/proxy/loci/formats/in/DeltavisionReader.h"
#include "jace/proxy/loci/formats/in/DicomReader.h"
#include "jace/proxy/loci/formats/in/EPSReader.h"
#include "jace/proxy/loci/formats/in/Ecat7Reader.h"
#include "jace/proxy/loci/formats/in/FEIReader.h"
#include "jace/proxy/loci/formats/in/FEITiffReader.h"
#include "jace/proxy/loci/formats/in/FV1000Reader.h"
#include "jace/proxy/loci/formats/in/FakeReader.h"
#include "jace/proxy/loci/formats/in/FitsReader.h"
#include "jace/proxy/loci/formats/in/FlexReader.h"
#include "jace/proxy/loci/formats/in/FluoviewReader.h"
#include "jace/proxy/loci/formats/in/GIFReader.h"
#include "jace/proxy/loci/formats/in/GatanDM2Reader.h"
#include "jace/proxy/loci/formats/in/GatanReader.h"
#include "jace/proxy/loci/formats/in/GelReader.h"
#include "jace/proxy/loci/formats/in/HISReader.h"
#include "jace/proxy/loci/formats/in/ICSReader.h"
#include "jace/proxy/loci/formats/in/IPLabReader.h"
#include "jace/proxy/loci/formats/in/IPWReader.h"
#include "jace/proxy/loci/formats/in/ImaconReader.h"
#include "jace/proxy/loci/formats/in/ImageIOReader.h"
#include "jace/proxy/loci/formats/in/ImarisHDFReader.h"
#include "jace/proxy/loci/formats/in/ImarisReader.h"
#include "jace/proxy/loci/formats/in/ImarisTiffReader.h"
#include "jace/proxy/loci/formats/in/ImprovisionTiffReader.h"
#include "jace/proxy/loci/formats/in/InCellReader.h"
#include "jace/proxy/loci/formats/in/IvisionReader.h"
#include "jace/proxy/loci/formats/in/JEOLReader.h"
#include "jace/proxy/loci/formats/in/JPEG2000Reader.h"
#include "jace/proxy/loci/formats/in/JPEGReader.h"
#include "jace/proxy/loci/formats/in/JPKReader.h"
#include "jace/proxy/loci/formats/in/KhorosReader.h"
#include "jace/proxy/loci/formats/in/L2DReader.h"
#include "jace/proxy/loci/formats/in/LEOReader.h"
#include "jace/proxy/loci/formats/in/LIFReader.h"
#include "jace/proxy/loci/formats/in/LIMReader.h"
#include "jace/proxy/loci/formats/in/LegacyND2Reader.h"
#include "jace/proxy/loci/formats/in/LegacyQTReader.h"
#include "jace/proxy/loci/formats/in/LeicaHandler.h"
#include "jace/proxy/loci/formats/in/LeicaReader.h"
#include "jace/proxy/loci/formats/in/LiFlimReader.h"
#include "jace/proxy/loci/formats/in/MIASReader.h"
#include "jace/proxy/loci/formats/in/MINCReader.h"
#include "jace/proxy/loci/formats/in/MNGReader.h"
#include "jace/proxy/loci/formats/in/MRCReader.h"
#include "jace/proxy/loci/formats/in/MRWReader.h"
#include "jace/proxy/loci/formats/in/MetadataLevel.h"
#include "jace/proxy/loci/formats/in/MetadataOptions.h"
#include "jace/proxy/loci/formats/in/MetamorphHandler.h"
#include "jace/proxy/loci/formats/in/MetamorphReader.h"
#include "jace/proxy/loci/formats/in/MetamorphTiffReader.h"
#include "jace/proxy/loci/formats/in/MicromanagerReader.h"
#include "jace/proxy/loci/formats/in/MinimalTiffReader.h"
#include "jace/proxy/loci/formats/in/MolecularImagingReader.h"
#include "jace/proxy/loci/formats/in/NAFReader.h"
#include "jace/proxy/loci/formats/in/ND2Handler.h"
#include "jace/proxy/loci/formats/in/ND2Reader.h"
#include "jace/proxy/loci/formats/in/NRRDReader.h"
#include "jace/proxy/loci/formats/in/NativeND2Reader.h"
#include "jace/proxy/loci/formats/in/NativeQTReader.h"
#include "jace/proxy/loci/formats/in/NiftiReader.h"
#include "jace/proxy/loci/formats/in/NikonElementsTiffReader.h"
#include "jace/proxy/loci/formats/in/NikonReader.h"
#include "jace/proxy/loci/formats/in/NikonTiffReader.h"
#include "jace/proxy/loci/formats/in/OMETiffReader.h"
#include "jace/proxy/loci/formats/in/OMEXMLReader.h"
#include "jace/proxy/loci/formats/in/OpenlabRawReader.h"
#include "jace/proxy/loci/formats/in/OpenlabReader.h"
#include "jace/proxy/loci/formats/in/OxfordInstrumentsReader.h"
#include "jace/proxy/loci/formats/in/PCIReader.h"
#include "jace/proxy/loci/formats/in/PCXReader.h"
#include "jace/proxy/loci/formats/in/PDSReader.h"
#include "jace/proxy/loci/formats/in/PGMReader.h"
#include "jace/proxy/loci/formats/in/PSDReader.h"
#include "jace/proxy/loci/formats/in/PerkinElmerReader.h"
#include "jace/proxy/loci/formats/in/PhotoshopTiffReader.h"
#include "jace/proxy/loci/formats/in/PictReader.h"
#include "jace/proxy/loci/formats/in/PrairieReader.h"
#include "jace/proxy/loci/formats/in/QTReader.h"
#include "jace/proxy/loci/formats/in/QuesantReader.h"
#include "jace/proxy/loci/formats/in/RHKReader.h"
#include "jace/proxy/loci/formats/in/SBIGReader.h"
#include "jace/proxy/loci/formats/in/SDTInfo.h"
#include "jace/proxy/loci/formats/in/SDTReader.h"
#include "jace/proxy/loci/formats/in/SEQReader.h"
#include "jace/proxy/loci/formats/in/SMCameraReader.h"
#include "jace/proxy/loci/formats/in/SVSReader.h"
#include "jace/proxy/loci/formats/in/ScanrReader.h"
#include "jace/proxy/loci/formats/in/ScreenReader.h"
#include "jace/proxy/loci/formats/in/SeikoReader.h"
#include "jace/proxy/loci/formats/in/SimplePCITiffReader.h"
#include "jace/proxy/loci/formats/in/SlidebookReader.h"
#include "jace/proxy/loci/formats/in/TCSReader.h"
#include "jace/proxy/loci/formats/in/TargaReader.h"
#include "jace/proxy/loci/formats/in/TextReader.h"
#include "jace/proxy/loci/formats/in/TiffDelegateReader.h"
#include "jace/proxy/loci/formats/in/TiffJAIReader.h"
#include "jace/proxy/loci/formats/in/TiffReader.h"
#include "jace/proxy/loci/formats/in/TillVisionReader.h"
#include "jace/proxy/loci/formats/in/TopometrixReader.h"
#include "jace/proxy/loci/formats/in/UBMReader.h"
#include "jace/proxy/loci/formats/in/UnisokuReader.h"
#include "jace/proxy/loci/formats/in/VGSAMReader.h"
#include "jace/proxy/loci/formats/in/VarianFDFReader.h"
#include "jace/proxy/loci/formats/in/VisitechReader.h"
#include "jace/proxy/loci/formats/in/WATOPReader.h"
#include "jace/proxy/loci/formats/in/ZeissLSMReader.h"
#include "jace/proxy/loci/formats/in/ZeissZVIReader.h"
#include "jace/proxy/loci/formats/in/ZipReader.h"
//using namespace jace::proxy::loci::formats::in;

#include "jace/proxy/loci/formats/meta/AggregateMetadata.h"
#include "jace/proxy/loci/formats/meta/DummyMetadata.h"
#include "jace/proxy/loci/formats/meta/FilterMetadata.h"
#include "jace/proxy/loci/formats/meta/IMetadata.h"
#include "jace/proxy/loci/formats/meta/IMinMaxStore.h"
#include "jace/proxy/loci/formats/meta/MetadataConverter.h"
#include "jace/proxy/loci/formats/meta/MetadataRetrieve.h"
#include "jace/proxy/loci/formats/meta/MetadataStore.h"
//using namespace jace::proxy::loci::formats::meta;

#include "jace/proxy/loci/formats/ome/AbstractOMEXMLMetadata.h"
#include "jace/proxy/loci/formats/ome/OMEXMLMetadata.h"
#include "jace/proxy/loci/formats/ome/OMEXMLMetadataImpl.h"
#include "jace/proxy/loci/formats/ome/OmeisException.h"
#include "jace/proxy/loci/formats/ome/OmeisImporter.h"
//using namespace jace::proxy::loci::formats::ome;

#include "jace/proxy/loci/formats/out/APNGWriter.h"
#include "jace/proxy/loci/formats/out/AVIWriter.h"
#include "jace/proxy/loci/formats/out/EPSWriter.h"
#include "jace/proxy/loci/formats/out/ICSWriter.h"
#include "jace/proxy/loci/formats/out/ImageIOWriter.h"
#include "jace/proxy/loci/formats/out/JPEG2000Writer.h"
#include "jace/proxy/loci/formats/out/JPEGWriter.h"
#include "jace/proxy/loci/formats/out/JavaWriter.h"
#include "jace/proxy/loci/formats/out/LegacyQTWriter.h"
#include "jace/proxy/loci/formats/out/OMETiffWriter.h"
#include "jace/proxy/loci/formats/out/OMEXMLWriter.h"
#include "jace/proxy/loci/formats/out/QTWriter.h"
#include "jace/proxy/loci/formats/out/TiffWriter.h"
//using namespace jace::proxy::loci::formats::out;

#include "jace/proxy/loci/formats/services/JAIIIOService.h"
#include "jace/proxy/loci/formats/services/JAIIIOServiceImpl.h"
#include "jace/proxy/loci/formats/services/LuraWaveService.h"
#include "jace/proxy/loci/formats/services/LuraWaveServiceImpl.h"
#include "jace/proxy/loci/formats/services/MDBService.h"
#include "jace/proxy/loci/formats/services/MDBServiceImpl.h"
#include "jace/proxy/loci/formats/services/NetCDFService.h"
#include "jace/proxy/loci/formats/services/NetCDFServiceImpl.h"
#include "jace/proxy/loci/formats/services/OMEXMLService.h"
#include "jace/proxy/loci/formats/services/OMEXMLServiceImpl.h"
#include "jace/proxy/loci/formats/services/POIService.h"
#include "jace/proxy/loci/formats/services/POIServiceImpl.h"
//using namespace jace::proxy::loci::formats::services;

#include "jace/proxy/loci/formats/tiff/IFD.h"
#include "jace/proxy/loci/formats/tiff/IFDList.h"
#include "jace/proxy/loci/formats/tiff/IFDType.h"
#include "jace/proxy/loci/formats/tiff/PhotoInterp.h"
#include "jace/proxy/loci/formats/tiff/TiffCompression.h"
#include "jace/proxy/loci/formats/tiff/TiffConstants.h"
#include "jace/proxy/loci/formats/tiff/TiffIFDEntry.h"
#include "jace/proxy/loci/formats/tiff/TiffParser.h"
#include "jace/proxy/loci/formats/tiff/TiffRational.h"
#include "jace/proxy/loci/formats/tiff/TiffSaver.h"
//using namespace jace::proxy::loci::formats::tiff;

#include "jace/proxy/loci/formats/tools/AmiraParameters.h"
#include "jace/proxy/loci/formats/tools/AsciiImage.h"
#include "jace/proxy/loci/formats/tools/CacheConsole.h"
#include "jace/proxy/loci/formats/tools/EditTiffG.h"
#include "jace/proxy/loci/formats/tools/ImageConverter.h"
#include "jace/proxy/loci/formats/tools/ImageInfo.h"
#include "jace/proxy/loci/formats/tools/PrintDomains.h"
#include "jace/proxy/loci/formats/tools/PrintFormatTable.h"
#include "jace/proxy/loci/formats/tools/TiffComment.h"
#include "jace/proxy/loci/formats/tools/XMLIndent.h"
#include "jace/proxy/loci/formats/tools/XMLValidate.h"
//using namespace jace::proxy::loci::formats::tools;

#endif
