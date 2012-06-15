#include "attach_session.h"

UnitSensor::UnitSensor (
    int unitID)
: Unit(unitID)
{ }


UnitSensor::~UnitSensor ()
{
    Cancel();
}


BioAPI_RETURN UnitSensor::Capture (
    AttachSession* attach_session,
    BioAPI_BIR_PURPOSE Purpose,
    BioAPI_BIR_SUBTYPE Subtype,
    const BioAPI_BIR_BIOMETRIC_DATA_FORMAT *OutputFormat,
    BioAPI_BIR_HANDLE *CapturedBIR,
    int32_t Timeout,
    BioAPI_BIR_HANDLE *AuditData)
{
    return BIOAPI_UNIT_ERROR | BioAPIERR_FUNCTION_NOT_SUPPORTED;
}


BioAPI_RETURN UnitSensor::CalibrateSensor (
    AttachSession* attach_session,
    int32_t Timeout) 
{
    return BIOAPI_UNIT_ERROR | BioAPIERR_FUNCTION_NOT_SUPPORTED;
}
