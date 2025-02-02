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
 *            Module: VTTCntrl
 *           Program: 
 *          Customer: N/A
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: 
 *    License Scope : The usage is restricted to CBD0000000_D30
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: VttCntrl_SysVar_Cfg.c
 *   Generation Time: 2024-04-03 15:25:55
 *           Project: MyECU - Version 1.0
 *          Delivery: CBD0000000_D30
 *      Tool Version: DaVinci Configurator  5.11.16 SP1
 *
 *
 *********************************************************************************************************************/

# define VTTSYSVAR_CFG_SOURCE

/**********************************************************************************************************************
*  INCLUDES
*********************************************************************************************************************/
# include "VttCntrl_SysVar.h"
# include "VttCntrl_Base.h"
# include "CANoeAPI.h"
# include "VttCntrl_SysVar_Cbk.h"


/**********************************************************************************************************************
*  PRAGMAS
*********************************************************************************************************************/
/* The following pragmas ensure that all variables of this module are places in memory that is not cleared during a
 * simulated ECU reset/poweron */
#pragma bss_seg()
#pragma data_seg()

/**********************************************************************************************************************
*  VERSION CHECK
*********************************************************************************************************************/
/* Check the version of VttCntrl_SysVar header file */
#if (  (VTTCNTRL_SYSVAR_MAJOR_VERSION != (0x03u)) \
    || (VTTCNTRL_SYSVAR_MINOR_VERSION != (0x00u)) \
    || (VTTCNTRL_SYSVAR_PATCH_VERSION != (0x04u)) )
# error "Vendor specific version numbers of VttCntrl_SysVar_Cfg.c and VttCntrl_SysVar.h are inconsistent"
#endif

/* Check the version of the configuration header file */
#if (  (VTTSYSVAR_CFG_MAJOR_VERSION != (0x13u)) \
    || (VTTSYSVAR_CFG_MINOR_VERSION != (0x00u)) \
    || (VTTSYSVAR_CFG_PATCH_VERSION != (0x00u)))
  #error "Version numbers of VttCntrl_SysVar_Cfg.c and VttCntrl_SysVar_Cfg.h are inconsistent!"
#endif

/* Check the version of the VttCntrl_Base header file */
#if (  (VTTCNTRL_SW_MAJOR_VERSION != (0x04)) \
    || (VTTCNTRL_SW_MINOR_VERSION != (0x00)) \
    || (VTTCNTRL_SW_PATCH_VERSION != (0x00)) )
  #error "Vendor specific version numbers of VttCntrl_SysVar_Cfg.c and VttCntrl_Base.h are inconsistent"
#endif


/**********************************************************************************************************************
*  LOCAL FUNCTION PROTOTYPES
**********************************************************************************************************************/



/**********************************************************************************************************************
*  LOCAL DATA TYPES AND STRUCTURES
**********************************************************************************************************************/

extern uint64 VttSysVar_NumPendingChanges; /* Number of Channel IDs with a pending change. */

#if VTTSYSVAR_CHANNELS > 0
extern uint64 VttSysVar_PendingChanges[VTTSYSVAR_CHANNELS]; /* List of IDs. Contains IDs of channels that have a pending change. */
#endif

#if VTTSYSVAR_CHANNELS > 0
VttSysVar_CntrlType VttSysVar_Channel_Cfg[VTTSYSVAR_CHANNELS] =
{
};
#endif


/* OnLoad */
void VttSysVar_OnLoad(void)
{
}

/* Read/Write function for types */


/* Notification forwarder for each system variable */


/**********************************************************************************************************************
*  END OF FILE: VttCntrl_SysVar_Cfg.c
*********************************************************************************************************************/


