/*
 * Multirotor_Model_1.h
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

#ifndef RTW_HEADER_Multirotor_Model_1_h_
#define RTW_HEADER_Multirotor_Model_1_h_
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <float.h>
#include <stddef.h>
#ifndef Multirotor_Model_1_COMMON_INCLUDES_
#define Multirotor_Model_1_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "rt_logging.h"
#endif                                 /* Multirotor_Model_1_COMMON_INCLUDES_ */

#include "Multirotor_Model_1_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "rtGetNaN.h"
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

/* Block signals for system '<S510>/For Each Subsystem' */
typedef struct {
  real_T nHzrps;                       /* '<S520>/Integrator' */
  real_T Torque;                       /* '<S518>/Multiply' */
  real_T i;                            /* '<S523>/Transfer Fcn' */
  real_T DataTypeConversion1;          /* '<S523>/Data Type Conversion1' */
  real_T it;                           /* '<S523>/Gain3' */
  real_T Integrator;                   /* '<S532>/Integrator' */
  real_T PolarisationOverVoltage;      /* '<S529>/Polarisation Over Voltage' */
  real_T PolarisationOhmicVoltage;     /* '<S529>/Polarisation Ohmic Voltage' */
  real_T Sum;                          /* '<S529>/Sum' */
  real_T DataTypeConversion2;          /* '<S523>/Data Type Conversion2' */
  real_T PolarisationOverVoltage_p;    /* '<S528>/Polarisation Over Voltage' */
  real_T PolarisationOhmicVoltage_i;   /* '<S528>/Polarisation Ohmic Voltage' */
  real_T Sum_h;                        /* '<S528>/Sum' */
  real_T ExponentialZone;              /* '<S530>/Exponential Zone' */
  real_T Sum_p;                        /* '<S523>/Sum' */
  real_T CurrentA;                     /* '<S523>/Gain' */
  real_T InternalResistanceOhms;       /* '<S523>/Internal Resistance [Ohms]' */
  real_T Saturation3;                  /* '<S523>/Saturation3' */
  real_T V;                            /* '<S523>/Gain2' */
  real_T MotorN;                       /* '<S547>/[rps] to [rpm]' */
  real_T Sum1;                         /* '<S547>/Sum1' */
  real_T FilterCoefficient;            /* '<S586>/Filter Coefficient' */
  real_T Saturation;                   /* '<S590>/Saturation' */
  real_T MechPower;                    /* '<S547>/Mech Power' */
  real_T Delay;                        /* '<S525>/Delay' */
  real_T MotorPower;                   /* '<S546>/Divide1' */
  real_T MotorI;                       /* '<S546>/i = P//V' */
  real_T MotorT;                       /* '<S546>/Motor Torque' */
  real_T MotorQ;                       /* '<S545>/Motor Heat [W]' */
  real_T Switch;                       /* '<S574>/Switch' */
  real_T SOC;                          /* '<S523>/Gain6' */
  real_T Probe[2];                     /* '<S539>/Probe' */
  real_T Constant;                     /* '<S542>/Constant' */
  real_T uT;                           /* '<S531>/1//T' */
  real_T AB;                           /* '<S531>/[A,B]' */
  real_T PolarisationResistancedch;   /* '<S529>/Polarisation Resistance dch' */
  real_T DCh;                          /* '<S529>/DCh' */
  real_T Q_heat_irrv_dch;              /* '<S529>/Q_heat_irrv_dch' */
  real_T Merge1;                       /* '<S529>/Merge1' */
  real_T Q_heat_rrv_dch;               /* '<S529>/Q_heat_rrv_dch' */
  real_T Sum1_k;                       /* '<S529>/Sum1' */
  real_T PolarisationResistanceCH;     /* '<S528>/Polarisation Resistance CH' */
  real_T Q_heat_irrv_ChW;              /* '<S528>/Q_heat_irrv_Ch [W]' */
  real_T Merge1_d;                     /* '<S528>/Merge1' */
  real_T Q_heat_rrv_Ch;                /* '<S528>/Q_heat_rrv_Ch' */
  real_T Sum1_h;                       /* '<S528>/Sum1' */
  real_T QBat;                         /* '<S523>/Sum2' */
  real_T CellCoreTemp;                 /* '<S532>/Cell Core Temp' */
  real_T Pcell;                        /* '<S523>/Divide2' */
  real_T Divide1;                      /* '<S532>/Divide1' */
  real_T u2piIIInertiaofallcomponentscon;
  /* '<S520>/1//(2pi*I) I= Inertia of all  components connected  to the shaft' */
  real_T load[6];                      /* '<S521>/MATLAB Function' */
  real_T n;                            /* '<S544>/Motor Efficiency Function' */
  boolean_T AND3;                      /* '<S574>/AND3' */
  boolean_T Memory;                    /* '<S574>/Memory' */
} B_CoreSubsys_Multirotor_Model_T;

/* Block states (default storage) for system '<S510>/For Each Subsystem' */
typedef struct {
  real_T Delay_DSTATE;                 /* '<S523>/Delay' */
  real_T Delay_DSTATE_b;               /* '<S525>/Delay' */
  int_T Integrator_IWORK;              /* '<S543>/Integrator' */
  int8_T If1_ActiveSubsystem;          /* '<S529>/If1' */
  int8_T If1_ActiveSubsystem_g;        /* '<S528>/If1' */
  boolean_T Memory_PreviousInput;      /* '<S574>/Memory' */
} DW_CoreSubsys_Multirotor_Mode_T;

/* Continuous states for system '<S510>/For Each Subsystem' */
typedef struct {
  real_T Integrator_CSTATE_pb;         /* '<S520>/Integrator' */
  real_T TransferFcn_CSTATE;           /* '<S523>/Transfer Fcn' */
  real_T Integrator1_CSTATE_c;         /* '<S523>/Integrator1' */
  real_T Integrator_CSTATE_a;          /* '<S532>/Integrator' */
  real_T Integrator_CSTATE_nm;         /* '<S583>/Integrator' */
  real_T Filter_CSTATE_pu;             /* '<S578>/Filter' */
  real_T Integrator_CSTATE_he;         /* '<S543>/Integrator' */
} X_CoreSubsys_Multirotor_Model_T;

/* State derivatives for system '<S510>/For Each Subsystem' */
typedef struct {
  real_T Integrator_CSTATE_pb;         /* '<S520>/Integrator' */
  real_T TransferFcn_CSTATE;           /* '<S523>/Transfer Fcn' */
  real_T Integrator1_CSTATE_c;         /* '<S523>/Integrator1' */
  real_T Integrator_CSTATE_a;          /* '<S532>/Integrator' */
  real_T Integrator_CSTATE_nm;         /* '<S583>/Integrator' */
  real_T Filter_CSTATE_pu;             /* '<S578>/Filter' */
  real_T Integrator_CSTATE_he;         /* '<S543>/Integrator' */
} XDot_CoreSubsys_Multirotor_Mo_T;

/* State Disabled for system '<S510>/For Each Subsystem' */
typedef struct {
  boolean_T Integrator_CSTATE_pb;      /* '<S520>/Integrator' */
  boolean_T TransferFcn_CSTATE;        /* '<S523>/Transfer Fcn' */
  boolean_T Integrator1_CSTATE_c;      /* '<S523>/Integrator1' */
  boolean_T Integrator_CSTATE_a;       /* '<S532>/Integrator' */
  boolean_T Integrator_CSTATE_nm;      /* '<S583>/Integrator' */
  boolean_T Filter_CSTATE_pu;          /* '<S578>/Filter' */
  boolean_T Integrator_CSTATE_he;      /* '<S543>/Integrator' */
} XDis_CoreSubsys_Multirotor_Mo_T;

/* Zero-crossing (trigger) state for system '<S510>/For Each Subsystem' */
typedef struct {
  ZCSigState Integrator_Reset_ZCE;     /* '<S543>/Integrator' */
} ZCE_CoreSubsys_Multirotor_Mod_T;

/* Block signals (default storage) */
typedef struct {
  real_T Delay[24];                    /* '<Root>/Delay' */
  real_T FilterCoefficient;            /* '<S346>/Filter Coefficient' */
  real_T ProportionalGain;             /* '<S396>/Proportional Gain' */
  real_T DerivativeGain;               /* '<S385>/Derivative Gain' */
  real_T FilterCoefficient_n;          /* '<S394>/Filter Coefficient' */
  real_T Saturation;                   /* '<S398>/Saturation' */
  real_T FilterCoefficient_j;          /* '<S491>/Filter Coefficient' */
  real_T Saturation_h;                 /* '<S495>/Saturation' */
  real_T FilterCoefficient_f;          /* '<S442>/Filter Coefficient' */
  real_T Saturation_hv;                /* '<S446>/Saturation' */
  real_T FilterCoefficient_m;          /* '<S45>/Filter Coefficient' */
  real_T Gain1;                        /* '<S9>/Gain1' */
  real_T Gain;                         /* '<S9>/Gain' */
  real_T Sum1;                         /* '<S9>/Sum1' */
  real_T FilterCoefficient_p;          /* '<S145>/Filter Coefficient' */
  real_T Saturation_j;                 /* '<S149>/Saturation' */
  real_T FilterCoefficient_jz;         /* '<S196>/Filter Coefficient' */
  real_T FilterCoefficient_a;          /* '<S97>/Filter Coefficient' */
  real_T Gain1_b;                      /* '<S59>/Gain1' */
  real_T FilterCoefficient_a2;         /* '<S244>/Filter Coefficient' */
  real_T FilterCoefficient_c;          /* '<S292>/Filter Coefficient' */
  real_T Saturation_o;                 /* '<S296>/Saturation' */
  real_T Delay_b;                      /* '<S2>/Delay' */
  real_T Gain1_d;                      /* '<Root>/Gain1' */
  real_T Gain_d;                       /* '<Root>/Gain' */
  real_T Gain2;                        /* '<Root>/Gain2' */
  real_T IntegralGain;                 /* '<S39>/Integral Gain' */
  real_T IntegralGain_d;               /* '<S91>/Integral Gain' */
  real_T IntegralGain_i;               /* '<S139>/Integral Gain' */
  real_T IntegralGain_k;               /* '<S190>/Integral Gain' */
  real_T IntegralGain_d3;              /* '<S238>/Integral Gain' */
  real_T IntegralGain_g;               /* '<S286>/Integral Gain' */
  real_T IntegralGain_h;               /* '<S340>/Integral Gain' */
  real_T IntegralGain_m;               /* '<S388>/Integral Gain' */
  real_T IntegralGain_gm;              /* '<S436>/Integral Gain' */
  real_T IntegralGain_i1;              /* '<S485>/Integral Gain' */
  real_T Total_Wing_Load[6];           /* '<S512>/MATLAB Function' */
  real_T Total_Weight_Load[6];         /* '<S511>/MATLAB Function' */
  real_T Total_Rotor_Load[6];          /* '<S510>/MATLAB Function1' */
  real_T ImpAsg_InsertedFor_ShaftRPMs_at[4];/* '<S514>/Propulsor' */
  real_T Total_Fuselage_Load[6];       /* '<S509>/MATLAB Function' */
  real_T Z_desired;                    /* '<Root>/Mission Profile' */
  real_T X_desired;                    /* '<Root>/Mission Profile' */
  real_T psi_desired;                  /* '<Root>/Mission Profile' */
  real_T a_body[3];                    /* '<S2>/Translational Dynamics' */
  real_T P_dot_new[3];                 /* '<S2>/Transform1' */
  real_T Eang_dot_new[3];              /* '<S2>/Transform1' */
  real_T States_New[24];               /* '<S2>/State_update' */
  real_T reset_flag;                   /* '<S2>/State_update' */
  real_T om_dot[3];                    /* '<S2>/Rotational Dynamics' */
  real_T u_des;                        /* '<S8>/MATLAB Function' */
  real_T v_des;                        /* '<S8>/MATLAB Function' */
  real_T w_des;                        /* '<S8>/MATLAB Function' */
  real_T r_des;                        /* '<S8>/MATLAB Function' */
  real_T ssw;                          /* '<S1>/MATLAB Function' */
  real_T RPMs[4];                      /* '<S1>/MATLAB Function' */
  B_CoreSubsys_Multirotor_Model_T CoreSubsys[4];/* '<S510>/For Each Subsystem' */
} B_Multirotor_Model_1_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T Delay_DSTATE[24];             /* '<Root>/Delay' */
  real_T Delay_DSTATE_m;               /* '<S1>/Delay' */
  real_T Delay_DSTATE_e;               /* '<S2>/Delay' */
  DW_CoreSubsys_Multirotor_Mode_T CoreSubsys[4];/* '<S510>/For Each Subsystem' */
} DW_Multirotor_Model_1_T;

/* Continuous states (default storage) */
typedef struct {
  real_T Integrator_CSTATE;            /* '<S343>/Integrator' */
  real_T Filter_CSTATE;                /* '<S338>/Filter' */
  real_T Integrator_CSTATE_b;          /* '<S391>/Integrator' */
  real_T Filter_CSTATE_j;              /* '<S386>/Filter' */
  real_T Integrator_CSTATE_b0;         /* '<S488>/Integrator' */
  real_T Filter_CSTATE_p;              /* '<S483>/Filter' */
  real_T Integrator_CSTATE_d;          /* '<S439>/Integrator' */
  real_T Filter_CSTATE_a;              /* '<S434>/Filter' */
  real_T Integrator_CSTATE_f;          /* '<S42>/Integrator' */
  real_T Filter_CSTATE_e;              /* '<S37>/Filter' */
  real_T Integrator_CSTATE_e;          /* '<S142>/Integrator' */
  real_T Filter_CSTATE_o;              /* '<S137>/Filter' */
  real_T Integrator_CSTATE_n;          /* '<S193>/Integrator' */
  real_T Filter_CSTATE_e2;             /* '<S188>/Filter' */
  real_T Integrator_CSTATE_k;          /* '<S94>/Integrator' */
  real_T Filter_CSTATE_j2;             /* '<S89>/Filter' */
  real_T Integrator_CSTATE_h;          /* '<S241>/Integrator' */
  real_T Filter_CSTATE_eb;             /* '<S236>/Filter' */
  real_T Integrator_CSTATE_h4;         /* '<S289>/Integrator' */
  real_T Filter_CSTATE_d;              /* '<S284>/Filter' */
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
  X_CoreSubsys_Multirotor_Model_T CoreSubsys[4];/* '<S514>/CoreSubsys' */
} X_Multirotor_Model_1_T;

/* State derivatives (default storage) */
typedef struct {
  real_T Integrator_CSTATE;            /* '<S343>/Integrator' */
  real_T Filter_CSTATE;                /* '<S338>/Filter' */
  real_T Integrator_CSTATE_b;          /* '<S391>/Integrator' */
  real_T Filter_CSTATE_j;              /* '<S386>/Filter' */
  real_T Integrator_CSTATE_b0;         /* '<S488>/Integrator' */
  real_T Filter_CSTATE_p;              /* '<S483>/Filter' */
  real_T Integrator_CSTATE_d;          /* '<S439>/Integrator' */
  real_T Filter_CSTATE_a;              /* '<S434>/Filter' */
  real_T Integrator_CSTATE_f;          /* '<S42>/Integrator' */
  real_T Filter_CSTATE_e;              /* '<S37>/Filter' */
  real_T Integrator_CSTATE_e;          /* '<S142>/Integrator' */
  real_T Filter_CSTATE_o;              /* '<S137>/Filter' */
  real_T Integrator_CSTATE_n;          /* '<S193>/Integrator' */
  real_T Filter_CSTATE_e2;             /* '<S188>/Filter' */
  real_T Integrator_CSTATE_k;          /* '<S94>/Integrator' */
  real_T Filter_CSTATE_j2;             /* '<S89>/Filter' */
  real_T Integrator_CSTATE_h;          /* '<S241>/Integrator' */
  real_T Filter_CSTATE_eb;             /* '<S236>/Filter' */
  real_T Integrator_CSTATE_h4;         /* '<S289>/Integrator' */
  real_T Filter_CSTATE_d;              /* '<S284>/Filter' */
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
  XDot_CoreSubsys_Multirotor_Mo_T CoreSubsys[4];/* '<S514>/CoreSubsys' */
} XDot_Multirotor_Model_1_T;

/* State disabled  */
typedef struct {
  boolean_T Integrator_CSTATE;         /* '<S343>/Integrator' */
  boolean_T Filter_CSTATE;             /* '<S338>/Filter' */
  boolean_T Integrator_CSTATE_b;       /* '<S391>/Integrator' */
  boolean_T Filter_CSTATE_j;           /* '<S386>/Filter' */
  boolean_T Integrator_CSTATE_b0;      /* '<S488>/Integrator' */
  boolean_T Filter_CSTATE_p;           /* '<S483>/Filter' */
  boolean_T Integrator_CSTATE_d;       /* '<S439>/Integrator' */
  boolean_T Filter_CSTATE_a;           /* '<S434>/Filter' */
  boolean_T Integrator_CSTATE_f;       /* '<S42>/Integrator' */
  boolean_T Filter_CSTATE_e;           /* '<S37>/Filter' */
  boolean_T Integrator_CSTATE_e;       /* '<S142>/Integrator' */
  boolean_T Filter_CSTATE_o;           /* '<S137>/Filter' */
  boolean_T Integrator_CSTATE_n;       /* '<S193>/Integrator' */
  boolean_T Filter_CSTATE_e2;          /* '<S188>/Filter' */
  boolean_T Integrator_CSTATE_k;       /* '<S94>/Integrator' */
  boolean_T Filter_CSTATE_j2;          /* '<S89>/Filter' */
  boolean_T Integrator_CSTATE_h;       /* '<S241>/Integrator' */
  boolean_T Filter_CSTATE_eb;          /* '<S236>/Filter' */
  boolean_T Integrator_CSTATE_h4;      /* '<S289>/Integrator' */
  boolean_T Filter_CSTATE_d;           /* '<S284>/Filter' */
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
  XDis_CoreSubsys_Multirotor_Mo_T CoreSubsys[4];/* '<S514>/CoreSubsys' */
} XDis_Multirotor_Model_1_T;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState Integrator2_Reset_ZCE;    /* '<S2>/Integrator2' */
  ZCSigState Integrator8_Reset_ZCE;    /* '<S2>/Integrator8' */
  ZCE_CoreSubsys_Multirotor_Mod_T CoreSubsys[4];/* '<S510>/For Each Subsystem' */
} PrevZCX_Multirotor_Model_1_T;

#ifndef ODE3_INTG
#define ODE3_INTG

/* ODE3 Integration Data */
typedef struct {
  real_T *y;                           /* output */
  real_T *f[3];                        /* derivatives */
} ODE3_IntgData;

#endif

/* Parameters for system: '<S510>/For Each Subsystem' */
struct P_CoreSubsys_Multirotor_Model_T_ {
  real_T FilteredDerivativeDiscreteorCon;
                              /* Mask Parameter: FilteredDerivativeDiscreteorCon
                               * Referenced by: '<S531>/[A,B]'
                               */
  real_T FilteredDerivativeDiscreteorC_m;
                              /* Mask Parameter: FilteredDerivativeDiscreteorC_m
                               * Referenced by: '<S531>/[A,B]'
                               */
  real_T TorqueController_InitialConditi;
                              /* Mask Parameter: TorqueController_InitialConditi
                               * Referenced by: '<S578>/Filter'
                               */
  real_T TorqueController_InitialCondi_i;
                              /* Mask Parameter: TorqueController_InitialCondi_i
                               * Referenced by: '<S583>/Integrator'
                               */
  real_T FilteredDerivativeDiscreteorC_c;
                              /* Mask Parameter: FilteredDerivativeDiscreteorC_c
                               * Referenced by: '<S531>/Gain'
                               */
  real_T TorqueController_LowerSaturatio;
                              /* Mask Parameter: TorqueController_LowerSaturatio
                               * Referenced by:
                               *   '<S590>/Saturation'
                               *   '<S576>/DeadZone'
                               */
  real_T TorqueController_N;           /* Mask Parameter: TorqueController_N
                                        * Referenced by: '<S586>/Filter Coefficient'
                                        */
  real_T FilteredDerivativeDiscreteorC_n;
                              /* Mask Parameter: FilteredDerivativeDiscreteorC_n
                               * Referenced by: '<S539>/Time constant'
                               */
  real_T CompareToConstant1_const;   /* Mask Parameter: CompareToConstant1_const
                                      * Referenced by: '<S527>/Constant'
                                      */
  real_T CompareToConstant_const;     /* Mask Parameter: CompareToConstant_const
                                       * Referenced by: '<S526>/Constant'
                                       */
  real_T FilteredDerivativeDiscreteorC_b;
                              /* Mask Parameter: FilteredDerivativeDiscreteorC_b
                               * Referenced by: '<S539>/Minimum sampling to time constant ratio'
                               */
  real_T FilteredDerivativeDiscreteor_cf;
                              /* Mask Parameter: FilteredDerivativeDiscreteor_cf
                               * Referenced by: '<S542>/Constant'
                               */
  real_T Constant1_Value;              /* Expression: 0
                                        * Referenced by: '<S574>/Constant1'
                                        */
  real_T rpstorpm_Gain;                /* Expression: 60
                                        * Referenced by: '<S518>/rps to rpm'
                                        */
  real_T Multiply_Gain;                /* Expression: -1
                                        * Referenced by: '<S518>/Multiply'
                                        */
  real_T TransferFcn_A;                /* Computed Parameter: TransferFcn_A
                                        * Referenced by: '<S523>/Transfer Fcn'
                                        */
  real_T TransferFcn_C;                /* Computed Parameter: TransferFcn_C
                                        * Referenced by: '<S523>/Transfer Fcn'
                                        */
  real_T Integrator1_LowerSat;         /* Expression: -inf
                                        * Referenced by: '<S523>/Integrator1'
                                        */
  real_T Gain3_Gain;                   /* Expression: 1/3600
                                        * Referenced by: '<S523>/Gain3'
                                        */
  real_T Saturation_LowerSat;          /* Expression: 0
                                        * Referenced by: '<S523>/Saturation'
                                        */
  real_T Saturation2_LowerSat;         /* Expression: 0
                                        * Referenced by: '<S523>/Saturation2'
                                        */
  real_T Delay_InitialCondition;       /* Expression: 0.0
                                        * Referenced by: '<S523>/Delay'
                                        */
  real_T Saturation3_LowerSat;         /* Expression: 0
                                        * Referenced by: '<S523>/Saturation3'
                                        */
  real_T rpstorpm_Gain_j;              /* Expression: 60
                                        * Referenced by: '<S547>/[rps] to [rpm]'
                                        */
  real_T Delay_InitialCondition_g;     /* Expression: 0.0
                                        * Referenced by: '<S525>/Delay'
                                        */
  real_T rpmtorads_Gain;               /* Expression: 6.28318/60
                                        * Referenced by: '<S544>/[rpm] to [rad//s]'
                                        */
  real_T Saturation_UpperSat;          /* Expression: 1
                                        * Referenced by: '<S544>/Saturation'
                                        */
  real_T Saturation_LowerSat_c;        /* Expression: 0.7
                                        * Referenced by: '<S544>/Saturation'
                                        */
  real_T ZeroGain_Gain;                /* Expression: 0
                                        * Referenced by: '<S574>/ZeroGain'
                                        */
  real_T Gain6_Gain;                   /* Expression: 100
                                        * Referenced by: '<S523>/Gain6'
                                        */
  real_T Constant_Value;               /* Expression: 0
                                        * Referenced by: '<S531>/Constant'
                                        */
  real_T Integrator_UpperSat;          /* Expression: antiwindupUpperLimit
                                        * Referenced by: '<S543>/Integrator'
                                        */
  real_T Integrator_LowerSat;          /* Expression: antiwindupLowerLimit
                                        * Referenced by: '<S543>/Integrator'
                                        */
  real_T Saturation_UpperSat_g;        /* Expression: windupUpperLimit
                                        * Referenced by: '<S543>/Saturation'
                                        */
  real_T Saturation_LowerSat_d;        /* Expression: windupLowerLimit
                                        * Referenced by: '<S543>/Saturation'
                                        */
  real_T Constant1_Value_d;            /* Expression: 1
                                        * Referenced by: '<S529>/Constant1'
                                        */
  real_T Constant_Value_b;             /* Expression: 1
                                        * Referenced by: '<S529>/Constant'
                                        */
  real_T Merge1_InitialOutput;       /* Computed Parameter: Merge1_InitialOutput
                                      * Referenced by: '<S529>/Merge1'
                                      */
  real_T Constant_Value_h;             /* Expression: 1
                                        * Referenced by: '<S528>/Constant'
                                        */
  real_T Constant1_Value_a;            /* Expression: 1
                                        * Referenced by: '<S528>/Constant1'
                                        */
  real_T Merge1_InitialOutput_b;   /* Computed Parameter: Merge1_InitialOutput_b
                                    * Referenced by: '<S528>/Merge1'
                                    */
  boolean_T Memory_InitialCondition;
                                  /* Computed Parameter: Memory_InitialCondition
                                   * Referenced by: '<S574>/Memory'
                                   */
};

/* Parameters (default storage) */
struct P_Multirotor_Model_1_T_ {
  ip_bus ip;                           /* Variable: ip
                                        * Referenced by: '<S521>/Constant'
                                        */
  Quad_bus Quad;                       /* Variable: Quad
                                        * Referenced by:
                                        *   '<S1>/Constant'
                                        *   '<S2>/Constant'
                                        *   '<S509>/Constant'
                                        *   '<S510>/Constant'
                                        *   '<S511>/Constant'
                                        *   '<S9>/Gain'
                                        */
  real_T Bat_Rint;                     /* Variable: Bat_Rint
                                        * Referenced by: '<S523>/Internal Resistance [Ohms]'
                                        */
  real_T Cp;                           /* Variable: Cp
                                        * Referenced by: '<S532>/Cp*m'
                                        */
  real_T E0;                           /* Variable: E0
                                        * Referenced by: '<S523>/E0//Nernst [V]'
                                        */
  real_T I_shaft_PM;                   /* Variable: I_shaft_PM
                                        * Referenced by: '<S520>/1//(2pi*I) I= Inertia of all  components connected  to the shaft'
                                        */
  real_T Int_n_PM;                     /* Variable: Int_n_PM
                                        * Referenced by: '<S520>/Integrator'
                                        */
  real_T Kd_TCntrl;                    /* Variable: Kd_TCntrl
                                        * Referenced by: '<S577>/Derivative Gain'
                                        */
  real_T Ki_TCntrl;                    /* Variable: Ki_TCntrl
                                        * Referenced by: '<S580>/Integral Gain'
                                        */
  real_T Kp_TCntrl;                    /* Variable: Kp_TCntrl
                                        * Referenced by: '<S588>/Proportional Gain'
                                        */
  real_T N_parallel;                   /* Variable: N_parallel
                                        * Referenced by: '<S523>/Gain'
                                        */
  real_T N_series;                     /* Variable: N_series
                                        * Referenced by: '<S523>/Gain2'
                                        */
  real_T Q_max;                        /* Variable: Q_max
                                        * Referenced by:
                                        *   '<S523>/Capacity [Ah]'
                                        *   '<S523>/Max Charge [Ah]'
                                        *   '<S523>/Integrator1'
                                        *   '<S523>/Saturation'
                                        *   '<S523>/Saturation1'
                                        *   '<S523>/Saturation2'
                                        */
  real_T R;                            /* Variable: R
                                        * Referenced by: '<S544>/Constant5'
                                        */
  real_T SOC_init;                     /* Variable: SOC_init
                                        * Referenced by: '<S523>/Integrator1'
                                        */
  real_T T0a;                          /* Variable: T0a
                                        * Referenced by: '<S544>/Constant2'
                                        */
  real_T T0b;                          /* Variable: T0b
                                        * Referenced by: '<S544>/Constant3'
                                        */
  real_T T0c;                          /* Variable: T0c
                                        * Referenced by: '<S544>/Constant4'
                                        */
  real_T TCntrl_maxlim;                /* Variable: TCntrl_maxlim
                                        * Referenced by:
                                        *   '<S590>/Saturation'
                                        *   '<S576>/DeadZone'
                                        */
  real_T TcoreI;                       /* Variable: TcoreI
                                        * Referenced by: '<S532>/Integrator'
                                        */
  real_T Vcell_max;                    /* Variable: Vcell_max
                                        * Referenced by: '<S523>/Saturation3'
                                        */
  real_T kt;                           /* Variable: kt
                                        * Referenced by: '<S544>/Constant'
                                        */
  real_T m_cell;                       /* Variable: m_cell
                                        * Referenced by: '<S532>/Cp*m'
                                        */
  real_T PIDController_D;              /* Mask Parameter: PIDController_D
                                        * Referenced by: '<S337>/Derivative Gain'
                                        */
  real_T PIDController1_D;             /* Mask Parameter: PIDController1_D
                                        * Referenced by: '<S385>/Derivative Gain'
                                        */
  real_T PIDController_D_h;            /* Mask Parameter: PIDController_D_h
                                        * Referenced by: '<S482>/Derivative Gain'
                                        */
  real_T PIDController2_D;             /* Mask Parameter: PIDController2_D
                                        * Referenced by: '<S433>/Derivative Gain'
                                        */
  real_T PIDController_D_f;            /* Mask Parameter: PIDController_D_f
                                        * Referenced by: '<S36>/Derivative Gain'
                                        */
  real_T PIDController1_D_a;           /* Mask Parameter: PIDController1_D_a
                                        * Referenced by: '<S136>/Derivative Gain'
                                        */
  real_T PIDController_D_n;            /* Mask Parameter: PIDController_D_n
                                        * Referenced by: '<S187>/Derivative Gain'
                                        */
  real_T PIDController_D_e;            /* Mask Parameter: PIDController_D_e
                                        * Referenced by: '<S88>/Derivative Gain'
                                        */
  real_T PIDController1_D_e;           /* Mask Parameter: PIDController1_D_e
                                        * Referenced by: '<S235>/Derivative Gain'
                                        */
  real_T PIDController2_D_b;           /* Mask Parameter: PIDController2_D_b
                                        * Referenced by: '<S283>/Derivative Gain'
                                        */
  real_T PIDController_I;              /* Mask Parameter: PIDController_I
                                        * Referenced by: '<S39>/Integral Gain'
                                        */
  real_T PIDController_I_l;            /* Mask Parameter: PIDController_I_l
                                        * Referenced by: '<S91>/Integral Gain'
                                        */
  real_T PIDController1_I;             /* Mask Parameter: PIDController1_I
                                        * Referenced by: '<S139>/Integral Gain'
                                        */
  real_T PIDController_I_g;            /* Mask Parameter: PIDController_I_g
                                        * Referenced by: '<S190>/Integral Gain'
                                        */
  real_T PIDController1_I_a;           /* Mask Parameter: PIDController1_I_a
                                        * Referenced by: '<S238>/Integral Gain'
                                        */
  real_T PIDController2_I;             /* Mask Parameter: PIDController2_I
                                        * Referenced by: '<S286>/Integral Gain'
                                        */
  real_T PIDController_I_a;            /* Mask Parameter: PIDController_I_a
                                        * Referenced by: '<S340>/Integral Gain'
                                        */
  real_T PIDController1_I_d;           /* Mask Parameter: PIDController1_I_d
                                        * Referenced by: '<S388>/Integral Gain'
                                        */
  real_T PIDController2_I_g;           /* Mask Parameter: PIDController2_I_g
                                        * Referenced by: '<S436>/Integral Gain'
                                        */
  real_T PIDController_I_lu;           /* Mask Parameter: PIDController_I_lu
                                        * Referenced by: '<S485>/Integral Gain'
                                        */
  real_T PIDController_InitialConditionF;
                              /* Mask Parameter: PIDController_InitialConditionF
                               * Referenced by: '<S338>/Filter'
                               */
  real_T PIDController1_InitialCondition;
                              /* Mask Parameter: PIDController1_InitialCondition
                               * Referenced by: '<S386>/Filter'
                               */
  real_T PIDController_InitialConditio_e;
                              /* Mask Parameter: PIDController_InitialConditio_e
                               * Referenced by: '<S483>/Filter'
                               */
  real_T PIDController2_InitialCondition;
                              /* Mask Parameter: PIDController2_InitialCondition
                               * Referenced by: '<S434>/Filter'
                               */
  real_T PIDController_InitialConditio_l;
                              /* Mask Parameter: PIDController_InitialConditio_l
                               * Referenced by: '<S37>/Filter'
                               */
  real_T PIDController1_InitialConditi_h;
                              /* Mask Parameter: PIDController1_InitialConditi_h
                               * Referenced by: '<S137>/Filter'
                               */
  real_T PIDController_InitialConditio_k;
                              /* Mask Parameter: PIDController_InitialConditio_k
                               * Referenced by: '<S188>/Filter'
                               */
  real_T PIDController_InitialConditi_ek;
                              /* Mask Parameter: PIDController_InitialConditi_ek
                               * Referenced by: '<S89>/Filter'
                               */
  real_T PIDController1_InitialConditi_c;
                              /* Mask Parameter: PIDController1_InitialConditi_c
                               * Referenced by: '<S236>/Filter'
                               */
  real_T PIDController2_InitialConditi_h;
                              /* Mask Parameter: PIDController2_InitialConditi_h
                               * Referenced by: '<S284>/Filter'
                               */
  real_T PIDController_InitialConditio_b;
                              /* Mask Parameter: PIDController_InitialConditio_b
                               * Referenced by: '<S343>/Integrator'
                               */
  real_T PIDController1_InitialConditi_f;
                              /* Mask Parameter: PIDController1_InitialConditi_f
                               * Referenced by: '<S391>/Integrator'
                               */
  real_T PIDController_InitialConditio_o;
                              /* Mask Parameter: PIDController_InitialConditio_o
                               * Referenced by: '<S488>/Integrator'
                               */
  real_T PIDController2_InitialConditi_j;
                              /* Mask Parameter: PIDController2_InitialConditi_j
                               * Referenced by: '<S439>/Integrator'
                               */
  real_T PIDController_InitialConditio_g;
                              /* Mask Parameter: PIDController_InitialConditio_g
                               * Referenced by: '<S42>/Integrator'
                               */
  real_T PIDController1_InitialConditi_k;
                              /* Mask Parameter: PIDController1_InitialConditi_k
                               * Referenced by: '<S142>/Integrator'
                               */
  real_T PIDController_InitialConditio_m;
                              /* Mask Parameter: PIDController_InitialConditio_m
                               * Referenced by: '<S193>/Integrator'
                               */
  real_T PIDController_InitialConditio_j;
                              /* Mask Parameter: PIDController_InitialConditio_j
                               * Referenced by: '<S94>/Integrator'
                               */
  real_T PIDController1_InitialConditi_e;
                              /* Mask Parameter: PIDController1_InitialConditi_e
                               * Referenced by: '<S241>/Integrator'
                               */
  real_T PIDController2_InitialConditi_i;
                              /* Mask Parameter: PIDController2_InitialConditi_i
                               * Referenced by: '<S289>/Integrator'
                               */
  real_T PIDController_LowerSaturationLi;
                              /* Mask Parameter: PIDController_LowerSaturationLi
                               * Referenced by: '<S350>/Saturation'
                               */
  real_T PIDController1_LowerSaturationL;
                              /* Mask Parameter: PIDController1_LowerSaturationL
                               * Referenced by: '<S398>/Saturation'
                               */
  real_T PIDController_LowerSaturation_e;
                              /* Mask Parameter: PIDController_LowerSaturation_e
                               * Referenced by: '<S495>/Saturation'
                               */
  real_T PIDController2_LowerSaturationL;
                              /* Mask Parameter: PIDController2_LowerSaturationL
                               * Referenced by: '<S446>/Saturation'
                               */
  real_T PIDController1_LowerSaturatio_j;
                              /* Mask Parameter: PIDController1_LowerSaturatio_j
                               * Referenced by: '<S149>/Saturation'
                               */
  real_T PIDController_LowerSaturation_l;
                              /* Mask Parameter: PIDController_LowerSaturation_l
                               * Referenced by: '<S200>/Saturation'
                               */
  real_T PIDController_LowerSaturation_d;
                              /* Mask Parameter: PIDController_LowerSaturation_d
                               * Referenced by: '<S101>/Saturation'
                               */
  real_T PIDController1_LowerSaturatio_l;
                              /* Mask Parameter: PIDController1_LowerSaturatio_l
                               * Referenced by: '<S248>/Saturation'
                               */
  real_T PIDController2_LowerSaturatio_m;
                              /* Mask Parameter: PIDController2_LowerSaturatio_m
                               * Referenced by: '<S296>/Saturation'
                               */
  real_T PIDController_N;              /* Mask Parameter: PIDController_N
                                        * Referenced by: '<S346>/Filter Coefficient'
                                        */
  real_T PIDController1_N;             /* Mask Parameter: PIDController1_N
                                        * Referenced by: '<S394>/Filter Coefficient'
                                        */
  real_T PIDController_N_c;            /* Mask Parameter: PIDController_N_c
                                        * Referenced by: '<S491>/Filter Coefficient'
                                        */
  real_T PIDController2_N;             /* Mask Parameter: PIDController2_N
                                        * Referenced by: '<S442>/Filter Coefficient'
                                        */
  real_T PIDController_N_o;            /* Mask Parameter: PIDController_N_o
                                        * Referenced by: '<S45>/Filter Coefficient'
                                        */
  real_T PIDController1_N_f;           /* Mask Parameter: PIDController1_N_f
                                        * Referenced by: '<S145>/Filter Coefficient'
                                        */
  real_T PIDController_N_oe;           /* Mask Parameter: PIDController_N_oe
                                        * Referenced by: '<S196>/Filter Coefficient'
                                        */
  real_T PIDController_N_f;            /* Mask Parameter: PIDController_N_f
                                        * Referenced by: '<S97>/Filter Coefficient'
                                        */
  real_T PIDController1_N_b;           /* Mask Parameter: PIDController1_N_b
                                        * Referenced by: '<S244>/Filter Coefficient'
                                        */
  real_T PIDController2_N_e;           /* Mask Parameter: PIDController2_N_e
                                        * Referenced by: '<S292>/Filter Coefficient'
                                        */
  real_T PIDController_P;              /* Mask Parameter: PIDController_P
                                        * Referenced by: '<S348>/Proportional Gain'
                                        */
  real_T PIDController1_P;             /* Mask Parameter: PIDController1_P
                                        * Referenced by: '<S396>/Proportional Gain'
                                        */
  real_T PIDController_P_m;            /* Mask Parameter: PIDController_P_m
                                        * Referenced by: '<S493>/Proportional Gain'
                                        */
  real_T PIDController2_P;             /* Mask Parameter: PIDController2_P
                                        * Referenced by: '<S444>/Proportional Gain'
                                        */
  real_T PIDController_P_my;           /* Mask Parameter: PIDController_P_my
                                        * Referenced by: '<S47>/Proportional Gain'
                                        */
  real_T PIDController1_P_l;           /* Mask Parameter: PIDController1_P_l
                                        * Referenced by: '<S147>/Proportional Gain'
                                        */
  real_T PIDController_P_mb;           /* Mask Parameter: PIDController_P_mb
                                        * Referenced by: '<S198>/Proportional Gain'
                                        */
  real_T PIDController_P_g;            /* Mask Parameter: PIDController_P_g
                                        * Referenced by: '<S99>/Proportional Gain'
                                        */
  real_T PIDController1_P_i;           /* Mask Parameter: PIDController1_P_i
                                        * Referenced by: '<S246>/Proportional Gain'
                                        */
  real_T PIDController2_P_b;           /* Mask Parameter: PIDController2_P_b
                                        * Referenced by: '<S294>/Proportional Gain'
                                        */
  real_T PIDController_UpperSaturationLi;
                              /* Mask Parameter: PIDController_UpperSaturationLi
                               * Referenced by: '<S350>/Saturation'
                               */
  real_T PIDController1_UpperSaturationL;
                              /* Mask Parameter: PIDController1_UpperSaturationL
                               * Referenced by: '<S398>/Saturation'
                               */
  real_T PIDController_UpperSaturation_k;
                              /* Mask Parameter: PIDController_UpperSaturation_k
                               * Referenced by: '<S495>/Saturation'
                               */
  real_T PIDController2_UpperSaturationL;
                              /* Mask Parameter: PIDController2_UpperSaturationL
                               * Referenced by: '<S446>/Saturation'
                               */
  real_T PIDController1_UpperSaturatio_n;
                              /* Mask Parameter: PIDController1_UpperSaturatio_n
                               * Referenced by: '<S149>/Saturation'
                               */
  real_T PIDController_UpperSaturation_i;
                              /* Mask Parameter: PIDController_UpperSaturation_i
                               * Referenced by: '<S200>/Saturation'
                               */
  real_T PIDController_UpperSaturation_j;
                              /* Mask Parameter: PIDController_UpperSaturation_j
                               * Referenced by: '<S101>/Saturation'
                               */
  real_T PIDController1_UpperSaturatio_c;
                              /* Mask Parameter: PIDController1_UpperSaturatio_c
                               * Referenced by: '<S248>/Saturation'
                               */
  real_T PIDController2_UpperSaturatio_k;
                              /* Mask Parameter: PIDController2_UpperSaturatio_k
                               * Referenced by: '<S296>/Saturation'
                               */
  real_T Delay_InitialCondition[24];
                /* Expression: [0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0]
                 * Referenced by: '<Root>/Delay'
                 */
  real_T Constant_Value;               /* Expression: 0
                                        * Referenced by: '<S8>/Constant'
                                        */
  real_T Gain1_Gain;                   /* Expression: -1
                                        * Referenced by: '<S9>/Gain1'
                                        */
  real_T Delay_InitialCondition_o;     /* Expression: 720
                                        * Referenced by: '<S1>/Delay'
                                        */
  real_T Gain1_Gain_l;                 /* Expression: -1
                                        * Referenced by: '<S59>/Gain1'
                                        */
  real_T Constant_Value_k;             /* Expression: 1
                                        * Referenced by: '<S512>/Constant'
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
  real_T Delay_InitialCondition_h;     /* Expression: 0
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
  real_T Gain1_Gain_b;                 /* Expression: -1
                                        * Referenced by: '<Root>/Gain1'
                                        */
  real_T Gain_Gain;                    /* Expression: -1
                                        * Referenced by: '<Root>/Gain'
                                        */
  real_T Gain2_Gain;                   /* Expression: -1
                                        * Referenced by: '<Root>/Gain2'
                                        */
  P_CoreSubsys_Multirotor_Model_T CoreSubsys;/* '<S510>/For Each Subsystem' */
};

/* Real-time Model Data Structure */
struct tag_RTM_Multirotor_Model_1_T {
  const char_T *errorStatus;
  RTWLogInfo *rtwLogInfo;
  RTWSolverInfo solverInfo;
  X_Multirotor_Model_1_T *contStates;
  int_T *periodicContStateIndices;
  real_T *periodicContStateRanges;
  real_T *derivs;
  boolean_T *contStateDisabled;
  boolean_T zCCacheNeedsReset;
  boolean_T derivCacheNeedsReset;
  boolean_T CTOutputIncnstWithState;
  real_T odeY[60];
  real_T odeF[3][60];
  ODE3_IntgData intgData;

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
    boolean_T firstInitCondFlag;
    time_T tFinal;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

/* Block parameters (default storage) */
extern P_Multirotor_Model_1_T Multirotor_Model_1_P;

/* Block signals (default storage) */
extern B_Multirotor_Model_1_T Multirotor_Model_1_B;

/* Continuous states (default storage) */
extern X_Multirotor_Model_1_T Multirotor_Model_1_X;

/* Block states (default storage) */
extern DW_Multirotor_Model_1_T Multirotor_Model_1_DW;

/* Zero-crossing (trigger) state */
extern PrevZCX_Multirotor_Model_1_T Multirotor_Model_1_PrevZCX;

/* Model entry point functions */
extern void Multirotor_Model_1_initialize(void);
extern void Multirotor_Model_1_step(void);
extern void Multirotor_Model_1_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Multirotor_Model_1_T *const Multirotor_Model_1_M;

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
 * '<Root>' : 'Multirotor_Model_1'
 * '<S1>'   : 'Multirotor_Model_1/Control System'
 * '<S2>'   : 'Multirotor_Model_1/Flight Dynamics'
 * '<S3>'   : 'Multirotor_Model_1/Mission Profile'
 * '<S4>'   : 'Multirotor_Model_1/Vehicle Performance'
 * '<S5>'   : 'Multirotor_Model_1/Control System/Altitude Controller'
 * '<S6>'   : 'Multirotor_Model_1/Control System/Attitude Controller'
 * '<S7>'   : 'Multirotor_Model_1/Control System/MATLAB Function'
 * '<S8>'   : 'Multirotor_Model_1/Control System/Position Controller'
 * '<S9>'   : 'Multirotor_Model_1/Control System/Altitude Controller/Velocity Controller'
 * '<S10>'  : 'Multirotor_Model_1/Control System/Altitude Controller/Velocity Controller/PID Controller'
 * '<S11>'  : 'Multirotor_Model_1/Control System/Altitude Controller/Velocity Controller/PID Controller/Anti-windup'
 * '<S12>'  : 'Multirotor_Model_1/Control System/Altitude Controller/Velocity Controller/PID Controller/D Gain'
 * '<S13>'  : 'Multirotor_Model_1/Control System/Altitude Controller/Velocity Controller/PID Controller/Filter'
 * '<S14>'  : 'Multirotor_Model_1/Control System/Altitude Controller/Velocity Controller/PID Controller/Filter ICs'
 * '<S15>'  : 'Multirotor_Model_1/Control System/Altitude Controller/Velocity Controller/PID Controller/I Gain'
 * '<S16>'  : 'Multirotor_Model_1/Control System/Altitude Controller/Velocity Controller/PID Controller/Ideal P Gain'
 * '<S17>'  : 'Multirotor_Model_1/Control System/Altitude Controller/Velocity Controller/PID Controller/Ideal P Gain Fdbk'
 * '<S18>'  : 'Multirotor_Model_1/Control System/Altitude Controller/Velocity Controller/PID Controller/Integrator'
 * '<S19>'  : 'Multirotor_Model_1/Control System/Altitude Controller/Velocity Controller/PID Controller/Integrator ICs'
 * '<S20>'  : 'Multirotor_Model_1/Control System/Altitude Controller/Velocity Controller/PID Controller/N Copy'
 * '<S21>'  : 'Multirotor_Model_1/Control System/Altitude Controller/Velocity Controller/PID Controller/N Gain'
 * '<S22>'  : 'Multirotor_Model_1/Control System/Altitude Controller/Velocity Controller/PID Controller/P Copy'
 * '<S23>'  : 'Multirotor_Model_1/Control System/Altitude Controller/Velocity Controller/PID Controller/Parallel P Gain'
 * '<S24>'  : 'Multirotor_Model_1/Control System/Altitude Controller/Velocity Controller/PID Controller/Reset Signal'
 * '<S25>'  : 'Multirotor_Model_1/Control System/Altitude Controller/Velocity Controller/PID Controller/Saturation'
 * '<S26>'  : 'Multirotor_Model_1/Control System/Altitude Controller/Velocity Controller/PID Controller/Saturation Fdbk'
 * '<S27>'  : 'Multirotor_Model_1/Control System/Altitude Controller/Velocity Controller/PID Controller/Sum'
 * '<S28>'  : 'Multirotor_Model_1/Control System/Altitude Controller/Velocity Controller/PID Controller/Sum Fdbk'
 * '<S29>'  : 'Multirotor_Model_1/Control System/Altitude Controller/Velocity Controller/PID Controller/Tracking Mode'
 * '<S30>'  : 'Multirotor_Model_1/Control System/Altitude Controller/Velocity Controller/PID Controller/Tracking Mode Sum'
 * '<S31>'  : 'Multirotor_Model_1/Control System/Altitude Controller/Velocity Controller/PID Controller/Tsamp - Integral'
 * '<S32>'  : 'Multirotor_Model_1/Control System/Altitude Controller/Velocity Controller/PID Controller/Tsamp - Ngain'
 * '<S33>'  : 'Multirotor_Model_1/Control System/Altitude Controller/Velocity Controller/PID Controller/postSat Signal'
 * '<S34>'  : 'Multirotor_Model_1/Control System/Altitude Controller/Velocity Controller/PID Controller/preSat Signal'
 * '<S35>'  : 'Multirotor_Model_1/Control System/Altitude Controller/Velocity Controller/PID Controller/Anti-windup/Passthrough'
 * '<S36>'  : 'Multirotor_Model_1/Control System/Altitude Controller/Velocity Controller/PID Controller/D Gain/Internal Parameters'
 * '<S37>'  : 'Multirotor_Model_1/Control System/Altitude Controller/Velocity Controller/PID Controller/Filter/Cont. Filter'
 * '<S38>'  : 'Multirotor_Model_1/Control System/Altitude Controller/Velocity Controller/PID Controller/Filter ICs/Internal IC - Filter'
 * '<S39>'  : 'Multirotor_Model_1/Control System/Altitude Controller/Velocity Controller/PID Controller/I Gain/Internal Parameters'
 * '<S40>'  : 'Multirotor_Model_1/Control System/Altitude Controller/Velocity Controller/PID Controller/Ideal P Gain/Passthrough'
 * '<S41>'  : 'Multirotor_Model_1/Control System/Altitude Controller/Velocity Controller/PID Controller/Ideal P Gain Fdbk/Disabled'
 * '<S42>'  : 'Multirotor_Model_1/Control System/Altitude Controller/Velocity Controller/PID Controller/Integrator/Continuous'
 * '<S43>'  : 'Multirotor_Model_1/Control System/Altitude Controller/Velocity Controller/PID Controller/Integrator ICs/Internal IC'
 * '<S44>'  : 'Multirotor_Model_1/Control System/Altitude Controller/Velocity Controller/PID Controller/N Copy/Disabled'
 * '<S45>'  : 'Multirotor_Model_1/Control System/Altitude Controller/Velocity Controller/PID Controller/N Gain/Internal Parameters'
 * '<S46>'  : 'Multirotor_Model_1/Control System/Altitude Controller/Velocity Controller/PID Controller/P Copy/Disabled'
 * '<S47>'  : 'Multirotor_Model_1/Control System/Altitude Controller/Velocity Controller/PID Controller/Parallel P Gain/Internal Parameters'
 * '<S48>'  : 'Multirotor_Model_1/Control System/Altitude Controller/Velocity Controller/PID Controller/Reset Signal/Disabled'
 * '<S49>'  : 'Multirotor_Model_1/Control System/Altitude Controller/Velocity Controller/PID Controller/Saturation/Passthrough'
 * '<S50>'  : 'Multirotor_Model_1/Control System/Altitude Controller/Velocity Controller/PID Controller/Saturation Fdbk/Disabled'
 * '<S51>'  : 'Multirotor_Model_1/Control System/Altitude Controller/Velocity Controller/PID Controller/Sum/Sum_PID'
 * '<S52>'  : 'Multirotor_Model_1/Control System/Altitude Controller/Velocity Controller/PID Controller/Sum Fdbk/Disabled'
 * '<S53>'  : 'Multirotor_Model_1/Control System/Altitude Controller/Velocity Controller/PID Controller/Tracking Mode/Disabled'
 * '<S54>'  : 'Multirotor_Model_1/Control System/Altitude Controller/Velocity Controller/PID Controller/Tracking Mode Sum/Passthrough'
 * '<S55>'  : 'Multirotor_Model_1/Control System/Altitude Controller/Velocity Controller/PID Controller/Tsamp - Integral/Passthrough'
 * '<S56>'  : 'Multirotor_Model_1/Control System/Altitude Controller/Velocity Controller/PID Controller/Tsamp - Ngain/Passthrough'
 * '<S57>'  : 'Multirotor_Model_1/Control System/Altitude Controller/Velocity Controller/PID Controller/postSat Signal/Forward_Path'
 * '<S58>'  : 'Multirotor_Model_1/Control System/Altitude Controller/Velocity Controller/PID Controller/preSat Signal/Forward_Path'
 * '<S59>'  : 'Multirotor_Model_1/Control System/Attitude Controller/Velocity'
 * '<S60>'  : 'Multirotor_Model_1/Control System/Attitude Controller/moments'
 * '<S61>'  : 'Multirotor_Model_1/Control System/Attitude Controller/Velocity/PID Controller'
 * '<S62>'  : 'Multirotor_Model_1/Control System/Attitude Controller/Velocity/PID Controller1'
 * '<S63>'  : 'Multirotor_Model_1/Control System/Attitude Controller/Velocity/PID Controller/Anti-windup'
 * '<S64>'  : 'Multirotor_Model_1/Control System/Attitude Controller/Velocity/PID Controller/D Gain'
 * '<S65>'  : 'Multirotor_Model_1/Control System/Attitude Controller/Velocity/PID Controller/Filter'
 * '<S66>'  : 'Multirotor_Model_1/Control System/Attitude Controller/Velocity/PID Controller/Filter ICs'
 * '<S67>'  : 'Multirotor_Model_1/Control System/Attitude Controller/Velocity/PID Controller/I Gain'
 * '<S68>'  : 'Multirotor_Model_1/Control System/Attitude Controller/Velocity/PID Controller/Ideal P Gain'
 * '<S69>'  : 'Multirotor_Model_1/Control System/Attitude Controller/Velocity/PID Controller/Ideal P Gain Fdbk'
 * '<S70>'  : 'Multirotor_Model_1/Control System/Attitude Controller/Velocity/PID Controller/Integrator'
 * '<S71>'  : 'Multirotor_Model_1/Control System/Attitude Controller/Velocity/PID Controller/Integrator ICs'
 * '<S72>'  : 'Multirotor_Model_1/Control System/Attitude Controller/Velocity/PID Controller/N Copy'
 * '<S73>'  : 'Multirotor_Model_1/Control System/Attitude Controller/Velocity/PID Controller/N Gain'
 * '<S74>'  : 'Multirotor_Model_1/Control System/Attitude Controller/Velocity/PID Controller/P Copy'
 * '<S75>'  : 'Multirotor_Model_1/Control System/Attitude Controller/Velocity/PID Controller/Parallel P Gain'
 * '<S76>'  : 'Multirotor_Model_1/Control System/Attitude Controller/Velocity/PID Controller/Reset Signal'
 * '<S77>'  : 'Multirotor_Model_1/Control System/Attitude Controller/Velocity/PID Controller/Saturation'
 * '<S78>'  : 'Multirotor_Model_1/Control System/Attitude Controller/Velocity/PID Controller/Saturation Fdbk'
 * '<S79>'  : 'Multirotor_Model_1/Control System/Attitude Controller/Velocity/PID Controller/Sum'
 * '<S80>'  : 'Multirotor_Model_1/Control System/Attitude Controller/Velocity/PID Controller/Sum Fdbk'
 * '<S81>'  : 'Multirotor_Model_1/Control System/Attitude Controller/Velocity/PID Controller/Tracking Mode'
 * '<S82>'  : 'Multirotor_Model_1/Control System/Attitude Controller/Velocity/PID Controller/Tracking Mode Sum'
 * '<S83>'  : 'Multirotor_Model_1/Control System/Attitude Controller/Velocity/PID Controller/Tsamp - Integral'
 * '<S84>'  : 'Multirotor_Model_1/Control System/Attitude Controller/Velocity/PID Controller/Tsamp - Ngain'
 * '<S85>'  : 'Multirotor_Model_1/Control System/Attitude Controller/Velocity/PID Controller/postSat Signal'
 * '<S86>'  : 'Multirotor_Model_1/Control System/Attitude Controller/Velocity/PID Controller/preSat Signal'
 * '<S87>'  : 'Multirotor_Model_1/Control System/Attitude Controller/Velocity/PID Controller/Anti-windup/Passthrough'
 * '<S88>'  : 'Multirotor_Model_1/Control System/Attitude Controller/Velocity/PID Controller/D Gain/Internal Parameters'
 * '<S89>'  : 'Multirotor_Model_1/Control System/Attitude Controller/Velocity/PID Controller/Filter/Cont. Filter'
 * '<S90>'  : 'Multirotor_Model_1/Control System/Attitude Controller/Velocity/PID Controller/Filter ICs/Internal IC - Filter'
 * '<S91>'  : 'Multirotor_Model_1/Control System/Attitude Controller/Velocity/PID Controller/I Gain/Internal Parameters'
 * '<S92>'  : 'Multirotor_Model_1/Control System/Attitude Controller/Velocity/PID Controller/Ideal P Gain/Passthrough'
 * '<S93>'  : 'Multirotor_Model_1/Control System/Attitude Controller/Velocity/PID Controller/Ideal P Gain Fdbk/Disabled'
 * '<S94>'  : 'Multirotor_Model_1/Control System/Attitude Controller/Velocity/PID Controller/Integrator/Continuous'
 * '<S95>'  : 'Multirotor_Model_1/Control System/Attitude Controller/Velocity/PID Controller/Integrator ICs/Internal IC'
 * '<S96>'  : 'Multirotor_Model_1/Control System/Attitude Controller/Velocity/PID Controller/N Copy/Disabled'
 * '<S97>'  : 'Multirotor_Model_1/Control System/Attitude Controller/Velocity/PID Controller/N Gain/Internal Parameters'
 * '<S98>'  : 'Multirotor_Model_1/Control System/Attitude Controller/Velocity/PID Controller/P Copy/Disabled'
 * '<S99>'  : 'Multirotor_Model_1/Control System/Attitude Controller/Velocity/PID Controller/Parallel P Gain/Internal Parameters'
 * '<S100>' : 'Multirotor_Model_1/Control System/Attitude Controller/Velocity/PID Controller/Reset Signal/Disabled'
 * '<S101>' : 'Multirotor_Model_1/Control System/Attitude Controller/Velocity/PID Controller/Saturation/Enabled'
 * '<S102>' : 'Multirotor_Model_1/Control System/Attitude Controller/Velocity/PID Controller/Saturation Fdbk/Disabled'
 * '<S103>' : 'Multirotor_Model_1/Control System/Attitude Controller/Velocity/PID Controller/Sum/Sum_PID'
 * '<S104>' : 'Multirotor_Model_1/Control System/Attitude Controller/Velocity/PID Controller/Sum Fdbk/Disabled'
 * '<S105>' : 'Multirotor_Model_1/Control System/Attitude Controller/Velocity/PID Controller/Tracking Mode/Disabled'
 * '<S106>' : 'Multirotor_Model_1/Control System/Attitude Controller/Velocity/PID Controller/Tracking Mode Sum/Passthrough'
 * '<S107>' : 'Multirotor_Model_1/Control System/Attitude Controller/Velocity/PID Controller/Tsamp - Integral/Passthrough'
 * '<S108>' : 'Multirotor_Model_1/Control System/Attitude Controller/Velocity/PID Controller/Tsamp - Ngain/Passthrough'
 * '<S109>' : 'Multirotor_Model_1/Control System/Attitude Controller/Velocity/PID Controller/postSat Signal/Forward_Path'
 * '<S110>' : 'Multirotor_Model_1/Control System/Attitude Controller/Velocity/PID Controller/preSat Signal/Forward_Path'
 * '<S111>' : 'Multirotor_Model_1/Control System/Attitude Controller/Velocity/PID Controller1/Anti-windup'
 * '<S112>' : 'Multirotor_Model_1/Control System/Attitude Controller/Velocity/PID Controller1/D Gain'
 * '<S113>' : 'Multirotor_Model_1/Control System/Attitude Controller/Velocity/PID Controller1/Filter'
 * '<S114>' : 'Multirotor_Model_1/Control System/Attitude Controller/Velocity/PID Controller1/Filter ICs'
 * '<S115>' : 'Multirotor_Model_1/Control System/Attitude Controller/Velocity/PID Controller1/I Gain'
 * '<S116>' : 'Multirotor_Model_1/Control System/Attitude Controller/Velocity/PID Controller1/Ideal P Gain'
 * '<S117>' : 'Multirotor_Model_1/Control System/Attitude Controller/Velocity/PID Controller1/Ideal P Gain Fdbk'
 * '<S118>' : 'Multirotor_Model_1/Control System/Attitude Controller/Velocity/PID Controller1/Integrator'
 * '<S119>' : 'Multirotor_Model_1/Control System/Attitude Controller/Velocity/PID Controller1/Integrator ICs'
 * '<S120>' : 'Multirotor_Model_1/Control System/Attitude Controller/Velocity/PID Controller1/N Copy'
 * '<S121>' : 'Multirotor_Model_1/Control System/Attitude Controller/Velocity/PID Controller1/N Gain'
 * '<S122>' : 'Multirotor_Model_1/Control System/Attitude Controller/Velocity/PID Controller1/P Copy'
 * '<S123>' : 'Multirotor_Model_1/Control System/Attitude Controller/Velocity/PID Controller1/Parallel P Gain'
 * '<S124>' : 'Multirotor_Model_1/Control System/Attitude Controller/Velocity/PID Controller1/Reset Signal'
 * '<S125>' : 'Multirotor_Model_1/Control System/Attitude Controller/Velocity/PID Controller1/Saturation'
 * '<S126>' : 'Multirotor_Model_1/Control System/Attitude Controller/Velocity/PID Controller1/Saturation Fdbk'
 * '<S127>' : 'Multirotor_Model_1/Control System/Attitude Controller/Velocity/PID Controller1/Sum'
 * '<S128>' : 'Multirotor_Model_1/Control System/Attitude Controller/Velocity/PID Controller1/Sum Fdbk'
 * '<S129>' : 'Multirotor_Model_1/Control System/Attitude Controller/Velocity/PID Controller1/Tracking Mode'
 * '<S130>' : 'Multirotor_Model_1/Control System/Attitude Controller/Velocity/PID Controller1/Tracking Mode Sum'
 * '<S131>' : 'Multirotor_Model_1/Control System/Attitude Controller/Velocity/PID Controller1/Tsamp - Integral'
 * '<S132>' : 'Multirotor_Model_1/Control System/Attitude Controller/Velocity/PID Controller1/Tsamp - Ngain'
 * '<S133>' : 'Multirotor_Model_1/Control System/Attitude Controller/Velocity/PID Controller1/postSat Signal'
 * '<S134>' : 'Multirotor_Model_1/Control System/Attitude Controller/Velocity/PID Controller1/preSat Signal'
 * '<S135>' : 'Multirotor_Model_1/Control System/Attitude Controller/Velocity/PID Controller1/Anti-windup/Passthrough'
 * '<S136>' : 'Multirotor_Model_1/Control System/Attitude Controller/Velocity/PID Controller1/D Gain/Internal Parameters'
 * '<S137>' : 'Multirotor_Model_1/Control System/Attitude Controller/Velocity/PID Controller1/Filter/Cont. Filter'
 * '<S138>' : 'Multirotor_Model_1/Control System/Attitude Controller/Velocity/PID Controller1/Filter ICs/Internal IC - Filter'
 * '<S139>' : 'Multirotor_Model_1/Control System/Attitude Controller/Velocity/PID Controller1/I Gain/Internal Parameters'
 * '<S140>' : 'Multirotor_Model_1/Control System/Attitude Controller/Velocity/PID Controller1/Ideal P Gain/Passthrough'
 * '<S141>' : 'Multirotor_Model_1/Control System/Attitude Controller/Velocity/PID Controller1/Ideal P Gain Fdbk/Disabled'
 * '<S142>' : 'Multirotor_Model_1/Control System/Attitude Controller/Velocity/PID Controller1/Integrator/Continuous'
 * '<S143>' : 'Multirotor_Model_1/Control System/Attitude Controller/Velocity/PID Controller1/Integrator ICs/Internal IC'
 * '<S144>' : 'Multirotor_Model_1/Control System/Attitude Controller/Velocity/PID Controller1/N Copy/Disabled'
 * '<S145>' : 'Multirotor_Model_1/Control System/Attitude Controller/Velocity/PID Controller1/N Gain/Internal Parameters'
 * '<S146>' : 'Multirotor_Model_1/Control System/Attitude Controller/Velocity/PID Controller1/P Copy/Disabled'
 * '<S147>' : 'Multirotor_Model_1/Control System/Attitude Controller/Velocity/PID Controller1/Parallel P Gain/Internal Parameters'
 * '<S148>' : 'Multirotor_Model_1/Control System/Attitude Controller/Velocity/PID Controller1/Reset Signal/Disabled'
 * '<S149>' : 'Multirotor_Model_1/Control System/Attitude Controller/Velocity/PID Controller1/Saturation/Enabled'
 * '<S150>' : 'Multirotor_Model_1/Control System/Attitude Controller/Velocity/PID Controller1/Saturation Fdbk/Disabled'
 * '<S151>' : 'Multirotor_Model_1/Control System/Attitude Controller/Velocity/PID Controller1/Sum/Sum_PID'
 * '<S152>' : 'Multirotor_Model_1/Control System/Attitude Controller/Velocity/PID Controller1/Sum Fdbk/Disabled'
 * '<S153>' : 'Multirotor_Model_1/Control System/Attitude Controller/Velocity/PID Controller1/Tracking Mode/Disabled'
 * '<S154>' : 'Multirotor_Model_1/Control System/Attitude Controller/Velocity/PID Controller1/Tracking Mode Sum/Passthrough'
 * '<S155>' : 'Multirotor_Model_1/Control System/Attitude Controller/Velocity/PID Controller1/Tsamp - Integral/Passthrough'
 * '<S156>' : 'Multirotor_Model_1/Control System/Attitude Controller/Velocity/PID Controller1/Tsamp - Ngain/Passthrough'
 * '<S157>' : 'Multirotor_Model_1/Control System/Attitude Controller/Velocity/PID Controller1/postSat Signal/Forward_Path'
 * '<S158>' : 'Multirotor_Model_1/Control System/Attitude Controller/Velocity/PID Controller1/preSat Signal/Forward_Path'
 * '<S159>' : 'Multirotor_Model_1/Control System/Attitude Controller/moments/PID Controller'
 * '<S160>' : 'Multirotor_Model_1/Control System/Attitude Controller/moments/PID Controller1'
 * '<S161>' : 'Multirotor_Model_1/Control System/Attitude Controller/moments/PID Controller2'
 * '<S162>' : 'Multirotor_Model_1/Control System/Attitude Controller/moments/PID Controller/Anti-windup'
 * '<S163>' : 'Multirotor_Model_1/Control System/Attitude Controller/moments/PID Controller/D Gain'
 * '<S164>' : 'Multirotor_Model_1/Control System/Attitude Controller/moments/PID Controller/Filter'
 * '<S165>' : 'Multirotor_Model_1/Control System/Attitude Controller/moments/PID Controller/Filter ICs'
 * '<S166>' : 'Multirotor_Model_1/Control System/Attitude Controller/moments/PID Controller/I Gain'
 * '<S167>' : 'Multirotor_Model_1/Control System/Attitude Controller/moments/PID Controller/Ideal P Gain'
 * '<S168>' : 'Multirotor_Model_1/Control System/Attitude Controller/moments/PID Controller/Ideal P Gain Fdbk'
 * '<S169>' : 'Multirotor_Model_1/Control System/Attitude Controller/moments/PID Controller/Integrator'
 * '<S170>' : 'Multirotor_Model_1/Control System/Attitude Controller/moments/PID Controller/Integrator ICs'
 * '<S171>' : 'Multirotor_Model_1/Control System/Attitude Controller/moments/PID Controller/N Copy'
 * '<S172>' : 'Multirotor_Model_1/Control System/Attitude Controller/moments/PID Controller/N Gain'
 * '<S173>' : 'Multirotor_Model_1/Control System/Attitude Controller/moments/PID Controller/P Copy'
 * '<S174>' : 'Multirotor_Model_1/Control System/Attitude Controller/moments/PID Controller/Parallel P Gain'
 * '<S175>' : 'Multirotor_Model_1/Control System/Attitude Controller/moments/PID Controller/Reset Signal'
 * '<S176>' : 'Multirotor_Model_1/Control System/Attitude Controller/moments/PID Controller/Saturation'
 * '<S177>' : 'Multirotor_Model_1/Control System/Attitude Controller/moments/PID Controller/Saturation Fdbk'
 * '<S178>' : 'Multirotor_Model_1/Control System/Attitude Controller/moments/PID Controller/Sum'
 * '<S179>' : 'Multirotor_Model_1/Control System/Attitude Controller/moments/PID Controller/Sum Fdbk'
 * '<S180>' : 'Multirotor_Model_1/Control System/Attitude Controller/moments/PID Controller/Tracking Mode'
 * '<S181>' : 'Multirotor_Model_1/Control System/Attitude Controller/moments/PID Controller/Tracking Mode Sum'
 * '<S182>' : 'Multirotor_Model_1/Control System/Attitude Controller/moments/PID Controller/Tsamp - Integral'
 * '<S183>' : 'Multirotor_Model_1/Control System/Attitude Controller/moments/PID Controller/Tsamp - Ngain'
 * '<S184>' : 'Multirotor_Model_1/Control System/Attitude Controller/moments/PID Controller/postSat Signal'
 * '<S185>' : 'Multirotor_Model_1/Control System/Attitude Controller/moments/PID Controller/preSat Signal'
 * '<S186>' : 'Multirotor_Model_1/Control System/Attitude Controller/moments/PID Controller/Anti-windup/Passthrough'
 * '<S187>' : 'Multirotor_Model_1/Control System/Attitude Controller/moments/PID Controller/D Gain/Internal Parameters'
 * '<S188>' : 'Multirotor_Model_1/Control System/Attitude Controller/moments/PID Controller/Filter/Cont. Filter'
 * '<S189>' : 'Multirotor_Model_1/Control System/Attitude Controller/moments/PID Controller/Filter ICs/Internal IC - Filter'
 * '<S190>' : 'Multirotor_Model_1/Control System/Attitude Controller/moments/PID Controller/I Gain/Internal Parameters'
 * '<S191>' : 'Multirotor_Model_1/Control System/Attitude Controller/moments/PID Controller/Ideal P Gain/Passthrough'
 * '<S192>' : 'Multirotor_Model_1/Control System/Attitude Controller/moments/PID Controller/Ideal P Gain Fdbk/Disabled'
 * '<S193>' : 'Multirotor_Model_1/Control System/Attitude Controller/moments/PID Controller/Integrator/Continuous'
 * '<S194>' : 'Multirotor_Model_1/Control System/Attitude Controller/moments/PID Controller/Integrator ICs/Internal IC'
 * '<S195>' : 'Multirotor_Model_1/Control System/Attitude Controller/moments/PID Controller/N Copy/Disabled'
 * '<S196>' : 'Multirotor_Model_1/Control System/Attitude Controller/moments/PID Controller/N Gain/Internal Parameters'
 * '<S197>' : 'Multirotor_Model_1/Control System/Attitude Controller/moments/PID Controller/P Copy/Disabled'
 * '<S198>' : 'Multirotor_Model_1/Control System/Attitude Controller/moments/PID Controller/Parallel P Gain/Internal Parameters'
 * '<S199>' : 'Multirotor_Model_1/Control System/Attitude Controller/moments/PID Controller/Reset Signal/Disabled'
 * '<S200>' : 'Multirotor_Model_1/Control System/Attitude Controller/moments/PID Controller/Saturation/Enabled'
 * '<S201>' : 'Multirotor_Model_1/Control System/Attitude Controller/moments/PID Controller/Saturation Fdbk/Disabled'
 * '<S202>' : 'Multirotor_Model_1/Control System/Attitude Controller/moments/PID Controller/Sum/Sum_PID'
 * '<S203>' : 'Multirotor_Model_1/Control System/Attitude Controller/moments/PID Controller/Sum Fdbk/Disabled'
 * '<S204>' : 'Multirotor_Model_1/Control System/Attitude Controller/moments/PID Controller/Tracking Mode/Disabled'
 * '<S205>' : 'Multirotor_Model_1/Control System/Attitude Controller/moments/PID Controller/Tracking Mode Sum/Passthrough'
 * '<S206>' : 'Multirotor_Model_1/Control System/Attitude Controller/moments/PID Controller/Tsamp - Integral/Passthrough'
 * '<S207>' : 'Multirotor_Model_1/Control System/Attitude Controller/moments/PID Controller/Tsamp - Ngain/Passthrough'
 * '<S208>' : 'Multirotor_Model_1/Control System/Attitude Controller/moments/PID Controller/postSat Signal/Forward_Path'
 * '<S209>' : 'Multirotor_Model_1/Control System/Attitude Controller/moments/PID Controller/preSat Signal/Forward_Path'
 * '<S210>' : 'Multirotor_Model_1/Control System/Attitude Controller/moments/PID Controller1/Anti-windup'
 * '<S211>' : 'Multirotor_Model_1/Control System/Attitude Controller/moments/PID Controller1/D Gain'
 * '<S212>' : 'Multirotor_Model_1/Control System/Attitude Controller/moments/PID Controller1/Filter'
 * '<S213>' : 'Multirotor_Model_1/Control System/Attitude Controller/moments/PID Controller1/Filter ICs'
 * '<S214>' : 'Multirotor_Model_1/Control System/Attitude Controller/moments/PID Controller1/I Gain'
 * '<S215>' : 'Multirotor_Model_1/Control System/Attitude Controller/moments/PID Controller1/Ideal P Gain'
 * '<S216>' : 'Multirotor_Model_1/Control System/Attitude Controller/moments/PID Controller1/Ideal P Gain Fdbk'
 * '<S217>' : 'Multirotor_Model_1/Control System/Attitude Controller/moments/PID Controller1/Integrator'
 * '<S218>' : 'Multirotor_Model_1/Control System/Attitude Controller/moments/PID Controller1/Integrator ICs'
 * '<S219>' : 'Multirotor_Model_1/Control System/Attitude Controller/moments/PID Controller1/N Copy'
 * '<S220>' : 'Multirotor_Model_1/Control System/Attitude Controller/moments/PID Controller1/N Gain'
 * '<S221>' : 'Multirotor_Model_1/Control System/Attitude Controller/moments/PID Controller1/P Copy'
 * '<S222>' : 'Multirotor_Model_1/Control System/Attitude Controller/moments/PID Controller1/Parallel P Gain'
 * '<S223>' : 'Multirotor_Model_1/Control System/Attitude Controller/moments/PID Controller1/Reset Signal'
 * '<S224>' : 'Multirotor_Model_1/Control System/Attitude Controller/moments/PID Controller1/Saturation'
 * '<S225>' : 'Multirotor_Model_1/Control System/Attitude Controller/moments/PID Controller1/Saturation Fdbk'
 * '<S226>' : 'Multirotor_Model_1/Control System/Attitude Controller/moments/PID Controller1/Sum'
 * '<S227>' : 'Multirotor_Model_1/Control System/Attitude Controller/moments/PID Controller1/Sum Fdbk'
 * '<S228>' : 'Multirotor_Model_1/Control System/Attitude Controller/moments/PID Controller1/Tracking Mode'
 * '<S229>' : 'Multirotor_Model_1/Control System/Attitude Controller/moments/PID Controller1/Tracking Mode Sum'
 * '<S230>' : 'Multirotor_Model_1/Control System/Attitude Controller/moments/PID Controller1/Tsamp - Integral'
 * '<S231>' : 'Multirotor_Model_1/Control System/Attitude Controller/moments/PID Controller1/Tsamp - Ngain'
 * '<S232>' : 'Multirotor_Model_1/Control System/Attitude Controller/moments/PID Controller1/postSat Signal'
 * '<S233>' : 'Multirotor_Model_1/Control System/Attitude Controller/moments/PID Controller1/preSat Signal'
 * '<S234>' : 'Multirotor_Model_1/Control System/Attitude Controller/moments/PID Controller1/Anti-windup/Passthrough'
 * '<S235>' : 'Multirotor_Model_1/Control System/Attitude Controller/moments/PID Controller1/D Gain/Internal Parameters'
 * '<S236>' : 'Multirotor_Model_1/Control System/Attitude Controller/moments/PID Controller1/Filter/Cont. Filter'
 * '<S237>' : 'Multirotor_Model_1/Control System/Attitude Controller/moments/PID Controller1/Filter ICs/Internal IC - Filter'
 * '<S238>' : 'Multirotor_Model_1/Control System/Attitude Controller/moments/PID Controller1/I Gain/Internal Parameters'
 * '<S239>' : 'Multirotor_Model_1/Control System/Attitude Controller/moments/PID Controller1/Ideal P Gain/Passthrough'
 * '<S240>' : 'Multirotor_Model_1/Control System/Attitude Controller/moments/PID Controller1/Ideal P Gain Fdbk/Disabled'
 * '<S241>' : 'Multirotor_Model_1/Control System/Attitude Controller/moments/PID Controller1/Integrator/Continuous'
 * '<S242>' : 'Multirotor_Model_1/Control System/Attitude Controller/moments/PID Controller1/Integrator ICs/Internal IC'
 * '<S243>' : 'Multirotor_Model_1/Control System/Attitude Controller/moments/PID Controller1/N Copy/Disabled'
 * '<S244>' : 'Multirotor_Model_1/Control System/Attitude Controller/moments/PID Controller1/N Gain/Internal Parameters'
 * '<S245>' : 'Multirotor_Model_1/Control System/Attitude Controller/moments/PID Controller1/P Copy/Disabled'
 * '<S246>' : 'Multirotor_Model_1/Control System/Attitude Controller/moments/PID Controller1/Parallel P Gain/Internal Parameters'
 * '<S247>' : 'Multirotor_Model_1/Control System/Attitude Controller/moments/PID Controller1/Reset Signal/Disabled'
 * '<S248>' : 'Multirotor_Model_1/Control System/Attitude Controller/moments/PID Controller1/Saturation/Enabled'
 * '<S249>' : 'Multirotor_Model_1/Control System/Attitude Controller/moments/PID Controller1/Saturation Fdbk/Disabled'
 * '<S250>' : 'Multirotor_Model_1/Control System/Attitude Controller/moments/PID Controller1/Sum/Sum_PID'
 * '<S251>' : 'Multirotor_Model_1/Control System/Attitude Controller/moments/PID Controller1/Sum Fdbk/Disabled'
 * '<S252>' : 'Multirotor_Model_1/Control System/Attitude Controller/moments/PID Controller1/Tracking Mode/Disabled'
 * '<S253>' : 'Multirotor_Model_1/Control System/Attitude Controller/moments/PID Controller1/Tracking Mode Sum/Passthrough'
 * '<S254>' : 'Multirotor_Model_1/Control System/Attitude Controller/moments/PID Controller1/Tsamp - Integral/Passthrough'
 * '<S255>' : 'Multirotor_Model_1/Control System/Attitude Controller/moments/PID Controller1/Tsamp - Ngain/Passthrough'
 * '<S256>' : 'Multirotor_Model_1/Control System/Attitude Controller/moments/PID Controller1/postSat Signal/Forward_Path'
 * '<S257>' : 'Multirotor_Model_1/Control System/Attitude Controller/moments/PID Controller1/preSat Signal/Forward_Path'
 * '<S258>' : 'Multirotor_Model_1/Control System/Attitude Controller/moments/PID Controller2/Anti-windup'
 * '<S259>' : 'Multirotor_Model_1/Control System/Attitude Controller/moments/PID Controller2/D Gain'
 * '<S260>' : 'Multirotor_Model_1/Control System/Attitude Controller/moments/PID Controller2/Filter'
 * '<S261>' : 'Multirotor_Model_1/Control System/Attitude Controller/moments/PID Controller2/Filter ICs'
 * '<S262>' : 'Multirotor_Model_1/Control System/Attitude Controller/moments/PID Controller2/I Gain'
 * '<S263>' : 'Multirotor_Model_1/Control System/Attitude Controller/moments/PID Controller2/Ideal P Gain'
 * '<S264>' : 'Multirotor_Model_1/Control System/Attitude Controller/moments/PID Controller2/Ideal P Gain Fdbk'
 * '<S265>' : 'Multirotor_Model_1/Control System/Attitude Controller/moments/PID Controller2/Integrator'
 * '<S266>' : 'Multirotor_Model_1/Control System/Attitude Controller/moments/PID Controller2/Integrator ICs'
 * '<S267>' : 'Multirotor_Model_1/Control System/Attitude Controller/moments/PID Controller2/N Copy'
 * '<S268>' : 'Multirotor_Model_1/Control System/Attitude Controller/moments/PID Controller2/N Gain'
 * '<S269>' : 'Multirotor_Model_1/Control System/Attitude Controller/moments/PID Controller2/P Copy'
 * '<S270>' : 'Multirotor_Model_1/Control System/Attitude Controller/moments/PID Controller2/Parallel P Gain'
 * '<S271>' : 'Multirotor_Model_1/Control System/Attitude Controller/moments/PID Controller2/Reset Signal'
 * '<S272>' : 'Multirotor_Model_1/Control System/Attitude Controller/moments/PID Controller2/Saturation'
 * '<S273>' : 'Multirotor_Model_1/Control System/Attitude Controller/moments/PID Controller2/Saturation Fdbk'
 * '<S274>' : 'Multirotor_Model_1/Control System/Attitude Controller/moments/PID Controller2/Sum'
 * '<S275>' : 'Multirotor_Model_1/Control System/Attitude Controller/moments/PID Controller2/Sum Fdbk'
 * '<S276>' : 'Multirotor_Model_1/Control System/Attitude Controller/moments/PID Controller2/Tracking Mode'
 * '<S277>' : 'Multirotor_Model_1/Control System/Attitude Controller/moments/PID Controller2/Tracking Mode Sum'
 * '<S278>' : 'Multirotor_Model_1/Control System/Attitude Controller/moments/PID Controller2/Tsamp - Integral'
 * '<S279>' : 'Multirotor_Model_1/Control System/Attitude Controller/moments/PID Controller2/Tsamp - Ngain'
 * '<S280>' : 'Multirotor_Model_1/Control System/Attitude Controller/moments/PID Controller2/postSat Signal'
 * '<S281>' : 'Multirotor_Model_1/Control System/Attitude Controller/moments/PID Controller2/preSat Signal'
 * '<S282>' : 'Multirotor_Model_1/Control System/Attitude Controller/moments/PID Controller2/Anti-windup/Passthrough'
 * '<S283>' : 'Multirotor_Model_1/Control System/Attitude Controller/moments/PID Controller2/D Gain/Internal Parameters'
 * '<S284>' : 'Multirotor_Model_1/Control System/Attitude Controller/moments/PID Controller2/Filter/Cont. Filter'
 * '<S285>' : 'Multirotor_Model_1/Control System/Attitude Controller/moments/PID Controller2/Filter ICs/Internal IC - Filter'
 * '<S286>' : 'Multirotor_Model_1/Control System/Attitude Controller/moments/PID Controller2/I Gain/Internal Parameters'
 * '<S287>' : 'Multirotor_Model_1/Control System/Attitude Controller/moments/PID Controller2/Ideal P Gain/Passthrough'
 * '<S288>' : 'Multirotor_Model_1/Control System/Attitude Controller/moments/PID Controller2/Ideal P Gain Fdbk/Disabled'
 * '<S289>' : 'Multirotor_Model_1/Control System/Attitude Controller/moments/PID Controller2/Integrator/Continuous'
 * '<S290>' : 'Multirotor_Model_1/Control System/Attitude Controller/moments/PID Controller2/Integrator ICs/Internal IC'
 * '<S291>' : 'Multirotor_Model_1/Control System/Attitude Controller/moments/PID Controller2/N Copy/Disabled'
 * '<S292>' : 'Multirotor_Model_1/Control System/Attitude Controller/moments/PID Controller2/N Gain/Internal Parameters'
 * '<S293>' : 'Multirotor_Model_1/Control System/Attitude Controller/moments/PID Controller2/P Copy/Disabled'
 * '<S294>' : 'Multirotor_Model_1/Control System/Attitude Controller/moments/PID Controller2/Parallel P Gain/Internal Parameters'
 * '<S295>' : 'Multirotor_Model_1/Control System/Attitude Controller/moments/PID Controller2/Reset Signal/Disabled'
 * '<S296>' : 'Multirotor_Model_1/Control System/Attitude Controller/moments/PID Controller2/Saturation/Enabled'
 * '<S297>' : 'Multirotor_Model_1/Control System/Attitude Controller/moments/PID Controller2/Saturation Fdbk/Disabled'
 * '<S298>' : 'Multirotor_Model_1/Control System/Attitude Controller/moments/PID Controller2/Sum/Sum_PID'
 * '<S299>' : 'Multirotor_Model_1/Control System/Attitude Controller/moments/PID Controller2/Sum Fdbk/Disabled'
 * '<S300>' : 'Multirotor_Model_1/Control System/Attitude Controller/moments/PID Controller2/Tracking Mode/Disabled'
 * '<S301>' : 'Multirotor_Model_1/Control System/Attitude Controller/moments/PID Controller2/Tracking Mode Sum/Passthrough'
 * '<S302>' : 'Multirotor_Model_1/Control System/Attitude Controller/moments/PID Controller2/Tsamp - Integral/Passthrough'
 * '<S303>' : 'Multirotor_Model_1/Control System/Attitude Controller/moments/PID Controller2/Tsamp - Ngain/Passthrough'
 * '<S304>' : 'Multirotor_Model_1/Control System/Attitude Controller/moments/PID Controller2/postSat Signal/Forward_Path'
 * '<S305>' : 'Multirotor_Model_1/Control System/Attitude Controller/moments/PID Controller2/preSat Signal/Forward_Path'
 * '<S306>' : 'Multirotor_Model_1/Control System/Position Controller/MATLAB Function'
 * '<S307>' : 'Multirotor_Model_1/Control System/Position Controller/Position Controller X and Y'
 * '<S308>' : 'Multirotor_Model_1/Control System/Position Controller/Position Controller Z'
 * '<S309>' : 'Multirotor_Model_1/Control System/Position Controller/Position Controller X and Y/PID Controller'
 * '<S310>' : 'Multirotor_Model_1/Control System/Position Controller/Position Controller X and Y/PID Controller1'
 * '<S311>' : 'Multirotor_Model_1/Control System/Position Controller/Position Controller X and Y/PID Controller2'
 * '<S312>' : 'Multirotor_Model_1/Control System/Position Controller/Position Controller X and Y/PID Controller/Anti-windup'
 * '<S313>' : 'Multirotor_Model_1/Control System/Position Controller/Position Controller X and Y/PID Controller/D Gain'
 * '<S314>' : 'Multirotor_Model_1/Control System/Position Controller/Position Controller X and Y/PID Controller/Filter'
 * '<S315>' : 'Multirotor_Model_1/Control System/Position Controller/Position Controller X and Y/PID Controller/Filter ICs'
 * '<S316>' : 'Multirotor_Model_1/Control System/Position Controller/Position Controller X and Y/PID Controller/I Gain'
 * '<S317>' : 'Multirotor_Model_1/Control System/Position Controller/Position Controller X and Y/PID Controller/Ideal P Gain'
 * '<S318>' : 'Multirotor_Model_1/Control System/Position Controller/Position Controller X and Y/PID Controller/Ideal P Gain Fdbk'
 * '<S319>' : 'Multirotor_Model_1/Control System/Position Controller/Position Controller X and Y/PID Controller/Integrator'
 * '<S320>' : 'Multirotor_Model_1/Control System/Position Controller/Position Controller X and Y/PID Controller/Integrator ICs'
 * '<S321>' : 'Multirotor_Model_1/Control System/Position Controller/Position Controller X and Y/PID Controller/N Copy'
 * '<S322>' : 'Multirotor_Model_1/Control System/Position Controller/Position Controller X and Y/PID Controller/N Gain'
 * '<S323>' : 'Multirotor_Model_1/Control System/Position Controller/Position Controller X and Y/PID Controller/P Copy'
 * '<S324>' : 'Multirotor_Model_1/Control System/Position Controller/Position Controller X and Y/PID Controller/Parallel P Gain'
 * '<S325>' : 'Multirotor_Model_1/Control System/Position Controller/Position Controller X and Y/PID Controller/Reset Signal'
 * '<S326>' : 'Multirotor_Model_1/Control System/Position Controller/Position Controller X and Y/PID Controller/Saturation'
 * '<S327>' : 'Multirotor_Model_1/Control System/Position Controller/Position Controller X and Y/PID Controller/Saturation Fdbk'
 * '<S328>' : 'Multirotor_Model_1/Control System/Position Controller/Position Controller X and Y/PID Controller/Sum'
 * '<S329>' : 'Multirotor_Model_1/Control System/Position Controller/Position Controller X and Y/PID Controller/Sum Fdbk'
 * '<S330>' : 'Multirotor_Model_1/Control System/Position Controller/Position Controller X and Y/PID Controller/Tracking Mode'
 * '<S331>' : 'Multirotor_Model_1/Control System/Position Controller/Position Controller X and Y/PID Controller/Tracking Mode Sum'
 * '<S332>' : 'Multirotor_Model_1/Control System/Position Controller/Position Controller X and Y/PID Controller/Tsamp - Integral'
 * '<S333>' : 'Multirotor_Model_1/Control System/Position Controller/Position Controller X and Y/PID Controller/Tsamp - Ngain'
 * '<S334>' : 'Multirotor_Model_1/Control System/Position Controller/Position Controller X and Y/PID Controller/postSat Signal'
 * '<S335>' : 'Multirotor_Model_1/Control System/Position Controller/Position Controller X and Y/PID Controller/preSat Signal'
 * '<S336>' : 'Multirotor_Model_1/Control System/Position Controller/Position Controller X and Y/PID Controller/Anti-windup/Passthrough'
 * '<S337>' : 'Multirotor_Model_1/Control System/Position Controller/Position Controller X and Y/PID Controller/D Gain/Internal Parameters'
 * '<S338>' : 'Multirotor_Model_1/Control System/Position Controller/Position Controller X and Y/PID Controller/Filter/Cont. Filter'
 * '<S339>' : 'Multirotor_Model_1/Control System/Position Controller/Position Controller X and Y/PID Controller/Filter ICs/Internal IC - Filter'
 * '<S340>' : 'Multirotor_Model_1/Control System/Position Controller/Position Controller X and Y/PID Controller/I Gain/Internal Parameters'
 * '<S341>' : 'Multirotor_Model_1/Control System/Position Controller/Position Controller X and Y/PID Controller/Ideal P Gain/Passthrough'
 * '<S342>' : 'Multirotor_Model_1/Control System/Position Controller/Position Controller X and Y/PID Controller/Ideal P Gain Fdbk/Disabled'
 * '<S343>' : 'Multirotor_Model_1/Control System/Position Controller/Position Controller X and Y/PID Controller/Integrator/Continuous'
 * '<S344>' : 'Multirotor_Model_1/Control System/Position Controller/Position Controller X and Y/PID Controller/Integrator ICs/Internal IC'
 * '<S345>' : 'Multirotor_Model_1/Control System/Position Controller/Position Controller X and Y/PID Controller/N Copy/Disabled'
 * '<S346>' : 'Multirotor_Model_1/Control System/Position Controller/Position Controller X and Y/PID Controller/N Gain/Internal Parameters'
 * '<S347>' : 'Multirotor_Model_1/Control System/Position Controller/Position Controller X and Y/PID Controller/P Copy/Disabled'
 * '<S348>' : 'Multirotor_Model_1/Control System/Position Controller/Position Controller X and Y/PID Controller/Parallel P Gain/Internal Parameters'
 * '<S349>' : 'Multirotor_Model_1/Control System/Position Controller/Position Controller X and Y/PID Controller/Reset Signal/Disabled'
 * '<S350>' : 'Multirotor_Model_1/Control System/Position Controller/Position Controller X and Y/PID Controller/Saturation/Enabled'
 * '<S351>' : 'Multirotor_Model_1/Control System/Position Controller/Position Controller X and Y/PID Controller/Saturation Fdbk/Disabled'
 * '<S352>' : 'Multirotor_Model_1/Control System/Position Controller/Position Controller X and Y/PID Controller/Sum/Sum_PID'
 * '<S353>' : 'Multirotor_Model_1/Control System/Position Controller/Position Controller X and Y/PID Controller/Sum Fdbk/Disabled'
 * '<S354>' : 'Multirotor_Model_1/Control System/Position Controller/Position Controller X and Y/PID Controller/Tracking Mode/Disabled'
 * '<S355>' : 'Multirotor_Model_1/Control System/Position Controller/Position Controller X and Y/PID Controller/Tracking Mode Sum/Passthrough'
 * '<S356>' : 'Multirotor_Model_1/Control System/Position Controller/Position Controller X and Y/PID Controller/Tsamp - Integral/Passthrough'
 * '<S357>' : 'Multirotor_Model_1/Control System/Position Controller/Position Controller X and Y/PID Controller/Tsamp - Ngain/Passthrough'
 * '<S358>' : 'Multirotor_Model_1/Control System/Position Controller/Position Controller X and Y/PID Controller/postSat Signal/Forward_Path'
 * '<S359>' : 'Multirotor_Model_1/Control System/Position Controller/Position Controller X and Y/PID Controller/preSat Signal/Forward_Path'
 * '<S360>' : 'Multirotor_Model_1/Control System/Position Controller/Position Controller X and Y/PID Controller1/Anti-windup'
 * '<S361>' : 'Multirotor_Model_1/Control System/Position Controller/Position Controller X and Y/PID Controller1/D Gain'
 * '<S362>' : 'Multirotor_Model_1/Control System/Position Controller/Position Controller X and Y/PID Controller1/Filter'
 * '<S363>' : 'Multirotor_Model_1/Control System/Position Controller/Position Controller X and Y/PID Controller1/Filter ICs'
 * '<S364>' : 'Multirotor_Model_1/Control System/Position Controller/Position Controller X and Y/PID Controller1/I Gain'
 * '<S365>' : 'Multirotor_Model_1/Control System/Position Controller/Position Controller X and Y/PID Controller1/Ideal P Gain'
 * '<S366>' : 'Multirotor_Model_1/Control System/Position Controller/Position Controller X and Y/PID Controller1/Ideal P Gain Fdbk'
 * '<S367>' : 'Multirotor_Model_1/Control System/Position Controller/Position Controller X and Y/PID Controller1/Integrator'
 * '<S368>' : 'Multirotor_Model_1/Control System/Position Controller/Position Controller X and Y/PID Controller1/Integrator ICs'
 * '<S369>' : 'Multirotor_Model_1/Control System/Position Controller/Position Controller X and Y/PID Controller1/N Copy'
 * '<S370>' : 'Multirotor_Model_1/Control System/Position Controller/Position Controller X and Y/PID Controller1/N Gain'
 * '<S371>' : 'Multirotor_Model_1/Control System/Position Controller/Position Controller X and Y/PID Controller1/P Copy'
 * '<S372>' : 'Multirotor_Model_1/Control System/Position Controller/Position Controller X and Y/PID Controller1/Parallel P Gain'
 * '<S373>' : 'Multirotor_Model_1/Control System/Position Controller/Position Controller X and Y/PID Controller1/Reset Signal'
 * '<S374>' : 'Multirotor_Model_1/Control System/Position Controller/Position Controller X and Y/PID Controller1/Saturation'
 * '<S375>' : 'Multirotor_Model_1/Control System/Position Controller/Position Controller X and Y/PID Controller1/Saturation Fdbk'
 * '<S376>' : 'Multirotor_Model_1/Control System/Position Controller/Position Controller X and Y/PID Controller1/Sum'
 * '<S377>' : 'Multirotor_Model_1/Control System/Position Controller/Position Controller X and Y/PID Controller1/Sum Fdbk'
 * '<S378>' : 'Multirotor_Model_1/Control System/Position Controller/Position Controller X and Y/PID Controller1/Tracking Mode'
 * '<S379>' : 'Multirotor_Model_1/Control System/Position Controller/Position Controller X and Y/PID Controller1/Tracking Mode Sum'
 * '<S380>' : 'Multirotor_Model_1/Control System/Position Controller/Position Controller X and Y/PID Controller1/Tsamp - Integral'
 * '<S381>' : 'Multirotor_Model_1/Control System/Position Controller/Position Controller X and Y/PID Controller1/Tsamp - Ngain'
 * '<S382>' : 'Multirotor_Model_1/Control System/Position Controller/Position Controller X and Y/PID Controller1/postSat Signal'
 * '<S383>' : 'Multirotor_Model_1/Control System/Position Controller/Position Controller X and Y/PID Controller1/preSat Signal'
 * '<S384>' : 'Multirotor_Model_1/Control System/Position Controller/Position Controller X and Y/PID Controller1/Anti-windup/Passthrough'
 * '<S385>' : 'Multirotor_Model_1/Control System/Position Controller/Position Controller X and Y/PID Controller1/D Gain/Internal Parameters'
 * '<S386>' : 'Multirotor_Model_1/Control System/Position Controller/Position Controller X and Y/PID Controller1/Filter/Cont. Filter'
 * '<S387>' : 'Multirotor_Model_1/Control System/Position Controller/Position Controller X and Y/PID Controller1/Filter ICs/Internal IC - Filter'
 * '<S388>' : 'Multirotor_Model_1/Control System/Position Controller/Position Controller X and Y/PID Controller1/I Gain/Internal Parameters'
 * '<S389>' : 'Multirotor_Model_1/Control System/Position Controller/Position Controller X and Y/PID Controller1/Ideal P Gain/Passthrough'
 * '<S390>' : 'Multirotor_Model_1/Control System/Position Controller/Position Controller X and Y/PID Controller1/Ideal P Gain Fdbk/Disabled'
 * '<S391>' : 'Multirotor_Model_1/Control System/Position Controller/Position Controller X and Y/PID Controller1/Integrator/Continuous'
 * '<S392>' : 'Multirotor_Model_1/Control System/Position Controller/Position Controller X and Y/PID Controller1/Integrator ICs/Internal IC'
 * '<S393>' : 'Multirotor_Model_1/Control System/Position Controller/Position Controller X and Y/PID Controller1/N Copy/Disabled'
 * '<S394>' : 'Multirotor_Model_1/Control System/Position Controller/Position Controller X and Y/PID Controller1/N Gain/Internal Parameters'
 * '<S395>' : 'Multirotor_Model_1/Control System/Position Controller/Position Controller X and Y/PID Controller1/P Copy/Disabled'
 * '<S396>' : 'Multirotor_Model_1/Control System/Position Controller/Position Controller X and Y/PID Controller1/Parallel P Gain/Internal Parameters'
 * '<S397>' : 'Multirotor_Model_1/Control System/Position Controller/Position Controller X and Y/PID Controller1/Reset Signal/Disabled'
 * '<S398>' : 'Multirotor_Model_1/Control System/Position Controller/Position Controller X and Y/PID Controller1/Saturation/Enabled'
 * '<S399>' : 'Multirotor_Model_1/Control System/Position Controller/Position Controller X and Y/PID Controller1/Saturation Fdbk/Disabled'
 * '<S400>' : 'Multirotor_Model_1/Control System/Position Controller/Position Controller X and Y/PID Controller1/Sum/Sum_PID'
 * '<S401>' : 'Multirotor_Model_1/Control System/Position Controller/Position Controller X and Y/PID Controller1/Sum Fdbk/Disabled'
 * '<S402>' : 'Multirotor_Model_1/Control System/Position Controller/Position Controller X and Y/PID Controller1/Tracking Mode/Disabled'
 * '<S403>' : 'Multirotor_Model_1/Control System/Position Controller/Position Controller X and Y/PID Controller1/Tracking Mode Sum/Passthrough'
 * '<S404>' : 'Multirotor_Model_1/Control System/Position Controller/Position Controller X and Y/PID Controller1/Tsamp - Integral/Passthrough'
 * '<S405>' : 'Multirotor_Model_1/Control System/Position Controller/Position Controller X and Y/PID Controller1/Tsamp - Ngain/Passthrough'
 * '<S406>' : 'Multirotor_Model_1/Control System/Position Controller/Position Controller X and Y/PID Controller1/postSat Signal/Forward_Path'
 * '<S407>' : 'Multirotor_Model_1/Control System/Position Controller/Position Controller X and Y/PID Controller1/preSat Signal/Forward_Path'
 * '<S408>' : 'Multirotor_Model_1/Control System/Position Controller/Position Controller X and Y/PID Controller2/Anti-windup'
 * '<S409>' : 'Multirotor_Model_1/Control System/Position Controller/Position Controller X and Y/PID Controller2/D Gain'
 * '<S410>' : 'Multirotor_Model_1/Control System/Position Controller/Position Controller X and Y/PID Controller2/Filter'
 * '<S411>' : 'Multirotor_Model_1/Control System/Position Controller/Position Controller X and Y/PID Controller2/Filter ICs'
 * '<S412>' : 'Multirotor_Model_1/Control System/Position Controller/Position Controller X and Y/PID Controller2/I Gain'
 * '<S413>' : 'Multirotor_Model_1/Control System/Position Controller/Position Controller X and Y/PID Controller2/Ideal P Gain'
 * '<S414>' : 'Multirotor_Model_1/Control System/Position Controller/Position Controller X and Y/PID Controller2/Ideal P Gain Fdbk'
 * '<S415>' : 'Multirotor_Model_1/Control System/Position Controller/Position Controller X and Y/PID Controller2/Integrator'
 * '<S416>' : 'Multirotor_Model_1/Control System/Position Controller/Position Controller X and Y/PID Controller2/Integrator ICs'
 * '<S417>' : 'Multirotor_Model_1/Control System/Position Controller/Position Controller X and Y/PID Controller2/N Copy'
 * '<S418>' : 'Multirotor_Model_1/Control System/Position Controller/Position Controller X and Y/PID Controller2/N Gain'
 * '<S419>' : 'Multirotor_Model_1/Control System/Position Controller/Position Controller X and Y/PID Controller2/P Copy'
 * '<S420>' : 'Multirotor_Model_1/Control System/Position Controller/Position Controller X and Y/PID Controller2/Parallel P Gain'
 * '<S421>' : 'Multirotor_Model_1/Control System/Position Controller/Position Controller X and Y/PID Controller2/Reset Signal'
 * '<S422>' : 'Multirotor_Model_1/Control System/Position Controller/Position Controller X and Y/PID Controller2/Saturation'
 * '<S423>' : 'Multirotor_Model_1/Control System/Position Controller/Position Controller X and Y/PID Controller2/Saturation Fdbk'
 * '<S424>' : 'Multirotor_Model_1/Control System/Position Controller/Position Controller X and Y/PID Controller2/Sum'
 * '<S425>' : 'Multirotor_Model_1/Control System/Position Controller/Position Controller X and Y/PID Controller2/Sum Fdbk'
 * '<S426>' : 'Multirotor_Model_1/Control System/Position Controller/Position Controller X and Y/PID Controller2/Tracking Mode'
 * '<S427>' : 'Multirotor_Model_1/Control System/Position Controller/Position Controller X and Y/PID Controller2/Tracking Mode Sum'
 * '<S428>' : 'Multirotor_Model_1/Control System/Position Controller/Position Controller X and Y/PID Controller2/Tsamp - Integral'
 * '<S429>' : 'Multirotor_Model_1/Control System/Position Controller/Position Controller X and Y/PID Controller2/Tsamp - Ngain'
 * '<S430>' : 'Multirotor_Model_1/Control System/Position Controller/Position Controller X and Y/PID Controller2/postSat Signal'
 * '<S431>' : 'Multirotor_Model_1/Control System/Position Controller/Position Controller X and Y/PID Controller2/preSat Signal'
 * '<S432>' : 'Multirotor_Model_1/Control System/Position Controller/Position Controller X and Y/PID Controller2/Anti-windup/Passthrough'
 * '<S433>' : 'Multirotor_Model_1/Control System/Position Controller/Position Controller X and Y/PID Controller2/D Gain/Internal Parameters'
 * '<S434>' : 'Multirotor_Model_1/Control System/Position Controller/Position Controller X and Y/PID Controller2/Filter/Cont. Filter'
 * '<S435>' : 'Multirotor_Model_1/Control System/Position Controller/Position Controller X and Y/PID Controller2/Filter ICs/Internal IC - Filter'
 * '<S436>' : 'Multirotor_Model_1/Control System/Position Controller/Position Controller X and Y/PID Controller2/I Gain/Internal Parameters'
 * '<S437>' : 'Multirotor_Model_1/Control System/Position Controller/Position Controller X and Y/PID Controller2/Ideal P Gain/Passthrough'
 * '<S438>' : 'Multirotor_Model_1/Control System/Position Controller/Position Controller X and Y/PID Controller2/Ideal P Gain Fdbk/Disabled'
 * '<S439>' : 'Multirotor_Model_1/Control System/Position Controller/Position Controller X and Y/PID Controller2/Integrator/Continuous'
 * '<S440>' : 'Multirotor_Model_1/Control System/Position Controller/Position Controller X and Y/PID Controller2/Integrator ICs/Internal IC'
 * '<S441>' : 'Multirotor_Model_1/Control System/Position Controller/Position Controller X and Y/PID Controller2/N Copy/Disabled'
 * '<S442>' : 'Multirotor_Model_1/Control System/Position Controller/Position Controller X and Y/PID Controller2/N Gain/Internal Parameters'
 * '<S443>' : 'Multirotor_Model_1/Control System/Position Controller/Position Controller X and Y/PID Controller2/P Copy/Disabled'
 * '<S444>' : 'Multirotor_Model_1/Control System/Position Controller/Position Controller X and Y/PID Controller2/Parallel P Gain/Internal Parameters'
 * '<S445>' : 'Multirotor_Model_1/Control System/Position Controller/Position Controller X and Y/PID Controller2/Reset Signal/Disabled'
 * '<S446>' : 'Multirotor_Model_1/Control System/Position Controller/Position Controller X and Y/PID Controller2/Saturation/Enabled'
 * '<S447>' : 'Multirotor_Model_1/Control System/Position Controller/Position Controller X and Y/PID Controller2/Saturation Fdbk/Disabled'
 * '<S448>' : 'Multirotor_Model_1/Control System/Position Controller/Position Controller X and Y/PID Controller2/Sum/Sum_PID'
 * '<S449>' : 'Multirotor_Model_1/Control System/Position Controller/Position Controller X and Y/PID Controller2/Sum Fdbk/Disabled'
 * '<S450>' : 'Multirotor_Model_1/Control System/Position Controller/Position Controller X and Y/PID Controller2/Tracking Mode/Disabled'
 * '<S451>' : 'Multirotor_Model_1/Control System/Position Controller/Position Controller X and Y/PID Controller2/Tracking Mode Sum/Passthrough'
 * '<S452>' : 'Multirotor_Model_1/Control System/Position Controller/Position Controller X and Y/PID Controller2/Tsamp - Integral/Passthrough'
 * '<S453>' : 'Multirotor_Model_1/Control System/Position Controller/Position Controller X and Y/PID Controller2/Tsamp - Ngain/Passthrough'
 * '<S454>' : 'Multirotor_Model_1/Control System/Position Controller/Position Controller X and Y/PID Controller2/postSat Signal/Forward_Path'
 * '<S455>' : 'Multirotor_Model_1/Control System/Position Controller/Position Controller X and Y/PID Controller2/preSat Signal/Forward_Path'
 * '<S456>' : 'Multirotor_Model_1/Control System/Position Controller/Position Controller Z/PID Controller'
 * '<S457>' : 'Multirotor_Model_1/Control System/Position Controller/Position Controller Z/PID Controller/Anti-windup'
 * '<S458>' : 'Multirotor_Model_1/Control System/Position Controller/Position Controller Z/PID Controller/D Gain'
 * '<S459>' : 'Multirotor_Model_1/Control System/Position Controller/Position Controller Z/PID Controller/Filter'
 * '<S460>' : 'Multirotor_Model_1/Control System/Position Controller/Position Controller Z/PID Controller/Filter ICs'
 * '<S461>' : 'Multirotor_Model_1/Control System/Position Controller/Position Controller Z/PID Controller/I Gain'
 * '<S462>' : 'Multirotor_Model_1/Control System/Position Controller/Position Controller Z/PID Controller/Ideal P Gain'
 * '<S463>' : 'Multirotor_Model_1/Control System/Position Controller/Position Controller Z/PID Controller/Ideal P Gain Fdbk'
 * '<S464>' : 'Multirotor_Model_1/Control System/Position Controller/Position Controller Z/PID Controller/Integrator'
 * '<S465>' : 'Multirotor_Model_1/Control System/Position Controller/Position Controller Z/PID Controller/Integrator ICs'
 * '<S466>' : 'Multirotor_Model_1/Control System/Position Controller/Position Controller Z/PID Controller/N Copy'
 * '<S467>' : 'Multirotor_Model_1/Control System/Position Controller/Position Controller Z/PID Controller/N Gain'
 * '<S468>' : 'Multirotor_Model_1/Control System/Position Controller/Position Controller Z/PID Controller/P Copy'
 * '<S469>' : 'Multirotor_Model_1/Control System/Position Controller/Position Controller Z/PID Controller/Parallel P Gain'
 * '<S470>' : 'Multirotor_Model_1/Control System/Position Controller/Position Controller Z/PID Controller/Reset Signal'
 * '<S471>' : 'Multirotor_Model_1/Control System/Position Controller/Position Controller Z/PID Controller/Saturation'
 * '<S472>' : 'Multirotor_Model_1/Control System/Position Controller/Position Controller Z/PID Controller/Saturation Fdbk'
 * '<S473>' : 'Multirotor_Model_1/Control System/Position Controller/Position Controller Z/PID Controller/Sum'
 * '<S474>' : 'Multirotor_Model_1/Control System/Position Controller/Position Controller Z/PID Controller/Sum Fdbk'
 * '<S475>' : 'Multirotor_Model_1/Control System/Position Controller/Position Controller Z/PID Controller/Tracking Mode'
 * '<S476>' : 'Multirotor_Model_1/Control System/Position Controller/Position Controller Z/PID Controller/Tracking Mode Sum'
 * '<S477>' : 'Multirotor_Model_1/Control System/Position Controller/Position Controller Z/PID Controller/Tsamp - Integral'
 * '<S478>' : 'Multirotor_Model_1/Control System/Position Controller/Position Controller Z/PID Controller/Tsamp - Ngain'
 * '<S479>' : 'Multirotor_Model_1/Control System/Position Controller/Position Controller Z/PID Controller/postSat Signal'
 * '<S480>' : 'Multirotor_Model_1/Control System/Position Controller/Position Controller Z/PID Controller/preSat Signal'
 * '<S481>' : 'Multirotor_Model_1/Control System/Position Controller/Position Controller Z/PID Controller/Anti-windup/Passthrough'
 * '<S482>' : 'Multirotor_Model_1/Control System/Position Controller/Position Controller Z/PID Controller/D Gain/Internal Parameters'
 * '<S483>' : 'Multirotor_Model_1/Control System/Position Controller/Position Controller Z/PID Controller/Filter/Cont. Filter'
 * '<S484>' : 'Multirotor_Model_1/Control System/Position Controller/Position Controller Z/PID Controller/Filter ICs/Internal IC - Filter'
 * '<S485>' : 'Multirotor_Model_1/Control System/Position Controller/Position Controller Z/PID Controller/I Gain/Internal Parameters'
 * '<S486>' : 'Multirotor_Model_1/Control System/Position Controller/Position Controller Z/PID Controller/Ideal P Gain/Passthrough'
 * '<S487>' : 'Multirotor_Model_1/Control System/Position Controller/Position Controller Z/PID Controller/Ideal P Gain Fdbk/Disabled'
 * '<S488>' : 'Multirotor_Model_1/Control System/Position Controller/Position Controller Z/PID Controller/Integrator/Continuous'
 * '<S489>' : 'Multirotor_Model_1/Control System/Position Controller/Position Controller Z/PID Controller/Integrator ICs/Internal IC'
 * '<S490>' : 'Multirotor_Model_1/Control System/Position Controller/Position Controller Z/PID Controller/N Copy/Disabled'
 * '<S491>' : 'Multirotor_Model_1/Control System/Position Controller/Position Controller Z/PID Controller/N Gain/Internal Parameters'
 * '<S492>' : 'Multirotor_Model_1/Control System/Position Controller/Position Controller Z/PID Controller/P Copy/Disabled'
 * '<S493>' : 'Multirotor_Model_1/Control System/Position Controller/Position Controller Z/PID Controller/Parallel P Gain/Internal Parameters'
 * '<S494>' : 'Multirotor_Model_1/Control System/Position Controller/Position Controller Z/PID Controller/Reset Signal/Disabled'
 * '<S495>' : 'Multirotor_Model_1/Control System/Position Controller/Position Controller Z/PID Controller/Saturation/Enabled'
 * '<S496>' : 'Multirotor_Model_1/Control System/Position Controller/Position Controller Z/PID Controller/Saturation Fdbk/Disabled'
 * '<S497>' : 'Multirotor_Model_1/Control System/Position Controller/Position Controller Z/PID Controller/Sum/Sum_PID'
 * '<S498>' : 'Multirotor_Model_1/Control System/Position Controller/Position Controller Z/PID Controller/Sum Fdbk/Disabled'
 * '<S499>' : 'Multirotor_Model_1/Control System/Position Controller/Position Controller Z/PID Controller/Tracking Mode/Disabled'
 * '<S500>' : 'Multirotor_Model_1/Control System/Position Controller/Position Controller Z/PID Controller/Tracking Mode Sum/Passthrough'
 * '<S501>' : 'Multirotor_Model_1/Control System/Position Controller/Position Controller Z/PID Controller/Tsamp - Integral/Passthrough'
 * '<S502>' : 'Multirotor_Model_1/Control System/Position Controller/Position Controller Z/PID Controller/Tsamp - Ngain/Passthrough'
 * '<S503>' : 'Multirotor_Model_1/Control System/Position Controller/Position Controller Z/PID Controller/postSat Signal/Forward_Path'
 * '<S504>' : 'Multirotor_Model_1/Control System/Position Controller/Position Controller Z/PID Controller/preSat Signal/Forward_Path'
 * '<S505>' : 'Multirotor_Model_1/Flight Dynamics/Rotational Dynamics'
 * '<S506>' : 'Multirotor_Model_1/Flight Dynamics/State_update'
 * '<S507>' : 'Multirotor_Model_1/Flight Dynamics/Transform1'
 * '<S508>' : 'Multirotor_Model_1/Flight Dynamics/Translational Dynamics'
 * '<S509>' : 'Multirotor_Model_1/Vehicle Performance/Fuselage Load'
 * '<S510>' : 'Multirotor_Model_1/Vehicle Performance/Total Rotor Load1'
 * '<S511>' : 'Multirotor_Model_1/Vehicle Performance/Weight'
 * '<S512>' : 'Multirotor_Model_1/Vehicle Performance/Wing Load'
 * '<S513>' : 'Multirotor_Model_1/Vehicle Performance/Fuselage Load/MATLAB Function'
 * '<S514>' : 'Multirotor_Model_1/Vehicle Performance/Total Rotor Load1/For Each Subsystem'
 * '<S515>' : 'Multirotor_Model_1/Vehicle Performance/Total Rotor Load1/MATLAB Function1'
 * '<S516>' : 'Multirotor_Model_1/Vehicle Performance/Total Rotor Load1/Subsystem'
 * '<S517>' : 'Multirotor_Model_1/Vehicle Performance/Total Rotor Load1/For Each Subsystem/Propulsor'
 * '<S518>' : 'Multirotor_Model_1/Vehicle Performance/Total Rotor Load1/For Each Subsystem/Propulsor/Aerodynamics'
 * '<S519>' : 'Multirotor_Model_1/Vehicle Performance/Total Rotor Load1/For Each Subsystem/Propulsor/Powertrain Architecture'
 * '<S520>' : 'Multirotor_Model_1/Vehicle Performance/Total Rotor Load1/For Each Subsystem/Propulsor/Shaft Propeller-Motor'
 * '<S521>' : 'Multirotor_Model_1/Vehicle Performance/Total Rotor Load1/For Each Subsystem/Propulsor/Aerodynamics/Rotor '
 * '<S522>' : 'Multirotor_Model_1/Vehicle Performance/Total Rotor Load1/For Each Subsystem/Propulsor/Aerodynamics/Rotor /MATLAB Function'
 * '<S523>' : 'Multirotor_Model_1/Vehicle Performance/Total Rotor Load1/For Each Subsystem/Propulsor/Powertrain Architecture/Battery'
 * '<S524>' : 'Multirotor_Model_1/Vehicle Performance/Total Rotor Load1/For Each Subsystem/Propulsor/Powertrain Architecture/DC Bus'
 * '<S525>' : 'Multirotor_Model_1/Vehicle Performance/Total Rotor Load1/For Each Subsystem/Propulsor/Powertrain Architecture/Motor'
 * '<S526>' : 'Multirotor_Model_1/Vehicle Performance/Total Rotor Load1/For Each Subsystem/Propulsor/Powertrain Architecture/Battery/Compare To Constant'
 * '<S527>' : 'Multirotor_Model_1/Vehicle Performance/Total Rotor Load1/For Each Subsystem/Propulsor/Powertrain Architecture/Battery/Compare To Constant1'
 * '<S528>' : 'Multirotor_Model_1/Vehicle Performance/Total Rotor Load1/For Each Subsystem/Propulsor/Powertrain Architecture/Battery/E_charge'
 * '<S529>' : 'Multirotor_Model_1/Vehicle Performance/Total Rotor Load1/For Each Subsystem/Propulsor/Powertrain Architecture/Battery/E_discharge'
 * '<S530>' : 'Multirotor_Model_1/Vehicle Performance/Total Rotor Load1/For Each Subsystem/Propulsor/Powertrain Architecture/Battery/Exponential'
 * '<S531>' : 'Multirotor_Model_1/Vehicle Performance/Total Rotor Load1/For Each Subsystem/Propulsor/Powertrain Architecture/Battery/Filtered Derivative (Discrete or Continuous)'
 * '<S532>' : 'Multirotor_Model_1/Vehicle Performance/Total Rotor Load1/For Each Subsystem/Propulsor/Powertrain Architecture/Battery/Heat Balance'
 * '<S533>' : 'Multirotor_Model_1/Vehicle Performance/Total Rotor Load1/For Each Subsystem/Propulsor/Powertrain Architecture/Battery/E_charge/If Action Subsystem3'
 * '<S534>' : 'Multirotor_Model_1/Vehicle Performance/Total Rotor Load1/For Each Subsystem/Propulsor/Powertrain Architecture/Battery/E_charge/If Action Subsystem4'
 * '<S535>' : 'Multirotor_Model_1/Vehicle Performance/Total Rotor Load1/For Each Subsystem/Propulsor/Powertrain Architecture/Battery/E_charge/If Action Subsystem5'
 * '<S536>' : 'Multirotor_Model_1/Vehicle Performance/Total Rotor Load1/For Each Subsystem/Propulsor/Powertrain Architecture/Battery/E_discharge/If Action Subsystem3'
 * '<S537>' : 'Multirotor_Model_1/Vehicle Performance/Total Rotor Load1/For Each Subsystem/Propulsor/Powertrain Architecture/Battery/E_discharge/If Action Subsystem4'
 * '<S538>' : 'Multirotor_Model_1/Vehicle Performance/Total Rotor Load1/For Each Subsystem/Propulsor/Powertrain Architecture/Battery/E_discharge/If Action Subsystem5'
 * '<S539>' : 'Multirotor_Model_1/Vehicle Performance/Total Rotor Load1/For Each Subsystem/Propulsor/Powertrain Architecture/Battery/Filtered Derivative (Discrete or Continuous)/Enable//disable time constant'
 * '<S540>' : 'Multirotor_Model_1/Vehicle Performance/Total Rotor Load1/For Each Subsystem/Propulsor/Powertrain Architecture/Battery/Filtered Derivative (Discrete or Continuous)/Initialization'
 * '<S541>' : 'Multirotor_Model_1/Vehicle Performance/Total Rotor Load1/For Each Subsystem/Propulsor/Powertrain Architecture/Battery/Filtered Derivative (Discrete or Continuous)/Integrator (Discrete or Continuous)'
 * '<S542>' : 'Multirotor_Model_1/Vehicle Performance/Total Rotor Load1/For Each Subsystem/Propulsor/Powertrain Architecture/Battery/Filtered Derivative (Discrete or Continuous)/Initialization/Init_param'
 * '<S543>' : 'Multirotor_Model_1/Vehicle Performance/Total Rotor Load1/For Each Subsystem/Propulsor/Powertrain Architecture/Battery/Filtered Derivative (Discrete or Continuous)/Integrator (Discrete or Continuous)/Continuous'
 * '<S544>' : 'Multirotor_Model_1/Vehicle Performance/Total Rotor Load1/For Each Subsystem/Propulsor/Powertrain Architecture/Motor/Efficiency'
 * '<S545>' : 'Multirotor_Model_1/Vehicle Performance/Total Rotor Load1/For Each Subsystem/Propulsor/Powertrain Architecture/Motor/Heat '
 * '<S546>' : 'Multirotor_Model_1/Vehicle Performance/Total Rotor Load1/For Each Subsystem/Propulsor/Powertrain Architecture/Motor/Performance'
 * '<S547>' : 'Multirotor_Model_1/Vehicle Performance/Total Rotor Load1/For Each Subsystem/Propulsor/Powertrain Architecture/Motor/Torque Control'
 * '<S548>' : 'Multirotor_Model_1/Vehicle Performance/Total Rotor Load1/For Each Subsystem/Propulsor/Powertrain Architecture/Motor/Efficiency/Motor Efficiency Function'
 * '<S549>' : 'Multirotor_Model_1/Vehicle Performance/Total Rotor Load1/For Each Subsystem/Propulsor/Powertrain Architecture/Motor/Torque Control/Torque Controller'
 * '<S550>' : 'Multirotor_Model_1/Vehicle Performance/Total Rotor Load1/For Each Subsystem/Propulsor/Powertrain Architecture/Motor/Torque Control/Torque Controller/Anti-windup'
 * '<S551>' : 'Multirotor_Model_1/Vehicle Performance/Total Rotor Load1/For Each Subsystem/Propulsor/Powertrain Architecture/Motor/Torque Control/Torque Controller/D Gain'
 * '<S552>' : 'Multirotor_Model_1/Vehicle Performance/Total Rotor Load1/For Each Subsystem/Propulsor/Powertrain Architecture/Motor/Torque Control/Torque Controller/Filter'
 * '<S553>' : 'Multirotor_Model_1/Vehicle Performance/Total Rotor Load1/For Each Subsystem/Propulsor/Powertrain Architecture/Motor/Torque Control/Torque Controller/Filter ICs'
 * '<S554>' : 'Multirotor_Model_1/Vehicle Performance/Total Rotor Load1/For Each Subsystem/Propulsor/Powertrain Architecture/Motor/Torque Control/Torque Controller/I Gain'
 * '<S555>' : 'Multirotor_Model_1/Vehicle Performance/Total Rotor Load1/For Each Subsystem/Propulsor/Powertrain Architecture/Motor/Torque Control/Torque Controller/Ideal P Gain'
 * '<S556>' : 'Multirotor_Model_1/Vehicle Performance/Total Rotor Load1/For Each Subsystem/Propulsor/Powertrain Architecture/Motor/Torque Control/Torque Controller/Ideal P Gain Fdbk'
 * '<S557>' : 'Multirotor_Model_1/Vehicle Performance/Total Rotor Load1/For Each Subsystem/Propulsor/Powertrain Architecture/Motor/Torque Control/Torque Controller/Integrator'
 * '<S558>' : 'Multirotor_Model_1/Vehicle Performance/Total Rotor Load1/For Each Subsystem/Propulsor/Powertrain Architecture/Motor/Torque Control/Torque Controller/Integrator ICs'
 * '<S559>' : 'Multirotor_Model_1/Vehicle Performance/Total Rotor Load1/For Each Subsystem/Propulsor/Powertrain Architecture/Motor/Torque Control/Torque Controller/N Copy'
 * '<S560>' : 'Multirotor_Model_1/Vehicle Performance/Total Rotor Load1/For Each Subsystem/Propulsor/Powertrain Architecture/Motor/Torque Control/Torque Controller/N Gain'
 * '<S561>' : 'Multirotor_Model_1/Vehicle Performance/Total Rotor Load1/For Each Subsystem/Propulsor/Powertrain Architecture/Motor/Torque Control/Torque Controller/P Copy'
 * '<S562>' : 'Multirotor_Model_1/Vehicle Performance/Total Rotor Load1/For Each Subsystem/Propulsor/Powertrain Architecture/Motor/Torque Control/Torque Controller/Parallel P Gain'
 * '<S563>' : 'Multirotor_Model_1/Vehicle Performance/Total Rotor Load1/For Each Subsystem/Propulsor/Powertrain Architecture/Motor/Torque Control/Torque Controller/Reset Signal'
 * '<S564>' : 'Multirotor_Model_1/Vehicle Performance/Total Rotor Load1/For Each Subsystem/Propulsor/Powertrain Architecture/Motor/Torque Control/Torque Controller/Saturation'
 * '<S565>' : 'Multirotor_Model_1/Vehicle Performance/Total Rotor Load1/For Each Subsystem/Propulsor/Powertrain Architecture/Motor/Torque Control/Torque Controller/Saturation Fdbk'
 * '<S566>' : 'Multirotor_Model_1/Vehicle Performance/Total Rotor Load1/For Each Subsystem/Propulsor/Powertrain Architecture/Motor/Torque Control/Torque Controller/Sum'
 * '<S567>' : 'Multirotor_Model_1/Vehicle Performance/Total Rotor Load1/For Each Subsystem/Propulsor/Powertrain Architecture/Motor/Torque Control/Torque Controller/Sum Fdbk'
 * '<S568>' : 'Multirotor_Model_1/Vehicle Performance/Total Rotor Load1/For Each Subsystem/Propulsor/Powertrain Architecture/Motor/Torque Control/Torque Controller/Tracking Mode'
 * '<S569>' : 'Multirotor_Model_1/Vehicle Performance/Total Rotor Load1/For Each Subsystem/Propulsor/Powertrain Architecture/Motor/Torque Control/Torque Controller/Tracking Mode Sum'
 * '<S570>' : 'Multirotor_Model_1/Vehicle Performance/Total Rotor Load1/For Each Subsystem/Propulsor/Powertrain Architecture/Motor/Torque Control/Torque Controller/Tsamp - Integral'
 * '<S571>' : 'Multirotor_Model_1/Vehicle Performance/Total Rotor Load1/For Each Subsystem/Propulsor/Powertrain Architecture/Motor/Torque Control/Torque Controller/Tsamp - Ngain'
 * '<S572>' : 'Multirotor_Model_1/Vehicle Performance/Total Rotor Load1/For Each Subsystem/Propulsor/Powertrain Architecture/Motor/Torque Control/Torque Controller/postSat Signal'
 * '<S573>' : 'Multirotor_Model_1/Vehicle Performance/Total Rotor Load1/For Each Subsystem/Propulsor/Powertrain Architecture/Motor/Torque Control/Torque Controller/preSat Signal'
 * '<S574>' : 'Multirotor_Model_1/Vehicle Performance/Total Rotor Load1/For Each Subsystem/Propulsor/Powertrain Architecture/Motor/Torque Control/Torque Controller/Anti-windup/Cont. Clamping Parallel'
 * '<S575>' : 'Multirotor_Model_1/Vehicle Performance/Total Rotor Load1/For Each Subsystem/Propulsor/Powertrain Architecture/Motor/Torque Control/Torque Controller/Anti-windup/Cont. Clamping Parallel/Dead Zone'
 * '<S576>' : 'Multirotor_Model_1/Vehicle Performance/Total Rotor Load1/For Each Subsystem/Propulsor/Powertrain Architecture/Motor/Torque Control/Torque Controller/Anti-windup/Cont. Clamping Parallel/Dead Zone/Enabled'
 * '<S577>' : 'Multirotor_Model_1/Vehicle Performance/Total Rotor Load1/For Each Subsystem/Propulsor/Powertrain Architecture/Motor/Torque Control/Torque Controller/D Gain/Internal Parameters'
 * '<S578>' : 'Multirotor_Model_1/Vehicle Performance/Total Rotor Load1/For Each Subsystem/Propulsor/Powertrain Architecture/Motor/Torque Control/Torque Controller/Filter/Cont. Filter'
 * '<S579>' : 'Multirotor_Model_1/Vehicle Performance/Total Rotor Load1/For Each Subsystem/Propulsor/Powertrain Architecture/Motor/Torque Control/Torque Controller/Filter ICs/Internal IC - Filter'
 * '<S580>' : 'Multirotor_Model_1/Vehicle Performance/Total Rotor Load1/For Each Subsystem/Propulsor/Powertrain Architecture/Motor/Torque Control/Torque Controller/I Gain/Internal Parameters'
 * '<S581>' : 'Multirotor_Model_1/Vehicle Performance/Total Rotor Load1/For Each Subsystem/Propulsor/Powertrain Architecture/Motor/Torque Control/Torque Controller/Ideal P Gain/Passthrough'
 * '<S582>' : 'Multirotor_Model_1/Vehicle Performance/Total Rotor Load1/For Each Subsystem/Propulsor/Powertrain Architecture/Motor/Torque Control/Torque Controller/Ideal P Gain Fdbk/Disabled'
 * '<S583>' : 'Multirotor_Model_1/Vehicle Performance/Total Rotor Load1/For Each Subsystem/Propulsor/Powertrain Architecture/Motor/Torque Control/Torque Controller/Integrator/Continuous'
 * '<S584>' : 'Multirotor_Model_1/Vehicle Performance/Total Rotor Load1/For Each Subsystem/Propulsor/Powertrain Architecture/Motor/Torque Control/Torque Controller/Integrator ICs/Internal IC'
 * '<S585>' : 'Multirotor_Model_1/Vehicle Performance/Total Rotor Load1/For Each Subsystem/Propulsor/Powertrain Architecture/Motor/Torque Control/Torque Controller/N Copy/Disabled'
 * '<S586>' : 'Multirotor_Model_1/Vehicle Performance/Total Rotor Load1/For Each Subsystem/Propulsor/Powertrain Architecture/Motor/Torque Control/Torque Controller/N Gain/Internal Parameters'
 * '<S587>' : 'Multirotor_Model_1/Vehicle Performance/Total Rotor Load1/For Each Subsystem/Propulsor/Powertrain Architecture/Motor/Torque Control/Torque Controller/P Copy/Disabled'
 * '<S588>' : 'Multirotor_Model_1/Vehicle Performance/Total Rotor Load1/For Each Subsystem/Propulsor/Powertrain Architecture/Motor/Torque Control/Torque Controller/Parallel P Gain/Internal Parameters'
 * '<S589>' : 'Multirotor_Model_1/Vehicle Performance/Total Rotor Load1/For Each Subsystem/Propulsor/Powertrain Architecture/Motor/Torque Control/Torque Controller/Reset Signal/Disabled'
 * '<S590>' : 'Multirotor_Model_1/Vehicle Performance/Total Rotor Load1/For Each Subsystem/Propulsor/Powertrain Architecture/Motor/Torque Control/Torque Controller/Saturation/Enabled'
 * '<S591>' : 'Multirotor_Model_1/Vehicle Performance/Total Rotor Load1/For Each Subsystem/Propulsor/Powertrain Architecture/Motor/Torque Control/Torque Controller/Saturation Fdbk/Disabled'
 * '<S592>' : 'Multirotor_Model_1/Vehicle Performance/Total Rotor Load1/For Each Subsystem/Propulsor/Powertrain Architecture/Motor/Torque Control/Torque Controller/Sum/Sum_PID'
 * '<S593>' : 'Multirotor_Model_1/Vehicle Performance/Total Rotor Load1/For Each Subsystem/Propulsor/Powertrain Architecture/Motor/Torque Control/Torque Controller/Sum Fdbk/Disabled'
 * '<S594>' : 'Multirotor_Model_1/Vehicle Performance/Total Rotor Load1/For Each Subsystem/Propulsor/Powertrain Architecture/Motor/Torque Control/Torque Controller/Tracking Mode/Disabled'
 * '<S595>' : 'Multirotor_Model_1/Vehicle Performance/Total Rotor Load1/For Each Subsystem/Propulsor/Powertrain Architecture/Motor/Torque Control/Torque Controller/Tracking Mode Sum/Passthrough'
 * '<S596>' : 'Multirotor_Model_1/Vehicle Performance/Total Rotor Load1/For Each Subsystem/Propulsor/Powertrain Architecture/Motor/Torque Control/Torque Controller/Tsamp - Integral/Passthrough'
 * '<S597>' : 'Multirotor_Model_1/Vehicle Performance/Total Rotor Load1/For Each Subsystem/Propulsor/Powertrain Architecture/Motor/Torque Control/Torque Controller/Tsamp - Ngain/Passthrough'
 * '<S598>' : 'Multirotor_Model_1/Vehicle Performance/Total Rotor Load1/For Each Subsystem/Propulsor/Powertrain Architecture/Motor/Torque Control/Torque Controller/postSat Signal/Forward_Path'
 * '<S599>' : 'Multirotor_Model_1/Vehicle Performance/Total Rotor Load1/For Each Subsystem/Propulsor/Powertrain Architecture/Motor/Torque Control/Torque Controller/preSat Signal/Forward_Path'
 * '<S600>' : 'Multirotor_Model_1/Vehicle Performance/Weight/MATLAB Function'
 * '<S601>' : 'Multirotor_Model_1/Vehicle Performance/Wing Load/MATLAB Function'
 */
#endif                                 /* RTW_HEADER_Multirotor_Model_1_h_ */
