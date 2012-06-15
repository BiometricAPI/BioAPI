#ifndef BIOSPI_H
#define BIOSPI_H

#include <bioapi.h>

typedef BioAPI_RETURN (BioAPI *BioSPI_EventHandler) (
    const BioAPI_UUID *BSPUuid,
    BioAPI_UNIT_ID UnitID,
    const BioAPI_UNIT_SCHEMA *UnitSchema,
    BioAPI_EVENT EventType);

typedef BioAPI_RETURN (*BioSPI_BFP_ENUMERATION_HANDLER) (
    BioAPI_BFP_SCHEMA **BFPSchemaArray,
    uint32_t *NumberOfElements);

typedef BioAPI_RETURN (*BioSPI_MEMORY_FREE_HANDLER) (
    void* Ptr);







BioAPI_RETURN BioAPI BioSPI_BSPLoad(
    const BioAPI_UUID *BSPUuid,
    BioSPI_EventHandler BioAPINotifyCallback,
    BioSPI_BFP_ENUMERATION_HANDLER BFPEnumerationHandler,
    BioSPI_MEMORY_FREE_HANDLER MemoryFreeHandler);

BioAPI_RETURN BioAPI BioSPI_BSPUnload (
    const BioAPI_UUID *BSPUuid);

BioAPI_RETURN BioAPI BioSPI_BSPAttach (
    const BioAPI_UUID *BSPUuid,
    BioAPI_VERSION Version,
    const BioAPI_UNIT_LIST_ELEMENT *UnitList,
    uint32_t NumUnits,
    BioAPI_HANDLE BSPHandle);

BioAPI_RETURN BioAPI BioSPI_BSPDetach (
    BioAPI_HANDLE BSPHandle);

BioAPI_RETURN BioAPI BioSPI_QueryUnits (
    const BioAPI_UUID *Uuid,
    BioAPI_UNIT_SCHEMA **UnitSchemaArray,
    uint32_t *NumberOfElements);

BioAPI_RETURN BioAPI BioSPI_QueryBFPs (
    const BioAPI_UUID *BSPUuid,
    BioAPI_BFP_LIST_ELEMENT **BFPList,
    uint32_t *NumberOfElements);
   
   
   
   
   
   
   
   
   

BioAPI_RETURN BioAPI BioSPI_ControlUnit (
    BioAPI_HANDLE BSPHandle,
    BioAPI_UNIT_ID UnitID,
    uint32_t ControlCode,
    const BioAPI_DATA *InputData,
    BioAPI_DATA *OutputData);

BioAPI_RETURN BioAPI BioSPI_FreeBIRHandle (
    BioAPI_HANDLE BSPHandle,
    BioAPI_BIR_HANDLE Handle);

BioAPI_RETURN BioAPI BioSPI_GetBIRFromHandle (
    BioAPI_HANDLE BSPHandle,
    BioAPI_BIR_HANDLE Handle,
    BioAPI_BIR *BIR);

BioAPI_RETURN BioAPI BioSPI_GetHeaderFromHandle (
    BioAPI_HANDLE BSPHandle,
    BioAPI_BIR_HANDLE Handle,
    BioAPI_BIR_HEADER *Header);

BioAPI_RETURN BioAPI BioSPI_EnableEvents (
    BioAPI_HANDLE BSPHandle,
    BioAPI_EVENT_MASK Events);

BioAPI_RETURN BioAPI BioSPI_SetGUICallbacks (
    BioAPI_HANDLE BSPHandle,
    BioAPI_GUI_STREAMING_CALLBACK GuiStreamingCallback,
    void *GuiStreamingCallbackCtx,
    BioAPI_GUI_STATE_CALLBACK GuiStateCallback,
    void *GuiStateCallbackCtx);

BioAPI_RETURN BioAPI BioSPI_Capture(
    BioAPI_HANDLE BSPHandle,
    BioAPI_BIR_PURPOSE Purpose,
    BioAPI_BIR_SUBTYPE Subtype,
    const BioAPI_BIR_BIOMETRIC_DATA_FORMAT *OutputFormat,
    BioAPI_BIR_HANDLE *CapturedBIR,
    int32_t Timeout,
    BioAPI_BIR_HANDLE *AuditData);

BioAPI_RETURN BioAPI BioSPI_CreateTemplate (
    BioAPI_HANDLE BSPHandle,
    const BioAPI_INPUT_BIR *CapturedBIR,
    const BioAPI_INPUT_BIR *ReferenceTemplate,
    const BioAPI_BIR_BIOMETRIC_DATA_FORMAT *OutputFormat,
    BioAPI_BIR_HANDLE *NewTemplate,
    const BioAPI_DATA *Payload,
    BioAPI_UUID *TemplateUUID);

BioAPI_RETURN BioAPI BioSPI_Process (
    BioAPI_HANDLE BSPHandle,
    const BioAPI_INPUT_BIR *CapturedBIR,
    const BioAPI_BIR_BIOMETRIC_DATA_FORMAT *OutputFormat,
    BioAPI_BIR_HANDLE *ProcessedBIR);

BioAPI_RETURN BioAPI BioSPI_ProcessWithAuxBIR (
    BioAPI_HANDLE BSPHandle,
    const BioAPI_INPUT_BIR *CapturedBIR,
    const BioAPI_INPUT_BIR *AuxiliaryData,
    const BioAPI_BIR_BIOMETRIC_DATA_FORMAT *OutputFormat,
    BioAPI_BIR_HANDLE *ProcessedBIR);

BioAPI_RETURN BioAPI BioSPI_VerifyMatch (
    BioAPI_HANDLE BSPHandle,
    BioAPI_FMR MaxFMRRequested,
    const BioAPI_INPUT_BIR *ProcessedBIR,
    const BioAPI_INPUT_BIR *ReferenceTemplate,
    BioAPI_BIR_HANDLE *AdaptedBIR,
    BioAPI_BOOL *Result,
    BioAPI_FMR *FMRAchieved,
    BioAPI_DATA *Payload);

BioAPI_RETURN BioAPI BioSPI_IdentifyMatch (
    BioAPI_HANDLE BSPHandle,
    BioAPI_FMR MaxFMRRequested,
    const BioAPI_INPUT_BIR *ProcessedBIR,
    const BioAPI_IDENTIFY_POPULATION *Population,
    uint32_t TotalNumberOfTemplates,
    BioAPI_BOOL Binning,
    uint32_t MaxNumberOfResults,
    uint32_t *NumberOfResults,
    BioAPI_CANDIDATE **Candidates,
    int32_t Timeout);

BioAPI_RETURN BioAPI BioSPI_Enroll (
    BioAPI_HANDLE BSPHandle,
    BioAPI_BIR_PURPOSE Purpose,
    BioAPI_BIR_SUBTYPE Subtype,
    const BioAPI_BIR_BIOMETRIC_DATA_FORMAT *OutputFormat,
    const BioAPI_INPUT_BIR *ReferenceTemplate,
    BioAPI_BIR_HANDLE *NewTemplate,
    const BioAPI_DATA *Payload,
    int32_t Timeout,
    BioAPI_BIR_HANDLE *AuditData,
    BioAPI_UUID *TemplateUUID);

BioAPI_RETURN BioAPI BioSPI_Verify (
    BioAPI_HANDLE BSPHandle,
    BioAPI_FMR MaxFMRRequested,
    const BioAPI_INPUT_BIR *ReferenceTemplate,
    BioAPI_BIR_SUBTYPE Subtype,
    BioAPI_BIR_HANDLE *AdaptedBIR,
    BioAPI_BOOL *Result,
    BioAPI_FMR *FMRAchieved,
    BioAPI_DATA *Payload,
    int32_t Timeout,
    BioAPI_BIR_HANDLE *AuditData);

BioAPI_RETURN BioAPI BioSPI_Identify (
    BioAPI_HANDLE BSPHandle,
    BioAPI_FMR MaxFMRRequested,
    BioAPI_BIR_SUBTYPE Subtype,
    const BioAPI_IDENTIFY_POPULATION *Population,
    uint32_t TotalNumberOfTemplates,
    BioAPI_BOOL Binning,
    uint32_t MaxNumberOfResults,
    uint32_t *NumberOfResults,
    BioAPI_CANDIDATE **Candidates,
    int32_t Timeout,
    BioAPI_BIR_HANDLE *AuditData);

BioAPI_RETURN BioAPI BioSPI_Import (
    BioAPI_HANDLE BSPHandle,
    const BioAPI_DATA *InputData,
    const BioAPI_BIR_BIOMETRIC_DATA_FORMAT *InputFormat,
    const BioAPI_BIR_BIOMETRIC_DATA_FORMAT *OutputFormat,
    BioAPI_BIR_PURPOSE Purpose,
    BioAPI_BIR_HANDLE *ConstructedBIR);

BioAPI_RETURN BioAPI BioSPI_PresetIdentifyPopulation (
    BioAPI_HANDLE BSPHandle,
    const BioAPI_IDENTIFY_POPULATION *Population);

BioAPI_RETURN BioAPI BioSPI_DbOpen (
    BioAPI_HANDLE BSPHandle,
    const BioAPI_UUID *DbUuid,
    BioAPI_DB_ACCESS_TYPE AccessRequest,
    BioAPI_DB_HANDLE *DbHandle,
    BioAPI_DB_MARKER_HANDLE *MarkerHandle);

BioAPI_RETURN BioAPI BioSPI_DbClose(
    BioAPI_HANDLE BSPHandle,
    BioAPI_DB_HANDLE DbHandle);

BioAPI_RETURN BioAPI BioSPI_DbCreate (
    BioAPI_HANDLE BSPHandle,
    const BioAPI_UUID *DbUuid,
    uint32_t NumberOfRecords,
    BioAPI_DB_ACCESS_TYPE AccessRequest,
    BioAPI_DB_HANDLE *DbHandle);

BioAPI_RETURN BioAPI BioSPI_DbDelete (
    BioAPI_HANDLE BSPHandle,
    const BioAPI_UUID *DbUuid);

BioAPI_RETURN BioAPI BioSPI_DbSetMarker (
    BioAPI_HANDLE BSPHandle,
    BioAPI_DB_HANDLE DbHandle,
    const BioAPI_UUID *KeyValue,
    BioAPI_DB_MARKER_HANDLE MarkerHandle);

BioAPI_RETURN BioAPI BioSPI_DbFreeMarker (
    BioAPI_HANDLE BSPHandle,
    BioAPI_DB_MARKER_HANDLE MarkerHandle);

BioAPI_RETURN BioAPI BioSPI_DbStoreBIR(
    BioAPI_HANDLE BSPHandle,
    const BioAPI_INPUT_BIR *BIRToStore,
    BioAPI_DB_HANDLE DbHandle,
    BioAPI_UUID *BirUuid);

BioAPI_RETURN BioAPI BioSPI_DbGetBIR (
    BioAPI_HANDLE BSPHandle,
    BioAPI_DB_HANDLE DbHandle,
    const BioAPI_UUID *KeyValue,
    BioAPI_BIR_HANDLE *RetrievedBIR,
    BioAPI_DB_MARKER_HANDLE *MarkerHandle);

BioAPI_RETURN BioAPI BioSPI_DbGetNextBIR (
    BioAPI_HANDLE BSPHandle,
    BioAPI_DB_HANDLE DbHandle,
    BioAPI_DB_MARKER_HANDLE MarkerHandle,
    BioAPI_BIR_HANDLE *RetrievedBIR,
    BioAPI_UUID *BirUuid);

BioAPI_RETURN BioAPI BioSPI_DbDeleteBIR(
    BioAPI_HANDLE BSPHandle,
    BioAPI_DB_HANDLE DbHandle,
    const BioAPI_UUID *KeyValue);

BioAPI_RETURN BioAPI BioSPI_SetPowerMode (
    BioAPI_HANDLE BSPHandle,
    BioAPI_UNIT_ID UnitId,
    BioAPI_POWER_MODE PowerMode);

BioAPI_RETURN BioAPI BioSPI_SetIndicatorStatus (
    BioAPI_HANDLE BSPHandle,
    BioAPI_UNIT_ID UnitId,
    BioAPI_INDICATOR_STATUS IndicatorStatus);

BioAPI_RETURN BioAPI BioSPI_GetIndicatorStatus (
    BioAPI_HANDLE BSPHandle,
    BioAPI_UNIT_ID UnitId,
    BioAPI_INDICATOR_STATUS *IndicatorStatus);

BioAPI_RETURN BioAPI BioSPI_CalibrateSensor (
    BioAPI_HANDLE BSPHandle,
    int32_t Timeout);

BioAPI_RETURN BioAPI BioSPI_Cancel (
    BioAPI_HANDLE BSPHandle);

BioAPI_RETURN BioAPI BioSPI_Free (
    void* Ptr);



#endif // BIOSPI_H
