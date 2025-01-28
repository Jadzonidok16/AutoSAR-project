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
 *          File:  Rte_CtApBatteryManager.h
 *        Config:  C:/nit-au-03/AUTOSAR_Exercises/AFS/MyECU.dpa
 *     SW-C Type:  CtApBatteryManager
 *  Generated at:  Sat Apr 13 16:30:42 2024
 *
 *     Generator:  MICROSAR RTE Generator Version 4.9.0
 *                 RTE Core Version 1.9.0
 *       License:  Unlimited license CBD0000000 for N/A
 *
 *   Description:  Application header file for SW-C <CtApBatteryManager> (Contract Phase)
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_CTAPBATTERYMANAGER_H
# define _RTE_CTAPBATTERYMANAGER_H

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

# include "Rte_CtApBatteryManager_Type.h"
# include "Rte_DataHandleType.h"


/**********************************************************************************************************************
 * Component Data Structures and Port Data Structures
 *********************************************************************************************************************/

struct Rte_CDS_CtApBatteryManager
{
  /* dummy entry */
  uint8 _dummy;
};

# define RTE_START_SEC_CONST_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern CONSTP2CONST(struct Rte_CDS_CtApBatteryManager, RTE_CONST, RTE_CONST) Rte_Inst_CtApBatteryManager; /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define RTE_STOP_SEC_CONST_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

typedef P2CONST(struct Rte_CDS_CtApBatteryManager, TYPEDEF, RTE_CONST) Rte_Instance;


# define RTE_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Switch_CtApBatteryManager_PpBatteryMode_BatteryMode(uint8 nextMode); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_CtApBatteryManager_Event_DTC_0x000002_SetEventStatus(Dem_EventStatusType EventStatus); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_CtApBatteryManager_PiBatteryLevelHwAb_ReadChannel(P2VAR(IdtDioValueType, AUTOMATIC, RTE_CTAPBATTERYMANAGER_APPL_VAR) value); /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define RTE_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */



/**********************************************************************************************************************
 * Rte_Switch_<p>_<m>
 *********************************************************************************************************************/
# define Rte_Switch_PpBatteryMode_BatteryMode Rte_Switch_CtApBatteryManager_PpBatteryMode_BatteryMode


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (C/S invocation)
 *********************************************************************************************************************/
# define Rte_Call_Event_DTC_0x000002_SetEventStatus Rte_Call_CtApBatteryManager_Event_DTC_0x000002_SetEventStatus
# define Rte_Call_PiBatteryLevelHwAb_ReadChannel Rte_Call_CtApBatteryManager_PiBatteryLevelHwAb_ReadChannel




# define CtApBatteryManager_START_SEC_CODE
# include "CtApBatteryManager_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 *
 * Runnable Entity Name: RCtApBatteryManager
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 100ms
 *
 **********************************************************************************************************************
 *
 * Mode Interfaces:
 * ================
 *   Std_ReturnType Rte_Switch_PpBatteryMode_BatteryMode(uint8 mode)
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
 *   Std_ReturnType Rte_Call_PiBatteryLevelHwAb_ReadChannel(IdtDioValueType *value)
 *     Synchronous Server Invocation. Timeout: None
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_Event_DTC_0x000002_SetEventStatus(Dem_EventStatusType EventStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *
 *********************************************************************************************************************/

# define RTE_RUNNABLE_RCtApBatteryManager RCtApBatteryManager
FUNC(void, CtApBatteryManager_CODE) RCtApBatteryManager(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define CtApBatteryManager_STOP_SEC_CODE
# include "CtApBatteryManager_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

# define RTE_E_DiagnosticMonitor_E_NOT_OK (1U)

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_CTAPBATTERYMANAGER_H */
