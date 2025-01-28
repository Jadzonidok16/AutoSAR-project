/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  Rte_CtApAFSController.h
 *        Config:  C:/nit-au-03/AUTOSAR_Exercises/AFS/MyECU.dpa
 *     SW-C Type:  CtApAFSController
 *  Generated at:  Sat Apr 13 16:30:41 2024
 *
 *     Generator:  MICROSAR RTE Generator Version 4.9.0
 *                 RTE Core Version 1.9.0
 *       License:  Unlimited license CBD0000000 for N/A
 *
 *   Description:  Application header file for SW-C <CtApAFSController> (Contract Phase)
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_CTAPAFSCONTROLLER_H
# define _RTE_CTAPAFSCONTROLLER_H

# ifdef RTE_APPLICATION_HEADER_FILE
#  error Multiple application header files included.
# endif
# define RTE_APPLICATION_HEADER_FILE
# ifndef RTE_PTR2ARRAYBASETYPE_PASSING
#  define RTE_PTR2ARRAYBASETYPE_PASSING
# endif

# ifdef __cplusplus
extern "C"
{
# endif /* __cplusplus */

/* include files */

# include "Rte_CtApAFSController_Type.h"
# include "Rte_DataHandleType.h"


/**********************************************************************************************************************
 * Component Data Structures and Port Data Structures
 *********************************************************************************************************************/

struct Rte_CDS_CtApAFSController
{
  /* PIM Handles section */
  P2VAR(IdtPassingLane, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_PimPassingLane; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  /* Vendor specific section */
};

# define RTE_START_SEC_CONST_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern CONSTP2CONST(struct Rte_CDS_CtApAFSController, RTE_CONST, RTE_CONST) Rte_Inst_CtApAFSController; /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define RTE_STOP_SEC_CONST_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

typedef P2CONST(struct Rte_CDS_CtApAFSController, TYPEDEF, RTE_CONST) Rte_Instance;


/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

# define Rte_InitValue_PpAmbientLight_DeAmbientLight (0U)
# define Rte_InitValue_PpLightPositionLeft_DeLightLength (0U)
# define Rte_InitValue_PpLightPositionLeft_DeLightPosition (0)
# define Rte_InitValue_PpLightPositionRight_DeLightLength (0U)
# define Rte_InitValue_PpLightPositionRight_DeLightPosition (0)
# define Rte_InitValue_PpSpeedometer_DeSpeedometer (0U)
# define Rte_InitValue_PpSteeringWheelPosition_DeSteeringWheelPosition (0U)


# define RTE_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApAFSController_PpAmbientLight_DeAmbientLight(P2VAR(IdtAmbientLight, AUTOMATIC, RTE_CTAPAFSCONTROLLER_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApAFSController_PpSpeedometer_DeSpeedometer(P2VAR(IdtSpeedometer, AUTOMATIC, RTE_CTAPAFSCONTROLLER_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApAFSController_PpSteeringWheelPosition_DeSteeringWheelPosition(P2VAR(IdtDioValueType, AUTOMATIC, RTE_CTAPAFSCONTROLLER_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApAFSController_PpLightPositionLeft_DeLightLength(uint8 data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApAFSController_PpLightPositionLeft_DeLightPosition(sint8 data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApAFSController_PpLightPositionRight_DeLightLength(uint8 data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApAFSController_PpLightPositionRight_DeLightPosition(sint8 data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(uint8, RTE_CODE) Rte_Mode_CtApAFSController_PpBatteryMode_BatteryMode(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_CtApAFSController_PiBatteryLevelHwAb_ReadChannel(P2VAR(IdtDioValueType, AUTOMATIC, RTE_CTAPAFSCONTROLLER_APPL_VAR) value); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_CtApAFSController_PpAFSSwitch_ReadChannel(P2VAR(uint8, AUTOMATIC, RTE_CTAPAFSCONTROLLER_APPL_VAR) value); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_CtApAFSController_PpComMUserRequestCtAFSController_RequestComMode(ComM_ModeType ComMode); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_CtApAFSController_PpHighBeam_ReadChannel(P2VAR(uint8, AUTOMATIC, RTE_CTAPAFSCONTROLLER_APPL_VAR) value); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_CtApAFSController_PpNvMPassingLaneCtApAFSControllerF_ReadBlock(dtRef_VOID DstPtr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_CtApAFSController_PpNvMPassingLaneCtApAFSControllerF_WriteBlock(dtRef_const_VOID SrcPtr); /* PRQA S 0850 */ /* MD_MSR_19.8 */

FUNC(void, RTE_CODE) Rte_Enter_CtApAFSController_ExArBatteryValue(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, RTE_CODE) Rte_Exit_CtApAFSController_ExArBatteryValue(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

FUNC(void, RTE_CODE) Rte_Enter_CtApAFSController_ExArPassLaneValue(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, RTE_CODE) Rte_Exit_CtApAFSController_ExArPassLaneValue(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define RTE_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */



/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
# define Rte_Read_PpAmbientLight_DeAmbientLight Rte_Read_CtApAFSController_PpAmbientLight_DeAmbientLight
# define Rte_Read_PpSpeedometer_DeSpeedometer Rte_Read_CtApAFSController_PpSpeedometer_DeSpeedometer
# define Rte_Read_PpSteeringWheelPosition_DeSteeringWheelPosition Rte_Read_CtApAFSController_PpSteeringWheelPosition_DeSteeringWheelPosition


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
# define Rte_Write_PpLightPositionLeft_DeLightLength Rte_Write_CtApAFSController_PpLightPositionLeft_DeLightLength
# define Rte_Write_PpLightPositionLeft_DeLightPosition Rte_Write_CtApAFSController_PpLightPositionLeft_DeLightPosition
# define Rte_Write_PpLightPositionRight_DeLightLength Rte_Write_CtApAFSController_PpLightPositionRight_DeLightLength
# define Rte_Write_PpLightPositionRight_DeLightPosition Rte_Write_CtApAFSController_PpLightPositionRight_DeLightPosition


/**********************************************************************************************************************
 * Rte_Mode_<p>_<m>
 *********************************************************************************************************************/
# define Rte_Mode_PpBatteryMode_BatteryMode Rte_Mode_CtApAFSController_PpBatteryMode_BatteryMode


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (C/S invocation)
 *********************************************************************************************************************/
# define Rte_Call_PiBatteryLevelHwAb_ReadChannel Rte_Call_CtApAFSController_PiBatteryLevelHwAb_ReadChannel
# define Rte_Call_PpAFSSwitch_ReadChannel Rte_Call_CtApAFSController_PpAFSSwitch_ReadChannel
# define Rte_Call_PpComMUserRequestCtAFSController_RequestComMode Rte_Call_CtApAFSController_PpComMUserRequestCtAFSController_RequestComMode
# define Rte_Call_PpHighBeam_ReadChannel Rte_Call_CtApAFSController_PpHighBeam_ReadChannel
# define Rte_Call_PpNvMPassingLaneCtApAFSControllerF_ReadBlock Rte_Call_CtApAFSController_PpNvMPassingLaneCtApAFSControllerF_ReadBlock
# define Rte_Call_PpNvMPassingLaneCtApAFSControllerF_WriteBlock Rte_Call_CtApAFSController_PpNvMPassingLaneCtApAFSControllerF_WriteBlock


/**********************************************************************************************************************
 * Exclusive Areas
 *********************************************************************************************************************/

# define Rte_Enter_ExArBatteryValue Rte_Enter_CtApAFSController_ExArBatteryValue
# define Rte_Exit_ExArBatteryValue Rte_Exit_CtApAFSController_ExArBatteryValue

# define Rte_Enter_ExArPassLaneValue Rte_Enter_CtApAFSController_ExArPassLaneValue
# define Rte_Exit_ExArPassLaneValue Rte_Exit_CtApAFSController_ExArPassLaneValue


/**********************************************************************************************************************
 * Per-Instance Memory User Types
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Rte_Pim (Per-Instance Memory)
 *********************************************************************************************************************/

# define Rte_Pim_PimPassingLane() (Rte_Inst_CtApAFSController->Pim_PimPassingLane) /* PRQA S 3453 */ /* MD_MSR_19.7 */




/**********************************************************************************************************************
 *
 * APIs which are accessible from all runnable entities of the SW-C
 *
 **********************************************************************************************************************
 * Per-Instance Memory:
 * ====================
 *   IdtPassingLane *Rte_Pim_PimPassingLane(void)
 *
 *********************************************************************************************************************/


# define CtApAFSController_START_SEC_CODE
# include "CtApAFSController_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 *
 * Runnable Entity Name: CBReadData_BatteryValue_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <CBReadData_BatteryValue>
 *
 **********************************************************************************************************************
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_PiBatteryLevelHwAb_ReadChannel(IdtDioValueType *value)
 *     Synchronous Server Invocation. Timeout: None
 *
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_ExArBatteryValue(void)
 *   void Rte_Exit_ExArBatteryValue(void)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType CBReadData_BatteryValue_ReadData(uint8 *Data)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_CSDataServices_BatteryValue_BatteryValue_E_NOT_OK
 *
 *********************************************************************************************************************/

# define RTE_RUNNABLE_CBReadData_BatteryValue_ReadData CBReadData_BatteryValue_ReadData
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, CtApAFSController_CODE) CBReadData_BatteryValue_ReadData(P2VAR(uint8, AUTOMATIC, RTE_CTAPAFSCONTROLLER_APPL_VAR) Data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, CtApAFSController_CODE) CBReadData_BatteryValue_ReadData(P2VAR(DataArray_Type_4, AUTOMATIC, RTE_CTAPAFSCONTROLLER_APPL_VAR) Data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_Diag_RDI_BatteryValue_BatteryValue_ConditionCheckRead
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ConditionCheckRead> of PortPrototype <DataServices_Diag_RDI_BatteryValue_BatteryValue>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_Diag_RDI_BatteryValue_BatteryValue_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Diag_RDI_BatteryValue_BatteryValue_E_NOT_OK
 *   RTE_E_DataServices_Diag_RDI_BatteryValue_BatteryValue_E_PENDING
 *
 *********************************************************************************************************************/

# define RTE_RUNNABLE_DataServices_Diag_RDI_BatteryValue_BatteryValue_ConditionCheckRead DataServices_Diag_RDI_BatteryValue_BatteryValue_ConditionCheckRead
FUNC(Std_ReturnType, CtApAFSController_CODE) DataServices_Diag_RDI_BatteryValue_BatteryValue_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CTAPAFSCONTROLLER_APPL_VAR) ErrorCode); /* PRQA S 0850 */ /* MD_MSR_19.8 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_Diag_RDI_BatteryValue_BatteryValue_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_Diag_RDI_BatteryValue_BatteryValue>
 *
 **********************************************************************************************************************
 *
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_ExArBatteryValue(void)
 *   void Rte_Exit_ExArBatteryValue(void)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_Diag_RDI_BatteryValue_BatteryValue_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Diag_RDI_BatteryValue_BatteryValue_E_NOT_OK
 *   RTE_E_DataServices_Diag_RDI_BatteryValue_BatteryValue_E_PENDING
 *
 *********************************************************************************************************************/

# define RTE_RUNNABLE_DataServices_Diag_RDI_BatteryValue_BatteryValue_ReadData DataServices_Diag_RDI_BatteryValue_BatteryValue_ReadData
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, CtApAFSController_CODE) DataServices_Diag_RDI_BatteryValue_BatteryValue_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_CTAPAFSCONTROLLER_APPL_VAR) Data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, CtApAFSController_CODE) DataServices_Diag_RDI_BatteryValue_BatteryValue_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data4ByteType, AUTOMATIC, RTE_CTAPAFSCONTROLLER_APPL_VAR) Data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_Diag_RWDI_PassingLane_PassingLane_PassingLane_ConditionCheckRead
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ConditionCheckRead> of PortPrototype <DataServices_Diag_RWDI_PassingLane_PassingLane_PassingLane>
 *
 **********************************************************************************************************************
 *
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_ExArPassLaneValue(void)
 *   void Rte_Exit_ExArPassLaneValue(void)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_Diag_RWDI_PassingLane_PassingLane_PassingLane_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Diag_RWDI_PassingLane_PassingLane_PassingLane_E_NOT_OK
 *   RTE_E_DataServices_Diag_RWDI_PassingLane_PassingLane_PassingLane_E_PENDING
 *
 *********************************************************************************************************************/

# define RTE_RUNNABLE_DataServices_Diag_RWDI_PassingLane_PassingLane_PassingLane_ConditionCheckRead DataServices_Diag_RWDI_PassingLane_PassingLane_PassingLane_ConditionCheckRead
FUNC(Std_ReturnType, CtApAFSController_CODE) DataServices_Diag_RWDI_PassingLane_PassingLane_PassingLane_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CTAPAFSCONTROLLER_APPL_VAR) ErrorCode); /* PRQA S 0850 */ /* MD_MSR_19.8 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_Diag_RWDI_PassingLane_PassingLane_PassingLane_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_Diag_RWDI_PassingLane_PassingLane_PassingLane>
 *
 **********************************************************************************************************************
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_PpNvMPassingLaneCtApAFSControllerF_ReadBlock(dtRef_VOID DstPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_E_NOT_OK
 *
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_ExArPassLaneValue(void)
 *   void Rte_Exit_ExArPassLaneValue(void)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_Diag_RWDI_PassingLane_PassingLane_PassingLane_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Diag_RWDI_PassingLane_PassingLane_PassingLane_E_NOT_OK
 *   RTE_E_DataServices_Diag_RWDI_PassingLane_PassingLane_PassingLane_E_PENDING
 *
 *********************************************************************************************************************/

# define RTE_RUNNABLE_DataServices_Diag_RWDI_PassingLane_PassingLane_PassingLane_ReadData DataServices_Diag_RWDI_PassingLane_PassingLane_PassingLane_ReadData
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, CtApAFSController_CODE) DataServices_Diag_RWDI_PassingLane_PassingLane_PassingLane_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_CTAPAFSCONTROLLER_APPL_VAR) Data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, CtApAFSController_CODE) DataServices_Diag_RWDI_PassingLane_PassingLane_PassingLane_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data1ByteType, AUTOMATIC, RTE_CTAPAFSCONTROLLER_APPL_VAR) Data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_Diag_RWDI_PassingLane_PassingLane_PassingLane_WriteData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <WriteData> of PortPrototype <DataServices_Diag_RWDI_PassingLane_PassingLane_PassingLane>
 *
 **********************************************************************************************************************
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_PpNvMPassingLaneCtApAFSControllerF_WriteBlock(dtRef_const_VOID SrcPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_E_NOT_OK
 *
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_ExArPassLaneValue(void)
 *   void Rte_Exit_ExArPassLaneValue(void)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_Diag_RWDI_PassingLane_PassingLane_PassingLane_WriteData(const uint8 *Data, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Diag_RWDI_PassingLane_PassingLane_PassingLane_E_NOT_OK
 *   RTE_E_DataServices_Diag_RWDI_PassingLane_PassingLane_PassingLane_E_PENDING
 *
 *********************************************************************************************************************/

# define RTE_RUNNABLE_DataServices_Diag_RWDI_PassingLane_PassingLane_PassingLane_WriteData DataServices_Diag_RWDI_PassingLane_PassingLane_PassingLane_WriteData
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, CtApAFSController_CODE) DataServices_Diag_RWDI_PassingLane_PassingLane_PassingLane_WriteData(P2CONST(uint8, AUTOMATIC, RTE_CTAPAFSCONTROLLER_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CTAPAFSCONTROLLER_APPL_VAR) ErrorCode); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, CtApAFSController_CODE) DataServices_Diag_RWDI_PassingLane_PassingLane_PassingLane_WriteData(P2CONST(Dcm_Data1ByteType, AUTOMATIC, RTE_CTAPAFSCONTROLLER_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CTAPAFSCONTROLLER_APPL_VAR) ErrorCode); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RCtApAFSControllerLogic
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on DataReceivedEvent for DataElementPrototype <DeSteeringWheelPosition> of PortPrototype <PpSteeringWheelPosition>
 *     and not in Mode(s) <BATTERY_LOW>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_PpAmbientLight_DeAmbientLight(IdtAmbientLight *data)
 *   Std_ReturnType Rte_Read_PpSpeedometer_DeSpeedometer(IdtSpeedometer *data)
 *   Std_ReturnType Rte_Read_PpSteeringWheelPosition_DeSteeringWheelPosition(IdtDioValueType *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_PpLightPositionLeft_DeLightLength(uint8 data)
 *   Std_ReturnType Rte_Write_PpLightPositionLeft_DeLightPosition(sint8 data)
 *   Std_ReturnType Rte_Write_PpLightPositionRight_DeLightLength(uint8 data)
 *   Std_ReturnType Rte_Write_PpLightPositionRight_DeLightPosition(sint8 data)
 *
 * Mode Interfaces:
 * ================
 *   uint8 Rte_Mode_PpBatteryMode_BatteryMode(void)
 *   Modes of Rte_ModeType_BatteryMode:
 *   - RTE_MODE_BatteryMode_BATTERY_HIGH
 *   - RTE_MODE_BatteryMode_BATTERY_LOW
 *   - RTE_MODE_BatteryMode_BATTERY_MEDIUM
 *   - RTE_TRANSITION_BatteryMode
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_PpAFSSwitch_ReadChannel(uint8 *value)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_PpHighBeam_ReadChannel(uint8 *value)
 *     Synchronous Server Invocation. Timeout: None
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_PpComMUserRequestCtAFSController_RequestComMode(ComM_ModeType ComMode)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_ComM_UserRequest_E_MODE_LIMITATION, RTE_E_ComM_UserRequest_E_NOT_OK
 *   Std_ReturnType Rte_Call_PpNvMPassingLaneCtApAFSControllerF_ReadBlock(dtRef_VOID DstPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_E_NOT_OK
 *
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_ExArBatteryValue(void)
 *   void Rte_Exit_ExArBatteryValue(void)
 *   void Rte_Enter_ExArPassLaneValue(void)
 *   void Rte_Exit_ExArPassLaneValue(void)
 *
 *********************************************************************************************************************/

# define RTE_RUNNABLE_RCtApAFSControllerLogic RCtApAFSControllerLogic
FUNC(void, CtApAFSController_CODE) RCtApAFSControllerLogic(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RCtApAFSController_Init
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 **********************************************************************************************************************
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_PpNvMPassingLaneCtApAFSControllerF_ReadBlock(dtRef_VOID DstPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_E_NOT_OK
 *
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_ExArBatteryValue(void)
 *   void Rte_Exit_ExArBatteryValue(void)
 *   void Rte_Enter_ExArPassLaneValue(void)
 *   void Rte_Exit_ExArPassLaneValue(void)
 *
 *********************************************************************************************************************/

# define RTE_RUNNABLE_RCtApAFSController_Init RCtApAFSController_Init
FUNC(void, CtApAFSController_CODE) RCtApAFSController_Init(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RCtApAFSController_ModeChange_HighBeam
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on entering of Mode <BATTERY_LOW> of ModeDeclarationGroupPrototype <BatteryMode> of PortPrototype <PpBatteryMode>
 *
 **********************************************************************************************************************
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_PpLightPositionLeft_DeLightLength(uint8 data)
 *   Std_ReturnType Rte_Write_PpLightPositionLeft_DeLightPosition(sint8 data)
 *   Std_ReturnType Rte_Write_PpLightPositionRight_DeLightLength(uint8 data)
 *   Std_ReturnType Rte_Write_PpLightPositionRight_DeLightPosition(sint8 data)
 *
 *********************************************************************************************************************/

# define RTE_RUNNABLE_RCtApAFSController_ModeChange_HighBeam RCtApAFSController_ModeChange_HighBeam
FUNC(void, CtApAFSController_CODE) RCtApAFSController_ModeChange_HighBeam(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define CtApAFSController_STOP_SEC_CODE
# include "CtApAFSController_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

# define RTE_E_CSDataServices_BatteryValue_BatteryValue_E_NOT_OK (1U)

# define RTE_E_ComM_UserRequest_E_MODE_LIMITATION (2U)

# define RTE_E_ComM_UserRequest_E_NOT_OK (1U)

# define RTE_E_DataServices_Diag_RDI_BatteryValue_BatteryValue_E_NOT_OK (1U)

# define RTE_E_DataServices_Diag_RDI_BatteryValue_BatteryValue_E_PENDING (10U)

# define RTE_E_DataServices_Diag_RWDI_PassingLane_PassingLane_PassingLane_E_NOT_OK (1U)

# define RTE_E_DataServices_Diag_RWDI_PassingLane_PassingLane_PassingLane_E_PENDING (10U)

# define RTE_E_NvMService_AC3_SRBS_E_NOT_OK (1U)

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_CTAPAFSCONTROLLER_H */
