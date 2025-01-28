/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  CtApAFSController.c
 *        Config:  C:/nit-au-03/AUTOSAR_Exercises/AFS/MyECU.dpa
 *     SW-C Type:  CtApAFSController
 *  Generated at:  Sat Apr 13 16:30:41 2024
 *
 *     Generator:  MICROSAR RTE Generator Version 4.9.0
 *                 RTE Core Version 1.9.0
 *       License:  Unlimited license CBD0000000 for N/A
 *
 *   Description:  C-Code implementation template for SW-C <CtApAFSController>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/* PRQA S 0777, 0779 EOF */ /* MD_Rte_0777, MD_Rte_0779 */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of version logging area >>                  DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *
 * AUTOSAR Modelling Object Descriptions
 *
 **********************************************************************************************************************
 *
 * Data Types:
 * ===========
 * ComM_ModeType
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * Dcm_NegativeResponseCodeType
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * Dcm_OpStatusType
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * IdtAmbientLight
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * IdtDioValueType
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * IdtPassingLane
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * IdtSpeedometer
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 *********************************************************************************************************************/

#include "Rte_CtApAFSController.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
#include <math.h>
#include <memory.h>		// zbog pristupa memoriji

#define OUTTER_LIGHT_FACTOR (double)(2.0 / 3.0)

#define CITYMODE_LENGTH_LEFT 50
#define CITYMODE_LENGTH_RIGHT 50

#define COUNTRYMODE_LENGTH_LEFT 70
#define COUNTRYMODE_LENGTH_RIGHT 120

#define MOTORWAYMODE_LENGTH_LEFT 140
#define MOTORWAYMODE_LENGTH_RIGHT 200

#define HIGHBEAM_LENGTH_LEFT 255
#define HIGHBEAM_LENGTH_RIGHT 255

#define AMBIENT_LIGHT_TRESHOLD 5

#define RIGHT_LANE 0
#define LEFT_LANE 1
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of include and declaration area >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *
 * Used AUTOSAR Data Types
 *
 **********************************************************************************************************************
 *
 * Primitive Types:
 * ================
 * IdtAmbientLight: Integer in interval [0...255]
 * IdtDioValueType: Integer in interval [0...255]
 * IdtPassingLane: Integer in interval [0...255]
 * IdtSpeedometer: Integer in interval [0...255]
 * dtRef_VOID: DataReference
 * dtRef_const_VOID: DataReference
 * sint8: Integer in interval [-128...127] (standard type)
 * uint8: Integer in interval [0...255] (standard type)
 *
 * Enumeration Types:
 * ==================
 * ComM_ModeType: Enumeration of integer in interval [0...255] with enumerators
 *   COMM_NO_COMMUNICATION (0U)
 *   COMM_SILENT_COMMUNICATION (1U)
 *   COMM_FULL_COMMUNICATION (2U)
 * Dcm_NegativeResponseCodeType: Enumeration of integer in interval [0...255] with enumerators
 *   DCM_E_POSITIVERESPONSE (0U)
 *   DCM_E_GENERALREJECT (16U)
 *   DCM_E_SERVICENOTSUPPORTED (17U)
 *   DCM_E_SUBFUNCTIONNOTSUPPORTED (18U)
 *   DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT (19U)
 *   DCM_E_RESPONSETOOLONG (20U)
 *   DCM_E_BUSYREPEATREQUEST (33U)
 *   DCM_E_CONDITIONSNOTCORRECT (34U)
 *   DCM_E_REQUESTSEQUENCEERROR (36U)
 *   DCM_E_NORESPONSEFROMSUBNETCOMPONENT (37U)
 *   DCM_E_FAILUREPREVENTSEXECUTIONOFREQUESTEDACTION (38U)
 *   DCM_E_REQUESTOUTOFRANGE (49U)
 *   DCM_E_SECURITYACCESSDENIED (51U)
 *   DCM_E_INVALIDKEY (53U)
 *   DCM_E_EXCEEDNUMBEROFATTEMPTS (54U)
 *   DCM_E_REQUIREDTIMEDELAYNOTEXPIRED (55U)
 *   DCM_E_UPLOADDOWNLOADNOTACCEPTED (112U)
 *   DCM_E_TRANSFERDATASUSPENDED (113U)
 *   DCM_E_GENERALPROGRAMMINGFAILURE (114U)
 *   DCM_E_WRONGBLOCKSEQUENCECOUNTER (115U)
 *   DCM_E_REQUESTCORRECTLYRECEIVEDRESPONSEPENDING (120U)
 *   DCM_E_SUBFUNCTIONNOTSUPPORTEDINACTIVESESSION (126U)
 *   DCM_E_SERVICENOTSUPPORTEDINACTIVESESSION (127U)
 *   DCM_E_RPMTOOHIGH (129U)
 *   DCM_E_RPMTOOLOW (130U)
 *   DCM_E_ENGINEISRUNNING (131U)
 *   DCM_E_ENGINEISNOTRUNNING (132U)
 *   DCM_E_ENGINERUNTIMETOOLOW (133U)
 *   DCM_E_TEMPERATURETOOHIGH (134U)
 *   DCM_E_TEMPERATURETOOLOW (135U)
 *   DCM_E_VEHICLESPEEDTOOHIGH (136U)
 *   DCM_E_VEHICLESPEEDTOOLOW (137U)
 *   DCM_E_THROTTLE_PEDALTOOHIGH (138U)
 *   DCM_E_THROTTLE_PEDALTOOLOW (139U)
 *   DCM_E_TRANSMISSIONRANGENOTINNEUTRAL (140U)
 *   DCM_E_TRANSMISSIONRANGENOTINGEAR (141U)
 *   DCM_E_BRAKESWITCH_NOTCLOSED (143U)
 *   DCM_E_SHIFTERLEVERNOTINPARK (144U)
 *   DCM_E_TORQUECONVERTERCLUTCHLOCKED (145U)
 *   DCM_E_VOLTAGETOOHIGH (146U)
 *   DCM_E_VOLTAGETOOLOW (147U)
 *   DCM_E_VMSCNC_0 (240U)
 *   DCM_E_VMSCNC_1 (241U)
 *   DCM_E_VMSCNC_2 (242U)
 *   DCM_E_VMSCNC_3 (243U)
 *   DCM_E_VMSCNC_4 (244U)
 *   DCM_E_VMSCNC_5 (245U)
 *   DCM_E_VMSCNC_6 (246U)
 *   DCM_E_VMSCNC_7 (247U)
 *   DCM_E_VMSCNC_8 (248U)
 *   DCM_E_VMSCNC_9 (249U)
 *   DCM_E_VMSCNC_A (250U)
 *   DCM_E_VMSCNC_B (251U)
 *   DCM_E_VMSCNC_C (252U)
 *   DCM_E_VMSCNC_D (253U)
 *   DCM_E_VMSCNC_E (254U)
 * Dcm_OpStatusType: Enumeration of integer in interval [0...255] with enumerators
 *   DCM_INITIAL (0U)
 *   DCM_PENDING (1U)
 *   DCM_CANCEL (2U)
 *   DCM_FORCE_RCRRP_OK (3U)
 *   DCM_FORCE_RCRRP_NOT_OK (64U)
 *
 * Array Types:
 * ============
 * DataArray_Type_4: Array with 4 element(s) of type uint8
 * Dcm_Data1ByteType: Array with 1 element(s) of type uint8
 * Dcm_Data4ByteType: Array with 4 element(s) of type uint8
 *
 *********************************************************************************************************************/


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


#define CtApAFSController_START_SEC_CODE
#include "CtApAFSController_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

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
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: CBReadData_BatteryValue_ReadData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, CtApAFSController_CODE) CBReadData_BatteryValue_ReadData(P2VAR(uint8, AUTOMATIC, RTE_CTAPAFSCONTROLLER_APPL_VAR) Data) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CBReadData_BatteryValue_ReadData (returns application error)
 *********************************************************************************************************************/
	IdtBatteryLevel batteryValue;
	
	Rte_Call_PiBatteryLevelHwAb_ReadChannel(&batteryValue);
	memcpy(Data, &batteryValue, sizeof(batteryValue));
	

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

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
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Diag_RDI_BatteryValue_BatteryValue_ConditionCheckRead_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, CtApAFSController_CODE) DataServices_Diag_RDI_BatteryValue_BatteryValue_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CTAPAFSCONTROLLER_APPL_VAR) ErrorCode) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Diag_RDI_BatteryValue_BatteryValue_ConditionCheckRead (returns application error)
 *********************************************************************************************************************/
  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

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
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Diag_RDI_BatteryValue_BatteryValue_ReadData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, CtApAFSController_CODE) DataServices_Diag_RDI_BatteryValue_BatteryValue_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_CTAPAFSCONTROLLER_APPL_VAR) Data) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Diag_RDI_BatteryValue_BatteryValue_ReadData (returns application error)
 *********************************************************************************************************************/
  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

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
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Diag_RWDI_PassingLane_PassingLane_PassingLane_ConditionCheckRead_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, CtApAFSController_CODE) DataServices_Diag_RWDI_PassingLane_PassingLane_PassingLane_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CTAPAFSCONTROLLER_APPL_VAR) ErrorCode) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Diag_RWDI_PassingLane_PassingLane_PassingLane_ConditionCheckRead (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

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
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Diag_RWDI_PassingLane_PassingLane_PassingLane_ReadData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, CtApAFSController_CODE) DataServices_Diag_RWDI_PassingLane_PassingLane_PassingLane_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_CTAPAFSCONTROLLER_APPL_VAR) Data) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Diag_RWDI_PassingLane_PassingLane_PassingLane_ReadData (returns application error)
 *********************************************************************************************************************/
	IdtPassingLane lane;

	Rte_Enter_ExArPassLaneValue();
	lane = *Rte_Pim_PimPassingLane();
	memcpy(Data, &lane, sizeof(lane));
	Rte_Exit_ExArPassLaneValue();

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

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
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Diag_RWDI_PassingLane_PassingLane_PassingLane_WriteData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, CtApAFSController_CODE) DataServices_Diag_RWDI_PassingLane_PassingLane_PassingLane_WriteData(P2CONST(uint8, AUTOMATIC, RTE_CTAPAFSCONTROLLER_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CTAPAFSCONTROLLER_APPL_VAR) ErrorCode) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Diag_RWDI_PassingLane_PassingLane_PassingLane_WriteData (returns application error)
 *********************************************************************************************************************/

	IdtPassingLane lane;
	Std_ReturnType ret;

	lane = *(uint8*)Data;
	Rte_Enter_ExArPassLaneValue();
	*Rte_Pim_PimPassingLane() = lane;
	Rte_Exit_ExArPassLaneValue();

	ret = Rte_Call_PpNvMPassingLaneCtApAFSControllerF_WriteBlock(NULL_PTR);

	if (ret != E_OK)
	{
		CANoeAPI_WriteString("Neuspesan upis!");
	}

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

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
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RCtApAFSControllerLogic_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, CtApAFSController_CODE) RCtApAFSControllerLogic(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: RCtApAFSControllerLogic
 *********************************************************************************************************************/
	uint8 highBeamModeSwitchState;
	uint8 afsSwitchState;
	uint8 leftLightLength;
	uint8 rightLightLength;
	sint8 steeringWheelPosition;
	sint8 leftLightTiltAngle;
	sint8 rightLightTiltAngle;

	IdtSpeedometer speed;
	IdtAmbientLight ambientlight;
	

	/* Read data from CAN bus */
	/* TODO */
	
	Rte_Read_PpSpeedometer_DeSpeedometer(&speed);
	Rte_Read_PpAmbientLight_DeAmbientLight(&ambientlight);
	/* Read data from Dio channels */
	(void)Rte_Call_PpAFSSwitch_ReadChannel(&afsSwitchState);
	(void)Rte_Call_PpHighBeam_ReadChannel(&highBeamModeSwitchState);

	if (FALSE == highBeamModeSwitchState)
	{
		/* set light mode based on speed */
		/* curently speed is ignored */
		/* TODO */
		leftLightLength = CITYMODE_LENGTH_LEFT;
		rightLightLength = CITYMODE_LENGTH_RIGHT;

		if (speed <= 50 && ambientlight <= AMBIENT_LIGHT_TRESHOLD)
		{
			leftLightLength = CITYMODE_LENGTH_LEFT;
			rightLightLength = CITYMODE_LENGTH_RIGHT;
		}
		else if ((speed > 50 && speed <= 120) && ambientlight <= AMBIENT_LIGHT_TRESHOLD)
		{
			/* COUNTRYMODE */
			/* TODO */
			leftLightLength = COUNTRYMODE_LENGTH_LEFT;
			rightLightLength = COUNTRYMODE_LENGTH_RIGHT;
		}
		else if ((speed > 120 && speed <= 250) && ambientlight <= AMBIENT_LIGHT_TRESHOLD)
		{
			/* MOTORWAYMODE */
			/* TODO */
			leftLightLength = MOTORWAYMODE_LENGTH_LEFT;
			rightLightLength = MOTORWAYMODE_LENGTH_RIGHT;
		}
		else if ((speed > 120 && speed <= 250) && ambientlight > AMBIENT_LIGHT_TRESHOLD)
		{
			/* When brigtness level above treshold set light length as in CITYMODE */
			/* set ambient light */
			/* TODO */
			leftLightLength = CITYMODE_LENGTH_LEFT;
			rightLightLength = CITYMODE_LENGTH_RIGHT;
		}

	}
	else
	{
		leftLightLength = HIGHBEAM_LENGTH_LEFT;
		rightLightLength = HIGHBEAM_LENGTH_RIGHT;
	}
	
	Rte_Read_PpSteeringWheelPosition_DeSteeringWheelPosition(&steeringWheelPosition);

	if (afsSwitchState == 0)
	{
		leftLightTiltAngle = 0;
		rightLightTiltAngle = 0;
		
		if (highBeamModeSwitchState)
		{
			leftLightLength = HIGHBEAM_LENGTH_LEFT;
			rightLightLength = HIGHBEAM_LENGTH_RIGHT;
		}
		else
		{
			leftLightLength = CITYMODE_LENGTH_LEFT;
			rightLightLength = CITYMODE_LENGTH_RIGHT;
		}
		

	}
	else
	{
		if (steeringWheelPosition <= 0)
		{
			leftLightTiltAngle = (uint8)round((double)steeringWheelPosition);
			rightLightTiltAngle = (uint8)round((double)(steeringWheelPosition) * OUTTER_LIGHT_FACTOR);
		}
		else
		{
			leftLightTiltAngle = (uint8)round((double)(steeringWheelPosition) * OUTTER_LIGHT_FACTOR);
			rightLightTiltAngle = (uint8)round((double)steeringWheelPosition);
		}
	}

	// PassingLane adjusments
	IdtPassingLane lane;

	Rte_Enter_ExArPassLaneValue();
	lane = *Rte_Pim_PimPassingLane();
	Rte_Exit_ExArPassLaneValue();

	uint8 tempLength;
	sint8 tempAngle;

	//RIGHT_LANE - default
	if (lane == LEFT_LANE) {
		tempLength = leftLightLength;
		leftLightLength = rightLightLength;
		rightLightLength = tempLength;

		tempAngle = leftLightTiltAngle;
		leftLightTiltAngle = rightLightTiltAngle;
		rightLightTiltAngle = tempAngle;
	}

	/* Provide data about light length to Actuator SWC */
	Rte_Write_PpLightPositionLeft_DeLightLength(leftLightLength);
	Rte_Write_PpLightPositionRight_DeLightLength(rightLightLength);

	/* Provide data about light angle to Actuator SWC */
	Rte_Write_PpLightPositionLeft_DeLightPosition(leftLightTiltAngle);
	Rte_Write_PpLightPositionRight_DeLightPosition(rightLightTiltAngle);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

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
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RCtApAFSController_Init_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, CtApAFSController_CODE) RCtApAFSController_Init(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: RCtApAFSController_Init
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

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
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RCtApAFSController_ModeChange_HighBeam_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, CtApAFSController_CODE) RCtApAFSController_ModeChange_HighBeam(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: RCtApAFSController_ModeChange_HighBeam
 *********************************************************************************************************************/
	//TRIGGER BATTERY_LOW

	uint8 highBeam;
	
	(void)Rte_Call_PpHighBeam_ReadChannel(&highBeam);

	if (highBeam){
		Rte_Write_CtApAFSController_PpLightPositionLeft_DeLightLength(HIGHBEAM_LENGTH_LEFT);
		Rte_Write_CtApAFSController_PpLightPositionRight_DeLightLength(HIGHBEAM_LENGTH_RIGHT);
	}
	else{
		Rte_Write_CtApAFSController_PpLightPositionLeft_DeLightLength(CITYMODE_LENGTH_LEFT);
		Rte_Write_CtApAFSController_PpLightPositionRight_DeLightLength(CITYMODE_LENGTH_RIGHT);
	}
	Rte_Write_PpLightPositionLeft_DeLightPosition(0);
	Rte_Write_PpLightPositionRight_DeLightPosition(0);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define CtApAFSController_STOP_SEC_CODE
#include "CtApAFSController_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of function definition area >>              DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of removed code area >>                   DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/



#if 0
/***  Start of saved code (symbol: runnable implementation:RCtApAFSControllerComM_ModeChange_FULL_COMM_Exit)  */


/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:RCtApAFSControllerComM_ModeChange_FULL_COMM_Exit_doc)  */


/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: runnable implementation:RCtApAFSControllerComM_ModeChange_FULL_COMM_Entry)  */
	uint8 highBeam;


	(void)Rte_Call_PpHighBeam_ReadChannel(&highBeam);
	if (highBeam) {
		Rte_Write_PpLightPositionLeft_DeLightLength(HIGHBEAM_LENGTH_LEFT);
		Rte_Write_PpLightPositionRight_DeLightLength(HIGHBEAM_LENGTH_RIGHT);
	}
	else {
		Rte_Write_PpLightPositionLeft_DeLightLength(CITYMODE_LENGTH_LEFT);
		Rte_Write_PpLightPositionRight_DeLightLength(CITYMODE_LENGTH_RIGHT);
	}

	//Rte_Write_PpLightPositionLeft_DeLightLength(CITYMODE_LENGTH_LEFT);
	Rte_Write_PpLightPositionLeft_DeLightPosition(0);
	//Rte_Write_PpLightPositionRight_DeLightLength(CITYMODE_LENGTH_RIGHT);
	Rte_Write_PpLightPositionRight_DeLightPosition(0);

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:RCtApAFSControllerComM_ModeChange_FULL_COMM_Entry_doc)  */


/***  End of saved code  ************************************************************************************/
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of removed code area >>                     DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 MISRA 2004 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_0777:  MISRA rule: 5.1
     Reason:     The defined RTE naming convention may result in identifiers with more than 31 characters. The compliance to this rule is under user's control.
                 This is covered in the MISRA C compliance section of the Rte specification.
     Risk:       Ambiguous identifiers can lead to compiler errors / warnings.
     Prevention: Verified during compile time. If the compiler reports an error or warning, the user has to rename the objects to be unique within the significant characters.

   MD_Rte_0779:  MISRA rule: 5.1
     Reason:     The defined RTE naming convention may result in identifiers with more than 31 characters. The compliance to this rule is under user's control.
                 This is covered in the MISRA C compliance section of the Rte specification.
     Risk:       Ambiguous identifiers can lead to compiler errors / warnings.
     Prevention: Verified during compile time. If the compiler reports an error or warning, the user has to rename the objects to be unique within the significant characters.

*/
