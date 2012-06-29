#pragma once

#include "common.h"

class BSP : public Cancellable {
public:
    std::map<BioAPI_UNIT_ID, BioAPI_UNIT_SCHEMA>  inserted_units;
    HandleManager<BioAPI_HANDLE, AttachSession>   session_handles;
    BioAPI_UUID                                   Uuid;
    BioSPI_EventHandler                           EventHandler;
    BioSPI_BFP_ENUMERATION_HANDLER                BFPEnumerationHandler;
    BioSPI_MEMORY_FREE_HANDLER                    MemoryFreeHandler;
    
public:
    BSP (
        BioAPI_UUID                    Uuid,
        BioSPI_EventHandler            BioAPINotifyCallback,
        BioSPI_BFP_ENUMERATION_HANDLER BFPEnumerationHandler,
        BioSPI_MEMORY_FREE_HANDLER     MemoryFreeHandler);
    ~BSP();
    
    //User tries to Unload() the BSP while there is an operation in progress
    virtual void CancelTasksAsync();
    virtual void CancelTasksJoin();

    BioAPI_RETURN QueryBFPs (
        BioAPI_BFP_LIST_ELEMENT **BFPList,
        uint32_t *NumberOfElements);
    
    BioAPI_RETURN QueryUnits (
        BioAPI_UNIT_SCHEMA **UnitSchemaArray,
        uint32_t *NumberOfElements);
    
    BioAPI_RETURN BSPAttach (
        const BioAPI_UNIT_LIST_ELEMENT *UnitList,
        uint32_t NumUnits,
        BioAPI_HANDLE BSPHandle,
        AttachSession** attachSession);
};