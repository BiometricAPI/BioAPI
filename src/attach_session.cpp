#include "common.h"

 
#define UNIT_DO_CANCELLABLE(unit, task_name, function) \
{ \
    if (!(unit)->UseStart(task_name) ) \
        return BIOAPI_UNIT_ERROR | BioAPIERR_USER_CANCELLED; \
    BioAPI_RETURN ret = (unit)->function; \
    (unit)->UseEnd(task_name); \
    return ret;\
}





static void FreeBIR (
    BioAPI_BIR *Ptr)
{
    if (Ptr != NULL) {
        BioSPI_Free (Ptr->BiometricData.Data);
        BioSPI_Free (Ptr->SecurityBlock.Data);
        BioSPI_Free (Ptr);
    }
}





AttachSession::AttachSession (
    UnitArchive *unitArchive, 
    UnitMatching *unitMatching, 
    UnitProcessing *unitProcessing, 
    UnitSensor *unitSensor)
:   
    bir_handles(FreeBIR),
    unitArchive (unitArchive),
    unitMatching (unitMatching),
    unitProcessing (unitProcessing),
    unitSensor (unitSensor)
{ }


AttachSession::~AttachSession ()
{
    Cancel();
    if (unitArchive)    delete unitArchive;
    if (unitMatching)   delete unitMatching;
    if (unitProcessing) delete unitProcessing;
    if (unitSensor)     delete unitSensor;
}


void AttachSession::CancelTasksAsync() 
{
    if (unitArchive)
        unitArchive->CancelAsync();
    if (unitMatching)
        unitMatching->CancelAsync();
    if (unitProcessing)
        unitProcessing->CancelAsync();  
    if (unitSensor)
        unitSensor->CancelAsync();  
}


void AttachSession::CancelTasksJoin() 
{
    if (unitArchive)
        unitArchive->CancelJoin();
    if (unitMatching)
        unitMatching->CancelJoin();
    if (unitProcessing)
        unitProcessing->CancelJoin();  
    if (unitSensor)
        unitSensor->CancelJoin();  
}



////////////////////////////////////////////////////////////////////////////////////////////////////


    
BioAPI_RETURN AttachSession::FreeBIRHandle (
    BioAPI_BIR_HANDLE Handle)
{
    if (!bir_handles.Remove(Handle, __func__))
        return BioAPIERR_INVALID_BIR_HANDLE;
    return BioAPI_OK;
}

///Called by \ref BioSPI_GetBIRFromHandle
BioAPI_RETURN AttachSession::GetBIRFromHandle (
    BioAPI_BIR_HANDLE Handle,
    BioAPI_BIR *BIR)
{
    BioAPI_BIR* data = bir_handles.Get(Handle, __func__);
    if (data == NULL)
        return BioAPIERR_INVALID_BIR_HANDLE;
    
    BioUtil_CloneBIR(*BIR, *data);
    
    bir_handles.Release(Handle, __func__, true); //Releases and removes the handle
    
    return BioAPI_OK;
}

///Called by \ref BioSPI_GetHeaderFromHandle
BioAPI_RETURN AttachSession::GetHeaderFromHandle (
    BioAPI_BIR_HANDLE Handle,
    BioAPI_BIR_HEADER *Header)
{
    BioAPI_BIR* data = bir_handles.Get(Handle, __func__);
    if (data == NULL)
        return BioAPIERR_INVALID_BIR_HANDLE;
    
    *Header = data->Header;
    
    bir_handles.Release(Handle, __func__); //Releases
    
    return BioAPI_OK;
}



////////////////////////////////////////////////////////////////////////////////////////////////////


    
Unit* AttachSession::GetUnit (
    BioAPI_UNIT_ID UnitID) 
{
    if (unitArchive->getUnitID() == UnitID)
        return unitArchive;
    if (unitMatching->getUnitID() == UnitID)
        return unitMatching;
    if (unitProcessing->getUnitID() == UnitID)
        return unitProcessing;
    if (unitSensor->getUnitID() == UnitID)
        return unitSensor;  
    return NULL;
}
    
BioAPI_RETURN AttachSession::ControlUnit (
    BioAPI_UNIT_ID UnitID,
    uint32_t ControlCode,
    const BioAPI_DATA *InputData,
    BioAPI_DATA *OutputData)
{
  Unit* unit = GetUnit(UnitID);
  if (unit==NULL)
      return BIOAPI_BSP_ERROR | BioAPIERR_FUNCTION_NOT_SUPPORTED;
  
  UNIT_DO_CANCELLABLE(
      unit, 
      __func__, 
      ControlUnit (
          this,
          ControlCode,
          InputData,
          OutputData ) );
}


BioAPI_RETURN AttachSession::SetPowerMode (
    BioAPI_UNIT_ID UnitID,
    BioAPI_POWER_MODE PowerMode)
{
    Unit* unit = GetUnit(UnitID);
    if (unit==NULL)
        return BIOAPI_BSP_ERROR | BioAPIERR_FUNCTION_NOT_SUPPORTED;
    
    UNIT_DO_CANCELLABLE(
        unit, 
        __func__, 
        SetPowerMode (
            this,
            PowerMode ) );
}

BioAPI_RETURN AttachSession::SetIndicatorStatus (
    BioAPI_UNIT_ID UnitID,
    BioAPI_INDICATOR_STATUS IndicatorStatus)
{
    Unit* unit = GetUnit(UnitID);
    if (unit==NULL)
        return BIOAPI_BSP_ERROR | BioAPIERR_FUNCTION_NOT_SUPPORTED;
    
    UNIT_DO_CANCELLABLE(
        unit, 
        __func__, 
        SetIndicatorStatus ( 
            this,
            IndicatorStatus ) );
}


BioAPI_RETURN AttachSession::GetIndicatorStatus (
    BioAPI_UNIT_ID UnitID,
    BioAPI_INDICATOR_STATUS *IndicatorStatus)
{
    Unit* unit = GetUnit(UnitID);
    if (unit==NULL)
        return BIOAPI_BSP_ERROR | BioAPIERR_FUNCTION_NOT_SUPPORTED;
    
    UNIT_DO_CANCELLABLE(
        unit, 
        __func__, 
        GetIndicatorStatus ( 
            this,
            IndicatorStatus ) );  
}
    
    
    
    
    
////////////////////////////////////////////////////////////////////////////////////////////////////
    
    
    
    
    
BioAPI_RETURN AttachSession::DbOpen (
    const BioAPI_UUID *DbUuid,
    BioAPI_DB_ACCESS_TYPE AccessRequest,
    BioAPI_DB_HANDLE *DbHandle,
    BioAPI_DB_MARKER_HANDLE *MarkerHandle) 
{
    if (unitArchive==NULL)
        return BIOAPI_BSP_ERROR | BioAPIERR_FUNCTION_NOT_SUPPORTED;
    
    UNIT_DO_CANCELLABLE(
        unitArchive, 
        __func__, 
        DbOpen ( 
            this,
            DbUuid,
            AccessRequest,
            DbHandle,
            MarkerHandle ) );  
}


BioAPI_RETURN AttachSession::DbClose (
    BioAPI_DB_HANDLE DbHandle)
{
    if (unitArchive==NULL)
        return BIOAPI_BSP_ERROR | BioAPIERR_FUNCTION_NOT_SUPPORTED;
    
    UNIT_DO_CANCELLABLE(
        unitArchive, 
        __func__, 
        DbClose ( 
            this,
            DbHandle ) );  
}

BioAPI_RETURN AttachSession::DbCreate (
    const BioAPI_UUID *DbUuid,
    uint32_t NumberOfRecords,
    BioAPI_DB_ACCESS_TYPE AccessRequest,
    BioAPI_DB_HANDLE *DbHandle)
{
    if (unitArchive==NULL)
        return BIOAPI_BSP_ERROR | BioAPIERR_FUNCTION_NOT_SUPPORTED;
    
    UNIT_DO_CANCELLABLE(
        unitArchive, 
        __func__, 
        DbCreate ( 
            this,
            DbUuid,
            NumberOfRecords,
            AccessRequest,
            DbHandle ) );  
}


BioAPI_RETURN AttachSession::DbDelete (
    const BioAPI_UUID *DbUuid)
{
    if (unitArchive==NULL)
        return BIOAPI_BSP_ERROR | BioAPIERR_FUNCTION_NOT_SUPPORTED;
    
    UNIT_DO_CANCELLABLE(
        unitArchive, 
        __func__, 
        DbDelete ( 
            this,
            DbUuid ) );  
}


BioAPI_RETURN AttachSession::DbSetMarker (
    BioAPI_DB_HANDLE DbHandle,
    const BioAPI_UUID *KeyValue,
    BioAPI_DB_MARKER_HANDLE MarkerHandle)
{
    if (unitArchive==NULL)
        return BIOAPI_BSP_ERROR | BioAPIERR_FUNCTION_NOT_SUPPORTED;
    
    UNIT_DO_CANCELLABLE(
        unitArchive, 
        __func__, 
        DbSetMarker ( 
            this,
            DbHandle,
            KeyValue,
            MarkerHandle ) );  
}


BioAPI_RETURN AttachSession::DbFreeMarker (
    BioAPI_DB_MARKER_HANDLE MarkerHandle)
{
    if (unitArchive==NULL)
        return BIOAPI_BSP_ERROR | BioAPIERR_FUNCTION_NOT_SUPPORTED;
    
    UNIT_DO_CANCELLABLE(
        unitArchive, 
        __func__, 
        DbFreeMarker ( 
            this,
            MarkerHandle ) );  
}


BioAPI_RETURN AttachSession::DbStoreBIR (
    const BioAPI_INPUT_BIR *BIRToStore,
    BioAPI_DB_HANDLE DbHandle,
    BioAPI_UUID *BirUuid)
{
    if (unitArchive==NULL)
        return BIOAPI_BSP_ERROR | BioAPIERR_FUNCTION_NOT_SUPPORTED;
    
    UNIT_DO_CANCELLABLE(
        unitArchive, 
        __func__, 
        DbStoreBIR ( 
            this,
            BIRToStore,
            DbHandle,
            BirUuid ) );  
}


BioAPI_RETURN AttachSession::DbGetBIR (
    BioAPI_DB_HANDLE DbHandle,
    const BioAPI_UUID *KeyValue,
    BioAPI_BIR_HANDLE *RetrievedBIR,
    BioAPI_DB_MARKER_HANDLE *MarkerHandle)
{
    if (unitArchive==NULL)
        return BIOAPI_BSP_ERROR | BioAPIERR_FUNCTION_NOT_SUPPORTED;
    
    UNIT_DO_CANCELLABLE(
        unitArchive, 
        __func__, 
        DbGetBIR ( 
            this,
            DbHandle,
            KeyValue,
            RetrievedBIR,
            MarkerHandle) );  
}


BioAPI_RETURN AttachSession::DbGetNextBIR (
    BioAPI_DB_HANDLE DbHandle,
    BioAPI_DB_MARKER_HANDLE MarkerHandle,
    BioAPI_BIR_HANDLE *RetrievedBIR,
    BioAPI_UUID *BirUuid)
{
    if (unitArchive==NULL)
        return BIOAPI_BSP_ERROR | BioAPIERR_FUNCTION_NOT_SUPPORTED;
    
    UNIT_DO_CANCELLABLE(
        unitArchive, 
        __func__, 
        DbGetNextBIR ( 
            this,
            DbHandle,
            MarkerHandle,
            RetrievedBIR,
            BirUuid ) );  
}

BioAPI_RETURN AttachSession::DbDeleteBIR (
    BioAPI_DB_HANDLE DbHandle,
    const BioAPI_UUID *KeyValue)
{
    if (unitArchive==NULL)
        return BIOAPI_BSP_ERROR | BioAPIERR_FUNCTION_NOT_SUPPORTED;
    
    UNIT_DO_CANCELLABLE(
        unitArchive, 
        __func__, 
        DbDeleteBIR ( 
            this,
            DbHandle,
            KeyValue ) );  
}
    
    
    
    
    
////////////////////////////////////////////////////////////////////////////////////////////////////
    
    
    
    

BioAPI_RETURN AttachSession::VerifyMatch (
    BioAPI_FMR MaxFMRRequested,
    const BioAPI_INPUT_BIR *ProcessedBIR,
    const BioAPI_INPUT_BIR *ReferenceTemplate,
    BioAPI_BIR_HANDLE *AdaptedBIR,
    BioAPI_BOOL *Result,
    BioAPI_FMR *FMRAchieved,
    BioAPI_DATA *Payload)
{
    if (unitMatching==NULL)
        return BIOAPI_BSP_ERROR | BioAPIERR_FUNCTION_NOT_SUPPORTED;
    
    UNIT_DO_CANCELLABLE(
        unitMatching, 
        __func__, 
        VerifyMatch ( 
            this,
            MaxFMRRequested,
            ProcessedBIR,
            ReferenceTemplate,
            AdaptedBIR,
            Result,
            FMRAchieved,
            Payload ) );  
}


BioAPI_RETURN AttachSession::IdentifyMatch (
    BioAPI_FMR MaxFMRRequested,
    const BioAPI_INPUT_BIR *ProcessedBIR,
    const BioAPI_IDENTIFY_POPULATION *Population,
    uint32_t TotalNumberOfTemplates,
    BioAPI_BOOL Binning,
    uint32_t MaxNumberOfResults,
    uint32_t *NumberOfResults,
    BioAPI_CANDIDATE **Candidates,
    int32_t Timeout)
{
    if (unitMatching==NULL)
        return BIOAPI_BSP_ERROR | BioAPIERR_FUNCTION_NOT_SUPPORTED;
    
    UNIT_DO_CANCELLABLE(
        unitMatching, 
        __func__, 
        IdentifyMatch ( 
            this,
            MaxFMRRequested,
            ProcessedBIR,
            Population,
            TotalNumberOfTemplates,
            Binning,
            MaxNumberOfResults,
            NumberOfResults,
            Candidates,
            Timeout ) );  
}


BioAPI_RETURN AttachSession::PresetIdentifyPopulation (
    const BioAPI_IDENTIFY_POPULATION *Population)
{
    if (unitMatching==NULL)
        return BIOAPI_BSP_ERROR | BioAPIERR_FUNCTION_NOT_SUPPORTED;
    
    UNIT_DO_CANCELLABLE(
        unitMatching, 
        __func__, 
        PresetIdentifyPopulation ( 
            this,
            Population ) );  
}
    
    
    
    
    
////////////////////////////////////////////////////////////////////////////////////////////////////
    
    
    
    

BioAPI_RETURN AttachSession::CreateTemplate (
    const BioAPI_INPUT_BIR *CapturedBIR,
    const BioAPI_INPUT_BIR *ReferenceTemplate,
    const BioAPI_BIR_BIOMETRIC_DATA_FORMAT *OutputFormat,
    BioAPI_BIR_HANDLE *NewTemplate,
    const BioAPI_DATA *Payload,
    BioAPI_UUID *TemplateUUID)
{
    if (unitProcessing==NULL)
        return BIOAPI_BSP_ERROR | BioAPIERR_FUNCTION_NOT_SUPPORTED;
    
    UNIT_DO_CANCELLABLE(
        unitProcessing, 
        __func__, 
        CreateTemplate ( 
            this,
            CapturedBIR,
            ReferenceTemplate,
            OutputFormat,
            NewTemplate,
            Payload,
            TemplateUUID ) );
}


BioAPI_RETURN AttachSession::Process (
    const BioAPI_INPUT_BIR *CapturedBIR,
    const BioAPI_BIR_BIOMETRIC_DATA_FORMAT *OutputFormat,
    BioAPI_BIR_HANDLE *ProcessedBIR)
{
    if (unitProcessing==NULL)
        return BIOAPI_BSP_ERROR | BioAPIERR_FUNCTION_NOT_SUPPORTED;
    
    UNIT_DO_CANCELLABLE(
        unitProcessing, 
        __func__, 
        Process (
            this,
            CapturedBIR,
            OutputFormat,
            ProcessedBIR ) );
}


BioAPI_RETURN AttachSession::ProcessWithAuxBIR (
    const BioAPI_INPUT_BIR *CapturedBIR,
    const BioAPI_INPUT_BIR *AuxiliaryData,
    const BioAPI_BIR_BIOMETRIC_DATA_FORMAT *OutputFormat,
    BioAPI_BIR_HANDLE *ProcessedBIR)
{
    if (unitProcessing==NULL)
        return BIOAPI_BSP_ERROR | BioAPIERR_FUNCTION_NOT_SUPPORTED;
    
    UNIT_DO_CANCELLABLE(
        unitProcessing, 
        __func__, 
        ProcessWithAuxBIR ( 
            this,
            CapturedBIR,
            AuxiliaryData,
            OutputFormat,
            ProcessedBIR ) );
}
    
    
    
    
    
////////////////////////////////////////////////////////////////////////////////////////////////////
    
    
    
    

BioAPI_RETURN AttachSession::Capture (
    BioAPI_BIR_PURPOSE Purpose,
    BioAPI_BIR_SUBTYPE Subtype,
    const BioAPI_BIR_BIOMETRIC_DATA_FORMAT *OutputFormat,
    BioAPI_BIR_HANDLE *CapturedBIR,
    int32_t Timeout,
    BioAPI_BIR_HANDLE *AuditData)
{
    if (unitSensor==NULL)
        return BIOAPI_BSP_ERROR | BioAPIERR_FUNCTION_NOT_SUPPORTED;
    
    UNIT_DO_CANCELLABLE(
        unitSensor, 
        __func__, 
        Capture (
            this,
            Purpose,
            Subtype,
            OutputFormat,
            CapturedBIR,
            Timeout,
            AuditData ) );
}


BioAPI_RETURN AttachSession::CalibrateSensor (
    int32_t Timeout)
{
    if (unitSensor==NULL)
        return BIOAPI_BSP_ERROR | BioAPIERR_FUNCTION_NOT_SUPPORTED;
    
    UNIT_DO_CANCELLABLE(
        unitSensor, 
        __func__, 
        CalibrateSensor ( 
            this,
            Timeout ) );
}





////////////////////////////////////////////////////////////////////////////////////////////////////





//TODO: Implementar Enroll de forma genérica e bonita
BioAPI_RETURN AttachSession::Enroll ( 
    BioAPI_BIR_PURPOSE Purpose,
    BioAPI_BIR_SUBTYPE Subtype,
    const BioAPI_BIR_BIOMETRIC_DATA_FORMAT *OutputFormat,
    const BioAPI_INPUT_BIR *ReferenceTemplate,
    BioAPI_BIR_HANDLE *NewTemplate,
    const BioAPI_DATA *Payload,
    int32_t Timeout,
    BioAPI_BIR_HANDLE *AuditData,
    BioAPI_UUID *TemplateUUID)
{
    return BIOAPI_BSP_ERROR | BioAPIERR_FUNCTION_NOT_SUPPORTED;
}



BioAPI_RETURN AttachSession::Verify (
    BioAPI_FMR MaxFMRRequested,
    const BioAPI_INPUT_BIR *ReferenceTemplate,
    BioAPI_BIR_SUBTYPE Subtype,
    BioAPI_BIR_HANDLE *AdaptedBIR,
    BioAPI_BOOL *Result,
    BioAPI_FMR *FMRAchieved,
    BioAPI_DATA *Payload,
    int32_t Timeout,
    BioAPI_BIR_HANDLE *AuditData)
{
    if (unitSensor==NULL || unitMatching==NULL || unitProcessing==NULL)
        return BIOAPI_BSP_ERROR | BioAPIERR_FUNCTION_NOT_SUPPORTED;
    
    uint64_t start_timestamp = BioUtil_Timestamp();
    int32_t timeout_remaining = start_timestamp + Timeout - BioUtil_Timestamp();
    BioAPI_RETURN ret = BioAPI_OK;
    
    BioAPI_BIR_HANDLE capturedBirHandle  = BioAPI_INVALID_BIR_HANDLE;
    BioAPI_INPUT_BIR capturedBirInput;
    capturedBirInput.Form = BioAPI_BIR_HANDLE_INPUT;
    capturedBirInput.InputBIR.BIRinBSP = &capturedBirHandle;
    
    BioAPI_BIR_HANDLE processedBirHandle = BioAPI_INVALID_BIR_HANDLE;
    BioAPI_INPUT_BIR processedBirInput;
    processedBirInput.Form = BioAPI_BIR_HANDLE_INPUT;
    processedBirInput.InputBIR.BIRinBSP = &processedBirHandle;
       
    
    
    ret = Capture (
        BioAPI_PURPOSE_VERIFY,
        Subtype,
        NULL,
        &capturedBirHandle,
        timeout_remaining,
        AuditData );
    timeout_remaining = start_timestamp + Timeout - BioUtil_Timestamp();
    if (ret == BioAPI_OK && timeout_remaining <= 0)
        ret = BioAPIERR_TIMEOUT_EXPIRED;
    if (ret != BioAPI_OK) {
        if (AuditData) {
            FreeBIRHandle(*AuditData);
            *AuditData = BioAPI_INVALID_BIR_HANDLE;
        }
        return ret;
    }

    
    
    ret = Process (
        &capturedBirInput,
        NULL,
        &processedBirHandle );
    FreeBIRHandle(capturedBirHandle);
    timeout_remaining = start_timestamp + Timeout - BioUtil_Timestamp();
    if (ret == BioAPI_OK && timeout_remaining <= 0)
        ret = BioAPIERR_TIMEOUT_EXPIRED;
    if (ret != BioAPI_OK) {
        if (AuditData) {
            FreeBIRHandle(*AuditData);
            *AuditData = BioAPI_INVALID_BIR_HANDLE;
        }
        return ret;
    }
    
        

    ret = VerifyMatch (
        MaxFMRRequested,
        &processedBirInput,
        ReferenceTemplate,
        AdaptedBIR,
        Result,
        FMRAchieved,
        Payload);
    FreeBIRHandle(processedBirHandle);
    if (ret != BioAPI_OK) {
        if (AuditData) {
            FreeBIRHandle(*AuditData);
            *AuditData = BioAPI_INVALID_BIR_HANDLE;
        }
        return ret;
    }
    
    
    
    return BioAPI_OK;
}



BioAPI_RETURN AttachSession::Identify (
    BioAPI_FMR MaxFMRRequested,
    BioAPI_BIR_SUBTYPE Subtype,
    const BioAPI_IDENTIFY_POPULATION *Population,
    uint32_t TotalNumberOfTemplates,
    BioAPI_BOOL Binning,
    uint32_t MaxNumberOfResults,
    uint32_t *NumberOfResults,
    BioAPI_CANDIDATE **Candidates,
    int32_t Timeout,
    BioAPI_BIR_HANDLE *AuditData)
{
    if (unitSensor==NULL || unitMatching==NULL || unitProcessing==NULL)
        return BIOAPI_BSP_ERROR | BioAPIERR_FUNCTION_NOT_SUPPORTED;
    
    uint64_t start_timestamp = BioUtil_Timestamp();
    int32_t timeout_remaining = start_timestamp + Timeout - BioUtil_Timestamp();
    BioAPI_RETURN ret = BioAPI_OK;
    
    BioAPI_BIR_HANDLE capturedBirHandle  = BioAPI_INVALID_BIR_HANDLE;
    BioAPI_INPUT_BIR capturedBirInput;
    capturedBirInput.Form = BioAPI_BIR_HANDLE_INPUT;
    capturedBirInput.InputBIR.BIRinBSP = &capturedBirHandle;
    
    BioAPI_BIR_HANDLE processedBirHandle = BioAPI_INVALID_BIR_HANDLE;
    BioAPI_INPUT_BIR processedBirInput;
    processedBirInput.Form = BioAPI_BIR_HANDLE_INPUT;
    processedBirInput.InputBIR.BIRinBSP = &processedBirHandle;
       
    
    
    ret = Capture (
        BioAPI_PURPOSE_IDENTIFY,
        Subtype,
        NULL,
        &capturedBirHandle,
        timeout_remaining,
        AuditData );
    timeout_remaining = start_timestamp + Timeout - BioUtil_Timestamp();
    if (ret == BioAPI_OK && timeout_remaining <= 0)
        ret = BioAPIERR_TIMEOUT_EXPIRED;
    if (ret != BioAPI_OK) {
        if (AuditData) {
            FreeBIRHandle(*AuditData);
            *AuditData = BioAPI_INVALID_BIR_HANDLE;
        }
        return ret;
    }
    

    
    ret = Process (
        &capturedBirInput,
        NULL,
        &processedBirHandle );
    FreeBIRHandle(capturedBirHandle);
    timeout_remaining = start_timestamp + Timeout - BioUtil_Timestamp();
    if (ret == BioAPI_OK && timeout_remaining <= 0)
        ret = BioAPIERR_TIMEOUT_EXPIRED;
    if (ret != BioAPI_OK) {
        if (AuditData) {
            FreeBIRHandle(*AuditData);
            *AuditData = BioAPI_INVALID_BIR_HANDLE;
        }
        return ret;
    }
    
        

    ret = IdentifyMatch (
            MaxFMRRequested,
            &processedBirInput,
            Population,
            TotalNumberOfTemplates,
            Binning,
            MaxNumberOfResults,
            NumberOfResults,
            Candidates,
            Timeout );
    FreeBIRHandle(processedBirHandle);
    if (ret != BioAPI_OK) {
        if (AuditData) {
            FreeBIRHandle(*AuditData);
            *AuditData = BioAPI_INVALID_BIR_HANDLE;
        }
        return ret;
    }

    
    
    return BioAPI_OK;
}



BioAPI_RETURN AttachSession::Import (
    const BioAPI_DATA *InputData,
    const BioAPI_BIR_BIOMETRIC_DATA_FORMAT *InputFormat,
    const BioAPI_BIR_BIOMETRIC_DATA_FORMAT *OutputFormat,
    BioAPI_BIR_PURPOSE Purpose,
    BioAPI_BIR_HANDLE *ConstructedBIR)
{
    return BIOAPI_BSP_ERROR | BioAPIERR_FUNCTION_NOT_SUPPORTED;
}
