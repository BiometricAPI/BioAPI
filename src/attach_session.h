#pragma once

#include "common.h"

class AttachSession : public Cancellable {
public:
    UnitArchive    *unitArchive;
    UnitMatching   *unitMatching;
    UnitProcessing *unitProcessing;
    UnitSensor     *unitSensor;
    HandleManager<BioAPI_BIR_HANDLE, BioAPI_BIR> bir_handles;
    
public:
    AttachSession (
        UnitArchive *unitArchive,
        UnitMatching *unitMatching,
        UnitProcessing *unitProcessing,
        UnitSensor *unitSensor);
    
    ~AttachSession ();
    
    //Invokes Cancel() on each child unit
    virtual void CancelTasksAsync();
    virtual void CancelTasksJoin();

    
    
    
    /**
     * \name BIR Management Functions
     * \{
     */
    ///Called by \ref BioSPI_FreeBIRHandle
    virtual BioAPI_RETURN FreeBIRHandle (
        BioAPI_BIR_HANDLE Handle);
    
    ///Called by \ref BioSPI_GetBIRFromHandle
    virtual BioAPI_RETURN GetBIRFromHandle (
        BioAPI_BIR_HANDLE Handle,
        BioAPI_BIR *BIR);

    ///Called by \ref BioSPI_GetHeaderFromHandle
    virtual BioAPI_RETURN GetHeaderFromHandle (
        BioAPI_BIR_HANDLE Handle,
        BioAPI_BIR_HEADER *Header);
    /** \} */ //BIR Management Functions
    
    
    
    
    
    /**
     * \name Callback Functions
     * \{
     */
    ///Called by \ref BioSPI_EnableEvents
    virtual BioAPI_RETURN EnableEvents (
        BioAPI_EVENT_MASK Events);
    
    ///Called by \ref BioSPI_SetGUICallbacks
    virtual BioAPI_RETURN SetGUICallbacks (
        BioAPI_GUI_STREAMING_CALLBACK GuiStreamingCallback,
        void *GuiStreamingCallbackCtx,
        BioAPI_GUI_STATE_CALLBACK GuiStateCallback,
        void *GuiStateCallbackCtx);
    /** \} */ //Callback Functions
    
    
    
    
    
    /**
     * \name General Unit Functions
     * \{
     */
    ///Internal function called by \ref ControlUnit, \ref SetPowerMode, \ref SetIndicatorStatus and \ref GetIndicatorStatus.
    Unit* GetUnit (
        BioAPI_UNIT_ID UnitID);
    ///Called by \ref BioSPI_ControlUnit
    virtual BioAPI_RETURN ControlUnit (
	BioAPI_UNIT_ID UnitID,
	uint32_t ControlCode,
	const BioAPI_DATA *InputData,
	BioAPI_DATA *OutputData);

    ///Called by \ref BioSPI_SetPowerMode
    virtual BioAPI_RETURN SetPowerMode (
	BioAPI_UNIT_ID UnitID,
	BioAPI_POWER_MODE PowerMode);

    ///Called by \ref BioSPI_SetIndicatorStatus
    virtual BioAPI_RETURN SetIndicatorStatus (
	BioAPI_UNIT_ID UnitID,
	BioAPI_INDICATOR_STATUS IndicatorStatus);

    ///Called by \ref BioSPI_GetIndicatorStatus
    virtual BioAPI_RETURN GetIndicatorStatus (
	BioAPI_UNIT_ID UnitID,
	BioAPI_INDICATOR_STATUS *IndicatorStatus);
    /** \} */ //General Unit Functions
    
    
    
    
    
    /**
     * \name Archive Unit Functions
     * \{
     */
    ///Called by \ref BioSPI_DbOpen
    virtual BioAPI_RETURN DbOpen (
	const BioAPI_UUID *DbUuid,
	BioAPI_DB_ACCESS_TYPE AccessRequest,
	BioAPI_DB_HANDLE *DbHandle,
	BioAPI_DB_MARKER_HANDLE *MarkerHandle);

    ///Called by \ref BioSPI_DbClose
    virtual BioAPI_RETURN DbClose (
	BioAPI_DB_HANDLE DbHandle);

    ///Called by \ref BioSPI_DbCreate
    virtual BioAPI_RETURN DbCreate (
	const BioAPI_UUID *DbUuid,
	uint32_t NumberOfRecords,
	BioAPI_DB_ACCESS_TYPE AccessRequest,
	BioAPI_DB_HANDLE *DbHandle);

    ///Called by \ref BioSPI_DbDelete
    virtual BioAPI_RETURN DbDelete (
	const BioAPI_UUID *DbUuid);

    ///Called by \ref BioSPI_DbSetMarker
    virtual BioAPI_RETURN DbSetMarker (
	BioAPI_DB_HANDLE DbHandle,
	const BioAPI_UUID *KeyValue,
	BioAPI_DB_MARKER_HANDLE MarkerHandle);

    ///Called by \ref BioSPI_DbFreeMarker
    virtual BioAPI_RETURN DbFreeMarker (
	BioAPI_DB_MARKER_HANDLE MarkerHandle);

    ///Called by \ref BioSPI_DbStoreBIR
    virtual BioAPI_RETURN DbStoreBIR (
	const BioAPI_INPUT_BIR *BIRToStore,
	BioAPI_DB_HANDLE DbHandle,
	BioAPI_UUID *BirUuid);

    ///Called by \ref BioSPI_DbGetBIR
    virtual BioAPI_RETURN DbGetBIR (
	BioAPI_DB_HANDLE DbHandle,
	const BioAPI_UUID *KeyValue,
	BioAPI_BIR_HANDLE *RetrievedBIR,
	BioAPI_DB_MARKER_HANDLE *MarkerHandle);

    ///Called by \ref BioSPI_DbGetNextBIR
    virtual BioAPI_RETURN DbGetNextBIR (
	BioAPI_DB_HANDLE DbHandle,
	BioAPI_DB_MARKER_HANDLE MarkerHandle,
	BioAPI_BIR_HANDLE *RetrievedBIR,
	BioAPI_UUID *BirUuid);

    ///Called by \ref BioSPI_DbDeleteBIR
    virtual BioAPI_RETURN DbDeleteBIR (
	BioAPI_DB_HANDLE DbHandle,
	const BioAPI_UUID *KeyValue);
    /** \} */ //Archive Unit Functions
    
    
    
    
    
    /**
     * \name Matching Unit Functions
     * \{
     */
    ///Called by \ref BioSPI_VerifyMatch
    virtual BioAPI_RETURN VerifyMatch (
	BioAPI_FMR MaxFMRRequested,
	const BioAPI_INPUT_BIR *ProcessedBIR,
	const BioAPI_INPUT_BIR *ReferenceTemplate,
	BioAPI_BIR_HANDLE *AdaptedBIR,
	BioAPI_BOOL *Result,
	BioAPI_FMR *FMRAchieved,
	BioAPI_DATA *Payload);

    ///Called by \ref BioSPI_IdentifyMatch
    virtual BioAPI_RETURN IdentifyMatch (
	BioAPI_FMR MaxFMRRequested,
	const BioAPI_INPUT_BIR *ProcessedBIR,
	const BioAPI_IDENTIFY_POPULATION *Population,
	uint32_t TotalNumberOfTemplates,
	BioAPI_BOOL Binning,
	uint32_t MaxNumberOfResults,
	uint32_t *NumberOfResults,
	BioAPI_CANDIDATE **Candidates,
	int32_t Timeout);
    
    ///Called by \ref BioSPI_PresetIdentifyPopulation
    virtual BioAPI_RETURN PresetIdentifyPopulation (
	const BioAPI_IDENTIFY_POPULATION *Population);
    /** \} */ //Matching Unit Functions
    
    
    
    
    
    /**
     * \name Processing Unit Functions
     * \{
     */
    ///Called by \ref BioSPI_CreateTemplate
    virtual BioAPI_RETURN CreateTemplate (
	const BioAPI_INPUT_BIR *CapturedBIR,
	const BioAPI_INPUT_BIR *ReferenceTemplate,
	const BioAPI_BIR_BIOMETRIC_DATA_FORMAT *OutputFormat,
	BioAPI_BIR_HANDLE *NewTemplate,
	const BioAPI_DATA *Payload,
	BioAPI_UUID *TemplateUUID);

    ///Called by \ref BioSPI_Process
    virtual BioAPI_RETURN Process (
	const BioAPI_INPUT_BIR *CapturedBIR,
	const BioAPI_BIR_BIOMETRIC_DATA_FORMAT *OutputFormat,
	BioAPI_BIR_HANDLE *ProcessedBIR);

    ///Called by \ref BioSPI_ProcessWithAuxBIR
    virtual BioAPI_RETURN ProcessWithAuxBIR (
	const BioAPI_INPUT_BIR *CapturedBIR,
	const BioAPI_INPUT_BIR *AuxiliaryData,
	const BioAPI_BIR_BIOMETRIC_DATA_FORMAT *OutputFormat,
	BioAPI_BIR_HANDLE *ProcessedBIR);
    /** \} */ //Processing Unit Functions

    
    
    
    
    /**
     * \name Sensor Unit Functions
     * \{
     */
    ///Called by \ref BioSPI_Capture
    virtual BioAPI_RETURN Capture (
	BioAPI_BIR_PURPOSE Purpose,
	BioAPI_BIR_SUBTYPE Subtype,
	const BioAPI_BIR_BIOMETRIC_DATA_FORMAT *OutputFormat,
	BioAPI_BIR_HANDLE *CapturedBIR,
	int32_t Timeout,
	BioAPI_BIR_HANDLE *AuditData);


    ///Called by \ref BioSPI_CalibrateSensor
    virtual BioAPI_RETURN CalibrateSensor (
	int32_t Timeout);
    /** \} */ //Sensor Unit Functions
    
    
    
    
    /**
     * \name Multiple-Units Functions
     * \{
     */
    ///Called by \ref BioSPI_Enroll    
    virtual BioAPI_RETURN Enroll (
	BioAPI_BIR_PURPOSE Purpose,
	BioAPI_BIR_SUBTYPE Subtype,
	const BioAPI_BIR_BIOMETRIC_DATA_FORMAT *OutputFormat,
	const BioAPI_INPUT_BIR *ReferenceTemplate,
	BioAPI_BIR_HANDLE *NewTemplate,
	const BioAPI_DATA *Payload,
	int32_t Timeout,
	BioAPI_BIR_HANDLE *AuditData,
	BioAPI_UUID *TemplateUUID);

    ///Called by \ref BioSPI_Verify
    virtual BioAPI_RETURN Verify (
	BioAPI_FMR MaxFMRRequested,
	const BioAPI_INPUT_BIR *ReferenceTemplate,
	BioAPI_BIR_SUBTYPE Subtype,
	BioAPI_BIR_HANDLE *AdaptedBIR,
	BioAPI_BOOL *Result,
	BioAPI_FMR *FMRAchieved,
	BioAPI_DATA *Payload,
	int32_t Timeout,
	BioAPI_BIR_HANDLE *AuditData);

    ///Called by \ref BioSPI_Identify
    virtual BioAPI_RETURN Identify (
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

    ///Called by \ref BioSPI_Import
    virtual BioAPI_RETURN Import (
	const BioAPI_DATA *InputData,
	const BioAPI_BIR_BIOMETRIC_DATA_FORMAT *InputFormat,
	const BioAPI_BIR_BIOMETRIC_DATA_FORMAT *OutputFormat,
	BioAPI_BIR_PURPOSE Purpose,
	BioAPI_BIR_HANDLE *ConstructedBIR);
    /** \} */ //Multiple-Units Functions
};