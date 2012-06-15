#pragma once

#include "unit.h"

class UnitArchive : public Unit {
public:
    UnitArchive (
        int unitID);
    
    
    ~UnitArchive ();
  
    
    virtual BioAPI_RETURN DbOpen (
        AttachSession* attach_session,
        const BioAPI_UUID *DbUuid,
        BioAPI_DB_ACCESS_TYPE AccessRequest,
        BioAPI_DB_HANDLE *DbHandle,
        BioAPI_DB_MARKER_HANDLE *MarkerHandle);


    virtual BioAPI_RETURN DbClose (
        AttachSession* attach_session,
        BioAPI_DB_HANDLE DbHandle);

    
    virtual BioAPI_RETURN DbCreate (
        AttachSession* attach_session,
        const BioAPI_UUID *DbUuid,
        uint32_t NumberOfRecords,
        BioAPI_DB_ACCESS_TYPE AccessRequest,
        BioAPI_DB_HANDLE *DbHandle);


    virtual BioAPI_RETURN DbDelete (
        AttachSession* attach_session,
        const BioAPI_UUID *DbUuid);


    virtual BioAPI_RETURN DbSetMarker (
        AttachSession* attach_session,
        BioAPI_DB_HANDLE DbHandle,
        const BioAPI_UUID *KeyValue,
        BioAPI_DB_MARKER_HANDLE MarkerHandle);

    
    virtual BioAPI_RETURN DbFreeMarker (
        AttachSession* attach_session,
        BioAPI_DB_MARKER_HANDLE MarkerHandle);


    virtual BioAPI_RETURN DbStoreBIR (
        AttachSession* attach_session,
        const BioAPI_INPUT_BIR *BIRToStore,
        BioAPI_DB_HANDLE DbHandle,
        BioAPI_UUID *BirUuid);


    virtual BioAPI_RETURN DbGetBIR (
        AttachSession* attach_session,
        BioAPI_DB_HANDLE DbHandle,
        const BioAPI_UUID *KeyValue,
        BioAPI_BIR_HANDLE *RetrievedBIR,
        BioAPI_DB_MARKER_HANDLE *MarkerHandle);


    virtual BioAPI_RETURN DbGetNextBIR (
        AttachSession* attach_session,
        BioAPI_DB_HANDLE DbHandle,
        BioAPI_DB_MARKER_HANDLE MarkerHandle,
        BioAPI_BIR_HANDLE *RetrievedBIR,
        BioAPI_UUID *BirUuid);


    virtual BioAPI_RETURN DbDeleteBIR (
        AttachSession* attach_session,
        BioAPI_DB_HANDLE DbHandle,
        const BioAPI_UUID *KeyValue);
};
