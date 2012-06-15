#include "attach_session.h"

UnitArchive::UnitArchive (
    int unitID) 
: Unit(unitID)
{ }


UnitArchive::~UnitArchive () 
{
    Cancel();
}


BioAPI_RETURN UnitArchive::DbOpen (
    AttachSession* attach_session,
    const BioAPI_UUID *DbUuid,
    BioAPI_DB_ACCESS_TYPE AccessRequest,
    BioAPI_DB_HANDLE *DbHandle,
    BioAPI_DB_MARKER_HANDLE *MarkerHandle)
{
    return BIOAPI_UNIT_ERROR | BioAPIERR_FUNCTION_NOT_SUPPORTED;
}


BioAPI_RETURN UnitArchive::DbClose (
    AttachSession* attach_session,
    BioAPI_DB_HANDLE DbHandle)
{
    return BIOAPI_UNIT_ERROR | BioAPIERR_FUNCTION_NOT_SUPPORTED;
}


BioAPI_RETURN UnitArchive::DbCreate (
    AttachSession* attach_session,
    const BioAPI_UUID *DbUuid,
    uint32_t NumberOfRecords,
    BioAPI_DB_ACCESS_TYPE AccessRequest,
    BioAPI_DB_HANDLE *DbHandle)
{
    return BIOAPI_UNIT_ERROR | BioAPIERR_FUNCTION_NOT_SUPPORTED;
}


BioAPI_RETURN UnitArchive::DbDelete (
    AttachSession* attach_session,
    const BioAPI_UUID *DbUuid)
{
    return BIOAPI_UNIT_ERROR | BioAPIERR_FUNCTION_NOT_SUPPORTED;
}


BioAPI_RETURN UnitArchive::DbSetMarker (
    AttachSession* attach_session,
    BioAPI_DB_HANDLE DbHandle,
    const BioAPI_UUID *KeyValue,
    BioAPI_DB_MARKER_HANDLE MarkerHandle)
{
    return BIOAPI_UNIT_ERROR | BioAPIERR_FUNCTION_NOT_SUPPORTED;
}


BioAPI_RETURN UnitArchive::DbFreeMarker (
    AttachSession* attach_session,
    BioAPI_DB_MARKER_HANDLE MarkerHandle)
{
    return BIOAPI_UNIT_ERROR | BioAPIERR_FUNCTION_NOT_SUPPORTED;
}


BioAPI_RETURN UnitArchive::DbStoreBIR (
    AttachSession* attach_session,
    const BioAPI_INPUT_BIR *BIRToStore,
    BioAPI_DB_HANDLE DbHandle,
    BioAPI_UUID *BirUuid)
{
    return BIOAPI_UNIT_ERROR | BioAPIERR_FUNCTION_NOT_SUPPORTED;
}


BioAPI_RETURN UnitArchive::DbGetBIR (
    AttachSession* attach_session,
    BioAPI_DB_HANDLE DbHandle,
    const BioAPI_UUID *KeyValue,
    BioAPI_BIR_HANDLE *RetrievedBIR,
    BioAPI_DB_MARKER_HANDLE *MarkerHandle)
{
    return BIOAPI_UNIT_ERROR | BioAPIERR_FUNCTION_NOT_SUPPORTED;
}


BioAPI_RETURN UnitArchive::DbGetNextBIR (
    AttachSession* attach_session,
    BioAPI_DB_HANDLE DbHandle,
    BioAPI_DB_MARKER_HANDLE MarkerHandle,
    BioAPI_BIR_HANDLE *RetrievedBIR,
    BioAPI_UUID *BirUuid)
{
    return BIOAPI_UNIT_ERROR | BioAPIERR_FUNCTION_NOT_SUPPORTED;
}


BioAPI_RETURN UnitArchive::DbDeleteBIR (
    AttachSession* attach_session,
    BioAPI_DB_HANDLE DbHandle,
    const BioAPI_UUID *KeyValue)
{
    return BIOAPI_UNIT_ERROR | BioAPIERR_FUNCTION_NOT_SUPPORTED;
}
