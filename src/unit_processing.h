#pragma once

#include "common.h"

class UnitProcessing : public Unit {
public:
    UnitProcessing (
        int unitID);
    
    
    ~UnitProcessing ();
    
    
    virtual BioAPI_RETURN CreateTemplate (
        AttachSession* attach_session,
        const BioAPI_INPUT_BIR *CapturedBIR,
        const BioAPI_INPUT_BIR *ReferenceTemplate,
        const BioAPI_BIR_BIOMETRIC_DATA_FORMAT *OutputFormat,
        BioAPI_BIR_HANDLE *NewTemplate,
        const BioAPI_DATA *Payload,
        BioAPI_UUID *TemplateUUID);

    
    virtual BioAPI_RETURN Process (
        AttachSession* attach_session,
        const BioAPI_INPUT_BIR *CapturedBIR,
        const BioAPI_BIR_BIOMETRIC_DATA_FORMAT *OutputFormat,
        BioAPI_BIR_HANDLE *ProcessedBIR);

    
    virtual BioAPI_RETURN ProcessWithAuxBIR (
        AttachSession* attach_session,
        const BioAPI_INPUT_BIR *CapturedBIR,
        const BioAPI_INPUT_BIR *AuxiliaryData,
        const BioAPI_BIR_BIOMETRIC_DATA_FORMAT *OutputFormat,
        BioAPI_BIR_HANDLE *ProcessedBIR);
};
