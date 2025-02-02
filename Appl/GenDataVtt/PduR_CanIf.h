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
 *            Module: PduR
 *           Program: 
 *          Customer: N/A
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: 
 *    License Scope : The usage is restricted to CBD0000000_D30
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: PduR_CanIf.h
 *   Generation Time: 2024-04-03 15:25:55
 *           Project: MyECU - Version 1.0
 *          Delivery: CBD0000000_D30
 *      Tool Version: DaVinci Configurator  5.11.16 SP1
 *
 *
 *********************************************************************************************************************/

#if !defined (PDUR_CANIF_H)
# define PDUR_CANIF_H

/* PRQA S 3451 EOF */ /* MD_PduR_3451 */

/**********************************************************************************************************************
  INCLUDES
**********************************************************************************************************************/
#include "PduR_Cfg.h"

/**********************************************************************************************************************
  GLOBAL CONSTANT MACROS
**********************************************************************************************************************/

/**********************************************************************************************************************
  GLOBAL FUNCTION MACROS
**********************************************************************************************************************/

/**********************************************************************************************************************
  GLOBAL DATA TYPES AND STRUCTURES
**********************************************************************************************************************/

/**********************************************************************************************************************
  GLOBAL DATA PROTOTYPES
**********************************************************************************************************************/

/**********************************************************************************************************************
  GLOBAL FUNCTION PROTOTYPES
**********************************************************************************************************************/
/* \trace SPEC-629 */

#define PDUR_START_SEC_CODE
# include "MemMap.h"    /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
PduR_CanIfRxIndication
**********************************************************************************************************************/
/*!
\brief    The function is called by the CanIf to indicate the complete reception of a CanIf I-PDU.\n
          The PDU Router evaluates the CanIf I-PDU handle and identifies the destination(s) of the PDU.\n
          The call is routed to an upper IF module using the appropriate I-PDU handle of the destination layer.
\param    RxPduId           ID of the received CanIf I-PDU
\param    PduInfoPtr        Payload information of the received I-PDU (pointer to data and data length)
\return   none
\pre      PduR_Init() is executed successfully.
\context  This function can be called on interrupt and task level and has not to be interrupted by other\n
          PduR_CanIfRxIndication calls for the same CanIfRxPduId.
\trace    CREQ-1209
\trace    SPEC-666, SPEC-674, SPEC-1096, SPEC-2020085
\note     The function is called by CanIf.
**********************************************************************************************************************/
FUNC(void, PDUR_CODE) PduR_CanIfRxIndication(PduIdType RxPduId, P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) PduInfoPtr);

/* PduR_CanIfTxConfirmation API disabled due to disabled TxConfirmation in PduRBswModule settings. */









#define PDUR_STOP_SEC_CODE
# include "MemMap.h"    /* PRQA S 5087 */ /* MD_MSR_19.1 */

#endif  /* PDUR_CANIF_H */


/**********************************************************************************************************************
* GLOBAL MISRA / PCLINT JUSTIFICATION
*********************************************************************************************************************/
/*  module specific MISRA deviations:
    MD_PduR_3451:   MISRA rule: 8.8
    Reason:         The global identifier has been declared in more than one file. the function declaration has to be in
                    the PduR_<Module>.h. Affected APIs are CancelReceive, CancelTransmit and ChangeParameter.
    Risk:           no risk.
    Prevention:     To avoid a duplicate declaration uns the BSW-Module "use-Tag" flag.
*/

/**********************************************************************************************************************
  END OF FILE: PduR_CanIf.h
**********************************************************************************************************************/

