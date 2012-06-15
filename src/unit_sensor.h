#pragma once

#include "unit.h"

class UnitSensor : public Unit {
public:
    UnitSensor (
        int unitID);
    
    
    ~UnitSensor ();
    
    
    virtual BioAPI_RETURN Capture (
        AttachSession* attach_session,
        BioAPI_BIR_PURPOSE Purpose,
        BioAPI_BIR_SUBTYPE Subtype,
        const BioAPI_BIR_BIOMETRIC_DATA_FORMAT *OutputFormat,
        BioAPI_BIR_HANDLE *CapturedBIR,
        int32_t Timeout,
        BioAPI_BIR_HANDLE *AuditData);
    
    virtual BioAPI_RETURN CalibrateSensor (
        AttachSession* attach_session,
        int32_t Timeout);
};
