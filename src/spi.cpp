#include "common.h"
#include <cstring>

static UUID VERIDIS_BIOMETRIC_BSP_UUID = (BioAPI_UUID){1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};

static std::map<UUID, BSP*>  biospi_loaded_bsps;
static pthread_mutex_t       biospi_loaded_bsps_mutex = PTHREAD_MUTEX_INITIALIZER;
static pthread_mutex_t       biospi_load_unload_mutex = PTHREAD_MUTEX_INITIALIZER;

static std::map<BioAPI_HANDLE, AttachSession*>  biospi_attached_sessions;
//static std::map<BSP*, set<BioAPI_HANDLE> >      biospi_bsp_attached_sessions;
static pthread_mutex_t                          biospi_attached_sessions_mutex      = PTHREAD_MUTEX_INITIALIZER;
static pthread_mutex_t                          biospi_attach_detach_mutex = PTHREAD_MUTEX_INITIALIZER;


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


static BioAPI_RETURN useBSP(UUID BSPUuid, const char* task_name, BSP* &bsp) {
    pthread_mutex_lock(&biospi_loaded_bsps_mutex);
    bsp = biospi_loaded_bsps[BSPUuid];
    if (bsp == NULL) {
      biospi_loaded_bsps.erase(BSPUuid);
      pthread_mutex_unlock(&biospi_loaded_bsps_mutex);
      BioUtil_Log(task_name, "BSP Not loaded\n");
      return BIOAPI_BSP_ERROR | BioAPIERR_BSP_NOT_LOADED;
    }
    if (!bsp->UseStart(task_name) ) {
        pthread_mutex_unlock(&biospi_loaded_bsps_mutex);
        BioUtil_Log(task_name, "User Cancel\n");
        return BIOAPI_BSP_ERROR | BioAPIERR_USER_CANCELLED;
    }
    return BioAPI_OK;
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


#define BSP_DO_CANCELLABLE(BSPUuid, task_name, function) \
{ \
    BSP* bsp = NULL; \
    BioAPI_RETURN ret  = useBSP(BSPUuid, task_name, bsp); \
    if (ret) return ret; \
    ret = bsp->function; \
    bsp->UseEnd(task_name); \
    return ret;\
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


BioAPI_RETURN BioSPI_BSPLoad (
    const BioAPI_UUID *BSPUuid,
    BioSPI_EventHandler BioAPINotifyCallback,
    BioSPI_BFP_ENUMERATION_HANDLER BFPEnumerationHandler,
    BioSPI_MEMORY_FREE_HANDLER MemoryFreeHandler)
{
    //Check NULL arguments
    if (BSPUuid==NULL) {
        BioUtil_Log(__func__, "NULL BSP UUID\n");
        return BIOAPI_BSP_ERROR | BioAPIERR_INVALID_UUID;
    }
    if (BioAPINotifyCallback==NULL || BFPEnumerationHandler==NULL || MemoryFreeHandler==NULL) {
        BioUtil_Log(__func__, "NULL Parameter\n");
        return BIOAPI_BSP_ERROR | BioAPIERR_INVALID_INPUT_POINTER;
    }
  
    pthread_mutex_lock(&biospi_load_unload_mutex);
  
    //Check if BSP is already loaded
    pthread_mutex_lock(&biospi_loaded_bsps_mutex);
    bool already_loaded = biospi_loaded_bsps.find(BSPUuid) != biospi_loaded_bsps.end();
    pthread_mutex_unlock(&biospi_loaded_bsps_mutex);
    
    if (already_loaded) {
        pthread_mutex_unlock(&biospi_load_unload_mutex);
        BioUtil_Log(__func__, "BSP already Loaded\n");
        return BIOAPI_BSP_ERROR | BioAPIERR_BSP_LOAD_FAIL;
    }
    
    //Ok! Load it accordingly to the UUID
    if (BSPUuid == VERIDIS_BIOMETRIC_BSP_UUID) {
        BSP* bsp = NULL; //TODO: Instantiate BSP here!
        
        pthread_mutex_lock(&biospi_loaded_bsps_mutex);
        biospi_loaded_bsps[BSPUuid] = bsp;
        pthread_mutex_unlock(&biospi_loaded_bsps_mutex);
    
        pthread_mutex_unlock(&biospi_load_unload_mutex);
        return BioAPI_OK;
    }
    
    //The UUID was not found!
    pthread_mutex_unlock(&biospi_load_unload_mutex);
    BioUtil_Log(__func__, "BSP UUID not found\n");
    return BIOAPI_BSP_ERROR | BioAPIERR_INVALID_UUID;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


BioAPI_RETURN BioSPI_BSPUnload (
    const BioAPI_UUID *BSPUuid)
{
    //Check NULL arguments
    if (BSPUuid==NULL) {
        BioUtil_Log(__func__, "NULL BSP UUID\n");
        return BIOAPI_BSP_ERROR | BioAPIERR_INVALID_UUID;
    }
    
    pthread_mutex_lock(&biospi_load_unload_mutex);
    
    pthread_mutex_lock(&biospi_loaded_bsps_mutex);
    BSP* bsp = biospi_loaded_bsps[BSPUuid];
    biospi_loaded_bsps.erase(BSPUuid);
    pthread_mutex_unlock(&biospi_loaded_bsps_mutex);
    
    
    if (bsp == NULL) {
        pthread_mutex_unlock(&biospi_load_unload_mutex);
        BioUtil_Log(__func__, "BSP Not Loaded\n");
        return BIOAPI_BSP_ERROR | BioAPIERR_BSP_NOT_LOADED;
    }

    //TODO: Kill Attach Sessions
    delete bsp;
    pthread_mutex_unlock(&biospi_load_unload_mutex);
    return BioAPI_OK;
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


BioAPI_RETURN BioSPI_QueryUnits (
    const BioAPI_UUID *BSPUuid,
    BioAPI_UNIT_SCHEMA **UnitSchemaArray,
    uint32_t *NumberOfElements)
{    
    //Initialize output arguments
    if (UnitSchemaArray) *UnitSchemaArray=NULL;
    if (NumberOfElements) *NumberOfElements=0;
    
    //Check NULL arguments
    if (BSPUuid==NULL) {
        BioUtil_Log(__func__, "NULL BSP UUID\n");
        return BIOAPI_BSP_ERROR | BioAPIERR_INVALID_UUID;
    }
    if (UnitSchemaArray==NULL || NumberOfElements==NULL) {
        BioUtil_Log(__func__, "Invalid Unit List\n");
        return BIOAPI_BSP_ERROR | BioAPIERR_INVALID_UUID;
    }

    BSP_DO_CANCELLABLE(BSPUuid, __func__, QueryUnits(UnitSchemaArray, NumberOfElements) );
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


BioAPI_RETURN BioSPI_QueryBFPs (
    const BioAPI_UUID *BSPUuid,
    BioAPI_BFP_LIST_ELEMENT **BFPList,
    uint32_t *NumberOfElements)
{
    //Initialize output arguments
    if (BFPList) *BFPList=NULL;
    if (NumberOfElements) *NumberOfElements=0;
    
    //Check NULL arguments
    if (BSPUuid==NULL) {
        BioUtil_Log(__func__, "NULL BSP UUID\n");
        return BIOAPI_BSP_ERROR | BioAPIERR_INVALID_UUID;
    }
    if (BFPList==NULL || NumberOfElements==NULL) {
        BioUtil_Log(__func__, "Invalid BFP List\n");
        return BIOAPI_BSP_ERROR | BioAPIERR_INVALID_UUID;
    }
    
    BSP_DO_CANCELLABLE(BSPUuid, __func__, QueryBFPs(BFPList, NumberOfElements) );
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


BioAPI_RETURN BioSPI_BSPAttach (
    const BioAPI_UUID *BSPUuid,
    BioAPI_VERSION Version,
    const BioAPI_UNIT_LIST_ELEMENT *UnitList,
    uint32_t NumUnits,
    BioAPI_HANDLE BSPHandle)
{
    //Check NULL arguments
    if (BSPUuid==NULL) {
        BioUtil_Log(__func__, "NULL BSP UUID\n");
        return BIOAPI_BSP_ERROR | BioAPIERR_INVALID_UUID;
    }
    if (Version != 0x20) {
        BioUtil_Log(__func__, "Invalid Version: Only BioAPI 2.0 is supported\n");
        return BIOAPI_BSP_ERROR | BioAPIERR_INCOMPATIBLE_VERSION;
    }
    if (NumUnits && UnitList==NULL) {
        BioUtil_Log(__func__, "Invalid Unit List\n");
        return BIOAPI_BSP_ERROR | BioAPIERR_INVALID_INPUT_POINTER;
    }
    
    
    pthread_mutex_lock(&biospi_attach_detach_mutex);
    pthread_mutex_lock(&biospi_attached_sessions_mutex);
    
    if (biospi_attached_sessions.find(BSPHandle) != biospi_attached_sessions.end()) {
        pthread_mutex_unlock(&biospi_attached_sessions_mutex);
        pthread_mutex_unlock(&biospi_attach_detach_mutex);
        BioUtil_Log(__func__, "BSPHandle #%i is in use\n", BSPHandle);
        return BIOAPI_BSP_ERROR | BioAPIERR_INTERNAL_ERROR;
    }
    pthread_mutex_unlock(&biospi_attached_sessions_mutex);
    
    
    AttachSession* attachSession = NULL;
    BSP* bsp = NULL;
    BioAPI_RETURN ret = useBSP(BSPUuid, __func__, bsp);
    if (ret) {
        pthread_mutex_unlock(&biospi_attach_detach_mutex);
        return ret;
    }
    ret = bsp->BSPAttach(UnitList, NumUnits, BSPHandle, &attachSession);
    bsp->UseEnd(__func__);
    
    pthread_mutex_lock(&biospi_attached_sessions_mutex);
    biospi_attached_sessions[BSPHandle] = attachSession;
    pthread_mutex_unlock(&biospi_attached_sessions_mutex);
    
    pthread_mutex_unlock(&biospi_attach_detach_mutex);
    return ret;
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


BioAPI_RETURN BioSPI_BSPDetach (
    BioAPI_HANDLE BSPHandle)
{
    pthread_mutex_lock(&biospi_attach_detach_mutex);
    pthread_mutex_lock(&biospi_attached_sessions_mutex);
    AttachSession* session = biospi_attached_sessions[BSPHandle];
    biospi_attached_sessions.erase(BSPHandle);
    pthread_mutex_unlock(&biospi_attached_sessions_mutex);
    pthread_mutex_unlock(&biospi_attach_detach_mutex);
    
    if (session == NULL) {
        BioUtil_Log(__func__, "Invalid BSP Handle\n");
        return BIOAPI_BSP_ERROR | BioAPIERR_INVALID_BSP_HANDLE;
    } else {
        delete session;
        return BioAPI_OK;
    }
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

   
static BioAPI_RETURN useAttachSession(BioAPI_HANDLE BSPHandle, const char* task_name, AttachSession* &attachSession) {
    pthread_mutex_lock(&biospi_attach_detach_mutex);
    attachSession = biospi_attached_sessions[BSPHandle];
    if (attachSession == NULL) {
      biospi_attached_sessions.erase(BSPHandle);
      pthread_mutex_unlock(&biospi_attach_detach_mutex);
      BioUtil_Log(task_name, "Invalid BSP Handle\n");
      return BIOAPI_BSP_ERROR | BioAPIERR_INVALID_BSP_HANDLE;
    }
    if (!attachSession->UseStart(task_name) ) {
        pthread_mutex_unlock(&biospi_attach_detach_mutex);
        BioUtil_Log(task_name, "User Cancel\n");
        return BIOAPI_BSP_ERROR | BioAPIERR_USER_CANCELLED;
    }
    return BioAPI_OK;
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


#define ATTACHSESSION_DO_CANCELLABLE(BSPHandle, task_name, function) \
{ \
    AttachSession* attachSession = NULL; \
    BioAPI_RETURN ret  = useAttachSession(BSPHandle, task_name, attachSession); \
    if (ret) return ret; \
    ret = attachSession->function; \
    attachSession->UseEnd(task_name); \
    return ret;\
}
   
   
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
   

BioAPI_RETURN BioSPI_ControlUnit (
    BioAPI_HANDLE BSPHandle,
    BioAPI_UNIT_ID UnitID,
    uint32_t ControlCode,
    const BioAPI_DATA *InputData,
    BioAPI_DATA *OutputData)
{
    //Initialize output arguments
    if (OutputData) memset(OutputData, 0, sizeof(*OutputData));
    
    //Check NULL arguments
    if (InputData==NULL || (InputData->Length!=0 && InputData->Data==NULL) ) {
        BioUtil_Log(__func__, "NULL Input Data\n");
        return BIOAPI_BSP_ERROR | BioAPIERR_INVALID_INPUT_POINTER;
    }
    if (OutputData==NULL) {
        BioUtil_Log(__func__, "NULL Output Data\n");
        return BIOAPI_BSP_ERROR | BioAPIERR_INVALID_OUTPUT_POINTER;
    }
    
    ATTACHSESSION_DO_CANCELLABLE (BSPHandle, __func__,
        ControlUnit (
            UnitID,
            ControlCode,
            InputData,
            OutputData) );
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


BioAPI_RETURN BioSPI_FreeBIRHandle (
    BioAPI_HANDLE BSPHandle,
    BioAPI_BIR_HANDLE Handle)
{
    ATTACHSESSION_DO_CANCELLABLE (BSPHandle, __func__,
        FreeBIRHandle (Handle) );
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


BioAPI_RETURN BioSPI_GetBIRFromHandle (
    BioAPI_HANDLE BSPHandle,
    BioAPI_BIR_HANDLE Handle,
    BioAPI_BIR *BIR)
{
      //Initialize output arguments
    if (BIR) memset(BIR, 0, sizeof(*BIR));
    
    //Check NULL arguments
    if (BIR==NULL) {
        BioUtil_Log(__func__, "NULL Output BIR\n");
        return BIOAPI_BSP_ERROR | BioAPIERR_INVALID_OUTPUT_POINTER;
    }
    
    ATTACHSESSION_DO_CANCELLABLE (BSPHandle, __func__,
        GetBIRFromHandle (
            Handle,
            BIR) );
}

BioAPI_RETURN BioSPI_GetHeaderFromHandle (
    BioAPI_HANDLE BSPHandle,
    BioAPI_BIR_HANDLE Handle,
    BioAPI_BIR_HEADER *Header)
{
  
    //Initialize output arguments
    if (Header) memset(Header, 0, sizeof(*Header));
    
    //Check NULL arguments
    if (Header==NULL) {
        BioUtil_Log(__func__, "NULL Output Header\n");
        return BIOAPI_BSP_ERROR | BioAPIERR_INVALID_OUTPUT_POINTER;
    }
    
    ATTACHSESSION_DO_CANCELLABLE (BSPHandle, __func__,
        GetHeaderFromHandle (
            Handle,
            Header) );
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


BioAPI_RETURN BioSPI_EnableEvents (
    BioAPI_HANDLE BSPHandle,
    BioAPI_EVENT_MASK Events)
{
    ATTACHSESSION_DO_CANCELLABLE (BSPHandle, __func__,
        EnableEvents (
            Events) );
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


BioAPI_RETURN BioSPI_SetGUICallbacks (
    BioAPI_HANDLE BSPHandle,
    BioAPI_GUI_STREAMING_CALLBACK GuiStreamingCallback,
    void *GuiStreamingCallbackCtx,
    BioAPI_GUI_STATE_CALLBACK GuiStateCallback,
    void *GuiStateCallbackCtx)
{
    ATTACHSESSION_DO_CANCELLABLE (BSPHandle, __func__,
        SetGUICallbacks (
            GuiStreamingCallback,
            GuiStreamingCallbackCtx,
            GuiStateCallback,
            GuiStateCallbackCtx) );
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


BioAPI_RETURN BioSPI_Capture(
    BioAPI_HANDLE BSPHandle,
    BioAPI_BIR_PURPOSE Purpose,
    BioAPI_BIR_SUBTYPE Subtype,
    const BioAPI_BIR_BIOMETRIC_DATA_FORMAT *OutputFormat,
    BioAPI_BIR_HANDLE *CapturedBIR,
    int32_t Timeout,
    BioAPI_BIR_HANDLE *AuditData)
{
    //Initialize output arguments
    if (Timeout<0) Timeout = DEFAULT_CAPTURE_TIMEOUT;
    if (CapturedBIR) *CapturedBIR = BioAPI_INVALID_BIR_HANDLE;
    if (AuditData)   *AuditData = BioAPI_INVALID_BIR_HANDLE;
    
    //Check NULL arguments
    if (CapturedBIR==NULL) {
        BioUtil_Log(__func__, "NULL CapturedBIR\n");
        return BIOAPI_BSP_ERROR | BioAPIERR_INVALID_OUTPUT_POINTER;
    }
    
    ATTACHSESSION_DO_CANCELLABLE (BSPHandle, __func__,
        Capture (
            Purpose,
            Subtype,
            OutputFormat,
            CapturedBIR,
            Timeout,
            AuditData) );
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


BioAPI_RETURN BioSPI_CreateTemplate (
    BioAPI_HANDLE BSPHandle,
    const BioAPI_INPUT_BIR *CapturedBIR,
    const BioAPI_INPUT_BIR *ReferenceTemplate,
    const BioAPI_BIR_BIOMETRIC_DATA_FORMAT *OutputFormat,
    BioAPI_BIR_HANDLE *NewTemplate,
    const BioAPI_DATA *Payload,
    BioAPI_UUID *TemplateUUID)
{
    //Initialize output arguments 
    if (NewTemplate) *NewTemplate = BioAPI_INVALID_BIR_HANDLE;
    if (TemplateUUID) memset(TemplateUUID, 0, sizeof(*TemplateUUID));
    
    //Check NULL arguments
    if (CapturedBIR==NULL) {
        BioUtil_Log(__func__, "NULL CapturedBIR\n");
        return BIOAPI_BSP_ERROR | BioAPIERR_INVALID_INPUT_POINTER;
    }
    if (NewTemplate==NULL) {
        BioUtil_Log(__func__, "NULL NewTemplate\n");
        return BIOAPI_BSP_ERROR | BioAPIERR_INVALID_OUTPUT_POINTER;
    }
    
    ATTACHSESSION_DO_CANCELLABLE (BSPHandle, __func__,
        CreateTemplate (
            CapturedBIR,
            ReferenceTemplate,
            OutputFormat,
            NewTemplate,
            Payload,
            TemplateUUID) );
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


BioAPI_RETURN BioSPI_Process (
    BioAPI_HANDLE BSPHandle,
    const BioAPI_INPUT_BIR *CapturedBIR,
    const BioAPI_BIR_BIOMETRIC_DATA_FORMAT *OutputFormat,
    BioAPI_BIR_HANDLE *ProcessedBIR)
{
    //Initialize output arguments 
    if (ProcessedBIR) *ProcessedBIR = BioAPI_INVALID_BIR_HANDLE;
    
    //Check NULL arguments
    if (CapturedBIR==NULL) {
        BioUtil_Log(__func__, "NULL CapturedBIR\n");
        return BIOAPI_BSP_ERROR | BioAPIERR_INVALID_INPUT_POINTER;
    }
    if (ProcessedBIR==NULL) {
        BioUtil_Log(__func__, "NULL ProcessedBIR\n");
        return BIOAPI_BSP_ERROR | BioAPIERR_INVALID_OUTPUT_POINTER;
    }
    
    ATTACHSESSION_DO_CANCELLABLE (BSPHandle, __func__,
        Process (
            CapturedBIR,
            OutputFormat,
            ProcessedBIR) );
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


BioAPI_RETURN BioSPI_ProcessWithAuxBIR (
    BioAPI_HANDLE BSPHandle,
    const BioAPI_INPUT_BIR *CapturedBIR,
    const BioAPI_INPUT_BIR *AuxiliaryData,
    const BioAPI_BIR_BIOMETRIC_DATA_FORMAT *OutputFormat,
    BioAPI_BIR_HANDLE *ProcessedBIR)
{
    //Initialize output arguments 
    if (ProcessedBIR) *ProcessedBIR = BioAPI_INVALID_BIR_HANDLE;
    
    //Check NULL arguments
    if (CapturedBIR==NULL || AuxiliaryData==NULL) {
        BioUtil_Log(__func__, "NULL CapturedBIR\n");
        return BIOAPI_BSP_ERROR | BioAPIERR_INVALID_INPUT_POINTER;
    }
    if (AuxiliaryData==NULL) {
        BioUtil_Log(__func__, "NULL AuxiliaryData\n");
        return BIOAPI_BSP_ERROR | BioAPIERR_INVALID_INPUT_POINTER;
    }
    if (ProcessedBIR==NULL) {
        BioUtil_Log(__func__, "NULL ProcessedBIR\n");
        return BIOAPI_BSP_ERROR | BioAPIERR_INVALID_OUTPUT_POINTER;
    }
    
    ATTACHSESSION_DO_CANCELLABLE (BSPHandle, __func__,
        ProcessWithAuxBIR (
            CapturedBIR,
            AuxiliaryData,
            OutputFormat,
            ProcessedBIR) );
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


BioAPI_RETURN BioSPI_VerifyMatch (
    BioAPI_HANDLE BSPHandle,
    BioAPI_FMR MaxFMRRequested,
    const BioAPI_INPUT_BIR *ProcessedBIR,
    const BioAPI_INPUT_BIR *ReferenceTemplate,
    BioAPI_BIR_HANDLE *AdaptedBIR,
    BioAPI_BOOL *Result,
    BioAPI_FMR *FMRAchieved,
    BioAPI_DATA *Payload);


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



BioAPI_RETURN BioSPI_IdentifyMatch (
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

BioAPI_RETURN BioSPI_Enroll (
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

BioAPI_RETURN BioSPI_Verify (
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

BioAPI_RETURN BioSPI_Identify (
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

BioAPI_RETURN BioSPI_Import (
    BioAPI_HANDLE BSPHandle,
    const BioAPI_DATA *InputData,
    const BioAPI_BIR_BIOMETRIC_DATA_FORMAT *InputFormat,
    const BioAPI_BIR_BIOMETRIC_DATA_FORMAT *OutputFormat,
    BioAPI_BIR_PURPOSE Purpose,
    BioAPI_BIR_HANDLE *ConstructedBIR);

BioAPI_RETURN BioSPI_PresetIdentifyPopulation (
    BioAPI_HANDLE BSPHandle,
    const BioAPI_IDENTIFY_POPULATION *Population);

BioAPI_RETURN BioSPI_DbOpen (
    BioAPI_HANDLE BSPHandle,
    const BioAPI_UUID *DbUuid,
    BioAPI_DB_ACCESS_TYPE AccessRequest,
    BioAPI_DB_HANDLE *DbHandle,
    BioAPI_DB_MARKER_HANDLE *MarkerHandle);

BioAPI_RETURN BioSPI_DbClose(
    BioAPI_HANDLE BSPHandle,
    BioAPI_DB_HANDLE DbHandle);

BioAPI_RETURN BioSPI_DbCreate (
    BioAPI_HANDLE BSPHandle,
    const BioAPI_UUID *DbUuid,
    uint32_t NumberOfRecords,
    BioAPI_DB_ACCESS_TYPE AccessRequest,
    BioAPI_DB_HANDLE *DbHandle);

BioAPI_RETURN BioSPI_DbDelete (
    BioAPI_HANDLE BSPHandle,
    const BioAPI_UUID *DbUuid);

BioAPI_RETURN BioSPI_DbSetMarker (
    BioAPI_HANDLE BSPHandle,
    BioAPI_DB_HANDLE DbHandle,
    const BioAPI_UUID *KeyValue,
    BioAPI_DB_MARKER_HANDLE MarkerHandle);

BioAPI_RETURN BioSPI_DbFreeMarker (
    BioAPI_HANDLE BSPHandle,
    BioAPI_DB_MARKER_HANDLE MarkerHandle);

BioAPI_RETURN BioSPI_DbStoreBIR(
    BioAPI_HANDLE BSPHandle,
    const BioAPI_INPUT_BIR *BIRToStore,
    BioAPI_DB_HANDLE DbHandle,
    BioAPI_UUID *BirUuid);

BioAPI_RETURN BioSPI_DbGetBIR (
    BioAPI_HANDLE BSPHandle,
    BioAPI_DB_HANDLE DbHandle,
    const BioAPI_UUID *KeyValue,
    BioAPI_BIR_HANDLE *RetrievedBIR,
    BioAPI_DB_MARKER_HANDLE *MarkerHandle);

BioAPI_RETURN BioSPI_DbGetNextBIR (
    BioAPI_HANDLE BSPHandle,
    BioAPI_DB_HANDLE DbHandle,
    BioAPI_DB_MARKER_HANDLE MarkerHandle,
    BioAPI_BIR_HANDLE *RetrievedBIR,
    BioAPI_UUID *BirUuid);

BioAPI_RETURN BioSPI_DbDeleteBIR(
    BioAPI_HANDLE BSPHandle,
    BioAPI_DB_HANDLE DbHandle,
    const BioAPI_UUID *KeyValue);

BioAPI_RETURN BioSPI_SetPowerMode (
    BioAPI_HANDLE BSPHandle,
    BioAPI_UNIT_ID UnitId,
    BioAPI_POWER_MODE PowerMode);

BioAPI_RETURN BioSPI_SetIndicatorStatus (
    BioAPI_HANDLE BSPHandle,
    BioAPI_UNIT_ID UnitId,
    BioAPI_INDICATOR_STATUS IndicatorStatus);

BioAPI_RETURN BioSPI_GetIndicatorStatus (
    BioAPI_HANDLE BSPHandle,
    BioAPI_UNIT_ID UnitId,
    BioAPI_INDICATOR_STATUS *IndicatorStatus);

BioAPI_RETURN BioSPI_CalibrateSensor (
    BioAPI_HANDLE BSPHandle,
    int32_t Timeout);

BioAPI_RETURN BioSPI_Cancel (
    BioAPI_HANDLE BSPHandle);
