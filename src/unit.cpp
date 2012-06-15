#include "unit.h"

Unit::Unit (
    BioAPI_UNIT_ID unitID)
{
    this->unitID = unitID;
}


Unit::~Unit () 
{
    Cancel();
}


BioAPI_UNIT_ID Unit::getUnitID() 
{
    return unitID;
}


BioAPI_RETURN Unit::ControlUnit (
    AttachSession* attach_session,
    uint32_t ControlCode, 
    const BioAPI_DATA *InputData, 
    BioAPI_DATA *OutputData) 
{
    return BIOAPI_UNIT_ERROR | BioAPIERR_FUNCTION_NOT_SUPPORTED;
}


BioAPI_RETURN Unit::SetPowerMode (
    AttachSession* attach_session,
    BioAPI_POWER_MODE PowerMode) 
{
    return BIOAPI_UNIT_ERROR | BioAPIERR_FUNCTION_NOT_SUPPORTED;
}


BioAPI_RETURN Unit::SetIndicatorStatus (
    AttachSession* attach_session,
    BioAPI_INDICATOR_STATUS IndicatorStatus) 
{
    return BIOAPI_UNIT_ERROR | BioAPIERR_FUNCTION_NOT_SUPPORTED;
}


BioAPI_RETURN Unit::GetIndicatorStatus (
    AttachSession* attach_session,
    BioAPI_INDICATOR_STATUS *IndicatorStatus) 
{
    return BIOAPI_UNIT_ERROR | BioAPIERR_FUNCTION_NOT_SUPPORTED;
}
