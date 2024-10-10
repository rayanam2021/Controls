/*
 * Quad_biplane.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Quad_biplane".
 *
 * Model version              : 1.1481
 * Simulink Coder version : 9.4 (R2020b) 29-Jul-2020
 * C source code generated on : Wed Nov  8 19:19:20 2023
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Quad_biplane_h_
#define RTW_HEADER_Quad_biplane_h_
#include <float.h>
#include <math.h>
#include <string.h>
#include <stddef.h>
#ifndef Quad_biplane_COMMON_INCLUDES_
#define Quad_biplane_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "rt_logging.h"
#endif                                 /* Quad_biplane_COMMON_INCLUDES_ */

#include "Quad_biplane_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "rt_nonfinite.h"
#include "rt_zcfcn.h"
#include "rt_defines.h"
#include "rtGetInf.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetContStateDisabled
#define rtmGetContStateDisabled(rtm)   ((rtm)->contStateDisabled)
#endif

#ifndef rtmSetContStateDisabled
#define rtmSetContStateDisabled(rtm, val) ((rtm)->contStateDisabled = (val))
#endif

#ifndef rtmGetContStates
#define rtmGetContStates(rtm)          ((rtm)->contStates)
#endif

#ifndef rtmSetContStates
#define rtmSetContStates(rtm, val)     ((rtm)->contStates = (val))
#endif

#ifndef rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag
#define rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm) ((rtm)->CTOutputIncnstWithState)
#endif

#ifndef rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag
#define rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm, val) ((rtm)->CTOutputIncnstWithState = (val))
#endif

#ifndef rtmGetDerivCacheNeedsReset
#define rtmGetDerivCacheNeedsReset(rtm) ((rtm)->derivCacheNeedsReset)
#endif

#ifndef rtmSetDerivCacheNeedsReset
#define rtmSetDerivCacheNeedsReset(rtm, val) ((rtm)->derivCacheNeedsReset = (val))
#endif

#ifndef rtmGetFinalTime
#define rtmGetFinalTime(rtm)           ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetIntgData
#define rtmGetIntgData(rtm)            ((rtm)->intgData)
#endif

#ifndef rtmSetIntgData
#define rtmSetIntgData(rtm, val)       ((rtm)->intgData = (val))
#endif

#ifndef rtmGetOdeF
#define rtmGetOdeF(rtm)                ((rtm)->odeF)
#endif

#ifndef rtmSetOdeF
#define rtmSetOdeF(rtm, val)           ((rtm)->odeF = (val))
#endif

#ifndef rtmGetOdeY
#define rtmGetOdeY(rtm)                ((rtm)->odeY)
#endif

#ifndef rtmSetOdeY
#define rtmSetOdeY(rtm, val)           ((rtm)->odeY = (val))
#endif

#ifndef rtmGetPeriodicContStateIndices
#define rtmGetPeriodicContStateIndices(rtm) ((rtm)->periodicContStateIndices)
#endif

#ifndef rtmSetPeriodicContStateIndices
#define rtmSetPeriodicContStateIndices(rtm, val) ((rtm)->periodicContStateIndices = (val))
#endif

#ifndef rtmGetPeriodicContStateRanges
#define rtmGetPeriodicContStateRanges(rtm) ((rtm)->periodicContStateRanges)
#endif

#ifndef rtmSetPeriodicContStateRanges
#define rtmSetPeriodicContStateRanges(rtm, val) ((rtm)->periodicContStateRanges = (val))
#endif

#ifndef rtmGetRTWLogInfo
#define rtmGetRTWLogInfo(rtm)          ((rtm)->rtwLogInfo)
#endif

#ifndef rtmGetZCCacheNeedsReset
#define rtmGetZCCacheNeedsReset(rtm)   ((rtm)->zCCacheNeedsReset)
#endif

#ifndef rtmSetZCCacheNeedsReset
#define rtmSetZCCacheNeedsReset(rtm, val) ((rtm)->zCCacheNeedsReset = (val))
#endif

#ifndef rtmGetdX
#define rtmGetdX(rtm)                  ((rtm)->derivs)
#endif

#ifndef rtmSetdX
#define rtmSetdX(rtm, val)             ((rtm)->derivs = (val))
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm)       ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
#define rtmSetStopRequested(rtm, val)  ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
#define rtmGetStopRequestedPtr(rtm)    (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTFinal
#define rtmGetTFinal(rtm)              ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                ((rtm)->Timing.t)
#endif

/* Block signals for system '<S619>/MATLAB Function' */
typedef struct {
  real_T load[6];                      /* '<S619>/MATLAB Function' */
} B_MATLABFunction_Quad_biplane_T;

/* Block signals (default storage) */
typedef struct {
  real_T Delay[24];                    /* '<Root>/Delay' */
  real_T ProportionalGain;             /* '<S399>/Proportional Gain' */
  real_T DerivativeGain;               /* '<S388>/Derivative Gain' */
  real_T FilterCoefficient;            /* '<S397>/Filter Coefficient' */
  real_T Saturation;                   /* '<S401>/Saturation' */
  real_T FilterCoefficient_j;          /* '<S594>/Filter Coefficient' */
  real_T Saturation_h;                 /* '<S598>/Saturation' */
  real_T Merge;                        /* '<S310>/Merge' */
  real_T FilterCoefficient_f;          /* '<S445>/Filter Coefficient' */
  real_T Saturation_hv;                /* '<S449>/Saturation' */
  real_T FilterCoefficient_e;          /* '<S493>/Filter Coefficient' */
  real_T Saturation_f;                 /* '<S497>/Saturation' */
  real_T FilterCoefficient_i;          /* '<S45>/Filter Coefficient' */
  real_T Gain1;                        /* '<S9>/Gain1' */
  real_T Delay_d;                      /* '<S1>/Delay' */
  real_T Sum1;                         /* '<S9>/Sum1' */
  real_T FilterCoefficient_n;          /* '<S147>/Filter Coefficient' */
  real_T Saturation_c;                 /* '<S151>/Saturation' */
  real_T Sum;                          /* '<S60>/Sum' */
  real_T FilterCoefficient_ir;         /* '<S198>/Filter Coefficient' */
  real_T Sum_d;                        /* '<S204>/Sum' */
  real_T Sum_a;                        /* '<S59>/Sum' */
  real_T FilterCoefficient_d;          /* '<S99>/Filter Coefficient' */
  real_T Gain1_b;                      /* '<S59>/Gain1' */
  real_T Merge_m;                      /* '<S59>/Merge' */
  real_T Sum1_o;                       /* '<S60>/Sum1' */
  real_T FilterCoefficient_il;         /* '<S246>/Filter Coefficient' */
  real_T Sum_f;                        /* '<S252>/Sum' */
  real_T ProportionalGain_f;           /* '<S296>/Proportional Gain' */
  real_T DerivativeGain_a;             /* '<S285>/Derivative Gain' */
  real_T FilterCoefficient_b;          /* '<S294>/Filter Coefficient' */
  real_T Sum_g;                        /* '<S300>/Sum' */
  real_T Add[6];                       /* '<S4>/Add' */
  real_T Delay_f;                      /* '<S2>/Delay' */
  real_T Gain1_d;                      /* '<Root>/Gain1' */
  real_T Gain;                         /* '<Root>/Gain' */
  real_T Gain2;                        /* '<Root>/Gain2' */
  real_T Gain3;                        /* '<Root>/Gain3' */
  real_T Gain_c[4];                    /* '<S1>/Gain' */
  real_T IntegralGain;                 /* '<S39>/Integral Gain' */
  real_T IntegralGain_e;               /* '<S93>/Integral Gain' */
  real_T IntegralGain_k;               /* '<S141>/Integral Gain' */
  real_T IntegralGain_g;               /* '<S192>/Integral Gain' */
  real_T IntegralGain_l;               /* '<S240>/Integral Gain' */
  real_T IntegralGain_p;               /* '<S288>/Integral Gain' */
  real_T IntegralGain_h;               /* '<S343>/Integral Gain' */
  real_T FilterCoefficient_h;          /* '<S349>/Filter Coefficient' */
  real_T IntegralGain_m;               /* '<S391>/Integral Gain' */
  real_T IntegralGain_gm;              /* '<S439>/Integral Gain' */
  real_T IntegralGain_e2;              /* '<S487>/Integral Gain' */
  real_T IntegralGain_i;               /* '<S588>/Integral Gain' */
  real_T Gain_b;                       /* '<S619>/Gain' */
  real_T Gain_e;                       /* '<S620>/Gain' */
  real_T Gain_k;                       /* '<S621>/Gain' */
  real_T Gain_a;                       /* '<S622>/Gain' */
  real_T Total_wing_load[6];           /* '<S615>/MATLAB Function' */
  real_T Total_Weight_Load[6];         /* '<S614>/MATLAB Function' */
  real_T Total_Rotor_Load[6];          /* '<S613>/MATLAB Function2' */
  real_T fuselage_load[6];             /* '<S612>/Fuselage' */
  real_T Z_desired;                    /* '<Root>/Mission Profile' */
  real_T X_desired;                    /* '<Root>/Mission Profile' */
  real_T theta_desired;                /* '<Root>/Mission Profile' */
  real_T psi_desired;                  /* '<Root>/Mission Profile' */
  real_T transition;                   /* '<Root>/Mission Profile' */
  real_T a_body[3];                    /* '<S2>/Translational Dynamics' */
  real_T P_dot_new[3];                 /* '<S2>/Transform1' */
  real_T Eang_dot_new[3];              /* '<S2>/Transform1' */
  real_T States_New[24];               /* '<S2>/State_update' */
  real_T reset_flag;                   /* '<S2>/State_update' */
  real_T om_dot[3];                    /* '<S2>/Rotational Dynamics' */
  real_T ProportionalGain_j;           /* '<S548>/Proportional Gain' */
  real_T DerivativeGain_h;             /* '<S537>/Derivative Gain' */
  real_T FilterCoefficient_p;          /* '<S546>/Filter Coefficient' */
  real_T Saturation_k;                 /* '<S550>/Saturation' */
  real_T IntegralGain_f;               /* '<S540>/Integral Gain' */
  real_T u_des;                        /* '<S8>/MATLAB Function' */
  real_T v_des;                        /* '<S8>/MATLAB Function' */
  real_T w_des;                        /* '<S8>/MATLAB Function' */
  real_T q_des;                        /* '<S8>/MATLAB Function' */
  real_T ssw;                          /* '<S1>/MATLAB Function' */
  B_MATLABFunction_Quad_biplane_T sf_MATLABFunction_l;/* '<S622>/MATLAB Function' */
  B_MATLABFunction_Quad_biplane_T sf_MATLABFunction_d;/* '<S621>/MATLAB Function' */
  B_MATLABFunction_Quad_biplane_T sf_MATLABFunction_j;/* '<S620>/MATLAB Function' */
  B_MATLABFunction_Quad_biplane_T sf_MATLABFunction_n;/* '<S619>/MATLAB Function' */
} B_Quad_biplane_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T Delay_DSTATE[24];             /* '<Root>/Delay' */
  real_T Delay_DSTATE_m;               /* '<S1>/Delay' */
  real_T Delay_DSTATE_a;               /* '<S2>/Delay' */
  int8_T If_ActiveSubsystem;           /* '<S310>/If' */
  int8_T If_ActiveSubsystem_l;         /* '<S59>/If' */
} DW_Quad_biplane_T;

/* Continuous states (default storage) */
typedef struct {
  real_T Integrator_CSTATE;            /* '<S394>/Integrator' */
  real_T Filter_CSTATE;                /* '<S389>/Filter' */
  real_T Integrator_CSTATE_b;          /* '<S591>/Integrator' */
  real_T Filter_CSTATE_p;              /* '<S586>/Filter' */
  real_T Integrator_CSTATE_d;          /* '<S442>/Integrator' */
  real_T Filter_CSTATE_a;              /* '<S437>/Filter' */
  real_T Integrator_CSTATE_n;          /* '<S490>/Integrator' */
  real_T Filter_CSTATE_d;              /* '<S485>/Filter' */
  real_T Integrator_CSTATE_n4;         /* '<S42>/Integrator' */
  real_T Filter_CSTATE_k;              /* '<S37>/Filter' */
  real_T Integrator_CSTATE_c;          /* '<S144>/Integrator' */
  real_T Filter_CSTATE_db;             /* '<S139>/Filter' */
  real_T Integrator_CSTATE_h;          /* '<S195>/Integrator' */
  real_T Filter_CSTATE_aw;             /* '<S190>/Filter' */
  real_T Integrator_CSTATE_m;          /* '<S96>/Integrator' */
  real_T Filter_CSTATE_n;              /* '<S91>/Filter' */
  real_T Integrator_CSTATE_mn;         /* '<S243>/Integrator' */
  real_T Filter_CSTATE_b;              /* '<S238>/Filter' */
  real_T Integrator_CSTATE_j;          /* '<S291>/Integrator' */
  real_T Filter_CSTATE_o;              /* '<S286>/Filter' */
  real_T Integrator3_CSTATE;           /* '<S2>/Integrator3' */
  real_T Integrator4_CSTATE;           /* '<S2>/Integrator4' */
  real_T Integrator5_CSTATE;           /* '<S2>/Integrator5' */
  real_T Integrator_CSTATE_p;          /* '<S2>/Integrator' */
  real_T Integrator1_CSTATE;           /* '<S2>/Integrator1' */
  real_T Integrator2_CSTATE;           /* '<S2>/Integrator2' */
  real_T Integrator6_CSTATE;           /* '<S2>/Integrator6' */
  real_T Integrator7_CSTATE;           /* '<S2>/Integrator7' */
  real_T Integrator8_CSTATE;           /* '<S2>/Integrator8' */
  real_T Integrator9_CSTATE;           /* '<S2>/Integrator9' */
  real_T Integrator10_CSTATE;          /* '<S2>/Integrator10' */
  real_T Integrator11_CSTATE;          /* '<S2>/Integrator11' */
  real_T Filter_CSTATE_f;              /* '<S341>/Filter' */
  real_T Integrator_CSTATE_bt;         /* '<S346>/Integrator' */
  real_T Integrator_CSTATE_c5;         /* '<S543>/Integrator' */
  real_T Filter_CSTATE_fr;             /* '<S538>/Filter' */
} X_Quad_biplane_T;

/* State derivatives (default storage) */
typedef struct {
  real_T Integrator_CSTATE;            /* '<S394>/Integrator' */
  real_T Filter_CSTATE;                /* '<S389>/Filter' */
  real_T Integrator_CSTATE_b;          /* '<S591>/Integrator' */
  real_T Filter_CSTATE_p;              /* '<S586>/Filter' */
  real_T Integrator_CSTATE_d;          /* '<S442>/Integrator' */
  real_T Filter_CSTATE_a;              /* '<S437>/Filter' */
  real_T Integrator_CSTATE_n;          /* '<S490>/Integrator' */
  real_T Filter_CSTATE_d;              /* '<S485>/Filter' */
  real_T Integrator_CSTATE_n4;         /* '<S42>/Integrator' */
  real_T Filter_CSTATE_k;              /* '<S37>/Filter' */
  real_T Integrator_CSTATE_c;          /* '<S144>/Integrator' */
  real_T Filter_CSTATE_db;             /* '<S139>/Filter' */
  real_T Integrator_CSTATE_h;          /* '<S195>/Integrator' */
  real_T Filter_CSTATE_aw;             /* '<S190>/Filter' */
  real_T Integrator_CSTATE_m;          /* '<S96>/Integrator' */
  real_T Filter_CSTATE_n;              /* '<S91>/Filter' */
  real_T Integrator_CSTATE_mn;         /* '<S243>/Integrator' */
  real_T Filter_CSTATE_b;              /* '<S238>/Filter' */
  real_T Integrator_CSTATE_j;          /* '<S291>/Integrator' */
  real_T Filter_CSTATE_o;              /* '<S286>/Filter' */
  real_T Integrator3_CSTATE;           /* '<S2>/Integrator3' */
  real_T Integrator4_CSTATE;           /* '<S2>/Integrator4' */
  real_T Integrator5_CSTATE;           /* '<S2>/Integrator5' */
  real_T Integrator_CSTATE_p;          /* '<S2>/Integrator' */
  real_T Integrator1_CSTATE;           /* '<S2>/Integrator1' */
  real_T Integrator2_CSTATE;           /* '<S2>/Integrator2' */
  real_T Integrator6_CSTATE;           /* '<S2>/Integrator6' */
  real_T Integrator7_CSTATE;           /* '<S2>/Integrator7' */
  real_T Integrator8_CSTATE;           /* '<S2>/Integrator8' */
  real_T Integrator9_CSTATE;           /* '<S2>/Integrator9' */
  real_T Integrator10_CSTATE;          /* '<S2>/Integrator10' */
  real_T Integrator11_CSTATE;          /* '<S2>/Integrator11' */
  real_T Filter_CSTATE_f;              /* '<S341>/Filter' */
  real_T Integrator_CSTATE_bt;         /* '<S346>/Integrator' */
  real_T Integrator_CSTATE_c5;         /* '<S543>/Integrator' */
  real_T Filter_CSTATE_fr;             /* '<S538>/Filter' */
} XDot_Quad_biplane_T;

/* State disabled  */
typedef struct {
  boolean_T Integrator_CSTATE;         /* '<S394>/Integrator' */
  boolean_T Filter_CSTATE;             /* '<S389>/Filter' */
  boolean_T Integrator_CSTATE_b;       /* '<S591>/Integrator' */
  boolean_T Filter_CSTATE_p;           /* '<S586>/Filter' */
  boolean_T Integrator_CSTATE_d;       /* '<S442>/Integrator' */
  boolean_T Filter_CSTATE_a;           /* '<S437>/Filter' */
  boolean_T Integrator_CSTATE_n;       /* '<S490>/Integrator' */
  boolean_T Filter_CSTATE_d;           /* '<S485>/Filter' */
  boolean_T Integrator_CSTATE_n4;      /* '<S42>/Integrator' */
  boolean_T Filter_CSTATE_k;           /* '<S37>/Filter' */
  boolean_T Integrator_CSTATE_c;       /* '<S144>/Integrator' */
  boolean_T Filter_CSTATE_db;          /* '<S139>/Filter' */
  boolean_T Integrator_CSTATE_h;       /* '<S195>/Integrator' */
  boolean_T Filter_CSTATE_aw;          /* '<S190>/Filter' */
  boolean_T Integrator_CSTATE_m;       /* '<S96>/Integrator' */
  boolean_T Filter_CSTATE_n;           /* '<S91>/Filter' */
  boolean_T Integrator_CSTATE_mn;      /* '<S243>/Integrator' */
  boolean_T Filter_CSTATE_b;           /* '<S238>/Filter' */
  boolean_T Integrator_CSTATE_j;       /* '<S291>/Integrator' */
  boolean_T Filter_CSTATE_o;           /* '<S286>/Filter' */
  boolean_T Integrator3_CSTATE;        /* '<S2>/Integrator3' */
  boolean_T Integrator4_CSTATE;        /* '<S2>/Integrator4' */
  boolean_T Integrator5_CSTATE;        /* '<S2>/Integrator5' */
  boolean_T Integrator_CSTATE_p;       /* '<S2>/Integrator' */
  boolean_T Integrator1_CSTATE;        /* '<S2>/Integrator1' */
  boolean_T Integrator2_CSTATE;        /* '<S2>/Integrator2' */
  boolean_T Integrator6_CSTATE;        /* '<S2>/Integrator6' */
  boolean_T Integrator7_CSTATE;        /* '<S2>/Integrator7' */
  boolean_T Integrator8_CSTATE;        /* '<S2>/Integrator8' */
  boolean_T Integrator9_CSTATE;        /* '<S2>/Integrator9' */
  boolean_T Integrator10_CSTATE;       /* '<S2>/Integrator10' */
  boolean_T Integrator11_CSTATE;       /* '<S2>/Integrator11' */
  boolean_T Filter_CSTATE_f;           /* '<S341>/Filter' */
  boolean_T Integrator_CSTATE_bt;      /* '<S346>/Integrator' */
  boolean_T Integrator_CSTATE_c5;      /* '<S543>/Integrator' */
  boolean_T Filter_CSTATE_fr;          /* '<S538>/Filter' */
} XDis_Quad_biplane_T;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState Integrator2_Reset_ZCE;    /* '<S2>/Integrator2' */
  ZCSigState Integrator8_Reset_ZCE;    /* '<S2>/Integrator8' */
} PrevZCX_Quad_biplane_T;

#ifndef ODE4_INTG
#define ODE4_INTG

/* ODE4 Integration Data */
typedef struct {
  real_T *y;                           /* output */
  real_T *f[4];                        /* derivatives */
} ODE4_IntgData;

#endif

/* Parameters (default storage) */
struct P_Quad_biplane_T_ {
  ip_bus ip;                           /* Variable: ip
                                        * Referenced by:
                                        *   '<S619>/Constant'
                                        *   '<S620>/Constant'
                                        *   '<S621>/Constant'
                                        *   '<S622>/Constant'
                                        */
  Quad_bus Quad;                       /* Variable: Quad
                                        * Referenced by:
                                        *   '<S1>/Constant'
                                        *   '<S2>/Constant'
                                        *   '<S613>/Constant'
                                        *   '<S614>/Constant'
                                        */
  real_T PIDController2_D;             /* Mask Parameter: PIDController2_D
                                        * Referenced by: '<S537>/Derivative Gain'
                                        */
  real_T PIDController1_D;             /* Mask Parameter: PIDController1_D
                                        * Referenced by: '<S388>/Derivative Gain'
                                        */
  real_T PIDController_D;              /* Mask Parameter: PIDController_D
                                        * Referenced by: '<S585>/Derivative Gain'
                                        */
  real_T PIDController2_D_n;           /* Mask Parameter: PIDController2_D_n
                                        * Referenced by: '<S436>/Derivative Gain'
                                        */
  real_T PIDController3_D;             /* Mask Parameter: PIDController3_D
                                        * Referenced by: '<S484>/Derivative Gain'
                                        */
  real_T PIDController1_D_m;           /* Mask Parameter: PIDController1_D_m
                                        * Referenced by: '<S36>/Derivative Gain'
                                        */
  real_T PIDController1_D_f;           /* Mask Parameter: PIDController1_D_f
                                        * Referenced by: '<S138>/Derivative Gain'
                                        */
  real_T PIDController_D_m;            /* Mask Parameter: PIDController_D_m
                                        * Referenced by: '<S189>/Derivative Gain'
                                        */
  real_T PIDController_D_mc;           /* Mask Parameter: PIDController_D_mc
                                        * Referenced by: '<S90>/Derivative Gain'
                                        */
  real_T PIDController2_D_l;           /* Mask Parameter: PIDController2_D_l
                                        * Referenced by: '<S237>/Derivative Gain'
                                        */
  real_T PIDController3_D_m;           /* Mask Parameter: PIDController3_D_m
                                        * Referenced by: '<S285>/Derivative Gain'
                                        */
  real_T PIDController_D_h;            /* Mask Parameter: PIDController_D_h
                                        * Referenced by: '<S340>/Derivative Gain'
                                        */
  real_T PIDController2_I;             /* Mask Parameter: PIDController2_I
                                        * Referenced by: '<S540>/Integral Gain'
                                        */
  real_T PIDController1_I;             /* Mask Parameter: PIDController1_I
                                        * Referenced by: '<S39>/Integral Gain'
                                        */
  real_T PIDController_I;              /* Mask Parameter: PIDController_I
                                        * Referenced by: '<S93>/Integral Gain'
                                        */
  real_T PIDController1_I_j;           /* Mask Parameter: PIDController1_I_j
                                        * Referenced by: '<S141>/Integral Gain'
                                        */
  real_T PIDController_I_c;            /* Mask Parameter: PIDController_I_c
                                        * Referenced by: '<S192>/Integral Gain'
                                        */
  real_T PIDController2_I_j;           /* Mask Parameter: PIDController2_I_j
                                        * Referenced by: '<S240>/Integral Gain'
                                        */
  real_T PIDController3_I;             /* Mask Parameter: PIDController3_I
                                        * Referenced by: '<S288>/Integral Gain'
                                        */
  real_T PIDController_I_a;            /* Mask Parameter: PIDController_I_a
                                        * Referenced by: '<S343>/Integral Gain'
                                        */
  real_T PIDController1_I_d;           /* Mask Parameter: PIDController1_I_d
                                        * Referenced by: '<S391>/Integral Gain'
                                        */
  real_T PIDController2_I_g;           /* Mask Parameter: PIDController2_I_g
                                        * Referenced by: '<S439>/Integral Gain'
                                        */
  real_T PIDController3_I_g;           /* Mask Parameter: PIDController3_I_g
                                        * Referenced by: '<S487>/Integral Gain'
                                        */
  real_T PIDController_I_l;            /* Mask Parameter: PIDController_I_l
                                        * Referenced by: '<S588>/Integral Gain'
                                        */
  real_T PIDController2_InitialCondition;
                              /* Mask Parameter: PIDController2_InitialCondition
                               * Referenced by: '<S538>/Filter'
                               */
  real_T PIDController1_InitialCondition;
                              /* Mask Parameter: PIDController1_InitialCondition
                               * Referenced by: '<S389>/Filter'
                               */
  real_T PIDController_InitialConditionF;
                              /* Mask Parameter: PIDController_InitialConditionF
                               * Referenced by: '<S586>/Filter'
                               */
  real_T PIDController2_InitialConditi_n;
                              /* Mask Parameter: PIDController2_InitialConditi_n
                               * Referenced by: '<S437>/Filter'
                               */
  real_T PIDController3_InitialCondition;
                              /* Mask Parameter: PIDController3_InitialCondition
                               * Referenced by: '<S485>/Filter'
                               */
  real_T PIDController1_InitialConditi_o;
                              /* Mask Parameter: PIDController1_InitialConditi_o
                               * Referenced by: '<S37>/Filter'
                               */
  real_T PIDController1_InitialConditi_e;
                              /* Mask Parameter: PIDController1_InitialConditi_e
                               * Referenced by: '<S139>/Filter'
                               */
  real_T PIDController_InitialConditio_i;
                              /* Mask Parameter: PIDController_InitialConditio_i
                               * Referenced by: '<S190>/Filter'
                               */
  real_T PIDController_InitialConditio_k;
                              /* Mask Parameter: PIDController_InitialConditio_k
                               * Referenced by: '<S91>/Filter'
                               */
  real_T PIDController2_InitialConditi_k;
                              /* Mask Parameter: PIDController2_InitialConditi_k
                               * Referenced by: '<S238>/Filter'
                               */
  real_T PIDController3_InitialConditi_f;
                              /* Mask Parameter: PIDController3_InitialConditi_f
                               * Referenced by: '<S286>/Filter'
                               */
  real_T PIDController_InitialConditio_l;
                              /* Mask Parameter: PIDController_InitialConditio_l
                               * Referenced by: '<S341>/Filter'
                               */
  real_T PIDController2_InitialConditi_e;
                              /* Mask Parameter: PIDController2_InitialConditi_e
                               * Referenced by: '<S543>/Integrator'
                               */
  real_T PIDController1_InitialConditi_f;
                              /* Mask Parameter: PIDController1_InitialConditi_f
                               * Referenced by: '<S394>/Integrator'
                               */
  real_T PIDController_InitialConditio_o;
                              /* Mask Parameter: PIDController_InitialConditio_o
                               * Referenced by: '<S591>/Integrator'
                               */
  real_T PIDController2_InitialConditi_j;
                              /* Mask Parameter: PIDController2_InitialConditi_j
                               * Referenced by: '<S442>/Integrator'
                               */
  real_T PIDController3_InitialConditi_n;
                              /* Mask Parameter: PIDController3_InitialConditi_n
                               * Referenced by: '<S490>/Integrator'
                               */
  real_T PIDController1_InitialConditi_k;
                              /* Mask Parameter: PIDController1_InitialConditi_k
                               * Referenced by: '<S42>/Integrator'
                               */
  real_T PIDController1_InitialConditi_d;
                              /* Mask Parameter: PIDController1_InitialConditi_d
                               * Referenced by: '<S144>/Integrator'
                               */
  real_T PIDController_InitialConditio_p;
                              /* Mask Parameter: PIDController_InitialConditio_p
                               * Referenced by: '<S195>/Integrator'
                               */
  real_T PIDController_InitialConditio_g;
                              /* Mask Parameter: PIDController_InitialConditio_g
                               * Referenced by: '<S96>/Integrator'
                               */
  real_T PIDController2_InitialCondit_eb;
                              /* Mask Parameter: PIDController2_InitialCondit_eb
                               * Referenced by: '<S243>/Integrator'
                               */
  real_T PIDController3_InitialConditi_g;
                              /* Mask Parameter: PIDController3_InitialConditi_g
                               * Referenced by: '<S291>/Integrator'
                               */
  real_T PIDController_InitialConditio_b;
                              /* Mask Parameter: PIDController_InitialConditio_b
                               * Referenced by: '<S346>/Integrator'
                               */
  real_T PIDController2_LowerSaturationL;
                              /* Mask Parameter: PIDController2_LowerSaturationL
                               * Referenced by: '<S550>/Saturation'
                               */
  real_T PIDController1_LowerSaturationL;
                              /* Mask Parameter: PIDController1_LowerSaturationL
                               * Referenced by: '<S401>/Saturation'
                               */
  real_T PIDController_LowerSaturationLi;
                              /* Mask Parameter: PIDController_LowerSaturationLi
                               * Referenced by: '<S598>/Saturation'
                               */
  real_T PIDController2_LowerSaturatio_e;
                              /* Mask Parameter: PIDController2_LowerSaturatio_e
                               * Referenced by: '<S449>/Saturation'
                               */
  real_T PIDController3_LowerSaturationL;
                              /* Mask Parameter: PIDController3_LowerSaturationL
                               * Referenced by: '<S497>/Saturation'
                               */
  real_T PIDController1_LowerSaturatio_e;
                              /* Mask Parameter: PIDController1_LowerSaturatio_e
                               * Referenced by: '<S151>/Saturation'
                               */
  real_T PIDController_LowerSaturation_g;
                              /* Mask Parameter: PIDController_LowerSaturation_g
                               * Referenced by: '<S103>/Saturation'
                               */
  real_T PIDController2_N;             /* Mask Parameter: PIDController2_N
                                        * Referenced by: '<S546>/Filter Coefficient'
                                        */
  real_T PIDController1_N;             /* Mask Parameter: PIDController1_N
                                        * Referenced by: '<S397>/Filter Coefficient'
                                        */
  real_T PIDController_N;              /* Mask Parameter: PIDController_N
                                        * Referenced by: '<S594>/Filter Coefficient'
                                        */
  real_T PIDController2_N_h;           /* Mask Parameter: PIDController2_N_h
                                        * Referenced by: '<S445>/Filter Coefficient'
                                        */
  real_T PIDController3_N;             /* Mask Parameter: PIDController3_N
                                        * Referenced by: '<S493>/Filter Coefficient'
                                        */
  real_T PIDController1_N_j;           /* Mask Parameter: PIDController1_N_j
                                        * Referenced by: '<S45>/Filter Coefficient'
                                        */
  real_T PIDController1_N_h;           /* Mask Parameter: PIDController1_N_h
                                        * Referenced by: '<S147>/Filter Coefficient'
                                        */
  real_T PIDController_N_n;            /* Mask Parameter: PIDController_N_n
                                        * Referenced by: '<S198>/Filter Coefficient'
                                        */
  real_T PIDController_N_a;            /* Mask Parameter: PIDController_N_a
                                        * Referenced by: '<S99>/Filter Coefficient'
                                        */
  real_T PIDController2_N_g;           /* Mask Parameter: PIDController2_N_g
                                        * Referenced by: '<S246>/Filter Coefficient'
                                        */
  real_T PIDController3_N_n;           /* Mask Parameter: PIDController3_N_n
                                        * Referenced by: '<S294>/Filter Coefficient'
                                        */
  real_T PIDController_N_ah;           /* Mask Parameter: PIDController_N_ah
                                        * Referenced by: '<S349>/Filter Coefficient'
                                        */
  real_T PIDController2_P;             /* Mask Parameter: PIDController2_P
                                        * Referenced by: '<S548>/Proportional Gain'
                                        */
  real_T PIDController1_P;             /* Mask Parameter: PIDController1_P
                                        * Referenced by: '<S399>/Proportional Gain'
                                        */
  real_T PIDController_P;              /* Mask Parameter: PIDController_P
                                        * Referenced by: '<S596>/Proportional Gain'
                                        */
  real_T PIDController2_P_a;           /* Mask Parameter: PIDController2_P_a
                                        * Referenced by: '<S447>/Proportional Gain'
                                        */
  real_T PIDController3_P;             /* Mask Parameter: PIDController3_P
                                        * Referenced by: '<S495>/Proportional Gain'
                                        */
  real_T PIDController1_P_c;           /* Mask Parameter: PIDController1_P_c
                                        * Referenced by: '<S47>/Proportional Gain'
                                        */
  real_T PIDController1_P_j;           /* Mask Parameter: PIDController1_P_j
                                        * Referenced by: '<S149>/Proportional Gain'
                                        */
  real_T PIDController_P_e;            /* Mask Parameter: PIDController_P_e
                                        * Referenced by: '<S200>/Proportional Gain'
                                        */
  real_T PIDController_P_eb;           /* Mask Parameter: PIDController_P_eb
                                        * Referenced by: '<S101>/Proportional Gain'
                                        */
  real_T PIDController2_P_l;           /* Mask Parameter: PIDController2_P_l
                                        * Referenced by: '<S248>/Proportional Gain'
                                        */
  real_T PIDController3_P_l;           /* Mask Parameter: PIDController3_P_l
                                        * Referenced by: '<S296>/Proportional Gain'
                                        */
  real_T PIDController2_UpperSaturationL;
                              /* Mask Parameter: PIDController2_UpperSaturationL
                               * Referenced by: '<S550>/Saturation'
                               */
  real_T PIDController1_UpperSaturationL;
                              /* Mask Parameter: PIDController1_UpperSaturationL
                               * Referenced by: '<S401>/Saturation'
                               */
  real_T PIDController_UpperSaturationLi;
                              /* Mask Parameter: PIDController_UpperSaturationLi
                               * Referenced by: '<S598>/Saturation'
                               */
  real_T PIDController2_UpperSaturatio_e;
                              /* Mask Parameter: PIDController2_UpperSaturatio_e
                               * Referenced by: '<S449>/Saturation'
                               */
  real_T PIDController3_UpperSaturationL;
                              /* Mask Parameter: PIDController3_UpperSaturationL
                               * Referenced by: '<S497>/Saturation'
                               */
  real_T PIDController1_UpperSaturatio_o;
                              /* Mask Parameter: PIDController1_UpperSaturatio_o
                               * Referenced by: '<S151>/Saturation'
                               */
  real_T PIDController_UpperSaturation_g;
                              /* Mask Parameter: PIDController_UpperSaturation_g
                               * Referenced by: '<S103>/Saturation'
                               */
  real_T theta_dot_des_Y0;             /* Computed Parameter: theta_dot_des_Y0
                                        * Referenced by: '<S509>/theta_dot_des'
                                        */
  real_T Delay_InitialCondition[24];
                /* Expression: [0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0]
                 * Referenced by: '<Root>/Delay'
                 */
  real_T Constant_Value;               /* Expression: 0
                                        * Referenced by: '<S8>/Constant'
                                        */
  real_T Merge_InitialOutput;         /* Computed Parameter: Merge_InitialOutput
                                       * Referenced by: '<S310>/Merge'
                                       */
  real_T Gain1_Gain;                   /* Expression: -1
                                        * Referenced by: '<S9>/Gain1'
                                        */
  real_T Delay_InitialCondition_o;     /* Expression: 300
                                        * Referenced by: '<S1>/Delay'
                                        */
  real_T Gain1_Gain_l;                 /* Expression: -1
                                        * Referenced by: '<S59>/Gain1'
                                        */
  real_T Constant2_Value;              /* Expression: 0
                                        * Referenced by: '<S8>/Constant2'
                                        */
  real_T Gain1_Gain_b;                 /* Expression: 180/pi
                                        * Referenced by: '<S612>/Gain1'
                                        */
  real_T Gain_Gain;                    /* Expression: -1
                                        * Referenced by: '<S615>/Gain'
                                        */
  real_T Gain1_Gain_a;                 /* Expression: 180/pi
                                        * Referenced by: '<S615>/Gain1'
                                        */
  real_T Integrator3_IC;               /* Expression: 0
                                        * Referenced by: '<S2>/Integrator3'
                                        */
  real_T Integrator4_IC;               /* Expression: 0
                                        * Referenced by: '<S2>/Integrator4'
                                        */
  real_T Integrator5_IC;               /* Expression: 0
                                        * Referenced by: '<S2>/Integrator5'
                                        */
  real_T Integrator_IC;                /* Expression: 0
                                        * Referenced by: '<S2>/Integrator'
                                        */
  real_T Integrator1_IC;               /* Expression: 0
                                        * Referenced by: '<S2>/Integrator1'
                                        */
  real_T Delay_InitialCondition_m;     /* Expression: 0
                                        * Referenced by: '<S2>/Delay'
                                        */
  real_T Integrator2_IC;               /* Expression: 0
                                        * Referenced by: '<S2>/Integrator2'
                                        */
  real_T Integrator6_IC;               /* Expression: 0
                                        * Referenced by: '<S2>/Integrator6'
                                        */
  real_T Integrator7_IC;               /* Expression: 0
                                        * Referenced by: '<S2>/Integrator7'
                                        */
  real_T Integrator8_IC;               /* Expression: 0
                                        * Referenced by: '<S2>/Integrator8'
                                        */
  real_T Integrator9_IC;               /* Expression: 0
                                        * Referenced by: '<S2>/Integrator9'
                                        */
  real_T Integrator10_IC;              /* Expression: 0
                                        * Referenced by: '<S2>/Integrator10'
                                        */
  real_T Integrator11_IC;              /* Expression: 0
                                        * Referenced by: '<S2>/Integrator11'
                                        */
  real_T Gain1_Gain_bx;                /* Expression: -1
                                        * Referenced by: '<Root>/Gain1'
                                        */
  real_T Gain_Gain_m;                  /* Expression: -1
                                        * Referenced by: '<Root>/Gain'
                                        */
  real_T Gain2_Gain;                   /* Expression: -1
                                        * Referenced by: '<Root>/Gain2'
                                        */
  real_T Gain3_Gain;                   /* Expression: 180/pi
                                        * Referenced by: '<Root>/Gain3'
                                        */
  real_T Gain_Gain_k;                  /* Expression: 60/(2*pi)
                                        * Referenced by: '<S1>/Gain'
                                        */
  real_T Gain_Gain_c;                  /* Expression: -1
                                        * Referenced by: '<S619>/Gain'
                                        */
  real_T Gain_Gain_d;                  /* Expression: -1
                                        * Referenced by: '<S620>/Gain'
                                        */
  real_T Gain_Gain_g;                  /* Expression: -1
                                        * Referenced by: '<S621>/Gain'
                                        */
  real_T Gain_Gain_d0;                 /* Expression: -1
                                        * Referenced by: '<S622>/Gain'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_Quad_biplane_T {
  const char_T *errorStatus;
  RTWLogInfo *rtwLogInfo;
  RTWSolverInfo solverInfo;
  X_Quad_biplane_T *contStates;
  int_T *periodicContStateIndices;
  real_T *periodicContStateRanges;
  real_T *derivs;
  boolean_T *contStateDisabled;
  boolean_T zCCacheNeedsReset;
  boolean_T derivCacheNeedsReset;
  boolean_T CTOutputIncnstWithState;
  real_T odeY[36];
  real_T odeF[4][36];
  ODE4_IntgData intgData;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    int_T numContStates;
    int_T numPeriodicContStates;
    int_T numSampTimes;
  } Sizes;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    uint32_T clockTick1;
    uint32_T clockTickH1;
    time_T tFinal;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

/* Block parameters (default storage) */
extern P_Quad_biplane_T Quad_biplane_P;

/* Block signals (default storage) */
extern B_Quad_biplane_T Quad_biplane_B;

/* Continuous states (default storage) */
extern X_Quad_biplane_T Quad_biplane_X;

/* Block states (default storage) */
extern DW_Quad_biplane_T Quad_biplane_DW;

/* Zero-crossing (trigger) state */
extern PrevZCX_Quad_biplane_T Quad_biplane_PrevZCX;

/* Model entry point functions */
extern void Quad_biplane_initialize(void);
extern void Quad_biplane_step(void);
extern void Quad_biplane_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Quad_biplane_T *const Quad_biplane_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'Quad_biplane'
 * '<S1>'   : 'Quad_biplane/Control System'
 * '<S2>'   : 'Quad_biplane/Flight Dynamics'
 * '<S3>'   : 'Quad_biplane/Mission Profile'
 * '<S4>'   : 'Quad_biplane/Vehicle Performance'
 * '<S5>'   : 'Quad_biplane/Control System/Altitude Controller'
 * '<S6>'   : 'Quad_biplane/Control System/Attitude Controller'
 * '<S7>'   : 'Quad_biplane/Control System/MATLAB Function'
 * '<S8>'   : 'Quad_biplane/Control System/Position Controller'
 * '<S9>'   : 'Quad_biplane/Control System/Altitude Controller/Velocity Controller'
 * '<S10>'  : 'Quad_biplane/Control System/Altitude Controller/Velocity Controller/PID Controller1'
 * '<S11>'  : 'Quad_biplane/Control System/Altitude Controller/Velocity Controller/PID Controller1/Anti-windup'
 * '<S12>'  : 'Quad_biplane/Control System/Altitude Controller/Velocity Controller/PID Controller1/D Gain'
 * '<S13>'  : 'Quad_biplane/Control System/Altitude Controller/Velocity Controller/PID Controller1/Filter'
 * '<S14>'  : 'Quad_biplane/Control System/Altitude Controller/Velocity Controller/PID Controller1/Filter ICs'
 * '<S15>'  : 'Quad_biplane/Control System/Altitude Controller/Velocity Controller/PID Controller1/I Gain'
 * '<S16>'  : 'Quad_biplane/Control System/Altitude Controller/Velocity Controller/PID Controller1/Ideal P Gain'
 * '<S17>'  : 'Quad_biplane/Control System/Altitude Controller/Velocity Controller/PID Controller1/Ideal P Gain Fdbk'
 * '<S18>'  : 'Quad_biplane/Control System/Altitude Controller/Velocity Controller/PID Controller1/Integrator'
 * '<S19>'  : 'Quad_biplane/Control System/Altitude Controller/Velocity Controller/PID Controller1/Integrator ICs'
 * '<S20>'  : 'Quad_biplane/Control System/Altitude Controller/Velocity Controller/PID Controller1/N Copy'
 * '<S21>'  : 'Quad_biplane/Control System/Altitude Controller/Velocity Controller/PID Controller1/N Gain'
 * '<S22>'  : 'Quad_biplane/Control System/Altitude Controller/Velocity Controller/PID Controller1/P Copy'
 * '<S23>'  : 'Quad_biplane/Control System/Altitude Controller/Velocity Controller/PID Controller1/Parallel P Gain'
 * '<S24>'  : 'Quad_biplane/Control System/Altitude Controller/Velocity Controller/PID Controller1/Reset Signal'
 * '<S25>'  : 'Quad_biplane/Control System/Altitude Controller/Velocity Controller/PID Controller1/Saturation'
 * '<S26>'  : 'Quad_biplane/Control System/Altitude Controller/Velocity Controller/PID Controller1/Saturation Fdbk'
 * '<S27>'  : 'Quad_biplane/Control System/Altitude Controller/Velocity Controller/PID Controller1/Sum'
 * '<S28>'  : 'Quad_biplane/Control System/Altitude Controller/Velocity Controller/PID Controller1/Sum Fdbk'
 * '<S29>'  : 'Quad_biplane/Control System/Altitude Controller/Velocity Controller/PID Controller1/Tracking Mode'
 * '<S30>'  : 'Quad_biplane/Control System/Altitude Controller/Velocity Controller/PID Controller1/Tracking Mode Sum'
 * '<S31>'  : 'Quad_biplane/Control System/Altitude Controller/Velocity Controller/PID Controller1/Tsamp - Integral'
 * '<S32>'  : 'Quad_biplane/Control System/Altitude Controller/Velocity Controller/PID Controller1/Tsamp - Ngain'
 * '<S33>'  : 'Quad_biplane/Control System/Altitude Controller/Velocity Controller/PID Controller1/postSat Signal'
 * '<S34>'  : 'Quad_biplane/Control System/Altitude Controller/Velocity Controller/PID Controller1/preSat Signal'
 * '<S35>'  : 'Quad_biplane/Control System/Altitude Controller/Velocity Controller/PID Controller1/Anti-windup/Passthrough'
 * '<S36>'  : 'Quad_biplane/Control System/Altitude Controller/Velocity Controller/PID Controller1/D Gain/Internal Parameters'
 * '<S37>'  : 'Quad_biplane/Control System/Altitude Controller/Velocity Controller/PID Controller1/Filter/Cont. Filter'
 * '<S38>'  : 'Quad_biplane/Control System/Altitude Controller/Velocity Controller/PID Controller1/Filter ICs/Internal IC - Filter'
 * '<S39>'  : 'Quad_biplane/Control System/Altitude Controller/Velocity Controller/PID Controller1/I Gain/Internal Parameters'
 * '<S40>'  : 'Quad_biplane/Control System/Altitude Controller/Velocity Controller/PID Controller1/Ideal P Gain/Passthrough'
 * '<S41>'  : 'Quad_biplane/Control System/Altitude Controller/Velocity Controller/PID Controller1/Ideal P Gain Fdbk/Disabled'
 * '<S42>'  : 'Quad_biplane/Control System/Altitude Controller/Velocity Controller/PID Controller1/Integrator/Continuous'
 * '<S43>'  : 'Quad_biplane/Control System/Altitude Controller/Velocity Controller/PID Controller1/Integrator ICs/Internal IC'
 * '<S44>'  : 'Quad_biplane/Control System/Altitude Controller/Velocity Controller/PID Controller1/N Copy/Disabled'
 * '<S45>'  : 'Quad_biplane/Control System/Altitude Controller/Velocity Controller/PID Controller1/N Gain/Internal Parameters'
 * '<S46>'  : 'Quad_biplane/Control System/Altitude Controller/Velocity Controller/PID Controller1/P Copy/Disabled'
 * '<S47>'  : 'Quad_biplane/Control System/Altitude Controller/Velocity Controller/PID Controller1/Parallel P Gain/Internal Parameters'
 * '<S48>'  : 'Quad_biplane/Control System/Altitude Controller/Velocity Controller/PID Controller1/Reset Signal/Disabled'
 * '<S49>'  : 'Quad_biplane/Control System/Altitude Controller/Velocity Controller/PID Controller1/Saturation/Passthrough'
 * '<S50>'  : 'Quad_biplane/Control System/Altitude Controller/Velocity Controller/PID Controller1/Saturation Fdbk/Disabled'
 * '<S51>'  : 'Quad_biplane/Control System/Altitude Controller/Velocity Controller/PID Controller1/Sum/Sum_PID'
 * '<S52>'  : 'Quad_biplane/Control System/Altitude Controller/Velocity Controller/PID Controller1/Sum Fdbk/Disabled'
 * '<S53>'  : 'Quad_biplane/Control System/Altitude Controller/Velocity Controller/PID Controller1/Tracking Mode/Disabled'
 * '<S54>'  : 'Quad_biplane/Control System/Altitude Controller/Velocity Controller/PID Controller1/Tracking Mode Sum/Passthrough'
 * '<S55>'  : 'Quad_biplane/Control System/Altitude Controller/Velocity Controller/PID Controller1/Tsamp - Integral/Passthrough'
 * '<S56>'  : 'Quad_biplane/Control System/Altitude Controller/Velocity Controller/PID Controller1/Tsamp - Ngain/Passthrough'
 * '<S57>'  : 'Quad_biplane/Control System/Altitude Controller/Velocity Controller/PID Controller1/postSat Signal/Forward_Path'
 * '<S58>'  : 'Quad_biplane/Control System/Altitude Controller/Velocity Controller/PID Controller1/preSat Signal/Forward_Path'
 * '<S59>'  : 'Quad_biplane/Control System/Attitude Controller/Velocity'
 * '<S60>'  : 'Quad_biplane/Control System/Attitude Controller/moments'
 * '<S61>'  : 'Quad_biplane/Control System/Attitude Controller/Velocity/If Action Subsystem'
 * '<S62>'  : 'Quad_biplane/Control System/Attitude Controller/Velocity/If Action Subsystem1'
 * '<S63>'  : 'Quad_biplane/Control System/Attitude Controller/Velocity/PID Controller'
 * '<S64>'  : 'Quad_biplane/Control System/Attitude Controller/Velocity/PID Controller1'
 * '<S65>'  : 'Quad_biplane/Control System/Attitude Controller/Velocity/PID Controller/Anti-windup'
 * '<S66>'  : 'Quad_biplane/Control System/Attitude Controller/Velocity/PID Controller/D Gain'
 * '<S67>'  : 'Quad_biplane/Control System/Attitude Controller/Velocity/PID Controller/Filter'
 * '<S68>'  : 'Quad_biplane/Control System/Attitude Controller/Velocity/PID Controller/Filter ICs'
 * '<S69>'  : 'Quad_biplane/Control System/Attitude Controller/Velocity/PID Controller/I Gain'
 * '<S70>'  : 'Quad_biplane/Control System/Attitude Controller/Velocity/PID Controller/Ideal P Gain'
 * '<S71>'  : 'Quad_biplane/Control System/Attitude Controller/Velocity/PID Controller/Ideal P Gain Fdbk'
 * '<S72>'  : 'Quad_biplane/Control System/Attitude Controller/Velocity/PID Controller/Integrator'
 * '<S73>'  : 'Quad_biplane/Control System/Attitude Controller/Velocity/PID Controller/Integrator ICs'
 * '<S74>'  : 'Quad_biplane/Control System/Attitude Controller/Velocity/PID Controller/N Copy'
 * '<S75>'  : 'Quad_biplane/Control System/Attitude Controller/Velocity/PID Controller/N Gain'
 * '<S76>'  : 'Quad_biplane/Control System/Attitude Controller/Velocity/PID Controller/P Copy'
 * '<S77>'  : 'Quad_biplane/Control System/Attitude Controller/Velocity/PID Controller/Parallel P Gain'
 * '<S78>'  : 'Quad_biplane/Control System/Attitude Controller/Velocity/PID Controller/Reset Signal'
 * '<S79>'  : 'Quad_biplane/Control System/Attitude Controller/Velocity/PID Controller/Saturation'
 * '<S80>'  : 'Quad_biplane/Control System/Attitude Controller/Velocity/PID Controller/Saturation Fdbk'
 * '<S81>'  : 'Quad_biplane/Control System/Attitude Controller/Velocity/PID Controller/Sum'
 * '<S82>'  : 'Quad_biplane/Control System/Attitude Controller/Velocity/PID Controller/Sum Fdbk'
 * '<S83>'  : 'Quad_biplane/Control System/Attitude Controller/Velocity/PID Controller/Tracking Mode'
 * '<S84>'  : 'Quad_biplane/Control System/Attitude Controller/Velocity/PID Controller/Tracking Mode Sum'
 * '<S85>'  : 'Quad_biplane/Control System/Attitude Controller/Velocity/PID Controller/Tsamp - Integral'
 * '<S86>'  : 'Quad_biplane/Control System/Attitude Controller/Velocity/PID Controller/Tsamp - Ngain'
 * '<S87>'  : 'Quad_biplane/Control System/Attitude Controller/Velocity/PID Controller/postSat Signal'
 * '<S88>'  : 'Quad_biplane/Control System/Attitude Controller/Velocity/PID Controller/preSat Signal'
 * '<S89>'  : 'Quad_biplane/Control System/Attitude Controller/Velocity/PID Controller/Anti-windup/Passthrough'
 * '<S90>'  : 'Quad_biplane/Control System/Attitude Controller/Velocity/PID Controller/D Gain/Internal Parameters'
 * '<S91>'  : 'Quad_biplane/Control System/Attitude Controller/Velocity/PID Controller/Filter/Cont. Filter'
 * '<S92>'  : 'Quad_biplane/Control System/Attitude Controller/Velocity/PID Controller/Filter ICs/Internal IC - Filter'
 * '<S93>'  : 'Quad_biplane/Control System/Attitude Controller/Velocity/PID Controller/I Gain/Internal Parameters'
 * '<S94>'  : 'Quad_biplane/Control System/Attitude Controller/Velocity/PID Controller/Ideal P Gain/Passthrough'
 * '<S95>'  : 'Quad_biplane/Control System/Attitude Controller/Velocity/PID Controller/Ideal P Gain Fdbk/Disabled'
 * '<S96>'  : 'Quad_biplane/Control System/Attitude Controller/Velocity/PID Controller/Integrator/Continuous'
 * '<S97>'  : 'Quad_biplane/Control System/Attitude Controller/Velocity/PID Controller/Integrator ICs/Internal IC'
 * '<S98>'  : 'Quad_biplane/Control System/Attitude Controller/Velocity/PID Controller/N Copy/Disabled'
 * '<S99>'  : 'Quad_biplane/Control System/Attitude Controller/Velocity/PID Controller/N Gain/Internal Parameters'
 * '<S100>' : 'Quad_biplane/Control System/Attitude Controller/Velocity/PID Controller/P Copy/Disabled'
 * '<S101>' : 'Quad_biplane/Control System/Attitude Controller/Velocity/PID Controller/Parallel P Gain/Internal Parameters'
 * '<S102>' : 'Quad_biplane/Control System/Attitude Controller/Velocity/PID Controller/Reset Signal/Disabled'
 * '<S103>' : 'Quad_biplane/Control System/Attitude Controller/Velocity/PID Controller/Saturation/Enabled'
 * '<S104>' : 'Quad_biplane/Control System/Attitude Controller/Velocity/PID Controller/Saturation Fdbk/Disabled'
 * '<S105>' : 'Quad_biplane/Control System/Attitude Controller/Velocity/PID Controller/Sum/Sum_PID'
 * '<S106>' : 'Quad_biplane/Control System/Attitude Controller/Velocity/PID Controller/Sum Fdbk/Disabled'
 * '<S107>' : 'Quad_biplane/Control System/Attitude Controller/Velocity/PID Controller/Tracking Mode/Disabled'
 * '<S108>' : 'Quad_biplane/Control System/Attitude Controller/Velocity/PID Controller/Tracking Mode Sum/Passthrough'
 * '<S109>' : 'Quad_biplane/Control System/Attitude Controller/Velocity/PID Controller/Tsamp - Integral/Passthrough'
 * '<S110>' : 'Quad_biplane/Control System/Attitude Controller/Velocity/PID Controller/Tsamp - Ngain/Passthrough'
 * '<S111>' : 'Quad_biplane/Control System/Attitude Controller/Velocity/PID Controller/postSat Signal/Forward_Path'
 * '<S112>' : 'Quad_biplane/Control System/Attitude Controller/Velocity/PID Controller/preSat Signal/Forward_Path'
 * '<S113>' : 'Quad_biplane/Control System/Attitude Controller/Velocity/PID Controller1/Anti-windup'
 * '<S114>' : 'Quad_biplane/Control System/Attitude Controller/Velocity/PID Controller1/D Gain'
 * '<S115>' : 'Quad_biplane/Control System/Attitude Controller/Velocity/PID Controller1/Filter'
 * '<S116>' : 'Quad_biplane/Control System/Attitude Controller/Velocity/PID Controller1/Filter ICs'
 * '<S117>' : 'Quad_biplane/Control System/Attitude Controller/Velocity/PID Controller1/I Gain'
 * '<S118>' : 'Quad_biplane/Control System/Attitude Controller/Velocity/PID Controller1/Ideal P Gain'
 * '<S119>' : 'Quad_biplane/Control System/Attitude Controller/Velocity/PID Controller1/Ideal P Gain Fdbk'
 * '<S120>' : 'Quad_biplane/Control System/Attitude Controller/Velocity/PID Controller1/Integrator'
 * '<S121>' : 'Quad_biplane/Control System/Attitude Controller/Velocity/PID Controller1/Integrator ICs'
 * '<S122>' : 'Quad_biplane/Control System/Attitude Controller/Velocity/PID Controller1/N Copy'
 * '<S123>' : 'Quad_biplane/Control System/Attitude Controller/Velocity/PID Controller1/N Gain'
 * '<S124>' : 'Quad_biplane/Control System/Attitude Controller/Velocity/PID Controller1/P Copy'
 * '<S125>' : 'Quad_biplane/Control System/Attitude Controller/Velocity/PID Controller1/Parallel P Gain'
 * '<S126>' : 'Quad_biplane/Control System/Attitude Controller/Velocity/PID Controller1/Reset Signal'
 * '<S127>' : 'Quad_biplane/Control System/Attitude Controller/Velocity/PID Controller1/Saturation'
 * '<S128>' : 'Quad_biplane/Control System/Attitude Controller/Velocity/PID Controller1/Saturation Fdbk'
 * '<S129>' : 'Quad_biplane/Control System/Attitude Controller/Velocity/PID Controller1/Sum'
 * '<S130>' : 'Quad_biplane/Control System/Attitude Controller/Velocity/PID Controller1/Sum Fdbk'
 * '<S131>' : 'Quad_biplane/Control System/Attitude Controller/Velocity/PID Controller1/Tracking Mode'
 * '<S132>' : 'Quad_biplane/Control System/Attitude Controller/Velocity/PID Controller1/Tracking Mode Sum'
 * '<S133>' : 'Quad_biplane/Control System/Attitude Controller/Velocity/PID Controller1/Tsamp - Integral'
 * '<S134>' : 'Quad_biplane/Control System/Attitude Controller/Velocity/PID Controller1/Tsamp - Ngain'
 * '<S135>' : 'Quad_biplane/Control System/Attitude Controller/Velocity/PID Controller1/postSat Signal'
 * '<S136>' : 'Quad_biplane/Control System/Attitude Controller/Velocity/PID Controller1/preSat Signal'
 * '<S137>' : 'Quad_biplane/Control System/Attitude Controller/Velocity/PID Controller1/Anti-windup/Passthrough'
 * '<S138>' : 'Quad_biplane/Control System/Attitude Controller/Velocity/PID Controller1/D Gain/Internal Parameters'
 * '<S139>' : 'Quad_biplane/Control System/Attitude Controller/Velocity/PID Controller1/Filter/Cont. Filter'
 * '<S140>' : 'Quad_biplane/Control System/Attitude Controller/Velocity/PID Controller1/Filter ICs/Internal IC - Filter'
 * '<S141>' : 'Quad_biplane/Control System/Attitude Controller/Velocity/PID Controller1/I Gain/Internal Parameters'
 * '<S142>' : 'Quad_biplane/Control System/Attitude Controller/Velocity/PID Controller1/Ideal P Gain/Passthrough'
 * '<S143>' : 'Quad_biplane/Control System/Attitude Controller/Velocity/PID Controller1/Ideal P Gain Fdbk/Disabled'
 * '<S144>' : 'Quad_biplane/Control System/Attitude Controller/Velocity/PID Controller1/Integrator/Continuous'
 * '<S145>' : 'Quad_biplane/Control System/Attitude Controller/Velocity/PID Controller1/Integrator ICs/Internal IC'
 * '<S146>' : 'Quad_biplane/Control System/Attitude Controller/Velocity/PID Controller1/N Copy/Disabled'
 * '<S147>' : 'Quad_biplane/Control System/Attitude Controller/Velocity/PID Controller1/N Gain/Internal Parameters'
 * '<S148>' : 'Quad_biplane/Control System/Attitude Controller/Velocity/PID Controller1/P Copy/Disabled'
 * '<S149>' : 'Quad_biplane/Control System/Attitude Controller/Velocity/PID Controller1/Parallel P Gain/Internal Parameters'
 * '<S150>' : 'Quad_biplane/Control System/Attitude Controller/Velocity/PID Controller1/Reset Signal/Disabled'
 * '<S151>' : 'Quad_biplane/Control System/Attitude Controller/Velocity/PID Controller1/Saturation/Enabled'
 * '<S152>' : 'Quad_biplane/Control System/Attitude Controller/Velocity/PID Controller1/Saturation Fdbk/Disabled'
 * '<S153>' : 'Quad_biplane/Control System/Attitude Controller/Velocity/PID Controller1/Sum/Sum_PID'
 * '<S154>' : 'Quad_biplane/Control System/Attitude Controller/Velocity/PID Controller1/Sum Fdbk/Disabled'
 * '<S155>' : 'Quad_biplane/Control System/Attitude Controller/Velocity/PID Controller1/Tracking Mode/Disabled'
 * '<S156>' : 'Quad_biplane/Control System/Attitude Controller/Velocity/PID Controller1/Tracking Mode Sum/Passthrough'
 * '<S157>' : 'Quad_biplane/Control System/Attitude Controller/Velocity/PID Controller1/Tsamp - Integral/Passthrough'
 * '<S158>' : 'Quad_biplane/Control System/Attitude Controller/Velocity/PID Controller1/Tsamp - Ngain/Passthrough'
 * '<S159>' : 'Quad_biplane/Control System/Attitude Controller/Velocity/PID Controller1/postSat Signal/Forward_Path'
 * '<S160>' : 'Quad_biplane/Control System/Attitude Controller/Velocity/PID Controller1/preSat Signal/Forward_Path'
 * '<S161>' : 'Quad_biplane/Control System/Attitude Controller/moments/PID Controller'
 * '<S162>' : 'Quad_biplane/Control System/Attitude Controller/moments/PID Controller2'
 * '<S163>' : 'Quad_biplane/Control System/Attitude Controller/moments/PID Controller3'
 * '<S164>' : 'Quad_biplane/Control System/Attitude Controller/moments/PID Controller/Anti-windup'
 * '<S165>' : 'Quad_biplane/Control System/Attitude Controller/moments/PID Controller/D Gain'
 * '<S166>' : 'Quad_biplane/Control System/Attitude Controller/moments/PID Controller/Filter'
 * '<S167>' : 'Quad_biplane/Control System/Attitude Controller/moments/PID Controller/Filter ICs'
 * '<S168>' : 'Quad_biplane/Control System/Attitude Controller/moments/PID Controller/I Gain'
 * '<S169>' : 'Quad_biplane/Control System/Attitude Controller/moments/PID Controller/Ideal P Gain'
 * '<S170>' : 'Quad_biplane/Control System/Attitude Controller/moments/PID Controller/Ideal P Gain Fdbk'
 * '<S171>' : 'Quad_biplane/Control System/Attitude Controller/moments/PID Controller/Integrator'
 * '<S172>' : 'Quad_biplane/Control System/Attitude Controller/moments/PID Controller/Integrator ICs'
 * '<S173>' : 'Quad_biplane/Control System/Attitude Controller/moments/PID Controller/N Copy'
 * '<S174>' : 'Quad_biplane/Control System/Attitude Controller/moments/PID Controller/N Gain'
 * '<S175>' : 'Quad_biplane/Control System/Attitude Controller/moments/PID Controller/P Copy'
 * '<S176>' : 'Quad_biplane/Control System/Attitude Controller/moments/PID Controller/Parallel P Gain'
 * '<S177>' : 'Quad_biplane/Control System/Attitude Controller/moments/PID Controller/Reset Signal'
 * '<S178>' : 'Quad_biplane/Control System/Attitude Controller/moments/PID Controller/Saturation'
 * '<S179>' : 'Quad_biplane/Control System/Attitude Controller/moments/PID Controller/Saturation Fdbk'
 * '<S180>' : 'Quad_biplane/Control System/Attitude Controller/moments/PID Controller/Sum'
 * '<S181>' : 'Quad_biplane/Control System/Attitude Controller/moments/PID Controller/Sum Fdbk'
 * '<S182>' : 'Quad_biplane/Control System/Attitude Controller/moments/PID Controller/Tracking Mode'
 * '<S183>' : 'Quad_biplane/Control System/Attitude Controller/moments/PID Controller/Tracking Mode Sum'
 * '<S184>' : 'Quad_biplane/Control System/Attitude Controller/moments/PID Controller/Tsamp - Integral'
 * '<S185>' : 'Quad_biplane/Control System/Attitude Controller/moments/PID Controller/Tsamp - Ngain'
 * '<S186>' : 'Quad_biplane/Control System/Attitude Controller/moments/PID Controller/postSat Signal'
 * '<S187>' : 'Quad_biplane/Control System/Attitude Controller/moments/PID Controller/preSat Signal'
 * '<S188>' : 'Quad_biplane/Control System/Attitude Controller/moments/PID Controller/Anti-windup/Passthrough'
 * '<S189>' : 'Quad_biplane/Control System/Attitude Controller/moments/PID Controller/D Gain/Internal Parameters'
 * '<S190>' : 'Quad_biplane/Control System/Attitude Controller/moments/PID Controller/Filter/Cont. Filter'
 * '<S191>' : 'Quad_biplane/Control System/Attitude Controller/moments/PID Controller/Filter ICs/Internal IC - Filter'
 * '<S192>' : 'Quad_biplane/Control System/Attitude Controller/moments/PID Controller/I Gain/Internal Parameters'
 * '<S193>' : 'Quad_biplane/Control System/Attitude Controller/moments/PID Controller/Ideal P Gain/Passthrough'
 * '<S194>' : 'Quad_biplane/Control System/Attitude Controller/moments/PID Controller/Ideal P Gain Fdbk/Disabled'
 * '<S195>' : 'Quad_biplane/Control System/Attitude Controller/moments/PID Controller/Integrator/Continuous'
 * '<S196>' : 'Quad_biplane/Control System/Attitude Controller/moments/PID Controller/Integrator ICs/Internal IC'
 * '<S197>' : 'Quad_biplane/Control System/Attitude Controller/moments/PID Controller/N Copy/Disabled'
 * '<S198>' : 'Quad_biplane/Control System/Attitude Controller/moments/PID Controller/N Gain/Internal Parameters'
 * '<S199>' : 'Quad_biplane/Control System/Attitude Controller/moments/PID Controller/P Copy/Disabled'
 * '<S200>' : 'Quad_biplane/Control System/Attitude Controller/moments/PID Controller/Parallel P Gain/Internal Parameters'
 * '<S201>' : 'Quad_biplane/Control System/Attitude Controller/moments/PID Controller/Reset Signal/Disabled'
 * '<S202>' : 'Quad_biplane/Control System/Attitude Controller/moments/PID Controller/Saturation/Passthrough'
 * '<S203>' : 'Quad_biplane/Control System/Attitude Controller/moments/PID Controller/Saturation Fdbk/Disabled'
 * '<S204>' : 'Quad_biplane/Control System/Attitude Controller/moments/PID Controller/Sum/Sum_PID'
 * '<S205>' : 'Quad_biplane/Control System/Attitude Controller/moments/PID Controller/Sum Fdbk/Disabled'
 * '<S206>' : 'Quad_biplane/Control System/Attitude Controller/moments/PID Controller/Tracking Mode/Disabled'
 * '<S207>' : 'Quad_biplane/Control System/Attitude Controller/moments/PID Controller/Tracking Mode Sum/Passthrough'
 * '<S208>' : 'Quad_biplane/Control System/Attitude Controller/moments/PID Controller/Tsamp - Integral/Passthrough'
 * '<S209>' : 'Quad_biplane/Control System/Attitude Controller/moments/PID Controller/Tsamp - Ngain/Passthrough'
 * '<S210>' : 'Quad_biplane/Control System/Attitude Controller/moments/PID Controller/postSat Signal/Forward_Path'
 * '<S211>' : 'Quad_biplane/Control System/Attitude Controller/moments/PID Controller/preSat Signal/Forward_Path'
 * '<S212>' : 'Quad_biplane/Control System/Attitude Controller/moments/PID Controller2/Anti-windup'
 * '<S213>' : 'Quad_biplane/Control System/Attitude Controller/moments/PID Controller2/D Gain'
 * '<S214>' : 'Quad_biplane/Control System/Attitude Controller/moments/PID Controller2/Filter'
 * '<S215>' : 'Quad_biplane/Control System/Attitude Controller/moments/PID Controller2/Filter ICs'
 * '<S216>' : 'Quad_biplane/Control System/Attitude Controller/moments/PID Controller2/I Gain'
 * '<S217>' : 'Quad_biplane/Control System/Attitude Controller/moments/PID Controller2/Ideal P Gain'
 * '<S218>' : 'Quad_biplane/Control System/Attitude Controller/moments/PID Controller2/Ideal P Gain Fdbk'
 * '<S219>' : 'Quad_biplane/Control System/Attitude Controller/moments/PID Controller2/Integrator'
 * '<S220>' : 'Quad_biplane/Control System/Attitude Controller/moments/PID Controller2/Integrator ICs'
 * '<S221>' : 'Quad_biplane/Control System/Attitude Controller/moments/PID Controller2/N Copy'
 * '<S222>' : 'Quad_biplane/Control System/Attitude Controller/moments/PID Controller2/N Gain'
 * '<S223>' : 'Quad_biplane/Control System/Attitude Controller/moments/PID Controller2/P Copy'
 * '<S224>' : 'Quad_biplane/Control System/Attitude Controller/moments/PID Controller2/Parallel P Gain'
 * '<S225>' : 'Quad_biplane/Control System/Attitude Controller/moments/PID Controller2/Reset Signal'
 * '<S226>' : 'Quad_biplane/Control System/Attitude Controller/moments/PID Controller2/Saturation'
 * '<S227>' : 'Quad_biplane/Control System/Attitude Controller/moments/PID Controller2/Saturation Fdbk'
 * '<S228>' : 'Quad_biplane/Control System/Attitude Controller/moments/PID Controller2/Sum'
 * '<S229>' : 'Quad_biplane/Control System/Attitude Controller/moments/PID Controller2/Sum Fdbk'
 * '<S230>' : 'Quad_biplane/Control System/Attitude Controller/moments/PID Controller2/Tracking Mode'
 * '<S231>' : 'Quad_biplane/Control System/Attitude Controller/moments/PID Controller2/Tracking Mode Sum'
 * '<S232>' : 'Quad_biplane/Control System/Attitude Controller/moments/PID Controller2/Tsamp - Integral'
 * '<S233>' : 'Quad_biplane/Control System/Attitude Controller/moments/PID Controller2/Tsamp - Ngain'
 * '<S234>' : 'Quad_biplane/Control System/Attitude Controller/moments/PID Controller2/postSat Signal'
 * '<S235>' : 'Quad_biplane/Control System/Attitude Controller/moments/PID Controller2/preSat Signal'
 * '<S236>' : 'Quad_biplane/Control System/Attitude Controller/moments/PID Controller2/Anti-windup/Passthrough'
 * '<S237>' : 'Quad_biplane/Control System/Attitude Controller/moments/PID Controller2/D Gain/Internal Parameters'
 * '<S238>' : 'Quad_biplane/Control System/Attitude Controller/moments/PID Controller2/Filter/Cont. Filter'
 * '<S239>' : 'Quad_biplane/Control System/Attitude Controller/moments/PID Controller2/Filter ICs/Internal IC - Filter'
 * '<S240>' : 'Quad_biplane/Control System/Attitude Controller/moments/PID Controller2/I Gain/Internal Parameters'
 * '<S241>' : 'Quad_biplane/Control System/Attitude Controller/moments/PID Controller2/Ideal P Gain/Passthrough'
 * '<S242>' : 'Quad_biplane/Control System/Attitude Controller/moments/PID Controller2/Ideal P Gain Fdbk/Disabled'
 * '<S243>' : 'Quad_biplane/Control System/Attitude Controller/moments/PID Controller2/Integrator/Continuous'
 * '<S244>' : 'Quad_biplane/Control System/Attitude Controller/moments/PID Controller2/Integrator ICs/Internal IC'
 * '<S245>' : 'Quad_biplane/Control System/Attitude Controller/moments/PID Controller2/N Copy/Disabled'
 * '<S246>' : 'Quad_biplane/Control System/Attitude Controller/moments/PID Controller2/N Gain/Internal Parameters'
 * '<S247>' : 'Quad_biplane/Control System/Attitude Controller/moments/PID Controller2/P Copy/Disabled'
 * '<S248>' : 'Quad_biplane/Control System/Attitude Controller/moments/PID Controller2/Parallel P Gain/Internal Parameters'
 * '<S249>' : 'Quad_biplane/Control System/Attitude Controller/moments/PID Controller2/Reset Signal/Disabled'
 * '<S250>' : 'Quad_biplane/Control System/Attitude Controller/moments/PID Controller2/Saturation/Passthrough'
 * '<S251>' : 'Quad_biplane/Control System/Attitude Controller/moments/PID Controller2/Saturation Fdbk/Disabled'
 * '<S252>' : 'Quad_biplane/Control System/Attitude Controller/moments/PID Controller2/Sum/Sum_PID'
 * '<S253>' : 'Quad_biplane/Control System/Attitude Controller/moments/PID Controller2/Sum Fdbk/Disabled'
 * '<S254>' : 'Quad_biplane/Control System/Attitude Controller/moments/PID Controller2/Tracking Mode/Disabled'
 * '<S255>' : 'Quad_biplane/Control System/Attitude Controller/moments/PID Controller2/Tracking Mode Sum/Passthrough'
 * '<S256>' : 'Quad_biplane/Control System/Attitude Controller/moments/PID Controller2/Tsamp - Integral/Passthrough'
 * '<S257>' : 'Quad_biplane/Control System/Attitude Controller/moments/PID Controller2/Tsamp - Ngain/Passthrough'
 * '<S258>' : 'Quad_biplane/Control System/Attitude Controller/moments/PID Controller2/postSat Signal/Forward_Path'
 * '<S259>' : 'Quad_biplane/Control System/Attitude Controller/moments/PID Controller2/preSat Signal/Forward_Path'
 * '<S260>' : 'Quad_biplane/Control System/Attitude Controller/moments/PID Controller3/Anti-windup'
 * '<S261>' : 'Quad_biplane/Control System/Attitude Controller/moments/PID Controller3/D Gain'
 * '<S262>' : 'Quad_biplane/Control System/Attitude Controller/moments/PID Controller3/Filter'
 * '<S263>' : 'Quad_biplane/Control System/Attitude Controller/moments/PID Controller3/Filter ICs'
 * '<S264>' : 'Quad_biplane/Control System/Attitude Controller/moments/PID Controller3/I Gain'
 * '<S265>' : 'Quad_biplane/Control System/Attitude Controller/moments/PID Controller3/Ideal P Gain'
 * '<S266>' : 'Quad_biplane/Control System/Attitude Controller/moments/PID Controller3/Ideal P Gain Fdbk'
 * '<S267>' : 'Quad_biplane/Control System/Attitude Controller/moments/PID Controller3/Integrator'
 * '<S268>' : 'Quad_biplane/Control System/Attitude Controller/moments/PID Controller3/Integrator ICs'
 * '<S269>' : 'Quad_biplane/Control System/Attitude Controller/moments/PID Controller3/N Copy'
 * '<S270>' : 'Quad_biplane/Control System/Attitude Controller/moments/PID Controller3/N Gain'
 * '<S271>' : 'Quad_biplane/Control System/Attitude Controller/moments/PID Controller3/P Copy'
 * '<S272>' : 'Quad_biplane/Control System/Attitude Controller/moments/PID Controller3/Parallel P Gain'
 * '<S273>' : 'Quad_biplane/Control System/Attitude Controller/moments/PID Controller3/Reset Signal'
 * '<S274>' : 'Quad_biplane/Control System/Attitude Controller/moments/PID Controller3/Saturation'
 * '<S275>' : 'Quad_biplane/Control System/Attitude Controller/moments/PID Controller3/Saturation Fdbk'
 * '<S276>' : 'Quad_biplane/Control System/Attitude Controller/moments/PID Controller3/Sum'
 * '<S277>' : 'Quad_biplane/Control System/Attitude Controller/moments/PID Controller3/Sum Fdbk'
 * '<S278>' : 'Quad_biplane/Control System/Attitude Controller/moments/PID Controller3/Tracking Mode'
 * '<S279>' : 'Quad_biplane/Control System/Attitude Controller/moments/PID Controller3/Tracking Mode Sum'
 * '<S280>' : 'Quad_biplane/Control System/Attitude Controller/moments/PID Controller3/Tsamp - Integral'
 * '<S281>' : 'Quad_biplane/Control System/Attitude Controller/moments/PID Controller3/Tsamp - Ngain'
 * '<S282>' : 'Quad_biplane/Control System/Attitude Controller/moments/PID Controller3/postSat Signal'
 * '<S283>' : 'Quad_biplane/Control System/Attitude Controller/moments/PID Controller3/preSat Signal'
 * '<S284>' : 'Quad_biplane/Control System/Attitude Controller/moments/PID Controller3/Anti-windup/Passthrough'
 * '<S285>' : 'Quad_biplane/Control System/Attitude Controller/moments/PID Controller3/D Gain/Internal Parameters'
 * '<S286>' : 'Quad_biplane/Control System/Attitude Controller/moments/PID Controller3/Filter/Cont. Filter'
 * '<S287>' : 'Quad_biplane/Control System/Attitude Controller/moments/PID Controller3/Filter ICs/Internal IC - Filter'
 * '<S288>' : 'Quad_biplane/Control System/Attitude Controller/moments/PID Controller3/I Gain/Internal Parameters'
 * '<S289>' : 'Quad_biplane/Control System/Attitude Controller/moments/PID Controller3/Ideal P Gain/Passthrough'
 * '<S290>' : 'Quad_biplane/Control System/Attitude Controller/moments/PID Controller3/Ideal P Gain Fdbk/Disabled'
 * '<S291>' : 'Quad_biplane/Control System/Attitude Controller/moments/PID Controller3/Integrator/Continuous'
 * '<S292>' : 'Quad_biplane/Control System/Attitude Controller/moments/PID Controller3/Integrator ICs/Internal IC'
 * '<S293>' : 'Quad_biplane/Control System/Attitude Controller/moments/PID Controller3/N Copy/Disabled'
 * '<S294>' : 'Quad_biplane/Control System/Attitude Controller/moments/PID Controller3/N Gain/Internal Parameters'
 * '<S295>' : 'Quad_biplane/Control System/Attitude Controller/moments/PID Controller3/P Copy/Disabled'
 * '<S296>' : 'Quad_biplane/Control System/Attitude Controller/moments/PID Controller3/Parallel P Gain/Internal Parameters'
 * '<S297>' : 'Quad_biplane/Control System/Attitude Controller/moments/PID Controller3/Reset Signal/Disabled'
 * '<S298>' : 'Quad_biplane/Control System/Attitude Controller/moments/PID Controller3/Saturation/Passthrough'
 * '<S299>' : 'Quad_biplane/Control System/Attitude Controller/moments/PID Controller3/Saturation Fdbk/Disabled'
 * '<S300>' : 'Quad_biplane/Control System/Attitude Controller/moments/PID Controller3/Sum/Sum_PID'
 * '<S301>' : 'Quad_biplane/Control System/Attitude Controller/moments/PID Controller3/Sum Fdbk/Disabled'
 * '<S302>' : 'Quad_biplane/Control System/Attitude Controller/moments/PID Controller3/Tracking Mode/Disabled'
 * '<S303>' : 'Quad_biplane/Control System/Attitude Controller/moments/PID Controller3/Tracking Mode Sum/Passthrough'
 * '<S304>' : 'Quad_biplane/Control System/Attitude Controller/moments/PID Controller3/Tsamp - Integral/Passthrough'
 * '<S305>' : 'Quad_biplane/Control System/Attitude Controller/moments/PID Controller3/Tsamp - Ngain/Passthrough'
 * '<S306>' : 'Quad_biplane/Control System/Attitude Controller/moments/PID Controller3/postSat Signal/Forward_Path'
 * '<S307>' : 'Quad_biplane/Control System/Attitude Controller/moments/PID Controller3/preSat Signal/Forward_Path'
 * '<S308>' : 'Quad_biplane/Control System/Position Controller/MATLAB Function'
 * '<S309>' : 'Quad_biplane/Control System/Position Controller/Position Controller X and Y'
 * '<S310>' : 'Quad_biplane/Control System/Position Controller/Position Controller Z'
 * '<S311>' : 'Quad_biplane/Control System/Position Controller/Position Controller X and Y/PID Controller'
 * '<S312>' : 'Quad_biplane/Control System/Position Controller/Position Controller X and Y/PID Controller1'
 * '<S313>' : 'Quad_biplane/Control System/Position Controller/Position Controller X and Y/PID Controller2'
 * '<S314>' : 'Quad_biplane/Control System/Position Controller/Position Controller X and Y/PID Controller3'
 * '<S315>' : 'Quad_biplane/Control System/Position Controller/Position Controller X and Y/PID Controller/Anti-windup'
 * '<S316>' : 'Quad_biplane/Control System/Position Controller/Position Controller X and Y/PID Controller/D Gain'
 * '<S317>' : 'Quad_biplane/Control System/Position Controller/Position Controller X and Y/PID Controller/Filter'
 * '<S318>' : 'Quad_biplane/Control System/Position Controller/Position Controller X and Y/PID Controller/Filter ICs'
 * '<S319>' : 'Quad_biplane/Control System/Position Controller/Position Controller X and Y/PID Controller/I Gain'
 * '<S320>' : 'Quad_biplane/Control System/Position Controller/Position Controller X and Y/PID Controller/Ideal P Gain'
 * '<S321>' : 'Quad_biplane/Control System/Position Controller/Position Controller X and Y/PID Controller/Ideal P Gain Fdbk'
 * '<S322>' : 'Quad_biplane/Control System/Position Controller/Position Controller X and Y/PID Controller/Integrator'
 * '<S323>' : 'Quad_biplane/Control System/Position Controller/Position Controller X and Y/PID Controller/Integrator ICs'
 * '<S324>' : 'Quad_biplane/Control System/Position Controller/Position Controller X and Y/PID Controller/N Copy'
 * '<S325>' : 'Quad_biplane/Control System/Position Controller/Position Controller X and Y/PID Controller/N Gain'
 * '<S326>' : 'Quad_biplane/Control System/Position Controller/Position Controller X and Y/PID Controller/P Copy'
 * '<S327>' : 'Quad_biplane/Control System/Position Controller/Position Controller X and Y/PID Controller/Parallel P Gain'
 * '<S328>' : 'Quad_biplane/Control System/Position Controller/Position Controller X and Y/PID Controller/Reset Signal'
 * '<S329>' : 'Quad_biplane/Control System/Position Controller/Position Controller X and Y/PID Controller/Saturation'
 * '<S330>' : 'Quad_biplane/Control System/Position Controller/Position Controller X and Y/PID Controller/Saturation Fdbk'
 * '<S331>' : 'Quad_biplane/Control System/Position Controller/Position Controller X and Y/PID Controller/Sum'
 * '<S332>' : 'Quad_biplane/Control System/Position Controller/Position Controller X and Y/PID Controller/Sum Fdbk'
 * '<S333>' : 'Quad_biplane/Control System/Position Controller/Position Controller X and Y/PID Controller/Tracking Mode'
 * '<S334>' : 'Quad_biplane/Control System/Position Controller/Position Controller X and Y/PID Controller/Tracking Mode Sum'
 * '<S335>' : 'Quad_biplane/Control System/Position Controller/Position Controller X and Y/PID Controller/Tsamp - Integral'
 * '<S336>' : 'Quad_biplane/Control System/Position Controller/Position Controller X and Y/PID Controller/Tsamp - Ngain'
 * '<S337>' : 'Quad_biplane/Control System/Position Controller/Position Controller X and Y/PID Controller/postSat Signal'
 * '<S338>' : 'Quad_biplane/Control System/Position Controller/Position Controller X and Y/PID Controller/preSat Signal'
 * '<S339>' : 'Quad_biplane/Control System/Position Controller/Position Controller X and Y/PID Controller/Anti-windup/Passthrough'
 * '<S340>' : 'Quad_biplane/Control System/Position Controller/Position Controller X and Y/PID Controller/D Gain/Internal Parameters'
 * '<S341>' : 'Quad_biplane/Control System/Position Controller/Position Controller X and Y/PID Controller/Filter/Cont. Filter'
 * '<S342>' : 'Quad_biplane/Control System/Position Controller/Position Controller X and Y/PID Controller/Filter ICs/Internal IC - Filter'
 * '<S343>' : 'Quad_biplane/Control System/Position Controller/Position Controller X and Y/PID Controller/I Gain/Internal Parameters'
 * '<S344>' : 'Quad_biplane/Control System/Position Controller/Position Controller X and Y/PID Controller/Ideal P Gain/Passthrough'
 * '<S345>' : 'Quad_biplane/Control System/Position Controller/Position Controller X and Y/PID Controller/Ideal P Gain Fdbk/Disabled'
 * '<S346>' : 'Quad_biplane/Control System/Position Controller/Position Controller X and Y/PID Controller/Integrator/Continuous'
 * '<S347>' : 'Quad_biplane/Control System/Position Controller/Position Controller X and Y/PID Controller/Integrator ICs/Internal IC'
 * '<S348>' : 'Quad_biplane/Control System/Position Controller/Position Controller X and Y/PID Controller/N Copy/Disabled'
 * '<S349>' : 'Quad_biplane/Control System/Position Controller/Position Controller X and Y/PID Controller/N Gain/Internal Parameters'
 * '<S350>' : 'Quad_biplane/Control System/Position Controller/Position Controller X and Y/PID Controller/P Copy/Disabled'
 * '<S351>' : 'Quad_biplane/Control System/Position Controller/Position Controller X and Y/PID Controller/Parallel P Gain/Internal Parameters'
 * '<S352>' : 'Quad_biplane/Control System/Position Controller/Position Controller X and Y/PID Controller/Reset Signal/Disabled'
 * '<S353>' : 'Quad_biplane/Control System/Position Controller/Position Controller X and Y/PID Controller/Saturation/Enabled'
 * '<S354>' : 'Quad_biplane/Control System/Position Controller/Position Controller X and Y/PID Controller/Saturation Fdbk/Disabled'
 * '<S355>' : 'Quad_biplane/Control System/Position Controller/Position Controller X and Y/PID Controller/Sum/Sum_PID'
 * '<S356>' : 'Quad_biplane/Control System/Position Controller/Position Controller X and Y/PID Controller/Sum Fdbk/Disabled'
 * '<S357>' : 'Quad_biplane/Control System/Position Controller/Position Controller X and Y/PID Controller/Tracking Mode/Disabled'
 * '<S358>' : 'Quad_biplane/Control System/Position Controller/Position Controller X and Y/PID Controller/Tracking Mode Sum/Passthrough'
 * '<S359>' : 'Quad_biplane/Control System/Position Controller/Position Controller X and Y/PID Controller/Tsamp - Integral/Passthrough'
 * '<S360>' : 'Quad_biplane/Control System/Position Controller/Position Controller X and Y/PID Controller/Tsamp - Ngain/Passthrough'
 * '<S361>' : 'Quad_biplane/Control System/Position Controller/Position Controller X and Y/PID Controller/postSat Signal/Forward_Path'
 * '<S362>' : 'Quad_biplane/Control System/Position Controller/Position Controller X and Y/PID Controller/preSat Signal/Forward_Path'
 * '<S363>' : 'Quad_biplane/Control System/Position Controller/Position Controller X and Y/PID Controller1/Anti-windup'
 * '<S364>' : 'Quad_biplane/Control System/Position Controller/Position Controller X and Y/PID Controller1/D Gain'
 * '<S365>' : 'Quad_biplane/Control System/Position Controller/Position Controller X and Y/PID Controller1/Filter'
 * '<S366>' : 'Quad_biplane/Control System/Position Controller/Position Controller X and Y/PID Controller1/Filter ICs'
 * '<S367>' : 'Quad_biplane/Control System/Position Controller/Position Controller X and Y/PID Controller1/I Gain'
 * '<S368>' : 'Quad_biplane/Control System/Position Controller/Position Controller X and Y/PID Controller1/Ideal P Gain'
 * '<S369>' : 'Quad_biplane/Control System/Position Controller/Position Controller X and Y/PID Controller1/Ideal P Gain Fdbk'
 * '<S370>' : 'Quad_biplane/Control System/Position Controller/Position Controller X and Y/PID Controller1/Integrator'
 * '<S371>' : 'Quad_biplane/Control System/Position Controller/Position Controller X and Y/PID Controller1/Integrator ICs'
 * '<S372>' : 'Quad_biplane/Control System/Position Controller/Position Controller X and Y/PID Controller1/N Copy'
 * '<S373>' : 'Quad_biplane/Control System/Position Controller/Position Controller X and Y/PID Controller1/N Gain'
 * '<S374>' : 'Quad_biplane/Control System/Position Controller/Position Controller X and Y/PID Controller1/P Copy'
 * '<S375>' : 'Quad_biplane/Control System/Position Controller/Position Controller X and Y/PID Controller1/Parallel P Gain'
 * '<S376>' : 'Quad_biplane/Control System/Position Controller/Position Controller X and Y/PID Controller1/Reset Signal'
 * '<S377>' : 'Quad_biplane/Control System/Position Controller/Position Controller X and Y/PID Controller1/Saturation'
 * '<S378>' : 'Quad_biplane/Control System/Position Controller/Position Controller X and Y/PID Controller1/Saturation Fdbk'
 * '<S379>' : 'Quad_biplane/Control System/Position Controller/Position Controller X and Y/PID Controller1/Sum'
 * '<S380>' : 'Quad_biplane/Control System/Position Controller/Position Controller X and Y/PID Controller1/Sum Fdbk'
 * '<S381>' : 'Quad_biplane/Control System/Position Controller/Position Controller X and Y/PID Controller1/Tracking Mode'
 * '<S382>' : 'Quad_biplane/Control System/Position Controller/Position Controller X and Y/PID Controller1/Tracking Mode Sum'
 * '<S383>' : 'Quad_biplane/Control System/Position Controller/Position Controller X and Y/PID Controller1/Tsamp - Integral'
 * '<S384>' : 'Quad_biplane/Control System/Position Controller/Position Controller X and Y/PID Controller1/Tsamp - Ngain'
 * '<S385>' : 'Quad_biplane/Control System/Position Controller/Position Controller X and Y/PID Controller1/postSat Signal'
 * '<S386>' : 'Quad_biplane/Control System/Position Controller/Position Controller X and Y/PID Controller1/preSat Signal'
 * '<S387>' : 'Quad_biplane/Control System/Position Controller/Position Controller X and Y/PID Controller1/Anti-windup/Passthrough'
 * '<S388>' : 'Quad_biplane/Control System/Position Controller/Position Controller X and Y/PID Controller1/D Gain/Internal Parameters'
 * '<S389>' : 'Quad_biplane/Control System/Position Controller/Position Controller X and Y/PID Controller1/Filter/Cont. Filter'
 * '<S390>' : 'Quad_biplane/Control System/Position Controller/Position Controller X and Y/PID Controller1/Filter ICs/Internal IC - Filter'
 * '<S391>' : 'Quad_biplane/Control System/Position Controller/Position Controller X and Y/PID Controller1/I Gain/Internal Parameters'
 * '<S392>' : 'Quad_biplane/Control System/Position Controller/Position Controller X and Y/PID Controller1/Ideal P Gain/Passthrough'
 * '<S393>' : 'Quad_biplane/Control System/Position Controller/Position Controller X and Y/PID Controller1/Ideal P Gain Fdbk/Disabled'
 * '<S394>' : 'Quad_biplane/Control System/Position Controller/Position Controller X and Y/PID Controller1/Integrator/Continuous'
 * '<S395>' : 'Quad_biplane/Control System/Position Controller/Position Controller X and Y/PID Controller1/Integrator ICs/Internal IC'
 * '<S396>' : 'Quad_biplane/Control System/Position Controller/Position Controller X and Y/PID Controller1/N Copy/Disabled'
 * '<S397>' : 'Quad_biplane/Control System/Position Controller/Position Controller X and Y/PID Controller1/N Gain/Internal Parameters'
 * '<S398>' : 'Quad_biplane/Control System/Position Controller/Position Controller X and Y/PID Controller1/P Copy/Disabled'
 * '<S399>' : 'Quad_biplane/Control System/Position Controller/Position Controller X and Y/PID Controller1/Parallel P Gain/Internal Parameters'
 * '<S400>' : 'Quad_biplane/Control System/Position Controller/Position Controller X and Y/PID Controller1/Reset Signal/Disabled'
 * '<S401>' : 'Quad_biplane/Control System/Position Controller/Position Controller X and Y/PID Controller1/Saturation/Enabled'
 * '<S402>' : 'Quad_biplane/Control System/Position Controller/Position Controller X and Y/PID Controller1/Saturation Fdbk/Disabled'
 * '<S403>' : 'Quad_biplane/Control System/Position Controller/Position Controller X and Y/PID Controller1/Sum/Sum_PID'
 * '<S404>' : 'Quad_biplane/Control System/Position Controller/Position Controller X and Y/PID Controller1/Sum Fdbk/Disabled'
 * '<S405>' : 'Quad_biplane/Control System/Position Controller/Position Controller X and Y/PID Controller1/Tracking Mode/Disabled'
 * '<S406>' : 'Quad_biplane/Control System/Position Controller/Position Controller X and Y/PID Controller1/Tracking Mode Sum/Passthrough'
 * '<S407>' : 'Quad_biplane/Control System/Position Controller/Position Controller X and Y/PID Controller1/Tsamp - Integral/Passthrough'
 * '<S408>' : 'Quad_biplane/Control System/Position Controller/Position Controller X and Y/PID Controller1/Tsamp - Ngain/Passthrough'
 * '<S409>' : 'Quad_biplane/Control System/Position Controller/Position Controller X and Y/PID Controller1/postSat Signal/Forward_Path'
 * '<S410>' : 'Quad_biplane/Control System/Position Controller/Position Controller X and Y/PID Controller1/preSat Signal/Forward_Path'
 * '<S411>' : 'Quad_biplane/Control System/Position Controller/Position Controller X and Y/PID Controller2/Anti-windup'
 * '<S412>' : 'Quad_biplane/Control System/Position Controller/Position Controller X and Y/PID Controller2/D Gain'
 * '<S413>' : 'Quad_biplane/Control System/Position Controller/Position Controller X and Y/PID Controller2/Filter'
 * '<S414>' : 'Quad_biplane/Control System/Position Controller/Position Controller X and Y/PID Controller2/Filter ICs'
 * '<S415>' : 'Quad_biplane/Control System/Position Controller/Position Controller X and Y/PID Controller2/I Gain'
 * '<S416>' : 'Quad_biplane/Control System/Position Controller/Position Controller X and Y/PID Controller2/Ideal P Gain'
 * '<S417>' : 'Quad_biplane/Control System/Position Controller/Position Controller X and Y/PID Controller2/Ideal P Gain Fdbk'
 * '<S418>' : 'Quad_biplane/Control System/Position Controller/Position Controller X and Y/PID Controller2/Integrator'
 * '<S419>' : 'Quad_biplane/Control System/Position Controller/Position Controller X and Y/PID Controller2/Integrator ICs'
 * '<S420>' : 'Quad_biplane/Control System/Position Controller/Position Controller X and Y/PID Controller2/N Copy'
 * '<S421>' : 'Quad_biplane/Control System/Position Controller/Position Controller X and Y/PID Controller2/N Gain'
 * '<S422>' : 'Quad_biplane/Control System/Position Controller/Position Controller X and Y/PID Controller2/P Copy'
 * '<S423>' : 'Quad_biplane/Control System/Position Controller/Position Controller X and Y/PID Controller2/Parallel P Gain'
 * '<S424>' : 'Quad_biplane/Control System/Position Controller/Position Controller X and Y/PID Controller2/Reset Signal'
 * '<S425>' : 'Quad_biplane/Control System/Position Controller/Position Controller X and Y/PID Controller2/Saturation'
 * '<S426>' : 'Quad_biplane/Control System/Position Controller/Position Controller X and Y/PID Controller2/Saturation Fdbk'
 * '<S427>' : 'Quad_biplane/Control System/Position Controller/Position Controller X and Y/PID Controller2/Sum'
 * '<S428>' : 'Quad_biplane/Control System/Position Controller/Position Controller X and Y/PID Controller2/Sum Fdbk'
 * '<S429>' : 'Quad_biplane/Control System/Position Controller/Position Controller X and Y/PID Controller2/Tracking Mode'
 * '<S430>' : 'Quad_biplane/Control System/Position Controller/Position Controller X and Y/PID Controller2/Tracking Mode Sum'
 * '<S431>' : 'Quad_biplane/Control System/Position Controller/Position Controller X and Y/PID Controller2/Tsamp - Integral'
 * '<S432>' : 'Quad_biplane/Control System/Position Controller/Position Controller X and Y/PID Controller2/Tsamp - Ngain'
 * '<S433>' : 'Quad_biplane/Control System/Position Controller/Position Controller X and Y/PID Controller2/postSat Signal'
 * '<S434>' : 'Quad_biplane/Control System/Position Controller/Position Controller X and Y/PID Controller2/preSat Signal'
 * '<S435>' : 'Quad_biplane/Control System/Position Controller/Position Controller X and Y/PID Controller2/Anti-windup/Passthrough'
 * '<S436>' : 'Quad_biplane/Control System/Position Controller/Position Controller X and Y/PID Controller2/D Gain/Internal Parameters'
 * '<S437>' : 'Quad_biplane/Control System/Position Controller/Position Controller X and Y/PID Controller2/Filter/Cont. Filter'
 * '<S438>' : 'Quad_biplane/Control System/Position Controller/Position Controller X and Y/PID Controller2/Filter ICs/Internal IC - Filter'
 * '<S439>' : 'Quad_biplane/Control System/Position Controller/Position Controller X and Y/PID Controller2/I Gain/Internal Parameters'
 * '<S440>' : 'Quad_biplane/Control System/Position Controller/Position Controller X and Y/PID Controller2/Ideal P Gain/Passthrough'
 * '<S441>' : 'Quad_biplane/Control System/Position Controller/Position Controller X and Y/PID Controller2/Ideal P Gain Fdbk/Disabled'
 * '<S442>' : 'Quad_biplane/Control System/Position Controller/Position Controller X and Y/PID Controller2/Integrator/Continuous'
 * '<S443>' : 'Quad_biplane/Control System/Position Controller/Position Controller X and Y/PID Controller2/Integrator ICs/Internal IC'
 * '<S444>' : 'Quad_biplane/Control System/Position Controller/Position Controller X and Y/PID Controller2/N Copy/Disabled'
 * '<S445>' : 'Quad_biplane/Control System/Position Controller/Position Controller X and Y/PID Controller2/N Gain/Internal Parameters'
 * '<S446>' : 'Quad_biplane/Control System/Position Controller/Position Controller X and Y/PID Controller2/P Copy/Disabled'
 * '<S447>' : 'Quad_biplane/Control System/Position Controller/Position Controller X and Y/PID Controller2/Parallel P Gain/Internal Parameters'
 * '<S448>' : 'Quad_biplane/Control System/Position Controller/Position Controller X and Y/PID Controller2/Reset Signal/Disabled'
 * '<S449>' : 'Quad_biplane/Control System/Position Controller/Position Controller X and Y/PID Controller2/Saturation/Enabled'
 * '<S450>' : 'Quad_biplane/Control System/Position Controller/Position Controller X and Y/PID Controller2/Saturation Fdbk/Disabled'
 * '<S451>' : 'Quad_biplane/Control System/Position Controller/Position Controller X and Y/PID Controller2/Sum/Sum_PID'
 * '<S452>' : 'Quad_biplane/Control System/Position Controller/Position Controller X and Y/PID Controller2/Sum Fdbk/Disabled'
 * '<S453>' : 'Quad_biplane/Control System/Position Controller/Position Controller X and Y/PID Controller2/Tracking Mode/Disabled'
 * '<S454>' : 'Quad_biplane/Control System/Position Controller/Position Controller X and Y/PID Controller2/Tracking Mode Sum/Passthrough'
 * '<S455>' : 'Quad_biplane/Control System/Position Controller/Position Controller X and Y/PID Controller2/Tsamp - Integral/Passthrough'
 * '<S456>' : 'Quad_biplane/Control System/Position Controller/Position Controller X and Y/PID Controller2/Tsamp - Ngain/Passthrough'
 * '<S457>' : 'Quad_biplane/Control System/Position Controller/Position Controller X and Y/PID Controller2/postSat Signal/Forward_Path'
 * '<S458>' : 'Quad_biplane/Control System/Position Controller/Position Controller X and Y/PID Controller2/preSat Signal/Forward_Path'
 * '<S459>' : 'Quad_biplane/Control System/Position Controller/Position Controller X and Y/PID Controller3/Anti-windup'
 * '<S460>' : 'Quad_biplane/Control System/Position Controller/Position Controller X and Y/PID Controller3/D Gain'
 * '<S461>' : 'Quad_biplane/Control System/Position Controller/Position Controller X and Y/PID Controller3/Filter'
 * '<S462>' : 'Quad_biplane/Control System/Position Controller/Position Controller X and Y/PID Controller3/Filter ICs'
 * '<S463>' : 'Quad_biplane/Control System/Position Controller/Position Controller X and Y/PID Controller3/I Gain'
 * '<S464>' : 'Quad_biplane/Control System/Position Controller/Position Controller X and Y/PID Controller3/Ideal P Gain'
 * '<S465>' : 'Quad_biplane/Control System/Position Controller/Position Controller X and Y/PID Controller3/Ideal P Gain Fdbk'
 * '<S466>' : 'Quad_biplane/Control System/Position Controller/Position Controller X and Y/PID Controller3/Integrator'
 * '<S467>' : 'Quad_biplane/Control System/Position Controller/Position Controller X and Y/PID Controller3/Integrator ICs'
 * '<S468>' : 'Quad_biplane/Control System/Position Controller/Position Controller X and Y/PID Controller3/N Copy'
 * '<S469>' : 'Quad_biplane/Control System/Position Controller/Position Controller X and Y/PID Controller3/N Gain'
 * '<S470>' : 'Quad_biplane/Control System/Position Controller/Position Controller X and Y/PID Controller3/P Copy'
 * '<S471>' : 'Quad_biplane/Control System/Position Controller/Position Controller X and Y/PID Controller3/Parallel P Gain'
 * '<S472>' : 'Quad_biplane/Control System/Position Controller/Position Controller X and Y/PID Controller3/Reset Signal'
 * '<S473>' : 'Quad_biplane/Control System/Position Controller/Position Controller X and Y/PID Controller3/Saturation'
 * '<S474>' : 'Quad_biplane/Control System/Position Controller/Position Controller X and Y/PID Controller3/Saturation Fdbk'
 * '<S475>' : 'Quad_biplane/Control System/Position Controller/Position Controller X and Y/PID Controller3/Sum'
 * '<S476>' : 'Quad_biplane/Control System/Position Controller/Position Controller X and Y/PID Controller3/Sum Fdbk'
 * '<S477>' : 'Quad_biplane/Control System/Position Controller/Position Controller X and Y/PID Controller3/Tracking Mode'
 * '<S478>' : 'Quad_biplane/Control System/Position Controller/Position Controller X and Y/PID Controller3/Tracking Mode Sum'
 * '<S479>' : 'Quad_biplane/Control System/Position Controller/Position Controller X and Y/PID Controller3/Tsamp - Integral'
 * '<S480>' : 'Quad_biplane/Control System/Position Controller/Position Controller X and Y/PID Controller3/Tsamp - Ngain'
 * '<S481>' : 'Quad_biplane/Control System/Position Controller/Position Controller X and Y/PID Controller3/postSat Signal'
 * '<S482>' : 'Quad_biplane/Control System/Position Controller/Position Controller X and Y/PID Controller3/preSat Signal'
 * '<S483>' : 'Quad_biplane/Control System/Position Controller/Position Controller X and Y/PID Controller3/Anti-windup/Passthrough'
 * '<S484>' : 'Quad_biplane/Control System/Position Controller/Position Controller X and Y/PID Controller3/D Gain/Internal Parameters'
 * '<S485>' : 'Quad_biplane/Control System/Position Controller/Position Controller X and Y/PID Controller3/Filter/Cont. Filter'
 * '<S486>' : 'Quad_biplane/Control System/Position Controller/Position Controller X and Y/PID Controller3/Filter ICs/Internal IC - Filter'
 * '<S487>' : 'Quad_biplane/Control System/Position Controller/Position Controller X and Y/PID Controller3/I Gain/Internal Parameters'
 * '<S488>' : 'Quad_biplane/Control System/Position Controller/Position Controller X and Y/PID Controller3/Ideal P Gain/Passthrough'
 * '<S489>' : 'Quad_biplane/Control System/Position Controller/Position Controller X and Y/PID Controller3/Ideal P Gain Fdbk/Disabled'
 * '<S490>' : 'Quad_biplane/Control System/Position Controller/Position Controller X and Y/PID Controller3/Integrator/Continuous'
 * '<S491>' : 'Quad_biplane/Control System/Position Controller/Position Controller X and Y/PID Controller3/Integrator ICs/Internal IC'
 * '<S492>' : 'Quad_biplane/Control System/Position Controller/Position Controller X and Y/PID Controller3/N Copy/Disabled'
 * '<S493>' : 'Quad_biplane/Control System/Position Controller/Position Controller X and Y/PID Controller3/N Gain/Internal Parameters'
 * '<S494>' : 'Quad_biplane/Control System/Position Controller/Position Controller X and Y/PID Controller3/P Copy/Disabled'
 * '<S495>' : 'Quad_biplane/Control System/Position Controller/Position Controller X and Y/PID Controller3/Parallel P Gain/Internal Parameters'
 * '<S496>' : 'Quad_biplane/Control System/Position Controller/Position Controller X and Y/PID Controller3/Reset Signal/Disabled'
 * '<S497>' : 'Quad_biplane/Control System/Position Controller/Position Controller X and Y/PID Controller3/Saturation/Enabled'
 * '<S498>' : 'Quad_biplane/Control System/Position Controller/Position Controller X and Y/PID Controller3/Saturation Fdbk/Disabled'
 * '<S499>' : 'Quad_biplane/Control System/Position Controller/Position Controller X and Y/PID Controller3/Sum/Sum_PID'
 * '<S500>' : 'Quad_biplane/Control System/Position Controller/Position Controller X and Y/PID Controller3/Sum Fdbk/Disabled'
 * '<S501>' : 'Quad_biplane/Control System/Position Controller/Position Controller X and Y/PID Controller3/Tracking Mode/Disabled'
 * '<S502>' : 'Quad_biplane/Control System/Position Controller/Position Controller X and Y/PID Controller3/Tracking Mode Sum/Passthrough'
 * '<S503>' : 'Quad_biplane/Control System/Position Controller/Position Controller X and Y/PID Controller3/Tsamp - Integral/Passthrough'
 * '<S504>' : 'Quad_biplane/Control System/Position Controller/Position Controller X and Y/PID Controller3/Tsamp - Ngain/Passthrough'
 * '<S505>' : 'Quad_biplane/Control System/Position Controller/Position Controller X and Y/PID Controller3/postSat Signal/Forward_Path'
 * '<S506>' : 'Quad_biplane/Control System/Position Controller/Position Controller X and Y/PID Controller3/preSat Signal/Forward_Path'
 * '<S507>' : 'Quad_biplane/Control System/Position Controller/Position Controller Z/If Action Subsystem'
 * '<S508>' : 'Quad_biplane/Control System/Position Controller/Position Controller Z/If Action Subsystem1'
 * '<S509>' : 'Quad_biplane/Control System/Position Controller/Position Controller Z/If Action Subsystem2'
 * '<S510>' : 'Quad_biplane/Control System/Position Controller/Position Controller Z/PID Controller'
 * '<S511>' : 'Quad_biplane/Control System/Position Controller/Position Controller Z/If Action Subsystem2/PID Controller2'
 * '<S512>' : 'Quad_biplane/Control System/Position Controller/Position Controller Z/If Action Subsystem2/PID Controller2/Anti-windup'
 * '<S513>' : 'Quad_biplane/Control System/Position Controller/Position Controller Z/If Action Subsystem2/PID Controller2/D Gain'
 * '<S514>' : 'Quad_biplane/Control System/Position Controller/Position Controller Z/If Action Subsystem2/PID Controller2/Filter'
 * '<S515>' : 'Quad_biplane/Control System/Position Controller/Position Controller Z/If Action Subsystem2/PID Controller2/Filter ICs'
 * '<S516>' : 'Quad_biplane/Control System/Position Controller/Position Controller Z/If Action Subsystem2/PID Controller2/I Gain'
 * '<S517>' : 'Quad_biplane/Control System/Position Controller/Position Controller Z/If Action Subsystem2/PID Controller2/Ideal P Gain'
 * '<S518>' : 'Quad_biplane/Control System/Position Controller/Position Controller Z/If Action Subsystem2/PID Controller2/Ideal P Gain Fdbk'
 * '<S519>' : 'Quad_biplane/Control System/Position Controller/Position Controller Z/If Action Subsystem2/PID Controller2/Integrator'
 * '<S520>' : 'Quad_biplane/Control System/Position Controller/Position Controller Z/If Action Subsystem2/PID Controller2/Integrator ICs'
 * '<S521>' : 'Quad_biplane/Control System/Position Controller/Position Controller Z/If Action Subsystem2/PID Controller2/N Copy'
 * '<S522>' : 'Quad_biplane/Control System/Position Controller/Position Controller Z/If Action Subsystem2/PID Controller2/N Gain'
 * '<S523>' : 'Quad_biplane/Control System/Position Controller/Position Controller Z/If Action Subsystem2/PID Controller2/P Copy'
 * '<S524>' : 'Quad_biplane/Control System/Position Controller/Position Controller Z/If Action Subsystem2/PID Controller2/Parallel P Gain'
 * '<S525>' : 'Quad_biplane/Control System/Position Controller/Position Controller Z/If Action Subsystem2/PID Controller2/Reset Signal'
 * '<S526>' : 'Quad_biplane/Control System/Position Controller/Position Controller Z/If Action Subsystem2/PID Controller2/Saturation'
 * '<S527>' : 'Quad_biplane/Control System/Position Controller/Position Controller Z/If Action Subsystem2/PID Controller2/Saturation Fdbk'
 * '<S528>' : 'Quad_biplane/Control System/Position Controller/Position Controller Z/If Action Subsystem2/PID Controller2/Sum'
 * '<S529>' : 'Quad_biplane/Control System/Position Controller/Position Controller Z/If Action Subsystem2/PID Controller2/Sum Fdbk'
 * '<S530>' : 'Quad_biplane/Control System/Position Controller/Position Controller Z/If Action Subsystem2/PID Controller2/Tracking Mode'
 * '<S531>' : 'Quad_biplane/Control System/Position Controller/Position Controller Z/If Action Subsystem2/PID Controller2/Tracking Mode Sum'
 * '<S532>' : 'Quad_biplane/Control System/Position Controller/Position Controller Z/If Action Subsystem2/PID Controller2/Tsamp - Integral'
 * '<S533>' : 'Quad_biplane/Control System/Position Controller/Position Controller Z/If Action Subsystem2/PID Controller2/Tsamp - Ngain'
 * '<S534>' : 'Quad_biplane/Control System/Position Controller/Position Controller Z/If Action Subsystem2/PID Controller2/postSat Signal'
 * '<S535>' : 'Quad_biplane/Control System/Position Controller/Position Controller Z/If Action Subsystem2/PID Controller2/preSat Signal'
 * '<S536>' : 'Quad_biplane/Control System/Position Controller/Position Controller Z/If Action Subsystem2/PID Controller2/Anti-windup/Passthrough'
 * '<S537>' : 'Quad_biplane/Control System/Position Controller/Position Controller Z/If Action Subsystem2/PID Controller2/D Gain/Internal Parameters'
 * '<S538>' : 'Quad_biplane/Control System/Position Controller/Position Controller Z/If Action Subsystem2/PID Controller2/Filter/Cont. Filter'
 * '<S539>' : 'Quad_biplane/Control System/Position Controller/Position Controller Z/If Action Subsystem2/PID Controller2/Filter ICs/Internal IC - Filter'
 * '<S540>' : 'Quad_biplane/Control System/Position Controller/Position Controller Z/If Action Subsystem2/PID Controller2/I Gain/Internal Parameters'
 * '<S541>' : 'Quad_biplane/Control System/Position Controller/Position Controller Z/If Action Subsystem2/PID Controller2/Ideal P Gain/Passthrough'
 * '<S542>' : 'Quad_biplane/Control System/Position Controller/Position Controller Z/If Action Subsystem2/PID Controller2/Ideal P Gain Fdbk/Disabled'
 * '<S543>' : 'Quad_biplane/Control System/Position Controller/Position Controller Z/If Action Subsystem2/PID Controller2/Integrator/Continuous'
 * '<S544>' : 'Quad_biplane/Control System/Position Controller/Position Controller Z/If Action Subsystem2/PID Controller2/Integrator ICs/Internal IC'
 * '<S545>' : 'Quad_biplane/Control System/Position Controller/Position Controller Z/If Action Subsystem2/PID Controller2/N Copy/Disabled'
 * '<S546>' : 'Quad_biplane/Control System/Position Controller/Position Controller Z/If Action Subsystem2/PID Controller2/N Gain/Internal Parameters'
 * '<S547>' : 'Quad_biplane/Control System/Position Controller/Position Controller Z/If Action Subsystem2/PID Controller2/P Copy/Disabled'
 * '<S548>' : 'Quad_biplane/Control System/Position Controller/Position Controller Z/If Action Subsystem2/PID Controller2/Parallel P Gain/Internal Parameters'
 * '<S549>' : 'Quad_biplane/Control System/Position Controller/Position Controller Z/If Action Subsystem2/PID Controller2/Reset Signal/Disabled'
 * '<S550>' : 'Quad_biplane/Control System/Position Controller/Position Controller Z/If Action Subsystem2/PID Controller2/Saturation/Enabled'
 * '<S551>' : 'Quad_biplane/Control System/Position Controller/Position Controller Z/If Action Subsystem2/PID Controller2/Saturation Fdbk/Disabled'
 * '<S552>' : 'Quad_biplane/Control System/Position Controller/Position Controller Z/If Action Subsystem2/PID Controller2/Sum/Sum_PID'
 * '<S553>' : 'Quad_biplane/Control System/Position Controller/Position Controller Z/If Action Subsystem2/PID Controller2/Sum Fdbk/Disabled'
 * '<S554>' : 'Quad_biplane/Control System/Position Controller/Position Controller Z/If Action Subsystem2/PID Controller2/Tracking Mode/Disabled'
 * '<S555>' : 'Quad_biplane/Control System/Position Controller/Position Controller Z/If Action Subsystem2/PID Controller2/Tracking Mode Sum/Passthrough'
 * '<S556>' : 'Quad_biplane/Control System/Position Controller/Position Controller Z/If Action Subsystem2/PID Controller2/Tsamp - Integral/Passthrough'
 * '<S557>' : 'Quad_biplane/Control System/Position Controller/Position Controller Z/If Action Subsystem2/PID Controller2/Tsamp - Ngain/Passthrough'
 * '<S558>' : 'Quad_biplane/Control System/Position Controller/Position Controller Z/If Action Subsystem2/PID Controller2/postSat Signal/Forward_Path'
 * '<S559>' : 'Quad_biplane/Control System/Position Controller/Position Controller Z/If Action Subsystem2/PID Controller2/preSat Signal/Forward_Path'
 * '<S560>' : 'Quad_biplane/Control System/Position Controller/Position Controller Z/PID Controller/Anti-windup'
 * '<S561>' : 'Quad_biplane/Control System/Position Controller/Position Controller Z/PID Controller/D Gain'
 * '<S562>' : 'Quad_biplane/Control System/Position Controller/Position Controller Z/PID Controller/Filter'
 * '<S563>' : 'Quad_biplane/Control System/Position Controller/Position Controller Z/PID Controller/Filter ICs'
 * '<S564>' : 'Quad_biplane/Control System/Position Controller/Position Controller Z/PID Controller/I Gain'
 * '<S565>' : 'Quad_biplane/Control System/Position Controller/Position Controller Z/PID Controller/Ideal P Gain'
 * '<S566>' : 'Quad_biplane/Control System/Position Controller/Position Controller Z/PID Controller/Ideal P Gain Fdbk'
 * '<S567>' : 'Quad_biplane/Control System/Position Controller/Position Controller Z/PID Controller/Integrator'
 * '<S568>' : 'Quad_biplane/Control System/Position Controller/Position Controller Z/PID Controller/Integrator ICs'
 * '<S569>' : 'Quad_biplane/Control System/Position Controller/Position Controller Z/PID Controller/N Copy'
 * '<S570>' : 'Quad_biplane/Control System/Position Controller/Position Controller Z/PID Controller/N Gain'
 * '<S571>' : 'Quad_biplane/Control System/Position Controller/Position Controller Z/PID Controller/P Copy'
 * '<S572>' : 'Quad_biplane/Control System/Position Controller/Position Controller Z/PID Controller/Parallel P Gain'
 * '<S573>' : 'Quad_biplane/Control System/Position Controller/Position Controller Z/PID Controller/Reset Signal'
 * '<S574>' : 'Quad_biplane/Control System/Position Controller/Position Controller Z/PID Controller/Saturation'
 * '<S575>' : 'Quad_biplane/Control System/Position Controller/Position Controller Z/PID Controller/Saturation Fdbk'
 * '<S576>' : 'Quad_biplane/Control System/Position Controller/Position Controller Z/PID Controller/Sum'
 * '<S577>' : 'Quad_biplane/Control System/Position Controller/Position Controller Z/PID Controller/Sum Fdbk'
 * '<S578>' : 'Quad_biplane/Control System/Position Controller/Position Controller Z/PID Controller/Tracking Mode'
 * '<S579>' : 'Quad_biplane/Control System/Position Controller/Position Controller Z/PID Controller/Tracking Mode Sum'
 * '<S580>' : 'Quad_biplane/Control System/Position Controller/Position Controller Z/PID Controller/Tsamp - Integral'
 * '<S581>' : 'Quad_biplane/Control System/Position Controller/Position Controller Z/PID Controller/Tsamp - Ngain'
 * '<S582>' : 'Quad_biplane/Control System/Position Controller/Position Controller Z/PID Controller/postSat Signal'
 * '<S583>' : 'Quad_biplane/Control System/Position Controller/Position Controller Z/PID Controller/preSat Signal'
 * '<S584>' : 'Quad_biplane/Control System/Position Controller/Position Controller Z/PID Controller/Anti-windup/Passthrough'
 * '<S585>' : 'Quad_biplane/Control System/Position Controller/Position Controller Z/PID Controller/D Gain/Internal Parameters'
 * '<S586>' : 'Quad_biplane/Control System/Position Controller/Position Controller Z/PID Controller/Filter/Cont. Filter'
 * '<S587>' : 'Quad_biplane/Control System/Position Controller/Position Controller Z/PID Controller/Filter ICs/Internal IC - Filter'
 * '<S588>' : 'Quad_biplane/Control System/Position Controller/Position Controller Z/PID Controller/I Gain/Internal Parameters'
 * '<S589>' : 'Quad_biplane/Control System/Position Controller/Position Controller Z/PID Controller/Ideal P Gain/Passthrough'
 * '<S590>' : 'Quad_biplane/Control System/Position Controller/Position Controller Z/PID Controller/Ideal P Gain Fdbk/Disabled'
 * '<S591>' : 'Quad_biplane/Control System/Position Controller/Position Controller Z/PID Controller/Integrator/Continuous'
 * '<S592>' : 'Quad_biplane/Control System/Position Controller/Position Controller Z/PID Controller/Integrator ICs/Internal IC'
 * '<S593>' : 'Quad_biplane/Control System/Position Controller/Position Controller Z/PID Controller/N Copy/Disabled'
 * '<S594>' : 'Quad_biplane/Control System/Position Controller/Position Controller Z/PID Controller/N Gain/Internal Parameters'
 * '<S595>' : 'Quad_biplane/Control System/Position Controller/Position Controller Z/PID Controller/P Copy/Disabled'
 * '<S596>' : 'Quad_biplane/Control System/Position Controller/Position Controller Z/PID Controller/Parallel P Gain/Internal Parameters'
 * '<S597>' : 'Quad_biplane/Control System/Position Controller/Position Controller Z/PID Controller/Reset Signal/Disabled'
 * '<S598>' : 'Quad_biplane/Control System/Position Controller/Position Controller Z/PID Controller/Saturation/Enabled'
 * '<S599>' : 'Quad_biplane/Control System/Position Controller/Position Controller Z/PID Controller/Saturation Fdbk/Disabled'
 * '<S600>' : 'Quad_biplane/Control System/Position Controller/Position Controller Z/PID Controller/Sum/Sum_PID'
 * '<S601>' : 'Quad_biplane/Control System/Position Controller/Position Controller Z/PID Controller/Sum Fdbk/Disabled'
 * '<S602>' : 'Quad_biplane/Control System/Position Controller/Position Controller Z/PID Controller/Tracking Mode/Disabled'
 * '<S603>' : 'Quad_biplane/Control System/Position Controller/Position Controller Z/PID Controller/Tracking Mode Sum/Passthrough'
 * '<S604>' : 'Quad_biplane/Control System/Position Controller/Position Controller Z/PID Controller/Tsamp - Integral/Passthrough'
 * '<S605>' : 'Quad_biplane/Control System/Position Controller/Position Controller Z/PID Controller/Tsamp - Ngain/Passthrough'
 * '<S606>' : 'Quad_biplane/Control System/Position Controller/Position Controller Z/PID Controller/postSat Signal/Forward_Path'
 * '<S607>' : 'Quad_biplane/Control System/Position Controller/Position Controller Z/PID Controller/preSat Signal/Forward_Path'
 * '<S608>' : 'Quad_biplane/Flight Dynamics/Rotational Dynamics'
 * '<S609>' : 'Quad_biplane/Flight Dynamics/State_update'
 * '<S610>' : 'Quad_biplane/Flight Dynamics/Transform1'
 * '<S611>' : 'Quad_biplane/Flight Dynamics/Translational Dynamics'
 * '<S612>' : 'Quad_biplane/Vehicle Performance/Fuselage Load'
 * '<S613>' : 'Quad_biplane/Vehicle Performance/Total Rotor Load1'
 * '<S614>' : 'Quad_biplane/Vehicle Performance/Weight'
 * '<S615>' : 'Quad_biplane/Vehicle Performance/Wing Load'
 * '<S616>' : 'Quad_biplane/Vehicle Performance/Fuselage Load/Fuselage'
 * '<S617>' : 'Quad_biplane/Vehicle Performance/Fuselage Load/Norm'
 * '<S618>' : 'Quad_biplane/Vehicle Performance/Total Rotor Load1/MATLAB Function2'
 * '<S619>' : 'Quad_biplane/Vehicle Performance/Total Rotor Load1/Rotor 1 '
 * '<S620>' : 'Quad_biplane/Vehicle Performance/Total Rotor Load1/Rotor 2'
 * '<S621>' : 'Quad_biplane/Vehicle Performance/Total Rotor Load1/Rotor 3'
 * '<S622>' : 'Quad_biplane/Vehicle Performance/Total Rotor Load1/Rotor 4'
 * '<S623>' : 'Quad_biplane/Vehicle Performance/Total Rotor Load1/Subsystem'
 * '<S624>' : 'Quad_biplane/Vehicle Performance/Total Rotor Load1/Rotor 1 /MATLAB Function'
 * '<S625>' : 'Quad_biplane/Vehicle Performance/Total Rotor Load1/Rotor 2/MATLAB Function'
 * '<S626>' : 'Quad_biplane/Vehicle Performance/Total Rotor Load1/Rotor 3/MATLAB Function'
 * '<S627>' : 'Quad_biplane/Vehicle Performance/Total Rotor Load1/Rotor 4/MATLAB Function'
 * '<S628>' : 'Quad_biplane/Vehicle Performance/Weight/MATLAB Function'
 * '<S629>' : 'Quad_biplane/Vehicle Performance/Wing Load/MATLAB Function'
 * '<S630>' : 'Quad_biplane/Vehicle Performance/Wing Load/Norm'
 * '<S631>' : 'Quad_biplane/Vehicle Performance/Wing Load/Wing Load1'
 * '<S632>' : 'Quad_biplane/Vehicle Performance/Wing Load/Wing Load2'
 */
#endif                                 /* RTW_HEADER_Quad_biplane_h_ */
