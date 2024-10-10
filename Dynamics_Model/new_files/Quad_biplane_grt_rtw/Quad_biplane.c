/*
 * Quad_biplane.c
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

#include "Quad_biplane.h"
#include "Quad_biplane_private.h"

/* Block signals (default storage) */
B_Quad_biplane_T Quad_biplane_B;

/* Continuous states */
X_Quad_biplane_T Quad_biplane_X;

/* Block states (default storage) */
DW_Quad_biplane_T Quad_biplane_DW;

/* Previous zero-crossings (trigger) states */
PrevZCX_Quad_biplane_T Quad_biplane_PrevZCX;

/* Real-time model */
static RT_MODEL_Quad_biplane_T Quad_biplane_M_;
RT_MODEL_Quad_biplane_T *const Quad_biplane_M = &Quad_biplane_M_;

/* Forward declaration for local functions */
static void Quad_biplane_sind(real_T *x);
static void Quad_biplane_cosd(real_T *x);

/*
 * This function updates continuous states using the ODE4 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE4_IntgData *id = (ODE4_IntgData *)rtsiGetSolverData(si);
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T *f3 = id->f[3];
  real_T temp;
  int_T i;
  int_T nXc = 36;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  Quad_biplane_derivatives();

  /* f1 = f(t + (h/2), y + (h/2)*f0) */
  temp = 0.5 * h;
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (temp*f0[i]);
  }

  rtsiSetT(si, t + temp);
  rtsiSetdX(si, f1);
  Quad_biplane_step();
  Quad_biplane_derivatives();

  /* f2 = f(t + (h/2), y + (h/2)*f1) */
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (temp*f1[i]);
  }

  rtsiSetdX(si, f2);
  Quad_biplane_step();
  Quad_biplane_derivatives();

  /* f3 = f(t + h, y + h*f2) */
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (h*f2[i]);
  }

  rtsiSetT(si, tnew);
  rtsiSetdX(si, f3);
  Quad_biplane_step();
  Quad_biplane_derivatives();

  /* tnew = t + h
     ynew = y + (h/6)*(f0 + 2*f1 + 2*f2 + 2*f3) */
  temp = h / 6.0;
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + temp*(f0[i] + 2.0*f1[i] + 2.0*f2[i] + f3[i]);
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/*
 * Output and update for action system:
 *    '<S59>/If Action Subsystem'
 *    '<S59>/If Action Subsystem1'
 *    '<S310>/If Action Subsystem1'
 */
void Quad_biplane_IfActionSubsystem(real_T rtu_In1, real_T *rty_Out1)
{
  /* Inport: '<S61>/In1' */
  *rty_Out1 = rtu_In1;
}

/*
 * Output and update for atomic system:
 *    '<S619>/MATLAB Function'
 *    '<S620>/MATLAB Function'
 *    '<S621>/MATLAB Function'
 *    '<S622>/MATLAB Function'
 */
void Quad_biplane_MATLABFunction(real_T rtu_rpm, B_MATLABFunction_Quad_biplane_T
  *localB)
{
  localB->load[0] = 0.0;
  localB->load[1] = 0.0;
  localB->load[2] = 0.0003 * rtu_rpm * rtu_rpm;
  localB->load[3] = 0.0;
  localB->load[4] = 0.0;
  localB->load[5] = 1.0E-5 * rtu_rpm * rtu_rpm;
}

real_T rt_atan2d_snf(real_T u0, real_T u1)
{
  real_T y;
  int32_T u0_0;
  int32_T u1_0;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else if (rtIsInf(u0) && rtIsInf(u1)) {
    if (u0 > 0.0) {
      u0_0 = 1;
    } else {
      u0_0 = -1;
    }

    if (u1 > 0.0) {
      u1_0 = 1;
    } else {
      u1_0 = -1;
    }

    y = atan2(u0_0, u1_0);
  } else if (u1 == 0.0) {
    if (u0 > 0.0) {
      y = RT_PI / 2.0;
    } else if (u0 < 0.0) {
      y = -(RT_PI / 2.0);
    } else {
      y = 0.0;
    }
  } else {
    y = atan2(u0, u1);
  }

  return y;
}

real_T rt_remd_snf(real_T u0, real_T u1)
{
  real_T q;
  real_T y;
  if (rtIsNaN(u0) || rtIsNaN(u1) || rtIsInf(u0)) {
    y = (rtNaN);
  } else if (rtIsInf(u1)) {
    y = u0;
  } else if ((u1 != 0.0) && (u1 != trunc(u1))) {
    q = fabs(u0 / u1);
    if (!(fabs(q - floor(q + 0.5)) > DBL_EPSILON * q)) {
      y = 0.0 * u0;
    } else {
      y = fmod(u0, u1);
    }
  } else {
    y = fmod(u0, u1);
  }

  return y;
}

/* Function for MATLAB Function: '<S612>/Fuselage' */
static void Quad_biplane_sind(real_T *x)
{
  real_T absx;
  real_T c_x;
  int8_T n;
  if (rtIsInf(*x) || rtIsNaN(*x)) {
    *x = (rtNaN);
  } else {
    c_x = rt_remd_snf(*x, 360.0);
    absx = fabs(c_x);
    if (absx > 180.0) {
      if (c_x > 0.0) {
        c_x -= 360.0;
      } else {
        c_x += 360.0;
      }

      absx = fabs(c_x);
    }

    if (absx <= 45.0) {
      c_x *= 0.017453292519943295;
      *x = sin(c_x);
    } else {
      if (absx <= 135.0) {
        if (c_x > 0.0) {
          c_x = (c_x - 90.0) * 0.017453292519943295;
          n = 1;
        } else {
          c_x = (c_x + 90.0) * 0.017453292519943295;
          n = -1;
        }
      } else if (c_x > 0.0) {
        c_x = (c_x - 180.0) * 0.017453292519943295;
        n = 2;
      } else {
        c_x = (c_x + 180.0) * 0.017453292519943295;
        n = -2;
      }

      if (n == 1) {
        *x = cos(c_x);
      } else if (n == -1) {
        *x = -cos(c_x);
      } else {
        *x = -sin(c_x);
      }
    }
  }
}

/* Function for MATLAB Function: '<S612>/Fuselage' */
static void Quad_biplane_cosd(real_T *x)
{
  real_T absx;
  real_T b_x;
  int8_T n;
  if (rtIsInf(*x) || rtIsNaN(*x)) {
    *x = (rtNaN);
  } else {
    b_x = rt_remd_snf(*x, 360.0);
    absx = fabs(b_x);
    if (absx > 180.0) {
      if (b_x > 0.0) {
        b_x -= 360.0;
      } else {
        b_x += 360.0;
      }

      absx = fabs(b_x);
    }

    if (absx <= 45.0) {
      b_x *= 0.017453292519943295;
      *x = cos(b_x);
    } else {
      if (absx <= 135.0) {
        if (b_x > 0.0) {
          b_x = (b_x - 90.0) * 0.017453292519943295;
          n = 1;
        } else {
          b_x = (b_x + 90.0) * 0.017453292519943295;
          n = -1;
        }
      } else if (b_x > 0.0) {
        b_x = (b_x - 180.0) * 0.017453292519943295;
        n = 2;
      } else {
        b_x = (b_x + 180.0) * 0.017453292519943295;
        n = -2;
      }

      if (n == 1) {
        *x = -sin(b_x);
      } else if (n == -1) {
        *x = sin(b_x);
      } else {
        *x = -cos(b_x);
      }
    }
  }
}

/* Model step function */
void Quad_biplane_step(void)
{
  /* local block i/o variables */
  real_T rtb_RPMs[4];
  real_T rtb_Gain1;
  real_T rtb_Gain1_i;
  real_T rtb_SquareRoot_c;
  real_T rtb_load_wing_i[6];
  real_T rtb_Sum2;
  static const int8_T b[3] = { 0, 0, 1 };

  real_T R[9];
  real_T R_tmp[9];
  real_T c[9];
  real_T rtb_SquareRoot_0[9];
  real_T P_ddot[3];
  real_T R_0[3];
  real_T R_1[3];
  real_T R_2[3];
  real_T Weight_Force[3];
  real_T tmp[3];
  real_T CL;
  real_T D;
  real_T L;
  real_T R_tmp_tmp;
  real_T R_tmp_tmp_0;
  real_T Total_Rotor_Load_tmp;
  real_T Total_Rotor_Load_tmp_0;
  real_T g;
  real_T h;
  real_T i;
  real_T rtb_Clock;
  real_T rtb_Filter_c_tmp;
  real_T rtb_Filter_i;
  real_T rtb_SquareRoot;
  real_T rtb_SquareRoot_tmp;
  real_T rtb_Sum1;
  real_T rtb_Sum2_i;
  real_T rtb_Sum3;
  real_T rtb_Sum_g;
  real_T rtb_Sum_g_tmp;
  real_T rtb_Sum_m;
  real_T rtb_load_wing_idx_2;
  int32_T c_tmp;
  int32_T i_0;
  int32_T i_1;
  int8_T rtAction;
  ZCEventType zcEvent;
  if (rtmIsMajorTimeStep(Quad_biplane_M)) {
    /* set solver stop time */
    if (!(Quad_biplane_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&Quad_biplane_M->solverInfo,
                            ((Quad_biplane_M->Timing.clockTickH0 + 1) *
        Quad_biplane_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&Quad_biplane_M->solverInfo,
                            ((Quad_biplane_M->Timing.clockTick0 + 1) *
        Quad_biplane_M->Timing.stepSize0 + Quad_biplane_M->Timing.clockTickH0 *
        Quad_biplane_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(Quad_biplane_M)) {
    Quad_biplane_M->Timing.t[0] = rtsiGetT(&Quad_biplane_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(Quad_biplane_M)) {
    /* Delay: '<Root>/Delay' */
    memcpy(&Quad_biplane_B.Delay[0], &Quad_biplane_DW.Delay_DSTATE[0], 24U *
           sizeof(real_T));
  }

  /* Clock: '<Root>/Clock' */
  rtb_Clock = Quad_biplane_M->Timing.t[0];

  /* MATLAB Function: '<Root>/Mission Profile' */
  Quad_biplane_B.Z_desired = 0.0;
  Quad_biplane_B.X_desired = 0.0;
  Quad_biplane_B.theta_desired = 0.0;
  Quad_biplane_B.psi_desired = 0.0;
  Quad_biplane_B.transition = 0.0;
  if ((rtb_Clock >= 0.0) && (rtb_Clock <= 100.0)) {
    Quad_biplane_B.Z_desired = -200.0;
    Quad_biplane_B.X_desired = 0.0;
    Quad_biplane_B.transition = 0.0;
  }

  if ((rtb_Clock > 100.0) && (rtb_Clock <= 700.0)) {
    Quad_biplane_B.Z_desired = 0.0;
    Quad_biplane_B.theta_desired = fmax(-1.4, (rtb_Clock - 100.0) / 5.0 * -1.4);
    Quad_biplane_B.transition = 1.0;
  }

  if ((rtb_Clock > 700.0) && (rtb_Clock <= 850.0)) {
    Quad_biplane_B.Z_desired = 0.0;
    Quad_biplane_B.theta_desired = fmin(0.0, (rtb_Clock - 705.0) / 5.0 * 1.4);
    Quad_biplane_B.transition = 1.0;
  }

  if ((rtb_Clock > 850.0) && (rtb_Clock <= 1000.0)) {
    Quad_biplane_B.Z_desired = -1.0;
    Quad_biplane_B.X_desired = 0.0;
    Quad_biplane_B.transition = 0.0;
  }

  /* End of MATLAB Function: '<Root>/Mission Profile' */
  if (rtmIsMajorTimeStep(Quad_biplane_M)) {
    /* Sum: '<S309>/Sum1' incorporates:
     *  Constant: '<S8>/Constant'
     */
    rtb_Sum1 = Quad_biplane_P.Constant_Value - Quad_biplane_B.Delay[1];

    /* Gain: '<S399>/Proportional Gain' */
    Quad_biplane_B.ProportionalGain = Quad_biplane_P.PIDController1_P * rtb_Sum1;

    /* Gain: '<S388>/Derivative Gain' */
    Quad_biplane_B.DerivativeGain = Quad_biplane_P.PIDController1_D * rtb_Sum1;
  }

  /* Gain: '<S397>/Filter Coefficient' incorporates:
   *  Integrator: '<S389>/Filter'
   *  Sum: '<S389>/SumD'
   */
  Quad_biplane_B.FilterCoefficient = (Quad_biplane_B.DerivativeGain -
    Quad_biplane_X.Filter_CSTATE) * Quad_biplane_P.PIDController1_N;

  /* Sum: '<S403>/Sum' incorporates:
   *  Integrator: '<S394>/Integrator'
   */
  L = (Quad_biplane_B.ProportionalGain + Quad_biplane_X.Integrator_CSTATE) +
    Quad_biplane_B.FilterCoefficient;

  /* Saturate: '<S401>/Saturation' */
  if (L > Quad_biplane_P.PIDController1_UpperSaturationL) {
    /* Saturate: '<S401>/Saturation' */
    Quad_biplane_B.Saturation = Quad_biplane_P.PIDController1_UpperSaturationL;
  } else if (L < Quad_biplane_P.PIDController1_LowerSaturationL) {
    /* Saturate: '<S401>/Saturation' */
    Quad_biplane_B.Saturation = Quad_biplane_P.PIDController1_LowerSaturationL;
  } else {
    /* Saturate: '<S401>/Saturation' */
    Quad_biplane_B.Saturation = L;
  }

  /* End of Saturate: '<S401>/Saturation' */

  /* Sum: '<S310>/Sum' */
  rtb_Clock = Quad_biplane_B.Z_desired - Quad_biplane_B.Delay[2];

  /* Gain: '<S594>/Filter Coefficient' incorporates:
   *  Gain: '<S585>/Derivative Gain'
   *  Integrator: '<S586>/Filter'
   *  Sum: '<S586>/SumD'
   */
  Quad_biplane_B.FilterCoefficient_j = (Quad_biplane_P.PIDController_D *
    rtb_Clock - Quad_biplane_X.Filter_CSTATE_p) * Quad_biplane_P.PIDController_N;

  /* Sum: '<S600>/Sum' incorporates:
   *  Gain: '<S596>/Proportional Gain'
   *  Integrator: '<S591>/Integrator'
   */
  L = (Quad_biplane_P.PIDController_P * rtb_Clock +
       Quad_biplane_X.Integrator_CSTATE_b) + Quad_biplane_B.FilterCoefficient_j;

  /* Saturate: '<S598>/Saturation' */
  if (L > Quad_biplane_P.PIDController_UpperSaturationLi) {
    /* Saturate: '<S598>/Saturation' */
    Quad_biplane_B.Saturation_h = Quad_biplane_P.PIDController_UpperSaturationLi;
  } else if (L < Quad_biplane_P.PIDController_LowerSaturationLi) {
    /* Saturate: '<S598>/Saturation' */
    Quad_biplane_B.Saturation_h = Quad_biplane_P.PIDController_LowerSaturationLi;
  } else {
    /* Saturate: '<S598>/Saturation' */
    Quad_biplane_B.Saturation_h = L;
  }

  /* End of Saturate: '<S598>/Saturation' */

  /* If: '<S310>/If' */
  if (rtmIsMajorTimeStep(Quad_biplane_M)) {
    if (Quad_biplane_B.transition == 1.0) {
      rtAction = 0;
    } else if (Quad_biplane_B.transition == 2.0) {
      rtAction = 1;
    } else {
      rtAction = 2;
    }

    Quad_biplane_DW.If_ActiveSubsystem = rtAction;
  } else {
    rtAction = Quad_biplane_DW.If_ActiveSubsystem;
  }

  switch (rtAction) {
   case 0:
    /* Outputs for IfAction SubSystem: '<S310>/If Action Subsystem' incorporates:
     *  ActionPort: '<S507>/Action Port'
     */
    /* Merge: '<S310>/Merge' incorporates:
     *  Inport: '<S507>/Z_desired'
     */
    Quad_biplane_B.Merge = Quad_biplane_B.Z_desired;

    /* End of Outputs for SubSystem: '<S310>/If Action Subsystem' */
    break;

   case 1:
    /* Outputs for IfAction SubSystem: '<S310>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S509>/Action Port'
     */
    if (rtmIsMajorTimeStep(Quad_biplane_M)) {
      /* Gain: '<S548>/Proportional Gain' */
      Quad_biplane_B.ProportionalGain_j = Quad_biplane_P.PIDController2_P * 0.0;

      /* Gain: '<S537>/Derivative Gain' */
      Quad_biplane_B.DerivativeGain_h = Quad_biplane_P.PIDController2_D * 0.0;
    }

    /* Gain: '<S546>/Filter Coefficient' incorporates:
     *  Integrator: '<S538>/Filter'
     *  Sum: '<S538>/SumD'
     */
    Quad_biplane_B.FilterCoefficient_p = (Quad_biplane_B.DerivativeGain_h -
      Quad_biplane_X.Filter_CSTATE_fr) * Quad_biplane_P.PIDController2_N;

    /* Sum: '<S552>/Sum' incorporates:
     *  Integrator: '<S543>/Integrator'
     */
    L = (Quad_biplane_B.ProportionalGain_j + Quad_biplane_X.Integrator_CSTATE_c5)
      + Quad_biplane_B.FilterCoefficient_p;

    /* Saturate: '<S550>/Saturation' */
    if (L > Quad_biplane_P.PIDController2_UpperSaturationL) {
      /* Saturate: '<S550>/Saturation' */
      Quad_biplane_B.Saturation_k =
        Quad_biplane_P.PIDController2_UpperSaturationL;
    } else if (L < Quad_biplane_P.PIDController2_LowerSaturationL) {
      /* Saturate: '<S550>/Saturation' */
      Quad_biplane_B.Saturation_k =
        Quad_biplane_P.PIDController2_LowerSaturationL;
    } else {
      /* Saturate: '<S550>/Saturation' */
      Quad_biplane_B.Saturation_k = L;
    }

    /* End of Saturate: '<S550>/Saturation' */
    if (rtmIsMajorTimeStep(Quad_biplane_M)) {
      /* Gain: '<S540>/Integral Gain' */
      Quad_biplane_B.IntegralGain_f = Quad_biplane_P.PIDController2_I * 0.0;
    }

    /* End of Outputs for SubSystem: '<S310>/If Action Subsystem2' */
    break;

   case 2:
    /* Outputs for IfAction SubSystem: '<S310>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S508>/Action Port'
     */
    Quad_biplane_IfActionSubsystem(Quad_biplane_B.Saturation_h,
      &Quad_biplane_B.Merge);

    /* End of Outputs for SubSystem: '<S310>/If Action Subsystem1' */
    break;
  }

  /* End of If: '<S310>/If' */

  /* Sum: '<S309>/Sum2' */
  rtb_Sum2_i = Quad_biplane_B.theta_desired - Quad_biplane_B.Delay[7];

  /* Gain: '<S445>/Filter Coefficient' incorporates:
   *  Gain: '<S436>/Derivative Gain'
   *  Integrator: '<S437>/Filter'
   *  Sum: '<S437>/SumD'
   */
  Quad_biplane_B.FilterCoefficient_f = (Quad_biplane_P.PIDController2_D_n *
    rtb_Sum2_i - Quad_biplane_X.Filter_CSTATE_a) *
    Quad_biplane_P.PIDController2_N_h;

  /* Sum: '<S451>/Sum' incorporates:
   *  Gain: '<S447>/Proportional Gain'
   *  Integrator: '<S442>/Integrator'
   */
  L = (Quad_biplane_P.PIDController2_P_a * rtb_Sum2_i +
       Quad_biplane_X.Integrator_CSTATE_d) + Quad_biplane_B.FilterCoefficient_f;

  /* Saturate: '<S449>/Saturation' */
  if (L > Quad_biplane_P.PIDController2_UpperSaturatio_e) {
    /* Saturate: '<S449>/Saturation' */
    Quad_biplane_B.Saturation_hv =
      Quad_biplane_P.PIDController2_UpperSaturatio_e;
  } else if (L < Quad_biplane_P.PIDController2_LowerSaturatio_e) {
    /* Saturate: '<S449>/Saturation' */
    Quad_biplane_B.Saturation_hv =
      Quad_biplane_P.PIDController2_LowerSaturatio_e;
  } else {
    /* Saturate: '<S449>/Saturation' */
    Quad_biplane_B.Saturation_hv = L;
  }

  /* End of Saturate: '<S449>/Saturation' */

  /* Sum: '<S309>/Sum3' */
  rtb_Sum3 = Quad_biplane_B.psi_desired - Quad_biplane_B.Delay[8];

  /* Gain: '<S493>/Filter Coefficient' incorporates:
   *  Gain: '<S484>/Derivative Gain'
   *  Integrator: '<S485>/Filter'
   *  Sum: '<S485>/SumD'
   */
  Quad_biplane_B.FilterCoefficient_e = (Quad_biplane_P.PIDController3_D *
    rtb_Sum3 - Quad_biplane_X.Filter_CSTATE_d) * Quad_biplane_P.PIDController3_N;

  /* Sum: '<S499>/Sum' incorporates:
   *  Gain: '<S495>/Proportional Gain'
   *  Integrator: '<S490>/Integrator'
   */
  L = (Quad_biplane_P.PIDController3_P * rtb_Sum3 +
       Quad_biplane_X.Integrator_CSTATE_n) + Quad_biplane_B.FilterCoefficient_e;

  /* Saturate: '<S497>/Saturation' */
  if (L > Quad_biplane_P.PIDController3_UpperSaturationL) {
    /* Saturate: '<S497>/Saturation' */
    Quad_biplane_B.Saturation_f = Quad_biplane_P.PIDController3_UpperSaturationL;
  } else if (L < Quad_biplane_P.PIDController3_LowerSaturationL) {
    /* Saturate: '<S497>/Saturation' */
    Quad_biplane_B.Saturation_f = Quad_biplane_P.PIDController3_LowerSaturationL;
  } else {
    /* Saturate: '<S497>/Saturation' */
    Quad_biplane_B.Saturation_f = L;
  }

  /* End of Saturate: '<S497>/Saturation' */

  /* MATLAB Function: '<S8>/MATLAB Function' incorporates:
   *  MATLAB Function: '<S2>/State_update'
   *  MATLAB Function: '<S2>/Transform1'
   *  MATLAB Function: '<S2>/Translational Dynamics'
   *  MATLAB Function: '<S614>/MATLAB Function'
   */
  rtb_Sum_m = sin(Quad_biplane_B.Delay[6]);
  R_tmp_tmp = cos(Quad_biplane_B.Delay[6]);
  rtb_Sum_g_tmp = sin(Quad_biplane_B.Delay[7]);
  R_tmp_tmp_0 = cos(Quad_biplane_B.Delay[7]);
  rtb_Filter_c_tmp = sin(Quad_biplane_B.Delay[8]);
  rtb_SquareRoot_tmp = cos(Quad_biplane_B.Delay[8]);
  R[1] = 0.0;
  R[4] = R_tmp_tmp;
  R[7] = rtb_Sum_m;
  R[2] = 0.0;
  R[5] = -rtb_Sum_m;
  R[8] = R_tmp_tmp;
  R_tmp[0] = R_tmp_tmp_0;
  R_tmp[3] = 0.0;
  R_tmp[6] = -rtb_Sum_g_tmp;
  R[0] = 1.0;
  R_tmp[1] = 0.0;
  R[3] = 0.0;
  R_tmp[4] = 1.0;
  R[6] = 0.0;
  R_tmp[7] = 0.0;
  R_tmp[2] = rtb_Sum_g_tmp;
  R_tmp[5] = 0.0;
  R_tmp[8] = R_tmp_tmp_0;
  rtb_SquareRoot_0[0] = rtb_SquareRoot_tmp;
  rtb_SquareRoot_0[3] = rtb_Filter_c_tmp;
  rtb_SquareRoot_0[6] = 0.0;
  rtb_SquareRoot_0[1] = -rtb_Filter_c_tmp;
  rtb_SquareRoot_0[4] = rtb_SquareRoot_tmp;
  rtb_SquareRoot_0[7] = 0.0;
  for (i_0 = 0; i_0 < 3; i_0++) {
    for (i_1 = 0; i_1 < 3; i_1++) {
      c_tmp = i_0 + 3 * i_1;
      c[c_tmp] = 0.0;
      c[c_tmp] += R_tmp[3 * i_1] * R[i_0];
      c[c_tmp] += R_tmp[3 * i_1 + 1] * R[i_0 + 3];
      c[c_tmp] += R_tmp[3 * i_1 + 2] * R[i_0 + 6];
    }

    rtb_SquareRoot_0[3 * i_0 + 2] = b[i_0];
  }

  P_ddot[0] = Quad_biplane_B.X_desired;
  P_ddot[1] = Quad_biplane_B.Delay[4];
  P_ddot[2] = Quad_biplane_B.Delay[5];
  Weight_Force[0] = Quad_biplane_B.Delay[3];
  Weight_Force[1] = Quad_biplane_B.Saturation;
  Weight_Force[2] = Quad_biplane_B.Delay[5];
  tmp[0] = Quad_biplane_B.Delay[3];
  tmp[1] = Quad_biplane_B.Delay[4];
  tmp[2] = Quad_biplane_B.Merge;
  for (i_0 = 0; i_0 < 3; i_0++) {
    R_0[i_0] = 0.0;
    R_1[i_0] = 0.0;
    R_2[i_0] = 0.0;
    for (i_1 = 0; i_1 < 3; i_1++) {
      c_tmp = i_0 + 3 * i_1;
      R[c_tmp] = 0.0;
      R[c_tmp] += rtb_SquareRoot_0[3 * i_1] * c[i_0];
      R[c_tmp] += rtb_SquareRoot_0[3 * i_1 + 1] * c[i_0 + 3];
      R[c_tmp] += rtb_SquareRoot_0[3 * i_1 + 2] * c[i_0 + 6];
      R_0[i_0] += R[c_tmp] * P_ddot[i_1];
      R_1[i_0] += R[c_tmp] * Weight_Force[i_1];
      R_2[i_0] += R[c_tmp] * tmp[i_1];
    }
  }

  Quad_biplane_B.u_des = R_0[0];
  Quad_biplane_B.v_des = R_1[1];
  Quad_biplane_B.w_des = R_2[2];
  c[0] = 1.0;
  c[3] = 0.0;
  c[6] = -sin(Quad_biplane_B.Delay[7]);
  c[1] = 0.0;
  c[4] = R_tmp_tmp;
  c[7] = rtb_Sum_m * R_tmp_tmp_0;
  c[2] = 0.0;
  c[5] = -sin(Quad_biplane_B.Delay[6]);
  c[8] = R_tmp_tmp * R_tmp_tmp_0;
  rtb_Sum_g = Quad_biplane_B.Delay[21];
  rtb_Filter_i = Quad_biplane_B.Delay[23];
  for (i_0 = 0; i_0 < 3; i_0++) {
    P_ddot[i_0] = c[i_0 + 6] * rtb_Filter_i + (c[i_0 + 3] *
      Quad_biplane_B.Saturation_hv + c[i_0] * rtb_Sum_g);
  }

  Quad_biplane_B.q_des = P_ddot[1];

  /* Sum: '<S9>/Sum' */
  rtb_Sum_g = Quad_biplane_B.w_des - Quad_biplane_B.Delay[20];

  /* Gain: '<S45>/Filter Coefficient' incorporates:
   *  Gain: '<S36>/Derivative Gain'
   *  Integrator: '<S37>/Filter'
   *  Sum: '<S37>/SumD'
   */
  Quad_biplane_B.FilterCoefficient_i = (Quad_biplane_P.PIDController1_D_m *
    rtb_Sum_g - Quad_biplane_X.Filter_CSTATE_k) *
    Quad_biplane_P.PIDController1_N_j;

  /* Gain: '<S9>/Gain1' incorporates:
   *  Gain: '<S47>/Proportional Gain'
   *  Integrator: '<S42>/Integrator'
   *  Sum: '<S51>/Sum'
   */
  Quad_biplane_B.Gain1 = ((Quad_biplane_P.PIDController1_P_c * rtb_Sum_g +
    Quad_biplane_X.Integrator_CSTATE_n4) + Quad_biplane_B.FilterCoefficient_i) *
    Quad_biplane_P.Gain1_Gain;
  if (rtmIsMajorTimeStep(Quad_biplane_M)) {
    /* Delay: '<S1>/Delay' */
    Quad_biplane_B.Delay_d = Quad_biplane_DW.Delay_DSTATE_m;
  }

  /* Sum: '<S9>/Sum1' */
  Quad_biplane_B.Sum1 = Quad_biplane_B.Gain1 + Quad_biplane_B.Delay_d;

  /* Sum: '<S59>/Sum1' */
  rtb_Filter_i = Quad_biplane_B.v_des - Quad_biplane_B.Delay[19];

  /* Gain: '<S147>/Filter Coefficient' incorporates:
   *  Gain: '<S138>/Derivative Gain'
   *  Integrator: '<S139>/Filter'
   *  Sum: '<S139>/SumD'
   */
  Quad_biplane_B.FilterCoefficient_n = (Quad_biplane_P.PIDController1_D_f *
    rtb_Filter_i - Quad_biplane_X.Filter_CSTATE_db) *
    Quad_biplane_P.PIDController1_N_h;

  /* Sum: '<S153>/Sum' incorporates:
   *  Gain: '<S149>/Proportional Gain'
   *  Integrator: '<S144>/Integrator'
   */
  L = (Quad_biplane_P.PIDController1_P_j * rtb_Filter_i +
       Quad_biplane_X.Integrator_CSTATE_c) + Quad_biplane_B.FilterCoefficient_n;

  /* Saturate: '<S151>/Saturation' */
  if (L > Quad_biplane_P.PIDController1_UpperSaturatio_o) {
    /* Saturate: '<S151>/Saturation' */
    Quad_biplane_B.Saturation_c = Quad_biplane_P.PIDController1_UpperSaturatio_o;
  } else if (L < Quad_biplane_P.PIDController1_LowerSaturatio_e) {
    /* Saturate: '<S151>/Saturation' */
    Quad_biplane_B.Saturation_c = Quad_biplane_P.PIDController1_LowerSaturatio_e;
  } else {
    /* Saturate: '<S151>/Saturation' */
    Quad_biplane_B.Saturation_c = L;
  }

  /* End of Saturate: '<S151>/Saturation' */

  /* Sum: '<S60>/Sum' */
  Quad_biplane_B.Sum = Quad_biplane_B.Saturation_c - Quad_biplane_B.Delay[9];

  /* Gain: '<S198>/Filter Coefficient' incorporates:
   *  Gain: '<S189>/Derivative Gain'
   *  Integrator: '<S190>/Filter'
   *  Sum: '<S190>/SumD'
   */
  Quad_biplane_B.FilterCoefficient_ir = (Quad_biplane_P.PIDController_D_m *
    Quad_biplane_B.Sum - Quad_biplane_X.Filter_CSTATE_aw) *
    Quad_biplane_P.PIDController_N_n;

  /* Sum: '<S204>/Sum' incorporates:
   *  Gain: '<S200>/Proportional Gain'
   *  Integrator: '<S195>/Integrator'
   */
  Quad_biplane_B.Sum_d = (Quad_biplane_P.PIDController_P_e * Quad_biplane_B.Sum
    + Quad_biplane_X.Integrator_CSTATE_h) + Quad_biplane_B.FilterCoefficient_ir;

  /* Sum: '<S59>/Sum' */
  Quad_biplane_B.Sum_a = Quad_biplane_B.u_des - Quad_biplane_B.Delay[18];

  /* Gain: '<S99>/Filter Coefficient' incorporates:
   *  Gain: '<S90>/Derivative Gain'
   *  Integrator: '<S91>/Filter'
   *  Sum: '<S91>/SumD'
   */
  Quad_biplane_B.FilterCoefficient_d = (Quad_biplane_P.PIDController_D_mc *
    Quad_biplane_B.Sum_a - Quad_biplane_X.Filter_CSTATE_n) *
    Quad_biplane_P.PIDController_N_a;

  /* Sum: '<S105>/Sum' incorporates:
   *  Gain: '<S101>/Proportional Gain'
   *  Integrator: '<S96>/Integrator'
   */
  L = (Quad_biplane_P.PIDController_P_eb * Quad_biplane_B.Sum_a +
       Quad_biplane_X.Integrator_CSTATE_m) + Quad_biplane_B.FilterCoefficient_d;

  /* Saturate: '<S103>/Saturation' */
  if (L > Quad_biplane_P.PIDController_UpperSaturation_g) {
    L = Quad_biplane_P.PIDController_UpperSaturation_g;
  } else {
    if (L < Quad_biplane_P.PIDController_LowerSaturation_g) {
      L = Quad_biplane_P.PIDController_LowerSaturation_g;
    }
  }

  /* End of Saturate: '<S103>/Saturation' */

  /* Gain: '<S59>/Gain1' */
  Quad_biplane_B.Gain1_b = Quad_biplane_P.Gain1_Gain_l * L;

  /* If: '<S59>/If' */
  if (rtmIsMajorTimeStep(Quad_biplane_M)) {
    rtAction = (int8_T)!(Quad_biplane_B.transition == 1.0);
    Quad_biplane_DW.If_ActiveSubsystem_l = rtAction;
  } else {
    rtAction = Quad_biplane_DW.If_ActiveSubsystem_l;
  }

  switch (rtAction) {
   case 0:
    /* Outputs for IfAction SubSystem: '<S59>/If Action Subsystem' incorporates:
     *  ActionPort: '<S61>/Action Port'
     */
    Quad_biplane_IfActionSubsystem(Quad_biplane_B.q_des, &Quad_biplane_B.Merge_m);

    /* End of Outputs for SubSystem: '<S59>/If Action Subsystem' */
    break;

   case 1:
    /* Outputs for IfAction SubSystem: '<S59>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S62>/Action Port'
     */
    Quad_biplane_IfActionSubsystem(Quad_biplane_B.Gain1_b,
      &Quad_biplane_B.Merge_m);

    /* End of Outputs for SubSystem: '<S59>/If Action Subsystem1' */
    break;
  }

  /* End of If: '<S59>/If' */

  /* Sum: '<S60>/Sum1' */
  Quad_biplane_B.Sum1_o = Quad_biplane_B.Merge_m - Quad_biplane_B.Delay[10];

  /* Gain: '<S246>/Filter Coefficient' incorporates:
   *  Gain: '<S237>/Derivative Gain'
   *  Integrator: '<S238>/Filter'
   *  Sum: '<S238>/SumD'
   */
  Quad_biplane_B.FilterCoefficient_il = (Quad_biplane_P.PIDController2_D_l *
    Quad_biplane_B.Sum1_o - Quad_biplane_X.Filter_CSTATE_b) *
    Quad_biplane_P.PIDController2_N_g;

  /* Sum: '<S252>/Sum' incorporates:
   *  Gain: '<S248>/Proportional Gain'
   *  Integrator: '<S243>/Integrator'
   */
  Quad_biplane_B.Sum_f = (Quad_biplane_P.PIDController2_P_l *
    Quad_biplane_B.Sum1_o + Quad_biplane_X.Integrator_CSTATE_mn) +
    Quad_biplane_B.FilterCoefficient_il;
  if (rtmIsMajorTimeStep(Quad_biplane_M)) {
    /* Sum: '<S60>/Sum2' incorporates:
     *  Constant: '<S8>/Constant2'
     */
    rtb_Sum2 = Quad_biplane_P.Constant2_Value - Quad_biplane_B.Delay[11];

    /* Gain: '<S296>/Proportional Gain' */
    Quad_biplane_B.ProportionalGain_f = Quad_biplane_P.PIDController3_P_l *
      rtb_Sum2;

    /* Gain: '<S285>/Derivative Gain' */
    Quad_biplane_B.DerivativeGain_a = Quad_biplane_P.PIDController3_D_m *
      rtb_Sum2;
  }

  /* Gain: '<S294>/Filter Coefficient' incorporates:
   *  Integrator: '<S286>/Filter'
   *  Sum: '<S286>/SumD'
   */
  Quad_biplane_B.FilterCoefficient_b = (Quad_biplane_B.DerivativeGain_a -
    Quad_biplane_X.Filter_CSTATE_o) * Quad_biplane_P.PIDController3_N_n;

  /* Sum: '<S300>/Sum' incorporates:
   *  Integrator: '<S291>/Integrator'
   */
  Quad_biplane_B.Sum_g = (Quad_biplane_B.ProportionalGain_f +
    Quad_biplane_X.Integrator_CSTATE_j) + Quad_biplane_B.FilterCoefficient_b;

  /* MATLAB Function: '<S1>/MATLAB Function' */
  Quad_biplane_B.ssw = Quad_biplane_B.Sum1;
  L = Quad_biplane_B.Sum1 + Quad_biplane_B.Sum_d;
  rtb_RPMs[0] = fmax(0.0, (L + Quad_biplane_B.Sum_f) + Quad_biplane_B.Sum_g);
  CL = Quad_biplane_B.Sum1 - Quad_biplane_B.Sum_d;
  rtb_RPMs[1] = fmax(0.0, (CL + Quad_biplane_B.Sum_f) - Quad_biplane_B.Sum_g);
  rtb_RPMs[2] = fmax(0.0, (CL - Quad_biplane_B.Sum_f) + Quad_biplane_B.Sum_g);
  rtb_RPMs[3] = fmax(0.0, (L - Quad_biplane_B.Sum_f) - Quad_biplane_B.Sum_g);

  /* MATLAB Function: '<S619>/MATLAB Function' */
  Quad_biplane_MATLABFunction(rtb_RPMs[0], &Quad_biplane_B.sf_MATLABFunction_n);

  /* MATLAB Function: '<S620>/MATLAB Function' */
  Quad_biplane_MATLABFunction(rtb_RPMs[1], &Quad_biplane_B.sf_MATLABFunction_j);

  /* MATLAB Function: '<S621>/MATLAB Function' */
  Quad_biplane_MATLABFunction(rtb_RPMs[2], &Quad_biplane_B.sf_MATLABFunction_d);

  /* MATLAB Function: '<S622>/MATLAB Function' */
  Quad_biplane_MATLABFunction(rtb_RPMs[3], &Quad_biplane_B.sf_MATLABFunction_l);

  /* MATLAB Function: '<S613>/MATLAB Function2' incorporates:
   *  Constant: '<S613>/Constant'
   */
  Quad_biplane_B.Total_Rotor_Load[0] =
    ((Quad_biplane_B.sf_MATLABFunction_n.load[0] +
      Quad_biplane_B.sf_MATLABFunction_j.load[0]) +
     Quad_biplane_B.sf_MATLABFunction_d.load[0]) +
    Quad_biplane_B.sf_MATLABFunction_l.load[0];
  Quad_biplane_B.Total_Rotor_Load[1] =
    ((Quad_biplane_B.sf_MATLABFunction_n.load[1] +
      Quad_biplane_B.sf_MATLABFunction_j.load[1]) +
     Quad_biplane_B.sf_MATLABFunction_d.load[1]) +
    Quad_biplane_B.sf_MATLABFunction_l.load[1];
  Quad_biplane_B.Total_Rotor_Load[2] =
    -(((Quad_biplane_B.sf_MATLABFunction_n.load[2] +
        Quad_biplane_B.sf_MATLABFunction_j.load[2]) +
       Quad_biplane_B.sf_MATLABFunction_d.load[2]) +
      Quad_biplane_B.sf_MATLABFunction_l.load[2]);
  L = Quad_biplane_P.Quad.l * Quad_biplane_B.sf_MATLABFunction_n.load[2];
  CL = Quad_biplane_P.Quad.l * Quad_biplane_B.sf_MATLABFunction_j.load[2];
  Total_Rotor_Load_tmp = Quad_biplane_P.Quad.l *
    Quad_biplane_B.sf_MATLABFunction_d.load[2];
  Total_Rotor_Load_tmp_0 = Quad_biplane_P.Quad.l *
    Quad_biplane_B.sf_MATLABFunction_l.load[2];
  Quad_biplane_B.Total_Rotor_Load[3] = ((L - CL) - Total_Rotor_Load_tmp) +
    Total_Rotor_Load_tmp_0;
  Quad_biplane_B.Total_Rotor_Load[4] = ((L + CL) - Total_Rotor_Load_tmp) -
    Total_Rotor_Load_tmp_0;
  Quad_biplane_B.Total_Rotor_Load[5] =
    ((Quad_biplane_B.sf_MATLABFunction_n.load[5] -
      Quad_biplane_B.sf_MATLABFunction_j.load[5]) +
     Quad_biplane_B.sf_MATLABFunction_d.load[5]) -
    Quad_biplane_B.sf_MATLABFunction_l.load[5];
  if (rtmIsMajorTimeStep(Quad_biplane_M)) {
    /* Sqrt: '<S617>/Square Root' incorporates:
     *  Math: '<S617>/Math Function'
     *  Math: '<S617>/Math Function1'
     *  Math: '<S617>/Math Function2'
     *  Sqrt: '<S630>/Square Root'
     *  Sum: '<S617>/Add'
     *
     * About '<S617>/Math Function':
     *  Operator: magnitude^2
     *
     * About '<S617>/Math Function1':
     *  Operator: magnitude^2
     *
     * About '<S617>/Math Function2':
     *  Operator: magnitude^2
     */
    rtb_load_wing_idx_2 = sqrt((Quad_biplane_B.Delay[18] * Quad_biplane_B.Delay
      [18] + Quad_biplane_B.Delay[19] * Quad_biplane_B.Delay[19]) +
      Quad_biplane_B.Delay[20] * Quad_biplane_B.Delay[20]);

    /* Gain: '<S612>/Gain1' incorporates:
     *  Trigonometry: '<S612>/Atan2'
     */
    rtb_Gain1 = Quad_biplane_P.Gain1_Gain_b * rt_atan2d_snf
      (Quad_biplane_B.Delay[20], Quad_biplane_B.Delay[18]);

    /* MATLAB Function: '<S612>/Fuselage' incorporates:
     *  Sqrt: '<S617>/Square Root'
     */
    rtb_SquareRoot = 0.6128 * rtb_load_wing_idx_2 * rtb_load_wing_idx_2;
    if (rtb_Gain1 < 0.0) {
      D = fabs(rtb_Gain1);
      Total_Rotor_Load_tmp = D;
      Quad_biplane_sind(&Total_Rotor_Load_tmp);
      Total_Rotor_Load_tmp_0 = D;
      Quad_biplane_sind(&Total_Rotor_Load_tmp_0);
      Quad_biplane_cosd(&D);
      CL = -2.0 * Total_Rotor_Load_tmp * Total_Rotor_Load_tmp_0 * D;
    } else {
      D = fabs(rtb_Gain1);
      L = D;
      Quad_biplane_sind(&L);
      CL = D;
      Quad_biplane_sind(&CL);
      Quad_biplane_cosd(&D);
      CL = 2.0 * L * CL * D;
    }

    L = rtb_SquareRoot * 0.2 * CL;
    D = fabs(rtb_Gain1);
    h = D;
    Quad_biplane_sind(&h);
    i = D;
    Quad_biplane_sind(&i);
    Quad_biplane_sind(&D);
    D = (2.0 * h * i * D + CL * CL / 0.50265482457436694) * (rtb_SquareRoot *
      0.2);
    for (i_0 = 0; i_0 < 6; i_0++) {
      Quad_biplane_B.fuselage_load[i_0] = 0.0;
    }

    h = rtb_Gain1;
    Quad_biplane_sind(&h);
    i = rtb_Gain1;
    Quad_biplane_cosd(&i);
    Quad_biplane_B.fuselage_load[0] = L * h - D * i;
    h = rtb_Gain1;
    Quad_biplane_cosd(&h);
    i = rtb_Gain1;
    Quad_biplane_sind(&i);
    Quad_biplane_B.fuselage_load[2] = -L * h - D * i;
    Quad_biplane_B.fuselage_load[4] = rtb_SquareRoot * 0.2 * 0.0;

    /* End of MATLAB Function: '<S612>/Fuselage' */

    /* MATLAB Function: '<S614>/MATLAB Function' incorporates:
     *  Constant: '<S614>/Constant'
     */
    rtb_SquareRoot_0[1] = 0.0;
    rtb_SquareRoot_0[4] = R_tmp_tmp;
    rtb_SquareRoot_0[7] = rtb_Sum_m;
    rtb_SquareRoot_0[2] = 0.0;
    rtb_SquareRoot_0[5] = -sin(Quad_biplane_B.Delay[6]);
    rtb_SquareRoot_0[8] = R_tmp_tmp;
    c[0] = R_tmp_tmp_0;
    c[3] = 0.0;
    c[6] = -sin(Quad_biplane_B.Delay[7]);
    rtb_SquareRoot_0[0] = 1.0;
    c[1] = 0.0;
    rtb_SquareRoot_0[3] = 0.0;
    c[4] = 1.0;
    rtb_SquareRoot_0[6] = 0.0;
    c[7] = 0.0;
    c[2] = rtb_Sum_g_tmp;
    c[5] = 0.0;
    c[8] = R_tmp_tmp_0;
    R_tmp[0] = rtb_SquareRoot_tmp;
    R_tmp[3] = rtb_Filter_c_tmp;
    R_tmp[6] = 0.0;
    R_tmp[1] = -sin(Quad_biplane_B.Delay[8]);
    R_tmp[4] = rtb_SquareRoot_tmp;
    R_tmp[7] = 0.0;
    for (i_0 = 0; i_0 < 3; i_0++) {
      for (i_1 = 0; i_1 < 3; i_1++) {
        c_tmp = i_0 + 3 * i_1;
        R[c_tmp] = 0.0;
        R[c_tmp] += c[3 * i_1] * rtb_SquareRoot_0[i_0];
        R[c_tmp] += c[3 * i_1 + 1] * rtb_SquareRoot_0[i_0 + 3];
        R[c_tmp] += c[3 * i_1 + 2] * rtb_SquareRoot_0[i_0 + 6];
      }

      R_tmp[3 * i_0 + 2] = b[i_0];
    }

    P_ddot[0] = 0.0;
    P_ddot[1] = 0.0;
    P_ddot[2] = Quad_biplane_P.Quad.m * Quad_biplane_P.Quad.g;
    for (i_0 = 0; i_0 < 3; i_0++) {
      Weight_Force[i_0] = 0.0;
      for (i_1 = 0; i_1 < 3; i_1++) {
        c_tmp = i_0 + 3 * i_1;
        rtb_SquareRoot_0[c_tmp] = 0.0;
        rtb_SquareRoot_0[c_tmp] += R_tmp[3 * i_1] * R[i_0];
        rtb_SquareRoot_0[c_tmp] += R_tmp[3 * i_1 + 1] * R[i_0 + 3];
        rtb_SquareRoot_0[c_tmp] += R_tmp[3 * i_1 + 2] * R[i_0 + 6];
        Weight_Force[i_0] += rtb_SquareRoot_0[c_tmp] * P_ddot[i_1];
      }
    }

    Quad_biplane_B.Total_Weight_Load[0] = Weight_Force[0];
    Quad_biplane_B.Total_Weight_Load[1] = Weight_Force[1];
    Quad_biplane_B.Total_Weight_Load[2] = Weight_Force[2];
    Quad_biplane_B.Total_Weight_Load[3] = 0.0;
    Quad_biplane_B.Total_Weight_Load[4] = 0.0;
    Quad_biplane_B.Total_Weight_Load[5] = 0.0;

    /* Gain: '<S615>/Gain1' incorporates:
     *  Gain: '<S615>/Gain'
     *  Trigonometry: '<S615>/Atan2'
     */
    rtb_Gain1_i = rt_atan2d_snf(Quad_biplane_B.Delay[18],
      Quad_biplane_P.Gain_Gain * Quad_biplane_B.Delay[20]) *
      Quad_biplane_P.Gain1_Gain_a;

    /* Sqrt: '<S630>/Square Root' */
    rtb_SquareRoot_c = rtb_load_wing_idx_2;

    /* MATLAB Function: '<S615>/Wing Load1' incorporates:
     *  MATLAB Function: '<S615>/Wing Load2'
     */
    rtb_load_wing_idx_2 = 0.6128 * rtb_SquareRoot_c * rtb_SquareRoot_c;
    if ((rtb_Gain1_i >= -15.0) && (rtb_Gain1_i <= 15.0)) {
      CL = 4.9 * rtb_Gain1_i * 0.017453292519943295;
    } else if (rtb_Gain1_i < -15.0) {
      D = fabs(rtb_Gain1_i);
      Total_Rotor_Load_tmp = D;
      Quad_biplane_sind(&Total_Rotor_Load_tmp);
      Total_Rotor_Load_tmp_0 = D;
      Quad_biplane_sind(&Total_Rotor_Load_tmp_0);
      Quad_biplane_cosd(&D);
      CL = -2.0 * Total_Rotor_Load_tmp * Total_Rotor_Load_tmp_0 * D;
    } else {
      D = fabs(rtb_Gain1_i);
      L = D;
      Quad_biplane_sind(&L);
      CL = D;
      Quad_biplane_sind(&CL);
      Quad_biplane_cosd(&D);
      CL = 2.0 * L * CL * D;
    }

    for (i_0 = 0; i_0 < 6; i_0++) {
      rtb_load_wing_i[i_0] = 0.0;
    }

    D = fabs(rtb_Gain1_i);
    h = D;
    Quad_biplane_sind(&h);
    i = D;
    Quad_biplane_sind(&i);
    L = D;
    Quad_biplane_sind(&L);
    rtb_load_wing_i[0] = (2.0 * h * i * L + CL * CL / 17.341591447815659) *
      (rtb_load_wing_idx_2 * 0.754);
    rtb_load_wing_i[2] = rtb_load_wing_idx_2 * 0.754 * CL;
    rtb_load_wing_i[4] = rtb_load_wing_idx_2 * 0.754 * 0.3 * 0.0;

    /* End of MATLAB Function: '<S615>/Wing Load1' */

    /* MATLAB Function: '<S615>/Wing Load2' */
    if ((rtb_Gain1_i >= -15.0) && (rtb_Gain1_i <= 15.0)) {
      CL = 4.9 * rtb_Gain1_i * 0.017453292519943295;
    } else if (rtb_Gain1_i < -15.0) {
      Total_Rotor_Load_tmp = D;
      Quad_biplane_sind(&Total_Rotor_Load_tmp);
      Total_Rotor_Load_tmp_0 = D;
      Quad_biplane_sind(&Total_Rotor_Load_tmp_0);
      g = D;
      Quad_biplane_cosd(&g);
      CL = -2.0 * Total_Rotor_Load_tmp * Total_Rotor_Load_tmp_0 * g;
    } else {
      L = D;
      Quad_biplane_sind(&L);
      CL = D;
      Quad_biplane_sind(&CL);
      rtb_SquareRoot = D;
      Quad_biplane_cosd(&rtb_SquareRoot);
      CL = 2.0 * L * CL * rtb_SquareRoot;
    }

    h = D;
    Quad_biplane_sind(&h);
    i = D;
    Quad_biplane_sind(&i);
    Quad_biplane_sind(&D);
    D = (2.0 * h * i * D + CL * CL / 17.341591447815659) * (rtb_load_wing_idx_2 *
      0.754);
    rtb_load_wing_idx_2 = rtb_load_wing_idx_2 * 0.754 * CL;

    /* MATLAB Function: '<S615>/MATLAB Function' */
    L = rtb_Gain1_i;
    Quad_biplane_cosd(&L);
    CL = rtb_Gain1_i;
    Quad_biplane_sind(&CL);
    rtb_SquareRoot = rtb_Gain1_i;
    Quad_biplane_cosd(&rtb_SquareRoot);
    Total_Rotor_Load_tmp = rtb_Gain1_i;
    Quad_biplane_sind(&Total_Rotor_Load_tmp);
    Total_Rotor_Load_tmp_0 = rtb_Gain1_i;
    Quad_biplane_sind(&Total_Rotor_Load_tmp_0);
    g = rtb_Gain1_i;
    Quad_biplane_cosd(&g);
    h = rtb_Gain1_i;
    Quad_biplane_sind(&h);
    i = rtb_Gain1_i;
    Quad_biplane_cosd(&i);
    Quad_biplane_B.Total_wing_load[0] = -(rtb_load_wing_i[2] * L +
      rtb_load_wing_i[0] * CL) - (rtb_load_wing_idx_2 * rtb_SquareRoot + D *
      Total_Rotor_Load_tmp);
    Quad_biplane_B.Total_wing_load[1] = 0.0;
    Quad_biplane_B.Total_wing_load[2] = (-rtb_load_wing_i[2] *
      Total_Rotor_Load_tmp_0 + rtb_load_wing_i[0] * g) + (-rtb_load_wing_idx_2 *
      h + D * i);
    Quad_biplane_B.Total_wing_load[3] = 0.0;
    Quad_biplane_B.Total_wing_load[4] = 0.0;
    Quad_biplane_B.Total_wing_load[5] = 0.0;
  }

  for (i_0 = 0; i_0 < 6; i_0++) {
    /* Sum: '<S4>/Add' */
    Quad_biplane_B.Add[i_0] = ((Quad_biplane_B.Total_Rotor_Load[i_0] +
      Quad_biplane_B.fuselage_load[i_0]) + Quad_biplane_B.Total_Weight_Load[i_0])
      + Quad_biplane_B.Total_wing_load[i_0];
  }

  /* MATLAB Function: '<S2>/Translational Dynamics' incorporates:
   *  Constant: '<S2>/Constant'
   */
  rtb_SquareRoot_0[1] = 0.0;
  rtb_SquareRoot_0[4] = R_tmp_tmp;
  rtb_SquareRoot_0[7] = rtb_Sum_m;
  rtb_SquareRoot_0[2] = 0.0;
  rtb_SquareRoot_0[5] = -sin(Quad_biplane_B.Delay[6]);
  rtb_SquareRoot_0[8] = R_tmp_tmp;
  c[0] = R_tmp_tmp_0;
  c[3] = 0.0;
  c[6] = -sin(Quad_biplane_B.Delay[7]);
  rtb_SquareRoot_0[0] = 1.0;
  c[1] = 0.0;
  rtb_SquareRoot_0[3] = 0.0;
  c[4] = 1.0;
  rtb_SquareRoot_0[6] = 0.0;
  c[7] = 0.0;
  c[2] = rtb_Sum_g_tmp;
  c[5] = 0.0;
  c[8] = R_tmp_tmp_0;
  R_tmp[0] = rtb_SquareRoot_tmp;
  R_tmp[3] = rtb_Filter_c_tmp;
  R_tmp[6] = 0.0;
  R_tmp[1] = -sin(Quad_biplane_B.Delay[8]);
  R_tmp[4] = rtb_SquareRoot_tmp;
  R_tmp[7] = 0.0;
  for (i_0 = 0; i_0 < 3; i_0++) {
    for (i_1 = 0; i_1 < 3; i_1++) {
      c_tmp = i_0 + 3 * i_1;
      R[c_tmp] = 0.0;
      R[c_tmp] += c[3 * i_1] * rtb_SquareRoot_0[i_0];
      R[c_tmp] += c[3 * i_1 + 1] * rtb_SquareRoot_0[i_0 + 3];
      R[c_tmp] += c[3 * i_1 + 2] * rtb_SquareRoot_0[i_0 + 6];
    }

    R_tmp[3 * i_0 + 2] = b[i_0];
  }

  P_ddot[0] = Quad_biplane_B.Delay[3];
  P_ddot[1] = Quad_biplane_B.Delay[4];
  P_ddot[2] = Quad_biplane_B.Delay[5];
  for (i_0 = 0; i_0 < 3; i_0++) {
    Weight_Force[i_0] = 0.0;
    for (i_1 = 0; i_1 < 3; i_1++) {
      c_tmp = i_0 + 3 * i_1;
      rtb_SquareRoot_0[c_tmp] = 0.0;
      rtb_SquareRoot_0[c_tmp] += R_tmp[3 * i_1] * R[i_0];
      rtb_SquareRoot_0[c_tmp] += R_tmp[3 * i_1 + 1] * R[i_0 + 3];
      rtb_SquareRoot_0[c_tmp] += R_tmp[3 * i_1 + 2] * R[i_0 + 6];
      Weight_Force[i_0] += rtb_SquareRoot_0[c_tmp] * P_ddot[i_1];
    }
  }

  rtb_SquareRoot = 1.0 / Quad_biplane_P.Quad.m;
  Quad_biplane_B.a_body[0] = (Quad_biplane_B.Delay[11] * Weight_Force[1] -
    Quad_biplane_B.Delay[10] * Weight_Force[2]) + rtb_SquareRoot *
    Quad_biplane_B.Add[0];
  Quad_biplane_B.a_body[1] = (Quad_biplane_B.Delay[9] * Weight_Force[2] -
    Quad_biplane_B.Delay[11] * Weight_Force[0]) + rtb_SquareRoot *
    Quad_biplane_B.Add[1];
  Quad_biplane_B.a_body[2] = (Quad_biplane_B.Delay[10] * Weight_Force[0] -
    Quad_biplane_B.Delay[9] * Weight_Force[1]) + rtb_SquareRoot *
    Quad_biplane_B.Add[2];

  /* MATLAB Function: '<S2>/Rotational Dynamics' incorporates:
   *  Constant: '<S2>/Constant'
   */
  c[0] = 0.0;
  c[3] = Quad_biplane_B.Delay[11];
  c[6] = -Quad_biplane_B.Delay[10];
  c[1] = -Quad_biplane_B.Delay[11];
  c[4] = 0.0;
  c[7] = Quad_biplane_B.Delay[9];
  c[2] = Quad_biplane_B.Delay[10];
  c[5] = -Quad_biplane_B.Delay[9];
  c[8] = 0.0;
  P_ddot[0] = Quad_biplane_B.Delay[9];
  P_ddot[1] = Quad_biplane_B.Delay[10];
  P_ddot[2] = Quad_biplane_B.Delay[11];
  tmp[0] = Quad_biplane_B.Add[3];
  tmp[1] = Quad_biplane_B.Add[4];
  tmp[2] = Quad_biplane_B.Add[5];
  for (i_0 = 0; i_0 < 3; i_0++) {
    Weight_Force[i_0] = 0.0;
    for (i_1 = 0; i_1 < 3; i_1++) {
      c_tmp = i_0 + 3 * i_1;
      R_tmp[c_tmp] = 0.0;
      R_tmp[c_tmp] += Quad_biplane_P.Quad.J[3 * i_1] * c[i_0];
      R_tmp[c_tmp] += Quad_biplane_P.Quad.J[3 * i_1 + 1] * c[i_0 + 3];
      R_tmp[c_tmp] += Quad_biplane_P.Quad.J[3 * i_1 + 2] * c[i_0 + 6];
      Weight_Force[i_0] += R_tmp[c_tmp] * P_ddot[i_1];
    }

    R_0[i_0] = Weight_Force[i_0] + tmp[i_0];
  }

  for (i_0 = 0; i_0 < 3; i_0++) {
    Quad_biplane_B.om_dot[i_0] = 0.0;
    Quad_biplane_B.om_dot[i_0] += Quad_biplane_P.Quad.J_inv[i_0] * R_0[0];
    Quad_biplane_B.om_dot[i_0] += Quad_biplane_P.Quad.J_inv[i_0 + 3] * R_0[1];
    Quad_biplane_B.om_dot[i_0] += Quad_biplane_P.Quad.J_inv[i_0 + 6] * R_0[2];
  }

  /* End of MATLAB Function: '<S2>/Rotational Dynamics' */
  if (rtmIsMajorTimeStep(Quad_biplane_M)) {
    /* Delay: '<S2>/Delay' */
    Quad_biplane_B.Delay_f = Quad_biplane_DW.Delay_DSTATE_a;
  }

  /* Integrator: '<S2>/Integrator2' */
  if (rtmIsMajorTimeStep(Quad_biplane_M)) {
    zcEvent = rt_ZCFcn(ANY_ZERO_CROSSING,
                       &Quad_biplane_PrevZCX.Integrator2_Reset_ZCE,
                       (Quad_biplane_B.Delay_f));

    /* evaluate zero-crossings and the level of the reset signal */
    if ((zcEvent != NO_ZCEVENT) || (Quad_biplane_B.Delay_f != 0.0)) {
      Quad_biplane_X.Integrator2_CSTATE = Quad_biplane_P.Integrator2_IC;
    }
  }

  /* MATLAB Function: '<S2>/Transform1' */
  rtb_SquareRoot_0[1] = 0.0;
  rtb_SquareRoot_0[4] = R_tmp_tmp;
  rtb_SquareRoot_0[7] = rtb_Sum_m;
  rtb_SquareRoot_0[2] = 0.0;
  rtb_SquareRoot_0[5] = -sin(Quad_biplane_B.Delay[6]);
  rtb_SquareRoot_0[8] = R_tmp_tmp;
  c[0] = R_tmp_tmp_0;
  c[3] = 0.0;
  c[6] = -sin(Quad_biplane_B.Delay[7]);
  rtb_SquareRoot_0[0] = 1.0;
  c[1] = 0.0;
  rtb_SquareRoot_0[3] = 0.0;
  c[4] = 1.0;
  rtb_SquareRoot_0[6] = 0.0;
  c[7] = 0.0;
  c[2] = rtb_Sum_g_tmp;
  c[5] = 0.0;
  c[8] = R_tmp_tmp_0;
  R_tmp[0] = rtb_SquareRoot_tmp;
  R_tmp[3] = rtb_Filter_c_tmp;
  R_tmp[6] = 0.0;
  R_tmp[1] = -sin(Quad_biplane_B.Delay[8]);
  R_tmp[4] = rtb_SquareRoot_tmp;
  R_tmp[7] = 0.0;
  for (i_0 = 0; i_0 < 3; i_0++) {
    for (i_1 = 0; i_1 < 3; i_1++) {
      c_tmp = i_0 + 3 * i_1;
      R[c_tmp] = 0.0;
      R[c_tmp] += c[3 * i_1] * rtb_SquareRoot_0[i_0];
      R[c_tmp] += c[3 * i_1 + 1] * rtb_SquareRoot_0[i_0 + 3];
      R[c_tmp] += c[3 * i_1 + 2] * rtb_SquareRoot_0[i_0 + 6];
    }

    R_tmp[3 * i_0 + 2] = b[i_0];
  }

  /* SignalConversion generated from: '<S610>/ SFunction ' incorporates:
   *  Integrator: '<S2>/Integrator'
   *  Integrator: '<S2>/Integrator1'
   *  Integrator: '<S2>/Integrator2'
   *  MATLAB Function: '<S2>/Transform1'
   */
  P_ddot[0] = Quad_biplane_X.Integrator_CSTATE_p;
  P_ddot[1] = Quad_biplane_X.Integrator1_CSTATE;
  P_ddot[2] = Quad_biplane_X.Integrator2_CSTATE;

  /* MATLAB Function: '<S2>/Transform1' incorporates:
   *  Integrator: '<S2>/Integrator3'
   *  Integrator: '<S2>/Integrator4'
   *  Integrator: '<S2>/Integrator5'
   *  MATLAB Function: '<S8>/MATLAB Function'
   */
  for (i_0 = 0; i_0 < 3; i_0++) {
    Quad_biplane_B.P_dot_new[i_0] = 0.0;
    for (i_1 = 0; i_1 < 3; i_1++) {
      c_tmp = i_0 + 3 * i_1;
      rtb_SquareRoot_0[c_tmp] = 0.0;
      rtb_SquareRoot_0[c_tmp] += R_tmp[3 * i_0] * R[i_1];
      rtb_SquareRoot_0[c_tmp] += R_tmp[3 * i_0 + 1] * R[i_1 + 3];
      rtb_SquareRoot_0[c_tmp] += R_tmp[3 * i_0 + 2] * R[i_1 + 6];
      Quad_biplane_B.P_dot_new[i_0] += rtb_SquareRoot_0[c_tmp] * P_ddot[i_1];
    }
  }

  rtb_SquareRoot = tan(Quad_biplane_B.Delay[7]);
  c[0] = 1.0;
  c[3] = rtb_Sum_m * rtb_SquareRoot;
  c[6] = R_tmp_tmp * rtb_SquareRoot;
  c[1] = 0.0;
  c[4] = R_tmp_tmp;
  c[7] = -sin(Quad_biplane_B.Delay[6]);
  c[2] = 0.0;
  c[5] = 1.0 / R_tmp_tmp_0 * rtb_Sum_m;
  c[8] = 1.0 / cos(Quad_biplane_B.Delay[7]) * R_tmp_tmp;
  for (i_0 = 0; i_0 < 3; i_0++) {
    Quad_biplane_B.Eang_dot_new[i_0] = 0.0;
    Quad_biplane_B.Eang_dot_new[i_0] += c[i_0] *
      Quad_biplane_X.Integrator3_CSTATE;
    Quad_biplane_B.Eang_dot_new[i_0] += c[i_0 + 3] *
      Quad_biplane_X.Integrator4_CSTATE;
    Quad_biplane_B.Eang_dot_new[i_0] += c[i_0 + 6] *
      Quad_biplane_X.Integrator5_CSTATE;
  }

  /* Integrator: '<S2>/Integrator8' */
  if (rtmIsMajorTimeStep(Quad_biplane_M)) {
    zcEvent = rt_ZCFcn(ANY_ZERO_CROSSING,
                       &Quad_biplane_PrevZCX.Integrator8_Reset_ZCE,
                       (Quad_biplane_B.Delay_f));

    /* evaluate zero-crossings and the level of the reset signal */
    if ((zcEvent != NO_ZCEVENT) || (Quad_biplane_B.Delay_f != 0.0)) {
      Quad_biplane_X.Integrator8_CSTATE = Quad_biplane_P.Integrator8_IC;
    }
  }

  /* MATLAB Function: '<S2>/State_update' incorporates:
   *  Integrator: '<S2>/Integrator'
   *  Integrator: '<S2>/Integrator1'
   *  Integrator: '<S2>/Integrator10'
   *  Integrator: '<S2>/Integrator11'
   *  Integrator: '<S2>/Integrator2'
   *  Integrator: '<S2>/Integrator3'
   *  Integrator: '<S2>/Integrator4'
   *  Integrator: '<S2>/Integrator5'
   *  Integrator: '<S2>/Integrator6'
   *  Integrator: '<S2>/Integrator7'
   *  Integrator: '<S2>/Integrator8'
   *  Integrator: '<S2>/Integrator9'
   */
  Quad_biplane_B.States_New[2] = Quad_biplane_X.Integrator8_CSTATE;
  rtb_SquareRoot_0[1] = 0.0;
  rtb_SquareRoot_0[4] = R_tmp_tmp;
  rtb_SquareRoot_0[7] = rtb_Sum_m;
  rtb_SquareRoot_0[2] = 0.0;
  rtb_SquareRoot_0[5] = -sin(Quad_biplane_B.Delay[6]);
  rtb_SquareRoot_0[8] = R_tmp_tmp;
  c[0] = R_tmp_tmp_0;
  c[3] = 0.0;
  c[6] = -sin(Quad_biplane_B.Delay[7]);
  rtb_SquareRoot_0[0] = 1.0;
  c[1] = 0.0;
  rtb_SquareRoot_0[3] = 0.0;
  c[4] = 1.0;
  Quad_biplane_B.States_New[5] = Quad_biplane_B.P_dot_new[2];
  Quad_biplane_B.States_New[20] = Quad_biplane_X.Integrator2_CSTATE;
  rtb_SquareRoot_0[6] = 0.0;
  c[7] = 0.0;
  c[2] = rtb_Sum_g_tmp;
  c[5] = 0.0;
  c[8] = R_tmp_tmp_0;
  R_tmp[0] = rtb_SquareRoot_tmp;
  R_tmp[3] = rtb_Filter_c_tmp;
  R_tmp[6] = 0.0;
  R_tmp[1] = -sin(Quad_biplane_B.Delay[8]);
  R_tmp[4] = rtb_SquareRoot_tmp;
  R_tmp[7] = 0.0;
  for (i_0 = 0; i_0 < 3; i_0++) {
    for (i_1 = 0; i_1 < 3; i_1++) {
      c_tmp = i_0 + 3 * i_1;
      R[c_tmp] = 0.0;
      R[c_tmp] += c[3 * i_1] * rtb_SquareRoot_0[i_0];
      R[c_tmp] += c[3 * i_1 + 1] * rtb_SquareRoot_0[i_0 + 3];
      R[c_tmp] += c[3 * i_1 + 2] * rtb_SquareRoot_0[i_0 + 6];
    }

    R_tmp[3 * i_0 + 2] = b[i_0];
  }

  for (i_0 = 0; i_0 < 3; i_0++) {
    P_ddot[i_0] = 0.0;
    for (i_1 = 0; i_1 < 3; i_1++) {
      c_tmp = i_0 + 3 * i_1;
      rtb_SquareRoot_0[c_tmp] = 0.0;
      rtb_SquareRoot_0[c_tmp] += R_tmp[3 * i_0] * R[i_1];
      rtb_SquareRoot_0[c_tmp] += R_tmp[3 * i_0 + 1] * R[i_1 + 3];
      rtb_SquareRoot_0[c_tmp] += R_tmp[3 * i_0 + 2] * R[i_1 + 6];
      P_ddot[i_0] += rtb_SquareRoot_0[c_tmp] * Quad_biplane_B.a_body[i_1];
    }
  }

  Quad_biplane_B.reset_flag = 0.0;
  if (Quad_biplane_X.Integrator8_CSTATE > 0.0) {
    Quad_biplane_B.States_New[2] = 0.0;
    Quad_biplane_B.States_New[5] = 0.0;
    P_ddot[2] = 0.0;
    Quad_biplane_B.States_New[20] = 0.0;
    Quad_biplane_B.reset_flag = 1.0;
  }

  Quad_biplane_B.States_New[0] = Quad_biplane_X.Integrator6_CSTATE;
  Quad_biplane_B.States_New[1] = Quad_biplane_X.Integrator7_CSTATE;
  Quad_biplane_B.States_New[3] = Quad_biplane_B.P_dot_new[0];
  Quad_biplane_B.States_New[4] = Quad_biplane_B.P_dot_new[1];
  Quad_biplane_B.States_New[6] = Quad_biplane_X.Integrator9_CSTATE;
  Quad_biplane_B.States_New[7] = Quad_biplane_X.Integrator10_CSTATE;
  Quad_biplane_B.States_New[8] = Quad_biplane_X.Integrator11_CSTATE;
  Quad_biplane_B.States_New[9] = Quad_biplane_X.Integrator3_CSTATE;
  Quad_biplane_B.States_New[10] = Quad_biplane_X.Integrator4_CSTATE;
  Quad_biplane_B.States_New[11] = Quad_biplane_X.Integrator5_CSTATE;
  Quad_biplane_B.States_New[12] = P_ddot[0];
  Quad_biplane_B.States_New[13] = P_ddot[1];
  Quad_biplane_B.States_New[14] = P_ddot[2];
  Quad_biplane_B.States_New[15] = Quad_biplane_B.om_dot[0];
  Quad_biplane_B.States_New[16] = Quad_biplane_B.om_dot[1];
  Quad_biplane_B.States_New[17] = Quad_biplane_B.om_dot[2];
  Quad_biplane_B.States_New[18] = Quad_biplane_X.Integrator_CSTATE_p;
  Quad_biplane_B.States_New[19] = Quad_biplane_X.Integrator1_CSTATE;
  Quad_biplane_B.States_New[21] = Quad_biplane_B.Eang_dot_new[0];
  Quad_biplane_B.States_New[22] = Quad_biplane_B.Eang_dot_new[1];
  Quad_biplane_B.States_New[23] = Quad_biplane_B.Eang_dot_new[2];

  /* Gain: '<Root>/Gain1' */
  Quad_biplane_B.Gain1_d = Quad_biplane_P.Gain1_Gain_bx *
    Quad_biplane_B.States_New[2];
  if (rtmIsMajorTimeStep(Quad_biplane_M)) {
  }

  /* Gain: '<Root>/Gain' */
  Quad_biplane_B.Gain = Quad_biplane_P.Gain_Gain_m * Quad_biplane_B.States_New[5];
  if (rtmIsMajorTimeStep(Quad_biplane_M)) {
  }

  /* Gain: '<Root>/Gain2' */
  Quad_biplane_B.Gain2 = Quad_biplane_P.Gain2_Gain * Quad_biplane_B.States_New
    [20];
  if (rtmIsMajorTimeStep(Quad_biplane_M)) {
  }

  /* Gain: '<Root>/Gain3' */
  Quad_biplane_B.Gain3 = Quad_biplane_P.Gain3_Gain * Quad_biplane_B.States_New[7];
  if (rtmIsMajorTimeStep(Quad_biplane_M)) {
  }

  /* Gain: '<S1>/Gain' */
  Quad_biplane_B.Gain_c[0] = Quad_biplane_P.Gain_Gain_k * rtb_RPMs[0];
  Quad_biplane_B.Gain_c[1] = Quad_biplane_P.Gain_Gain_k * rtb_RPMs[1];
  Quad_biplane_B.Gain_c[2] = Quad_biplane_P.Gain_Gain_k * rtb_RPMs[2];
  Quad_biplane_B.Gain_c[3] = Quad_biplane_P.Gain_Gain_k * rtb_RPMs[3];
  if (rtmIsMajorTimeStep(Quad_biplane_M)) {
  }

  /* Gain: '<S39>/Integral Gain' */
  Quad_biplane_B.IntegralGain = Quad_biplane_P.PIDController1_I * rtb_Sum_g;
  if (rtmIsMajorTimeStep(Quad_biplane_M)) {
  }

  /* Gain: '<S93>/Integral Gain' */
  Quad_biplane_B.IntegralGain_e = Quad_biplane_P.PIDController_I *
    Quad_biplane_B.Sum_a;

  /* Gain: '<S141>/Integral Gain' */
  Quad_biplane_B.IntegralGain_k = Quad_biplane_P.PIDController1_I_j *
    rtb_Filter_i;
  if (rtmIsMajorTimeStep(Quad_biplane_M)) {
  }

  /* Gain: '<S192>/Integral Gain' */
  Quad_biplane_B.IntegralGain_g = Quad_biplane_P.PIDController_I_c *
    Quad_biplane_B.Sum;

  /* Gain: '<S240>/Integral Gain' */
  Quad_biplane_B.IntegralGain_l = Quad_biplane_P.PIDController2_I_j *
    Quad_biplane_B.Sum1_o;
  if (rtmIsMajorTimeStep(Quad_biplane_M)) {
    /* Gain: '<S288>/Integral Gain' */
    Quad_biplane_B.IntegralGain_p = Quad_biplane_P.PIDController3_I * rtb_Sum2;

    /* Gain: '<S391>/Integral Gain' */
    Quad_biplane_B.IntegralGain_m = Quad_biplane_P.PIDController1_I_d * rtb_Sum1;
  }

  /* Sum: '<S309>/Sum' */
  rtb_Sum_m = Quad_biplane_B.X_desired - Quad_biplane_B.Delay[0];

  /* Gain: '<S343>/Integral Gain' */
  Quad_biplane_B.IntegralGain_h = Quad_biplane_P.PIDController_I_a * rtb_Sum_m;

  /* Gain: '<S349>/Filter Coefficient' incorporates:
   *  Gain: '<S340>/Derivative Gain'
   *  Integrator: '<S341>/Filter'
   *  Sum: '<S341>/SumD'
   */
  Quad_biplane_B.FilterCoefficient_h = (Quad_biplane_P.PIDController_D_h *
    rtb_Sum_m - Quad_biplane_X.Filter_CSTATE_f) *
    Quad_biplane_P.PIDController_N_ah;

  /* Gain: '<S439>/Integral Gain' */
  Quad_biplane_B.IntegralGain_gm = Quad_biplane_P.PIDController2_I_g *
    rtb_Sum2_i;

  /* Gain: '<S487>/Integral Gain' */
  Quad_biplane_B.IntegralGain_e2 = Quad_biplane_P.PIDController3_I_g * rtb_Sum3;
  if (rtmIsMajorTimeStep(Quad_biplane_M)) {
  }

  /* Gain: '<S588>/Integral Gain' */
  Quad_biplane_B.IntegralGain_i = Quad_biplane_P.PIDController_I_l * rtb_Clock;
  if (rtmIsMajorTimeStep(Quad_biplane_M)) {
  }

  /* Gain: '<S619>/Gain' */
  Quad_biplane_B.Gain_b = Quad_biplane_P.Gain_Gain_c *
    Quad_biplane_B.sf_MATLABFunction_n.load[5];
  if (rtmIsMajorTimeStep(Quad_biplane_M)) {
  }

  /* Gain: '<S620>/Gain' */
  Quad_biplane_B.Gain_e = Quad_biplane_P.Gain_Gain_d *
    Quad_biplane_B.sf_MATLABFunction_j.load[5];
  if (rtmIsMajorTimeStep(Quad_biplane_M)) {
  }

  /* Gain: '<S621>/Gain' */
  Quad_biplane_B.Gain_k = Quad_biplane_P.Gain_Gain_g *
    Quad_biplane_B.sf_MATLABFunction_d.load[5];
  if (rtmIsMajorTimeStep(Quad_biplane_M)) {
  }

  /* Gain: '<S622>/Gain' */
  Quad_biplane_B.Gain_a = Quad_biplane_P.Gain_Gain_d0 *
    Quad_biplane_B.sf_MATLABFunction_l.load[5];
  if (rtmIsMajorTimeStep(Quad_biplane_M)) {
  }

  if (rtmIsMajorTimeStep(Quad_biplane_M)) {
    /* Matfile logging */
    rt_UpdateTXYLogVars(Quad_biplane_M->rtwLogInfo, (Quad_biplane_M->Timing.t));
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep(Quad_biplane_M)) {
    if (rtmIsMajorTimeStep(Quad_biplane_M)) {
      /* Update for Delay: '<Root>/Delay' */
      memcpy(&Quad_biplane_DW.Delay_DSTATE[0], &Quad_biplane_B.States_New[0],
             24U * sizeof(real_T));

      /* Update for Delay: '<S1>/Delay' */
      Quad_biplane_DW.Delay_DSTATE_m = Quad_biplane_B.ssw;

      /* Update for Delay: '<S2>/Delay' */
      Quad_biplane_DW.Delay_DSTATE_a = Quad_biplane_B.reset_flag;
    }
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep(Quad_biplane_M)) {
    /* signal main to stop simulation */
    {                                  /* Sample time: [0.0s, 0.0s] */
      if ((rtmGetTFinal(Quad_biplane_M)!=-1) &&
          !((rtmGetTFinal(Quad_biplane_M)-(((Quad_biplane_M->Timing.clockTick1+
               Quad_biplane_M->Timing.clockTickH1* 4294967296.0)) * 0.001)) >
            (((Quad_biplane_M->Timing.clockTick1+
               Quad_biplane_M->Timing.clockTickH1* 4294967296.0)) * 0.001) *
            (DBL_EPSILON))) {
        rtmSetErrorStatus(Quad_biplane_M, "Simulation finished");
      }
    }

    rt_ertODEUpdateContinuousStates(&Quad_biplane_M->solverInfo);

    /* Update absolute time for base rate */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick0 and the high bits
     * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++Quad_biplane_M->Timing.clockTick0)) {
      ++Quad_biplane_M->Timing.clockTickH0;
    }

    Quad_biplane_M->Timing.t[0] = rtsiGetSolverStopTime
      (&Quad_biplane_M->solverInfo);

    {
      /* Update absolute timer for sample time: [0.001s, 0.0s] */
      /* The "clockTick1" counts the number of times the code of this task has
       * been executed. The resolution of this integer timer is 0.001, which is the step size
       * of the task. Size of "clockTick1" ensures timer will not overflow during the
       * application lifespan selected.
       * Timer of this task consists of two 32 bit unsigned integers.
       * The two integers represent the low bits Timing.clockTick1 and the high bits
       * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
       */
      Quad_biplane_M->Timing.clockTick1++;
      if (!Quad_biplane_M->Timing.clockTick1) {
        Quad_biplane_M->Timing.clockTickH1++;
      }
    }
  }                                    /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void Quad_biplane_derivatives(void)
{
  XDot_Quad_biplane_T *_rtXdot;
  _rtXdot = ((XDot_Quad_biplane_T *) Quad_biplane_M->derivs);

  /* Derivatives for Integrator: '<S394>/Integrator' */
  _rtXdot->Integrator_CSTATE = Quad_biplane_B.IntegralGain_m;

  /* Derivatives for Integrator: '<S389>/Filter' */
  _rtXdot->Filter_CSTATE = Quad_biplane_B.FilterCoefficient;

  /* Derivatives for Integrator: '<S591>/Integrator' */
  _rtXdot->Integrator_CSTATE_b = Quad_biplane_B.IntegralGain_i;

  /* Derivatives for Integrator: '<S586>/Filter' */
  _rtXdot->Filter_CSTATE_p = Quad_biplane_B.FilterCoefficient_j;

  /* Derivatives for If: '<S310>/If' */
  {
    real_T *dx;
    int_T i;
    dx = &(((XDot_Quad_biplane_T *) Quad_biplane_M->derivs)
           ->Integrator_CSTATE_c5);
    for (i=0; i < 2; i++) {
      dx[i] = 0.0;
    }
  }

  if (Quad_biplane_DW.If_ActiveSubsystem == 1) {
    /* Derivatives for IfAction SubSystem: '<S310>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S509>/Action Port'
     */
    /* Derivatives for Integrator: '<S543>/Integrator' */
    _rtXdot->Integrator_CSTATE_c5 = Quad_biplane_B.IntegralGain_f;

    /* Derivatives for Integrator: '<S538>/Filter' */
    _rtXdot->Filter_CSTATE_fr = Quad_biplane_B.FilterCoefficient_p;

    /* End of Derivatives for SubSystem: '<S310>/If Action Subsystem2' */
  }

  /* End of Derivatives for If: '<S310>/If' */

  /* Derivatives for Integrator: '<S442>/Integrator' */
  _rtXdot->Integrator_CSTATE_d = Quad_biplane_B.IntegralGain_gm;

  /* Derivatives for Integrator: '<S437>/Filter' */
  _rtXdot->Filter_CSTATE_a = Quad_biplane_B.FilterCoefficient_f;

  /* Derivatives for Integrator: '<S490>/Integrator' */
  _rtXdot->Integrator_CSTATE_n = Quad_biplane_B.IntegralGain_e2;

  /* Derivatives for Integrator: '<S485>/Filter' */
  _rtXdot->Filter_CSTATE_d = Quad_biplane_B.FilterCoefficient_e;

  /* Derivatives for Integrator: '<S42>/Integrator' */
  _rtXdot->Integrator_CSTATE_n4 = Quad_biplane_B.IntegralGain;

  /* Derivatives for Integrator: '<S37>/Filter' */
  _rtXdot->Filter_CSTATE_k = Quad_biplane_B.FilterCoefficient_i;

  /* Derivatives for Integrator: '<S144>/Integrator' */
  _rtXdot->Integrator_CSTATE_c = Quad_biplane_B.IntegralGain_k;

  /* Derivatives for Integrator: '<S139>/Filter' */
  _rtXdot->Filter_CSTATE_db = Quad_biplane_B.FilterCoefficient_n;

  /* Derivatives for Integrator: '<S195>/Integrator' */
  _rtXdot->Integrator_CSTATE_h = Quad_biplane_B.IntegralGain_g;

  /* Derivatives for Integrator: '<S190>/Filter' */
  _rtXdot->Filter_CSTATE_aw = Quad_biplane_B.FilterCoefficient_ir;

  /* Derivatives for Integrator: '<S96>/Integrator' */
  _rtXdot->Integrator_CSTATE_m = Quad_biplane_B.IntegralGain_e;

  /* Derivatives for Integrator: '<S91>/Filter' */
  _rtXdot->Filter_CSTATE_n = Quad_biplane_B.FilterCoefficient_d;

  /* Derivatives for Integrator: '<S243>/Integrator' */
  _rtXdot->Integrator_CSTATE_mn = Quad_biplane_B.IntegralGain_l;

  /* Derivatives for Integrator: '<S238>/Filter' */
  _rtXdot->Filter_CSTATE_b = Quad_biplane_B.FilterCoefficient_il;

  /* Derivatives for Integrator: '<S291>/Integrator' */
  _rtXdot->Integrator_CSTATE_j = Quad_biplane_B.IntegralGain_p;

  /* Derivatives for Integrator: '<S286>/Filter' */
  _rtXdot->Filter_CSTATE_o = Quad_biplane_B.FilterCoefficient_b;

  /* Derivatives for Integrator: '<S2>/Integrator3' */
  _rtXdot->Integrator3_CSTATE = Quad_biplane_B.om_dot[0];

  /* Derivatives for Integrator: '<S2>/Integrator4' */
  _rtXdot->Integrator4_CSTATE = Quad_biplane_B.om_dot[1];

  /* Derivatives for Integrator: '<S2>/Integrator5' */
  _rtXdot->Integrator5_CSTATE = Quad_biplane_B.om_dot[2];

  /* Derivatives for Integrator: '<S2>/Integrator' */
  _rtXdot->Integrator_CSTATE_p = Quad_biplane_B.a_body[0];

  /* Derivatives for Integrator: '<S2>/Integrator1' */
  _rtXdot->Integrator1_CSTATE = Quad_biplane_B.a_body[1];

  /* Derivatives for Integrator: '<S2>/Integrator6' */
  _rtXdot->Integrator6_CSTATE = Quad_biplane_B.P_dot_new[0];

  /* Derivatives for Integrator: '<S2>/Integrator7' */
  _rtXdot->Integrator7_CSTATE = Quad_biplane_B.P_dot_new[1];

  /* Derivatives for Integrator: '<S2>/Integrator2' incorporates:
   *  Integrator: '<S2>/Integrator8'
   */
  if (Quad_biplane_B.Delay_f == 0.0) {
    _rtXdot->Integrator2_CSTATE = Quad_biplane_B.a_body[2];
    _rtXdot->Integrator8_CSTATE = Quad_biplane_B.P_dot_new[2];
  } else {
    /* level reset is active */
    _rtXdot->Integrator2_CSTATE = 0.0;

    /* level reset is active */
    _rtXdot->Integrator8_CSTATE = 0.0;
  }

  /* End of Derivatives for Integrator: '<S2>/Integrator2' */

  /* Derivatives for Integrator: '<S2>/Integrator9' */
  _rtXdot->Integrator9_CSTATE = Quad_biplane_B.Eang_dot_new[0];

  /* Derivatives for Integrator: '<S2>/Integrator10' */
  _rtXdot->Integrator10_CSTATE = Quad_biplane_B.Eang_dot_new[1];

  /* Derivatives for Integrator: '<S2>/Integrator11' */
  _rtXdot->Integrator11_CSTATE = Quad_biplane_B.Eang_dot_new[2];

  /* Derivatives for Integrator: '<S341>/Filter' */
  _rtXdot->Filter_CSTATE_f = Quad_biplane_B.FilterCoefficient_h;

  /* Derivatives for Integrator: '<S346>/Integrator' */
  _rtXdot->Integrator_CSTATE_bt = Quad_biplane_B.IntegralGain_h;
}

/* Model initialize function */
void Quad_biplane_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)Quad_biplane_M, 0,
                sizeof(RT_MODEL_Quad_biplane_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&Quad_biplane_M->solverInfo,
                          &Quad_biplane_M->Timing.simTimeStep);
    rtsiSetTPtr(&Quad_biplane_M->solverInfo, &rtmGetTPtr(Quad_biplane_M));
    rtsiSetStepSizePtr(&Quad_biplane_M->solverInfo,
                       &Quad_biplane_M->Timing.stepSize0);
    rtsiSetdXPtr(&Quad_biplane_M->solverInfo, &Quad_biplane_M->derivs);
    rtsiSetContStatesPtr(&Quad_biplane_M->solverInfo, (real_T **)
                         &Quad_biplane_M->contStates);
    rtsiSetNumContStatesPtr(&Quad_biplane_M->solverInfo,
      &Quad_biplane_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&Quad_biplane_M->solverInfo,
      &Quad_biplane_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&Quad_biplane_M->solverInfo,
      &Quad_biplane_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&Quad_biplane_M->solverInfo,
      &Quad_biplane_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&Quad_biplane_M->solverInfo, (&rtmGetErrorStatus
      (Quad_biplane_M)));
    rtsiSetRTModelPtr(&Quad_biplane_M->solverInfo, Quad_biplane_M);
  }

  rtsiSetSimTimeStep(&Quad_biplane_M->solverInfo, MAJOR_TIME_STEP);
  Quad_biplane_M->intgData.y = Quad_biplane_M->odeY;
  Quad_biplane_M->intgData.f[0] = Quad_biplane_M->odeF[0];
  Quad_biplane_M->intgData.f[1] = Quad_biplane_M->odeF[1];
  Quad_biplane_M->intgData.f[2] = Quad_biplane_M->odeF[2];
  Quad_biplane_M->intgData.f[3] = Quad_biplane_M->odeF[3];
  Quad_biplane_M->contStates = ((X_Quad_biplane_T *) &Quad_biplane_X);
  rtsiSetSolverData(&Quad_biplane_M->solverInfo, (void *)
                    &Quad_biplane_M->intgData);
  rtsiSetSolverName(&Quad_biplane_M->solverInfo,"ode4");
  rtmSetTPtr(Quad_biplane_M, &Quad_biplane_M->Timing.tArray[0]);
  rtmSetTFinal(Quad_biplane_M, 1000.0);
  Quad_biplane_M->Timing.stepSize0 = 0.001;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    rt_DataLoggingInfo.loggingInterval = NULL;
    Quad_biplane_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(Quad_biplane_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(Quad_biplane_M->rtwLogInfo, (NULL));
    rtliSetLogT(Quad_biplane_M->rtwLogInfo, "tout");
    rtliSetLogX(Quad_biplane_M->rtwLogInfo, "");
    rtliSetLogXFinal(Quad_biplane_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(Quad_biplane_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(Quad_biplane_M->rtwLogInfo, 4);
    rtliSetLogMaxRows(Quad_biplane_M->rtwLogInfo, 0);
    rtliSetLogDecimation(Quad_biplane_M->rtwLogInfo, 1);
    rtliSetLogY(Quad_biplane_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(Quad_biplane_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(Quad_biplane_M->rtwLogInfo, (NULL));
  }

  /* block I/O */
  (void) memset(((void *) &Quad_biplane_B), 0,
                sizeof(B_Quad_biplane_T));

  /* states (continuous) */
  {
    (void) memset((void *)&Quad_biplane_X, 0,
                  sizeof(X_Quad_biplane_T));
  }

  /* states (dwork) */
  (void) memset((void *)&Quad_biplane_DW, 0,
                sizeof(DW_Quad_biplane_T));

  /* Matfile logging */
  rt_StartDataLoggingWithStartTime(Quad_biplane_M->rtwLogInfo, 0.0, rtmGetTFinal
    (Quad_biplane_M), Quad_biplane_M->Timing.stepSize0, (&rtmGetErrorStatus
    (Quad_biplane_M)));

  /* Start for If: '<S310>/If' */
  Quad_biplane_DW.If_ActiveSubsystem = -1;

  /* Start for If: '<S59>/If' */
  Quad_biplane_DW.If_ActiveSubsystem_l = -1;
  Quad_biplane_PrevZCX.Integrator2_Reset_ZCE = UNINITIALIZED_ZCSIG;
  Quad_biplane_PrevZCX.Integrator8_Reset_ZCE = UNINITIALIZED_ZCSIG;

  /* InitializeConditions for Delay: '<Root>/Delay' */
  memcpy(&Quad_biplane_DW.Delay_DSTATE[0],
         &Quad_biplane_P.Delay_InitialCondition[0], 24U * sizeof(real_T));

  /* InitializeConditions for Integrator: '<S394>/Integrator' */
  Quad_biplane_X.Integrator_CSTATE =
    Quad_biplane_P.PIDController1_InitialConditi_f;

  /* InitializeConditions for Integrator: '<S389>/Filter' */
  Quad_biplane_X.Filter_CSTATE = Quad_biplane_P.PIDController1_InitialCondition;

  /* InitializeConditions for Integrator: '<S591>/Integrator' */
  Quad_biplane_X.Integrator_CSTATE_b =
    Quad_biplane_P.PIDController_InitialConditio_o;

  /* InitializeConditions for Integrator: '<S586>/Filter' */
  Quad_biplane_X.Filter_CSTATE_p =
    Quad_biplane_P.PIDController_InitialConditionF;

  /* InitializeConditions for Integrator: '<S442>/Integrator' */
  Quad_biplane_X.Integrator_CSTATE_d =
    Quad_biplane_P.PIDController2_InitialConditi_j;

  /* InitializeConditions for Integrator: '<S437>/Filter' */
  Quad_biplane_X.Filter_CSTATE_a =
    Quad_biplane_P.PIDController2_InitialConditi_n;

  /* InitializeConditions for Integrator: '<S490>/Integrator' */
  Quad_biplane_X.Integrator_CSTATE_n =
    Quad_biplane_P.PIDController3_InitialConditi_n;

  /* InitializeConditions for Integrator: '<S485>/Filter' */
  Quad_biplane_X.Filter_CSTATE_d =
    Quad_biplane_P.PIDController3_InitialCondition;

  /* InitializeConditions for Integrator: '<S42>/Integrator' */
  Quad_biplane_X.Integrator_CSTATE_n4 =
    Quad_biplane_P.PIDController1_InitialConditi_k;

  /* InitializeConditions for Integrator: '<S37>/Filter' */
  Quad_biplane_X.Filter_CSTATE_k =
    Quad_biplane_P.PIDController1_InitialConditi_o;

  /* InitializeConditions for Delay: '<S1>/Delay' */
  Quad_biplane_DW.Delay_DSTATE_m = Quad_biplane_P.Delay_InitialCondition_o;

  /* InitializeConditions for Integrator: '<S144>/Integrator' */
  Quad_biplane_X.Integrator_CSTATE_c =
    Quad_biplane_P.PIDController1_InitialConditi_d;

  /* InitializeConditions for Integrator: '<S139>/Filter' */
  Quad_biplane_X.Filter_CSTATE_db =
    Quad_biplane_P.PIDController1_InitialConditi_e;

  /* InitializeConditions for Integrator: '<S195>/Integrator' */
  Quad_biplane_X.Integrator_CSTATE_h =
    Quad_biplane_P.PIDController_InitialConditio_p;

  /* InitializeConditions for Integrator: '<S190>/Filter' */
  Quad_biplane_X.Filter_CSTATE_aw =
    Quad_biplane_P.PIDController_InitialConditio_i;

  /* InitializeConditions for Integrator: '<S96>/Integrator' */
  Quad_biplane_X.Integrator_CSTATE_m =
    Quad_biplane_P.PIDController_InitialConditio_g;

  /* InitializeConditions for Integrator: '<S91>/Filter' */
  Quad_biplane_X.Filter_CSTATE_n =
    Quad_biplane_P.PIDController_InitialConditio_k;

  /* InitializeConditions for Integrator: '<S243>/Integrator' */
  Quad_biplane_X.Integrator_CSTATE_mn =
    Quad_biplane_P.PIDController2_InitialCondit_eb;

  /* InitializeConditions for Integrator: '<S238>/Filter' */
  Quad_biplane_X.Filter_CSTATE_b =
    Quad_biplane_P.PIDController2_InitialConditi_k;

  /* InitializeConditions for Integrator: '<S291>/Integrator' */
  Quad_biplane_X.Integrator_CSTATE_j =
    Quad_biplane_P.PIDController3_InitialConditi_g;

  /* InitializeConditions for Integrator: '<S286>/Filter' */
  Quad_biplane_X.Filter_CSTATE_o =
    Quad_biplane_P.PIDController3_InitialConditi_f;

  /* InitializeConditions for Integrator: '<S2>/Integrator3' */
  Quad_biplane_X.Integrator3_CSTATE = Quad_biplane_P.Integrator3_IC;

  /* InitializeConditions for Integrator: '<S2>/Integrator4' */
  Quad_biplane_X.Integrator4_CSTATE = Quad_biplane_P.Integrator4_IC;

  /* InitializeConditions for Integrator: '<S2>/Integrator5' */
  Quad_biplane_X.Integrator5_CSTATE = Quad_biplane_P.Integrator5_IC;

  /* InitializeConditions for Integrator: '<S2>/Integrator' */
  Quad_biplane_X.Integrator_CSTATE_p = Quad_biplane_P.Integrator_IC;

  /* InitializeConditions for Integrator: '<S2>/Integrator1' */
  Quad_biplane_X.Integrator1_CSTATE = Quad_biplane_P.Integrator1_IC;

  /* InitializeConditions for Delay: '<S2>/Delay' */
  Quad_biplane_DW.Delay_DSTATE_a = Quad_biplane_P.Delay_InitialCondition_m;

  /* InitializeConditions for Integrator: '<S2>/Integrator2' */
  Quad_biplane_X.Integrator2_CSTATE = Quad_biplane_P.Integrator2_IC;

  /* InitializeConditions for Integrator: '<S2>/Integrator6' */
  Quad_biplane_X.Integrator6_CSTATE = Quad_biplane_P.Integrator6_IC;

  /* InitializeConditions for Integrator: '<S2>/Integrator7' */
  Quad_biplane_X.Integrator7_CSTATE = Quad_biplane_P.Integrator7_IC;

  /* InitializeConditions for Integrator: '<S2>/Integrator8' */
  Quad_biplane_X.Integrator8_CSTATE = Quad_biplane_P.Integrator8_IC;

  /* InitializeConditions for Integrator: '<S2>/Integrator9' */
  Quad_biplane_X.Integrator9_CSTATE = Quad_biplane_P.Integrator9_IC;

  /* InitializeConditions for Integrator: '<S2>/Integrator10' */
  Quad_biplane_X.Integrator10_CSTATE = Quad_biplane_P.Integrator10_IC;

  /* InitializeConditions for Integrator: '<S2>/Integrator11' */
  Quad_biplane_X.Integrator11_CSTATE = Quad_biplane_P.Integrator11_IC;

  /* InitializeConditions for Integrator: '<S341>/Filter' */
  Quad_biplane_X.Filter_CSTATE_f =
    Quad_biplane_P.PIDController_InitialConditio_l;

  /* InitializeConditions for Integrator: '<S346>/Integrator' */
  Quad_biplane_X.Integrator_CSTATE_bt =
    Quad_biplane_P.PIDController_InitialConditio_b;

  /* InitializeConditions for Integrator: '<S543>/Integrator' */
  Quad_biplane_X.Integrator_CSTATE_c5 =
    Quad_biplane_P.PIDController2_InitialConditi_e;

  /* InitializeConditions for Integrator: '<S538>/Filter' */
  Quad_biplane_X.Filter_CSTATE_fr =
    Quad_biplane_P.PIDController2_InitialCondition;

  /* SystemInitialize for Saturate: '<S550>/Saturation' incorporates:
   *  Outport: '<S509>/theta_dot_des'
   */
  Quad_biplane_B.Saturation_k = Quad_biplane_P.theta_dot_des_Y0;

  /* End of SystemInitialize for SubSystem: '<S310>/If Action Subsystem2' */

  /* SystemInitialize for Merge: '<S310>/Merge' */
  Quad_biplane_B.Merge = Quad_biplane_P.Merge_InitialOutput;
}

/* Model terminate function */
void Quad_biplane_terminate(void)
{
  /* (no terminate code required) */
}
