/*
 * Multirotor_Model_1_private.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Multirotor_Model_1".
 *
 * Model version              : 1.982
 * Simulink Coder version : 9.4 (R2020b) 29-Jul-2020
 * C source code generated on : Mon Apr  3 15:48:00 2023
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Multirotor_Model_1_private_h_
#define RTW_HEADER_Multirotor_Model_1_private_h_
#include "rtwtypes.h"
#include "builtin_typeid_types.h"
#include "multiword_types.h"
#include "Multirotor_Model_1.h"

/* Private macros used by the generated code to access rtModel */
#ifndef rtmSetFirstInitCond
#define rtmSetFirstInitCond(rtm, val)  ((rtm)->Timing.firstInitCondFlag = (val))
#endif

#ifndef rtmIsFirstInitCond
#define rtmIsFirstInitCond(rtm)        ((rtm)->Timing.firstInitCondFlag)
#endif

#ifndef rtmIsMajorTimeStep
#define rtmIsMajorTimeStep(rtm)        (((rtm)->Timing.simTimeStep) == MAJOR_TIME_STEP)
#endif

#ifndef rtmIsMinorTimeStep
#define rtmIsMinorTimeStep(rtm)        (((rtm)->Timing.simTimeStep) == MINOR_TIME_STEP)
#endif

#ifndef rtmSetTFinal
#define rtmSetTFinal(rtm, val)         ((rtm)->Timing.tFinal = (val))
#endif

#ifndef rtmSetTPtr
#define rtmSetTPtr(rtm, val)           ((rtm)->Timing.t = (val))
#endif

extern real_T rt_atan2d_snf(real_T u0, real_T u1);
extern real_T rt_powd_snf(real_T u0, real_T u1);
extern void Multiro_IfActionSubsystem3_Init(real_T *rty_Out1);
extern void Multirotor_M_IfActionSubsystem3(real_T rtu_In1, real_T *rty_Out1);
extern void Multiro_IfActionSubsystem4_Init(real_T *rty_Out1);
extern void Multirotor_M_IfActionSubsystem4(RT_MODEL_Multirotor_Model_1_T *
  const Multirotor_Model_1_M, real_T rtu_In1, real_T *rty_Out1);
extern void Multiro_IfActionSubsystem5_Init(real_T *rty_Out1);
extern void Multirotor_M_IfActionSubsystem5(RT_MODEL_Multirotor_Model_1_T *
  const Multirotor_Model_1_M, real_T rtu_In1, real_T *rty_Out1);

/* private model entry point functions */
extern void Multirotor_Model_1_derivatives(void);

#endif                            /* RTW_HEADER_Multirotor_Model_1_private_h_ */
