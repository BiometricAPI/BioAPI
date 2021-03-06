/**
 * \file 
 * This file contains the functions specified by \ref iso19784-1, section 8, <i>BioAPI Functions</i>.
 * 
 * \section NO_VALUE_AVAILABLE  Foo
 */
#ifndef VR_BIOAPI_FUNCTIONS_H
#define VR_BIOAPI_FUNCTIONS_H

BioAPI_RETURN BioAPI BioAPI_Init(BioAPI_VERSION Version);

BioAPI_RETURN BioAPI BioAPI_Terminate(void);

BioAPI_RETURN BioAPI BioAPI_GetFrameworkInfo(
  BioAPI_FRAMEWORK_SCHEMA *FrameworkSchema);

BioAPI_RETURN BioAPI BioAPI_EnumBSPs
   (BioAPI_BSP_SCHEMA **BSPSchemaArray,
   uint32_t *NumberOfElements);

BioAPI_RETURN BioAPI BioAPI_BSPLoad
   (const BioAPI_UUID *BSPUuid,
   BioAPI_EventHandler AppNotifyCallback,
   void* AppNotifyCallbackCtx);

BioAPI_RETURN BioAPI BioAPI_BSPUnload
   (const BioAPI_UUID *BSPUuid,
   BioAPI_EventHandler AppNotifyCallback,
   void* AppNotifyCallbackCtx);

BioAPI_RETURN BioAPI BioAPI_BSPAttach
   (const BioAPI_UUID *BSPUuid,
   BioAPI_VERSION Version,
   const BioAPI_UNIT_LIST_ELEMENT *UnitList,
   uint32_t NumUnits,
   BioAPI_HANDLE *NewBSPHandle);

BioAPI_RETURN BioAPI BioAPI_BSPDetach
   (BioAPI_HANDLE BSPHandle);

BioAPI_RETURN BioAPI BioAPI_QueryUnits
   (const BioAPI_UUID *BSPUuid,
   BioAPI_UNIT_SCHEMA **UnitSchemaArray,
   uint32_t *NumberOfElements);

BioAPI_RETURN BioAPI BioAPI_EnumBFPs
   (BioAPI_BFP_SCHEMA **BFPSchemaArray,
   uint32_t *NumberOfElements);

BioAPI_RETURN BioAPI BioAPI_QueryBFPs
   (const BioAPI_UUID *BSPUuid,
   BioAPI_BFP_LIST_ELEMENT **BFPList,
   uint32_t *NumberOfElements);

BioAPI_RETURN BioAPI BioAPI_ControlUnit
   (BioAPI_HANDLE BSPHandle,
    BioAPI_UNIT_ID UnitID,
    uint32_t ControlCode,
    const BioAPI_DATA *InputData,
    BioAPI_DATA *OutputData);

BioAPI_RETURN BioAPI BioAPI_FreeBIRHandle
   (BioAPI_HANDLE BSPHandle,
   BioAPI_BIR_HANDLE Handle);

BioAPI_RETURN BioAPI BioAPI_GetBIRFromHandle
   (BioAPI_HANDLE BSPHandle,
   BioAPI_BIR_HANDLE Handle,
   BioAPI_BIR *BIR);

BioAPI_RETURN BioAPI BioAPI_GetHeaderFromHandle
   (BioAPI_HANDLE BSPHandle,
   BioAPI_BIR_HANDLE Handle,
   BioAPI_BIR_HEADER *Header);

BioAPI_RETURN BioAPI BioAPI_EnableEvents
   (BioAPI_HANDLE BSPHandle,
   BioAPI_EVENT_MASK Events);

BioAPI_RETURN BioAPI BioAPI_SetGUICallbacks
   (BioAPI_HANDLE BSPHandle,
   BioAPI_GUI_STREAMING_CALLBACK GuiStreamingCallback,
   void *GuiStreamingCallbackCtx,
   BioAPI_GUI_STATE_CALLBACK GuiStateCallback,
   void *GuiStateCallbackCtx);

BioAPI_RETURN BioAPI BioAPI_Capture
   (BioAPI_HANDLE BSPHandle,
   BioAPI_BIR_PURPOSE Purpose,
   BioAPI_BIR_SUBTYPE Subtype,
   const BioAPI_BIR_BIOMETRIC_DATA_FORMAT *OutputFormat,
   BioAPI_BIR_HANDLE *CapturedBIR,
   int32_t Timeout,
   BioAPI_BIR_HANDLE *AuditData);

BioAPI_RETURN BioAPI BioAPI_CreateTemplate
   (BioAPI_HANDLE BSPHandle,
   const BioAPI_INPUT_BIR *CapturedBIR,
   const BioAPI_INPUT_BIR *ReferenceTemplate,
   const BioAPI_BIR_BIOMETRIC_DATA_FORMAT *OutputFormat,
   BioAPI_BIR_HANDLE *NewTemplate,
   const BioAPI_DATA *Payload,
   BioAPI_UUID *TemplateUUID);

BioAPI_RETURN BioAPI BioAPI_Process
   (BioAPI_HANDLE BSPHandle,
   const BioAPI_INPUT_BIR *CapturedBIR,
   const BioAPI_BIR_BIOMETRIC_DATA_FORMAT*Format,
   BioAPI_BIR_HANDLE *ProcessedBIR);

BioAPI_RETURN BioAPI BioAPI_ProcessWithAuxBIR
   (BioAPI_HANDLE BSPHandle,
   const BioAPI_INPUT_BIR *CapturedBIR,
   const BioAPI_INPUT_BIR *AuxiliaryData,
   const BioAPI_BIR_BIOMETRIC_DATA_FORMAT *OutputFormat,
   BioAPI_BIR_HANDLE *ProcessedBIR);

BioAPI_RETURN BioAPI BioAPI_VerifyMatch
   (BioAPI_HANDLE BSPHandle,
   BioAPI_FMR MaxFMRRequested,
   const BioAPI_INPUT_BIR *ProcessedBIR,
   const BioAPI_INPUT_BIR *ReferenceTemplate,
   BioAPI_BIR_HANDLE *AdaptedBIR,
   BioAPI_BOOL *Result,
   BioAPI_FMR *FMRAchieved,
   BioAPI_DATA *Payload);

BioAPI_RETURN BioAPI BioAPI_IdentifyMatch
   (BioAPI_HANDLE BSPHandle,
   BioAPI_FMR MaxFMRRequested,
   const BioAPI_INPUT_BIR *ProcessedBIR,
   const BioAPI_IDENTIFY_POPULATION *Population,
   uint32_t TotalNumberOfTemplates,
   BioAPI_BOOL Binning,
   uint32_t MaxNumberOfResults,
   uint32_t *NumberOfResults,
   BioAPI_CANDIDATE **Candidates,
   int32_t Timeout);

BioAPI_RETURN BioAPI BioAPI_Enroll
   (BioAPI_HANDLE BSPHandle,
   BioAPI_BIR_PURPOSE Purpose,
   BioAPI_BIR_SUBTYPE Subtype,
   const BioAPI_BIR_BIOMETRIC_DATA_FORMAT *OutputFormat,
   const BioAPI_INPUT_BIR *ReferenceTemplate,
   BioAPI_BIR_HANDLE *NewTemplate,
   const BioAPI_DATA *Payload,
   int32_t Timeout,
   BioAPI_BIR_HANDLE *AuditData,
   BioAPI_UUID *TemplateUUID);

BioAPI_RETURN BioAPI BioAPI_Verify (
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

BioAPI_RETURN BioAPI BioAPI_Identify (
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

BioAPI_RETURN BioAPI BioAPI_Import (
    BioAPI_HANDLE BSPHandle,
    const BioAPI_DATA *InputData,
    const BioAPI_BIR_BIOMETRIC_DATA_FORMAT,
    const BioAPI_BIR_BIOMETRIC_DATA_FORMAT,
    BioAPI_BIR_PURPOSE Purpose,
    BioAPI_BIR_HANDLE *ConstructedBIR);

BioAPI_RETURN BioAPI BioAPI_PresetIdentifyPopulation (
    BioAPI_HANDLE BSPHandle,
    const BioAPI_IDENTIFY_POPULATION *Population);

BioAPI_RETURN BioAPI BioAPI_DbOpen (
    BioAPI_HANDLE BSPHandle,
    const BioAPI_UUID *DbUuid,
    BioAPI_DB_ACCESS_TYPE AccessRequest,
    BioAPI_DB_HANDLE *DbHandle,
    BioAPI_DB_MARKER_HANDLE *MarkerHandle);

BioAPI_RETURN BioAPI BioAPI_DbClose (
    BioAPI_HANDLE BSPHandle,
    BioAPI_DB_HANDLE DbHandle);

BioAPI_RETURN BioAPI BioAPI_DbCreate(
    BioAPI_HANDLE BSPHandle,
    const BioAPI_UUID *DbUuid,
    uint32_t NumberOfRecords,
    BioAPI_DB_ACCESS_TYPE AccessRequest,
    BioAPI_DB_HANDLE *DbHandle);

BioAPI_RETURN BioAPI BioAPI_DbDelete (
    BioAPI_HANDLE BSPHandle,
    const BioAPI_UUID *DbUuid);

BioAPI_RETURN BioAPI BioAPI_DbSetMarker (
    BioAPI_HANDLE BSPHandle,
    BioAPI_DB_HANDLE DbHandle,
    const BioAPI_UUID *KeyValue,
    BioAPI_DB_MARKER_HANDLE MarkerHandle);

BioAPI_RETURN BioAPI BioAPI_DbFreeMarker (
    BioAPI_HANDLE BSPHandle,
    BioAPI_DB_MARKER_HANDLE MarkerHandle);

BioAPI_RETURN BioAPI BioAPI_DbStoreBIR (
    BioAPI_HANDLE BSPHandle,
    const BioAPI_INPUT_BIR *BIRToStore,
    BioAPI_DB_HANDLE DbHandle,
    BioAPI_UUID *BirUuid);

BioAPI_RETURN BioAPI BioAPI_DbGetBIR (
    BioAPI_HANDLE BSPHandle,
    BioAPI_DB_HANDLE DbHandle,
    const BioAPI_UUID *KeyValue,
    BioAPI_BIR_HANDLE *RetrievedBIR,
    BioAPI_DB_MARKER_HANDLE *MarkerHandle);

BioAPI_RETURN BioAPI BioAPI_DbGetNextBIR (
    BioAPI_HANDLE BSPHandle,
    BioAPI_DB_HANDLE DbHandle,
    BioAPI_DB_MARKER_HANDLE MarkerHandle,
    BioAPI_BIR_HANDLE *RetrievedBIR,
    BioAPI_UUID *BirUuid);

BioAPI_RETURN BioAPI BioAPI_DbDeleteBIR (
    BioAPI_HANDLE BSPHandle,
    BioAPI_DB_HANDLE DbHandle,
    const BioAPI_UUID *KeyValue);

BioAPI_RETURN BioAPI BioAPI_SetPowerMode (
    BioAPI_HANDLE BSPHandle,
    BioAPI_UNIT_ID UnitId,
    BioAPI_POWER_MODE PowerMode);

BioAPI_RETURN BioAPI BioAPI_SetIndicatorStatus (
    BioAPI_HANDLE BSPHandle,
    BioAPI_UNIT_ID UnitId,
    BioAPI_INDICATOR_STATUS IndicatorStatus);

BioAPI_RETURN BioAPI BioAPI_GetIndicatorStatus (
    BioAPI_HANDLE BSPHandle,
    BioAPI_UNIT_ID UnitId,
    BioAPI_INDICATOR_STATUS *IndicatorStatus);

BioAPI_RETURN BioAPI BioAPI_CalibrateSensor (
    BioAPI_HANDLE BSPHandle,
    int32_t Timeout);

BioAPI_RETURN BioAPI BioAPI_Cancel (
    BioAPI_HANDLE BSPHandle);

BioAPI_RETURN BioAPI BioAPI_Free (
    void* Ptr);

   
   
   
   
BioAPI_RETURN BioAPI BioAPI_Util_InstallBSP (
    BioAPI_INSTALL_ACTION Action,
    BioAPI_INSTALL_ERROR *Error,
    const BioAPI_BSP_SCHEMA *BSPSchema);





BioAPI_RETURN BioAPI BioAPI_Util_InstallBFP (
    BioAPI_INSTALL_ACTION Action,
    BioAPI_INSTALL_ERROR *Error,
    const BioAPI_BFP_SCHEMA *BFPSchema);

#endif //VR_BIOAPI_FUNCTIONS_H
