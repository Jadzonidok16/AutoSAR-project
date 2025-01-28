/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *
 *                 This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                 Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                 All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  LICENSE
 *  -------------------------------------------------------------------------------------------------------------------
 *            Module: BswM
 *           Program: 
 *          Customer: N/A
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: 
 *    License Scope : The usage is restricted to CBD0000000_D30
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: BswM_Callout_Stubs.c
 *   Generation Time: 2024-04-03 15:25:56
 *           Project: MyECU - Version 1.0
 *          Delivery: CBD0000000_D30
 *      Tool Version: DaVinci Configurator  5.11.16 SP1
 *
 *
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK User Version>                           DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/*********************************************************************************************************************
    INCLUDES
 *********************************************************************************************************************/
/* PRQA S 0857 EOF */ /* MD_MSR_1.1_857 */
#define BSWM_CALLOUT_STUBS_SOURCE
#include "BswM.h"
#include "BswM_Private_Cfg.h"



/**********************************************************************************************************************
 *  Additional configured User includes
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK User Includes>                          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#include "Main.h"

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/



/**********************************************************************************************************************
 *  CALLOUT FUNCTIONS
 *********************************************************************************************************************/
#define BSWM_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *  GENERIC CALLOUTS
 *********************************************************************************************************************/
FUNC(void, BSWM_CODE) BswM_INIT_NvMReadAll(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK BswM_INIT_NvMReadAll>                   DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

	BswNvMReadAll();

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

} /* End of BswM_INIT_NvMReadAll */


FUNC(void, BSWM_CODE) Appl_StartCommunication(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK Appl_StartCommunication>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
	ComM_CommunicationAllowed(ComMConf_ComMChannel_CAN00_f26020e5, 1u);        /* CAN */
	ComM_RequestComMode(ComMConf_ComMChannel_CAN00_f26020e5, COMM_FULL_COMMUNICATION);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

} /* End of Appl_StartCommunication */


FUNC(void, BSWM_CODE) ESH_ComM_CheckPendingRequests(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK ESH_ComM_CheckPendingRequests>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
ComM_StateType CAN00_f26020e5 = COMM_NO_COM_NO_PENDING_REQUEST;

(void)ComM_GetState(ComMConf_ComMChannel_CAN00_f26020e5, &CAN00_f26020e5); /* SBSW_BSWM_FCTCALL_LOCALVAR */

if(CAN00_f26020e5 != COMM_NO_COM_NO_PENDING_REQUEST)
{
  BswM_RequestMode(BSWM_GENERIC_ESH_ComMPendingRequests, BSWM_GENERICVALUE_ESH_ComMPendingRequests_ESH_COMM_PENDING_REQUEST);
}
else
{
  BswM_RequestMode(BSWM_GENERIC_ESH_ComMPendingRequests, BSWM_GENERICVALUE_ESH_ComMPendingRequests_ESH_COMM_NO_REQUEST);
}

} /* End of ESH_ComM_CheckPendingRequests */


FUNC(void, BSWM_CODE) BswM_ESH_OnEnterPostRun(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK BswM_ESH_OnEnterPostRun>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

} /* End of BswM_ESH_OnEnterPostRun */


FUNC(void, BSWM_CODE) BswM_ESH_OnEnterShutdown(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK BswM_ESH_OnEnterShutdown>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

} /* End of BswM_ESH_OnEnterShutdown */


FUNC(void, BSWM_CODE) BswM_ESH_OnEnterPrepShutdown(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK BswM_ESH_OnEnterPrepShutdown>           DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

} /* End of BswM_ESH_OnEnterPrepShutdown */


FUNC(void, BSWM_CODE) BswM_ESH_OnEnterWakeup(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK BswM_ESH_OnEnterWakeup>                 DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

} /* End of BswM_ESH_OnEnterWakeup */


FUNC(void, BSWM_CODE) BswM_ESH_OnEnterRun(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK BswM_ESH_OnEnterRun>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

} /* End of BswM_ESH_OnEnterRun */


FUNC(void, BSWM_CODE) BswM_ESH_OnEnterWaitForNvm(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK BswM_ESH_OnEnterWaitForNvm>             DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

} /* End of BswM_ESH_OnEnterWaitForNvm */


#define BSWM_STOP_SEC_CODE
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_19.1 */

#if 0
#endif


/**********************************************************************************************************************
 *  END OF FILE: BSWM_CALLOUT_STUBS.C
 *********************************************************************************************************************/


