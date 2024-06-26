/**************************************************************************//**
 * @file     core_cmInstr.h
 * @brief    CMSIS Cortex-M Core Instruction Access Header File
 * @version  V4.30
 * @date     28 March 2024
 ******************************************************************************/

#if   defined ( __ICCARM__ )
 #pragma system_include         /* treat file as system include file for MISRA check */
#elif defined(__ARMCC_VERSION) && (__ARMCC_VERSION >= 6010050)
  #pragma clang system_header   /* treat file as system include file */
#endif

#ifndef __CORE_CMINSTR_H
#define __CORE_CMINSTR_H


/* ##########################  Core Instruction Access  ######################### */
/** \defgroup CMSIS_Core_InstructionInterface CMSIS Core Instruction Interface
  Access to dedicated instructions
  @{
*/

/*------------------ RealView Compiler -----------------*/
#if   defined ( __CC_ARM )
  #include "cmsis_armcc.h"

/*------------------ ARM Compiler V6 -------------------*/
#elif defined(__ARMCC_VERSION) && (__ARMCC_VERSION >= 6010050)
  #include "cmsis_armcc_V6.h"

/*------------------ GNU Compiler ----------------------*/
#elif defined ( __GNUC__ )
  #include "cmsis_gcc.h"

/*------------------ ICC Compiler ----------------------*/
#elif defined ( __ICCARM__ )
  #include <cmsis_iar.h>

/*------------------ TI CCS Compiler -------------------*/
#elif defined ( __TMS470__ )
  #include <cmsis_ccs.h>

/*------------------ TASKING Compiler ------------------*/
#elif defined ( __TASKING__ )
  /*
   * The CMSIS functions have been implemented as intrinsics in the compiler.
   * Please use "carm -?i" to get an up to date list of all intrinsics,
   * Including the CMSIS ones.
   */

/*------------------ COSMIC Compiler -------------------*/
#elif defined ( __CSMC__ )
  #include <cmsis_csm.h>

#endif

/*@}*/ /* end of group CMSIS_Core_InstructionInterface */

#endif /* __CORE_CMINSTR_H */
