/**
 * \file 
 * This file contains the data structures and macros specified by \ref iso19784-1, section 7, <i>BioAPI types and macros</i>.
 * 
 * \section NO_VALUE_AVAILABLE NO_VALUE_AVAILABLE
 */
#ifndef BIOAPI_TYPES_H
#define BIOAPI_TYPES_H

#include <inttypes.h>





#if defined WIN || defined WIN32 || defined WIN64 || defined _WIN || defined _WIN32 || defined _WIN64
    ///Uses <a href="http://en.wikipedia.org/wiki/X86_calling_conventions#stdcall">stdcall</a> calling 
    ///convention on Windows, default convention other platforms.
    #define BioAPI __stdcall
#else
    ///Uses <a href="http://en.wikipedia.org/wiki/X86_calling_conventions#stdcall">stdcall</a> calling 
    ///convention on Windows, default convention other platforms.
    #define BioAPI
#endif





//================================== BASIC TYPES ==============================================





/**
 * This data type is used to indicate a \a true or \a false condition.
 */
typedef  uint8_t BioAPI_BOOL;

#define BioAPI_FALSE    (0)
#define BioAPI_TRUE     (1)





/**
 * A mask that describes the set of biometric types (factors) contained within a BioAPI \ref bioapi_definition_bir 
 * or supported by a \ref bioapi_definition_bsp.
 * 
 * \note 
 * -# \ref BioAPI_TYPE_MULTIPLE is used to indicate that the \ref bioapi_definition_biometric_sample%s contained 
 *    within the \ref bioapi_definition_bdb include \ref bioapi_definition_biometric_sample%s from more than one type 
 *    of biometric sensor unit (e.g., fingerprint and facial data). Location of the individual samples within the BDB 
 *    is specified by the \ref BioAPI_BIR_BIOMETRIC_DATA_FORMAT.Owner "Format Owner" and identified by the value of the \ref BioAPI_BIR_BIOMETRIC_DATA_FORMAT.Type "Format Type".
 * -# The condition \ref NO_VALUE_AVAILABLE is indicated by setting the value to zero. BIRs that are not originally
 *    created by BioAPI BSPs should use this value when transformed into a BioAPI BIR if Biometric Type information is
 *    not available in the original source record. Transformed BIRs whose biometric type does not correspond to one of the
 *    defined types shall use the value for OTHER.
 * -# The \ref BioAPI_BIR_BIOMETRIC_TYPE corresponds to the “CBEFF_BDB_biometric_type” in \ref iso19785-1.
 */
typedef uint32_t BioAPI_BIR_BIOMETRIC_TYPE;

///\ref BioAPI_BIR_BIOMETRIC_TYPE "Biometric Type" used is Unknown.
#define BioAPI_NO_TYPE_AVAILABLE        (0x00000000)
///Multiple \ref BioAPI_BIR_BIOMETRIC_TYPE "Biometric Type" are used.
#define BioAPI_TYPE_MULTIPLE            (0x00000001)
///\ref BioAPI_BIR_BIOMETRIC_TYPE "Biometric Type" used is Facial.
#define BioAPI_TYPE_FACIAL_FEATURES     (0x00000002)
///\ref BioAPI_BIR_BIOMETRIC_TYPE "Biometric Type" used is Voice.
#define BioAPI_TYPE_VOICE               (0x00000004)
///\ref BioAPI_BIR_BIOMETRIC_TYPE "Biometric Type" used is Fingerprint.
#define BioAPI_TYPE_FINGERPRINT         (0x00000008)
///\ref BioAPI_BIR_BIOMETRIC_TYPE "Biometric Type" used is Iris.
#define BioAPI_TYPE_IRIS                (0x00000010)
///\ref BioAPI_BIR_BIOMETRIC_TYPE "Biometric Type" used is Retirna.
#define BioAPI_TYPE_RETINA              (0x00000020)
///\ref BioAPI_BIR_BIOMETRIC_TYPE "Biometric Type" used is Hand Geometry.
#define BioAPI_TYPE_HAND_GEOMETRY       (0x00000040)
///\ref BioAPI_BIR_BIOMETRIC_TYPE "Biometric Type" used is Signature.
#define BioAPI_TYPE_SIGNATURE_DYNAMICS  (0x00000080)
///\ref BioAPI_BIR_BIOMETRIC_TYPE "Biometric Type" used is Keystroke Dynamics.
#define BioAPI_TYPE_KEYSTOKE_DYNAMICS   (0x00000100)
///\ref BioAPI_BIR_BIOMETRIC_TYPE "Biometric Type" used is Lip Movement.
#define BioAPI_TYPE_LIP_MOVEMENT        (0x00000200)
///\ref BioAPI_BIR_BIOMETRIC_TYPE "Biometric Type" used is Thermal Face Image.
#define BioAPI_TYPE_THERMAL_FACE_IMAGE  (0x00000400)
///\ref BioAPI_BIR_BIOMETRIC_TYPE "Biometric Type" used is Thermal Hand Image.
#define BioAPI_TYPE_THERMAL_HAND_IMAGE  (0x00000800)
///\ref BioAPI_BIR_BIOMETRIC_TYPE "Biometric Type" used is Gait.
#define BioAPI_TYPE_GAIT                (0x00001000)
///Other (unregistered) \ref BioAPI_BIR_BIOMETRIC_TYPE "Biometric Type" is used.
#define BioAPI_TYPE_OTHER               (0x40000000)
///\ref BioAPI_BIR_BIOMETRIC_TYPE "Biometric Type" used is Password.
#define BioAPI_TYPE_PASSWORD            (0x80000000)





/**
 * This data type is used for three different purposes:
 * - it identifies the type of biometric sample (raw, intermediate, or processed) that is contained in the BDB;
 * - it identifies whether the BioAPI \ref bioapi_symbol_bir is encrypted and/or signed;
 * - it identifies whether or not an index value is included as part of the BIR header.
 * 
 * \note If the BIR has been encrypted by a BSP, it may not be readable by an application or by another BSP.
 *
 * Exactly one of the three flags "raw", "intermediate" and "processed" shall be set. If a BIR carrying a
 * BIR data type with multiple flags set is passed to the BioAPI Framework in a parameter of a function call, a
 * BioAPIERR_INVALID_BIR error shall be returned.
 * 
 * \note BIRs that are not originally created by a BioAPI BSP but have been transformed from another data format
 * and for which sample type information is not available may not have set a flag. (BioAPI BSPs set one of the three
 * flags.)
 * 
 * Each of the flags "encrypted" and "signed" may or may not be set.
 * 
 * The ‘index’ flag shall be set if an index is present in the BIR header and not set if no index is present 
 * in the BIR header.
 * 
 * \note The BioAPI BIR Data Type corresponds to a combination of the “CBEFF_BDB_processed_level”,
“CBEFF_BDB_encryption_options”, and “CBEFF_BIR_integrity_options” in ISO/IEC 19785-1.
 */
typedef uint8_t BioAPI_BIR_DATA_TYPE;

///Identifies the \link BioAPI_BIR_DATA_TYPE type\endlink of a \ref bioapi_symbol_bir as "Raw".
#define BioAPI_BIR_DATA_TYPE_RAW          (0x01)
///Identifies the \link BioAPI_BIR_DATA_TYPE type\endlink of a \ref bioapi_symbol_bir as "Intermediate".
#define BioAPI_BIR_DATA_TYPE_INTERMEDIATE (0x02)
///Identifies the \link BioAPI_BIR_DATA_TYPE type\endlink of a \ref bioapi_symbol_bir as "Processed".
#define BioAPI_BIR_DATA_TYPE_PROCESSED    (0x04)
///Identifies whenever the \link BioAPI_BIR_DATA_TYPE type\endlink of a \ref bioapi_symbol_bir is encrypted.
#define BioAPI_BIR_DATA_TYPE_ENCRYPTED    (0x10)
///Identifies whenever the \link BioAPI_BIR_DATA_TYPE type\endlink of a \ref bioapi_symbol_bir is signed.
#define BioAPI_BIR_DATA_TYPE_SIGNED       (0x20)
///Identifies whenever the \link BioAPI_BIR_DATA_TYPE type\endlink of a \ref bioapi_symbol_bir is indexed.
#define BioAPI_BIR_INDEX_PRESENT           (0x80)





/**
 * A \ref bioapi_definition_handle to refer to a \ref bioapi_definition_bir that exists within a \ref bioapi_definition_bsp.
 * 
 * \note A \ref bioapi_definition_handle that identifies a \ref bioapi_definition_bir is a positive non-zero value. 
 * Other values of \ref BioAPI_BIR_HANDLE are reserved for exception indications
 * (currently only \ref BioAPI_INVALID_BIR_HANDLE and \ref BioAPI_UNSUPPORTED_BIR_HANDLE).
 */
typedef int32_t BioAPI_BIR_HANDLE;

///Indicates that requested \ref bioapi_symbol_bir could not be create.
#define BioAPI_INVALID_BIR_HANDLE     (-1)
///Indicates that requested \ref bioapi_symbol_bir is not supported.
#define BioAPI_UNSUPPORTED_BIR_HANDLE (-2)





/**
 * A value which defines the purpose for which the BioAPI BIR is intended (when used as an input to a BioAPI function) 
 * or is suitable (when used as an output from a BioAPI function or within the BIR header).
 * 
 * \note The condition NO VALUE AVAILABLE is indicated by setting the value to zero. This value is used only for
 * BIRs that are not originally generated by a BioAPI BSP, but originate from another source and have been
 * transformed into a BioAPI BIR. BSPs shall not use this value.
 * 
 * The Purpose value is utilized in two ways. First, it is used as an input parameter to allow the
 * application to indicate to the BSP the purpose for which the resulting BIR is intended, thus allowing the BSP to
 * perform the appropriate capturing and/or processing to create the proper BIR for this purpose. The second
 * use is within the BIR header to indicate to the application (or to the BSP during subsequent operations) what
 * purpose the BIR is suitable for. For example, some BSPs use different BDB formats depending on whether
 * the data is to be used for verification or identification, the latter generally including additional information to
 * enhance speed or accuracy. Similarly, many BSPs use different data formats depending on whether the data
 * is to be used as a sample for immediate verification or as a reference template for future matching (i.e.,
 * enrollment).
 * 
 * \note The BioAPI BIR Purpose in a BIR header corresponds to the “CBEFF_BDB_purpose” in ISO/IEC 19785-1.
 * The names differ slightly since the BioAPI BIR contains a single BDB, but the semantics are the same.
 * 
 * Restrictions on the use of BIR data of a particular purpose include:
 * -# All purposes are valid in the BIR header.
 * -# Purposes of BioAPI_PURPOSE_VERIFY and BioAPI_PURPOSE_IDENTIFY are only valid as input
 *    to the BioAPI_Capture function.
 * -# Purposes of BioAPI_PURPOSE_ENROLL, BioAPI_PURPOSE_ENROLL_FOR_VERIFICATION_ONLY, and 
 *    BioAPI_PURPOSE_ENROLL_FOR_IDENTIFICATION_ONLY are only valid as input to the BioAPI_Capture, BioAPI_Enroll, and BioAPI_Import functions.
 * -# The BioAPI_PURPOSE_AUDIT purpose is not valid as input to any function, but is only used in the BIR header.
 * -# The BioAPI_Process, BioAPI_CreateTemplate, and BioAPI_ProcessWithAuxData functions do 
 *    not have Purpose as an input parameter, but read the Purpose field from the BIR header of the input CapturedBIR.
 * -# The BioAPI_Process function may accept as input any intermediate BIR with a Purpose of
 *    BioAPI_PURPOSE_VERIFY or BioAPI_PURPOSE_IDENTIFY, and shall output only BIRs with the
 *    same purpose as the input BIR.
 * -# The BioAPI_CreateTemplate function may accept as input any intermediate BIR with a Purpose of
 * BioAPI_PURPOSE_ENROLL, BioAPI_PURPOSE_ENROLL_FOR_VERIFICATION_ONLY, or BioAPI_PURPOSE_ENROLL_FOR_IDENTFICATION_ONLY, 
 * and shall output only BIRs with the same Purpose as the input BIR.
 */
typedef uint8_t BioAPI_BIR_PURPOSE;

#define BioAPI_NO_PURPOSE_AVAILABLE                   (0)
#define BioAPI_PURPOSE_VERIFY                         (1)
#define BioAPI_PURPOSE_IDENTIFY                       (2)
#define BioAPI_PURPOSE_ENROLL                         (3)
#define BioAPI_PURPOSE_ENROLL_FOR_VERIFICATION_ONLY   (4)
#define BioAPI_PURPOSE_ENROLL_FOR_IDENTIFICATION_ONLY (5)
#define BioAPI_PURPOSE_AUDIT                          (6)





/**
 * This identifies a subtype within the BDB type (specified in the BioAPI_BIR_BIOMETRIC_TYPE). 
 * 
 * Its values and their meaning are defined by the specifier of that BDB type.
 * 
 * Each of the feature flags BioAPI_BIR_SUBTYPE_LEFT and BioAPI_BIR_SUBTYPE_RIGHT may or may not be set (zero, one, or both).
 * 
 * Either none or exactly one of the five finger subtypes may be set.
 *
 * \note
 * -# The condition NO VALUE AVAILABLE is indicated by setting the value to zero. BIRs that are not
 *    originally created by a BioAPI BSP but have been transformed from another data format and for which subtype
 *    information is not available may use this value.
 * -# The BioAPI BIR Subtype corresponds to the “CBEFF_BDB_biometric_subtype” in ISO/IEC 19785-1.
 * -# This structure is primarily used within a BIR header; however, it is also used as an input parameter for
 *    functions that capture biometric data. The BioAPI_NO_SUBTYPE_AVAILABLE value is used in the BIR header
 *    when either this field is not applicable or information is not available. BioAPI_NO_SUBTYPE_AVAILABLE is
 *    also used as a function parameter when the application allows the BSP to determine which subtype is to be
 *    captured.
 */
typedef uint8_t  BioAPI_BIR_SUBTYPE;

#define BioAPI_NO_SUBTYPE_AVAILABLE      (0x00)
#define BioAPI_BIR_SUBTYPE_LEFT          (0x01)
#define BioAPI_BIR_SUBTYPE_RIGHT         (0x02)
#define BioAPI_BIR_SUBTYPE_THUMB         (0x04)
#define BioAPI_BIR_SUBTYPE_POINTERFINGER (0x08)
#define BioAPI_BIR_SUBTYPE_MIDDLEFINGER  (0x10)
#define BioAPI_BIR_SUBTYPE_RINGFINGER    (0x20)
#define BioAPI_BIR_SUBTYPE_LITTLEFINGER  (0x40)
#define BioAPI_BIR_SUBTYPE_MULTIPLE      (0x80)





typedef uint32_t    BioAPI_CATEGORY;

#define BioAPI_CATEGORY_ARCHIVE         (0x00000001)
#define BioAPI_CATEGORY_MATCHING_ALG    (0x00000002)
#define BioAPI_CATEGORY_PROCESSING_ALG  (0x00000004)
#define BioAPI_CATEGORY_SENSOR          (0x00000008)





typedef uint32_t    BioAPI_DB_ACCESS_TYPE;

#define BioAPI_DB_ACCESS_READ           (0x00000001)
#define BioAPI_DB_ACCESS_WRITE          (0x00000002)





typedef uint32_t    BioAPI_DB_MARKER_HANDLE;





typedef  int32_t    BioAPI_DB_HANDLE;

#define BioAPI_DB_INVALID_HANDLE        (-1)
#define BioAPI_DB_DEFAULT_HANDLE        (0)
#define BioAPI_DB_DEFAULT_UUID_PTR      (NULL)





typedef uint32_t    BioAPI_EVENT;

#define BioAPI_NOTIFY_INSERT            (1)
#define BioAPI_NOTIFY_REMOVE            (2)
#define BioAPI_NOTIFY_FAULT             (3)
#define BioAPI_NOTIFY_SOURCE_PRESENT    (4)
#define BioAPI_NOTIFY_SOURCE_REMOVED    (5)





typedef uint32_t    BioAPI_EVENT_MASK;

#define BioAPI_NOTIFY_INSERT_BIT          (0x00000001)
#define BioAPI_NOTIFY_REMOVE_BIT          (0x00000002)
#define BioAPI_NOTIFY_FAULT_BIT           (0x00000004)
#define BioAPI_NOTIFY_SOURCE_PRESENT_BIT  (0x00000008)
#define BioAPI_NOTIFY_SOURCE_REMOVED_BIT  (0x00000010)





typedef int32_t     BioAPI_FMR;

#define BioAPI_NOT_SET              (-1)





typedef uint32_t    BioAPI_GUI_MESSAGE;





typedef uint8_t     BioAPI_GUI_PROGRESS;





typedef uint8_t     BioAPI_GUI_RESPONSE;

#define BioAPI_CAPTURE_SAMPLE    (1)  // Instruction to BSP to capture sample
#define BioAPI_CANCEL            (2)  // User cancelled operation
#define BioAPI_CONTINUE          (3)  // User or application selects to proceed
#define BioAPI_VALID_SAMPLE      (4)  // Valid sample received
#define BioAPI_INVALID_SAMPLE    (5)  // Invalid sample received





typedef uint32_t    BioAPI_GUI_STATE;

#define BioAPI_SAMPLE_AVAILABLE (0x0001)    // Sample captured and available
#define BioAPI_MESSAGE_PROVIDED (0x0002)    // BSP provided message for display
#define BioAPI_PROGRESS_PROVIDED (0x0004)   // BSP provide progress for display





typedef uint32_t    BioAPI_HANDLE;





typedef uint8_t     BioAPI_IDENTIFY_POPULATION_TYPE;

#define BioAPI_DB_TYPE             (1)
#define BioAPI_ARRAY_TYPE          (2)
#define BioAPI_PRESET_ARRAY_TYPE   (3)





typedef uint8_t     BioAPI_INDICATOR_STATUS;

#define BioAPI_INDICATOR_ACCEPT         (1)
#define BioAPI_INDICATOR_REJECT         (2)
#define BioAPI_INDICATOR_READY          (3)
#define BioAPI_INDICATOR_BUSY           (4)
#define BioAPI_INDICATOR_FAILURE        (5)





typedef uint8_t     BioAPI_INPUT_BIR_FORM;

#define BioAPI_DATABASE_ID_INPUT (1)
#define BioAPI_BIR_HANDLE_INPUT  (2)
#define BioAPI_FULLBIR_INPUT     (3)





typedef uint32_t    BioAPI_INSTALL_ACTION;

#define BioAPI_INSTALL_ACTION_INSTALL   (1)
#define BioAPI_INSTALL_ACTION_REFRESH   (2)
#define BioAPI_INSTALL_ACTION_UNINSTALL (3)





typedef uint32_t    BioAPI_OPERATIONS_MASK;

#define BioAPI_ENABLEEVENTS             (0x00000001)
#define BioAPI_SETGUICALLBACKS          (0x00000002)
#define BioAPI_CAPTURE                  (0x00000004)
#define BioAPI_CREATETEMPLATE           (0x00000008)
#define BioAPI_PROCESS                  (0x00000010)
#define BioAPI_PROCESSWITHAUXBIR        (0x00000020)
#define BioAPI_VERIFYMATCH              (0x00000040)
#define BioAPI_IDENTIFYMATCH            (0x00000080)
#define BioAPI_ENROLL                   (0x00000100)
#define BioAPI_VERIFY                   (0x00000200)
#define BioAPI_IDENTIFY                 (0x00000400)
#define BioAPI_IMPORT                   (0x00000800)
#define BioAPI_PRESETIDENTIFYPOPULATION (0x00001000)
#define BioAPI_DATABASEOPERATIONS       (0x00002000)
#define BioAPI_SETPOWERMODE             (0x00004000)
#define BioAPI_SETINDICATORSTATUS       (0x00008000)
#define BioAPI_GETINDICATORSTATUS       (0x00010000)
#define BioAPI_CALIBRATESENSOR          (0x00020000)
#define BioAPI_UTILITIES                (0x00040000)
#define BioAPI_QUERYUNITS               (0X00100000)
#define BioAPI_QUERYBFPS                (0x00200000)
#define BioAPI_CONTROLUNIT              (0x00400000)





typedef uint32_t    BioAPI_OPTIONS_MASK;

#define BioAPI_RAW                  (0x00000001)
#define BioAPI_QUALITY_RAW          (0x00000002)
#define BioAPI_QUALITY_INTERMEDIATE (0x00000004)
#define BioAPI_QUALITY_PROCESSED    (0x00000008)
#define BioAPI_APP_GUI              (0x00000010)
#define BioAPI_STREAMINGDATA        (0x00000020)
#define BioAPI_SOURCEPRESENT        (0x00000040)
#define BioAPI_PAYLOAD              (0x00000080)
#define BioAPI_BIR_SIGN             (0x00000100)
#define BioAPI_BIR_ENCRYPT          (0x00000200)
#define BioAPI_TEMPLATEUPDATE       (0x00000400)
#define BioAPI_ADAPTATION           (0x00000800)
#define BioAPI_BINNING              (0x00001000)
#define BioAPI_SELFCONTAINEDDEVICE  (0x00002000)
#define BioAPI_MOC                  (0x00004000)
#define BioAPI_SUBTYPE_TO_CAPTURE   (0x00008000)
#define BioAPI_SENSORBFP            (0x00010000)
#define BioAPI_ARCHIVEBFP           (0x00020000)
#define BioAPI_MATCHINGBFP          (0x00040000)
#define BioAPI_PROCESSINGBFP        (0x00080000)
#define BioAPI_COARSESCORES         (0x00100000)





typedef uint32_t BioAPI_POWER_MODE;

/** All functions available */
#define BioAPI_POWER_NORMAL         (1)
/** Able to detect (for example) insertion/finger on/person present type of events */
#define BioAPI_POWER_DETECT         (2)
/** Minimum mode. All functions off */
#define BioAPI_POWER_SLEEP          (3)





typedef int8_t      BioAPI_QUALITY;





typedef uint32_t    BioAPI_RETURN;

#define BioAPI_OK   (0)





typedef uint8_t     BioAPI_STRING[269];





typedef uint32_t    BioAPI_UNIT_ID;

#define BioAPI_DONT_CARE        (0x0000000)
#define BioAPI_DONT_INCLUDE     (0xFFFFFFF)





typedef uint8_t     BioAPI_UUID[16];





typedef uint8_t     BioAPI_VERSION;





//================================== COMPLEX TYPES ==============================================





/**
 * Defines the format of the data contained within the “opaque” biometric data block (BDB) of the BioAPI BIR, BiometricData element.
 * 
 * FormatOwner values are assigned and registered by the <a href="http://www.ibia.org/cbeff/iso/">CBEFF Registration Authority</a> (see \ref iso19785-2). 
 * Format Type is assigned by the Format Owner and may optionally be registered.
 * 
 * \note 
 * -# The BioAPI BIR Biometric Data Format corresponds to a combination of the “CBEFF_BDB_format_owner” and “CBEFF_BDB_format_type” in \ref iso19785-1.
 * -# This structure is primarily used within a BIR header; however, it is also used as an input parameter for functions that capture biometric data.
 */
typedef struct bioapi_bir_biometric_data_format {
    ///Vendor code, assigned by the CBEFF Registration Authority.
    uint16_t FormatOwner;
    ///Format type, assigned by owner and optionally registered.
    uint16_t FormatType;
} BioAPI_BIR_BIOMETRIC_DATA_FORMAT;





typedef struct bioapi_data {
    uint32_t                Length;
    void                    *Data;
} BioAPI_DATA;





typedef struct bioapi_gui_bitmap {
  uint32_t Width;   // Width of bitmap in pixels (number of pixels for each
                    // line)
  uint32_t Height;  // Height of bitmap in pixels (number of lines)
  BioAPI_DATA Bitmap;
} BioAPI_GUI_BITMAP;





typedef struct bioapi_date {
    uint16_t                Year;  // valid range: 1900  9999
                                   // valid range: 01  12
    uint8_t                 Month;
    uint8_t                 Day;   // valid range: 01  31, consistent with
                                   // associated month/year
} BioAPI_DATE;

#define BioAPI_NO_YEAR_AVAILABLE        (0)
#define BioAPI_NO_MONTH_AVAILABLE       (0)
#define BioAPI_NO_DAY_AVAILABLE         (0)





typedef struct bioapi_time {
    uint8_t                 Hour;  // valid range: 00  23, 99
                                   // valid range: 00  59, 99
    uint8_t                 Minute;
                                   // valid range: 00  59, 99
    uint8_t                 Second;
} BioAPI_TIME;

#define BioAPI_NO_HOUR_AVAILABLE        (99)
#define BioAPI_NO_MINUTE_AVAILABLE      (99)
#define BioAPI_NO_SECOND_AVAILABLE      (99)





typedef struct bioapi_DTG {
  BioAPI_DATE Date;
  BioAPI_TIME Time;
} BioAPI_DTG;





/**
 * Provides the product identifier (PID) for the BSP that generated the BDB in the BIR (the BiometricData element).
 * 
 * The condition \ref NO_VALUE_AVAILABLE shall be indicated by setting the value of all components to zero. This
 * value shall be used only for BIRs that are not originally generated by a BioAPI BSP, but originate from another
 * source and have been transformed into a BioAPI BIR. BSPs shall not use this value.
 * 
 * Product Owner values are assigned and registered by the <a href="http://www.ibia.org/cbeff/iso/">CBEFF Registration Authority</a> as Biometric
 * Organization identifiers (see ISO/IEC 19785-2). Product Type is assigned by the Product Owner and may
 * optionally be registered.
 * 
 * \note Product IDs are analogous to Format IDs and the registration process is the same. A single vendor can 
 * register for one Format/Product Owner value (a Biometric Organization identifier) that can be used in both fields.
 * 
 * \note The BioAPI BIR Biometric Product ID corresponds to the “CBEFF_BDB_product_owner” and 
 * “CBEFF_BDB_product_type” in ISO/IEC 19785-1.
 */
typedef struct bioapi_bir_biometric_product_ID {
    ///Vendor code, assigned by the CBEFF Registration Authority.
    uint16_t ProductOwner;
    ///Product type, assigned by owner and optionally registered.
    uint16_t ProductType;
} BioAPI_BIR_BIOMETRIC_PRODUCT_ID;

///Indicates \ref NO_VALUE_AVAILABLE condition for a \link BioAPI_BIR_BIOMETRIC_PRODUCT_ID Product ID\endlink
#define BioAPI_NO_PRODUCT_TYPE_AVAILABLE  (0x0000)
///Indicates \ref NO_VALUE_AVAILABLE condition for a \link BioAPI_BIR_BIOMETRIC_PRODUCT_ID Product ID\endlink
#define BioAPI_NO_PRODUCT_OWNER_AVAILABLE (0x0000)





/**
 * Defines the format of the data contained within the security block (SB) of the BioAPI BIR (SecurityBlock element).
 * 
 * If neither the ‘encrypt’ or ‘signed’ flags are set within the BioAPI_BIR_DATA_TYPE field of the BIR Header, 
 * then the SecurityFormatOwner and SecurityFormatType are each set to 0x0000 and no security block is present.
 * 
 * SecurityFormatOwner values are assigned and registered by the <a href="http://www.ibia.org/cbeff/iso/">CBEFF 
 * Registration  Authority</a> as Biometric Organization identifiers (see ISO/IEC 19785-2). Security Format Type 
 * is assigned by the Security Format Owner (the Biometric Organization) and may optionally be registered.
 * 
 * \note Security Format IDs are analogous to Format IDs and the registration process is the same. A single vendor 
 * can register for one Format/Product/Security Owner value (a Biometric Organization identifier) that can be used 
 * in all associated fields.
 * 
 * \note The content of the security block itself may include a digital signature or message authentication code 
 * (calculated on the BIR Header + BDB), BDB encryption parameters (e.g., encryption algorithm, key length), and/or 
 * BIR integrity parameters (e.g., algorithm ID, keyname, version).
 * 
 * \note  The BioAPI BIR security block Format in a BioAPI BIR header corresponds to the “CBEFF_SB_format_owner” and 
 * “CBEFF_SB_format_type” in ISO/IEC 19785-1.
 */
typedef struct bioapi_bir_security_block_format {
    ///Vendor code, assigned by the CBEFF Registration Authority.
    uint16_t SecurityFormatOwner;
    ///Security Block Format type, assigned by owner and optionally registered.
    uint16_t SecurityFormatType;
} BioAPI_BIR_SECURITY_BLOCK_FORMAT;







/**
 * Identifies a \ref bioapi_definition_bfp, giving its category and \ref bioapi_symbol_uuid. 
 * 
 * A list is returned by a \ref bioapi_definition_bsp when queried for the installed \ref bioapi_definition_bfp "BFP"s that it supports* (\ref BioAPI_QueryBFPs).
 */
typedef struct bioapi_bfp_list_element {
    ///Defines the category of the \ref bioapi_definition_unit that the \ref bioapi_definition_bfp supports.
    BioAPI_CATEGORY BFPCategory; 
    ///\ref bioapi_definition_uuid of the \ref bioapi_definition_bfp in the \ref bioapi_definition_component_registry.
    BioAPI_UUID BFPUuid;         
} BioAPI_BFP_LIST_ELEMENT;





/**
 * Information about a \ref bioapi_definition_bfp, maintained in the \ref bioapi_definition_component_registry.
 */
typedef struct bioapi_bfp_schema {
    ///\ref bioapi_definition_uuid of the \ref bioapi_definition_bfp.  
    BioAPI_UUID BFPUuid;                                   
    ///Category of the \ref bioapi_definition_component_registry identified by the \a BFPUuid.
    BioAPI_CATEGORY BFPCategory;                           
    ///A NULL-terminated string containing a text description of the \ref bioapi_definition_bfp.
    BioAPI_STRING BFPDescription;                          
    ///A pointer to a NULL-terminated string containing the path of the \ref bioapi_definition_bfp file, 
    ///including the filename. The path may be a URL. 
    ///\note When \ref BioAPI_BFP_SCHEMA is used within a function call, the component that receives 
    ///the call allocates the memory for the \a Path schema element and the calling component frees the memory.
    uint8_t *Path;
    ///Major/minor version number of the \ref bioapi_symbol_fpi specification to which the \ref bioapi_definition_bfp was implemented.
    BioAPI_VERSION SpecVersion;
    ///The version string of the \ref bioapi_definition_bfp software.
    BioAPI_STRING ProductVersion;
    ///A NULL-terminated string containing the name of the \ref bioapi_definition_bfp vendor.
    BioAPI_STRING Vendor;
    ///A pointer to an array of \ref BioAPI_BIR_BIOMETRIC_DATA_FORMAT structures specifying the supported \ref bioapi_definition_bdb formats.
    BioAPI_BIR_BIOMETRIC_DATA_FORMAT *BFPSupportedFormats;
    ///Number of supported formats contained in \a BFPSupportedFormats.
    uint32_t NumSupportedFormats;
    ///A mask which indicates which biometric types are supported by the \ref bioapi_definition_bfp.
    BioAPI_BIR_BIOMETRIC_TYPE FactorsMask;
    ///\ref bioapi_definition_uuid of the format of the following \ref bioapi_definition_bfp property.
    BioAPI_UUID BFPPropertyID;
    ///Address and length of a memory buffer containing the \ref bioapi_definition_bfp property. 
    ///The format and content of the \ref bioapi_definition_bfp property can either be specified by a vendor or can be specified in a related standard.
    BioAPI_DATA BFPProperty;
} BioAPI_BFP_SCHEMA;





/**
 * Standard information which describes the content of the opaque \ref bioapi_definition_bdb that follows. This
 * information is readable by the application and is provided to allow it to make processing and routing decisions
 * regarding the \ref bioapi_definition_bir. The header is not encrypted by the \ref bioapi_definition_bsp.
 * 
 * \note 
 *  -# The \ref BioAPI_BIR_HEADER corresponds to the <i>SBH</i> in \ref iso19785-1.
 *  -# The \a ExpirationDate field corresponds to the <i>Valid to</i> portion of the <i>CBEFF_BDB_validity_period</i> in 
 *     \ref iso19785-1. The \a Index field corresponds to the <i>CBEFF_BDB_index</i> in \ref iso19785-1.
 *  -# It is possible that a \ref BioAPI_BIR may exist that has not been created by a BioAPI \ref bioapi_definition_bsp but has been
 *     transformed from another data format. In this case, some of the header fields that are optional in \ref iso19785-1
 *     but required by BioAPI may not be present. For this reason, NO_VALUE_AVAILABLE or default values have been identified 
 *     for these fields (within their corresponding data structures). However, all BIRs created by BioAPI BSPs shall include 
 *     valid data for these fields and shall not use the NO VALUE AVAILABLE value. (The exceptions to this are BioAPI_QUALITY 
 *     and BioAPI_BIR_SUBTYPE, which are optional in the BioAPI BIR header.) 
 *     If such a non-BioAPI generated BIR is provided as an input parameter to a BioAPI BSP, the BSP may return an
 *    \ref BioAPIERR_INVALID_BIR error.
 *  -# The storage format for the BIR includes explicit length fields, which are not necessary in the C structure. 
 *     See Annex B for the BIR storage format.
 */
typedef struct bioapi_bir_header {
    BioAPI_VERSION HeaderVersion;
    BioAPI_BIR_DATA_TYPE Type;
    BioAPI_BIR_BIOMETRIC_DATA_FORMAT Format;
    BioAPI_QUALITY Quality;
    BioAPI_BIR_PURPOSE Purpose;
    BioAPI_BIR_BIOMETRIC_TYPE FactorsMask;
    BioAPI_BIR_BIOMETRIC_PRODUCT_ID ProductID;
    BioAPI_DTG CreationDTG;
    BioAPI_BIR_SUBTYPE Subtype;
    BioAPI_DATE ExpirationDate;
    BioAPI_BIR_SECURITY_BLOCK_FORMAT SBFormat;
    BioAPI_UUID Index;
} BioAPI_BIR_HEADER;





/**
 * A \ref bioapi_definition_bir is a container for biometric data.
 * 
 * A \ref BioAPI_BIR consists of a \ref BioAPI_BIR_HEADER, a \ref bioapi_definition_bdb, and an optional \ref bioapi_definition_sb. 
 * 
 * The \ref bioapi_definition_bdb may contain \ref bioapi_definition_raw_biometric_sample data, partially processed 
 * (\ref bioapi_definition_intermediate_biometric_sample) data, or completely \ref bioapi_definition_processed_biometric_sample 
 * data. The \ref BioAPI_BIR may be used to \ref bioapi_definition_enrollment "Enroll" a user (thus being stored persistently), or may be
 * used to \ref bioapi_definition_verification "verify" or \ref bioapi_definition_identification "identify" a user
 * (thus being used transiently).
 * 
 * The \ref bioapi_definition_bdb and \ref bioapi_definition_sb are an integral number of octets and are of variable length, up to 
 * \f$2^{32}-1\f$ octets. If the \ref bioapi_definition_sb contains a signature, it is calculated on the combined \ref BioAPI_BIR_HEADER 
 * and \ref bioapi_definition_bdb.
 * 
 * \note The BioAPI \ref bioapi_definition_bir contains the information needed for a CBEFF Patron Format as defined in the Common
 * Biometric Exchange Formats Framework (CBEFF), \ref iso19785-1. See Annex B for the specification of the BioAPI
 * BIR Patron Format, including internetworking and storage formats.
 * 
 * \note The format of the \ref bioapi_definition_bdb and \ref bioapi_definition_sb are determined by the
 * \ref BioAPI_BIR_BIOMETRIC_DATA_FORMAT and \ref BioAPI_BIR_SECURITY_BLOCK_FORMAT elements of the
 * \ref BioAPI_BIR_HEADER respectively.
 * 
 * \note CBEFF (\ref iso19785-1) allows the possibility of different \ref bioapi_definition_bir formats from that supported by BioAPI.
 * Conversion between the BioAPI \ref bioapi_definition_bir format and other \ref bioapi_definition_bir formats is specifed in \ref iso19785-1.
 */
typedef struct bioapi_bir {
    ///Header, contains BDB and SB formats and other information.
    BioAPI_BIR_HEADER Header;
    ///Raw sample data, partially processed (intermediate) data, or completely processed data.
    BioAPI_DATA BiometricData;
    ///Optional Security Data Block, may signature and/or encryption information. <tt>SecurityBlock.Data=NULL</tt> if no SB.
    BioAPI_DATA SecurityBlock;
} BioAPI_BIR;





/**
 * An array of BIRs, generally used during identification operations 
 * (as input to BioAPI_Identify or BioAPI_IdentifyMatch as part of BioAPI_IDENTIFY_POPULATION).
 */
typedef struct bioapi_bir_array_population {
    ///Size of array of BIRs.
    uint32_t NumberOfMembers;
    ///A pointer to an array of BIRs.
    BioAPI_BIR *Members;
} BioAPI_BIR_ARRAY_POPULATION;

































typedef struct install_error {
  BioAPI_RETURN ErrorCode;
  BioAPI_STRING ErrorString;
} BioAPI_INSTALL_ERROR;

typedef struct bioapi_dbbir_id {
  BioAPI_DB_HANDLE DbHandle;
  BioAPI_UUID KeyValue;
} BioAPI_DBBIR_ID;

typedef struct bioapi_candidate {
  BioAPI_IDENTIFY_POPULATION_TYPE Type;
  union {
    BioAPI_UUID *BIRInDataBase;
    uint32_t    *BIRInArray;
  } BIR;
  BioAPI_FMR    FMRAchieved;
} BioAPI_CANDIDATE;



typedef struct bioapi_framework_schema {
  BioAPI_UUID FrameworkUuid;
  BioAPI_STRING FwDescription;
  uint8_t *Path;
  BioAPI_VERSION SpecVersion;
  BioAPI_STRING ProductVersion;
  BioAPI_STRING Vendor;
  BioAPI_UUID FwPropertyId;
  BioAPI_DATA FwProperty;
} BioAPI_FRAMEWORK_SCHEMA;


typedef struct bioapi_input_bir {
  BioAPI_INPUT_BIR_FORM Form;
  union {
    BioAPI_DBBIR_ID *BIRinDb;
    BioAPI_BIR_HANDLE *BIRinBSP;
    BioAPI_BIR *BIR;
  } InputBIR;
} BioAPI_INPUT_BIR;


typedef struct bioapi_identify_population {
  BioAPI_IDENTIFY_POPULATION_TYPE Type;
  union {
    BioAPI_DB_HANDLE *BIRDataBase;
    BioAPI_BIR_ARRAY_POPULATION *BIRArray;
  } BIRs;
} BioAPI_IDENTIFY_POPULATION;

typedef struct bioapi_bsp_schema {
    BioAPI_UUID                 BSPUuid;
    BioAPI_STRING               BSPDescription;
    uint8_t                     *Path;
    BioAPI_VERSION              SpecVersion;
    BioAPI_STRING               ProductVersion;
    BioAPI_STRING               Vendor;
    BioAPI_BIR_BIOMETRIC_DATA_FORMAT    *BSPSupportedFormats;
    uint32_t                    NumSupportedFormats;
    BioAPI_BIR_BIOMETRIC_TYPE   FactorsMask;
    BioAPI_OPERATIONS_MASK      Operations;
    BioAPI_OPTIONS_MASK         Options;
    BioAPI_FMR                  PayloadPolicy;
    uint32_t                    MaxPayloadSize;
    int32_t                     DefaultVerifyTimeout;
    int32_t                     DefaultIdentifyTimeout;
    int32_t                     DefaultCaptureTimeout;
    int32_t                     DefaultEnrollTimeout;
    int32_t                     DefaultCalibrateTimeout;
    uint32_t                    MaxBSPDbSize;
    uint32_t                    MaxIdentify;
} BioAPI_BSP_SCHEMA;

typedef struct bioapi_unit_list_element {
    BioAPI_CATEGORY             UnitCategory;
    BioAPI_UNIT_ID              UnitId;
} BioAPI_UNIT_LIST_ELEMENT;

typedef struct bioapi_unit_schema {
    BioAPI_UUID                 BSPUuid;
    BioAPI_UUID                 UnitManagerUuid;
    BioAPI_UNIT_ID              UnitId;
    BioAPI_CATEGORY             UnitCategory;
    BioAPI_UUID                 UnitProperties;
    BioAPI_STRING               VendorInformation;
    uint32_t                    SupportedEvents;
    BioAPI_UUID                 UnitPropertyID;
    BioAPI_DATA                 UnitProperty;
    BioAPI_STRING               HardwareVersion;
    BioAPI_STRING               FirmwareVersion;
    BioAPI_STRING               SoftwareVersion;
    BioAPI_STRING               HardwareSerialNumber;
    BioAPI_BOOL                 AuthenticatedHardware;
    uint32_t                    MaxBSPDbSize;
    uint32_t                    MaxIdentify;
} BioAPI_UNIT_SCHEMA;





//================================== CALLBACKS ==============================================





typedef BioAPI_RETURN (BioAPI *BioAPI_EventHandler)(
    const BioAPI_UUID *BSPUuid,
    BioAPI_UNIT_ID UnitID,
    void* AppNotifyCallbackCtx,
    const BioAPI_UNIT_SCHEMA *UnitSchema,
    BioAPI_EVENT EventType
);





typedef BioAPI_RETURN (*BioAPI_GUI_STATE_CALLBACK)(
    void *GuiStateCallbackCtx,
    BioAPI_GUI_STATE GuiState,
    BioAPI_GUI_RESPONSE *Response,
    BioAPI_GUI_MESSAGE Message,
    BioAPI_GUI_PROGRESS Progress,
    const BioAPI_GUI_BITMAP *SampleBuffer
);





typedef BioAPI_RETURN (*BioAPI_GUI_STREAMING_CALLBACK)(
    void *GuiStreamingCallbackCtx,
    const BioAPI_GUI_BITMAP *Bitmap
);





#endif //BIOAPI_TYPES_H
