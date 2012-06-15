/**
 * \file 
 * This file contains the documentation page \ref bioapi_references, 
 * containing references from \ref iso19784-1, section 3, <i>References</i>,
 * \ref iso19784-1, <i>Bibliography</i> and others.
 * 
 * No functions or data structures are declared here.
 * 
 * 
 * 
 * 
 * 
 * \page bioapi_references  Normative references
 * 
 * The following referenced documents are indispensable for the application of this document.
 * 
 * 
 * 
 * 
 * 
* \section iso19784 ISO/IEC 19784 (BioAPI)
 * <b>Information technology — Biometric application programming interface</b>
 * \see \ref iso19784-1
 * \see \ref iso19784-2
 * \see \ref iso19784-4
 * 
 * 
 * 
 * 
 * 
 * \section iso19784-1 ISO/IEC 19784-1 (BioAPI Specification)
 * <b>Information technology — Biometric application programming interface — Part 1: BioAPI specification</b>
 * 
 * ISO/IEC 19784-1:2006 provides a defined interface that allows a software application to communicate with (utilize the services of) 
 * one or more biometric technologies. It includes a high-level generic biometric authentication model suited to a broad range 
 * of biometrically enabled applications and to most forms of biometric technology. An architectural model is described which 
 * enables components of a biometric system to be provided by different vendors, and to interwork through fully-defined 
 * Application Programming Interfaces (APIs), corresponding Service Provider Interfaces (SPIs), and associated data structures. 
 * 
 * ISO/IEC 19784-1:2006 covers the basic biometric functions of enrollment, verification and identification, and includes a 
 * database interface to allow an application to manage the storage of biometric records. Conformance requirements are 
 * identified and informative annexes, including sample code, are provided. 
 * 
 * ISO/IEC 19784-1:2006 specifies a biometric data structure which is compatible with \ref iso19785 and \ref iso19794.
 * 
 * \see <a href="http://www.iso.org/iso/catalogue_detail.htm?csnumber=33922">ISO Catalogue: ISO/IEC 19784-1:2006</a>
 * \see <a href="http://www.bioapi.org/">The BioAPI Consortium</a>
 * \see <a href="http://en.wikipedia.org/wiki/BioAPI">Wikipedia: BioAPI</a>
 * 
 * 
 * 
 * 
 * 
 * \section iso19784-2 ISO/IEC 19784-2 (Archive BFP)
 * <b>Information technology — Biometric application programming interface — Part 2: 
 * Biometric archive function provider interface</b>
 * 
 * ISO/IEC 19784-2:2007 defines the interface between a biometric service provider (BSP) and a 
 * biometric archive function provider (BAFP) for BioAPI. A BAFP encapsulates all functionality 
 * for the storage, search and management of biometric reference data regardless of the kind of 
 * physical storage media. Using a BAFP, a BSP does not have to provide special handling of 
 * different storage media like database servers, smartcards, database web services, etc. Whatever 
 * media is used, the BSP in all cases handles the same interface for a BAFP.
 * 
 * The interface description contains management functions to attach and detach different BAFPs, 
 * to query biometric data records and to store biometric data records.
 * 
 * \see <a href="http://www.iso.org/iso/catalogue_detail.htm?csnumber=43303">ISO Catalogue: ISO/IEC 19784-2:2007</a>
 * 
 * 
 * 
 * 
 * 
 * \section iso19784-4 ISO/IEC 19784-4 (Sensor BFP)
 * <b>Information technology — Biometric application programming interface — Part 4: 
 * Biometric sensor function provider interface</b>
 * 
 * ISO/IEC 19784-4:2011 specifies a biometric sensor interface for a Biometric Service Provider 
 * (BSP, see \ref iso19784-1). The interface supports a BSP wishing to provide the BioAPI Service 
 * Provider Interface (SPI) functions, whilst removing device handling activity from the BSP. 
 * 
 * ISO/IEC 19784-4:2011 provides an interface that can be used by all types of biometric sensor, 
 * including <i>inter alia</i> image streaming sensors (infrared, face, iris, finger, etc.), 
 * voice streaming sensors and digital tablets providing dynamic signature data.
 * 
 * It is not in the scope of ISO/IEC 19784-4:2011 to define security and privacy requirements for 
 * capturing and transferring of biometric data across the Sensor Function Provider Interface (SFPI).
 * 
 * \see <a href="http://www.iso.org/iso/catalogue_detail.htm?csnumber=50859">ISO Catalogue: ISO/IEC 19784-4:2011</a>
 * 
 * 
 * 
 * 
 * 
 * \section iso24708 ISO/IEC 24708 (BioAPI Interworking Protocol)
 * <b>Information technology — Biometrics — BioAPI Interworking Protocol</b>
 * 
 * ISO/IEC 24708:2008 specifies the syntax, semantics, and encodings of a set of messages 
 * (BIP messages) that enable a BioAPI-conforming application (see \ref iso19784-1) to 
 * request biometric operations in BioAPI-conforming biometric service providers (BSPs) 
 * across node or process boundaries, and to be notified of events originating in those 
 * remote BSPs. It also specifies extensions to the architecture and behaviour of the 
 * BioAPI framework (specified in \ref iso19784-1) that supports the creation, processing, 
 * sending and reception of BIP messages. It is applicable to all distributed applications 
 * of BioAPI.
 * 
 * \see <a href="http://www.iso.org/iso/catalogue_detail.htm?csnumber=43611">ISO Catalogue: ISO/IEC 24708:2008</a>
 * 
 * 
 * 
 * 
 * 
 * \section iso24709 ISO/IEC 24709 (Conformance testing for BioAPI)
 * <b>Information technology — Conformance testing for the biometric 
 * application programming interface (BioAPI)</b>
 * 
 * \see \ref iso24709-1
 * \see \ref iso24709-2
 * \see \ref iso24709-3
 * 
 * 
 * 
 * 
 * 
 * \section iso24709-1 ISO/IEC 24709-1 (Methods and Procedures for BioAPI Conformance Testing)
 * <b>Information technology — Conformance testing for the biometric 
 * application programming interface (BioAPI) — Part 1: Methods and procedures </b>
 *  
 * ISO/IEC 24709-1:2007 specifies the concepts, framework, test methods and criteria required to test conformity of 
 * biometric products claiming conformance to BioAPI (ISO/IEC 19784-1). Guidelines for specifying BioAPI conformance 
 * test suites, writing test assertions and defining procedures to be followed during the conformance testing are 
 * provided. The conformance testing methodology is concerned with conformance testing of biometric products claiming 
 * conformance to BioAPI. Definitions of schemas of the assertion language are provided in normative annexes.
 * 
 * \see <a href="http://www.iso.org/iso/catalogue_detail.htm?csnumber=38819">ISO Catalogue: ISO/IEC 24709-1:2007</a>
 * 
 * 
 * 
 * 
 * 
 * \section iso24709-2 ISO/IEC 24709-2 (Test Assertions for BSP Conformance Testing)
 * <b>Information technology — Conformance testing for the biometric application 
 * programming interface (BioAPI) — Part 2: Test assertions for biometric service providers</b>
 *  
 * ISO/IEC 24709-2:2007 defines a number of test assertions written in the assertion language specified 
 * in \ref iso24709-1. These assertions enable a user of ISO/IEC 24709-2:2007 (such as a testing laboratory) 
 * to test the conformance to \ref iso24709-1 of any biometric service provider (BSP) that claims 
 * to be a conforming implementation of that International Standard. 
 * 
 * Each test assertion specified in ISO/IEC 24709-2:2007 exercises one or more features of an implementation 
 * under test. Assertions are placed into packages (one or more assertions per package) as required by the 
 * assertion language. These assertions allow for testing conformance of BSPs of all conformance subclasses, 
 * and are further organized according to conformance subclasses and claimed support of optional features.
 * 
 * \see <a href="http://www.iso.org/iso/catalogue_detail.htm?csnumber=43352">ISO Catalogue: ISO/IEC 24709-2:2007</a>
 * 
 * 
 * 
 * 
 * 
 * \section iso24709-3 ISO/IEC 24709-3 (Test Assertions for BioAPI Framework Conformance Testing)
 * <b>Information technology — Conformance testing for the biometric application 
 * programming interface (BioAPI) — Part 3: Test assertions for BioAPI frameworks</b>
 *  
 * ISO/IEC 24709-3:2011 defines a number of test assertions written in the assertion language specified in 
 * \ref iso24709-1. These assertions enable a user of ISO/IEC 24709-3:2011 (such as a testing laboratory) 
 * to test the conformance to \ref iso24709-1 of any BioAPI Framework that claims to be a conforming 
 * implementation of \ref iso24709-1. Each test assertion specified in ISO/IEC 24709-3:2011 exercises 
 * one or more features of an implementation under test.
 * 
 * \see <a href="http://www.iso.org/iso/catalogue_detail.htm?csnumber=43609">ISO Catalogue: ISO/IEC 24709-3:2011</a>
 * 
 * 
 * 
 * 
 * 
 * 

 *  
 * 
 * 
 * 
 * 
 * 
 * \section iso19785 ISO/IEC 19785 (CBEFF)
 * <b>Information technology — Common Biometric Exchange Formats Framework</b>
 * \see \ref iso19785-1
 * \see \ref iso19785-2
 * \see \ref iso19785-3
 * \see \ref iso19785-4
 * 
 * 
 * 
 * 
 * 
 * \section iso19785-1 ISO/IEC 19785-1 (CBEFF Biometric Information Record)
 * <b>Information technology — Common Biometric Exchange Formats Framework 
 * — Part 1: Data element specification</b>
 * 
 * 19785-1:2006 defines a basic structure for standardized biometric information records (BIRs) within the 
 * Common Biometric Exchange Formats Framework (CBEFF). This structure consists of three parts: the standard biometric header (SBH), 
 * the biometric data block (BDB), and the security block (SB). CBEFF also defines several data elements and their standardized 
 * abstract values that can be used in SBHs and SBs (CBEFF treats the BDB as opaque data). CBEFF also establishes mechanisms by 
 * which organizations, called 'patrons' by CBEFF, can specify and publish BIR format specifications, which are in turn called
 * 'patron formats'. CBEFF enables patrons to develop BIR specifications that are fully standardized and interoperable, yet
 * are specifically adapted to the requirements of a particular application environment.
 * 
 * CBEFF defines rules for BIRs that contain only one BDB (simple BIR) and that contain at least one BDB (complex BIR). 
 * CBEFF defines mandatory data elements that identify the format of a BDB and its security attributes (encryption and integrity). 
 * All the other CBEFF-defined data elements and abstract values are optional. CBEFF enables patrons to define additional 
 * data elements and abstract values as required by the application environment.
 * 
 * \see <a href="http://www.iso.org/iso/catalogue_detail.htm?csnumber=41047">ISO Catalogue: ISO/IEC 19785-1:2006</a>
 * \see <a href="http://en.wikipedia.org/wiki/CBEFF">Wikipedia: CBEFF</a>
 * 
 * 
 * 
 * 
 * 
 * \section iso19785-2 ISO/IEC 19785-2 (CBEFF Registration)
 * <b>Information technology — Common Biometric Exchange Formats Framework 
 * — Part 2: Procedures for the operation of the Biometric Registration</b>
 * 
 * ISO/IEC 19785-2:2006 specifies the requirements for the operation of the Biometric Registration Authority
 * within the Common Biometric Exchange Formats Framework (CBEFF). The Registration Authority is responsible for 
 * assigning and publishing, via its website, unique biometric organization identifier values to organizations 
 * that own or are otherwise responsible for standardized or proprietary format specifications for biometric data 
 * blocks, biometric information record security blocks and/or CBEFF patron formats, and to organizations that 
 * intend to assign biometric product identifier values to their products.
 * 
 * \see <a href="http://www.iso.org/iso/catalogue_detail.htm?csnumber=41048">ISO Catalogue: ISO/IEC 19785-2:2006</a>
 * \see <a href="http://www.ibia.org/cbeff/iso/">IBIA: CBEFF Registrations</a>
 * 
 * 
 * 
 * 
 * 
 * \section iso19785-3 ISO/IEC 19785-3 (CBEFF Patron format specifications)
 * <b>Information technology — Common Biometric Exchange Formats Framework 
 * — Part 3: Patron format specifications</b>
 * 
 * ISO/IEC 19785-3:2007 specifies several patron formats that conform to the requirements 
 * of \ref iso19785-1.
 * 
 * \ref iso19785-1 defines a basic structure for standardized biometric information records (BIRs) that 
 * consists of three parts, the standard biometric header (SBH), the biometric data block (BDB), and 
 * the security block (SB). CBEFF also defines several data elements and their standardized abstract 
 * values that can be used in SBHs and SBs (CBEFF treats the BDB as opaque data). CBEFF also establishes 
 * mechanisms by which organizations, called “patrons” by CBEFF, can specify and publish BIR format 
 * specifications, which are in turn called “patron formats”. CBEFF enables patrons to develop BIR 
 * specifications that are fully standardized and interoperable, yet are specifically adapted to the 
 * requirements of a particular application environment.
 * 
 * CBEFF defines rules for BIRs that contain only one BDB (simple BIR) and that contain at least one BDB 
 * (complex BIR). CBEFF defines mandatory data elements that identify the format of a BDB and its security 
 * attributes (encryption and integrity). All the other CBEFF-defined data elements and abstract values 
 * are optional. CBEFF enables patrons to define additional data elements and abstract values as 
 * required by the application environment
 * 
 * \see <a href="http://www.iso.org/iso/catalogue_detail.htm?csnumber=43615">ISO Catalogue: ISO/IEC 19785-3:2007</a>
 * 
 * 
 * 
 * 
 * 
 * \section iso19785-4 ISO/IEC 19785-4 (CBEFF Security Block Formats)
 * <b>Information technology — Common Biometric Exchange Formats Framework — Part 4: 
 * Security block format specifications</b>
 * 
 * ISO/IEC 19785-4:2010 specifies security block formats (see \ref iso19785-1) registered in accordance with \ref iso19785-2 as 
 * formats defined by the CBEFF biometric organization ISO/IEC JTC 1/SC 37, and specifies their registered security block 
 * format identifiers. [The security block format identifier is recorded in the standard biometric header (SBH) of a 
 * patron format (or defined by that patron format as the only available security block format).]
 * 
 * The general-purpose security block format provides for specification of whether the biometric data block (BDB) is encrypted
 * or the SBH and BDB have integrity applied (or both), and can include ACBio instances (see ISO/IEC 24761). 
 * This security block provides all necessary security parameters, including those used for encryption or integrity.
 * 
 * It does not restrict the algorithms and parameters used for encryption or integrity, but provides for the 
 * recording of such algorithms and parameter values.
 * 
 * It is a matter for profiling to determine, for a particular application area, what algorithms and parameter ranges 
 * can be used by the generator of a security block, and hence what algorithms and parameter ranges have to be supported by 
 * the user of a security block. This is out of the scope of ISO/IEC 19785-4:2010.
 * 
 * The second security block is more limited, but simpler (and in particular cannot contain ACBio instances, 
 * and does not support encryption of the BDB).
 * 
 * \see <a href="http://www.iso.org/iso/catalogue_detail.htm?csnumber=50860">ISO Catalogue: ISO/IEC 19785-4:2010</a>
 * 
 * 
 * 
 * 
 * 
 * \section iso19794 ISO/IEC 19794 (Biometric Data Interchange Formats)
 * <b>Information technology — Biometric data interchange formats</b>
 * 
 * \see \ref iso19794-1
 * \see \ref iso19794-2
 * \see \ref iso19794-3
 * \see \ref iso19794-4
 * \see \ref iso19794-5
 * \see \ref iso19794-6
 * 
 * 
 * 
 * 
 * 
 * \section iso19794-1 ISO/IEC 19794-1 (Biometric Data Interchange Formats Framework)
 * <b>Information technology — Biometric data interchange formats — Part 1: Framework</b>
 * 
 * ISO/IEC 19794-1 describes the general aspects and requirements for defining biometric data interchange formats. 
 * The notation and transfer formats provide platform independence and separation of transfer syntax from content 
 * definition. 
 * 
 * ISO/IEC 19794-1 defines what is commonly applied for biometric data formats, i.e. the 
 * standardization of the common content, meaning, and representation of biometric data formats of biometric types 
 * considered in the specific parts of \ref iso19794.
 * 
 * \see <a href="http://www.iso.org/iso/catalogue_detail.htm?csnumber=50862">ISO Catalogue: ISO/IEC 19794-1:2011</a>
 * 
 * 
 * 
 * 
 * 
 * \section iso19794-2 ISO/IEC 19794-2 (Finger Minutiae Data Format)
 * <b>Information technology — Biometric data interchange formats — Part 1: Finger minutiae data</b>
 * 
 * \ref iso19794-2 specifies a concept and data formats for representation of fingerprints using the fundamental 
 * notion of minutiae. It is generic, in that it may be applied and used in a wide range of application areas where 
 * automated fingerprint recognition is involved. It contains definitions of relevant terms, a description of how 
 * minutiae are to be determined, data formats for containing the data for both general use and for use with cards, 
 * and conformance information. Guidelines and values for matching and decision parameters are provided.
 * 
 * ISO/IEC 19794-2:2011specifies the following:
 * 
 * - The fundamental data elements used for minutiae-based representation of a fingerprint;
 * - Three data formats for interchange and storage of this data: a record-based format, and normal and compact formats 
 *   for use on a smart card in a match-on-card application;
 * - Optional extended data formats for including additional data such as ridge counts and core and delta location.
 * 
 * ISO/IEC 19794-2:2011 provides for interchange of finger minutiae data between sensing, storage and matching systems.
 * 
 * \see <a href="http://www.iso.org/iso/catalogue_detail.htm?csnumber=50864">ISO Catalogue: ISO/IEC 19794-2:2011</a>
 * 
 * 
 * 
 * 
 * 
 * \section iso19794-3 ISO/IEC 19794-3 (Finger Pattern Spectral Data Format)
 * <b>Information technology — Biometric data interchange formats — Part 3: Finger pattern spectral data</b>
 * 
 * ISO/IEC 19794-3:2006, the finger pattern spectral data interchange format, specifies requirements for the 
 * representation of local or global spectral data derived from a fingerprint image. The format is designed 
 * to provide flexibility in the choice of spectral representation in that spectral components may be based 
 * on quantized co-sinusoidal triplets, Discrete Fourier Transformations or Gabor filters. The format also 
 * allows for a variable number of spectral components to be retained, which enables data representations 
 * in a form that is more compact than storage of the entire fingerprint image. ISO/IEC 19794-3:2006 provides 
 * example data records for each of the spectral representations.
 * 
 * \see <a href="http://www.iso.org/iso/catalogue_detail.htm?csnumber=38747">ISO Catalogue: ISO/IEC 19794-3:2006</a>
 * 
 * 
 * 
 * 
 * 
 * \section iso19794-4 ISO/IEC 19794-4 (Finger Image Data Format)
 * <b>Information technology — Biometric data interchange formats — Part 4: Finger image data</b>
 * 
 * ISO/IEC 19794-4:2011 specifies a data record interchange format for storing, recording, and transmitting 
 * the information from one or more finger or palm image areas within an \ref iso19785-1 data structure. 
 * 
 * This can be used for the exchange and comparison of finger image data. It defines the content, format, 
 * and units of measurement for the exchange of finger image data that may be used in the verification 
 * or identification process of a subject. The information consists of a variety of mandatory and optional 
 * items, including scanning parameters, compressed or uncompressed images and vendor-specific information. 
 * This information is intended for interchange among organizations that rely on automated devices and 
 * systems for identification or verification purposes based on the information from finger image areas. 
 * 
 * Information compiled and formatted in accordance with ISO/IEC 19794-4:2011 can be recorded on machine-readable 
 * media or may be transmitted by data communication facilities. 
 * 
 * \see <a href="http://www.iso.org/iso/catalogue_detail.htm?csnumber=50866">ISO Catalogue: ISO/IEC 19794-4:2011</a>
 * 
 * 
 * 
 * 
 * 
 * \section iso19794-5 ISO/IEC 19794-5 (Face Image Data Format)
 * <b>Information technology — Biometric data interchange formats — Part 5: Face image data</b>
 * 
 * ISO/IEC 19794-5:2011
 * - Specifies a record format for storing, recording, and transmitting information from one or more facial 
 *   images or a short video stream of facial images,
 * - Specifies scene constraints of the facial images,
 * - Specifies photographic properties of the facial images,
 * - Specifies digital image attributes of the facial images, and
 * - Provides best practices for the photography of faces.
 * 
 * \see <a href="http://www.iso.org/iso/catalogue_detail.htm?csnumber=50867">ISO Catalogue: ISO/IEC 19794-5:2011</a>
 * 
 * 
 * 
 * 
 * 
 * \section iso19794-6 ISO/IEC 19794-6 (Iris Image Data Format)
 * <b>Information technology — Biometric data interchange formats — Part 6: Iris image data</b>
 * 
 * ISO/IEC 19794-6:2011 specifies iris image interchange formats for biometric enrolment, verification 
 * and identification systems. The image information might be stored as
 * - An array of intensity values optionally compressed with ISO/IEC 15948 or ISO/IEC 15444, or
 * - An array of intensity values optionally compressed with ISO/IEC 15948 or ISO/IEC 15444 
 *   that might be cropped around the iris, with the iris at the centre, and which might 
 *   incorporate region-of-interest masking of non-iris regions.
 * 
 * ISO/IEC 19794-6:2011 does not establish
 * - Requirements on the optical specifications of cameras,
 * - Reequirements on photometric properties of iris images, or
 * - Reequirements on enrolment processes, workflow and use of iris equipment.
 * 
 * \see <a href="http://www.iso.org/iso/catalogue_detail.htm?csnumber=50868">ISO Catalogue: ISO/IEC 19794-6:2011</a>
 * 
 * 
 * 
 * 
 * 
 * \section iso9834-8 ISO/IEC 9834-8 (UUID)
 * <b>Information technology — Open Systems Interconnection — Procedures for the operation of 
 * OSI Registration Authorities: Generation and registration of Universally Unique Identifiers (UUIDs) and their
 * use as ASN1 Object Identifier components.</b>
 * 
 * ISO/IEC 9834-8:2005 specifies the format and generation rules that enable users to produce 128-bit identifiers that 
 * are either guaranteed or have a high probability of being globally unique.
 * 
 * The UUIDs generated in conformance with \ref iso9834-8 are suitable either for transient use, with generation of 
 * a new UUID every 100 nanoseconds, or as persistent identifiers.
 * ISO/IEC 9834-8:2005 is derived from earlier non-standard specifications of UUIDs and their generation, and is technically 
 * identical to those earlier specifications. It specifies the procedures for the operation of a 
 * Web-based Registration Authority for UUIDs.
 * 
 * ISO/IEC 9834-8:2005 also specifies and allows the use of UUIDs (registered or not registered) as OID components under the arc 
 * {joint-iso-itu-t uuid(25)}. This enables users to generate OIDs without any registration procedures. 
 * It also specifies and allows the use of UUIDs (registered or not registered) to form a URN.
 * 
 * \see <a href="http://www.iso.org/iso/catalogue_detail.htm?csnumber=36775">ISO Catalogue: ISO/IEC 9834-8:2005</a>
 * \see <a href="http://en.wikipedia.org/wiki/UUID">Wikipedia: Universally Unique Identifier</a>
 * 
 * 
 * 
 * 
 * 
 * \section iso10646 ISO/IEC 10646 (Universal Character Set)
 * <b>Information technology — Universal Multiple-Octet Coded Character Set (UCS)</b>
 * 
 * ISO/IEC 10646:2011 specifies the Universal Coded Character Set (UCS). It is applicable to the representation,
 * transmission, interchange, processing, storage, input and presentation of the written form of the languages of 
 * the world as well as additional symbols. It covers over 109 000 characters from the world's scripts.
 * 
 * ISO/IEC 10646:2011:
 * - Specifies the architecture of ISO/IEC 10646;
 * - Defines terms used ISO/IEC 10646;
 * - Describes the general structure of the UCS codespace;
 * - Specifies the Basic Multilingual Plane (BMP) of the UCS;
 * - Specifies supplementary planes of the UCS: the Supplementary Multilingual Plane (SMP), the 
 *   Supplementary Ideographic Plane (SIP), the Tertiary Ideographic Plane (TIP), and the Supplementary Special-purpose Plane (SSP);
 * - Defines a set of graphic characters used in scripts and the written form of languages on a world-wide scale;
 * - Specifies the names for the graphic characters and format characters of the BMP, SMP, SIP, TIP, SSP and their 
 *   coded representations within the UCS codespace;
 * - Specifies the coded representations for control characters and private use characters;
 * - Specifies three encoding forms of the UCS: UTF-8, UTF-16, and UTF-32;
 * - Specifies seven encoding schemes of the UCS: UTF-8, UTF-16, UTF-16BE, UTF-16LE, UTF-32, UTF-32BE, and UTF-32LE;
 * - Specifies the management of future additions to this coded character set.
 * 
 * The UCS is an encoding system different from that specified in ISO/IEC 2022. ISO/IEC 10646:2011 specifies 
 * the method to designate UCS from ISO/IEC 2022.
 * 
 * A graphic character will be assigned only one code point in the standard, located either in the BMP 
 * or in one of the supplementary planes.
 * 
 * By defining a consistent way of encoding multilingual text, ISO/IEC 10646:2011 enables the exchange of data internationally. 
 * The information technology industry gains data stability, greater global interoperability and data interchange. 
 * ISO/IEC 10646:2011 has been widely adopted in new Internet protocols and implemented in modern operating systems and 
 * computer languages.
 * 
 * \see <a href="http://www.iso.org/iso/catalogue_detail.htm?csnumber=51273">ISO Catalogue: ISO/IEC 10646:2011</a>
 * \see <a href="http://www.unicode.org">The Unicode Consortium</a>
 * \see <a href="http://en.wikipedia.org/wiki/Universal_Character_Set">Wikipedia: Universal Character Set</a>
 * 
 * 
 * 
 * 
 * 
 * \section iso9899 ISO/IEC 9899 (C Language)
 * <b>Programming Languages — C</b>
 * 
 * ISO/IEC 9899:2011 specifies the form and establishes the interpretation of programs written in 
 * the C programming language. It specifies: *
 * - The representation of C programs;
 * - The syntax and constraints of the C language;
 * - The semantic rules for interpreting C programs;
 * - The representation of input data to be processed by C programs;
 * - The representation of output data produced by C programs;
 * - The restrictions and limits imposed by a conforming implementation of C.
 * 
 * ISO/IEC 9899:2011 does not specify: * 
 * - The mechanism by which C programs are transformed for use by a data-processing system;
 * - The mechanism by which C programs are invoked for use by a data-processing system;
 * - The mechanism by which input data are transformed for use by a C program;
 * - The mechanism by which output data are transformed after being produced by a C program;
 * - The size or complexity of a program and its data that will exceed the capacity of any specific
 *   data-processing system or the capacity of a particular processor;
 * - All minimal requirements of a data-processing system that is capable of supporting a conforming implementation.
 * 
 * ISO/IEC 9899:2011 is designed to promote the portability of C programs among a variety of data-processing systems. 
 * It is intended for use by implementers and programmers.
 * 
 * \see <a href="http://www.iso.org/iso/catalogue_detail.htm?csnumber=57853">ISO Catalogue: ISO/IEC 9899:2011</a>
 * \see <a href="http://en.wikipedia.org/wiki/C_language">Wikipedia: C (Programming Language)</a>
 */
