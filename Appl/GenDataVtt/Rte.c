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
 *          File:  Rte.c
 *        Config:  MyECU.dpa
 *   ECU-Project:  MyECU
 *
 *     Generator:  MICROSAR RTE Generator Version 4.9.0
 *                 RTE Core Version 1.9.0
 *       License:  Unlimited license CBD0000000 for N/A
 *
 *   Description:  RTE implementation file
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* PRQA S 0777, 0779, 0781, 0857 EOF */ /* MD_Rte_0777, MD_Rte_0779, MD_Rte_0781, MD_MSR_1.1_857 */

#define RTE_CORE
#include "Os.h" /* PRQA S 0828, 0883 */ /* MD_MSR_1.1_828, MD_Rte_Os */
#include "Rte_Type.h"
#include "Rte_Main.h"

#include "Rte_BswM.h"
#include "Rte_ComM.h"
#include "Rte_CtApAFSController.h"
#include "Rte_CtApBatteryManager.h"
#include "Rte_CtCddIoHwAb.h"
#include "Rte_CtSaAmbientLight.h"
#include "Rte_CtSaFrontlight.h"
#include "Rte_CtSaSpeedometer.h"
#include "Rte_CtSaSteeringWheel.h"
#include "Rte_Dcm.h"
#include "Rte_Dem.h"
#include "Rte_Det.h"
#include "Rte_EcuM.h"
#include "Rte_NvM.h"
#include "SchM_BswM.h"
#include "SchM_Can.h"
#include "SchM_CanIf.h"
#include "SchM_CanNm.h"
#include "SchM_CanSM.h"
#include "SchM_CanTp.h"
#include "SchM_Com.h"
#include "SchM_ComM.h"
#include "SchM_Dcm.h"
#include "SchM_Dem.h"
#include "SchM_Det.h"
#include "SchM_EcuM.h"
#include "SchM_Fee.h"
#include "SchM_Fls.h"
#include "SchM_Nm.h"
#include "SchM_NvM.h"
#include "SchM_PduR.h"

#include "Rte_Hook.h"

#include "Com.h"
#if defined(IL_ASRCOM_VERSION)
# define RTE_USE_COM_TXSIGNAL_RDACCESS
#endif

#include "Rte_Cbk.h"

/* AUTOSAR 3.x compatibility */
#if !defined (STATIC)
# define STATIC static
#endif


/**********************************************************************************************************************
 * API for enable / disable interrupts global
 *********************************************************************************************************************/

#if defined(osDisableGlobalKM) && !defined(RTE_DISABLE_ENHANCED_INTERRUPT_LOCK_API)
# define Rte_DisableAllInterrupts() osDisableGlobalKM()   /* MICROSAR OS */
#else
# define Rte_DisableAllInterrupts() DisableAllInterrupts()   /* AUTOSAR OS */
#endif

#if defined(osEnableGlobalKM) && !defined(RTE_DISABLE_ENHANCED_INTERRUPT_LOCK_API)
# define Rte_EnableAllInterrupts() osEnableGlobalKM()   /* MICROSAR OS */
#else
# define Rte_EnableAllInterrupts() EnableAllInterrupts()   /* AUTOSAR OS */
#endif

/**********************************************************************************************************************
 * API for enable / disable interrupts up to the systemLevel
 *********************************************************************************************************************/

#if defined(osDisableLevelKM) && !defined(RTE_DISABLE_ENHANCED_INTERRUPT_LOCK_API)
# define Rte_DisableOSInterrupts() osDisableLevelKM()   /* MICROSAR OS */
#else
# define Rte_DisableOSInterrupts() SuspendOSInterrupts()   /* AUTOSAR OS */
#endif

#if defined(osEnableLevelKM) && !defined(RTE_DISABLE_ENHANCED_INTERRUPT_LOCK_API)
# define Rte_EnableOSInterrupts() osEnableLevelKM()   /* MICROSAR OS */
#else
# define Rte_EnableOSInterrupts() ResumeOSInterrupts()   /* AUTOSAR OS */
#endif


/**********************************************************************************************************************
 * Buffers for unqueued S/R
 *********************************************************************************************************************/

#define RTE_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

VAR(uint8, RTE_VAR_NOINIT) Rte_CpApAFSController_PpLightPositionLeft_DeLightLength; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(sint8, RTE_VAR_NOINIT) Rte_CpApAFSController_PpLightPositionLeft_DeLightPosition; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_NOINIT) Rte_CpApAFSController_PpLightPositionRight_DeLightLength; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(sint8, RTE_VAR_NOINIT) Rte_CpApAFSController_PpLightPositionRight_DeLightPosition; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(IdtAmbientLight, RTE_VAR_NOINIT) Rte_CpSaAmbientLight_PpAmbientLightOut_DeAmbientLight; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(IdtSpeedometer, RTE_VAR_NOINIT) Rte_CpSaSpeedometer_PpSpeedometerOut_DeSpeedometer; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(IdtDioValueType, RTE_VAR_NOINIT) Rte_CpSaSteeringWheel_PpSteeringWheelPositionOut_DeSteeringWheelPosition; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */

#define RTE_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 * Per-Instance Memory
 *********************************************************************************************************************/

#define RTE_START_SEC_VAR_DEFAULT_RTE_PIM_GROUP_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

VAR(IdtPassingLane, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_CpApAFSController_PimPassingLane; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */

#define RTE_STOP_SEC_VAR_DEFAULT_RTE_PIM_GROUP_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define RTE_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * API Prototypes
 *********************************************************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_WriteInst1_CtSaFrontlight_PpLightPositionOut_DeLightLength(uint8 data); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC(Std_ReturnType, RTE_CODE) Rte_WriteInst1_CtSaFrontlight_PpLightPositionOut_DeLightPosition(sint8 data); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC(Std_ReturnType, RTE_CODE) Rte_ReadInst1_CtSaFrontlight_PpLightPositionIn_DeLightLength(P2VAR(uint8, AUTOMATIC, RTE_CTSAFRONTLIGHT_APPL_VAR) data); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC(Std_ReturnType, RTE_CODE) Rte_ReadInst1_CtSaFrontlight_PpLightPositionIn_DeLightPosition(P2VAR(sint8, AUTOMATIC, RTE_CTSAFRONTLIGHT_APPL_VAR) data); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC(Std_ReturnType, RTE_CODE) Rte_WriteInst2_CtSaFrontlight_PpLightPositionOut_DeLightLength(uint8 data); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC(Std_ReturnType, RTE_CODE) Rte_WriteInst2_CtSaFrontlight_PpLightPositionOut_DeLightPosition(sint8 data); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC(Std_ReturnType, RTE_CODE) Rte_ReadInst2_CtSaFrontlight_PpLightPositionIn_DeLightLength(P2VAR(uint8, AUTOMATIC, RTE_CTSAFRONTLIGHT_APPL_VAR) data); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC(Std_ReturnType, RTE_CODE) Rte_ReadInst2_CtSaFrontlight_PpLightPositionIn_DeLightPosition(P2VAR(sint8, AUTOMATIC, RTE_CTSAFRONTLIGHT_APPL_VAR) data); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */

#define RTE_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define RTE_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * Component Data Structures
 *********************************************************************************************************************/

/* PRQA S 0850, 3408, 1504 L1 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
CONST(struct Rte_CDS_CtSaFrontlight, RTE_CONST) Rte_Instance_CpSaLeftFrontlight =
{
  /* Port API section */
  {
    Rte_WriteInst1_CtSaFrontlight_PpLightPositionOut_DeLightLength,
    Rte_WriteInst1_CtSaFrontlight_PpLightPositionOut_DeLightPosition,
  },
  {
    Rte_ReadInst1_CtSaFrontlight_PpLightPositionIn_DeLightLength,
    Rte_ReadInst1_CtSaFrontlight_PpLightPositionIn_DeLightPosition,
  },
  /* Vendor specific section */
};
/* PRQA L:L1 */

/* PRQA S 0850, 3408, 1504 L1 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
CONST(struct Rte_CDS_CtSaFrontlight, RTE_CONST) Rte_Instance_CpSaRightFrontlight =
{
  /* Port API section */
  {
    Rte_WriteInst2_CtSaFrontlight_PpLightPositionOut_DeLightLength,
    Rte_WriteInst2_CtSaFrontlight_PpLightPositionOut_DeLightPosition,
  },
  {
    Rte_ReadInst2_CtSaFrontlight_PpLightPositionIn_DeLightLength,
    Rte_ReadInst2_CtSaFrontlight_PpLightPositionIn_DeLightPosition,
  },
  /* Vendor specific section */
};
/* PRQA L:L1 */

#define RTE_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */



/**********************************************************************************************************************
 * Internal C/S connections
 *********************************************************************************************************************/

/* Queue definitions for internal C/S connections */
#define RTE_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

VAR(Rte_CS_ServerQueueType_CpApAFSController_CBReadData_BatteryValue_ReadData, RTE_VAR_NOINIT) Rte_CS_ServerQueue_CpApAFSController_CBReadData_BatteryValue_ReadData; /* PRQA S 0850, 1504, 3229 */ /* MD_MSR_19.8, MD_MSR_8.10, MD_Rte_Qac */
VAR(Rte_CS_ServerQueueInfoType_CpApAFSController_CBReadData_BatteryValue_ReadData, RTE_VAR_NOINIT) Rte_CS_ServerQueueInfo_CpApAFSController_CBReadData_BatteryValue_ReadData; /* PRQA S 0850, 1504 */ /* MD_MSR_19.8, MD_MSR_8.10 */

#define RTE_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define RTE_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

STATIC FUNC(void, RTE_CODE) Rte_MemClr(P2VAR(void, AUTOMATIC, RTE_VAR_NOINIT) ptr, uint16_least num); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, RTE_CODE) Rte_MemCpy(P2VAR(void, AUTOMATIC, RTE_APPL_VAR) destination, P2CONST(void, AUTOMATIC, RTE_APPL_DATA) source, uint16_least num); /* PRQA S 0850, 1505, 3447, 3408 */ /* MD_MSR_19.8, MD_MSR_8.10, MD_Rte_3447, MD_Rte_3408 */
FUNC(void, RTE_CODE) Rte_MemCpy32(P2VAR(void, AUTOMATIC, RTE_APPL_VAR) destination, P2CONST(void, AUTOMATIC, RTE_APPL_DATA) source, uint16_least num); /* PRQA S 0850, 1505, 3447, 3408 */ /* MD_MSR_19.8, MD_MSR_8.10, MD_Rte_3447, MD_Rte_3408 */
STATIC FUNC(void, RTE_CODE) Rte_IncDisableFlags_CpApBatteryManager_PpBatteryMode_BatteryMode(uint8 nextMode); /* PRQA S 0850 */ /* MD_MSR_19.8 */
STATIC FUNC(void, RTE_CODE) Rte_DecDisableFlags_CpApBatteryManager_PpBatteryMode_BatteryMode(uint8 previousMode); /* PRQA S 0850 */ /* MD_MSR_19.8 */

#define RTE_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define RTE_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * Data structures for mode management
 *********************************************************************************************************************/

VAR(uint8, RTE_VAR_NOINIT) Rte_ModeMachine_BswM_Switch_ESH_ModeSwitch_BswM_MDGP_ESH_Mode; /* PRQA S 3408 */ /* MD_Rte_3408 */

VAR(uint8, RTE_VAR_NOINIT) Rte_ModeMachine_ComM_UM_USR_CHNL_CAN00_currentMode; /* PRQA S 3408 */ /* MD_Rte_3408 */

VAR(uint8, RTE_VAR_NOINIT) Rte_ModeMachine_CpApAFSController_PpBswmMRequestBatteryMode_BswM_MDGP_BatteryMode; /* PRQA S 3408 */ /* MD_Rte_3408 */
STATIC VAR(Rte_ModeInfoType_CpApBatteryManager_PpBatteryMode_BatteryMode, RTE_VAR_NOINIT) Rte_ModeInfo_CpApBatteryManager_PpBatteryMode_BatteryMode;

VAR(uint8, RTE_VAR_NOINIT) Rte_ModeMachine_CpApBatteryManager_PpBatteryMode_BatteryMode; /* PRQA S 3408 */ /* MD_Rte_3408 */


#define RTE_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define RTE_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */





/* PRQA S 3408 L1 */ /* MD_Rte_3408 */
CONST(EventMaskType, RTE_CONST) Rte_ModeEntryEventMask_CpApBatteryManager_PpBatteryMode_BatteryMode[3] =
{
  (EventMaskType) 0, /* BATTERY_HIGH */
  Rte_Ev_Run_CpApAFSController_RCtApAFSController_ModeChange_HighBeam, /* BATTERY_LOW */
  (EventMaskType) 0  /* BATTERY_MEDIUM */
};
/* PRQA L:L1 */


#define RTE_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 * Trigger Disable Flags
 *********************************************************************************************************************/

#define RTE_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

VAR(Rte_TriggerDisableFlagsType, RTE_VAR_NOINIT) Rte_TriggerDisableFlags; /* PRQA S 0850 */ /* MD_MSR_19.8 */

#define RTE_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define Rte_TriggerDisableFlagsInit() (Rte_MemClr(&Rte_TriggerDisableFlags, sizeof(Rte_TriggerDisableFlagsType)))


/**********************************************************************************************************************
 * Timer handling
 *********************************************************************************************************************/

#define RTE_USEC_SystemTimer(val) ((TickType)RTE_CONST_USEC_SystemTimer_##val) /* PRQA S 0342 */ /* MD_Rte_0342 */
#define RTE_MSEC_SystemTimer(val) ((TickType)RTE_CONST_MSEC_SystemTimer_##val) /* PRQA S 0342 */ /* MD_Rte_0342 */
#define RTE_SEC_SystemTimer(val)  ((TickType)RTE_CONST_SEC_SystemTimer_##val) /* PRQA S 0342 */ /* MD_Rte_0342 */

#define RTE_CONST_MSEC_SystemTimer_0 (0UL)

#define RTE_CONST_MSEC_SystemTimer_10 (10UL)

#define RTE_CONST_MSEC_SystemTimer_100 (100UL)

#define RTE_CONST_MSEC_SystemTimer_20 (20UL)

#define RTE_CONST_MSEC_SystemTimer_5 (5UL)


/**********************************************************************************************************************
 * Internal definitions
 *********************************************************************************************************************/

#define RTE_TASK_TIMEOUT_EVENT_MASK   ((EventMaskType)0x01)
#define RTE_TASK_WAITPOINT_EVENT_MASK ((EventMaskType)0x02)

/**********************************************************************************************************************
 * RTE life cycle API
 *********************************************************************************************************************/

#define RTE_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

FUNC(void, RTE_CODE) Rte_MemCpy(P2VAR(void, AUTOMATIC, RTE_APPL_VAR) destination, P2CONST(void, AUTOMATIC, RTE_APPL_DATA) source, uint16_least num) /* PRQA S 3408, 1505 */ /* MD_Rte_3408, MD_MSR_8.10 */
{
  P2CONST(uint8, AUTOMATIC, RTE_APPL_DATA) src = source;
  P2VAR(uint8, AUTOMATIC, RTE_APPL_VAR) dst = destination;
  uint16_least i;
  for (i = 0; i < num ; i++)
  {
    dst[i] = src[i];
  }
}

#define RTE_MEMCPY32ALIGN (sizeof(uint32) - 1)

FUNC(void, RTE_CODE) Rte_MemCpy32(P2VAR(void, AUTOMATIC, RTE_APPL_VAR) destination, P2CONST(void, AUTOMATIC, RTE_APPL_DATA) source, uint16_least num)
{
  P2CONST(uint32, AUTOMATIC, RTE_APPL_DATA) asrc = source;
  P2VAR(uint32, AUTOMATIC, RTE_APPL_VAR) adst = destination;
  P2CONST(uint8, AUTOMATIC, RTE_APPL_DATA) src = source;
  P2VAR(uint8, AUTOMATIC, RTE_APPL_VAR) dst = destination;
  uint16_least i = 0;

  if (num >= 16)
  {
    if (((((uint32)src) & RTE_MEMCPY32ALIGN) == 0) && ((((uint32)dst) & RTE_MEMCPY32ALIGN) == 0)) /* PRQA S 0306 */ /* MD_Rte_0306 */
    {
      uint16_least asize = num / sizeof(uint32);
      uint16_least rem = num & RTE_MEMCPY32ALIGN;
      for (i = 0; i < (asize - 3); i += 4)
      {
        adst[i] = asrc[i];
        adst[i+1] = asrc[i+1];
        adst[i+2] = asrc[i+2];
        adst[i+3] = asrc[i+3];
      }

      while (i < asize)
      {
        adst[i] = asrc[i];
        ++i;
      }
      i = num - rem;
    }
    else
    {
      for (i = 0 ; (i + 15) < num; i += 16)
      {
        dst[i] = src[i];
        dst[i+1] = src[i+1];
        dst[i+2] = src[i+2];
        dst[i+3] = src[i+3];
        dst[i+4] = src[i+4];
        dst[i+5] = src[i+5];
        dst[i+6] = src[i+6];
        dst[i+7] = src[i+7];
        dst[i+8] = src[i+8];
        dst[i+9] = src[i+9];
        dst[i+10] = src[i+10];
        dst[i+11] = src[i+11];
        dst[i+12] = src[i+12];
        dst[i+13] = src[i+13];
        dst[i+14] = src[i+14];
        dst[i+15] = src[i+15];
      }
    }

  }
  while (i < num)
  {
    dst[i] = src[i];
    ++i;
  }
}

STATIC FUNC(void, RTE_CODE) Rte_MemClr(P2VAR(void, AUTOMATIC, RTE_VAR_NOINIT) ptr, uint16_least num)
{
  P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) dst = ptr;
  uint16_least i;
  for (i = 0; i < num; i++)
  {
    dst[i] = 0;
  }
}

FUNC(void, RTE_CODE) SchM_Init(void)
{
  /* activate the tasks */
  (void)ActivateTask(SchM_Task); /* PRQA S 3417 */ /* MD_Rte_Os */

  /* activate the alarms used for TimingEvents */
  (void)SetRelAlarm(Rte_Al_TE2_SchM_Task_0_5ms, RTE_MSEC_SystemTimer(0) + (TickType)1, RTE_MSEC_SystemTimer(5)); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)SetRelAlarm(Rte_Al_TE2_SchM_Task_0_20ms, RTE_MSEC_SystemTimer(0) + (TickType)1, RTE_MSEC_SystemTimer(20)); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)SetRelAlarm(Rte_Al_TE2_SchM_Task_0_10ms, RTE_MSEC_SystemTimer(0) + (TickType)1, RTE_MSEC_SystemTimer(10)); /* PRQA S 3417 */ /* MD_Rte_Os */

}

FUNC(Std_ReturnType, RTE_CODE) Rte_Start(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
  /* set default values for internal data */
  Rte_CpApAFSController_PpLightPositionLeft_DeLightLength = 0U;
  Rte_CpApAFSController_PpLightPositionLeft_DeLightPosition = 0;
  Rte_CpApAFSController_PpLightPositionRight_DeLightLength = 0U;
  Rte_CpApAFSController_PpLightPositionRight_DeLightPosition = 0;
  Rte_CpSaAmbientLight_PpAmbientLightOut_DeAmbientLight = 0U;
  Rte_CpSaSpeedometer_PpSpeedometerOut_DeSpeedometer = 0U;
  Rte_CpSaSteeringWheel_PpSteeringWheelPositionOut_DeSteeringWheelPosition = 0U;

  /* C/S queue initialization */
  Rte_CS_ServerQueueInfo_CpApAFSController_CBReadData_BatteryValue_ReadData.Rte_Free = 1;
  Rte_CS_ServerQueueInfo_CpApAFSController_CBReadData_BatteryValue_ReadData.Rte_Active = 0;

  /* mode management initialization part 1 */
  /* reset Trigger Disable Flags */
  Rte_TriggerDisableFlagsInit();

  Rte_ModeMachine_BswM_Switch_ESH_ModeSwitch_BswM_MDGP_ESH_Mode = RTE_MODE_ESH_Mode_STARTUP;

  Rte_ModeMachine_ComM_UM_USR_CHNL_CAN00_currentMode = RTE_MODE_ComMMode_COMM_NO_COMMUNICATION;

  Rte_ModeMachine_CpApAFSController_PpBswmMRequestBatteryMode_BswM_MDGP_BatteryMode = RTE_MODE_BatteryMode_BATTERY_MEDIUM;


  Rte_ModeMachine_CpApBatteryManager_PpBatteryMode_BatteryMode = RTE_TRANSITION_BatteryMode;

  Rte_ModeInfo_CpApBatteryManager_PpBatteryMode_BatteryMode.Rte_ModeQueue[0U] = RTE_MODE_BatteryMode_BATTERY_MEDIUM;
  Rte_ModeInfo_CpApBatteryManager_PpBatteryMode_BatteryMode.Rte_ModeQueue[1U] = RTE_MODE_BatteryMode_BATTERY_MEDIUM;

  /* activate the tasks */
  (void)ActivateTask(IO_Task); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)ActivateTask(My_Task); /* PRQA S 3417 */ /* MD_Rte_Os */

  /* activate the alarms used for TimingEvents */
  (void)SetRelAlarm(Rte_Al_TE_IO_Task_0_100ms, RTE_MSEC_SystemTimer(0) + (TickType)1, RTE_MSEC_SystemTimer(100)); /* PRQA S 3417 */ /* MD_Rte_Os */

  /* mode management initialization part 2 */
  (void)SetEvent(My_Task, Rte_Ev_MS_My_Task); /* PRQA S 3417 */ /* MD_Rte_Os */


  return RTE_E_OK;
} /* PRQA S 6050 */ /* MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Stop(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
  /* deactivate alarms */
  (void)CancelAlarm(Rte_Al_TE_IO_Task_0_100ms); /* PRQA S 3417 */ /* MD_Rte_Os */

  return RTE_E_OK;
}

FUNC(void, RTE_CODE) SchM_Deinit(void)
{
  /* deactivate alarms */
  (void)CancelAlarm(Rte_Al_TE2_SchM_Task_0_10ms); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)CancelAlarm(Rte_Al_TE2_SchM_Task_0_20ms); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)CancelAlarm(Rte_Al_TE2_SchM_Task_0_5ms); /* PRQA S 3417 */ /* MD_Rte_Os */

}

FUNC(void, RTE_CODE) Rte_InitMemory(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
}


/**********************************************************************************************************************
 * Internal/External Tx connections
 *********************************************************************************************************************/

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApAFSController_PpLightPositionLeft_DeLightPosition(sint8 data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_CpApAFSController_PpLightPositionLeft_DeLightPosition = *(&data);
  /* scheduled trigger for runnables: RCtSaFrontlight(CpSaLeftFrontlight) */
  (void)SetEvent(IO_Task, Rte_Ev_Run_CpSaLeftFrontlight_RCtSaFrontlight); /* PRQA S 3417 */ /* MD_Rte_Os */
  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApAFSController_PpLightPositionRight_DeLightPosition(sint8 data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_CpApAFSController_PpLightPositionRight_DeLightPosition = *(&data);
  /* scheduled trigger for runnables: RCtSaFrontlight(CpSaRightFrontlight) */
  (void)SetEvent(IO_Task, Rte_Ev_Run_CpSaRightFrontlight_RCtSaFrontlight); /* PRQA S 3417 */ /* MD_Rte_Os */
  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_WriteInst1_CtSaFrontlight_PpLightPositionOut_DeLightLength(uint8 data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  ret |= Com_SendSignal(ComConf_ComSignal_sig_LeftLightLength_Out, (&data)); /* PRQA S 0850 */ /* MD_MSR_19.8 */
  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_WriteInst1_CtSaFrontlight_PpLightPositionOut_DeLightPosition(sint8 data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  ret |= Com_SendSignal(ComConf_ComSignal_sig_LeftHAngle_Out, (&data)); /* PRQA S 0850 */ /* MD_MSR_19.8 */
  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_WriteInst2_CtSaFrontlight_PpLightPositionOut_DeLightLength(uint8 data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  ret |= Com_SendSignal(ComConf_ComSignal_sig_RightLightLength_Out, (&data)); /* PRQA S 0850 */ /* MD_MSR_19.8 */
  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_WriteInst2_CtSaFrontlight_PpLightPositionOut_DeLightPosition(sint8 data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  ret |= Com_SendSignal(ComConf_ComSignal_sig_RightHAngle_Out, (&data)); /* PRQA S 0850 */ /* MD_MSR_19.8 */
  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtSaSteeringWheel_PpSteeringWheelPositionOut_DeSteeringWheelPosition(IdtDioValueType data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_CpSaSteeringWheel_PpSteeringWheelPositionOut_DeSteeringWheelPosition = *(&data);
  /* scheduled trigger for runnables: RCtApAFSControllerLogic */
  (void)SetEvent(My_Task, Rte_Ev_Run1_CpApAFSController_RCtApAFSControllerLogic); /* PRQA S 3417 */ /* MD_Rte_Os */
  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */


/**********************************************************************************************************************
 * Internal/External Rx connections
 *********************************************************************************************************************/

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BswM_Request_ESH_PostRunRequest_0_requestedMode(P2VAR(BswM_ESH_RunRequest, AUTOMATIC, RTE_BSWM_APPL_VAR) data) /* PRQA S 0850, 3673, 1505, 3206 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10, MD_Rte_3206 */
{
  *data = 0U;
  return RTE_E_UNCONNECTED;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BswM_Request_ESH_PostRunRequest_1_requestedMode(P2VAR(BswM_ESH_RunRequest, AUTOMATIC, RTE_BSWM_APPL_VAR) data) /* PRQA S 0850, 3673, 1505, 3206 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10, MD_Rte_3206 */
{
  *data = 0U;
  return RTE_E_UNCONNECTED;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BswM_Request_ESH_RunRequest_0_requestedMode(P2VAR(BswM_ESH_RunRequest, AUTOMATIC, RTE_BSWM_APPL_VAR) data) /* PRQA S 0850, 3673, 1505, 3206 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10, MD_Rte_3206 */
{
  *data = 0U;
  return RTE_E_UNCONNECTED;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BswM_Request_ESH_RunRequest_1_requestedMode(P2VAR(BswM_ESH_RunRequest, AUTOMATIC, RTE_BSWM_APPL_VAR) data) /* PRQA S 0850, 3673, 1505, 3206 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10, MD_Rte_3206 */
{
  *data = 0U;
  return RTE_E_UNCONNECTED;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_ReadInst1_CtSaFrontlight_PpLightPositionIn_DeLightLength(P2VAR(uint8, AUTOMATIC, RTE_CTSAFRONTLIGHT_APPL_VAR) data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  *(data) = Rte_CpApAFSController_PpLightPositionLeft_DeLightLength;

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_ReadInst1_CtSaFrontlight_PpLightPositionIn_DeLightPosition(P2VAR(sint8, AUTOMATIC, RTE_CTSAFRONTLIGHT_APPL_VAR) data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  *(data) = Rte_CpApAFSController_PpLightPositionLeft_DeLightPosition;

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_ReadInst2_CtSaFrontlight_PpLightPositionIn_DeLightLength(P2VAR(uint8, AUTOMATIC, RTE_CTSAFRONTLIGHT_APPL_VAR) data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  *(data) = Rte_CpApAFSController_PpLightPositionRight_DeLightLength;

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_ReadInst2_CtSaFrontlight_PpLightPositionIn_DeLightPosition(P2VAR(sint8, AUTOMATIC, RTE_CTSAFRONTLIGHT_APPL_VAR) data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  *(data) = Rte_CpApAFSController_PpLightPositionRight_DeLightPosition;

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */


/**********************************************************************************************************************
 * Internal C/S connections
 *********************************************************************************************************************/

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_Dcm_DcmClearDTC(uint32 DTC, Dem_DTCFormatType DTCFormat, Dem_DTCOriginType DTCOrigin) /* PRQA S 0850, 1505, 3206, 3673 */ /* MD_MSR_19.8, MD_MSR_8.10, MD_Rte_3206, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_UNCONNECTED; /* PRQA S 3197 */ /* MD_Rte_3197 */

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_Dcm_DcmEnableDTCSetting(Dem_DTCGroupType DTCGroup, Dem_DTCKindType DTCKind) /* PRQA S 0850, 1505, 3206, 3673 */ /* MD_MSR_19.8, MD_MSR_8.10, MD_Rte_3206, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_UNCONNECTED; /* PRQA S 3197 */ /* MD_Rte_3197 */

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_Dcm_DcmGetExtendedDataRecordByDTC(uint32 DTC, Dem_DTCOriginType DTCOrigin, uint8 ExtendedDataNumber, P2VAR(uint8, AUTOMATIC, RTE_DCM_APPL_VAR) DestBuffer, P2VAR(uint16, AUTOMATIC, RTE_DCM_APPL_VAR) BufSize) /* PRQA S 0850, 1505, 3206, 3673 */ /* MD_MSR_19.8, MD_MSR_8.10, MD_Rte_3206, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_UNCONNECTED; /* PRQA S 3197 */ /* MD_Rte_3197 */

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_SecurityAccess_Level_01_CompareKey(P2CONST(Dcm_Data2ByteType, AUTOMATIC, RTE_DCM_APPL_DATA) Key, Dcm_OpStatusType OpStatus) /* PRQA S 0850, 1505, 3206, 3673 */ /* MD_MSR_19.8, MD_MSR_8.10, MD_Rte_3206, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_UNCONNECTED; /* PRQA S 3197 */ /* MD_Rte_3197 */

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_SecurityAccess_Level_01_GetSeed(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data2ByteType, AUTOMATIC, RTE_DCM_APPL_VAR) Seed, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DCM_APPL_VAR) ErrorCode) /* PRQA S 0850, 1505, 3206, 3673 */ /* MD_MSR_19.8, MD_MSR_8.10, MD_Rte_3206, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_UNCONNECTED; /* PRQA S 3197 */ /* MD_Rte_3197 */

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dem_CBReadData_OccurrenceCounter_OccurenceCounter_ReadData(P2VAR(DataArray_Type_4, AUTOMATIC, RTE_DEM_APPL_VAR) Data) /* PRQA S 0850, 1505, 3206, 3673 */ /* MD_MSR_19.8, MD_MSR_8.10, MD_Rte_3206, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_UNCONNECTED; /* PRQA S 3197 */ /* MD_Rte_3197 */

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dem_CBReadData_BatteryValue_BatteryValue_ReadData(P2VAR(DataArray_Type_4, AUTOMATIC, RTE_DEM_APPL_VAR) Data) /* PRQA S 0850, 1505, 3673 */ /* MD_MSR_19.8, MD_MSR_8.10, MD_Rte_Qac */
{
  Std_ReturnType ret;
  EventMaskType ev;


  {
    SuspendOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    if (Rte_CS_ServerQueueInfo_CpApAFSController_CBReadData_BatteryValue_ReadData.Rte_Free > 0)
    {
      Rte_CS_ServerQueueInfo_CpApAFSController_CBReadData_BatteryValue_ReadData.Rte_Free = 0;
      Rte_CS_ServerQueueInfo_CpApAFSController_CBReadData_BatteryValue_ReadData.Rte_Active = 1;
      ResumeOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

      Rte_CS_ServerQueue_CpApAFSController_CBReadData_BatteryValue_ReadData.Rte_ServerCompleted = FALSE;
      {
        Rte_CS_ServerQueue_CpApAFSController_CBReadData_BatteryValue_ReadData.Rte_TaskID = SchM_Task;
      }
      Rte_CS_ServerQueue_CpApAFSController_CBReadData_BatteryValue_ReadData.Data = Data;

      /* scheduled trigger for runnables: CBReadData_BatteryValue_ReadData */
      (void)SetEvent(IO_Task, Rte_Ev_Run_CpApAFSController_CBReadData_BatteryValue_ReadData); /* PRQA S 3417 */ /* MD_Rte_Os */

      {
        do
        {
          (void)WaitEvent(Rte_Ev_WP_SchM_Task); /* PRQA S 3417 */ /* MD_Rte_Os */
          (void)GetEvent(SchM_Task, &ev); /* PRQA S 3417 */ /* MD_Rte_Os */
          (void)ClearEvent(ev & (Rte_Ev_WP_SchM_Task)); /* PRQA S 3417 */ /* MD_Rte_Os */
        }
        while (Rte_CS_ServerQueue_CpApAFSController_CBReadData_BatteryValue_ReadData.Rte_ServerCompleted == FALSE);
      }

      ret = Rte_CS_ServerQueue_CpApAFSController_CBReadData_BatteryValue_ReadData.Rte_Result;

      SuspendOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
      Rte_CS_ServerQueueInfo_CpApAFSController_CBReadData_BatteryValue_ReadData.Rte_Free = 1;
    }
    else
    {
      ret = RTE_E_TIMEOUT;
    }
    ResumeOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  }


  return ret;
} /* PRQA S 6050 */ /* MD_MSR_STCAL */


/**********************************************************************************************************************
 * Mode switch handling functions
 *********************************************************************************************************************/
STATIC FUNC(void, RTE_CODE) Rte_IncDisableFlags_CpApBatteryManager_PpBatteryMode_BatteryMode(uint8 nextMode) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
  if (nextMode == RTE_MODE_BatteryMode_BATTERY_LOW)
  {
    Rte_CheckDetErrorContinue(Rte_TriggerDisableFlags.Rte_Trigger_CpApBatteryManager_PpBatteryMode_BatteryMode_BATTERY_LOW < Rte_TriggerDisableMaxCount_CpApBatteryManager_PpBatteryMode_BatteryMode_BATTERY_LOW, RTE_INCDISABLEFLAGS_SERVICE_ID, RTE_E_DET_TRIGGERDISABLECOUNTER); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_TriggerDisableFlags.Rte_Trigger_CpApBatteryManager_PpBatteryMode_BatteryMode_BATTERY_LOW++;
  }
}

STATIC FUNC(void, RTE_CODE) Rte_DecDisableFlags_CpApBatteryManager_PpBatteryMode_BatteryMode(uint8 previousMode) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
  if (previousMode == RTE_MODE_BatteryMode_BATTERY_LOW)
  {
    Rte_CheckDetErrorContinue(Rte_TriggerDisableFlags.Rte_Trigger_CpApBatteryManager_PpBatteryMode_BatteryMode_BATTERY_LOW > 0, RTE_DECDISABLEFLAGS_SERVICE_ID, RTE_E_DET_TRIGGERDISABLECOUNTER); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_TriggerDisableFlags.Rte_Trigger_CpApBatteryManager_PpBatteryMode_BatteryMode_BATTERY_LOW--;
  }
}



/**********************************************************************************************************************
 * Mode Switch API (Rte_Switch)
 *********************************************************************************************************************/

FUNC(Std_ReturnType, RTE_CODE) Rte_Switch_BswM_Switch_ESH_ModeSwitch_BswM_MDGP_ESH_Mode(uint8 nextMode) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  if (nextMode >= 5)
  {
    Rte_CallDetReportError(RTE_SWITCH_SERVICE_ID, RTE_E_DET_MODEARGUMENT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    ret = RTE_E_LIMIT;
  }
  else
  {
    SuspendOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_ModeMachine_BswM_Switch_ESH_ModeSwitch_BswM_MDGP_ESH_Mode = nextMode;
    ResumeOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  }

  return ret;
} /* PRQA S 6050 */ /* MD_MSR_STCAL */


/**********************************************************************************************************************
 * Mode reading API (Rte_Mode)
 *********************************************************************************************************************/

FUNC(uint8, RTE_CODE) Rte_Mode_BswM_Notification_ESH_ModeNotification_BswM_MDGP_ESH_Mode(void) /* PRQA S 3408 */ /* MD_Rte_3408 */
{
  return Rte_ModeMachine_BswM_Switch_ESH_ModeSwitch_BswM_MDGP_ESH_Mode;
}

FUNC(uint8, RTE_CODE) Rte_Mode_BswM_Notification_SWC_MODE_NOTIFICATION_BswM_MDGP_BatteryMode_BswM_MDGP_BatteryMode(void) /* PRQA S 3408 */ /* MD_Rte_3408 */
{
  return Rte_ModeMachine_CpApAFSController_PpBswmMRequestBatteryMode_BswM_MDGP_BatteryMode;
}


/**********************************************************************************************************************
 * Mode Switch API (Rte_Switch)
 *********************************************************************************************************************/

FUNC(Std_ReturnType, RTE_CODE) Rte_Switch_ComM_UM_USR_CHNL_CAN00_currentMode(uint8 nextMode) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  if (nextMode >= 3)
  {
    Rte_CallDetReportError(RTE_SWITCH_SERVICE_ID, RTE_E_DET_MODEARGUMENT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    ret = RTE_E_LIMIT;
  }
  else
  {
    SuspendOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_ModeMachine_ComM_UM_USR_CHNL_CAN00_currentMode = nextMode;
    ResumeOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  }

  return ret;
} /* PRQA S 6050 */ /* MD_MSR_STCAL */


/**********************************************************************************************************************
 * Mode Switch API (Rte_Switch)
 *********************************************************************************************************************/

FUNC(Std_ReturnType, RTE_CODE) Rte_Switch_CtApBatteryManager_PpBatteryMode_BatteryMode(uint8 nextMode) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  if (nextMode >= 3U)
  {
    Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_CallDetReportError(RTE_SWITCH_SERVICE_ID, RTE_E_DET_MODEARGUMENT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    ret = RTE_E_LIMIT;
  }
  else if (Rte_ModeMachine_CpApBatteryManager_PpBatteryMode_BatteryMode == RTE_TRANSITION_BatteryMode)
  {
    ret = RTE_E_LIMIT;
    Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  }
  else
  {
    EventMaskType ModeSwitchEventMask;
    uint8 currentMode = Rte_ModeMachine_CpApBatteryManager_PpBatteryMode_BatteryMode;

    ModeSwitchEventMask = Rte_ModeEntryEventMask_CpApBatteryManager_PpBatteryMode_BatteryMode[nextMode];

    if ((ModeSwitchEventMask == (EventMaskType)0) && (currentMode != nextMode))
    {
      if ((nextMode == RTE_MODE_BatteryMode_BATTERY_LOW) || (currentMode == RTE_MODE_BatteryMode_BATTERY_LOW))
      {
        ModeSwitchEventMask |= Rte_Ev_MS_My_Task;
      }
    }

    if (ModeSwitchEventMask != (EventMaskType)0)
    {
      Rte_ModeInfo_CpApBatteryManager_PpBatteryMode_BatteryMode.Rte_ModeQueue[0] = nextMode;
      Rte_ModeInfo_CpApBatteryManager_PpBatteryMode_BatteryMode.Rte_ModeQueue[1U] = currentMode;

      Rte_ModeMachine_CpApBatteryManager_PpBatteryMode_BatteryMode = RTE_TRANSITION_BatteryMode;
      if (currentMode != nextMode)
      {
        Rte_IncDisableFlags_CpApBatteryManager_PpBatteryMode_BatteryMode(nextMode);
      }
      Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

      (void)SetEvent(My_Task, ModeSwitchEventMask); /* PRQA S 3417 */ /* MD_Rte_Os */
    }
    else
    {
      Rte_ModeMachine_CpApBatteryManager_PpBatteryMode_BatteryMode = nextMode;
      Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    }
  }

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */


/**********************************************************************************************************************
 * Transmission/Mode Switch Acknowledgement handling (Rte_Feedback/Rte_SwitchAck)
 *********************************************************************************************************************/

FUNC(Std_ReturnType, RTE_CODE) Rte_SwitchAck_Dcm_DcmEcuReset_DcmEcuReset(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
  return RTE_E_UNCONNECTED;
} /* PRQA S 6010, 6030, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STMIF */


/**********************************************************************************************************************
 * Mode Switch API (Rte_Switch)
 *********************************************************************************************************************/

FUNC(Std_ReturnType, RTE_CODE) Rte_Switch_Dcm_DcmControlDtcSetting_DcmControlDtcSetting(uint8 nextMode) /* PRQA S 0850, 1505, 3206 */ /* MD_MSR_19.8, MD_MSR_8.10, MD_Rte_3206 */
{
  return RTE_E_OK;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Switch_Dcm_DcmDiagnosticSessionControl_DcmDiagnosticSessionControl(uint8 nextMode) /* PRQA S 0850, 1505, 3206 */ /* MD_MSR_19.8, MD_MSR_8.10, MD_Rte_3206 */
{
  return RTE_E_OK;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Switch_Dcm_DcmEcuReset_DcmEcuReset(uint8 nextMode) /* PRQA S 0850, 1505, 3206 */ /* MD_MSR_19.8, MD_MSR_8.10, MD_Rte_3206 */
{
  return RTE_E_OK;
}


/**********************************************************************************************************************
 * Task bodies for RTE controlled tasks
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Task:     IO_Task
 * Priority: 3
 * Schedule: FULL
 *********************************************************************************************************************/
TASK(IO_Task) /* PRQA S 3408, 1503 */ /* MD_Rte_3408, MD_MSR_14.1 */
{
  EventMaskType ev;


  for(;;)
  {
    (void)WaitEvent(Rte_Ev_Cyclic_IO_Task_0_100ms | Rte_Ev_Run_CpApAFSController_CBReadData_BatteryValue_ReadData | Rte_Ev_Run_CpSaLeftFrontlight_RCtSaFrontlight | Rte_Ev_Run_CpSaRightFrontlight_RCtSaFrontlight); /* PRQA S 3417 */ /* MD_Rte_Os */
    (void)GetEvent(IO_Task, &ev); /* PRQA S 3417 */ /* MD_Rte_Os */
    (void)ClearEvent(ev & (Rte_Ev_Cyclic_IO_Task_0_100ms | Rte_Ev_Run_CpApAFSController_CBReadData_BatteryValue_ReadData | Rte_Ev_Run_CpSaLeftFrontlight_RCtSaFrontlight | Rte_Ev_Run_CpSaRightFrontlight_RCtSaFrontlight)); /* PRQA S 3417 */ /* MD_Rte_Os */

    if (((ev & Rte_Ev_Cyclic_IO_Task_0_100ms) != (EventMaskType)0) && (Rte_TriggerDisableFlags.Rte_Trigger_CpApBatteryManager_PpBatteryMode_BatteryMode_BATTERY_LOW == 0))
    {
      /* call runnable */
      RCtSaSteeringWheelGetPosition();
    }

    if ((ev & Rte_Ev_Run_CpSaLeftFrontlight_RCtSaFrontlight) != (EventMaskType)0)
    {
      /* call runnable */
      RCtSaFrontlight(&Rte_Instance_CpSaLeftFrontlight);
    }

    if ((ev & Rte_Ev_Run_CpSaRightFrontlight_RCtSaFrontlight) != (EventMaskType)0)
    {
      /* call runnable */
      RCtSaFrontlight(&Rte_Instance_CpSaRightFrontlight);
    }

    if (((ev & Rte_Ev_Cyclic_IO_Task_0_100ms) != (EventMaskType)0) && (Rte_TriggerDisableFlags.Rte_Trigger_CpApBatteryManager_PpBatteryMode_BatteryMode_BATTERY_LOW == 0))
    {
      /* call runnable */
      RCtSaSpeedometer();

      /* call runnable */
      RCtSaAmbientLight();
    }

    if ((ev & Rte_Ev_Cyclic_IO_Task_0_100ms) != (EventMaskType)0)
    {
      /* call runnable */
      RCtApBatteryManager();
    }

    if ((ev & Rte_Ev_Run_CpApAFSController_CBReadData_BatteryValue_ReadData) != (EventMaskType)0)
    {
      {
        Rte_CS_ServerQueueInfo_CpApAFSController_CBReadData_BatteryValue_ReadData.Rte_Active = 0;

        /* call runnable */
        Rte_CS_ServerQueue_CpApAFSController_CBReadData_BatteryValue_ReadData.Rte_Result = CBReadData_BatteryValue_ReadData(Rte_CS_ServerQueue_CpApAFSController_CBReadData_BatteryValue_ReadData.Data);

        if (Rte_CS_ServerQueue_CpApAFSController_CBReadData_BatteryValue_ReadData.Rte_TaskID != INVALID_TASK)
        {
          Rte_CS_ServerQueue_CpApAFSController_CBReadData_BatteryValue_ReadData.Rte_ServerCompleted = TRUE;
          (void)SetEvent(Rte_CS_ServerQueue_CpApAFSController_CBReadData_BatteryValue_ReadData.Rte_TaskID, RTE_TASK_WAITPOINT_EVENT_MASK); /* PRQA S 3417 */ /* MD_Rte_Os */
        }
      }
    }
  }
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/**********************************************************************************************************************
 * Task:     My_Task
 * Priority: 2
 * Schedule: FULL
 *********************************************************************************************************************/
TASK(My_Task) /* PRQA S 3408, 1503 */ /* MD_Rte_3408, MD_MSR_14.1 */
{
  EventMaskType ev;


  /* call runnable */
  RCtApAFSController_Init();

  for(;;)
  {
    (void)WaitEvent(Rte_Ev_Run1_CpApAFSController_RCtApAFSControllerLogic | Rte_Ev_Run_CpApAFSController_RCtApAFSController_ModeChange_HighBeam | Rte_Ev_MS_My_Task); /* PRQA S 3417 */ /* MD_Rte_Os */
    (void)GetEvent(My_Task, &ev); /* PRQA S 3417 */ /* MD_Rte_Os */
    (void)ClearEvent(ev & (Rte_Ev_Run1_CpApAFSController_RCtApAFSControllerLogic | Rte_Ev_Run_CpApAFSController_RCtApAFSController_ModeChange_HighBeam | Rte_Ev_MS_My_Task)); /* PRQA S 3417 */ /* MD_Rte_Os */

    if (((ev & Rte_Ev_Run1_CpApAFSController_RCtApAFSControllerLogic) != (EventMaskType)0) && (Rte_TriggerDisableFlags.Rte_Trigger_CpApBatteryManager_PpBatteryMode_BatteryMode_BATTERY_LOW == 0))
    {
      /* call runnable */
      RCtApAFSControllerLogic();
    }

    if ((ev & Rte_Ev_Run_CpApAFSController_RCtApAFSController_ModeChange_HighBeam) != (EventMaskType)0)
    {
      /* call runnable */
      RCtApAFSController_ModeChange_HighBeam();
    }

    if (((ev & Rte_Ev_Run_CpApAFSController_RCtApAFSController_ModeChange_HighBeam) != (EventMaskType)0) || ((ev & Rte_Ev_MS_My_Task) != (EventMaskType)0))
    {
      uint8 previousMode;
      uint8 nextMode;

      Rte_CheckDetErrorContinue(Rte_ModeMachine_CpApBatteryManager_PpBatteryMode_BatteryMode == RTE_TRANSITION_BatteryMode, RTE_TASK_SERVICE_ID, RTE_E_DET_TRANSITIONSTATE); /* PRQA S 3109 */ /* MD_MSR_14.3 */

      Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
      previousMode = Rte_ModeInfo_CpApBatteryManager_PpBatteryMode_BatteryMode.Rte_ModeQueue[1U];
      nextMode = Rte_ModeInfo_CpApBatteryManager_PpBatteryMode_BatteryMode.Rte_ModeQueue[0];

      if (previousMode != nextMode)
      {
        Rte_DecDisableFlags_CpApBatteryManager_PpBatteryMode_BatteryMode(previousMode);
      }

      Rte_ModeMachine_CpApBatteryManager_PpBatteryMode_BatteryMode = Rte_ModeInfo_CpApBatteryManager_PpBatteryMode_BatteryMode.Rte_ModeQueue[0];

      Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */


    }
  }
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/**********************************************************************************************************************
 * Task:     SchM_Task
 * Priority: 6
 * Schedule: FULL
 *********************************************************************************************************************/
TASK(SchM_Task) /* PRQA S 3408, 1503 */ /* MD_Rte_3408, MD_MSR_14.1 */
{
  EventMaskType ev;


  for(;;)
  {
    (void)WaitEvent(Rte_Ev_Cyclic2_SchM_Task_0_10ms | Rte_Ev_Cyclic2_SchM_Task_0_20ms | Rte_Ev_Cyclic2_SchM_Task_0_5ms); /* PRQA S 3417 */ /* MD_Rte_Os */
    (void)GetEvent(SchM_Task, &ev); /* PRQA S 3417 */ /* MD_Rte_Os */
    (void)ClearEvent(ev & (Rte_Ev_Cyclic2_SchM_Task_0_10ms | Rte_Ev_Cyclic2_SchM_Task_0_20ms | Rte_Ev_Cyclic2_SchM_Task_0_5ms)); /* PRQA S 3417 */ /* MD_Rte_Os */

    if ((ev & Rte_Ev_Cyclic2_SchM_Task_0_20ms) != (EventMaskType)0)
    {
      /* call runnable */
      ComM_MainFunction_0();
    }

    if ((ev & Rte_Ev_Cyclic2_SchM_Task_0_10ms) != (EventMaskType)0)
    {
      /* call schedulable entity */
      CanSM_MainFunction();

      /* call schedulable entity */
      CanNm_MainFunction();

      /* call schedulable entity */
      Com_MainFunctionRx();
    }

    if ((ev & Rte_Ev_Cyclic2_SchM_Task_0_5ms) != (EventMaskType)0)
    {
      /* call schedulable entity */
      CanTp_MainFunction();
    }

    if ((ev & Rte_Ev_Cyclic2_SchM_Task_0_10ms) != (EventMaskType)0)
    {
      /* call schedulable entity */
      Com_MainFunctionTx();

      /* call runnable */
      Dem_MainFunction();

      /* call runnable */
      EcuM_MainFunction();

      /* call runnable */
      NvM_MainFunction();

      /* call schedulable entity */
      Can_MainFunction_Mode();

      /* call runnable */
      BswM_MainFunction();

      /* call schedulable entity */
      Can_MainFunction_BusOff();

      /* call schedulable entity */
      Can_MainFunction_Wakeup();
    }

    if ((ev & Rte_Ev_Cyclic2_SchM_Task_0_5ms) != (EventMaskType)0)
    {
      /* call schedulable entity */
      Fee_MainFunction();
    }

    if ((ev & Rte_Ev_Cyclic2_SchM_Task_0_10ms) != (EventMaskType)0)
    {
      /* call schedulable entity */
      Fls_MainFunction();

      /* call runnable */
      Dcm_MainFunction();
    }
  }
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

#define RTE_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 MISRA 2004 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_0306:  MISRA rule: 11.3
     Reason:     An optimized copy algorithm can be used for aligned data. To check if pointers are aligned, pointers need to be casted to an integer type.
     Risk:       No functional risk. Only the lower 8 bits of the address are checked, therefore all integer types are sufficient.
     Prevention: Not required.

   MD_Rte_0342:  MISRA rule: 19.13
     Reason:     For efficient code the use of macros and the operator '##' is necessary.
     Risk:       The used compiler is not ANSI/ISO C89 compatible. No functional risk.
     Prevention: AUTOSAR is based on ANSI/ISO C89. Compatible compilers are required.

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

   MD_Rte_0781:  MISRA rule: 5.6
     Reason:     The name is being used as a structure/union member as well as being a label, tag or ordinary identifier.
                 The compliance to this rule is under user's control.
     Risk:       Ambiguous identifiers can lead to compiler errors / warnings.
     Prevention: Verified during compile time. If the compiler reports an error or warning, the user has to rename the objects leading to the violation.

   MD_Rte_3408:  MISRA rule: 8.8
     Reason:     For the purpose of monitoring during calibration or debugging it is necessary to use non-static declarations.
                 This is covered in the MISRA C compliance section of the Rte specification.
     Risk:       No functional risk.
     Prevention: Not required.

   MD_Rte_3447:  MISRA rule: 8.8
     Reason:     For the purpose of monitoring during calibration or debugging it is necessary to use non-static declarations.
                 This is covered in the MISRA C compliance section of the Rte specification.
     Risk:       No functional risk.
     Prevention: Not required.

   MD_Rte_Os:
     Reason:     This justification is used as summary justification for all deviations caused by the MICROSAR OS
                 which is for testing of the RTE. Those deviations are no issues in the RTE code.
     Risk:       No functional risk.
     Prevention: Not required.

   MD_Rte_Qac:
     Reason:     This justification is used as summary justification for all deviations caused by wrong analysis tool results.
                 The used analysis tool QAC 7.0 sometimes creates wrong messages. Those deviations are no issues in the RTE code.
     Risk:       No functional risk.
     Prevention: Not required.

*/
