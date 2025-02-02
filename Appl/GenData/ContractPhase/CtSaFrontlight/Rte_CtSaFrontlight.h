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
 *          File:  Rte_CtSaFrontlight.h
 *        Config:  C:/nit-au-03/AUTOSAR_Exercises/AFS/MyECU.dpa
 *     SW-C Type:  CtSaFrontlight
 *  Generated at:  Sat Apr 13 16:30:44 2024
 *
 *     Generator:  MICROSAR RTE Generator Version 4.9.0
 *                 RTE Core Version 1.9.0
 *       License:  Unlimited license CBD0000000 for N/A
 *
 *   Description:  Application header file for SW-C <CtSaFrontlight> (Contract Phase)
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_CTSAFRONTLIGHT_H
# define _RTE_CTSAFRONTLIGHT_H

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

# define RTE_MULTI_INST_API

/* include files */

# include "Rte_CtSaFrontlight_Type.h"
# include "Rte_DataHandleType.h"


/**********************************************************************************************************************
 * Component Data Structures and Port Data Structures
 *********************************************************************************************************************/

struct Rte_PDS_CtSaFrontlight_PiLightPosition_P
{
  P2FUNC(Std_ReturnType, RTE_CODE, Write_DeLightLength) (uint8); /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2FUNC(Std_ReturnType, RTE_CODE, Write_DeLightPosition) (sint8); /* PRQA S 0850 */ /* MD_MSR_19.8 */
};

struct Rte_PDS_CtSaFrontlight_PiLightPosition_R
{
  P2FUNC(Std_ReturnType, RTE_CODE, Read_DeLightLength) (P2VAR(uint8, AUTOMATIC, RTE_CTSAFRONTLIGHT_APPL_VAR)); /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2FUNC(Std_ReturnType, RTE_CODE, Read_DeLightPosition) (P2VAR(sint8, AUTOMATIC, RTE_CTSAFRONTLIGHT_APPL_VAR)); /* PRQA S 0850 */ /* MD_MSR_19.8 */
};

struct Rte_CDS_CtSaFrontlight
{
  /* Port API section */
  struct Rte_PDS_CtSaFrontlight_PiLightPosition_P PpLightPositionOut;
  struct Rte_PDS_CtSaFrontlight_PiLightPosition_R PpLightPositionIn;
  /* Vendor specific section */
};

# define RTE_START_SEC_CONST_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern CONSTP2CONST(struct Rte_CDS_CtSaFrontlight, RTE_CONST, RTE_CONST) Rte_Inst_CtSaFrontlight; /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define RTE_STOP_SEC_CONST_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

typedef P2CONST(struct Rte_CDS_CtSaFrontlight, TYPEDEF, RTE_CONST) Rte_Instance;


/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

# define Rte_InitValue_PpLightPositionIn_DeLightLength (0U)
# define Rte_InitValue_PpLightPositionIn_DeLightPosition (0)
# define Rte_InitValue_PpLightPositionOut_DeLightLength (0U)
# define Rte_InitValue_PpLightPositionOut_DeLightPosition (0)



/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
# define Rte_Read_PpLightPositionIn_DeLightLength(self, data) ((self)->PpLightPositionIn.Read_DeLightLength(data)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# define Rte_Read_PpLightPositionIn_DeLightPosition(self, data) ((self)->PpLightPositionIn.Read_DeLightPosition(data)) /* PRQA S 3453 */ /* MD_MSR_19.7 */


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
# define Rte_Write_PpLightPositionOut_DeLightLength(self, data) ((self)->PpLightPositionOut.Write_DeLightLength(data)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# define Rte_Write_PpLightPositionOut_DeLightPosition(self, data) ((self)->PpLightPositionOut.Write_DeLightPosition(data)) /* PRQA S 3453 */ /* MD_MSR_19.7 */




# define CtSaFrontlight_START_SEC_CODE
# include "CtSaFrontlight_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 *
 * Runnable Entity Name: RCtSaFrontlight
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on DataReceivedEvent for DataElementPrototype <DeLightPosition> of PortPrototype <PpLightPositionIn>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_PpLightPositionIn_DeLightLength(Rte_Instance self, uint8 *data)
 *   Std_ReturnType Rte_Read_PpLightPositionIn_DeLightPosition(Rte_Instance self, sint8 *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_PpLightPositionOut_DeLightLength(Rte_Instance self, uint8 data)
 *   Std_ReturnType Rte_Write_PpLightPositionOut_DeLightPosition(Rte_Instance self, sint8 data)
 *
 *********************************************************************************************************************/

# define RTE_RUNNABLE_RCtSaFrontlight RCtSaFrontlight
FUNC(void, CtSaFrontlight_CODE) RCtSaFrontlight(Rte_Instance self); /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define CtSaFrontlight_STOP_SEC_CODE
# include "CtSaFrontlight_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_CTSAFRONTLIGHT_H */
