#include "attach_session.h"

UnitProcessing::UnitProcessing (
    int unitID) 
: Unit(unitID)
{ }


UnitProcessing::~UnitProcessing ()
{
    Cancel();
}


BioAPI_RETURN UnitProcessing::CreateTemplate (
    AttachSession* attach_session,
    const BioAPI_INPUT_BIR *CapturedBIR,
    const BioAPI_INPUT_BIR *ReferenceTemplate,
    const BioAPI_BIR_BIOMETRIC_DATA_FORMAT *OutputFormat,
    BioAPI_BIR_HANDLE *NewTemplate,
    const BioAPI_DATA *Payload,
    BioAPI_UUID *TemplateUUID)
{
    return BIOAPI_UNIT_ERROR | BioAPIERR_FUNCTION_NOT_SUPPORTED;
}


BioAPI_RETURN UnitProcessing::Process (
    AttachSession* attach_session,
    const BioAPI_INPUT_BIR *CapturedBIR,
    const BioAPI_BIR_BIOMETRIC_DATA_FORMAT *OutputFormat,
    BioAPI_BIR_HANDLE *ProcessedBIR)
{
    return BIOAPI_UNIT_ERROR | BioAPIERR_FUNCTION_NOT_SUPPORTED;
}


BioAPI_RETURN UnitProcessing::ProcessWithAuxBIR (
    AttachSession* attach_session,
    const BioAPI_INPUT_BIR *CapturedBIR,
    const BioAPI_INPUT_BIR *AuxiliaryData,
    const BioAPI_BIR_BIOMETRIC_DATA_FORMAT *OutputFormat,
    BioAPI_BIR_HANDLE *ProcessedBIR)
{
    return BIOAPI_UNIT_ERROR | BioAPIERR_FUNCTION_NOT_SUPPORTED;
}
