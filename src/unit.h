#pragma once

#include "cancellable.h"

class AttachSession;

class Unit : public Cancellable {
protected:
    BioAPI_UNIT_ID unitID;
    
public:
    Unit(
        BioAPI_UNIT_ID unitID);
    
    
    ~Unit();
  
    
    BioAPI_UNIT_ID getUnitID();
  
    
    virtual BioAPI_RETURN ControlUnit (
        AttachSession* attach_session,
        uint32_t ControlCode, 
        const BioAPI_DATA *InputData, 
        BioAPI_DATA *OutputData);  

    
    virtual BioAPI_RETURN SetPowerMode (
        AttachSession* attach_session,
        BioAPI_POWER_MODE PowerMode);

    
    virtual BioAPI_RETURN SetIndicatorStatus (
        AttachSession* attach_session,
        BioAPI_INDICATOR_STATUS IndicatorStatus);

    
    virtual BioAPI_RETURN GetIndicatorStatus (
        AttachSession* attach_session,
        BioAPI_INDICATOR_STATUS *IndicatorStatus);
};
