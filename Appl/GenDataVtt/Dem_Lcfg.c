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
 *            Module: Dem
 *           Program: 
 *          Customer: N/A
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: 
 *    License Scope : The usage is restricted to CBD0000000_D30
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: Dem_Lcfg.c
 *   Generation Time: 2024-04-04 17:05:43
 *           Project: MyECU - Version 1.0
 *          Delivery: CBD0000000_D30
 *      Tool Version: DaVinci Configurator  5.11.16 SP1
 *
 *
 *********************************************************************************************************************/



/* configuration, interrupt handling implementations differ from the
 * source identification define used here. The naming
 * schemes for those files can be taken from this list:
 *
 * Dem.c:         DEM_SOURCE
 * Dem_Lcfg.c:    DEM_LCFG_SOURCE
 * Dem_PBcfg.c:   DEM_PBCFG_SOURCE */
#define DEM_LCFG_SOURCE


/**********************************************************************************************************************
  MISRA JUSTIFICATIONS
**********************************************************************************************************************/

/* PRQA S 0828 EOF */ /* MD_MSR_1.1_828 */                                      /* Maximum '#if...' nesting exceeds 8 levels - program is non-conforming -- caused by #include'd files. */
/* PRQA S 0857 EOF */ /* MD_MSR_1.1_857 */                                      /* Number of macro definitions exceeds 1024 - program is non-conforming -- caused by #include'd files. */
/* PRQA S 0779 EOF */ /* MD_DEM_5.1 */                                          /* Identifier does not differ in 32 significant characters -- caused by Autosar algorithm for unique symbolic names. */
/* PRQA S 0612 EOF */ /* MD_DEM_1.1_612 */                                      /* The size of an object exceeds 32767 bytes - program is non-conforming -- caused by large user configration. */


/**********************************************************************************************************************
  INCLUDES
**********************************************************************************************************************/

#include "Dem.h"
#if (DEM_CFG_USE_NVM == STD_ON)
# include "NvM.h"                                                           /* get: symbolic names for NvM block IDs */
#endif
#if (DEM_CFG_SUPPORT_J1939 == STD_ON)
# include "J1939Nm.h"                                                       /* get: symbolic names for J1939Nm node IDs */
#endif
#if (DEM_CFG_USE_RTE == STD_ON)
/* DEM used with RTE */
# include "Rte_Dem.h"
#else
#endif


/**********************************************************************************************************************
  LOCAL CONSTANT MACROS
**********************************************************************************************************************/

/**********************************************************************************************************************
  LOCAL FUNCTION MACROS
**********************************************************************************************************************/

/**********************************************************************************************************************
  LOCAL DATA TYPES AND STRUCTURES
**********************************************************************************************************************/

/**********************************************************************************************************************
  LOCAL DATA PROTOTYPES
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: LOCAL DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: LOCAL DATA TYPES AND STRUCTURES
**********************************************************************************************************************/



/**********************************************************************************************************************
  LOCAL DATA
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: LOCAL DATA
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: LOCAL DATA
**********************************************************************************************************************/



/**********************************************************************************************************************
  GLOBAL DATA
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL DATA
**********************************************************************************************************************/
/**********************************************************************************************************************
  Dem_C_CycleIdTable
**********************************************************************************************************************/
/** 
  \var    Dem_C_CycleIdTable
  \details
  Element         Description
  UsedForAging    DemOperationCycle is target of any DemEventParameter/DemEventClass/DemAgingCycleRef
  OpCycleType     DemOperationCycleType of the DemOperationCycle: [DEM_CFG_OPCYC_IGNITION, DEM_CFG_OPCYC_OBD_DCY, DEM_CFG_OPCYC_OTHER, DEM_CFG_OPCYC_POWER, DEM_CFG_OPCYC_TIME, DEM_CFG_OPCYC_WARMUP, DEM_CFG_OPCYC_IGNITION_HYBRID, DEM_CFG_OPCYC_AGING]
*/ 
#define DEM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(Dem_C_CycleIdTableType, DEM_CONST) Dem_C_CycleIdTable[2] = {
    /* Index    UsedForAging  OpCycleType                   Comment */
  { /*     0 */         TRUE, DEM_CFG_OPCYC_IGNITION },  /* [DemConf_DemOperationCycle_IgnitionCycle] */
  { /*     1 */        FALSE, DEM_CFG_OPCYC_POWER    }   /* [DemConf_DemOperationCycle_PowerCycle] */
};
#define DEM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Dem_C_DataCollectionTable
**********************************************************************************************************************/
/** 
  \var    Dem_C_DataCollectionTable
  \details
  Element                                Description
  CollectionSize                     
  DataElementTableCol2ElmtIndEndIdx      the end index of the 0:n relation pointing to Dem_C_DataElementTableCol2ElmtInd
  DataElementTableCol2ElmtIndStartIdx    the start index of the 0:n relation pointing to Dem_C_DataElementTableCol2ElmtInd
  IdNumber                           
  MaskedBits                             contains bitcoded the boolean data of Dem_C_DataElementTableCol2ElmtIndUsedOfDataCollectionTable, Dem_C_UpdateOfDataCollectionTable
  StorageKind                        
*/ 
#define DEM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(Dem_C_DataCollectionTableType, DEM_CONST) Dem_C_DataCollectionTable[3] = {
    /* Index    CollectionSize  DataElementTableCol2ElmtIndEndIdx                                DataElementTableCol2ElmtIndStartIdx                                IdNumber  MaskedBits  StorageKind                     Referable Keys */
  { /*     0 */             0U, DEM_C_NO_DATAELEMENTTABLECOL2ELMTINDENDIDXOFDATACOLLECTIONTABLE, DEM_C_NO_DATAELEMENTTABLECOL2ELMTINDSTARTIDXOFDATACOLLECTIONTABLE,  0x0000U,      0x00U, DEM_CFG_EREC_TYPE_GLOBAL },  /* [#NoDataCollectionConfigured] */
  { /*     1 */             4U,                                                              1U,                                                                0U,  0x0002U,      0x03U, DEM_CFG_EREC_TYPE_USER   },  /* [#EdrBatteryValue, Ext:ExtendedDataClass_4f5344cd] */
  { /*     2 */             4U,                                                              2U,                                                                1U,  0x0001U,      0x03U, DEM_CFG_EREC_TYPE_USER   }   /* [#EdrOccurrenceCounter, Ext:ExtendedDataClass_4f5344cd] */
};
#define DEM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Dem_C_DataCollectionTableEdr2CollInd
**********************************************************************************************************************/
/** 
  \var    Dem_C_DataCollectionTableEdr2CollInd
  \brief  the indexes of the 1:1 sorted relation pointing to Dem_C_DataCollectionTable
*/ 
#define DEM_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(Dem_C_DataCollectionTableEdr2CollIndType, DEM_CONST) Dem_C_DataCollectionTableEdr2CollInd[2] = {
  /* Index    DataCollectionTableEdr2CollInd      Referable Keys */
  /*     0 */                             2U,  /* [Ext:ExtendedDataClass_4f5344cd] */
  /*     1 */                             1U   /* [Ext:ExtendedDataClass_4f5344cd] */
};
#define DEM_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Dem_C_DataElementTable
**********************************************************************************************************************/
/** 
  \var    Dem_C_DataElementTable
  \details
  Element         Description
  ElementKind     see #define DEM_CFG_DATA_FROM_... to interpret results
  ElementSize     Size of data element in Byte.
  ReadDataFunc    C-function for getting the data. Its signature depends on ElementKind: With value 28U or 30U use: Std_ReturnType (*)(uint8* Buffer); With value 29U or 31U use: Std_ReturnType (*)(uint8* Buffer, uint16 EventId);.
*/ 
#define DEM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(Dem_C_DataElementTableType, DEM_CONST) Dem_C_DataElementTable[3] = {
    /* Index    ElementKind  ElementSize  ReadDataFunc                                                                                                                       Referable Keys */
  { /*     0 */         32U,          0U,  (Dem_ReadDataFPtrType) /* PRQA S 0313 */ /* MD_DEM_11.1 */ NULL_PTR                                                        },  /* [#NoDataElementConfigured] */
  { /*     1 */         28U,          4U,  (Dem_ReadDataFPtrType) /* PRQA S 0313 */ /* MD_DEM_11.1 */ Rte_Call_CBReadData_OccurrenceCounter_OccurenceCounter_ReadData },  /* [#OccurrenceCounter_OccurenceCounter, EdrOccurrenceCounter] */
  { /*     2 */         28U,          4U,  (Dem_ReadDataFPtrType) /* PRQA S 0313 */ /* MD_DEM_11.1 */ Rte_Call_CBReadData_BatteryValue_BatteryValue_ReadData          }   /* [#BatteryValue_BatteryValue, EdrBatteryValue] */
};
#define DEM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Dem_C_DataElementTableCol2ElmtInd
**********************************************************************************************************************/
/** 
  \var    Dem_C_DataElementTableCol2ElmtInd
  \brief  the indexes of the 1:1 sorted relation pointing to Dem_C_DataElementTable
*/ 
#define DEM_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(Dem_C_DataElementTableCol2ElmtIndType, DEM_CONST) Dem_C_DataElementTableCol2ElmtInd[2] = {
  /* Index    DataElementTableCol2ElmtInd      Referable Keys */
  /*     0 */                          2U,  /* [EdrBatteryValue] */
  /*     1 */                          1U   /* [EdrOccurrenceCounter] */
};
#define DEM_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Dem_C_DebounceTable
**********************************************************************************************************************/
/** 
  \var    Dem_C_DebounceTable
  \details
  Element                   Description
  DecrementStepSize         (-1) * DemDebounceCounterDecrementStepSize of the DemEventParameter/DemEventClass/DemDebounceAlgorithmClass/DemDebounceCounterBased
  FailedThreshold           DemDebounceCounterFailedThreshold of the DemEventParameter/DemEventClass/DemDebounceAlgorithmClass/DemDebounceCounterBased
  IncrementStepSize         DemDebounceCounterIncrementStepSize of the DemEventParameter/DemEventClass/DemDebounceAlgorithmClass/DemDebounceCounterBased
  PassedThreshold           DemDebounceCounterPassedThreshold of the DemEventParameter/DemEventClass/DemDebounceAlgorithmClass/DemDebounceCounterBased
  EventDebounceAlgorithm    Used DemEventParameter/DemEventClass/DemDebounceAlgorithmClass
  MaskedBits                contains bitcoded the boolean data of Dem_C_DebounceContinuousOfDebounceTable, Dem_C_EventDebounceBehaviorOfDebounceTable, Dem_C_JumpDownOfDebounceTable, Dem_C_JumpUpOfDebounceTable, Dem_C_StorageOfDebounceTable
*/ 
#define DEM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(Dem_C_DebounceTableType, DEM_CONST) Dem_C_DebounceTable[3] = {
    /* Index    DecrementStepSize  FailedThreshold  IncrementStepSize  PassedThreshold  EventDebounceAlgorithm                                                    MaskedBits        Referable Keys */
  { /*     0 */                -1,             127,                 1,            -128, DEM_C_DEM_CFG_DEBOUNCETYPE_COUNTER_EVENTDEBOUNCEALGORITHMOFDEBOUNCETABLE,      0x02U },  /* [DTC_0x000002] */
  { /*     1 */                -1,             127,                 1,            -128, DEM_C_DEM_CFG_DEBOUNCETYPE_COUNTER_EVENTDEBOUNCEALGORITHMOFDEBOUNCETABLE,      0x06U },  /* [AutoCreatedDemEvent_EcuMConfiguration_ECUM_E_ALL_RUN_REQUESTS_KILLED, AutoCreatedDemEvent_EcuMConfiguration_ECUM_E_CONFIGURATION_DATA_INCONSISTENT, AutoCreatedDemEvent_EcuMConfiguration_ECUM_E_IMPROPER_CALLER, AutoCreatedDemEvent_EcuMConfiguration_ECUM_E_RAM_CHECK_FAILED, AutoCreatedDemEvent_NVM_E_INTEGRITY_FAILED, AutoCreatedDemEvent_NVM_E_LOSS_OF_REDUNDANCY, AutoCreatedDemEvent_NVM_E_QUEUE_OVERFLOW, AutoCreatedDemEvent_NVM_E_REQ_FAILED, AutoCreatedDemEvent_NVM_E_VERIFY_FAILED, AutoCreatedDemEvent_NVM_E_WRITE_PROTECTED, AutoCreatedDemEvent_NVM_E_WRONG_BLOCK_ID] */
  { /*     2 */                 0,               0,                 0,               0, DEM_C_DEM_CFG_DEBOUNCETYPE_INVALID_EVENTDEBOUNCEALGORITHMOFDEBOUNCETABLE,      0x00U }   /* [#EVENT_INVALID] */
};
#define DEM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Dem_C_DtcTable
**********************************************************************************************************************/
/** 
  \var    Dem_C_DtcTable
  \details
  Element    Description
  UdsDtc 
*/ 
#define DEM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(Dem_C_DtcTableType, DEM_CONST) Dem_C_DtcTable[2] = {
    /* Index    UdsDtc              Referable Keys */
  { /*     0 */ 0x00FFFFFFUL },  /* [#NoUdsDtcConfigured, #NoObdDtcConfigured, #NoJ1939DtcConfigured] */
  { /*     1 */ 0x00000002UL }   /* [DTCClass_DTC_0x000002] */
};
#define DEM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Dem_C_EventTable
**********************************************************************************************************************/
/** 
  \var    Dem_C_EventTable
  \details
  Element                        Description
  AgingCycleId                   DemOperationCycle (ID) referenced by DemEventParameter/DemEventClass/DemAgingCycleRef
  DebounceTableIdx               the index of the 1:1 relation pointing to Dem_C_DebounceTable
  EventKind                      DemEventKind of the DemEventParameter
  FreezeFrameNumTableEndIdx      the end index of the 0:n relation pointing to Dem_C_FreezeFrameNumTable
  FreezeFrameNumTableStartIdx    the start index of the 0:n relation pointing to Dem_C_FreezeFrameNumTable
  OperationCycleId               DemOperationCycle (ID) referenced by DemEventParameter/DemEventClass/DemOperationCycleRef
*/ 
#define DEM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(Dem_C_EventTableType, DEM_CONST) Dem_C_EventTable[13] = {
    /* Index    AgingCycleId                             DebounceTableIdx  EventKind                                       FreezeFrameNumTableEndIdx                       FreezeFrameNumTableStartIdx                       OperationCycleId                               Referable Keys */
  { /*     0 */ /*no AgingCycle*/ 2U                   ,               2U, DEM_C_DEM_EVENT_KIND_BSW_EVENTKINDOFEVENTTABLE, DEM_C_NO_FREEZEFRAMENUMTABLEENDIDXOFEVENTTABLE, DEM_C_NO_FREEZEFRAMENUMTABLESTARTIDXOFEVENTTABLE, /*no OperationCycle*/ 2U                },  /* [#EVENT_INVALID] */
  { /*     1 */ /*no AgingCycle*/ 2U                   ,               1U, DEM_C_DEM_EVENT_KIND_BSW_EVENTKINDOFEVENTTABLE, DEM_C_NO_FREEZEFRAMENUMTABLEENDIDXOFEVENTTABLE, DEM_C_NO_FREEZEFRAMENUMTABLESTARTIDXOFEVENTTABLE, DemConf_DemOperationCycle_PowerCycle    },  /* [AutoCreatedDemEvent_NVM_E_INTEGRITY_FAILED] */
  { /*     2 */ DemConf_DemOperationCycle_IgnitionCycle,               0U, DEM_C_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,                                             1U,                                               0U, DemConf_DemOperationCycle_IgnitionCycle },  /* [DTC_0x000002] */
  { /*     3 */ /*no AgingCycle*/ 2U                   ,               1U, DEM_C_DEM_EVENT_KIND_BSW_EVENTKINDOFEVENTTABLE, DEM_C_NO_FREEZEFRAMENUMTABLEENDIDXOFEVENTTABLE, DEM_C_NO_FREEZEFRAMENUMTABLESTARTIDXOFEVENTTABLE, DemConf_DemOperationCycle_PowerCycle    },  /* [AutoCreatedDemEvent_NVM_E_LOSS_OF_REDUNDANCY] */
  { /*     4 */ /*no AgingCycle*/ 2U                   ,               1U, DEM_C_DEM_EVENT_KIND_BSW_EVENTKINDOFEVENTTABLE, DEM_C_NO_FREEZEFRAMENUMTABLEENDIDXOFEVENTTABLE, DEM_C_NO_FREEZEFRAMENUMTABLESTARTIDXOFEVENTTABLE, DemConf_DemOperationCycle_PowerCycle    },  /* [AutoCreatedDemEvent_NVM_E_QUEUE_OVERFLOW] */
  { /*     5 */ /*no AgingCycle*/ 2U                   ,               1U, DEM_C_DEM_EVENT_KIND_BSW_EVENTKINDOFEVENTTABLE, DEM_C_NO_FREEZEFRAMENUMTABLEENDIDXOFEVENTTABLE, DEM_C_NO_FREEZEFRAMENUMTABLESTARTIDXOFEVENTTABLE, DemConf_DemOperationCycle_PowerCycle    },  /* [AutoCreatedDemEvent_NVM_E_REQ_FAILED] */
  { /*     6 */ /*no AgingCycle*/ 2U                   ,               1U, DEM_C_DEM_EVENT_KIND_BSW_EVENTKINDOFEVENTTABLE, DEM_C_NO_FREEZEFRAMENUMTABLEENDIDXOFEVENTTABLE, DEM_C_NO_FREEZEFRAMENUMTABLESTARTIDXOFEVENTTABLE, DemConf_DemOperationCycle_PowerCycle    },  /* [AutoCreatedDemEvent_NVM_E_VERIFY_FAILED] */
  { /*     7 */ /*no AgingCycle*/ 2U                   ,               1U, DEM_C_DEM_EVENT_KIND_BSW_EVENTKINDOFEVENTTABLE, DEM_C_NO_FREEZEFRAMENUMTABLEENDIDXOFEVENTTABLE, DEM_C_NO_FREEZEFRAMENUMTABLESTARTIDXOFEVENTTABLE, DemConf_DemOperationCycle_PowerCycle    },  /* [AutoCreatedDemEvent_NVM_E_WRITE_PROTECTED] */
  { /*     8 */ /*no AgingCycle*/ 2U                   ,               1U, DEM_C_DEM_EVENT_KIND_BSW_EVENTKINDOFEVENTTABLE, DEM_C_NO_FREEZEFRAMENUMTABLEENDIDXOFEVENTTABLE, DEM_C_NO_FREEZEFRAMENUMTABLESTARTIDXOFEVENTTABLE, DemConf_DemOperationCycle_PowerCycle    },  /* [AutoCreatedDemEvent_NVM_E_WRONG_BLOCK_ID] */
  { /*     9 */ /*no AgingCycle*/ 2U                   ,               1U, DEM_C_DEM_EVENT_KIND_BSW_EVENTKINDOFEVENTTABLE, DEM_C_NO_FREEZEFRAMENUMTABLEENDIDXOFEVENTTABLE, DEM_C_NO_FREEZEFRAMENUMTABLESTARTIDXOFEVENTTABLE, DemConf_DemOperationCycle_PowerCycle    },  /* [AutoCreatedDemEvent_EcuMConfiguration_ECUM_E_CONFIGURATION_DATA_INCONSISTENT] */
  { /*    10 */ /*no AgingCycle*/ 2U                   ,               1U, DEM_C_DEM_EVENT_KIND_BSW_EVENTKINDOFEVENTTABLE, DEM_C_NO_FREEZEFRAMENUMTABLEENDIDXOFEVENTTABLE, DEM_C_NO_FREEZEFRAMENUMTABLESTARTIDXOFEVENTTABLE, DemConf_DemOperationCycle_PowerCycle    },  /* [AutoCreatedDemEvent_EcuMConfiguration_ECUM_E_RAM_CHECK_FAILED] */
  { /*    11 */ /*no AgingCycle*/ 2U                   ,               1U, DEM_C_DEM_EVENT_KIND_BSW_EVENTKINDOFEVENTTABLE, DEM_C_NO_FREEZEFRAMENUMTABLEENDIDXOFEVENTTABLE, DEM_C_NO_FREEZEFRAMENUMTABLESTARTIDXOFEVENTTABLE, DemConf_DemOperationCycle_PowerCycle    },  /* [AutoCreatedDemEvent_EcuMConfiguration_ECUM_E_ALL_RUN_REQUESTS_KILLED] */
  { /*    12 */ /*no AgingCycle*/ 2U                   ,               1U, DEM_C_DEM_EVENT_KIND_BSW_EVENTKINDOFEVENTTABLE, DEM_C_NO_FREEZEFRAMENUMTABLEENDIDXOFEVENTTABLE, DEM_C_NO_FREEZEFRAMENUMTABLESTARTIDXOFEVENTTABLE, DemConf_DemOperationCycle_PowerCycle    }   /* [AutoCreatedDemEvent_EcuMConfiguration_ECUM_E_IMPROPER_CALLER] */
};
#define DEM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Dem_C_ExtendedDataTable
**********************************************************************************************************************/
/** 
  \var    Dem_C_ExtendedDataTable
  \details
  Element                                   Description
  DataCollectionTableEdr2CollIndEndIdx      the end index of the 0:n relation pointing to Dem_C_DataCollectionTableEdr2CollInd
  DataCollectionTableEdr2CollIndStartIdx    the start index of the 0:n relation pointing to Dem_C_DataCollectionTableEdr2CollInd
  MaxRecordSize                         
*/ 
#define DEM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(Dem_C_ExtendedDataTableType, DEM_CONST) Dem_C_ExtendedDataTable[2] = {
    /* Index    DataCollectionTableEdr2CollIndEndIdx                              DataCollectionTableEdr2CollIndStartIdx                              MaxRecordSize        Referable Keys */
  { /*     0 */ DEM_C_NO_DATACOLLECTIONTABLEEDR2COLLINDENDIDXOFEXTENDEDDATATABLE, DEM_C_NO_DATACOLLECTIONTABLEEDR2COLLINDSTARTIDXOFEXTENDEDDATATABLE,            0U },  /* [#NoExtendedDataRecordConfigured, #EVENT_INVALID, AutoCreatedDemEvent_NVM_E_INTEGRITY_FAILED, AutoCreatedDemEvent_NVM_E_LOSS_OF_REDUNDANCY, AutoCreatedDemEvent_NVM_E_QUEUE_OVERFLOW, AutoCreatedDemEvent_NVM_E_REQ_FAILED, AutoCreatedDemEvent_NVM_E_VERIFY_FAILED, AutoCreatedDemEvent_NVM_E_WRITE_PROTECTED, AutoCreatedDemEvent_NVM_E_WRONG_BLOCK_ID, AutoCreatedDemEvent_EcuMConfiguration_ECUM_E_CONFIGURATION_DATA_INCONSISTENT, AutoCreatedDemEvent_EcuMConfiguration_ECUM_E_RAM_CHECK_FAILED, AutoCreatedDemEvent_EcuMConfiguration_ECUM_E_ALL_RUN_REQUESTS_KILLED, AutoCreatedDemEvent_EcuMConfiguration_ECUM_E_IMPROPER_CALLER] */
  { /*     1 */                                                               2U,                                                                 0U,            4U }   /* [#ExtendedDataClass_4f5344cd, DTC_0x000002] */
};
#define DEM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Dem_C_MemoryBlockId
**********************************************************************************************************************/
/** 
  \var    Dem_C_MemoryBlockId
  \brief  The array contains these items: Admin, Status, 8 * Primary
*/ 
#define DEM_START_SEC_CONST_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(Dem_C_MemoryBlockIdType, DEM_CONST) Dem_C_MemoryBlockId[10] = {
  /* Index    MemoryBlockId                                                          Referable Keys */
  /*     0 */NvMConf_NvMBlockDescriptor_DemAdminDataBlock /*NvMBlockId=2*/     ,  /* [Dem_AdminData] */
  /*     1 */NvMConf_NvMBlockDescriptor_DemStatusDataBlock /*NvMBlockId=4*/    ,  /* [Dem_StatusData] */
  /*     2 */NvMConf_NvMBlockDescriptor_DemPrimaryDataBlock0 /*NvMBlockId=5*/  ,  /* [Dem_PrimaryEntry0] */
  /*     3 */NvMConf_NvMBlockDescriptor_DemPrimaryDataBlock1 /*NvMBlockId=6*/  ,  /* [Dem_PrimaryEntry1] */
  /*     4 */NvMConf_NvMBlockDescriptor_DemPrimaryDataBlock2 /*NvMBlockId=7*/  ,  /* [Dem_PrimaryEntry2] */
  /*     5 */NvMConf_NvMBlockDescriptor_DemPrimaryDataBlock3 /*NvMBlockId=8*/  ,  /* [Dem_PrimaryEntry3] */
  /*     6 */NvMConf_NvMBlockDescriptor_DemPrimaryDataBlock4 /*NvMBlockId=9*/  ,  /* [Dem_PrimaryEntry4] */
  /*     7 */NvMConf_NvMBlockDescriptor_DemPrimaryDataBlock5 /*NvMBlockId=10*/ ,  /* [Dem_PrimaryEntry5] */
  /*     8 */NvMConf_NvMBlockDescriptor_DemPrimaryDataBlock6 /*NvMBlockId=11*/ ,  /* [Dem_PrimaryEntry6] */
  /*     9 */NvMConf_NvMBlockDescriptor_DemPrimaryDataBlock7 /*NvMBlockId=12*/    /* [Dem_PrimaryEntry7] */
};
#define DEM_STOP_SEC_CONST_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Dem_C_MemoryDataPtr
**********************************************************************************************************************/
/** 
  \var    Dem_C_MemoryDataPtr
  \brief  The array contains these items: Admin, Status, 8 * Primary
*/ 
#define DEM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(Dem_NvDataPtrType, DEM_CONST) Dem_C_MemoryDataPtr[10] = {
  /* Index    MemoryDataPtr                                                                                  Referable Keys */
  /*     0 */(Dem_NvDataPtrType) &Dem_C_GetNvAdminData()        /* PRQA S 0310 */ /* MD_DEM_11.4_nvm */,  /* [Dem_AdminData] */
  /*     1 */(Dem_NvDataPtrType) &Dem_C_GetNvEventData()        /* PRQA S 0310 */ /* MD_DEM_11.4_nvm */,  /* [Dem_StatusData] */
  /*     2 */(Dem_NvDataPtrType) &Dem_C_GetNvPrimaryEntry_0()   /* PRQA S 0310 */ /* MD_DEM_11.4_nvm */,  /* [Dem_PrimaryEntry0] */
  /*     3 */(Dem_NvDataPtrType) &Dem_C_GetNvPrimaryEntry_1()   /* PRQA S 0310 */ /* MD_DEM_11.4_nvm */,  /* [Dem_PrimaryEntry1] */
  /*     4 */(Dem_NvDataPtrType) &Dem_C_GetNvPrimaryEntry_2()   /* PRQA S 0310 */ /* MD_DEM_11.4_nvm */,  /* [Dem_PrimaryEntry2] */
  /*     5 */(Dem_NvDataPtrType) &Dem_C_GetNvPrimaryEntry_3()   /* PRQA S 0310 */ /* MD_DEM_11.4_nvm */,  /* [Dem_PrimaryEntry3] */
  /*     6 */(Dem_NvDataPtrType) &Dem_C_GetNvPrimaryEntry_4()   /* PRQA S 0310 */ /* MD_DEM_11.4_nvm */,  /* [Dem_PrimaryEntry4] */
  /*     7 */(Dem_NvDataPtrType) &Dem_C_GetNvPrimaryEntry_5()   /* PRQA S 0310 */ /* MD_DEM_11.4_nvm */,  /* [Dem_PrimaryEntry5] */
  /*     8 */(Dem_NvDataPtrType) &Dem_C_GetNvPrimaryEntry_6()   /* PRQA S 0310 */ /* MD_DEM_11.4_nvm */,  /* [Dem_PrimaryEntry6] */
  /*     9 */(Dem_NvDataPtrType) &Dem_C_GetNvPrimaryEntry_7()   /* PRQA S 0310 */ /* MD_DEM_11.4_nvm */   /* [Dem_PrimaryEntry7] */
};
#define DEM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Dem_C_MemoryEntryInit
**********************************************************************************************************************/
#define DEM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(Dem_Cfg_PrimaryEntryType, DEM_CONST) Dem_C_MemoryEntryInit = { 0 };
#define DEM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Dem_C_CommitBuffer
**********************************************************************************************************************/
#define DEM_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(Dem_Cfg_CommitBufferType, DEM_VAR_NOINIT) Dem_C_CommitBuffer;  /* PRQA S 0759 */ /* MD_DEM_18.4 */
#define DEM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Dem_C_EventDebounceValue
**********************************************************************************************************************/
/** 
  \var    Dem_C_EventDebounceValue
  \brief  size = DEM_G_NUMBER_OF_EVENTS; (DEM_CFG_SUPPORT_DEBOUNCE_COUNTER == STD_ON) || (DEM_CFG_SUPPORT_DEBOUNCE_TIME == STD_ON)
*/ 
#define DEM_START_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
volatile VAR(Dem_C_EventDebounceValueType, DEM_VAR_NOINIT) Dem_C_EventDebounceValue[13];
#define DEM_STOP_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Dem_C_EventInternalStatus
**********************************************************************************************************************/
/** 
  \var    Dem_C_EventInternalStatus
  \brief  size = DEM_G_NUMBER_OF_EVENTS
*/ 
#define DEM_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
volatile VAR(Dem_Cfg_EventInternalStatusType, DEM_VAR_NOINIT) Dem_C_EventInternalStatus[13];
#define DEM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Dem_C_EventQueueStatus
**********************************************************************************************************************/
/** 
  \var    Dem_C_EventQueueStatus
  \brief  size = DEM_G_NUMBER_OF_EVENTS
*/ 
#define DEM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
volatile VAR(Dem_C_EventQueueStatusType, DEM_VAR_NOINIT) Dem_C_EventQueueStatus[13];
#define DEM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Dem_C_FilterReportedEvents
**********************************************************************************************************************/
/** 
  \var    Dem_C_FilterReportedEvents
  \brief  size = CEIL( DEM_G_NUMBER_OF_EVENTS / 8 )
*/ 
#define DEM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(Dem_C_FilterReportedEventsType, DEM_VAR_NOINIT) Dem_C_FilterReportedEvents[2];
#define DEM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Dem_C_MemoryCommitNumber
**********************************************************************************************************************/
/** 
  \var    Dem_C_MemoryCommitNumber
  \brief  The array contains these items: Admin, Status, 8 * Primary
*/ 
#define DEM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
volatile VAR(Dem_C_MemoryCommitNumberType, DEM_VAR_NOINIT) Dem_C_MemoryCommitNumber[10];
#define DEM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Dem_C_MemoryStatus
**********************************************************************************************************************/
/** 
  \var    Dem_C_MemoryStatus
  \brief  The array contains these items: Admin, Status, 8 * Primary
*/ 
#define DEM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(Dem_C_MemoryStatusType, DEM_VAR_NOINIT) Dem_C_MemoryStatus[10];
#define DEM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Dem_C_NvAdminData
**********************************************************************************************************************/
#define DEM_START_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(Dem_Cfg_AdminDataType, DEM_NVM_DATA_NOINIT) Dem_C_NvAdminData;
#define DEM_STOP_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Dem_C_NvEventData
**********************************************************************************************************************/
#define DEM_START_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(Dem_Cfg_StatusDataType, DEM_NVM_DATA_NOINIT) Dem_C_NvEventData;
#define DEM_STOP_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Dem_C_NvPrimaryEntry_0
**********************************************************************************************************************/
#define DEM_START_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(Dem_Cfg_PrimaryEntryType, DEM_NVM_DATA_NOINIT) Dem_C_NvPrimaryEntry_0;
#define DEM_STOP_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Dem_C_NvPrimaryEntry_1
**********************************************************************************************************************/
#define DEM_START_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(Dem_Cfg_PrimaryEntryType, DEM_NVM_DATA_NOINIT) Dem_C_NvPrimaryEntry_1;
#define DEM_STOP_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Dem_C_NvPrimaryEntry_2
**********************************************************************************************************************/
#define DEM_START_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(Dem_Cfg_PrimaryEntryType, DEM_NVM_DATA_NOINIT) Dem_C_NvPrimaryEntry_2;
#define DEM_STOP_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Dem_C_NvPrimaryEntry_3
**********************************************************************************************************************/
#define DEM_START_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(Dem_Cfg_PrimaryEntryType, DEM_NVM_DATA_NOINIT) Dem_C_NvPrimaryEntry_3;
#define DEM_STOP_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Dem_C_NvPrimaryEntry_4
**********************************************************************************************************************/
#define DEM_START_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(Dem_Cfg_PrimaryEntryType, DEM_NVM_DATA_NOINIT) Dem_C_NvPrimaryEntry_4;
#define DEM_STOP_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Dem_C_NvPrimaryEntry_5
**********************************************************************************************************************/
#define DEM_START_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(Dem_Cfg_PrimaryEntryType, DEM_NVM_DATA_NOINIT) Dem_C_NvPrimaryEntry_5;
#define DEM_STOP_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Dem_C_NvPrimaryEntry_6
**********************************************************************************************************************/
#define DEM_START_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(Dem_Cfg_PrimaryEntryType, DEM_NVM_DATA_NOINIT) Dem_C_NvPrimaryEntry_6;
#define DEM_STOP_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Dem_C_NvPrimaryEntry_7
**********************************************************************************************************************/
#define DEM_START_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(Dem_Cfg_PrimaryEntryType, DEM_NVM_DATA_NOINIT) Dem_C_NvPrimaryEntry_7;
#define DEM_STOP_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Dem_C_PrimaryChronology
**********************************************************************************************************************/
/** 
  \var    Dem_C_PrimaryChronology
  \brief  size = DEM_CFG_MAX_NUMBER_EVENT_ENTRY_PRIMARY
*/ 
#define DEM_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(Dem_Cfg_MemoryIndexType, DEM_VAR_NOINIT) Dem_C_PrimaryChronology[8];
#define DEM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Dem_C_ReadoutBuffer
**********************************************************************************************************************/
#define DEM_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(Dem_Cfg_PrimaryEntryType, DEM_VAR_NOINIT) Dem_C_ReadoutBuffer;
#define DEM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL DATA
**********************************************************************************************************************/



/**********************************************************************************************************************
  LOCAL FUNCTION PROTOTYPES
**********************************************************************************************************************/

/**********************************************************************************************************************
  LOCAL FUNCTIONS
**********************************************************************************************************************/

/**********************************************************************************************************************
  GLOBAL FUNCTIONS
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL FUNCTIONS
**********************************************************************************************************************/
#define DEM_START_SEC_CODE
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
#define DEM_STOP_SEC_CODE
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL FUNCTIONS
**********************************************************************************************************************/

#define DEM_START_SEC_CODE
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/************************************************************************************************************
 *  Dem_Cfg_FindEventFromUdsDtc()
 ***********************************************************************************************************/
/*! \brief         Map UDS DTC number to EventId.
 *  \details       Search (a range) of the event table for the requested DTC number. Return the event ID.
 *                 With combined events, the returned ID is the proxy of the combination group.
 *  \param[in]     DTC                                            the dtc number
 *  \param[in]     MemoryId                                       the memory area, for example
 *                                                                DEM_CFG_MEMORYID_PRIMARY,
 *                                                                DEM_CFG_MEMORYID_SECONDARY...
 *  \return        DEM_EVENT_INVALID                              Function not successful. No event in the
 *                                                                current variant has this DTC number.
 *  \return        x = {x > 0 && x < Dem_Cfg_GlobalEventCount()}  Function successful.
 *  \pre           -
 *  \context       ANY
 *  \reentrant     TRUE
 ***********************************************************************************************************/ 
FUNC(uint16, DEM_CODE) Dem_Cfg_FindEventFromUdsDtc(uint32 DTC, uint8 MemoryId) 
{ 
  Dem_EventIdType lLowerLimit;
  Dem_EventIdType lEventId;
  switch (MemoryId)
  {
  case DEM_CFG_MEMORYID_PRIMARY:
    lLowerLimit = Dem_Cfg_GlobalPrimaryFirst();
    lEventId    = Dem_Cfg_GlobalPrimaryLast();
    break;
  default:
    lLowerLimit = DEM_EVENT_INVALID;
    lEventId    = DEM_EVENT_INVALID;
    break;
  }
  
  if (lLowerLimit != DEM_EVENT_INVALID)
  {
    for (; lEventId >= lLowerLimit; --lEventId)
    {
      if (DTC == Dem_Cfg_EventUdsDtc(lEventId))
      {
        break;
      }
    }
    if (lEventId < lLowerLimit)
    {
      lEventId = DEM_EVENT_INVALID;
    }
  }
  
  return lEventId; 
} 

 
/************************************************************************************************************
 *  Dem_Cfg_FindEventFromJ1939Dtc()
 ***********************************************************************************************************/
/*! \brief         Map J1939 DTC number to EventId.
 *  \details       Search (a range) of the event table for the requested J1939DTC number. Return the event
 *                 ID.
 *  \param[in]     DTC                                            the J1939 dtc number
 *  \return        DEM_EVENT_INVALID                              Function not successful. No event in the
 *                                                                current variant has this J1939DTC number.
 *  \return        x = {x > 0 && x < Dem_Cfg_GlobalEventCount()}  Function successful.
 *  \pre           -
 *  \context       ANY
 *  \reentrant     TRUE
 ***********************************************************************************************************/ 
FUNC(uint16, DEM_CODE) Dem_Cfg_FindEventFromJ1939Dtc(uint32 DTC) 
{ 
  /* DEM_CFG_SUPPORT_J1939 == STD_OFF */
  DEM_IGNORE_UNUSED_ARGUMENT(DTC)                                                                   /* PRQA S 3112 */ /* MD_DEM_14.2 */
  return DEM_EVENT_INVALID; 
} 

 
/************************************************************************************************************
 *  Dem_Cfg_FindGroupMaskFromUdsDtc()
 ***********************************************************************************************************/
/*! \brief         Map GroupOfDtc number to (internal) GROUPMASK.
 *  \details       Test if the DTC number is a configured UDS 'groupOfDTC' number, and return the internal
 *                 representation of that group.
 *  \param[in]     DTC                           dtc number to check
 *  \return        DEM_CFG_GROUPMASK_NONE        Function not successful. The DTC number doen't represent any
 *                                               configured DemGroupOfDTC.
 *  \return        DEM_CFG_GROUPMASK_EMISSION    Function successful. The DTC number represents the OBD-II
 *                                               emission related group.
 *  \return        DEM_CFG_GROUPMASK_POWERTRAIN  Function successful. The DTC number represents Powertrain
 *                                               Group: engine and transmission.
 *  \return        DEM_CFG_GROUPMASK_CHASSIS     Function successful. The DTC number represents the Chassis
 *                                               Group.
 *  \return        DEM_CFG_GROUPMASK_BODY        Function successful. The DTC number represents the Body
 *                                               Group.
 *  \return        DEM_CFG_GROUPMASK_NETWORK     Function successful. The DTC number represents the Network
 *                                               Communication Group.
 *  \return        DEM_CFG_GROUPMASK_ALLDTCS     Function successful. The DTC number is the wildcard 'All
 *                                               Groups (all DTCs)'.
 *  \pre           -
 *  \context       ANY
 *  \reentrant     TRUE
 *  \note          Dependent on the current configuration, not all named (possible) return values are
 *                 actually used.
 ***********************************************************************************************************/ 
FUNC(uint8, DEM_CODE) Dem_Cfg_FindGroupMaskFromUdsDtc(uint32 groupDtcNumber) 
{ 
  uint8 mask;
  switch (groupDtcNumber)
  {
    case 0x00FFFFFFUL: mask = DEM_CFG_GROUPMASK_ALLDTCS; break;
    default: mask = DEM_CFG_GROUPMASK_NONE; break;
  }
  return mask; 
} 

 
/************************************************************************************************************
 *  Dem_Cfg_EventGroupMask()
 ***********************************************************************************************************/
/*! \brief         Map EventId to groupOfDTC's (internal) GROUPMASK.
 *  \details       Test if the DTC number is a configured UDS 'groupOfDTC' number, and return the internal
 *                 representation of that group.
 *  \param[in]     eventId                       event ID to check
 *  \return        DEM_CFG_GROUPMASK_NONE        Function not successful. The event has no DemUdsDTC number
 *                                               so it is not part of a DemGroupOfDTC.
 *  \return        DEM_CFG_GROUPMASK_EMISSION    Function successful. The event is part of the OBD-II
 *                                               emission related DemGroupOfDTC.
 *  \return        DEM_CFG_GROUPMASK_POWERTRAIN  Function successful. The event is part of the Powertrain
 *                                               DemGroupOfDTC.
 *  \return        DEM_CFG_GROUPMASK_CHASSIS     Function successful. The event is part of the Chassis
 *                                               DemGroupOfDTC.
 *  \return        DEM_CFG_GROUPMASK_BODY        Function successful. The event is part of the Body
 *                                               DemGroupOfDTC.
 *  \return        DEM_CFG_GROUPMASK_NETWORK     Function successful. The event is part of the Network
 *                                               Communication DemGroupOfDTC.
 *  \pre           -
 *  \context       ANY
 *  \reentrant     TRUE
 *  \note          Dependent on the current configuration, not all named (possible) return values are
 *                 actually used.
 *  \note          Implementation specific: the configured 'DemGroupDTCs' value is the lowest value of each
 *                 group.
 *                 In other words, the configured 'DemGroupDTCs' split the range of DTC numbers
 *                 0x000000..0xFFFFFF into groups and the proxy of each group is the 'DemGroupDTCs' value
 *                 (that never is a DemUdsDTC number in addition).
 ***********************************************************************************************************/ 
FUNC(uint8, DEM_CODE) Dem_Cfg_EventGroupMask(uint16 eventId) 
{ 
  DEM_IGNORE_UNUSED_ARGUMENT(eventId)                                                               /* PRQA S 3112 */ /* MD_DEM_14.2 */
  return DEM_CFG_GROUPMASK_NONE; /* no GroupOfDtc configured */ 
}                                                                                                   /* PRQA S 6080 */ /* MD_MSR_STMIF */ 

 
#define DEM_STOP_SEC_CODE
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */



/**********************************************************************************************************************
  END OF FILE: Dem_Lcfg.c     [Vector, VARIANT-PRE-COMPILE]
**********************************************************************************************************************/

