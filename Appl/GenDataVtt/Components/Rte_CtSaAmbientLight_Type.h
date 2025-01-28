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
 *          File:  Rte_CtSaAmbientLight_Type.h
 *        Config:  MyECU.dpa
 *   ECU-Project:  MyECU
 *
 *     Generator:  MICROSAR RTE Generator Version 4.9.0
 *                 RTE Core Version 1.9.0
 *       License:  Unlimited license CBD0000000 for N/A
 *
 *   Description:  Application types header file for SW-C <CtSaAmbientLight>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_CTSAAMBIENTLIGHT_TYPE_H
# define _RTE_CTSAAMBIENTLIGHT_TYPE_H

# ifdef __cplusplus
extern "C"
{
# endif /* __cplusplus */

# include "Rte_Type.h"

# ifndef RTE_CORE

# endif /* RTE_CORE */


/**********************************************************************************************************************
 * Definitions for Mode Management
 *********************************************************************************************************************/
# ifndef RTE_MODETYPE_BatteryMode
#  define RTE_MODETYPE_BatteryMode
typedef uint8 Rte_ModeType_BatteryMode;
# endif

# ifndef RTE_MODE_BatteryMode_BATTERY_HIGH
#  define RTE_MODE_BatteryMode_BATTERY_HIGH (0U)
# endif
# ifndef RTE_MODE_BatteryMode_BATTERY_LOW
#  define RTE_MODE_BatteryMode_BATTERY_LOW (1U)
# endif
# ifndef RTE_MODE_BatteryMode_BATTERY_MEDIUM
#  define RTE_MODE_BatteryMode_BATTERY_MEDIUM (2U)
# endif
# ifndef RTE_TRANSITION_BatteryMode
#  define RTE_TRANSITION_BatteryMode (3U)
# endif

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_CTSAAMBIENTLIGHT_TYPE_H */
