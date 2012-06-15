/**
 * \file 
 * This file contains the constans and macros specified by \ref iso19784-1, section 7, <i>BioAPI types and macros</i>.
 * 
 * \section NO_VALUE_AVAILABLE NO_VALUE_AVAILABLE
 */
#ifndef BIOAPI_CONSTANTS_H
#define BIOAPI_CONSTANTS_H





#if defined WIN || defined WIN32 || defined WIN64 || defined _WIN || defined _WIN32 || defined _WIN64
    ///Uses <a href="http://en.wikipedia.org/wiki/X86_calling_conventions#stdcall">stdcall</a> calling 
    ///convention on Windows, default convention other platforms.
    #define BioAPI __stdcall
#else
    ///Uses <a href="http://en.wikipedia.org/wiki/X86_calling_conventions#stdcall">stdcall</a> calling 
    ///convention on Windows, default convention other platforms.
    #define BioAPI
#endif





/**
 * \name Boolean Constant Values
 * \see BioAPI_BOOL
 * \{
 */
#define BioAPI_FALSE (0)
#define BioAPI_TRUE  (1)
/** \} */ //Boolean Constant Values





/**
 * \name BIR Handle Constant Values
 * \see BioAPI_BIR_HANDLE
 * \{
 */
///Indicates that requested \ref bioapi_symbol_bir could not be create.
#define BioAPI_INVALID_BIR_HANDLE     (-1)
///Indicates that requested \ref bioapi_symbol_bir is not supported.
#define BioAPI_UNSUPPORTED_BIR_HANDLE (-2)
/** \} */ //BIR Handle Constant Values





/**
 * \name Product ID Constant Values
 * \see BioAPI_BIR_BIOMETRIC_PRODUCT_ID
 * \{
 */
///Indicates \ref NO_VALUE_AVAILABLE condition for a \link BioAPI_BIR_BIOMETRIC_PRODUCT_ID Product ID\endlink
#define BioAPI_NO_PRODUCT_TYPE_AVAILABLE  (0x0000)
///Indicates \ref NO_VALUE_AVAILABLE condition for a \link BioAPI_BIR_BIOMETRIC_PRODUCT_ID Product ID\endlink
#define BioAPI_NO_PRODUCT_OWNER_AVAILABLE (0x0000)
/** \} */ //Product ID Constant Values





/**
 * \name BIR Data Type Constant Values
 * \see BioAPI_BIR_DATA_TYPE
 * \{
 */
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
/** \} */ //BIR Data Type Constant Values





/**
 * \name Biometric Type Constant Values
 * \see BioAPI_BIR_BIOMETRIC_TYPE
 * \{
 */
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
/** \} */ //Biometric Type Constant Values





/**
 * \name BIR Subtype Constant Values
 * \see BioAPI_BIR_SUBTYPE
 * \{
 */
#define BioAPI_NO_SUBTYPE_AVAILABLE      (0x00)
#define BioAPI_BIR_SUBTYPE_LEFT          (0x01)
#define BioAPI_BIR_SUBTYPE_RIGHT         (0x02)
#define BioAPI_BIR_SUBTYPE_THUMB         (0x04)
#define BioAPI_BIR_SUBTYPE_POINTERFINGER (0x08)
#define BioAPI_BIR_SUBTYPE_MIDDLEFINGER  (0x10)
#define BioAPI_BIR_SUBTYPE_RINGFINGER    (0x20)
#define BioAPI_BIR_SUBTYPE_LITTLEFINGER  (0x40)
#define BioAPI_BIR_SUBTYPE_MULTIPLE      (0x80)
/** \} */ //BIR Subtype Constant Values





/**
 * \name BIR Purpose Constant Values
 * \see BioAPI_BIR_PURPOSE
 * \{
 */
#define BioAPI_NO_PURPOSE_AVAILABLE                   (0)
#define BioAPI_PURPOSE_IDENTIFY                       (1)
#define BioAPI_PURPOSE_ENROLL                         (2)
#define BioAPI_PURPOSE_ENROLL_FOR_VERIFICATION_ONLY   (3)
#define BioAPI_PURPOSE_ENROLL_FOR_IDENTIFICATION_ONLY (4)
#define BioAPI_PURPOSE_AUDIT                          (5)
/** \} */ //BIR Purpose Constant Values














#endif //BIOAPI_CONSTANTS_H
