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
 *            Module: NvM
 *           Program: 
 *          Customer: N/A
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: 
 *    License Scope : The usage is restricted to CBD0000000_D30
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: NvM_Cfg.h
 *   Generation Time: 2024-04-06 16:46:40
 *           Project: MyECU - Version 1.0
 *          Delivery: CBD0000000_D30
 *      Tool Version: DaVinci Configurator  5.11.16 SP1
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * PROTECTION AGAINST MULTIPLE INCLUSION
 *********************************************************************************************************************/
/* public section - to be used by NvM itself and its users */
#if (!defined NVM_CFG_H_PUBLIC)
#define NVM_CFG_H_PUBLIC

/**********************************************************************************************************************
 * VERSION IDENTIFICATION
 *********************************************************************************************************************/
#define NVM_CFG_MAJOR_VERSION    (5u)
#define NVM_CFG_MINOR_VERSION    (3u)
#define NVM_CFG_PATCH_VERSION    (0u)

/**********************************************************************************************************************
 * NVM API TYPE INCLUDES
 *********************************************************************************************************************/
#include "Rte_NvM_Type.h"

#include "NvM_Types.h"

/**********************************************************************************************************************
 * API CFG TYPE DEFINITIONS
 *********************************************************************************************************************/
/* Type for an the additional published parameter Compiled Configuration ID
 * (see CompiledConfigurationId in NvM.h)
 */
/* Compiled Config Id Type */
/* PRQA S 0750 2 */ /* MD_MSR_18.4 */
typedef union
{
    uint16 Word_u16;
    uint8  Bytes_au8[2u];
} NvM_CompiledConfigIdType;

/**********************************************************************************************************************
 * CFG COMMON PARAMETER
 *********************************************************************************************************************/
/* --------------------  DEVELOPMENT / PRODUCTION MODE -------------------- */
/* switch between Debug- or Production-Mode */
#define NVM_DEV_ERROR_DETECT                  (STD_ON)

/* Preprocessor switch that is used in NvM_ReadAll() */
#define NVM_DYNAMIC_CONFIGURATION             (STD_OFF)

#define NVM_API_CONFIG_CLASS_1  (1u)
#define NVM_API_CONFIG_CLASS_2  (3u)
#define NVM_API_CONFIG_CLASS_3  (7u)

#define NVM_API_CONFIG_CLASS                  (NVM_API_CONFIG_CLASS_3)

#define NVM_JOB_PRIORISATION                  STD_OFF

/* define compiled Block ID */
#define NVM_COMPILED_CONFIG_ID                (1U)

/* switch for enablinig fast mode during multi block requests */
#define NVM_DRV_MODE_SWITCH                   (STD_OFF)

/* switch for enablinig polling mode and disabling notifications */
#define NVM_POLLING_MODE                      (STD_ON)

/* switch for enabling the internal buffer for Crc handling */
#define NVM_CRC_INT_BUFFER                    (STD_ON)

/* switch that is "ON" if dataset blocks are used */
#define NVM_USE_DATASETS                      (STD_ON)

/* switch that gives the user (EcuM) the possibility to time-out WriteAll cancellation */
#define NVM_KILL_WRITEALL_API                 (STD_ON)

/* enabled or disable the whole repair redundant blocks feature */
#define NVM_REPAIR_REDUNDANT_BLOCKS_API       (STD_OFF)

/* NVM does not need this macro. It is intended for underlying modules,
 * relying on its existence
 */
#define NVM_DATASET_SELECTION_BITS (4U)

/* block offset for DCM blocks */
#define NVM_DCM_BLOCK_OFFSET    0x8000u

/* returns corresponding DCM BlockId of an original NVRAM Block */
/* PRQA S 3453 1 */ /* MD_MSR_19.7 */
#define NvM_GetDcmBlockId(MyApplBlockId)    ((MyApplBlockId) | NVM_DCM_BLOCK_OFFSET)

/* BlockId's:
 * Note: The numbers of the following list must meet the configured blocks
 *       in the NvM_BlockDescriptorTable_at
 */

/* Alignment of the handles of all blocks */
/* Id 0 is reserved for multiblock calls */
/* Id 1 is reserved for config ID  */
#define NvMConf___MultiBlockRequest (0U) 
#define NvMConf_NvMBlockDescriptor_NvMConfigBlock (1UL) 
#define NvMConf_NvMBlockDescriptor_DemAdminDataBlock (2UL) 
#define NvMConf_NvMBlockDescriptor_CpApAFSControllerSnNvMPimPassingLaneF (3UL) 
#define NvMConf_NvMBlockDescriptor_DemStatusDataBlock (4UL) 
#define NvMConf_NvMBlockDescriptor_DemPrimaryDataBlock0 (5UL) 
#define NvMConf_NvMBlockDescriptor_DemPrimaryDataBlock1 (6UL) 
#define NvMConf_NvMBlockDescriptor_DemPrimaryDataBlock2 (7UL) 
#define NvMConf_NvMBlockDescriptor_DemPrimaryDataBlock3 (8UL) 
#define NvMConf_NvMBlockDescriptor_DemPrimaryDataBlock4 (9UL) 
#define NvMConf_NvMBlockDescriptor_DemPrimaryDataBlock5 (10UL) 
#define NvMConf_NvMBlockDescriptor_DemPrimaryDataBlock6 (11UL) 
#define NvMConf_NvMBlockDescriptor_DemPrimaryDataBlock7 (12UL) 


/* number of defined NV blocks */
#define NVM_TOTAL_NUM_OF_NVRAM_BLOCKS    (13UL)

/* version info api switch */
#define NVM_VERSION_INFO_API             (STD_OFF)

/* switch to enable the ram block status api */
#define NVM_SET_RAM_BLOCK_STATUS_API     (STD_ON)

/* CONST_DESCRIPTOR_TABLE contains all block relevant data,
 * including the compiled config ID
 */
#define NVM_START_SEC_CONST_DESCRIPTOR_TABLE
#include "MemMap.h"

/* Additional published parameter because e.g. in case of validate all RAM
 * Blocks it is nice to know the number of Blocks. But take care: this number
 * of Blocks includes Block 0 and Block 1, which are the MultiBlock and the
 * Configuration Block - user Blocks start wiht index 2!
 */
extern CONST(uint16, NVM_PUBLIC_CONST) NvM_NoOfBlockIds_t;

/* Additional published parameter because in case of a clear EEPROM, it is
 * necessary, to write the Configuration Block containing this Compiled
 * Configuration ID to EEPROM
 */
/* Compiled Configuration ID as defined in NvM_Cfg.c */
/* PRQA S 0759 1 */ /* MD_MSR_18.4 */
extern CONST(NvM_CompiledConfigIdType, NVM_PUBLIC_CONST) NvM_CompiledConfigId_t;

#define NVM_STOP_SEC_CONST_DESCRIPTOR_TABLE
#include "MemMap.h"

/* Component define block (available, if EcuC module is active, otherwise only NVM_DUMMY_STATEMENTs are defined*/
#ifndef NVM_USE_DUMMY_FUNCTIONS
#define NVM_USE_DUMMY_FUNCTIONS STD_OFF /* /MICROSAR/VTT/VTTEcuC/EcucGeneral/DummyFunction */
#endif
#ifndef NVM_USE_DUMMY_STATEMENT
#define NVM_USE_DUMMY_STATEMENT STD_OFF /* /MICROSAR/VTT/VTTEcuC/EcucGeneral/DummyStatement */
#endif
#ifndef NVM_DUMMY_STATEMENT
#define NVM_DUMMY_STATEMENT(v)  /* PRQA S 3453 */ /* MD_MSR_19.7 */  /* /MICROSAR/VTT/VTTEcuC/EcucGeneral/DummyStatementKind */
#endif
#ifndef NVM_DUMMY_STATEMENT_CONST
#define NVM_DUMMY_STATEMENT_CONST(v)  /* PRQA S 3453 */ /* MD_MSR_19.7 */  /* /MICROSAR/VTT/VTTEcuC/EcucGeneral/DummyStatementKind */
#endif
#ifndef NVM_ATOMIC_BIT_ACCESS_IN_BITFIELD
#define NVM_ATOMIC_BIT_ACCESS_IN_BITFIELD STD_OFF /* /MICROSAR/VTT/VTTEcuC/EcucGeneral/AtomicBitAccessInBitfield */
#endif
#ifndef NVM_ATOMIC_VARIABLE_ACCESS
#define NVM_ATOMIC_VARIABLE_ACCESS 32U /* /MICROSAR/VTT/VTTEcuC/EcucGeneral/AtomicVariableAccess */
#endif
#ifndef NVM_PROCESSOR_CANOEEMU
#define NVM_PROCESSOR_CANOEEMU
#endif
#ifndef NVM_COMP_ANSI
#define NVM_COMP_ANSI
#endif
#ifndef NVM_GEN_GENERATOR_MSR
#define NVM_GEN_GENERATOR_MSR
#endif
#ifndef NVM_CPUTYPE_BITORDER_LSB2MSB
#define NVM_CPUTYPE_BITORDER_LSB2MSB /* /MICROSAR/VTT/VTTEcuC/EcucGeneral/BitOrder */
#endif
#ifndef NVM_CONFIGURATION_VARIANT_PRECOMPILE
#define NVM_CONFIGURATION_VARIANT_PRECOMPILE 1
#endif
#ifndef NVM_CONFIGURATION_VARIANT_LINKTIME
#define NVM_CONFIGURATION_VARIANT_LINKTIME 2
#endif
#ifndef NVM_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE
#define NVM_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE 3
#endif
#ifndef NVM_CONFIGURATION_VARIANT
#define NVM_CONFIGURATION_VARIANT NVM_CONFIGURATION_VARIANT_PRECOMPILE
#endif
#ifndef NVM_POSTBUILD_VARIANT_SUPPORT
#define NVM_POSTBUILD_VARIANT_SUPPORT STD_OFF
#endif


/* ---- end public configuration section ---------------------------------- */

#endif /* NVM_CFG_H_PUBLIC */

/*---- End of File ---------------------------------------------------------*/

