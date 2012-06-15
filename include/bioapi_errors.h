/**
 * \file 
 * This file contains the Error Codes and Error Values specified by \ref iso19784-1, section 11, <i>BioAPI error handling</i>.
 * 
 * \section bioapi_errors Error Codes and Error Values
 * 
 * All BioAPI functions return a value of type \ref BioAPI_RETURN. The value \ref BioAPI_OK indicates 
 * that the function was successful. Any other value is an error value. Allowance has been made for 
 * returning error values originated from the BioAPI Framework and also error values that originate 
 * from a \ref bioapi_definition_bsp or from a \ref bioapi_definition_unit attached to a \ref bioapi_definition_bsp "BSP".
 * 
 * \subsection bioapi_error_code_schema Error Values and Error Codes Scheme
 * Error Value refers to the entire 32-bit \ref BioAPI_RETURN value.
 * 
 * Error Code refers to the low-order 24 bits of the Error Value, and identifies the actual error situation.
 * 
 * The 8 high-order bits of the Error Value identify the source of the error
 */
#ifndef BIOAPI_ERRORS_H
#define BIOAPI_ERRORS_H





/** 
 * \name BioAPI Error Value Constants
 * The 8 high-order bits of the Error Value identify the source of the error.
 * \{
 */
///Error source is the BioAPI Framework.
#define BIOAPI_FRAMEWORK_ERROR                0x00000000
///Error source is the \ref bioapi_definition_bsp.
#define BIOAPI_BSP_ERROR                      0x01000000
///Error source is the \ref bioapi_definition_unit.
#define BIOAPI_UNIT_ERROR                     0x02000000
/** \} */ //BioAPI Error Value Constants





/** 
 * \name General Error Codes
 * \{
 */
///General system error; indicates that an operating system or internal state error 
///has occurred and the system may not be in a known state.
#define BioAPIERR_INTERNAL_ERROR              0x00000101
///A memory error occurred.
#define BioAPIERR_MEMORY_ERROR                0x00000102
///An input/output function parameter or input/output field inside of a data structure is an invalid pointer.
#define BioAPIERR_INVALID_POINTER             0x00000103
///An input function parameter or input field in a data structure is an invalid pointer.
#define BioAPIERR_INVALID_INPUT_POINTER       0x00000104
///An output function parameter or output field in a data structure is an invalid pointer.
#define BioAPIERR_INVALID_OUTPUT_POINTER      0x00000105
///The function is not implemented by the biometric service provider.
#define BioAPIERR_FUNCTION_NOT_SUPPORTED      0x00000106
///The operating system denied access to a required resource.
#define BioAPIERR_OS_ACCESS_DENIED            0x00000107
///The function failed for an unknown reason.
#define BioAPIERR_FUNCTION_FAILED             0x00000108
///An input \ref bioapi_definition_uuid is invalid. (May occur if a component requested by this 
///\ref bioapi_definition_uuid is not present on the system or cannot be found
#define BioAPIERR_INVALID_UUID                0x00000109
///Version incompatibility. (May occur if the called component cannot support 
///the version of the BioAPI specification expected by the application.
#define BioAPIERR_INCOMPATIBLE_VERSION        0x0000010a
///The data in an input parameter is invalid.
#define BioAPIERR_INVALID_DATA                0x0000010b
///The associated \ref bioapi_definition_bsp is unable to capture raw samples from the requested \ref bioapi_definition_unit.
#define BioAPIERR_UNABLE_TO_CAPTURE           0x0000010c
///The associated \ref bioapi_definition_bsp has no more space to allocate \ref bioapi_definition_bir \ref bioapi_definition_handle.
#define BioAPIERR_TOO_MANY_HANDLES            0x0000010d
///The function has been terminated because the timeout value has expired.
#define BioAPIERR_TIMEOUT_EXPIRED             0x0000010e
///The input \ref bioapi_definition_bir is invalid for the purpose required.
#define BioAPIERR_INVALID_BIR                 0x0000010f
///The associated \ref bioapi_definition_bsp could not validate the signature on the \ref bioapi_definition_bir.
#define BioAPIERR_BIR_SIGNATURE_FAILURE       0x00000110
///The associated \ref bioapi_definition_bsp is unable to store the \ref bioapi_definition_payload.
#define BioAPIERR_UNABLE_TO_STORE_PAYLOAD     0x00000111
///The identify population is NULL.
#define BioAPIERR_NO_INPUT_BIRS               0x00000112
///The associated \ref bioapi_definition_bsp does not support the \ref bioapi_definition_bdb format requested.
#define BioAPIERR_UNSUPPORTED_FORMAT          0x00000113
///The associated \ref bioapi_definition_bsp was unable to construct a \ref bioapi_definition_bir from the input data.
#define BioAPIERR_UNABLE_TO_IMPORT            0x00000114
///The purpose recorded in the \ref bioapi_definition_bir and/or the requested purpose are 
///inconsistent with the function being performed.
#define BioAPIERR_INCONSISTENT_PURPOSE        0x00000115
///The function requires a fully processed \ref bioapi_definition_bir.
#define BioAPIERR_BIR_NOT_FULLY_PROCESSED     0x00000116
///The \ref bioapi_definition_bsp does not support the requested purpose.
#define BioAPIERR_PURPOSE_NOT_SUPPORTED       0x00000117
///User cancelled operation before completion or timeout.
#define BioAPIERR_USER_CANCELLED              0x00000118
///\ref bioapi_definition_bsp (or \ref bioapi_definition_unit attached to \ref bioapi_definition_bsp "BSP") is currently being used by another biometric application.
#define BioAPIERR_UNIT_IN_USE                 0x00000119
///The given \ref bioapi_definition_bsp \ref bioapi_definition_handle is not valid.
#define BioAPIERR_INVALID_BSP_HANDLE          0x0000011a
///A function has been called without initializing the BioAPI Framework.
#define BioAPIERR_FRAMEWORK_NOT_INITIALIZED   0x0000011b
///\ref bioapi_definition_bsp \ref bioapi_definition_handle is invalid (does not exist or has been released).
#define BioAPIERR_INVALID_BIR_HANDLE          0x0000011c
///The attempted calibration of a sensor unit was not able to be successfully completed.
#define BioAPIERR_CALIBRATION_NOT_SUCCESSFUL  0x0000011d
///No preset \ref bioapi_definition_bir population has been established.
#define BioAPIERR_PRESET_BIR_DOES_NOT_EXIST   0x0000011e
///The \ref bioapi_definition_bsp could not decrypt an input \ref bioapi_definition_bir (and thus was unable to use it for the requested operation).
#define BioAPIERR_BIR_DECRYPTION_FAILURE      0x0000011f
/** \} */ //General Error Codes





/**
 * \name Component Management Error Codes
 * \{
 */
///A reference to the file for the component being loaded cannot be found.
#define BioAPIERR_COMPONENT_FILE_REF_NOT_FOUND  0x00000201
///Framework was unable to successfully load the \ref bioapi_definition_bsp.
#define BioAPIERR_BSP_LOAD_FAIL                 0x00000202
///\ref bioapi_definition_bsp for which an action was requested is not loaded.
#define BioAPIERR_BSP_NOT_LOADED                0x00000203
///\ref bioapi_definition_unit for which an action was requested is not in the inserted state.
#define BioAPIERR_UNIT_NOT_INSERTED             0x00000204
///An invalid \ref bioapi_definition_unit ID was requested.
#define BioAPIERR_INVALID_UNIT_ID               0x00000205
///An invalid category of \ref bioapi_definition_bfp or \ref bioapi_definition_unit was requested.
#define BioAPIERR_INVALID_CATEGORY              0x00000206
/** \} */ //Component Management Error Codes






/**
 * \name Database Error Codes
 * \{
 */
///Invalid database \ref bioapi_definition_handle.
#define BioAPIERR_INVALID_DB_HANDLE             0x00000300
///The associated \ref bioapi_definition_bsp is unable to open the specified database.
#define BioAPIERR_UNABLE_TO_OPEN_DATABASE       0x00000301
///The database cannot be opened for the access requested because it is locked.
#define BioAPIERR_DATABASE_IS_LOCKED            0x00000302
///The specified database does not exist.
#define BioAPIERR_DATABASE_DOES_NOT_EXIST       0x00000303
///Create failed because the database already exists.
#define BioAPIERR_DATABASE_ALREADY_EXISTS       0x00000304
///Invalid database name (\ref bioapi_definition_uuid).
#define BioAPIERR_INVALID_DATABASE_NAME         0x00000305
///No record exists with the requested key.
#define BioAPIERR_RECORD_NOT_FOUND              0x00000306
///The specified marker \ref bioapi_definition_handle is invalid.
#define BioAPIERR_MARKER_HANDLE_IS_INVALID      0x00000307
///The database is already open.
#define BioAPIERR_DATABASE_IS_OPEN              0x00000308
///Unrecognized access type.
#define BioAPIERR_INVALID_ACCESS_REQUEST        0x00000309
///End of database has been reached.
#define BioAPIERR_END_OF_DATABASE               0x0000030a
///The associated \ref bioapi_definition_bsp cannot create the database.
#define BioAPIERR_UNABLE_TO_CREATE_DATABASE     0x0000030b
///The associated \ref bioapi_definition_bsp cannot close the database.
#define BioAPIERR_UNABLE_TO_CLOSE_DATABASE      0x0000030c
///The associated \ref bioapi_definition_bsp cannot delete the database.
#define BioAPIERR_UNABLE_TO_DELETE_DATABASE     0x0000030d
///The specified database is corrupt.
#define BioAPIERR_DATABASE_IS_CORRUPT           0x0000030e
/** \} */ //Database Error Codes





/**
 * \name Location Error Codes
 * In various biometric technologies like fingerprint, face, iris, retina or others, \ref bioapi_definition_biometric_sensor (sensor units)
 * have three dimensions from the user’s viewpoint. The error codes in this clause describe the errors that can
 * be caused by improper placement of a user’s biometric feature on the \ref bioapi_definition_biometric_sensor when 
 * attempting to capture their \ref bioapi_definition_biometric_sample. Figure below shows an example of a fingerprint
 * sensor, which can be mounted vertically (Case A) or horizontally (Case B). When the placement of the biometric feature 
 * is improper, error codes are required to provide appropriate user feedback. If the sensor is placed vertically, the words
 * ‘forward’ and ‘backward’ will be the expressions of intensity of the contact or distance, and if placed
 * horizontally, these words will be the expressions of lengthwise distances.
 * 
 * If the BSP or BioAPI Unit generating the error code knows whether the biometric device is oriented vertically
 * or horizontally, it can then choose an error code that describes the user’s situation appropriately. If it does not,
 * then a more general error code has to be used.
 * 
 * \image html bioapi_sensor_location.png "Biometric Sample Locations (Example of a fingerprint sensor)"
 * 
 * \note These errors can be returned from \ref BioAPI_CreateTemplate, \ref BioAPI_Process, \ref BioAPI_ProcessWithAuxBIR, 
 * \ref BioAPI_VerifyMatch, and \ref BioAPI_IdentifyMatch. The \ref bioapi_definition_bsp controlled \ref bioapi_symbol_gui in
 * the other biometric operations (\ref BioAPI_Capture, \ref BioAPI_Enroll, \ref BioAPI_Verify, and \ref BioAPI_Identify) will
 * instruct the user to capture a correct sample.
 * \{
 */
///A general location error.
#define BioAPIERR_LOCATION_ERROR                0x00000400
///Invalid horizontal or vertical position.
#define BioAPIERR_OUT_OF_FRAME                  0x00000401
///Invalid crosswise position.
#define BioAPIERR_INVALID_CROSSWISE_POSITION    0x00000402
///Invalid lengthwise position.
#define BioAPIERR_INVALID_LENGTHWISE_POSITION   0x00000403
///Invalid distance.
#define BioAPIERR_INVALID_DISTANCE              0x00000404

///The position was too far to the right.
#define BioAPIERR_LOCATION_TOO_RIGHT            0x00000405
///The position was too far to the left.
#define BioAPIERR_LOCATION_TOO_LEFT             0x00000406
///The position was too high.
#define BioAPIERR_LOCATION_TOO_HIGH             0x00000407
///The position was too low.
#define BioAPIERR_LOCATION_TOO_LOW              0x00000408
///The position was too far away.
#define BioAPIERR_LOCATION_TOO_FAR              0x00000409
///The position was too near (close).
#define BioAPIERR_LOCATION_TOO_NEAR             0x0000040a
///The position was too far forward.
#define BioAPIERR_LOCATION_TOO_FORWARD          0x0000040b
///The position was too far backward.
#define BioAPIERR_LOCATION_TOO_BACKWARD         0x0000040c
/** \} */ //Location Error Codes





/**
 * \name Quality Error Codes
 * \{
 */
///Sample quality is too poor for the operation to succeed.
///\note Quality errors can be returned from any function which receives a BioAPI BIR input.
#define BioAPIERR_QUALITY_ERROR                 0x00000501
/** \} */ //Quality Error Codes





#endif //BIOAPI_ERRORS_H
