#pragma once

#include "common.h"

class UnitMatching : public Unit {
public:
    UnitMatching (
        int unitID);
    
    
    ~UnitMatching ();
    
    
    virtual BioAPI_RETURN VerifyMatch (
        AttachSession* attach_session,
        BioAPI_FMR MaxFMRRequested,
        const BioAPI_INPUT_BIR *ProcessedBIR,
        const BioAPI_INPUT_BIR *ReferenceTemplate,
        BioAPI_BIR_HANDLE *AdaptedBIR,
        BioAPI_BOOL *Result,
        BioAPI_FMR *FMRAchieved,
        BioAPI_DATA *Payload);

    
    virtual BioAPI_RETURN IdentifyMatch (
        AttachSession* attach_session,
        BioAPI_FMR MaxFMRRequested,
        const BioAPI_INPUT_BIR *ProcessedBIR,
        const BioAPI_IDENTIFY_POPULATION *Population,
        uint32_t TotalNumberOfTemplates,
        BioAPI_BOOL Binning,
        uint32_t MaxNumberOfResults,
        uint32_t *NumberOfResults,
        BioAPI_CANDIDATE **Candidates,
        int32_t Timeout);
    
    
    virtual BioAPI_RETURN PresetIdentifyPopulation (
        AttachSession* attach_session,
        const BioAPI_IDENTIFY_POPULATION *Population);
};
