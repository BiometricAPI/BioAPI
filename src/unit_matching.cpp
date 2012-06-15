#include "attach_session.h"

UnitMatching::UnitMatching (
    int unitID) 
: Unit(unitID)
{ }


UnitMatching::~UnitMatching ()
{
    Cancel();
}


BioAPI_RETURN UnitMatching::VerifyMatch (
    AttachSession* attach_session,
    BioAPI_FMR MaxFMRRequested,
    const BioAPI_INPUT_BIR *ProcessedBIR,
    const BioAPI_INPUT_BIR *ReferenceTemplate,
    BioAPI_BIR_HANDLE *AdaptedBIR,
    BioAPI_BOOL *Result,
    BioAPI_FMR *FMRAchieved,
    BioAPI_DATA *Payload)
{
    return BIOAPI_UNIT_ERROR | BioAPIERR_FUNCTION_NOT_SUPPORTED;
}


BioAPI_RETURN UnitMatching::IdentifyMatch (
    AttachSession* attach_session,
    BioAPI_FMR MaxFMRRequested,
    const BioAPI_INPUT_BIR *ProcessedBIR,
    const BioAPI_IDENTIFY_POPULATION *Population,
    uint32_t TotalNumberOfTemplates,
    BioAPI_BOOL Binning,
    uint32_t MaxNumberOfResults,
    uint32_t *NumberOfResults,
    BioAPI_CANDIDATE **Candidates,
    int32_t Timeout)
{
    return BIOAPI_UNIT_ERROR | BioAPIERR_FUNCTION_NOT_SUPPORTED;
}


BioAPI_RETURN UnitMatching::PresetIdentifyPopulation (
    AttachSession* attach_session,
    const BioAPI_IDENTIFY_POPULATION *Population)
{
    return BIOAPI_UNIT_ERROR | BioAPIERR_FUNCTION_NOT_SUPPORTED;
}
