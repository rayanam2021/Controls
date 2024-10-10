/*
 * Multirotor_Model_1.c
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

#include "Multirotor_Model_1.h"
#include "Multirotor_Model_1_private.h"

/* Block signals (default storage) */
B_Multirotor_Model_1_T Multirotor_Model_1_B;

/* Continuous states */
X_Multirotor_Model_1_T Multirotor_Model_1_X;

/* Block states (default storage) */
DW_Multirotor_Model_1_T Multirotor_Model_1_DW;

/* Previous zero-crossings (trigger) states */
PrevZCX_Multirotor_Model_1_T Multirotor_Model_1_PrevZCX;

/* Real-time model */
static RT_MODEL_Multirotor_Model_1_T Multirotor_Model_1_M_;
RT_MODEL_Multirotor_Model_1_T *const Multirotor_Model_1_M =
  &Multirotor_Model_1_M_;

/* Forward declaration for local functions */
static void Multirotor_Model_emxInit_real_T(emxArray_real_T_Multirotor_Mo_T
  **pEmxArray, int32_T numDimensions);
static void Multirotor_Model_emxFree_real_T(emxArray_real_T_Multirotor_Mo_T
  **pEmxArray);
static real_T Multirotor_Model_1_mod(real_T x);
static void Multir_emxEnsureCapacity_real_T(emxArray_real_T_Multirotor_Mo_T
  *emxArray, int32_T oldNumel);
static void Multirotor_Mode_eml_float_colon(real_T d, real_T b,
  emxArray_real_T_Multirotor_Mo_T *y);
static real_T Multiroto_combineVectorElements(const
  emxArray_real_T_Multirotor_Mo_T *x);
static void Multirotor_Model_1_fn_interp2(const real_T x[34], const real_T b_y1
  [34], const real_T y2[34], real_T xeq, real_T *yeq1, real_T *yeq2);
static void Multirotor_Mode_fn_clcdcm_data4(real_T alpha, const real_T data[504],
  const real_T data2[102], real_T *cl, real_T *cd, real_T *cm);

/*
 * This function updates continuous states using the ODE3 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  /* Solver Matrices */
  static const real_T rt_ODE3_A[3] = {
    1.0/2.0, 3.0/4.0, 1.0
  };

  static const real_T rt_ODE3_B[3][3] = {
    { 1.0/2.0, 0.0, 0.0 },

    { 0.0, 3.0/4.0, 0.0 },

    { 2.0/9.0, 1.0/3.0, 4.0/9.0 }
  };

  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE3_IntgData *id = (ODE3_IntgData *)rtsiGetSolverData(si);
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T hB[3];
  int_T i;
  int_T nXc = 60;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  Multirotor_Model_1_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  Multirotor_Model_1_step();
  Multirotor_Model_1_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  Multirotor_Model_1_step();
  Multirotor_Model_1_derivatives();

  /* tnew = t + hA(3);
     ynew = y + f*hB(:,3); */
  for (i = 0; i <= 2; i++) {
    hB[i] = h * rt_ODE3_B[2][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2]);
  }

  rtsiSetT(si, tnew);
  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/*
 * System initialize for action system:
 *    '<S529>/If Action Subsystem3'
 *    '<S528>/If Action Subsystem3'
 */
void Multiro_IfActionSubsystem3_Init(real_T *rty_Out1)
{
  *rty_Out1 = 0.0;
}

/*
 * Output and update for action system:
 *    '<S529>/If Action Subsystem3'
 *    '<S528>/If Action Subsystem3'
 */
void Multirotor_M_IfActionSubsystem3(real_T rtu_In1, real_T *rty_Out1)
{
  /* Fcn: '<S536>/DeltaS' */
  *rty_Out1 = 99.88 * rtu_In1 - 76.67;
}

/*
 * System initialize for action system:
 *    '<S529>/If Action Subsystem4'
 *    '<S528>/If Action Subsystem4'
 */
void Multiro_IfActionSubsystem4_Init(real_T *rty_Out1)
{
  *rty_Out1 = 0.0;
}

/*
 * Output and update for action system:
 *    '<S529>/If Action Subsystem4'
 *    '<S528>/If Action Subsystem4'
 */
void Multirotor_M_IfActionSubsystem4(RT_MODEL_Multirotor_Model_1_T * const
  Multirotor_Model_1_M, real_T rtu_In1, real_T *rty_Out1)
{
  if (rtmIsMajorTimeStep(Multirotor_Model_1_M)) {
    /* Fcn: '<S537>/DeltaS' */
    *rty_Out1 = 30.0 * rtu_In1;
  }
}

/*
 * System initialize for action system:
 *    '<S529>/If Action Subsystem5'
 *    '<S528>/If Action Subsystem5'
 */
void Multiro_IfActionSubsystem5_Init(real_T *rty_Out1)
{
  *rty_Out1 = 0.0;
}

/*
 * Output and update for action system:
 *    '<S529>/If Action Subsystem5'
 *    '<S528>/If Action Subsystem5'
 */
void Multirotor_M_IfActionSubsystem5(RT_MODEL_Multirotor_Model_1_T * const
  Multirotor_Model_1_M, real_T rtu_In1, real_T *rty_Out1)
{
  if (rtmIsMajorTimeStep(Multirotor_Model_1_M)) {
    /* Fcn: '<S538>/DeltaS' */
    *rty_Out1 = -20.0 * rtu_In1;
  }
}

static void Multirotor_Model_emxInit_real_T(emxArray_real_T_Multirotor_Mo_T
  **pEmxArray, int32_T numDimensions)
{
  emxArray_real_T_Multirotor_Mo_T *emxArray;
  int32_T i;
  *pEmxArray = (emxArray_real_T_Multirotor_Mo_T *)malloc(sizeof
    (emxArray_real_T_Multirotor_Mo_T));
  emxArray = *pEmxArray;
  emxArray->data = (real_T *)NULL;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int32_T *)malloc(sizeof(int32_T) * numDimensions);
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < numDimensions; i++) {
    emxArray->size[i] = 0;
  }
}

static void Multirotor_Model_emxFree_real_T(emxArray_real_T_Multirotor_Mo_T
  **pEmxArray)
{
  if (*pEmxArray != (emxArray_real_T_Multirotor_Mo_T *)NULL) {
    if (((*pEmxArray)->data != (real_T *)NULL) && (*pEmxArray)->canFreeData) {
      free((*pEmxArray)->data);
    }

    free((*pEmxArray)->size);
    free(*pEmxArray);
    *pEmxArray = (emxArray_real_T_Multirotor_Mo_T *)NULL;
  }
}

/* Function for MATLAB Function: '<S510>/MATLAB Function1' */
static real_T Multirotor_Model_1_mod(real_T x)
{
  real_T r;
  if (rtIsNaN(x) || rtIsInf(x)) {
    r = (rtNaN);
  } else if (x == 0.0) {
    r = 0.0;
  } else {
    r = fmod(x, 2.0);
    if (r == 0.0) {
      r = 0.0;
    } else {
      if (x < 0.0) {
        r += 2.0;
      }
    }
  }

  return r;
}

static void Multir_emxEnsureCapacity_real_T(emxArray_real_T_Multirotor_Mo_T
  *emxArray, int32_T oldNumel)
{
  int32_T i;
  int32_T newNumel;
  void *newData;
  if (oldNumel < 0) {
    oldNumel = 0;
  }

  newNumel = 1;
  for (i = 0; i < emxArray->numDimensions; i++) {
    newNumel *= emxArray->size[i];
  }

  if (newNumel > emxArray->allocatedSize) {
    i = emxArray->allocatedSize;
    if (i < 16) {
      i = 16;
    }

    while (i < newNumel) {
      if (i > 1073741823) {
        i = MAX_int32_T;
      } else {
        i <<= 1;
      }
    }

    newData = calloc((uint32_T)i, sizeof(real_T));
    if (emxArray->data != NULL) {
      memcpy(newData, emxArray->data, sizeof(real_T) * oldNumel);
      if (emxArray->canFreeData) {
        free(emxArray->data);
      }
    }

    emxArray->data = (real_T *)newData;
    emxArray->allocatedSize = i;
    emxArray->canFreeData = true;
  }
}

/* Function for MATLAB Function: '<S521>/MATLAB Function' */
static void Multirotor_Mode_eml_float_colon(real_T d, real_T b,
  emxArray_real_T_Multirotor_Mo_T *y)
{
  real_T apnd;
  real_T cdiff;
  real_T ndbl;
  int32_T k;
  int32_T n;
  int32_T nm1d2;
  ndbl = floor(b / d + 0.5);
  apnd = ndbl * d;
  if (d > 0.0) {
    cdiff = apnd - b;
  } else {
    cdiff = b - apnd;
  }

  if (fabs(cdiff) < 4.4408920985006262E-16 * fabs(b)) {
    ndbl++;
    apnd = b;
  } else if (cdiff > 0.0) {
    apnd = (ndbl - 1.0) * d;
  } else {
    ndbl++;
  }

  if (ndbl >= 0.0) {
    n = (int32_T)ndbl - 1;
  } else {
    n = -1;
  }

  nm1d2 = y->size[0] * y->size[1];
  y->size[0] = 1;
  y->size[1] = n + 1;
  Multir_emxEnsureCapacity_real_T(y, nm1d2);
  if (n + 1 > 0) {
    y->data[0] = 0.0;
    if (n + 1 > 1) {
      y->data[n] = apnd;
      nm1d2 = n / 2;
      for (k = 1; k - 1 <= nm1d2 - 2; k++) {
        ndbl = (real_T)k * d;
        y->data[k] = ndbl;
        y->data[n - k] = apnd - ndbl;
      }

      if (nm1d2 << 1 == n) {
        y->data[nm1d2] = apnd / 2.0;
      } else {
        ndbl = (real_T)nm1d2 * d;
        y->data[nm1d2] = ndbl;
        y->data[nm1d2 + 1] = apnd - ndbl;
      }
    }
  }
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

/* Function for MATLAB Function: '<S521>/MATLAB Function' */
static real_T Multiroto_combineVectorElements(const
  emxArray_real_T_Multirotor_Mo_T *x)
{
  real_T y;
  int32_T k;
  if (x->size[0] == 0) {
    y = 0.0;
  } else {
    y = x->data[0];
    for (k = 2; k <= x->size[0]; k++) {
      y += x->data[k - 1];
    }
  }

  return y;
}

real_T rt_powd_snf(real_T u0, real_T u1)
{
  real_T tmp;
  real_T tmp_0;
  real_T y;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else {
    tmp = fabs(u0);
    tmp_0 = fabs(u1);
    if (rtIsInf(u1)) {
      if (tmp == 1.0) {
        y = 1.0;
      } else if (tmp > 1.0) {
        if (u1 > 0.0) {
          y = (rtInf);
        } else {
          y = 0.0;
        }
      } else if (u1 > 0.0) {
        y = 0.0;
      } else {
        y = (rtInf);
      }
    } else if (tmp_0 == 0.0) {
      y = 1.0;
    } else if (tmp_0 == 1.0) {
      if (u1 > 0.0) {
        y = u0;
      } else {
        y = 1.0 / u0;
      }
    } else if (u1 == 2.0) {
      y = u0 * u0;
    } else if ((u1 == 0.5) && (u0 >= 0.0)) {
      y = sqrt(u0);
    } else if ((u0 < 0.0) && (u1 > floor(u1))) {
      y = (rtNaN);
    } else {
      y = pow(u0, u1);
    }
  }

  return y;
}

/* Function for MATLAB Function: '<S521>/MATLAB Function' */
static void Multirotor_Model_1_fn_interp2(const real_T x[34], const real_T b_y1
  [34], const real_T y2[34], real_T xeq, real_T *yeq1, real_T *yeq2)
{
  real_T L;
  real_T R;
  real_T m;
  real_T tmp;
  int32_T exitg1;
  L = 1.0;
  R = 34.0;
  do {
    exitg1 = 0;
    if (R - L > 1.0) {
      m = floor((L + R) / 2.0);
      tmp = x[(int32_T)m - 1];
      if (xeq > tmp) {
        L = m;
      } else if (xeq < tmp) {
        R = m;
      } else {
        L = m;
        exitg1 = 1;
      }
    } else {
      exitg1 = 1;
    }
  } while (exitg1 == 0);

  m = x[(int32_T)L - 1];
  m = (xeq - m) / (x[(int32_T)R - 1] - m);
  *yeq1 = (1.0 - m) * b_y1[(int32_T)L - 1] + b_y1[(int32_T)R - 1] * m;
  *yeq2 = (1.0 - m) * y2[(int32_T)L - 1] + y2[(int32_T)R - 1] * m;
}

/* Function for MATLAB Function: '<S521>/MATLAB Function' */
static void Multirotor_Mode_fn_clcdcm_data4(real_T alpha, const real_T data[504],
  const real_T data2[102], real_T *cl, real_T *cd, real_T *cm)
{
  real_T R;
  real_T m;
  real_T s;
  real_T tmp;
  int32_T exitg1;
  alpha = alpha * 180.0 / 3.1415926535897931;
  *cl = 0.0;
  *cd = 0.0;
  *cm = 0.0;
  if ((alpha >= data[0]) && (alpha <= data[71])) {
    s = 1.0;
    R = 72.0;
    do {
      exitg1 = 0;
      if (R - s > 1.0) {
        m = floor((s + R) / 2.0);
        tmp = data[(int32_T)m - 1];
        if (alpha > tmp) {
          s = m;
        } else if (alpha < tmp) {
          R = m;
        } else {
          s = m;
          exitg1 = 1;
        }
      } else {
        exitg1 = 1;
      }
    } while (exitg1 == 0);

    m = data[(int32_T)s - 1];
    m = (alpha - m) / (data[(int32_T)R - 1] - m);
    *cl = (1.0 - m) * data[(int32_T)s + 71] + data[(int32_T)R + 71] * m;
    *cd = (1.0 - m) * data[(int32_T)s + 143] + data[(int32_T)R + 143] * m;
    *cm = (1.0 - m) * data[(int32_T)s + 215] + data[(int32_T)R + 215] * m;
  } else if (alpha >= 25.0) {
    *cm = data[287];
    Multirotor_Model_1_fn_interp2(&data2[0], &data2[34], &data2[68], alpha, cl,
      cd);
  } else if (alpha > data[71]) {
    *cm = data[287];
    s = (alpha - data[71]) / (data2[0] - data[71]);
    *cl = (1.0 - s) * data[143] + s * data2[34];
    *cd = (1.0 - s) * data[215] + s * data2[68];
  } else if (alpha < -25.0) {
    *cm = data[216];
    Multirotor_Model_1_fn_interp2(&data2[0], &data2[34], &data2[68], fabs(alpha),
      &s, cd);
    *cl = -s;
  } else {
    if (alpha < data[0]) {
      *cm = data[216];
      s = (alpha - data[0]) / (-data2[0] - data[0]);
      *cl = (1.0 - s) * data[72] - s * data2[34];
      *cd = (1.0 - s) * data[144] + s * data2[68];
    }
  }
}

/* Model step function */
void Multirotor_Model_1_step(void)
{
  /* local block i/o variables */
  real_T rtb_ImpSel_InsertedFor_Input_at;
  real_T rtb_Saturation_f;
  real_T rtb_SOC;
  real_T rtb_SOC_a;
  real_T rtb_I;

  /* local scratch DWork variables */
  int32_T ForEach_itr;
  static const int8_T b[3] = { 0, 0, 1 };

  emxArray_real_T_Multirotor_Mo_T *Fx;
  emxArray_real_T_Multirotor_Mo_T *Fy;
  emxArray_real_T_Multirotor_Mo_T *Fz;
  emxArray_real_T_Multirotor_Mo_T *Mx;
  emxArray_real_T_Multirotor_Mo_T *My;
  emxArray_real_T_Multirotor_Mo_T *Q;
  emxArray_real_T_Multirotor_Mo_T *U;
  emxArray_real_T_Multirotor_Mo_T *Up;
  emxArray_real_T_Multirotor_Mo_T *Ut;
  emxArray_real_T_Multirotor_Mo_T *alpha;
  emxArray_real_T_Multirotor_Mo_T *b_psi;
  emxArray_real_T_Multirotor_Mo_T *cd;
  emxArray_real_T_Multirotor_Mo_T *cl;
  emxArray_real_T_Multirotor_Mo_T *cl2d;
  emxArray_real_T_Multirotor_Mo_T *dD;
  emxArray_real_T_Multirotor_Mo_T *dFtan;
  emxArray_real_T_Multirotor_Mo_T *dFtan_0;
  emxArray_real_T_Multirotor_Mo_T *dFtan_1;
  emxArray_real_T_Multirotor_Mo_T *dFz;
  emxArray_real_T_Multirotor_Mo_T *dFz_0;
  emxArray_real_T_Multirotor_Mo_T *dL;
  emxArray_real_T_Multirotor_Mo_T *dMx;
  emxArray_real_T_Multirotor_Mo_T *dMx_0;
  emxArray_real_T_Multirotor_Mo_T *dMy;
  emxArray_real_T_Multirotor_Mo_T *dMy_0;
  emxArray_real_T_Multirotor_Mo_T *dQ;
  emxArray_real_T_Multirotor_Mo_T *dQ_0;
  emxArray_real_T_Multirotor_Mo_T *error;
  emxArray_real_T_Multirotor_Mo_T *error2;
  emxArray_real_T_Multirotor_Mo_T *lambdai;
  emxArray_real_T_Multirotor_Mo_T *lambdai_old;
  emxArray_real_T_Multirotor_Mo_T *phi;
  emxArray_real_T_Multirotor_Mo_T *psi;
  emxArray_real_T_Multirotor_Mo_T *theta;
  real_T rtb_ImpAsg_InsertedFor_Rotorloa[24];
  real_T R[9];
  real_T R_tmp[9];
  real_T c[9];
  real_T rtb_Sum_m[9];
  real_T rtb_Add[6];
  real_T Drag_Force[3];
  real_T P_ddot[3];
  real_T R_0[3];
  real_T R_1[3];
  real_T tmp[3];
  real_T tmp_0[3];
  real_T Load4;
  real_T Load5;
  real_T Load6;
  real_T R_tmp_tmp;
  real_T R_tmp_tmp_0;
  real_T R_tmp_tmp_1;
  real_T a;
  real_T a_a;
  real_T b_a;
  real_T dr;
  real_T i_0;
  real_T kx;
  real_T ky;
  real_T lambda;
  real_T lambda0;
  real_T lambda_1;
  real_T mu_tmp;
  real_T muz;
  real_T root_cut;
  real_T rtb_Clock;
  real_T rtb_Saturation_c;
  real_T rtb_Saturation_e;
  real_T rtb_Sum1_d_tmp;
  real_T rtb_Sum1_f;
  real_T rtb_Sum1_k;
  real_T rtb_Sum1_n;
  real_T rtb_Sum2;
  real_T rtb_Sum2_j;
  real_T rtb_Sum_bj;
  real_T rtb_Sum_d;
  real_T rtb_Sum_f;
  real_T rtb_Sum_g_tmp;
  real_T rtb_Sum_k;
  real_T rtb_Sum_m_tmp;
  real_T ssw2;
  real_T t;
  real_T theta_tmp;
  real_T theta_tmp_0;
  real_T tmp_1;
  real_T tmp_2;
  int32_T b_i;
  int32_T c_tmp;
  int32_T i;
  int32_T loop_ub;
  int8_T rtAction;
  boolean_T exitg1;
  boolean_T rtb_NotEqual;
  ZCEventType zcEvent;
  if (rtmIsMajorTimeStep(Multirotor_Model_1_M)) {
    /* set solver stop time */
    if (!(Multirotor_Model_1_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&Multirotor_Model_1_M->solverInfo,
                            ((Multirotor_Model_1_M->Timing.clockTickH0 + 1) *
        Multirotor_Model_1_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&Multirotor_Model_1_M->solverInfo,
                            ((Multirotor_Model_1_M->Timing.clockTick0 + 1) *
        Multirotor_Model_1_M->Timing.stepSize0 +
        Multirotor_Model_1_M->Timing.clockTickH0 *
        Multirotor_Model_1_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(Multirotor_Model_1_M)) {
    Multirotor_Model_1_M->Timing.t[0] = rtsiGetT
      (&Multirotor_Model_1_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(Multirotor_Model_1_M)) {
    /* Delay: '<Root>/Delay' */
    memcpy(&Multirotor_Model_1_B.Delay[0], &Multirotor_Model_1_DW.Delay_DSTATE[0],
           24U * sizeof(real_T));
  }

  /* Clock: '<Root>/Clock' */
  rtb_Clock = Multirotor_Model_1_M->Timing.t[0];

  /* MATLAB Function: '<Root>/Mission Profile' */
  Multirotor_Model_1_B.Z_desired = 0.0;
  Multirotor_Model_1_B.X_desired = 0.0;
  Multirotor_Model_1_B.psi_desired = 0.0;
  if ((rtb_Clock >= 0.0) && (rtb_Clock < 75.0)) {
    Multirotor_Model_1_B.Z_desired = -200.0;
    Multirotor_Model_1_B.X_desired = 0.0;
  }

  if ((rtb_Clock >= 75.0) && (rtb_Clock < 200.0)) {
    Multirotor_Model_1_B.Z_desired = -200.0;
    Multirotor_Model_1_B.X_desired = 1000.0;
  }

  if ((rtb_Clock >= 200.0) && (rtb_Clock < 280.0)) {
    Multirotor_Model_1_B.Z_desired = -1.0;
    Multirotor_Model_1_B.X_desired = 1000.0;
  }

  /* End of MATLAB Function: '<Root>/Mission Profile' */

  /* Sum: '<S307>/Sum' */
  rtb_Clock = Multirotor_Model_1_B.X_desired - Multirotor_Model_1_B.Delay[0];

  /* Gain: '<S346>/Filter Coefficient' incorporates:
   *  Gain: '<S337>/Derivative Gain'
   *  Integrator: '<S338>/Filter'
   *  Sum: '<S338>/SumD'
   */
  Multirotor_Model_1_B.FilterCoefficient = (Multirotor_Model_1_P.PIDController_D
    * rtb_Clock - Multirotor_Model_1_X.Filter_CSTATE) *
    Multirotor_Model_1_P.PIDController_N;
  if (rtmIsMajorTimeStep(Multirotor_Model_1_M)) {
    /* Sum: '<S307>/Sum1' incorporates:
     *  Constant: '<S8>/Constant'
     */
    rtb_Sum1_n = Multirotor_Model_1_P.Constant_Value -
      Multirotor_Model_1_B.Delay[1];

    /* Gain: '<S396>/Proportional Gain' */
    Multirotor_Model_1_B.ProportionalGain =
      Multirotor_Model_1_P.PIDController1_P * rtb_Sum1_n;

    /* Gain: '<S385>/Derivative Gain' */
    Multirotor_Model_1_B.DerivativeGain = Multirotor_Model_1_P.PIDController1_D *
      rtb_Sum1_n;
  }

  /* Gain: '<S394>/Filter Coefficient' incorporates:
   *  Integrator: '<S386>/Filter'
   *  Sum: '<S386>/SumD'
   */
  Multirotor_Model_1_B.FilterCoefficient_n =
    (Multirotor_Model_1_B.DerivativeGain - Multirotor_Model_1_X.Filter_CSTATE_j)
    * Multirotor_Model_1_P.PIDController1_N;

  /* Sum: '<S400>/Sum' incorporates:
   *  Integrator: '<S391>/Integrator'
   */
  Load4 = (Multirotor_Model_1_B.ProportionalGain +
           Multirotor_Model_1_X.Integrator_CSTATE_b) +
    Multirotor_Model_1_B.FilterCoefficient_n;

  /* Saturate: '<S398>/Saturation' */
  if (Load4 > Multirotor_Model_1_P.PIDController1_UpperSaturationL) {
    /* Saturate: '<S398>/Saturation' */
    Multirotor_Model_1_B.Saturation =
      Multirotor_Model_1_P.PIDController1_UpperSaturationL;
  } else if (Load4 < Multirotor_Model_1_P.PIDController1_LowerSaturationL) {
    /* Saturate: '<S398>/Saturation' */
    Multirotor_Model_1_B.Saturation =
      Multirotor_Model_1_P.PIDController1_LowerSaturationL;
  } else {
    /* Saturate: '<S398>/Saturation' */
    Multirotor_Model_1_B.Saturation = Load4;
  }

  /* End of Saturate: '<S398>/Saturation' */

  /* Sum: '<S308>/Sum' */
  rtb_Sum_f = Multirotor_Model_1_B.Z_desired - Multirotor_Model_1_B.Delay[2];

  /* Gain: '<S491>/Filter Coefficient' incorporates:
   *  Gain: '<S482>/Derivative Gain'
   *  Integrator: '<S483>/Filter'
   *  Sum: '<S483>/SumD'
   */
  Multirotor_Model_1_B.FilterCoefficient_j =
    (Multirotor_Model_1_P.PIDController_D_h * rtb_Sum_f -
     Multirotor_Model_1_X.Filter_CSTATE_p) *
    Multirotor_Model_1_P.PIDController_N_c;

  /* Sum: '<S497>/Sum' incorporates:
   *  Gain: '<S493>/Proportional Gain'
   *  Integrator: '<S488>/Integrator'
   */
  Load4 = (Multirotor_Model_1_P.PIDController_P_m * rtb_Sum_f +
           Multirotor_Model_1_X.Integrator_CSTATE_b0) +
    Multirotor_Model_1_B.FilterCoefficient_j;

  /* Saturate: '<S495>/Saturation' */
  if (Load4 > Multirotor_Model_1_P.PIDController_UpperSaturation_k) {
    /* Saturate: '<S495>/Saturation' */
    Multirotor_Model_1_B.Saturation_h =
      Multirotor_Model_1_P.PIDController_UpperSaturation_k;
  } else if (Load4 < Multirotor_Model_1_P.PIDController_LowerSaturation_e) {
    /* Saturate: '<S495>/Saturation' */
    Multirotor_Model_1_B.Saturation_h =
      Multirotor_Model_1_P.PIDController_LowerSaturation_e;
  } else {
    /* Saturate: '<S495>/Saturation' */
    Multirotor_Model_1_B.Saturation_h = Load4;
  }

  /* End of Saturate: '<S495>/Saturation' */

  /* Sum: '<S307>/Sum2' */
  rtb_Sum2 = Multirotor_Model_1_B.psi_desired - Multirotor_Model_1_B.Delay[8];

  /* Gain: '<S442>/Filter Coefficient' incorporates:
   *  Gain: '<S433>/Derivative Gain'
   *  Integrator: '<S434>/Filter'
   *  Sum: '<S434>/SumD'
   */
  Multirotor_Model_1_B.FilterCoefficient_f =
    (Multirotor_Model_1_P.PIDController2_D * rtb_Sum2 -
     Multirotor_Model_1_X.Filter_CSTATE_a) *
    Multirotor_Model_1_P.PIDController2_N;

  /* Sum: '<S448>/Sum' incorporates:
   *  Gain: '<S444>/Proportional Gain'
   *  Integrator: '<S439>/Integrator'
   */
  Load4 = (Multirotor_Model_1_P.PIDController2_P * rtb_Sum2 +
           Multirotor_Model_1_X.Integrator_CSTATE_d) +
    Multirotor_Model_1_B.FilterCoefficient_f;

  /* Saturate: '<S446>/Saturation' */
  if (Load4 > Multirotor_Model_1_P.PIDController2_UpperSaturationL) {
    /* Saturate: '<S446>/Saturation' */
    Multirotor_Model_1_B.Saturation_hv =
      Multirotor_Model_1_P.PIDController2_UpperSaturationL;
  } else if (Load4 < Multirotor_Model_1_P.PIDController2_LowerSaturationL) {
    /* Saturate: '<S446>/Saturation' */
    Multirotor_Model_1_B.Saturation_hv =
      Multirotor_Model_1_P.PIDController2_LowerSaturationL;
  } else {
    /* Saturate: '<S446>/Saturation' */
    Multirotor_Model_1_B.Saturation_hv = Load4;
  }

  /* End of Saturate: '<S446>/Saturation' */

  /* MATLAB Function: '<S8>/MATLAB Function' incorporates:
   *  MATLAB Function: '<S2>/State_update'
   *  MATLAB Function: '<S2>/Transform1'
   *  MATLAB Function: '<S2>/Translational Dynamics'
   *  MATLAB Function: '<S511>/MATLAB Function'
   */
  R_tmp_tmp_0 = sin(Multirotor_Model_1_B.Delay[6]);
  R_tmp_tmp = cos(Multirotor_Model_1_B.Delay[6]);
  rtb_Sum_g_tmp = sin(Multirotor_Model_1_B.Delay[7]);
  R_tmp_tmp_1 = cos(Multirotor_Model_1_B.Delay[7]);
  rtb_Sum1_d_tmp = sin(Multirotor_Model_1_B.Delay[8]);
  rtb_Sum_m_tmp = cos(Multirotor_Model_1_B.Delay[8]);
  R[1] = 0.0;
  R[4] = R_tmp_tmp;
  R[7] = R_tmp_tmp_0;
  R[2] = 0.0;
  R[5] = -R_tmp_tmp_0;
  R[8] = R_tmp_tmp;
  R_tmp[0] = R_tmp_tmp_1;
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
  R_tmp[8] = R_tmp_tmp_1;
  rtb_Sum_m[0] = rtb_Sum_m_tmp;
  rtb_Sum_m[3] = rtb_Sum1_d_tmp;
  rtb_Sum_m[6] = 0.0;
  rtb_Sum_m[1] = -rtb_Sum1_d_tmp;
  rtb_Sum_m[4] = rtb_Sum_m_tmp;
  rtb_Sum_m[7] = 0.0;
  for (b_i = 0; b_i < 3; b_i++) {
    for (i = 0; i < 3; i++) {
      c_tmp = b_i + 3 * i;
      c[c_tmp] = 0.0;
      c[c_tmp] += R_tmp[3 * i] * R[b_i];
      c[c_tmp] += R_tmp[3 * i + 1] * R[b_i + 3];
      c[c_tmp] += R_tmp[3 * i + 2] * R[b_i + 6];
    }

    rtb_Sum_m[3 * b_i + 2] = b[b_i];
  }

  /* Sum: '<S352>/Sum' incorporates:
   *  Gain: '<S348>/Proportional Gain'
   *  Integrator: '<S343>/Integrator'
   */
  Load4 = (Multirotor_Model_1_P.PIDController_P * rtb_Clock +
           Multirotor_Model_1_X.Integrator_CSTATE) +
    Multirotor_Model_1_B.FilterCoefficient;

  /* Saturate: '<S350>/Saturation' */
  if (Load4 > Multirotor_Model_1_P.PIDController_UpperSaturationLi) {
    /* MATLAB Function: '<S8>/MATLAB Function' */
    P_ddot[0] = Multirotor_Model_1_P.PIDController_UpperSaturationLi;
  } else if (Load4 < Multirotor_Model_1_P.PIDController_LowerSaturationLi) {
    /* MATLAB Function: '<S8>/MATLAB Function' */
    P_ddot[0] = Multirotor_Model_1_P.PIDController_LowerSaturationLi;
  } else {
    /* MATLAB Function: '<S8>/MATLAB Function' */
    P_ddot[0] = Load4;
  }

  /* End of Saturate: '<S350>/Saturation' */

  /* MATLAB Function: '<S8>/MATLAB Function' */
  P_ddot[1] = Multirotor_Model_1_B.Delay[4];
  P_ddot[2] = Multirotor_Model_1_B.Delay[5];
  tmp[0] = Multirotor_Model_1_B.Delay[3];
  tmp[1] = Multirotor_Model_1_B.Saturation;
  tmp[2] = Multirotor_Model_1_B.Delay[5];
  tmp_0[0] = Multirotor_Model_1_B.Delay[3];
  tmp_0[1] = Multirotor_Model_1_B.Delay[4];
  tmp_0[2] = Multirotor_Model_1_B.Saturation_h;
  for (b_i = 0; b_i < 3; b_i++) {
    Drag_Force[b_i] = 0.0;
    R_0[b_i] = 0.0;
    R_1[b_i] = 0.0;
    for (i = 0; i < 3; i++) {
      c_tmp = b_i + 3 * i;
      R[c_tmp] = 0.0;
      R[c_tmp] += rtb_Sum_m[3 * i] * c[b_i];
      R[c_tmp] += rtb_Sum_m[3 * i + 1] * c[b_i + 3];
      R[c_tmp] += rtb_Sum_m[3 * i + 2] * c[b_i + 6];
      Drag_Force[b_i] += R[c_tmp] * P_ddot[i];
      R_0[b_i] += R[c_tmp] * tmp[i];
      R_1[b_i] += R[c_tmp] * tmp_0[i];
    }
  }

  Multirotor_Model_1_B.u_des = Drag_Force[0];
  Multirotor_Model_1_B.v_des = R_0[1];
  Multirotor_Model_1_B.w_des = R_1[2];
  c[0] = 1.0;
  c[3] = 0.0;
  c[6] = -sin(Multirotor_Model_1_B.Delay[7]);
  c[1] = 0.0;
  c[4] = R_tmp_tmp;
  c[7] = R_tmp_tmp_0 * R_tmp_tmp_1;
  c[2] = 0.0;
  c[5] = -sin(Multirotor_Model_1_B.Delay[6]);
  c[8] = R_tmp_tmp * R_tmp_tmp_1;
  rtb_Sum_d = Multirotor_Model_1_B.Delay[21];
  rtb_Sum1_f = Multirotor_Model_1_B.Delay[22];
  for (b_i = 0; b_i < 3; b_i++) {
    P_ddot[b_i] = c[b_i + 6] * Multirotor_Model_1_B.Saturation_hv + (c[b_i + 3] *
      rtb_Sum1_f + c[b_i] * rtb_Sum_d);
  }

  Multirotor_Model_1_B.r_des = P_ddot[2];

  /* Sum: '<S9>/Sum' */
  rtb_Sum_d = Multirotor_Model_1_B.w_des - Multirotor_Model_1_B.Delay[20];

  /* Gain: '<S45>/Filter Coefficient' incorporates:
   *  Gain: '<S36>/Derivative Gain'
   *  Integrator: '<S37>/Filter'
   *  Sum: '<S37>/SumD'
   */
  Multirotor_Model_1_B.FilterCoefficient_m =
    (Multirotor_Model_1_P.PIDController_D_f * rtb_Sum_d -
     Multirotor_Model_1_X.Filter_CSTATE_e) *
    Multirotor_Model_1_P.PIDController_N_o;

  /* Gain: '<S9>/Gain1' incorporates:
   *  Gain: '<S47>/Proportional Gain'
   *  Integrator: '<S42>/Integrator'
   *  Sum: '<S51>/Sum'
   */
  Multirotor_Model_1_B.Gain1 = ((Multirotor_Model_1_P.PIDController_P_my *
    rtb_Sum_d + Multirotor_Model_1_X.Integrator_CSTATE_f) +
    Multirotor_Model_1_B.FilterCoefficient_m) * Multirotor_Model_1_P.Gain1_Gain;
  if (rtmIsMajorTimeStep(Multirotor_Model_1_M)) {
    /* Delay: '<S523>/Delay' incorporates:
     *  Delay: '<S1>/Delay'
     */
    rtb_I = Multirotor_Model_1_DW.Delay_DSTATE_m;

    /* Gain: '<S9>/Gain' incorporates:
     *  Math: '<S9>/Square'
     */
    Multirotor_Model_1_B.Gain = 4.0 * Multirotor_Model_1_P.Quad.KT * (rtb_I *
      rtb_I);
  }

  /* Sum: '<S9>/Sum1' */
  Multirotor_Model_1_B.Sum1 = Multirotor_Model_1_B.Gain1 +
    Multirotor_Model_1_B.Gain;

  /* Sum: '<S59>/Sum1' */
  rtb_Sum1_f = Multirotor_Model_1_B.v_des - Multirotor_Model_1_B.Delay[19];

  /* Gain: '<S145>/Filter Coefficient' incorporates:
   *  Gain: '<S136>/Derivative Gain'
   *  Integrator: '<S137>/Filter'
   *  Sum: '<S137>/SumD'
   */
  Multirotor_Model_1_B.FilterCoefficient_p =
    (Multirotor_Model_1_P.PIDController1_D_a * rtb_Sum1_f -
     Multirotor_Model_1_X.Filter_CSTATE_o) *
    Multirotor_Model_1_P.PIDController1_N_f;

  /* Sum: '<S151>/Sum' incorporates:
   *  Gain: '<S147>/Proportional Gain'
   *  Integrator: '<S142>/Integrator'
   */
  Load4 = (Multirotor_Model_1_P.PIDController1_P_l * rtb_Sum1_f +
           Multirotor_Model_1_X.Integrator_CSTATE_e) +
    Multirotor_Model_1_B.FilterCoefficient_p;

  /* Saturate: '<S149>/Saturation' */
  if (Load4 > Multirotor_Model_1_P.PIDController1_UpperSaturatio_n) {
    /* Saturate: '<S149>/Saturation' */
    Multirotor_Model_1_B.Saturation_j =
      Multirotor_Model_1_P.PIDController1_UpperSaturatio_n;
  } else if (Load4 < Multirotor_Model_1_P.PIDController1_LowerSaturatio_j) {
    /* Saturate: '<S149>/Saturation' */
    Multirotor_Model_1_B.Saturation_j =
      Multirotor_Model_1_P.PIDController1_LowerSaturatio_j;
  } else {
    /* Saturate: '<S149>/Saturation' */
    Multirotor_Model_1_B.Saturation_j = Load4;
  }

  /* End of Saturate: '<S149>/Saturation' */

  /* Sum: '<S60>/Sum' */
  rtb_Sum_k = Multirotor_Model_1_B.Saturation_j - Multirotor_Model_1_B.Delay[9];

  /* Gain: '<S196>/Filter Coefficient' incorporates:
   *  Gain: '<S187>/Derivative Gain'
   *  Integrator: '<S188>/Filter'
   *  Sum: '<S188>/SumD'
   */
  Multirotor_Model_1_B.FilterCoefficient_jz =
    (Multirotor_Model_1_P.PIDController_D_n * rtb_Sum_k -
     Multirotor_Model_1_X.Filter_CSTATE_e2) *
    Multirotor_Model_1_P.PIDController_N_oe;

  /* Sum: '<S202>/Sum' incorporates:
   *  Gain: '<S198>/Proportional Gain'
   *  Integrator: '<S193>/Integrator'
   */
  rtb_Saturation_c = (Multirotor_Model_1_P.PIDController_P_mb * rtb_Sum_k +
                      Multirotor_Model_1_X.Integrator_CSTATE_n) +
    Multirotor_Model_1_B.FilterCoefficient_jz;

  /* Saturate: '<S200>/Saturation' */
  if (rtb_Saturation_c > Multirotor_Model_1_P.PIDController_UpperSaturation_i) {
    rtb_Saturation_c = Multirotor_Model_1_P.PIDController_UpperSaturation_i;
  } else {
    if (rtb_Saturation_c < Multirotor_Model_1_P.PIDController_LowerSaturation_l)
    {
      rtb_Saturation_c = Multirotor_Model_1_P.PIDController_LowerSaturation_l;
    }
  }

  /* End of Saturate: '<S200>/Saturation' */

  /* Sum: '<S59>/Sum' */
  rtb_Sum_bj = Multirotor_Model_1_B.u_des - Multirotor_Model_1_B.Delay[18];

  /* Gain: '<S97>/Filter Coefficient' incorporates:
   *  Gain: '<S88>/Derivative Gain'
   *  Integrator: '<S89>/Filter'
   *  Sum: '<S89>/SumD'
   */
  Multirotor_Model_1_B.FilterCoefficient_a =
    (Multirotor_Model_1_P.PIDController_D_e * rtb_Sum_bj -
     Multirotor_Model_1_X.Filter_CSTATE_j2) *
    Multirotor_Model_1_P.PIDController_N_f;

  /* Sum: '<S103>/Sum' incorporates:
   *  Gain: '<S99>/Proportional Gain'
   *  Integrator: '<S94>/Integrator'
   */
  Load4 = (Multirotor_Model_1_P.PIDController_P_g * rtb_Sum_bj +
           Multirotor_Model_1_X.Integrator_CSTATE_k) +
    Multirotor_Model_1_B.FilterCoefficient_a;

  /* Saturate: '<S101>/Saturation' */
  if (Load4 > Multirotor_Model_1_P.PIDController_UpperSaturation_j) {
    Load4 = Multirotor_Model_1_P.PIDController_UpperSaturation_j;
  } else {
    if (Load4 < Multirotor_Model_1_P.PIDController_LowerSaturation_d) {
      Load4 = Multirotor_Model_1_P.PIDController_LowerSaturation_d;
    }
  }

  /* End of Saturate: '<S101>/Saturation' */

  /* Gain: '<S59>/Gain1' */
  Multirotor_Model_1_B.Gain1_b = Multirotor_Model_1_P.Gain1_Gain_l * Load4;

  /* Sum: '<S60>/Sum1' */
  rtb_Sum1_k = Multirotor_Model_1_B.Gain1_b - Multirotor_Model_1_B.Delay[10];

  /* Gain: '<S244>/Filter Coefficient' incorporates:
   *  Gain: '<S235>/Derivative Gain'
   *  Integrator: '<S236>/Filter'
   *  Sum: '<S236>/SumD'
   */
  Multirotor_Model_1_B.FilterCoefficient_a2 =
    (Multirotor_Model_1_P.PIDController1_D_e * rtb_Sum1_k -
     Multirotor_Model_1_X.Filter_CSTATE_eb) *
    Multirotor_Model_1_P.PIDController1_N_b;

  /* Sum: '<S250>/Sum' incorporates:
   *  Gain: '<S246>/Proportional Gain'
   *  Integrator: '<S241>/Integrator'
   */
  rtb_Saturation_e = (Multirotor_Model_1_P.PIDController1_P_i * rtb_Sum1_k +
                      Multirotor_Model_1_X.Integrator_CSTATE_h) +
    Multirotor_Model_1_B.FilterCoefficient_a2;

  /* Saturate: '<S248>/Saturation' */
  if (rtb_Saturation_e > Multirotor_Model_1_P.PIDController1_UpperSaturatio_c) {
    rtb_Saturation_e = Multirotor_Model_1_P.PIDController1_UpperSaturatio_c;
  } else {
    if (rtb_Saturation_e < Multirotor_Model_1_P.PIDController1_LowerSaturatio_l)
    {
      rtb_Saturation_e = Multirotor_Model_1_P.PIDController1_LowerSaturatio_l;
    }
  }

  /* End of Saturate: '<S248>/Saturation' */

  /* Sum: '<S60>/Sum2' */
  rtb_Sum2_j = Multirotor_Model_1_B.r_des - Multirotor_Model_1_B.Delay[11];

  /* Gain: '<S292>/Filter Coefficient' incorporates:
   *  Gain: '<S283>/Derivative Gain'
   *  Integrator: '<S284>/Filter'
   *  Sum: '<S284>/SumD'
   */
  Multirotor_Model_1_B.FilterCoefficient_c =
    (Multirotor_Model_1_P.PIDController2_D_b * rtb_Sum2_j -
     Multirotor_Model_1_X.Filter_CSTATE_d) *
    Multirotor_Model_1_P.PIDController2_N_e;

  /* Sum: '<S298>/Sum' incorporates:
   *  Gain: '<S294>/Proportional Gain'
   *  Integrator: '<S289>/Integrator'
   */
  Load4 = (Multirotor_Model_1_P.PIDController2_P_b * rtb_Sum2_j +
           Multirotor_Model_1_X.Integrator_CSTATE_h4) +
    Multirotor_Model_1_B.FilterCoefficient_c;

  /* Saturate: '<S296>/Saturation' */
  if (Load4 > Multirotor_Model_1_P.PIDController2_UpperSaturatio_k) {
    /* Saturate: '<S296>/Saturation' */
    Multirotor_Model_1_B.Saturation_o =
      Multirotor_Model_1_P.PIDController2_UpperSaturatio_k;
  } else if (Load4 < Multirotor_Model_1_P.PIDController2_LowerSaturatio_m) {
    /* Saturate: '<S296>/Saturation' */
    Multirotor_Model_1_B.Saturation_o =
      Multirotor_Model_1_P.PIDController2_LowerSaturatio_m;
  } else {
    /* Saturate: '<S296>/Saturation' */
    Multirotor_Model_1_B.Saturation_o = Load4;
  }

  /* End of Saturate: '<S296>/Saturation' */

  /* MATLAB Function: '<S1>/MATLAB Function' incorporates:
   *  Constant: '<S1>/Constant'
   */
  ssw2 = Multirotor_Model_1_B.Sum1 / 2.50172E-5;
  Multirotor_Model_1_B.ssw = fabs(ssw2);
  Multirotor_Model_1_B.ssw = sqrt(Multirotor_Model_1_B.ssw);
  a_a = 0.0 * Multirotor_Model_1_P.Quad.arm_angle +
    Multirotor_Model_1_P.Quad.rotor1_angle;
  Multirotor_Model_1_B.RPMs[0] = sqrt(fabs(((ssw2 - sin(a_a) * rtb_Saturation_c /
    7.0048160000000015E-6) + cos(a_a) * rtb_Saturation_e / 7.0048160000000015E-6)
    - Multirotor_Model_1_B.Saturation_o / 2.6542E-7)) * 9.5493;
  a_a = Multirotor_Model_1_P.Quad.rotor1_angle +
    Multirotor_Model_1_P.Quad.arm_angle;
  Load4 = -Multirotor_Model_1_B.Saturation_o / 2.6542E-7;
  Multirotor_Model_1_B.RPMs[1] = sqrt(fabs(((ssw2 - sin(a_a) * rtb_Saturation_c /
    7.0048160000000015E-6) + cos(a_a) * rtb_Saturation_e / 7.0048160000000015E-6)
    - Load4)) * 9.5493;
  a_a = 2.0 * Multirotor_Model_1_P.Quad.arm_angle +
    Multirotor_Model_1_P.Quad.rotor1_angle;
  Multirotor_Model_1_B.RPMs[2] = sqrt(fabs(((ssw2 - sin(a_a) * rtb_Saturation_c /
    7.0048160000000015E-6) + cos(a_a) * rtb_Saturation_e / 7.0048160000000015E-6)
    - Multirotor_Model_1_B.Saturation_o / 2.6542E-7)) * 9.5493;
  a_a = 3.0 * Multirotor_Model_1_P.Quad.arm_angle +
    Multirotor_Model_1_P.Quad.rotor1_angle;
  Multirotor_Model_1_B.RPMs[3] = sqrt(fabs(((ssw2 - sin(a_a) * rtb_Saturation_c /
    7.0048160000000015E-6) + cos(a_a) * rtb_Saturation_e / 7.0048160000000015E-6)
    - Load4)) * 9.5493;

  /* Outputs for Iterator SubSystem: '<S510>/For Each Subsystem' incorporates:
   *  ForEach: '<S514>/For Each'
   */
  ForEach_itr = 0;

  /* End of Outputs for SubSystem: '<S510>/For Each Subsystem' */
  Multirotor_Model_emxInit_real_T(&psi, 2);
  Multirotor_Model_emxInit_real_T(&theta, 2);
  Multirotor_Model_emxInit_real_T(&lambdai, 2);
  Multirotor_Model_emxInit_real_T(&lambdai_old, 2);
  Multirotor_Model_emxInit_real_T(&Ut, 2);
  Multirotor_Model_emxInit_real_T(&Up, 2);
  Multirotor_Model_emxInit_real_T(&U, 2);
  Multirotor_Model_emxInit_real_T(&phi, 2);
  Multirotor_Model_emxInit_real_T(&alpha, 2);
  Multirotor_Model_emxInit_real_T(&cl2d, 2);
  Multirotor_Model_emxInit_real_T(&cd, 2);
  Multirotor_Model_emxInit_real_T(&cl, 2);
  Multirotor_Model_emxInit_real_T(&dL, 2);
  Multirotor_Model_emxInit_real_T(&dD, 2);
  Multirotor_Model_emxInit_real_T(&dFz, 2);
  Multirotor_Model_emxInit_real_T(&dFtan, 2);
  Multirotor_Model_emxInit_real_T(&dQ, 2);
  Multirotor_Model_emxInit_real_T(&dMy, 2);
  Multirotor_Model_emxInit_real_T(&dMx, 2);
  Multirotor_Model_emxInit_real_T(&Fx, 1);
  Multirotor_Model_emxInit_real_T(&Fy, 1);
  Multirotor_Model_emxInit_real_T(&Fz, 1);
  Multirotor_Model_emxInit_real_T(&Q, 1);
  Multirotor_Model_emxInit_real_T(&Mx, 1);
  Multirotor_Model_emxInit_real_T(&My, 1);
  Multirotor_Model_emxInit_real_T(&error2, 1);
  Multirotor_Model_emxInit_real_T(&error, 2);
  Multirotor_Model_emxInit_real_T(&b_psi, 1);
  Multirotor_Model_emxInit_real_T(&dFtan_0, 1);
  Multirotor_Model_emxInit_real_T(&dFtan_1, 1);
  Multirotor_Model_emxInit_real_T(&dFz_0, 1);
  Multirotor_Model_emxInit_real_T(&dQ_0, 1);
  Multirotor_Model_emxInit_real_T(&dMx_0, 1);
  Multirotor_Model_emxInit_real_T(&dMy_0, 1);

  /* Outputs for Iterator SubSystem: '<S510>/For Each Subsystem' incorporates:
   *  ForEach: '<S514>/For Each'
   */
  while (ForEach_itr < 4) {
    /* ForEachSliceSelector generated from: '<S514>/Input' */
    rtb_ImpSel_InsertedFor_Input_at = Multirotor_Model_1_B.RPMs[ForEach_itr];

    /* Integrator: '<S520>/Integrator' */
    Multirotor_Model_1_B.CoreSubsys[ForEach_itr].nHzrps =
      Multirotor_Model_1_X.CoreSubsys[ForEach_itr].Integrator_CSTATE_pb;

    /* Gain: '<S518>/rps to rpm' */
    a_a = Multirotor_Model_1_P.CoreSubsys.rpstorpm_Gain *
      Multirotor_Model_1_B.CoreSubsys[ForEach_itr].nHzrps;

    /* MATLAB Function: '<S521>/MATLAB Function' incorporates:
     *  Constant: '<S521>/Constant'
     */
    rtb_Saturation_c = Multirotor_Model_1_P.ip.N_bet;
    rtb_Saturation_e = Multirotor_Model_1_P.ip.rho;
    ssw2 = Multirotor_Model_1_P.ip.itermax_bemt;
    Load4 = Multirotor_Model_1_P.ip.rad * 12.0 * 0.0254;
    Load5 = 3.3121686421112381E-170;
    Load6 = fabs(Multirotor_Model_1_B.Delay[18]);
    if (Load6 > 3.3121686421112381E-170) {
      a = 1.0;
      Load5 = Load6;
    } else {
      t = Load6 / 3.3121686421112381E-170;
      a = t * t;
    }

    Load6 = fabs(Multirotor_Model_1_B.Delay[19]);
    if (Load6 > Load5) {
      t = Load5 / Load6;
      a = a * t * t + 1.0;
      Load5 = Load6;
    } else {
      t = Load6 / Load5;
      a += t * t;
    }

    a = Load5 * sqrt(a);
    Load5 = Load4 * Load4 * 3.1415926535897931;
    Load6 = a_a * 2.0 * 3.1415926535897931 / 60.0 * Load4;
    t = -Multirotor_Model_1_B.Delay[20] / Load6;
    mu_tmp = a / Load6;
    muz = a * 0.0 / Load6;
    dr = Multirotor_Model_1_P.ip.dr;
    root_cut = Multirotor_Model_1_P.ip.root_cut;
    if (rtIsNaN(Multirotor_Model_1_P.ip.delpsi) || rtIsNaN(360.0 -
         Multirotor_Model_1_P.ip.delpsi)) {
      b_i = psi->size[0] * psi->size[1];
      psi->size[0] = 1;
      psi->size[1] = 1;
      Multir_emxEnsureCapacity_real_T(psi, b_i);
      psi->data[0] = (rtNaN);
    } else if ((Multirotor_Model_1_P.ip.delpsi == 0.0) || ((0.0 < 360.0 -
                 Multirotor_Model_1_P.ip.delpsi) &&
                (Multirotor_Model_1_P.ip.delpsi < 0.0)) || ((360.0 -
                 Multirotor_Model_1_P.ip.delpsi < 0.0) &&
                (Multirotor_Model_1_P.ip.delpsi > 0.0))) {
      psi->size[0] = 1;
      psi->size[1] = 0;
    } else if (rtIsInf(360.0 - Multirotor_Model_1_P.ip.delpsi) && (rtIsInf
                (Multirotor_Model_1_P.ip.delpsi) || (360.0 -
                 Multirotor_Model_1_P.ip.delpsi == 0.0))) {
      b_i = psi->size[0] * psi->size[1];
      psi->size[0] = 1;
      psi->size[1] = 1;
      Multir_emxEnsureCapacity_real_T(psi, b_i);
      psi->data[0] = (rtNaN);
    } else if (rtIsInf(Multirotor_Model_1_P.ip.delpsi)) {
      b_i = psi->size[0] * psi->size[1];
      psi->size[0] = 1;
      psi->size[1] = 1;
      Multir_emxEnsureCapacity_real_T(psi, b_i);
      psi->data[0] = 0.0;
    } else if (floor(Multirotor_Model_1_P.ip.delpsi) ==
               Multirotor_Model_1_P.ip.delpsi) {
      b_i = psi->size[0] * psi->size[1];
      psi->size[0] = 1;
      loop_ub = (int32_T)floor((360.0 - Multirotor_Model_1_P.ip.delpsi) /
        Multirotor_Model_1_P.ip.delpsi);
      psi->size[1] = loop_ub + 1;
      Multir_emxEnsureCapacity_real_T(psi, b_i);
      for (b_i = 0; b_i <= loop_ub; b_i++) {
        psi->data[b_i] = Multirotor_Model_1_P.ip.delpsi * (real_T)b_i;
      }
    } else {
      Multirotor_Mode_eml_float_colon(Multirotor_Model_1_P.ip.delpsi, 360.0 -
        Multirotor_Model_1_P.ip.delpsi, psi);
    }

    b_i = b_psi->size[0];
    b_psi->size[0] = psi->size[1];
    Multir_emxEnsureCapacity_real_T(b_psi, b_i);
    loop_ub = psi->size[1];
    for (b_i = 0; b_i < loop_ub; b_i++) {
      b_psi->data[b_i] = psi->data[b_i] * 3.1415926535897931 / 180.0;
    }

    b_i = theta->size[0] * theta->size[1];
    theta->size[0] = (int32_T)Multirotor_Model_1_P.ip.N_bet;
    theta->size[1] = b_psi->size[0];
    Multir_emxEnsureCapacity_real_T(theta, b_i);
    loop_ub = (int32_T)Multirotor_Model_1_P.ip.N_bet * b_psi->size[0] - 1;
    for (b_i = 0; b_i <= loop_ub; b_i++) {
      theta->data[b_i] = 0.0;
    }

    b_i = lambdai->size[0] * lambdai->size[1];
    lambdai->size[0] = (int32_T)Multirotor_Model_1_P.ip.N_bet;
    lambdai->size[1] = b_psi->size[0];
    Multir_emxEnsureCapacity_real_T(lambdai, b_i);
    loop_ub = (int32_T)Multirotor_Model_1_P.ip.N_bet * b_psi->size[0] - 1;
    for (b_i = 0; b_i <= loop_ub; b_i++) {
      lambdai->data[b_i] = 0.0;
    }

    b_i = lambdai_old->size[0] * lambdai_old->size[1];
    lambdai_old->size[0] = (int32_T)Multirotor_Model_1_P.ip.N_bet;
    lambdai_old->size[1] = b_psi->size[0];
    Multir_emxEnsureCapacity_real_T(lambdai_old, b_i);
    loop_ub = (int32_T)Multirotor_Model_1_P.ip.N_bet * b_psi->size[0] - 1;
    for (b_i = 0; b_i <= loop_ub; b_i++) {
      lambdai_old->data[b_i] = 0.0;
    }

    b_i = Ut->size[0] * Ut->size[1];
    Ut->size[0] = (int32_T)Multirotor_Model_1_P.ip.N_bet;
    Ut->size[1] = b_psi->size[0];
    Multir_emxEnsureCapacity_real_T(Ut, b_i);
    loop_ub = (int32_T)Multirotor_Model_1_P.ip.N_bet * b_psi->size[0] - 1;
    for (b_i = 0; b_i <= loop_ub; b_i++) {
      Ut->data[b_i] = 0.0;
    }

    b_i = Up->size[0] * Up->size[1];
    Up->size[0] = (int32_T)Multirotor_Model_1_P.ip.N_bet;
    Up->size[1] = b_psi->size[0];
    Multir_emxEnsureCapacity_real_T(Up, b_i);
    loop_ub = (int32_T)Multirotor_Model_1_P.ip.N_bet * b_psi->size[0] - 1;
    for (b_i = 0; b_i <= loop_ub; b_i++) {
      Up->data[b_i] = 0.0;
    }

    b_i = U->size[0] * U->size[1];
    U->size[0] = (int32_T)Multirotor_Model_1_P.ip.N_bet;
    U->size[1] = b_psi->size[0];
    Multir_emxEnsureCapacity_real_T(U, b_i);
    loop_ub = (int32_T)Multirotor_Model_1_P.ip.N_bet * b_psi->size[0] - 1;
    for (b_i = 0; b_i <= loop_ub; b_i++) {
      U->data[b_i] = 0.0;
    }

    b_i = phi->size[0] * phi->size[1];
    phi->size[0] = (int32_T)Multirotor_Model_1_P.ip.N_bet;
    phi->size[1] = b_psi->size[0];
    Multir_emxEnsureCapacity_real_T(phi, b_i);
    loop_ub = (int32_T)Multirotor_Model_1_P.ip.N_bet * b_psi->size[0] - 1;
    for (b_i = 0; b_i <= loop_ub; b_i++) {
      phi->data[b_i] = 0.0;
    }

    b_i = alpha->size[0] * alpha->size[1];
    alpha->size[0] = (int32_T)Multirotor_Model_1_P.ip.N_bet;
    alpha->size[1] = b_psi->size[0];
    Multir_emxEnsureCapacity_real_T(alpha, b_i);
    loop_ub = (int32_T)Multirotor_Model_1_P.ip.N_bet * b_psi->size[0] - 1;
    for (b_i = 0; b_i <= loop_ub; b_i++) {
      alpha->data[b_i] = 0.0;
    }

    b_i = cl2d->size[0] * cl2d->size[1];
    cl2d->size[0] = (int32_T)Multirotor_Model_1_P.ip.N_bet;
    cl2d->size[1] = b_psi->size[0];
    Multir_emxEnsureCapacity_real_T(cl2d, b_i);
    loop_ub = (int32_T)Multirotor_Model_1_P.ip.N_bet * b_psi->size[0] - 1;
    for (b_i = 0; b_i <= loop_ub; b_i++) {
      cl2d->data[b_i] = 0.0;
    }

    b_i = cd->size[0] * cd->size[1];
    cd->size[0] = (int32_T)Multirotor_Model_1_P.ip.N_bet;
    cd->size[1] = b_psi->size[0];
    Multir_emxEnsureCapacity_real_T(cd, b_i);
    loop_ub = (int32_T)Multirotor_Model_1_P.ip.N_bet * b_psi->size[0] - 1;
    for (b_i = 0; b_i <= loop_ub; b_i++) {
      cd->data[b_i] = 0.0;
    }

    b_i = cl->size[0] * cl->size[1];
    cl->size[0] = (int32_T)Multirotor_Model_1_P.ip.N_bet;
    cl->size[1] = b_psi->size[0];
    Multir_emxEnsureCapacity_real_T(cl, b_i);
    loop_ub = (int32_T)Multirotor_Model_1_P.ip.N_bet * b_psi->size[0] - 1;
    for (b_i = 0; b_i <= loop_ub; b_i++) {
      cl->data[b_i] = 0.0;
    }

    b_i = dL->size[0] * dL->size[1];
    dL->size[0] = (int32_T)Multirotor_Model_1_P.ip.N_bet;
    dL->size[1] = b_psi->size[0];
    Multir_emxEnsureCapacity_real_T(dL, b_i);
    loop_ub = (int32_T)Multirotor_Model_1_P.ip.N_bet * b_psi->size[0] - 1;
    for (b_i = 0; b_i <= loop_ub; b_i++) {
      dL->data[b_i] = 0.0;
    }

    b_i = dD->size[0] * dD->size[1];
    dD->size[0] = (int32_T)Multirotor_Model_1_P.ip.N_bet;
    dD->size[1] = b_psi->size[0];
    Multir_emxEnsureCapacity_real_T(dD, b_i);
    loop_ub = (int32_T)Multirotor_Model_1_P.ip.N_bet * b_psi->size[0] - 1;
    for (b_i = 0; b_i <= loop_ub; b_i++) {
      dD->data[b_i] = 0.0;
    }

    b_i = dFz->size[0] * dFz->size[1];
    dFz->size[0] = (int32_T)Multirotor_Model_1_P.ip.N_bet;
    dFz->size[1] = b_psi->size[0];
    Multir_emxEnsureCapacity_real_T(dFz, b_i);
    loop_ub = (int32_T)Multirotor_Model_1_P.ip.N_bet * b_psi->size[0] - 1;
    for (b_i = 0; b_i <= loop_ub; b_i++) {
      dFz->data[b_i] = 0.0;
    }

    b_i = dFtan->size[0] * dFtan->size[1];
    dFtan->size[0] = (int32_T)Multirotor_Model_1_P.ip.N_bet;
    dFtan->size[1] = b_psi->size[0];
    Multir_emxEnsureCapacity_real_T(dFtan, b_i);
    loop_ub = (int32_T)Multirotor_Model_1_P.ip.N_bet * b_psi->size[0] - 1;
    for (b_i = 0; b_i <= loop_ub; b_i++) {
      dFtan->data[b_i] = 0.0;
    }

    b_i = dQ->size[0] * dQ->size[1];
    dQ->size[0] = (int32_T)Multirotor_Model_1_P.ip.N_bet;
    dQ->size[1] = b_psi->size[0];
    Multir_emxEnsureCapacity_real_T(dQ, b_i);
    loop_ub = (int32_T)Multirotor_Model_1_P.ip.N_bet * b_psi->size[0] - 1;
    for (b_i = 0; b_i <= loop_ub; b_i++) {
      dQ->data[b_i] = 0.0;
    }

    b_i = dMy->size[0] * dMy->size[1];
    dMy->size[0] = (int32_T)Multirotor_Model_1_P.ip.N_bet;
    dMy->size[1] = b_psi->size[0];
    Multir_emxEnsureCapacity_real_T(dMy, b_i);
    loop_ub = (int32_T)Multirotor_Model_1_P.ip.N_bet * b_psi->size[0] - 1;
    for (b_i = 0; b_i <= loop_ub; b_i++) {
      dMy->data[b_i] = 0.0;
    }

    b_i = dMx->size[0] * dMx->size[1];
    dMx->size[0] = (int32_T)Multirotor_Model_1_P.ip.N_bet;
    dMx->size[1] = b_psi->size[0];
    Multir_emxEnsureCapacity_real_T(dMx, b_i);
    loop_ub = (int32_T)Multirotor_Model_1_P.ip.N_bet * b_psi->size[0] - 1;
    for (b_i = 0; b_i <= loop_ub; b_i++) {
      dMx->data[b_i] = 0.0;
    }

    b_i = Fx->size[0];
    Fx->size[0] = b_psi->size[0];
    Multir_emxEnsureCapacity_real_T(Fx, b_i);
    loop_ub = b_psi->size[0];
    for (b_i = 0; b_i < loop_ub; b_i++) {
      Fx->data[b_i] = 0.0;
    }

    b_i = Fy->size[0];
    Fy->size[0] = b_psi->size[0];
    Multir_emxEnsureCapacity_real_T(Fy, b_i);
    loop_ub = b_psi->size[0];
    for (b_i = 0; b_i < loop_ub; b_i++) {
      Fy->data[b_i] = 0.0;
    }

    b_i = Fz->size[0];
    Fz->size[0] = b_psi->size[0];
    Multir_emxEnsureCapacity_real_T(Fz, b_i);
    loop_ub = b_psi->size[0];
    for (b_i = 0; b_i < loop_ub; b_i++) {
      Fz->data[b_i] = 0.0;
    }

    b_i = Q->size[0];
    Q->size[0] = b_psi->size[0];
    Multir_emxEnsureCapacity_real_T(Q, b_i);
    loop_ub = b_psi->size[0];
    for (b_i = 0; b_i < loop_ub; b_i++) {
      Q->data[b_i] = 0.0;
    }

    b_i = Mx->size[0];
    Mx->size[0] = b_psi->size[0];
    Multir_emxEnsureCapacity_real_T(Mx, b_i);
    loop_ub = b_psi->size[0];
    for (b_i = 0; b_i < loop_ub; b_i++) {
      Mx->data[b_i] = 0.0;
    }

    b_i = My->size[0];
    My->size[0] = b_psi->size[0];
    Multir_emxEnsureCapacity_real_T(My, b_i);
    loop_ub = b_psi->size[0];
    for (b_i = 0; b_i < loop_ub; b_i++) {
      My->data[b_i] = 0.0;
    }

    b_i = error2->size[0];
    error2->size[0] = (int32_T)Multirotor_Model_1_P.ip.itermax_bemt;
    Multir_emxEnsureCapacity_real_T(error2, b_i);
    loop_ub = (int32_T)Multirotor_Model_1_P.ip.itermax_bemt;
    for (b_i = 0; b_i < loop_ub; b_i++) {
      error2->data[b_i] = 0.0;
    }

    lambda0 = 0.0;
    lambda = t;
    lambda_1 = 0.0;
    i = 0;
    exitg1 = false;
    while ((!exitg1) && (i <= (int32_T)ssw2 - 1)) {
      kx = tan(rt_atan2d_snf(mu_tmp, muz + lambda0) / 2.0) * 2.0488647740803;
      ky = -2.0 * mu_tmp * 0.0;
      for (c_tmp = 0; c_tmp < b_psi->size[0]; c_tmp++) {
        loop_ub = (int32_T)((1.0 - root_cut) + rtb_Saturation_c);
        for (b_i = 0; b_i < loop_ub; b_i++) {
          i_0 = root_cut + (real_T)b_i;
          theta_tmp = cos(b_psi->data[c_tmp]);
          theta_tmp_0 = sin(b_psi->data[c_tmp]);
          theta->data[((int32_T)i_0 + theta->size[0] * c_tmp) - 1] =
            (Multirotor_Model_1_P.ip.thetacol[(int32_T)i_0 - 1] +
             Multirotor_Model_1_P.ip.thetac * theta_tmp) +
            Multirotor_Model_1_P.ip.thetas * theta_tmp_0;
          lambdai_old->data[((int32_T)i_0 + lambdai_old->size[0] * c_tmp) - 1] =
            lambdai->data[(lambdai->size[0] * c_tmp + (int32_T)i_0) - 1];
          tmp_1 = Multirotor_Model_1_P.ip.r[(int32_T)i_0 - 1];
          lambdai->data[((int32_T)i_0 + lambdai->size[0] * c_tmp) - 1] = ((tmp_1
            * kx * theta_tmp + 1.0) + tmp_1 * ky * theta_tmp_0) * lambda0;
          Ut->data[((int32_T)i_0 + Ut->size[0] * c_tmp) - 1] = (tmp_1 +
            theta_tmp_0 * mu_tmp) * Load6;
          Up->data[((int32_T)i_0 + Up->size[0] * c_tmp) - 1] = ((lambdai->data
            [(lambdai->size[0] * c_tmp + (int32_T)i_0) - 1] + t) + muz) * Load6;
          a = Up->data[(Up->size[0] * c_tmp + (int32_T)i_0) - 1];
          b_a = Ut->data[(Ut->size[0] * c_tmp + (int32_T)i_0) - 1];
          U->data[((int32_T)i_0 + U->size[0] * c_tmp) - 1] = sqrt(a * a + b_a *
            b_a);
          phi->data[((int32_T)i_0 + phi->size[0] * c_tmp) - 1] = rt_atan2d_snf
            (Up->data[(Up->size[0] * c_tmp + (int32_T)i_0) - 1], Ut->data
             [(Ut->size[0] * c_tmp + (int32_T)i_0) - 1]);
          alpha->data[((int32_T)i_0 + alpha->size[0] * c_tmp) - 1] = theta->
            data[(theta->size[0] * c_tmp + (int32_T)i_0) - 1] - phi->data
            [(phi->size[0] * c_tmp + (int32_T)i_0) - 1];
          if (alpha->data[(alpha->size[0] * c_tmp + (int32_T)i_0) - 1] >
              3.1415926535897931) {
            alpha->data[((int32_T)i_0 + alpha->size[0] * c_tmp) - 1] =
              3.1415926535897931;
          }

          if (alpha->data[(alpha->size[0] * c_tmp + (int32_T)i_0) - 1] <
              -3.1415926535897931) {
            alpha->data[((int32_T)i_0 + alpha->size[0] * c_tmp) - 1] =
              9.42477796076938;
          }

          Multirotor_Mode_fn_clcdcm_data4(alpha->data[((int32_T)i_0 +
            alpha->size[0] * c_tmp) - 1], Multirotor_Model_1_P.ip.data,
            Multirotor_Model_1_P.ip.data_high, &cl2d->data[((int32_T)i_0 +
            cl2d->size[0] * c_tmp) - 1], &cd->data[((int32_T)i_0 + cd->size[0] *
            c_tmp) - 1], &a);
          cl->data[((int32_T)i_0 + cl->size[0] * c_tmp) - 1] = cl2d->data
            [(cl2d->size[0] * c_tmp + (int32_T)i_0) - 1] / (1.0 /
            Multirotor_Model_1_P.ip.AR + 1.0);
          a = U->data[(U->size[0] * c_tmp + (int32_T)i_0) - 1];
          b_a = Multirotor_Model_1_P.ip.chd[(int32_T)i_0 - 1];
          tmp_2 = Load4 * Load4;
          dL->data[((int32_T)i_0 + dL->size[0] * c_tmp) - 1] = 0.5 *
            rtb_Saturation_e * (a * a) * b_a * cl->data[(cl->size[0] * c_tmp +
            (int32_T)i_0) - 1] * dr * tmp_2;
          a = U->data[(U->size[0] * c_tmp + (int32_T)i_0) - 1];
          dD->data[((int32_T)i_0 + dD->size[0] * c_tmp) - 1] = 0.5 *
            rtb_Saturation_e * (a * a) * b_a * cd->data[(cd->size[0] * c_tmp +
            (int32_T)i_0) - 1] * dr * tmp_2;
          a = sin(phi->data[(phi->size[0] * c_tmp + (int32_T)i_0) - 1]);
          b_a = cos(phi->data[(phi->size[0] * c_tmp + (int32_T)i_0) - 1]);
          dFz->data[((int32_T)i_0 + dFz->size[0] * c_tmp) - 1] = dL->data
            [(dL->size[0] * c_tmp + (int32_T)i_0) - 1] * b_a - dD->data
            [(dD->size[0] * c_tmp + (int32_T)i_0) - 1] * a;
          dFtan->data[((int32_T)i_0 + dFtan->size[0] * c_tmp) - 1] = dL->data
            [(dL->size[0] * c_tmp + (int32_T)i_0) - 1] * a + dD->data[(dD->size
            [0] * c_tmp + (int32_T)i_0) - 1] * b_a;
          dQ->data[((int32_T)i_0 + dQ->size[0] * c_tmp) - 1] = dFtan->data
            [(dFtan->size[0] * c_tmp + (int32_T)i_0) - 1] * tmp_1 * Load4;
          dMy->data[((int32_T)i_0 + dMy->size[0] * c_tmp) - 1] = dFz->data
            [(dFz->size[0] * c_tmp + (int32_T)i_0) - 1] * tmp_1 * theta_tmp *
            Load4;
          dMx->data[((int32_T)i_0 + dMx->size[0] * c_tmp) - 1] = -dFz->data
            [(dFz->size[0] * c_tmp + (int32_T)i_0) - 1] * tmp_1 * theta_tmp_0 *
            Load4;
        }

        loop_ub = dFtan->size[0];
        b_i = dFtan_0->size[0];
        dFtan_0->size[0] = loop_ub;
        Multir_emxEnsureCapacity_real_T(dFtan_0, b_i);
        for (b_i = 0; b_i < loop_ub; b_i++) {
          dFtan_0->data[b_i] = dFtan->data[dFtan->size[0] * c_tmp + b_i];
        }

        Fx->data[c_tmp] = -Multiroto_combineVectorElements(dFtan_0) * sin
          (b_psi->data[c_tmp]);
        loop_ub = dFtan->size[0];
        b_i = dFtan_1->size[0];
        dFtan_1->size[0] = loop_ub;
        Multir_emxEnsureCapacity_real_T(dFtan_1, b_i);
        for (b_i = 0; b_i < loop_ub; b_i++) {
          dFtan_1->data[b_i] = dFtan->data[dFtan->size[0] * c_tmp + b_i];
        }

        Fy->data[c_tmp] = Multiroto_combineVectorElements(dFtan_1) * cos
          (b_psi->data[c_tmp]);
        loop_ub = dFz->size[0];
        b_i = dFz_0->size[0];
        dFz_0->size[0] = loop_ub;
        Multir_emxEnsureCapacity_real_T(dFz_0, b_i);
        for (b_i = 0; b_i < loop_ub; b_i++) {
          dFz_0->data[b_i] = dFz->data[dFz->size[0] * c_tmp + b_i];
        }

        Fz->data[c_tmp] = Multiroto_combineVectorElements(dFz_0);
        loop_ub = dQ->size[0];
        b_i = dQ_0->size[0];
        dQ_0->size[0] = loop_ub;
        Multir_emxEnsureCapacity_real_T(dQ_0, b_i);
        for (b_i = 0; b_i < loop_ub; b_i++) {
          dQ_0->data[b_i] = dQ->data[dQ->size[0] * c_tmp + b_i];
        }

        Q->data[c_tmp] = Multiroto_combineVectorElements(dQ_0);
        loop_ub = dMx->size[0];
        b_i = dMx_0->size[0];
        dMx_0->size[0] = loop_ub;
        Multir_emxEnsureCapacity_real_T(dMx_0, b_i);
        for (b_i = 0; b_i < loop_ub; b_i++) {
          dMx_0->data[b_i] = dMx->data[dMx->size[0] * c_tmp + b_i];
        }

        Mx->data[c_tmp] = Multiroto_combineVectorElements(dMx_0);
        loop_ub = dMy->size[0];
        b_i = dMy_0->size[0];
        dMy_0->size[0] = loop_ub;
        Multir_emxEnsureCapacity_real_T(dMy_0, b_i);
        for (b_i = 0; b_i < loop_ub; b_i++) {
          dMy_0->data[b_i] = dMy->data[dMy->size[0] * c_tmp + b_i];
        }

        My->data[c_tmp] = Multiroto_combineVectorElements(dMy_0);
      }

      a = Multiroto_combineVectorElements(Fz) / (real_T)Fz->size[0] *
        Multirotor_Model_1_P.ip.Nb / (rtb_Saturation_e * Load5 * (Load6 * Load6));
      if ((real_T)i + 1.0 <= ssw2) {
        lambda_1 = sqrt((sqrt(a * a + rt_powd_snf(mu_tmp, 4.0)) - mu_tmp *
                         mu_tmp) * 0.5) + t;
      }

      if ((real_T)i + 1.0 > ssw2) {
        lambda_1 = (0.5 * a / sqrt(mu_tmp * mu_tmp + lambda * lambda) + mu_tmp *
                    0.0 * 0.0) + t;
      }

      lambda += (lambda_1 - lambda) * 0.5;
      lambda0 = lambda - t;
      b_i = error->size[0] * error->size[1];
      error->size[0] = lambdai->size[0];
      error->size[1] = lambdai->size[1];
      Multir_emxEnsureCapacity_real_T(error, b_i);
      loop_ub = lambdai->size[0] * lambdai->size[1] - 1;
      for (b_i = 0; b_i <= loop_ub; b_i++) {
        error->data[b_i] = lambdai->data[b_i] - lambdai_old->data[b_i];
      }

      a = 0.0;
      for (b_i = 0; b_i < b_psi->size[0]; b_i++) {
        c_tmp = (int32_T)((1.0 - root_cut) + rtb_Saturation_c);
        for (loop_ub = 0; loop_ub < c_tmp; loop_ub++) {
          kx = error->data[((int32_T)(root_cut + (real_T)loop_ub) + error->size
                            [0] * b_i) - 1];
          a += kx * kx;
        }
      }

      error2->data[i] = a;
      if ((error2->data[i] < Multirotor_Model_1_P.ip.cutoff_bemt) && ((real_T)i
           + 1.0 > 1.0)) {
        exitg1 = true;
      } else {
        i++;
      }
    }

    b_i = Fx->size[0];
    Multir_emxEnsureCapacity_real_T(Fx, b_i);
    loop_ub = Fx->size[0];
    for (b_i = 0; b_i < loop_ub; b_i++) {
      Fx->data[b_i] *= Multirotor_Model_1_P.ip.kt;
    }

    b_i = Fy->size[0];
    Multir_emxEnsureCapacity_real_T(Fy, b_i);
    loop_ub = Fy->size[0];
    for (b_i = 0; b_i < loop_ub; b_i++) {
      Fy->data[b_i] *= Multirotor_Model_1_P.ip.kt;
    }

    b_i = Fz->size[0];
    Multir_emxEnsureCapacity_real_T(Fz, b_i);
    loop_ub = Fz->size[0];
    for (b_i = 0; b_i < loop_ub; b_i++) {
      Fz->data[b_i] *= Multirotor_Model_1_P.ip.kt;
    }

    Multirotor_Model_1_B.CoreSubsys[ForEach_itr].load[0] =
      Multiroto_combineVectorElements(Fx) / (real_T)Fx->size[0] *
      Multirotor_Model_1_P.ip.Nb;
    Multirotor_Model_1_B.CoreSubsys[ForEach_itr].load[1] =
      Multiroto_combineVectorElements(Fy) / (real_T)Fy->size[0] *
      Multirotor_Model_1_P.ip.Nb * 0.0;
    Multirotor_Model_1_B.CoreSubsys[ForEach_itr].load[2] =
      Multiroto_combineVectorElements(Fz) / (real_T)Fz->size[0] *
      Multirotor_Model_1_P.ip.Nb;
    Multirotor_Model_1_B.CoreSubsys[ForEach_itr].load[3] =
      Multiroto_combineVectorElements(Mx) / (real_T)Mx->size[0] *
      Multirotor_Model_1_P.ip.Nb;
    Multirotor_Model_1_B.CoreSubsys[ForEach_itr].load[4] =
      Multiroto_combineVectorElements(My) / (real_T)My->size[0] *
      Multirotor_Model_1_P.ip.Nb;
    Multirotor_Model_1_B.CoreSubsys[ForEach_itr].load[5] =
      Multiroto_combineVectorElements(Q) / (real_T)Q->size[0] *
      -Multirotor_Model_1_P.ip.Nb;

    /* End of MATLAB Function: '<S521>/MATLAB Function' */

    /* Gain: '<S518>/Multiply' */
    Multirotor_Model_1_B.CoreSubsys[ForEach_itr].Torque =
      Multirotor_Model_1_P.CoreSubsys.Multiply_Gain *
      Multirotor_Model_1_B.CoreSubsys[ForEach_itr].load[5];
    if (rtmIsMajorTimeStep(Multirotor_Model_1_M)) {
    }

    /* TransferFcn: '<S523>/Transfer Fcn' */
    Multirotor_Model_1_B.CoreSubsys[ForEach_itr].i = 0.0;
    Multirotor_Model_1_B.CoreSubsys[ForEach_itr].i +=
      Multirotor_Model_1_P.CoreSubsys.TransferFcn_C *
      Multirotor_Model_1_X.CoreSubsys[ForEach_itr].TransferFcn_CSTATE;

    /* DataTypeConversion: '<S523>/Data Type Conversion1' incorporates:
     *  Constant: '<S527>/Constant'
     *  RelationalOperator: '<S527>/Compare'
     */
    Multirotor_Model_1_B.CoreSubsys[ForEach_itr].DataTypeConversion1 =
      (Multirotor_Model_1_B.CoreSubsys[ForEach_itr].i >
       Multirotor_Model_1_P.CoreSubsys.CompareToConstant1_const);

    /* Integrator: '<S523>/Integrator1' */
    /* Limited  Integrator  */
    if (Multirotor_Model_1_X.CoreSubsys[ForEach_itr].Integrator1_CSTATE_c >=
        Multirotor_Model_1_P.Q_max * 3600.0) {
      Multirotor_Model_1_X.CoreSubsys[ForEach_itr].Integrator1_CSTATE_c =
        Multirotor_Model_1_P.Q_max * 3600.0;
    } else {
      if (Multirotor_Model_1_X.CoreSubsys[ForEach_itr].Integrator1_CSTATE_c <=
          Multirotor_Model_1_P.CoreSubsys.Integrator1_LowerSat) {
        Multirotor_Model_1_X.CoreSubsys[ForEach_itr].Integrator1_CSTATE_c =
          Multirotor_Model_1_P.CoreSubsys.Integrator1_LowerSat;
      }
    }

    /* Gain: '<S523>/Gain3' incorporates:
     *  Integrator: '<S523>/Integrator1'
     */
    Multirotor_Model_1_B.CoreSubsys[ForEach_itr].it =
      Multirotor_Model_1_P.CoreSubsys.Gain3_Gain *
      Multirotor_Model_1_X.CoreSubsys[ForEach_itr].Integrator1_CSTATE_c;

    /* Saturate: '<S523>/Saturation' incorporates:
     *  Saturate: '<S523>/Saturation1'
     *  Saturate: '<S523>/Saturation2'
     */
    Load4 = Multirotor_Model_1_P.Q_max * 0.999;
    if (Multirotor_Model_1_B.CoreSubsys[ForEach_itr].it > Load4) {
      rtb_Saturation_c = Load4;
    } else if (Multirotor_Model_1_B.CoreSubsys[ForEach_itr].it <
               Multirotor_Model_1_P.CoreSubsys.Saturation_LowerSat) {
      rtb_Saturation_c = Multirotor_Model_1_P.CoreSubsys.Saturation_LowerSat;
    } else {
      rtb_Saturation_c = Multirotor_Model_1_B.CoreSubsys[ForEach_itr].it;
    }

    /* End of Saturate: '<S523>/Saturation' */

    /* Product: '<S523>/Divide1' incorporates:
     *  Constant: '<S523>/Capacity [Ah]'
     *  Constant: '<S523>/Max Charge [Ah]'
     *  Sum: '<S523>/Add1'
     */
    rtb_Saturation_e = (Multirotor_Model_1_P.Q_max -
                        Multirotor_Model_1_B.CoreSubsys[ForEach_itr].it) /
      Multirotor_Model_1_P.Q_max;

    /* Integrator: '<S532>/Integrator' */
    Multirotor_Model_1_B.CoreSubsys[ForEach_itr].Integrator =
      Multirotor_Model_1_X.CoreSubsys[ForEach_itr].Integrator_CSTATE_a;

    /* Fcn: '<S529>/Polarisation Over Voltage' incorporates:
     *  Fcn: '<S529>/Polarisation Ohmic Voltage'
     */
    ssw2 = -Multirotor_Model_1_B.CoreSubsys[ForEach_itr].DataTypeConversion1 *
      0.0087662 * 3.0 / (3.0 - rtb_Saturation_c);

    /* Fcn: '<S529>/Polarisation Over Voltage' */
    Multirotor_Model_1_B.CoreSubsys[ForEach_itr].PolarisationOverVoltage = ssw2 *
      rtb_Saturation_c;

    /* Fcn: '<S529>/Polarisation Ohmic Voltage' */
    Multirotor_Model_1_B.CoreSubsys[ForEach_itr].PolarisationOhmicVoltage = ssw2
      * Multirotor_Model_1_B.CoreSubsys[ForEach_itr].i;

    /* Sum: '<S529>/Sum' */
    Multirotor_Model_1_B.CoreSubsys[ForEach_itr].Sum =
      Multirotor_Model_1_B.CoreSubsys[ForEach_itr].PolarisationOverVoltage +
      Multirotor_Model_1_B.CoreSubsys[ForEach_itr].PolarisationOhmicVoltage;

    /* DataTypeConversion: '<S523>/Data Type Conversion2' incorporates:
     *  Constant: '<S526>/Constant'
     *  RelationalOperator: '<S526>/Compare'
     */
    Multirotor_Model_1_B.CoreSubsys[ForEach_itr].DataTypeConversion2 =
      (Multirotor_Model_1_B.CoreSubsys[ForEach_itr].i <
       Multirotor_Model_1_P.CoreSubsys.CompareToConstant_const);

    /* Saturate: '<S523>/Saturation1' */
    ssw2 = -Multirotor_Model_1_P.Q_max * 0.999 * 0.1;
    if (Multirotor_Model_1_B.CoreSubsys[ForEach_itr].it > Load4) {
      ssw2 = Load4;
    } else {
      if (!(Multirotor_Model_1_B.CoreSubsys[ForEach_itr].it < ssw2)) {
        ssw2 = Multirotor_Model_1_B.CoreSubsys[ForEach_itr].it;
      }
    }

    /* Fcn: '<S528>/Polarisation Over Voltage' incorporates:
     *  Fcn: '<S528>/Polarisation Ohmic Voltage'
     */
    Load6 = -Multirotor_Model_1_B.CoreSubsys[ForEach_itr].DataTypeConversion2 *
      0.0087662 * 3.0;

    /* Fcn: '<S528>/Polarisation Over Voltage' */
    Multirotor_Model_1_B.CoreSubsys[ForEach_itr].PolarisationOverVoltage_p =
      Load6 / (3.0 - ssw2) * ssw2;

    /* Fcn: '<S528>/Polarisation Ohmic Voltage' */
    Multirotor_Model_1_B.CoreSubsys[ForEach_itr].PolarisationOhmicVoltage_i =
      Load6 / (ssw2 + 0.30000000000000004) *
      Multirotor_Model_1_B.CoreSubsys[ForEach_itr].i;

    /* Sum: '<S528>/Sum' */
    Multirotor_Model_1_B.CoreSubsys[ForEach_itr].Sum_h =
      Multirotor_Model_1_B.CoreSubsys[ForEach_itr].PolarisationOverVoltage_p +
      Multirotor_Model_1_B.CoreSubsys[ForEach_itr].PolarisationOhmicVoltage_i;

    /* Saturate: '<S523>/Saturation2' */
    if (!(Multirotor_Model_1_B.CoreSubsys[ForEach_itr].it > Load4)) {
      if (Multirotor_Model_1_B.CoreSubsys[ForEach_itr].it <
          Multirotor_Model_1_P.CoreSubsys.Saturation2_LowerSat) {
        Load4 = Multirotor_Model_1_P.CoreSubsys.Saturation2_LowerSat;
      } else {
        Load4 = Multirotor_Model_1_B.CoreSubsys[ForEach_itr].it;
      }
    }

    /* Fcn: '<S530>/Exponential Zone' */
    Multirotor_Model_1_B.CoreSubsys[ForEach_itr].ExponentialZone = exp(-3.5294 *
      Load4) * 0.468;

    /* Sum: '<S523>/Sum' incorporates:
     *  Constant: '<S523>/E0//Nernst [V]'
     */
    Multirotor_Model_1_B.CoreSubsys[ForEach_itr].Sum_p =
      ((Multirotor_Model_1_P.E0 + Multirotor_Model_1_B.CoreSubsys[ForEach_itr].
        Sum) + Multirotor_Model_1_B.CoreSubsys[ForEach_itr].Sum_h) +
      Multirotor_Model_1_B.CoreSubsys[ForEach_itr].ExponentialZone;
    if (rtmIsMajorTimeStep(Multirotor_Model_1_M)) {
      /* Delay: '<S523>/Delay' */
      rtb_I = Multirotor_Model_1_DW.CoreSubsys[ForEach_itr].Delay_DSTATE;

      /* Gain: '<S523>/Gain' */
      Multirotor_Model_1_B.CoreSubsys[ForEach_itr].CurrentA = 1.0 /
        Multirotor_Model_1_P.N_parallel * rtb_I;

      /* Gain: '<S523>/Internal Resistance [Ohms]' */
      Multirotor_Model_1_B.CoreSubsys[ForEach_itr].InternalResistanceOhms =
        Multirotor_Model_1_P.Bat_Rint
        * Multirotor_Model_1_B.CoreSubsys[ForEach_itr].CurrentA;
    }

    /* Sum: '<S523>/Sum1' */
    Load4 = Multirotor_Model_1_B.CoreSubsys[ForEach_itr].Sum_p -
      Multirotor_Model_1_B.CoreSubsys[ForEach_itr].InternalResistanceOhms;

    /* Saturate: '<S523>/Saturation3' */
    if (Load4 > Multirotor_Model_1_P.Vcell_max) {
      /* Saturate: '<S523>/Saturation3' */
      Multirotor_Model_1_B.CoreSubsys[ForEach_itr].Saturation3 =
        Multirotor_Model_1_P.Vcell_max;
    } else if (Load4 < Multirotor_Model_1_P.CoreSubsys.Saturation3_LowerSat) {
      /* Saturate: '<S523>/Saturation3' */
      Multirotor_Model_1_B.CoreSubsys[ForEach_itr].Saturation3 =
        Multirotor_Model_1_P.CoreSubsys.Saturation3_LowerSat;
    } else {
      /* Saturate: '<S523>/Saturation3' */
      Multirotor_Model_1_B.CoreSubsys[ForEach_itr].Saturation3 = Load4;
    }

    /* End of Saturate: '<S523>/Saturation3' */

    /* Gain: '<S523>/Gain2' */
    Multirotor_Model_1_B.CoreSubsys[ForEach_itr].V =
      Multirotor_Model_1_P.N_series *
      Multirotor_Model_1_B.CoreSubsys[ForEach_itr].Saturation3;

    /* Gain: '<S547>/[rps] to [rpm]' */
    Multirotor_Model_1_B.CoreSubsys[ForEach_itr].MotorN =
      Multirotor_Model_1_P.CoreSubsys.rpstorpm_Gain_j *
      Multirotor_Model_1_B.CoreSubsys[ForEach_itr].nHzrps;

    /* Sum: '<S547>/Sum1' */
    Multirotor_Model_1_B.CoreSubsys[ForEach_itr].Sum1 =
      rtb_ImpSel_InsertedFor_Input_at -
      Multirotor_Model_1_B.CoreSubsys[ForEach_itr].MotorN;

    /* Gain: '<S586>/Filter Coefficient' incorporates:
     *  Gain: '<S577>/Derivative Gain'
     *  Integrator: '<S578>/Filter'
     *  Sum: '<S578>/SumD'
     */
    Multirotor_Model_1_B.CoreSubsys[ForEach_itr].FilterCoefficient =
      (Multirotor_Model_1_P.Kd_TCntrl *
       Multirotor_Model_1_B.CoreSubsys[ForEach_itr].Sum1 -
       Multirotor_Model_1_X.CoreSubsys[ForEach_itr].Filter_CSTATE_pu) *
      Multirotor_Model_1_P.CoreSubsys.TorqueController_N;

    /* Sum: '<S592>/Sum' incorporates:
     *  Gain: '<S588>/Proportional Gain'
     *  Integrator: '<S583>/Integrator'
     */
    Load4 = (Multirotor_Model_1_P.Kp_TCntrl *
             Multirotor_Model_1_B.CoreSubsys[ForEach_itr].Sum1 +
             Multirotor_Model_1_X.CoreSubsys[ForEach_itr].Integrator_CSTATE_nm)
      + Multirotor_Model_1_B.CoreSubsys[ForEach_itr].FilterCoefficient;

    /* Saturate: '<S590>/Saturation' */
    if (Load4 > Multirotor_Model_1_P.TCntrl_maxlim) {
      /* Saturate: '<S590>/Saturation' */
      Multirotor_Model_1_B.CoreSubsys[ForEach_itr].Saturation =
        Multirotor_Model_1_P.TCntrl_maxlim;
    } else if (Load4 <
               Multirotor_Model_1_P.CoreSubsys.TorqueController_LowerSaturatio)
    {
      /* Saturate: '<S590>/Saturation' */
      Multirotor_Model_1_B.CoreSubsys[ForEach_itr].Saturation =
        Multirotor_Model_1_P.CoreSubsys.TorqueController_LowerSaturatio;
    } else {
      /* Saturate: '<S590>/Saturation' */
      Multirotor_Model_1_B.CoreSubsys[ForEach_itr].Saturation = Load4;
    }

    /* End of Saturate: '<S590>/Saturation' */

    /* Fcn: '<S547>/Mech Power' */
    Multirotor_Model_1_B.CoreSubsys[ForEach_itr].MechPower =
      Multirotor_Model_1_B.CoreSubsys[ForEach_itr].MotorN *
      Multirotor_Model_1_B.CoreSubsys[ForEach_itr].Saturation *
      6.2831853071795862 / 60.0;
    if (rtmIsMajorTimeStep(Multirotor_Model_1_M)) {
      /* Delay: '<S525>/Delay' */
      Multirotor_Model_1_B.CoreSubsys[ForEach_itr].Delay =
        Multirotor_Model_1_DW.CoreSubsys[ForEach_itr].Delay_DSTATE_b;
    }

    /* Gain: '<S544>/[rpm] to [rad//s]' */
    a = Multirotor_Model_1_P.CoreSubsys.rpmtorads_Gain *
      Multirotor_Model_1_B.CoreSubsys[ForEach_itr].MotorN;

    /* MATLAB Function: '<S544>/Motor Efficiency Function' incorporates:
     *  Constant: '<S544>/Constant'
     *  Constant: '<S544>/Constant2'
     *  Constant: '<S544>/Constant3'
     *  Constant: '<S544>/Constant4'
     *  Constant: '<S544>/Constant5'
     */
    Load5 = (((a * a * Multirotor_Model_1_P.T0a + Multirotor_Model_1_P.T0b * a)
              + Multirotor_Model_1_P.T0c) +
             Multirotor_Model_1_B.CoreSubsys[ForEach_itr].Delay) * a;
    Load6 = Load5 / (Multirotor_Model_1_P.kt * a * 3.0);
    Multirotor_Model_1_B.CoreSubsys[ForEach_itr].n =
      Multirotor_Model_1_B.CoreSubsys[ForEach_itr].Delay * a / (3.0 *
      Multirotor_Model_1_P.R * (Load6 * Load6) + Load5);

    /* Saturate: '<S544>/Saturation' */
    if (Multirotor_Model_1_B.CoreSubsys[ForEach_itr].n >
        Multirotor_Model_1_P.CoreSubsys.Saturation_UpperSat) {
      tmp_1 = Multirotor_Model_1_P.CoreSubsys.Saturation_UpperSat;
    } else if (Multirotor_Model_1_B.CoreSubsys[ForEach_itr].n <
               Multirotor_Model_1_P.CoreSubsys.Saturation_LowerSat_c) {
      tmp_1 = Multirotor_Model_1_P.CoreSubsys.Saturation_LowerSat_c;
    } else {
      tmp_1 = Multirotor_Model_1_B.CoreSubsys[ForEach_itr].n;
    }

    /* End of Saturate: '<S544>/Saturation' */

    /* Product: '<S546>/Divide1' */
    Multirotor_Model_1_B.CoreSubsys[ForEach_itr].MotorPower =
      Multirotor_Model_1_B.CoreSubsys[ForEach_itr].MechPower / tmp_1;

    /* Product: '<S546>/i = P//V' */
    Multirotor_Model_1_B.CoreSubsys[ForEach_itr].MotorI =
      Multirotor_Model_1_B.CoreSubsys[ForEach_itr].MotorPower /
      Multirotor_Model_1_B.CoreSubsys[ForEach_itr].V;

    /* Fcn: '<S546>/Motor Torque' */
    Multirotor_Model_1_B.CoreSubsys[ForEach_itr].MotorT = 60.0 *
      Multirotor_Model_1_B.CoreSubsys[ForEach_itr].MotorPower /
      (6.2831853071795862 * Multirotor_Model_1_B.CoreSubsys[ForEach_itr].MotorN);

    /* Fcn: '<S545>/Motor Heat [W]' incorporates:
     *  Constant: '<S544>/Constant5'
     */
    Multirotor_Model_1_B.CoreSubsys[ForEach_itr].MotorQ = rt_powd_snf
      (Multirotor_Model_1_B.CoreSubsys[ForEach_itr].MotorI, 2.0) *
      Multirotor_Model_1_P.R;
    if (rtmIsMajorTimeStep(Multirotor_Model_1_M)) {
    }

    /* Gain: '<S574>/ZeroGain' */
    a = Multirotor_Model_1_P.CoreSubsys.ZeroGain_Gain * Load4;

    /* DeadZone: '<S576>/DeadZone' */
    if (Load4 > Multirotor_Model_1_P.TCntrl_maxlim) {
      Load4 -= Multirotor_Model_1_P.TCntrl_maxlim;
    } else if (Load4 >=
               Multirotor_Model_1_P.CoreSubsys.TorqueController_LowerSaturatio)
    {
      Load4 = 0.0;
    } else {
      Load4 -= Multirotor_Model_1_P.CoreSubsys.TorqueController_LowerSaturatio;
    }

    /* End of DeadZone: '<S576>/DeadZone' */

    /* RelationalOperator: '<S574>/NotEqual' */
    rtb_NotEqual = (a != Load4);

    /* Signum: '<S574>/SignPreSat' */
    if (Load4 < 0.0) {
      Load4 = -1.0;
    } else if (Load4 > 0.0) {
      Load4 = 1.0;
    } else if (Load4 == 0.0) {
      Load4 = 0.0;
    } else {
      Load4 = (rtNaN);
    }

    /* End of Signum: '<S574>/SignPreSat' */

    /* Gain: '<S580>/Integral Gain' */
    a = Multirotor_Model_1_P.Ki_TCntrl *
      Multirotor_Model_1_B.CoreSubsys[ForEach_itr].Sum1;

    /* DataTypeConversion: '<S574>/DataTypeConv1' */
    if (rtIsNaN(Load4)) {
      tmp_1 = 0.0;
    } else {
      tmp_1 = fmod(Load4, 256.0);
    }

    /* Signum: '<S574>/SignPreIntegrator' */
    if (a < 0.0) {
      /* DataTypeConversion: '<S574>/DataTypeConv2' */
      b_a = -1.0;
    } else if (a > 0.0) {
      /* DataTypeConversion: '<S574>/DataTypeConv2' */
      b_a = 1.0;
    } else if (a == 0.0) {
      /* DataTypeConversion: '<S574>/DataTypeConv2' */
      b_a = 0.0;
    } else {
      /* DataTypeConversion: '<S574>/DataTypeConv2' */
      b_a = (rtNaN);
    }

    /* End of Signum: '<S574>/SignPreIntegrator' */

    /* DataTypeConversion: '<S574>/DataTypeConv2' */
    if (rtIsNaN(b_a)) {
      b_a = 0.0;
    } else {
      b_a = fmod(b_a, 256.0);
    }

    /* Logic: '<S574>/AND3' incorporates:
     *  DataTypeConversion: '<S574>/DataTypeConv1'
     *  DataTypeConversion: '<S574>/DataTypeConv2'
     *  RelationalOperator: '<S574>/Equal1'
     */
    Multirotor_Model_1_B.CoreSubsys[ForEach_itr].AND3 = (rtb_NotEqual && ((tmp_1
      < 0.0 ? (int32_T)(int8_T)-(int8_T)(uint8_T)-tmp_1 : (int32_T)(int8_T)
      (uint8_T)tmp_1) == (b_a < 0.0 ? (int32_T)(int8_T)-(int8_T)(uint8_T)-b_a :
                          (int32_T)(int8_T)(uint8_T)b_a)));
    if (rtmIsMajorTimeStep(Multirotor_Model_1_M)) {
      /* Memory: '<S574>/Memory' */
      Multirotor_Model_1_B.CoreSubsys[ForEach_itr].Memory =
        Multirotor_Model_1_DW.CoreSubsys[ForEach_itr].Memory_PreviousInput;
    }

    /* Switch: '<S574>/Switch' */
    if (Multirotor_Model_1_B.CoreSubsys[ForEach_itr].Memory) {
      /* Switch: '<S574>/Switch' incorporates:
       *  Constant: '<S574>/Constant1'
       */
      Multirotor_Model_1_B.CoreSubsys[ForEach_itr].Switch =
        Multirotor_Model_1_P.CoreSubsys.Constant1_Value;
    } else {
      /* Switch: '<S574>/Switch' */
      Multirotor_Model_1_B.CoreSubsys[ForEach_itr].Switch = a;
    }

    /* End of Switch: '<S574>/Switch' */

    /* Gain: '<S523>/Gain6' */
    Multirotor_Model_1_B.CoreSubsys[ForEach_itr].SOC =
      Multirotor_Model_1_P.CoreSubsys.Gain6_Gain * rtb_Saturation_e;

    /* MinMax: '<S539>/MinMax' incorporates:
     *  Constant: '<S539>/Time constant'
     *  Gain: '<S539>/Minimum sampling to time constant ratio'
     */
    a = fmax(Multirotor_Model_1_P.CoreSubsys.FilteredDerivativeDiscreteorC_b *
             Multirotor_Model_1_B.CoreSubsys[ForEach_itr].Probe[0],
             Multirotor_Model_1_P.CoreSubsys.FilteredDerivativeDiscreteorC_n);
    if (rtmIsMajorTimeStep(Multirotor_Model_1_M)) {
      /* Constant: '<S542>/Constant' */
      Multirotor_Model_1_B.CoreSubsys[ForEach_itr].Constant =
        Multirotor_Model_1_P.CoreSubsys.FilteredDerivativeDiscreteor_cf;
    }

    /* Integrator: '<S543>/Integrator' incorporates:
     *  Constant: '<S531>/Constant'
     */
    /* Limited  Integrator  */
    if (rtmIsMajorTimeStep(Multirotor_Model_1_M)) {
      zcEvent = rt_ZCFcn(ANY_ZERO_CROSSING,
                         &Multirotor_Model_1_PrevZCX.CoreSubsys[ForEach_itr].
                         Integrator_Reset_ZCE,
                         (Multirotor_Model_1_P.CoreSubsys.Constant_Value));

      /* evaluate zero-crossings and the level of the reset signal */
      if ((zcEvent != NO_ZCEVENT) ||
          (Multirotor_Model_1_P.CoreSubsys.Constant_Value != 0.0) ||
          (Multirotor_Model_1_DW.CoreSubsys[ForEach_itr].Integrator_IWORK != 0))
      {
        Multirotor_Model_1_X.CoreSubsys[ForEach_itr].Integrator_CSTATE_he =
          Multirotor_Model_1_B.CoreSubsys[ForEach_itr].Constant;
      }
    }

    if (Multirotor_Model_1_X.CoreSubsys[ForEach_itr].Integrator_CSTATE_he >=
        Multirotor_Model_1_P.CoreSubsys.Integrator_UpperSat) {
      Multirotor_Model_1_X.CoreSubsys[ForEach_itr].Integrator_CSTATE_he =
        Multirotor_Model_1_P.CoreSubsys.Integrator_UpperSat;
    } else {
      if (Multirotor_Model_1_X.CoreSubsys[ForEach_itr].Integrator_CSTATE_he <=
          Multirotor_Model_1_P.CoreSubsys.Integrator_LowerSat) {
        Multirotor_Model_1_X.CoreSubsys[ForEach_itr].Integrator_CSTATE_he =
          Multirotor_Model_1_P.CoreSubsys.Integrator_LowerSat;
      }
    }

    /* Saturate: '<S543>/Saturation' incorporates:
     *  Integrator: '<S543>/Integrator'
     */
    if (Multirotor_Model_1_X.CoreSubsys[ForEach_itr].Integrator_CSTATE_he >
        Multirotor_Model_1_P.CoreSubsys.Saturation_UpperSat_g) {
      /* Saturate: '<S543>/Saturation' */
      rtb_Saturation_f = Multirotor_Model_1_P.CoreSubsys.Saturation_UpperSat_g;
    } else if (Multirotor_Model_1_X.CoreSubsys[ForEach_itr].Integrator_CSTATE_he
               < Multirotor_Model_1_P.CoreSubsys.Saturation_LowerSat_d) {
      /* Saturate: '<S543>/Saturation' */
      rtb_Saturation_f = Multirotor_Model_1_P.CoreSubsys.Saturation_LowerSat_d;
    } else {
      /* Saturate: '<S543>/Saturation' */
      rtb_Saturation_f = Multirotor_Model_1_X.CoreSubsys[ForEach_itr].
        Integrator_CSTATE_he;
    }

    /* End of Saturate: '<S543>/Saturation' */

    /* Product: '<S531>/1//T' incorporates:
     *  Fcn: '<S539>/Avoid Divide by Zero'
     *  Sum: '<S531>/Sum1'
     */
    Multirotor_Model_1_B.CoreSubsys[ForEach_itr].uT = 1.0 / ((real_T)(a == 0.0) *
      2.2204460492503131e-16 + a) * (Multirotor_Model_1_B.CoreSubsys[ForEach_itr]
      .SOC - rtb_Saturation_f);

    /* Gain: '<S531>/Gain' */
    Load4 = Multirotor_Model_1_P.CoreSubsys.FilteredDerivativeDiscreteorC_c *
      Multirotor_Model_1_B.CoreSubsys[ForEach_itr].uT;

    /* Saturate: '<S531>/[A,B]' */
    if (Load4 > Multirotor_Model_1_P.CoreSubsys.FilteredDerivativeDiscreteorC_m)
    {
      /* Saturate: '<S531>/[A,B]' */
      Multirotor_Model_1_B.CoreSubsys[ForEach_itr].AB =
        Multirotor_Model_1_P.CoreSubsys.FilteredDerivativeDiscreteorC_m;
    } else if (Load4 <
               Multirotor_Model_1_P.CoreSubsys.FilteredDerivativeDiscreteorCon)
    {
      /* Saturate: '<S531>/[A,B]' */
      Multirotor_Model_1_B.CoreSubsys[ForEach_itr].AB =
        Multirotor_Model_1_P.CoreSubsys.FilteredDerivativeDiscreteorCon;
    } else {
      /* Saturate: '<S531>/[A,B]' */
      Multirotor_Model_1_B.CoreSubsys[ForEach_itr].AB = Load4;
    }

    /* End of Saturate: '<S531>/[A,B]' */

    /* Fcn: '<S529>/Polarisation Resistance dch' */
    Multirotor_Model_1_B.CoreSubsys[ForEach_itr].PolarisationResistancedch =
      Multirotor_Model_1_B.CoreSubsys[ForEach_itr].DataTypeConversion1 *
      0.0087662 * 3.0 / (3.0 - rtb_Saturation_c);

    /* Fcn: '<S529>/DCh' */
    Multirotor_Model_1_B.CoreSubsys[ForEach_itr].DCh =
      Multirotor_Model_1_B.CoreSubsys[ForEach_itr].DataTypeConversion1;

    /* Fcn: '<S529>/Q_heat_irrv_dch' incorporates:
     *  Fcn: '<S528>/Q_heat_irrv_Ch [W]'
     *  Fcn: '<S529>/Current'
     */
    rtb_Saturation_c = rt_powd_snf(Multirotor_Model_1_B.CoreSubsys[ForEach_itr].
      i, 2.0);

    /* Fcn: '<S529>/Q_heat_irrv_dch' */
    Multirotor_Model_1_B.CoreSubsys[ForEach_itr].Q_heat_irrv_dch =
      Multirotor_Model_1_B.CoreSubsys[ForEach_itr].DCh * rtb_Saturation_c * 0.09
      + rtb_Saturation_c * Multirotor_Model_1_B.CoreSubsys[ForEach_itr].
      PolarisationResistancedch;

    /* Fcn: '<S529>/SOC' */
    rtb_SOC = rtb_Saturation_e;

    /* If: '<S529>/If1' incorporates:
     *  Constant: '<S529>/Constant'
     *  Constant: '<S529>/Constant1'
     */
    rtAction = -1;
    if (rtmIsMajorTimeStep(Multirotor_Model_1_M)) {
      if (rtb_SOC <= 0.77) {
        rtAction = 0;
      } else if ((0.87 >= rtb_SOC) > 0.77) {
        rtAction = 1;
      } else {
        if ((1.0 >= rtb_SOC) > 0.87) {
          rtAction = 2;
        }
      }

      Multirotor_Model_1_DW.CoreSubsys[ForEach_itr].If1_ActiveSubsystem =
        rtAction;
    } else {
      rtAction = Multirotor_Model_1_DW.CoreSubsys[ForEach_itr].
        If1_ActiveSubsystem;
    }

    switch (rtAction) {
     case 0:
      /* Outputs for IfAction SubSystem: '<S529>/If Action Subsystem3' incorporates:
       *  ActionPort: '<S536>/Action Port'
       */
      Multirotor_M_IfActionSubsystem3(rtb_SOC,
        &Multirotor_Model_1_B.CoreSubsys[ForEach_itr].Merge1);

      /* End of Outputs for SubSystem: '<S529>/If Action Subsystem3' */
      break;

     case 1:
      /* Outputs for IfAction SubSystem: '<S529>/If Action Subsystem4' incorporates:
       *  ActionPort: '<S537>/Action Port'
       */
      Multirotor_M_IfActionSubsystem4(Multirotor_Model_1_M,
        Multirotor_Model_1_P.CoreSubsys.Constant_Value_b,
        &Multirotor_Model_1_B.CoreSubsys[ForEach_itr].Merge1);

      /* End of Outputs for SubSystem: '<S529>/If Action Subsystem4' */
      break;

     case 2:
      /* Outputs for IfAction SubSystem: '<S529>/If Action Subsystem5' incorporates:
       *  ActionPort: '<S538>/Action Port'
       */
      Multirotor_M_IfActionSubsystem5(Multirotor_Model_1_M,
        Multirotor_Model_1_P.CoreSubsys.Constant1_Value_d,
        &Multirotor_Model_1_B.CoreSubsys[ForEach_itr].Merge1);

      /* End of Outputs for SubSystem: '<S529>/If Action Subsystem5' */
      break;
    }

    /* End of If: '<S529>/If1' */

    /* Fcn: '<S529>/Q_heat_rrv_dch' incorporates:
     *  Fcn: '<S529>/I'
     *  Fcn: '<S529>/Tcore'
     */
    Multirotor_Model_1_B.CoreSubsys[ForEach_itr].Q_heat_rrv_dch =
      -(Multirotor_Model_1_B.CoreSubsys[ForEach_itr].DCh *
        Multirotor_Model_1_B.CoreSubsys[ForEach_itr].i *
        Multirotor_Model_1_B.CoreSubsys[ForEach_itr].Integrator *
        Multirotor_Model_1_B.CoreSubsys[ForEach_itr].Merge1) / 96485.0;

    /* Sum: '<S529>/Sum1' */
    Multirotor_Model_1_B.CoreSubsys[ForEach_itr].Sum1_k =
      Multirotor_Model_1_B.CoreSubsys[ForEach_itr].Q_heat_irrv_dch +
      Multirotor_Model_1_B.CoreSubsys[ForEach_itr].Q_heat_rrv_dch;

    /* Fcn: '<S528>/Polarisation Resistance CH' */
    Multirotor_Model_1_B.CoreSubsys[ForEach_itr].PolarisationResistanceCH =
      Multirotor_Model_1_B.CoreSubsys[ForEach_itr].DataTypeConversion2 *
      0.0087662 * 3.0 / (ssw2 + 0.30000000000000004);

    /* Fcn: '<S528>/Q_heat_irrv_Ch [W]' incorporates:
     *  Fcn: '<S528>/Ch'
     */
    Multirotor_Model_1_B.CoreSubsys[ForEach_itr].Q_heat_irrv_ChW =
      Multirotor_Model_1_B.CoreSubsys[ForEach_itr].DataTypeConversion2 *
      rtb_Saturation_c * 0.09 + rtb_Saturation_c *
      Multirotor_Model_1_B.CoreSubsys[ForEach_itr].PolarisationResistanceCH;

    /* Fcn: '<S528>/SOC' */
    rtb_SOC_a = rtb_Saturation_e;

    /* If: '<S528>/If1' incorporates:
     *  Constant: '<S528>/Constant'
     *  Constant: '<S528>/Constant1'
     */
    rtAction = -1;
    if (rtmIsMajorTimeStep(Multirotor_Model_1_M)) {
      if (rtb_SOC_a <= 0.77) {
        rtAction = 0;
      } else if ((0.87 >= rtb_SOC_a) > 0.77) {
        rtAction = 1;
      } else {
        if ((1.0 >= rtb_SOC_a) > 0.87) {
          rtAction = 2;
        }
      }

      Multirotor_Model_1_DW.CoreSubsys[ForEach_itr].If1_ActiveSubsystem_g =
        rtAction;
    } else {
      rtAction = Multirotor_Model_1_DW.CoreSubsys[ForEach_itr].
        If1_ActiveSubsystem_g;
    }

    switch (rtAction) {
     case 0:
      /* Outputs for IfAction SubSystem: '<S528>/If Action Subsystem3' incorporates:
       *  ActionPort: '<S533>/Action Port'
       */
      Multirotor_M_IfActionSubsystem3(rtb_SOC_a,
        &Multirotor_Model_1_B.CoreSubsys[ForEach_itr].Merge1_d);

      /* End of Outputs for SubSystem: '<S528>/If Action Subsystem3' */
      break;

     case 1:
      /* Outputs for IfAction SubSystem: '<S528>/If Action Subsystem4' incorporates:
       *  ActionPort: '<S534>/Action Port'
       */
      Multirotor_M_IfActionSubsystem4(Multirotor_Model_1_M,
        Multirotor_Model_1_P.CoreSubsys.Constant1_Value_a,
        &Multirotor_Model_1_B.CoreSubsys[ForEach_itr].Merge1_d);

      /* End of Outputs for SubSystem: '<S528>/If Action Subsystem4' */
      break;

     case 2:
      /* Outputs for IfAction SubSystem: '<S528>/If Action Subsystem5' incorporates:
       *  ActionPort: '<S535>/Action Port'
       */
      Multirotor_M_IfActionSubsystem5(Multirotor_Model_1_M,
        Multirotor_Model_1_P.CoreSubsys.Constant_Value_h,
        &Multirotor_Model_1_B.CoreSubsys[ForEach_itr].Merge1_d);

      /* End of Outputs for SubSystem: '<S528>/If Action Subsystem5' */
      break;
    }

    /* End of If: '<S528>/If1' */

    /* Fcn: '<S528>/Q_heat_rrv_Ch' incorporates:
     *  Fcn: '<S528>/Ch'
     *  Fcn: '<S528>/I'
     *  Fcn: '<S528>/Tcore'
     */
    Multirotor_Model_1_B.CoreSubsys[ForEach_itr].Q_heat_rrv_Ch =
      -(Multirotor_Model_1_B.CoreSubsys[ForEach_itr].DataTypeConversion2 *
        Multirotor_Model_1_B.CoreSubsys[ForEach_itr].i *
        Multirotor_Model_1_B.CoreSubsys[ForEach_itr].Integrator *
        Multirotor_Model_1_B.CoreSubsys[ForEach_itr].Merge1_d) / 96485.0;

    /* Sum: '<S528>/Sum1' */
    Multirotor_Model_1_B.CoreSubsys[ForEach_itr].Sum1_h =
      Multirotor_Model_1_B.CoreSubsys[ForEach_itr].Q_heat_irrv_ChW +
      Multirotor_Model_1_B.CoreSubsys[ForEach_itr].Q_heat_rrv_Ch;

    /* Sum: '<S523>/Sum2' */
    Multirotor_Model_1_B.CoreSubsys[ForEach_itr].QBat =
      Multirotor_Model_1_B.CoreSubsys[ForEach_itr].Sum1_k +
      Multirotor_Model_1_B.CoreSubsys[ForEach_itr].Sum1_h;
    if (rtmIsMajorTimeStep(Multirotor_Model_1_M)) {
    }

    /* Fcn: '<S532>/Cell Core Temp' */
    Multirotor_Model_1_B.CoreSubsys[ForEach_itr].CellCoreTemp = (0.43 *
      Multirotor_Model_1_B.CoreSubsys[ForEach_itr].Integrator +
      63.694758400000019) / 0.6437408;
    if (rtmIsMajorTimeStep(Multirotor_Model_1_M)) {
    }

    /* Product: '<S523>/Divide2' */
    Multirotor_Model_1_B.CoreSubsys[ForEach_itr].Pcell =
      Multirotor_Model_1_B.CoreSubsys[ForEach_itr].Saturation3 *
      Multirotor_Model_1_B.CoreSubsys[ForEach_itr].CurrentA;
    if (rtmIsMajorTimeStep(Multirotor_Model_1_M)) {
    }

    /* Product: '<S532>/Divide1' incorporates:
     *  Constant: '<S532>/Cp*m'
     *  Fcn: '<S532>/Conduction HLoss from core'
     *  Sum: '<S532>/Sum3'
     */
    Multirotor_Model_1_B.CoreSubsys[ForEach_itr].Divide1 =
      (Multirotor_Model_1_B.CoreSubsys[ForEach_itr].QBat -
       (Multirotor_Model_1_B.CoreSubsys[ForEach_itr].Integrator -
        Multirotor_Model_1_B.CoreSubsys[ForEach_itr].CellCoreTemp) *
       0.3134392857142857) / (Multirotor_Model_1_P.Cp *
      Multirotor_Model_1_P.m_cell);
    if (rtmIsMajorTimeStep(Multirotor_Model_1_M)) {
    }

    /* Gain: '<S520>/1//(2pi*I) I= Inertia of all  components connected  to the shaft' incorporates:
     *  Sum: '<S520>/Add'
     */
    Multirotor_Model_1_B.CoreSubsys[ForEach_itr].u2piIIInertiaofallcomponentscon
      = 1.0 / (6.2831853071795862 * Multirotor_Model_1_P.I_shaft_PM) *
      (Multirotor_Model_1_B.CoreSubsys[ForEach_itr].Saturation -
       Multirotor_Model_1_B.CoreSubsys[ForEach_itr].Torque);

    /* ForEachSliceAssignment generated from: '<S514>/Shaft RPMs' */
    Multirotor_Model_1_B.ImpAsg_InsertedFor_ShaftRPMs_at[ForEach_itr] = a_a;

    /* ForEachSliceAssignment generated from: '<S514>/Rotor loads' */
    for (i = 0; i < 6; i++) {
      rtb_ImpAsg_InsertedFor_Rotorloa[i + ForEach_itr * 6] =
        Multirotor_Model_1_B.CoreSubsys[ForEach_itr].load[i];
    }

    /* End of ForEachSliceAssignment generated from: '<S514>/Rotor loads' */
    ForEach_itr++;
  }

  /* End of Outputs for SubSystem: '<S510>/For Each Subsystem' */
  Multirotor_Model_emxFree_real_T(&dMy_0);
  Multirotor_Model_emxFree_real_T(&dMx_0);
  Multirotor_Model_emxFree_real_T(&dQ_0);
  Multirotor_Model_emxFree_real_T(&dFz_0);
  Multirotor_Model_emxFree_real_T(&dFtan_1);
  Multirotor_Model_emxFree_real_T(&dFtan_0);
  Multirotor_Model_emxFree_real_T(&b_psi);
  Multirotor_Model_emxFree_real_T(&error);
  Multirotor_Model_emxFree_real_T(&error2);
  Multirotor_Model_emxFree_real_T(&My);
  Multirotor_Model_emxFree_real_T(&Mx);
  Multirotor_Model_emxFree_real_T(&Q);
  Multirotor_Model_emxFree_real_T(&Fz);
  Multirotor_Model_emxFree_real_T(&Fy);
  Multirotor_Model_emxFree_real_T(&Fx);
  Multirotor_Model_emxFree_real_T(&dMx);
  Multirotor_Model_emxFree_real_T(&dMy);
  Multirotor_Model_emxFree_real_T(&dQ);
  Multirotor_Model_emxFree_real_T(&dFtan);
  Multirotor_Model_emxFree_real_T(&dFz);
  Multirotor_Model_emxFree_real_T(&dD);
  Multirotor_Model_emxFree_real_T(&dL);
  Multirotor_Model_emxFree_real_T(&cl);
  Multirotor_Model_emxFree_real_T(&cd);
  Multirotor_Model_emxFree_real_T(&cl2d);
  Multirotor_Model_emxFree_real_T(&alpha);
  Multirotor_Model_emxFree_real_T(&phi);
  Multirotor_Model_emxFree_real_T(&U);
  Multirotor_Model_emxFree_real_T(&Up);
  Multirotor_Model_emxFree_real_T(&Ut);
  Multirotor_Model_emxFree_real_T(&lambdai_old);
  Multirotor_Model_emxFree_real_T(&lambdai);
  Multirotor_Model_emxFree_real_T(&theta);
  Multirotor_Model_emxFree_real_T(&psi);

  /* MATLAB Function: '<S510>/MATLAB Function1' incorporates:
   *  Constant: '<S510>/Constant'
   */
  rtb_Saturation_c = 0.0;
  rtb_Saturation_e = 0.0;
  ssw2 = 0.0;
  Load4 = 0.0;
  Load5 = 0.0;
  Load6 = 0.0;
  for (i = 0; i < (int32_T)((Multirotor_Model_1_P.Quad.N_rotor - 1.0) + 1.0); i
       ++) {
    rtb_Saturation_c += rtb_ImpAsg_InsertedFor_Rotorloa[i * 6];
    rtb_Saturation_e += rtb_ImpAsg_InsertedFor_Rotorloa[i * 6 + 1];
    a_a = rtb_ImpAsg_InsertedFor_Rotorloa[i * 6 + 2];
    ssw2 -= a_a;
    t = Multirotor_Model_1_mod((real_T)i) - 0.5;
    if (t < 0.0) {
      t = -1.0;
    } else if (t > 0.0) {
      t = 1.0;
    } else if (t == 0.0) {
      t = 0.0;
    } else {
      t = (rtNaN);
    }

    a = (real_T)i * Multirotor_Model_1_P.Quad.arm_angle +
      Multirotor_Model_1_P.Quad.rotor1_angle;
    Load4 = (Load4 - sin(a) * Multirotor_Model_1_P.Quad.l * a_a) +
      rtb_ImpAsg_InsertedFor_Rotorloa[i * 6 + 3] * t;
    Load5 = (cos(a) * Multirotor_Model_1_P.Quad.l * a_a + Load5) -
      rtb_ImpAsg_InsertedFor_Rotorloa[i * 6 + 4];
    Load6 -= rtb_ImpAsg_InsertedFor_Rotorloa[i * 6 + 5] * t;
  }

  Multirotor_Model_1_B.Total_Rotor_Load[0] = rtb_Saturation_c;
  Multirotor_Model_1_B.Total_Rotor_Load[1] = rtb_Saturation_e;
  Multirotor_Model_1_B.Total_Rotor_Load[2] = ssw2;
  Multirotor_Model_1_B.Total_Rotor_Load[3] = Load4;
  Multirotor_Model_1_B.Total_Rotor_Load[4] = Load5;
  Multirotor_Model_1_B.Total_Rotor_Load[5] = Load6;

  /* End of MATLAB Function: '<S510>/MATLAB Function1' */
  if (rtmIsMajorTimeStep(Multirotor_Model_1_M)) {
    /* MATLAB Function: '<S509>/MATLAB Function' incorporates:
     *  Constant: '<S509>/Constant'
     */
    Multirotor_Model_1_B.Total_Fuselage_Load[0] = -Multirotor_Model_1_P.Quad.Kdx
      * Multirotor_Model_1_B.Delay[18];
    Multirotor_Model_1_B.Total_Fuselage_Load[1] = -Multirotor_Model_1_P.Quad.Kdy
      * Multirotor_Model_1_B.Delay[19];
    Multirotor_Model_1_B.Total_Fuselage_Load[2] = -Multirotor_Model_1_P.Quad.Kdz
      * Multirotor_Model_1_B.Delay[20];
    Multirotor_Model_1_B.Total_Fuselage_Load[3] = 0.0;
    Multirotor_Model_1_B.Total_Fuselage_Load[4] = 0.0;
    Multirotor_Model_1_B.Total_Fuselage_Load[5] = 0.0;

    /* MATLAB Function: '<S511>/MATLAB Function' incorporates:
     *  Constant: '<S511>/Constant'
     */
    rtb_Sum_m[1] = 0.0;
    rtb_Sum_m[4] = R_tmp_tmp;
    rtb_Sum_m[7] = R_tmp_tmp_0;
    rtb_Sum_m[2] = 0.0;
    rtb_Sum_m[5] = -sin(Multirotor_Model_1_B.Delay[6]);
    rtb_Sum_m[8] = R_tmp_tmp;
    c[0] = R_tmp_tmp_1;
    c[3] = 0.0;
    c[6] = -sin(Multirotor_Model_1_B.Delay[7]);
    rtb_Sum_m[0] = 1.0;
    c[1] = 0.0;
    rtb_Sum_m[3] = 0.0;
    c[4] = 1.0;
    rtb_Sum_m[6] = 0.0;
    c[7] = 0.0;
    c[2] = rtb_Sum_g_tmp;
    c[5] = 0.0;
    c[8] = R_tmp_tmp_1;
    R_tmp[0] = rtb_Sum_m_tmp;
    R_tmp[3] = rtb_Sum1_d_tmp;
    R_tmp[6] = 0.0;
    R_tmp[1] = -sin(Multirotor_Model_1_B.Delay[8]);
    R_tmp[4] = rtb_Sum_m_tmp;
    R_tmp[7] = 0.0;
    for (b_i = 0; b_i < 3; b_i++) {
      for (i = 0; i < 3; i++) {
        c_tmp = b_i + 3 * i;
        R[c_tmp] = 0.0;
        R[c_tmp] += c[3 * i] * rtb_Sum_m[b_i];
        R[c_tmp] += c[3 * i + 1] * rtb_Sum_m[b_i + 3];
        R[c_tmp] += c[3 * i + 2] * rtb_Sum_m[b_i + 6];
      }

      R_tmp[3 * b_i + 2] = b[b_i];
    }

    P_ddot[0] = 0.0;
    P_ddot[1] = 0.0;
    P_ddot[2] = Multirotor_Model_1_P.Quad.m * Multirotor_Model_1_P.Quad.g;
    for (b_i = 0; b_i < 3; b_i++) {
      Drag_Force[b_i] = 0.0;
      for (i = 0; i < 3; i++) {
        c_tmp = b_i + 3 * i;
        rtb_Sum_m[c_tmp] = 0.0;
        rtb_Sum_m[c_tmp] += R_tmp[3 * i] * R[b_i];
        rtb_Sum_m[c_tmp] += R_tmp[3 * i + 1] * R[b_i + 3];
        rtb_Sum_m[c_tmp] += R_tmp[3 * i + 2] * R[b_i + 6];
        Drag_Force[b_i] += rtb_Sum_m[c_tmp] * P_ddot[i];
      }
    }

    Multirotor_Model_1_B.Total_Weight_Load[0] = Drag_Force[0];
    Multirotor_Model_1_B.Total_Weight_Load[1] = Drag_Force[1];
    Multirotor_Model_1_B.Total_Weight_Load[2] = Drag_Force[2];
    Multirotor_Model_1_B.Total_Weight_Load[3] = 0.0;
    Multirotor_Model_1_B.Total_Weight_Load[4] = 0.0;
    Multirotor_Model_1_B.Total_Weight_Load[5] = 0.0;

    /* MATLAB Function: '<S512>/MATLAB Function' */
    for (i = 0; i < 6; i++) {
      Multirotor_Model_1_B.Total_Wing_Load[i] = 0.0;
    }

    /* End of MATLAB Function: '<S512>/MATLAB Function' */
  }

  /* Sum: '<S4>/Add' */
  for (i = 0; i < 6; i++) {
    rtb_Add[i] = ((Multirotor_Model_1_B.Total_Rotor_Load[i] +
                   Multirotor_Model_1_B.Total_Fuselage_Load[i]) +
                  Multirotor_Model_1_B.Total_Weight_Load[i]) +
      Multirotor_Model_1_B.Total_Wing_Load[i];
  }

  /* End of Sum: '<S4>/Add' */

  /* MATLAB Function: '<S2>/Translational Dynamics' incorporates:
   *  Constant: '<S2>/Constant'
   */
  rtb_Sum_m[1] = 0.0;
  rtb_Sum_m[4] = R_tmp_tmp;
  rtb_Sum_m[7] = R_tmp_tmp_0;
  rtb_Sum_m[2] = 0.0;
  rtb_Sum_m[5] = -sin(Multirotor_Model_1_B.Delay[6]);
  rtb_Sum_m[8] = R_tmp_tmp;
  c[0] = R_tmp_tmp_1;
  c[3] = 0.0;
  c[6] = -sin(Multirotor_Model_1_B.Delay[7]);
  rtb_Sum_m[0] = 1.0;
  c[1] = 0.0;
  rtb_Sum_m[3] = 0.0;
  c[4] = 1.0;
  rtb_Sum_m[6] = 0.0;
  c[7] = 0.0;
  c[2] = rtb_Sum_g_tmp;
  c[5] = 0.0;
  c[8] = R_tmp_tmp_1;
  R_tmp[0] = rtb_Sum_m_tmp;
  R_tmp[3] = rtb_Sum1_d_tmp;
  R_tmp[6] = 0.0;
  R_tmp[1] = -sin(Multirotor_Model_1_B.Delay[8]);
  R_tmp[4] = rtb_Sum_m_tmp;
  R_tmp[7] = 0.0;
  for (b_i = 0; b_i < 3; b_i++) {
    for (i = 0; i < 3; i++) {
      c_tmp = b_i + 3 * i;
      R[c_tmp] = 0.0;
      R[c_tmp] += c[3 * i] * rtb_Sum_m[b_i];
      R[c_tmp] += c[3 * i + 1] * rtb_Sum_m[b_i + 3];
      R[c_tmp] += c[3 * i + 2] * rtb_Sum_m[b_i + 6];
    }

    R_tmp[3 * b_i + 2] = b[b_i];
  }

  P_ddot[0] = Multirotor_Model_1_B.Delay[3];
  P_ddot[1] = Multirotor_Model_1_B.Delay[4];
  P_ddot[2] = Multirotor_Model_1_B.Delay[5];
  for (b_i = 0; b_i < 3; b_i++) {
    Drag_Force[b_i] = 0.0;
    for (i = 0; i < 3; i++) {
      c_tmp = b_i + 3 * i;
      rtb_Sum_m[c_tmp] = 0.0;
      rtb_Sum_m[c_tmp] += R_tmp[3 * i] * R[b_i];
      rtb_Sum_m[c_tmp] += R_tmp[3 * i + 1] * R[b_i + 3];
      rtb_Sum_m[c_tmp] += R_tmp[3 * i + 2] * R[b_i + 6];
      Drag_Force[b_i] += rtb_Sum_m[c_tmp] * P_ddot[i];
    }
  }

  a = 1.0 / Multirotor_Model_1_P.Quad.m;
  Multirotor_Model_1_B.a_body[0] = (Multirotor_Model_1_B.Delay[11] * Drag_Force
    [1] - Multirotor_Model_1_B.Delay[10] * Drag_Force[2]) + a * rtb_Add[0];
  Multirotor_Model_1_B.a_body[1] = (Multirotor_Model_1_B.Delay[9] * Drag_Force[2]
    - Multirotor_Model_1_B.Delay[11] * Drag_Force[0]) + a * rtb_Add[1];
  Multirotor_Model_1_B.a_body[2] = (Multirotor_Model_1_B.Delay[10] * Drag_Force
    [0] - Multirotor_Model_1_B.Delay[9] * Drag_Force[1]) + a * rtb_Add[2];

  /* MATLAB Function: '<S2>/Rotational Dynamics' incorporates:
   *  Constant: '<S2>/Constant'
   */
  rtb_Saturation_e = (Multirotor_Model_1_P.Quad.Jy -
                      Multirotor_Model_1_P.Quad.Jz) /
    Multirotor_Model_1_P.Quad.Jx;
  Multirotor_Model_1_B.om_dot[0] = rtb_Saturation_e *
    Multirotor_Model_1_B.Delay[10] * Multirotor_Model_1_B.Delay[11] + 1.0 /
    Multirotor_Model_1_P.Quad.Jx * rtb_Add[3];
  rtb_Saturation_e *= Multirotor_Model_1_B.Delay[9];
  Multirotor_Model_1_B.om_dot[1] = rtb_Saturation_e *
    Multirotor_Model_1_B.Delay[11] + 1.0 / Multirotor_Model_1_P.Quad.Jy *
    rtb_Add[4];
  Multirotor_Model_1_B.om_dot[2] = rtb_Saturation_e *
    Multirotor_Model_1_B.Delay[10] + 1.0 / Multirotor_Model_1_P.Quad.Jz *
    rtb_Add[5];
  if (rtmIsMajorTimeStep(Multirotor_Model_1_M)) {
    /* Delay: '<S2>/Delay' */
    Multirotor_Model_1_B.Delay_b = Multirotor_Model_1_DW.Delay_DSTATE_e;
  }

  /* Integrator: '<S2>/Integrator2' */
  if (rtmIsMajorTimeStep(Multirotor_Model_1_M)) {
    zcEvent = rt_ZCFcn(ANY_ZERO_CROSSING,
                       &Multirotor_Model_1_PrevZCX.Integrator2_Reset_ZCE,
                       (Multirotor_Model_1_B.Delay_b));

    /* evaluate zero-crossings and the level of the reset signal */
    if ((zcEvent != NO_ZCEVENT) || (Multirotor_Model_1_B.Delay_b != 0.0)) {
      Multirotor_Model_1_X.Integrator2_CSTATE =
        Multirotor_Model_1_P.Integrator2_IC;
    }
  }

  /* MATLAB Function: '<S2>/Transform1' */
  rtb_Sum_m[1] = 0.0;
  rtb_Sum_m[4] = R_tmp_tmp;
  rtb_Sum_m[7] = R_tmp_tmp_0;
  rtb_Sum_m[2] = 0.0;
  rtb_Sum_m[5] = -sin(Multirotor_Model_1_B.Delay[6]);
  rtb_Sum_m[8] = R_tmp_tmp;
  c[0] = R_tmp_tmp_1;
  c[3] = 0.0;
  c[6] = -sin(Multirotor_Model_1_B.Delay[7]);
  rtb_Sum_m[0] = 1.0;
  c[1] = 0.0;
  rtb_Sum_m[3] = 0.0;
  c[4] = 1.0;
  rtb_Sum_m[6] = 0.0;
  c[7] = 0.0;
  c[2] = rtb_Sum_g_tmp;
  c[5] = 0.0;
  c[8] = R_tmp_tmp_1;
  R_tmp[0] = rtb_Sum_m_tmp;
  R_tmp[3] = rtb_Sum1_d_tmp;
  R_tmp[6] = 0.0;
  R_tmp[1] = -sin(Multirotor_Model_1_B.Delay[8]);
  R_tmp[4] = rtb_Sum_m_tmp;
  R_tmp[7] = 0.0;
  for (b_i = 0; b_i < 3; b_i++) {
    for (i = 0; i < 3; i++) {
      c_tmp = b_i + 3 * i;
      R[c_tmp] = 0.0;
      R[c_tmp] += c[3 * i] * rtb_Sum_m[b_i];
      R[c_tmp] += c[3 * i + 1] * rtb_Sum_m[b_i + 3];
      R[c_tmp] += c[3 * i + 2] * rtb_Sum_m[b_i + 6];
    }

    R_tmp[3 * b_i + 2] = b[b_i];
  }

  /* SignalConversion generated from: '<S507>/ SFunction ' incorporates:
   *  Integrator: '<S2>/Integrator'
   *  Integrator: '<S2>/Integrator1'
   *  Integrator: '<S2>/Integrator2'
   *  MATLAB Function: '<S2>/Transform1'
   */
  P_ddot[0] = Multirotor_Model_1_X.Integrator_CSTATE_p;
  P_ddot[1] = Multirotor_Model_1_X.Integrator1_CSTATE;
  P_ddot[2] = Multirotor_Model_1_X.Integrator2_CSTATE;

  /* MATLAB Function: '<S2>/Transform1' incorporates:
   *  Integrator: '<S2>/Integrator3'
   *  Integrator: '<S2>/Integrator4'
   *  Integrator: '<S2>/Integrator5'
   *  MATLAB Function: '<S8>/MATLAB Function'
   */
  for (b_i = 0; b_i < 3; b_i++) {
    Multirotor_Model_1_B.P_dot_new[b_i] = 0.0;
    for (i = 0; i < 3; i++) {
      c_tmp = b_i + 3 * i;
      rtb_Sum_m[c_tmp] = 0.0;
      rtb_Sum_m[c_tmp] += R_tmp[3 * b_i] * R[i];
      rtb_Sum_m[c_tmp] += R_tmp[3 * b_i + 1] * R[i + 3];
      rtb_Sum_m[c_tmp] += R_tmp[3 * b_i + 2] * R[i + 6];
      Multirotor_Model_1_B.P_dot_new[b_i] += rtb_Sum_m[c_tmp] * P_ddot[i];
    }
  }

  a_a = tan(Multirotor_Model_1_B.Delay[7]);
  c[0] = 1.0;
  c[3] = R_tmp_tmp_0 * a_a;
  c[6] = R_tmp_tmp * a_a;
  c[1] = 0.0;
  c[4] = R_tmp_tmp;
  c[7] = -sin(Multirotor_Model_1_B.Delay[6]);
  c[2] = 0.0;
  c[5] = 1.0 / R_tmp_tmp_1 * R_tmp_tmp_0;
  c[8] = 1.0 / cos(Multirotor_Model_1_B.Delay[7]) * R_tmp_tmp;
  for (b_i = 0; b_i < 3; b_i++) {
    Multirotor_Model_1_B.Eang_dot_new[b_i] = 0.0;
    Multirotor_Model_1_B.Eang_dot_new[b_i] += c[b_i] *
      Multirotor_Model_1_X.Integrator3_CSTATE;
    Multirotor_Model_1_B.Eang_dot_new[b_i] += c[b_i + 3] *
      Multirotor_Model_1_X.Integrator4_CSTATE;
    Multirotor_Model_1_B.Eang_dot_new[b_i] += c[b_i + 6] *
      Multirotor_Model_1_X.Integrator5_CSTATE;
  }

  /* Integrator: '<S2>/Integrator8' */
  if (rtmIsMajorTimeStep(Multirotor_Model_1_M)) {
    zcEvent = rt_ZCFcn(ANY_ZERO_CROSSING,
                       &Multirotor_Model_1_PrevZCX.Integrator8_Reset_ZCE,
                       (Multirotor_Model_1_B.Delay_b));

    /* evaluate zero-crossings and the level of the reset signal */
    if ((zcEvent != NO_ZCEVENT) || (Multirotor_Model_1_B.Delay_b != 0.0)) {
      Multirotor_Model_1_X.Integrator8_CSTATE =
        Multirotor_Model_1_P.Integrator8_IC;
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
  Multirotor_Model_1_B.States_New[2] = Multirotor_Model_1_X.Integrator8_CSTATE;
  rtb_Sum_m[1] = 0.0;
  rtb_Sum_m[4] = R_tmp_tmp;
  rtb_Sum_m[7] = R_tmp_tmp_0;
  rtb_Sum_m[2] = 0.0;
  rtb_Sum_m[5] = -sin(Multirotor_Model_1_B.Delay[6]);
  rtb_Sum_m[8] = R_tmp_tmp;
  c[0] = R_tmp_tmp_1;
  c[3] = 0.0;
  c[6] = -sin(Multirotor_Model_1_B.Delay[7]);
  rtb_Sum_m[0] = 1.0;
  c[1] = 0.0;
  rtb_Sum_m[3] = 0.0;
  c[4] = 1.0;
  Multirotor_Model_1_B.States_New[5] = Multirotor_Model_1_B.P_dot_new[2];
  Multirotor_Model_1_B.States_New[20] = Multirotor_Model_1_X.Integrator2_CSTATE;
  rtb_Sum_m[6] = 0.0;
  c[7] = 0.0;
  c[2] = rtb_Sum_g_tmp;
  c[5] = 0.0;
  c[8] = R_tmp_tmp_1;
  R_tmp[0] = rtb_Sum_m_tmp;
  R_tmp[3] = rtb_Sum1_d_tmp;
  R_tmp[6] = 0.0;
  R_tmp[1] = -sin(Multirotor_Model_1_B.Delay[8]);
  R_tmp[4] = rtb_Sum_m_tmp;
  R_tmp[7] = 0.0;
  for (b_i = 0; b_i < 3; b_i++) {
    for (i = 0; i < 3; i++) {
      c_tmp = b_i + 3 * i;
      R[c_tmp] = 0.0;
      R[c_tmp] += c[3 * i] * rtb_Sum_m[b_i];
      R[c_tmp] += c[3 * i + 1] * rtb_Sum_m[b_i + 3];
      R[c_tmp] += c[3 * i + 2] * rtb_Sum_m[b_i + 6];
    }

    R_tmp[3 * b_i + 2] = b[b_i];
  }

  for (b_i = 0; b_i < 3; b_i++) {
    P_ddot[b_i] = 0.0;
    for (i = 0; i < 3; i++) {
      c_tmp = b_i + 3 * i;
      rtb_Sum_m[c_tmp] = 0.0;
      rtb_Sum_m[c_tmp] += R_tmp[3 * b_i] * R[i];
      rtb_Sum_m[c_tmp] += R_tmp[3 * b_i + 1] * R[i + 3];
      rtb_Sum_m[c_tmp] += R_tmp[3 * b_i + 2] * R[i + 6];
      P_ddot[b_i] += rtb_Sum_m[c_tmp] * Multirotor_Model_1_B.a_body[i];
    }
  }

  Multirotor_Model_1_B.reset_flag = 0.0;
  if (Multirotor_Model_1_X.Integrator8_CSTATE > 0.0) {
    Multirotor_Model_1_B.States_New[2] = 0.0;
    Multirotor_Model_1_B.States_New[5] = 0.0;
    P_ddot[2] = 0.0;
    Multirotor_Model_1_B.States_New[20] = 0.0;
    Multirotor_Model_1_B.reset_flag = 1.0;
  }

  Multirotor_Model_1_B.States_New[0] = Multirotor_Model_1_X.Integrator6_CSTATE;
  Multirotor_Model_1_B.States_New[1] = Multirotor_Model_1_X.Integrator7_CSTATE;
  Multirotor_Model_1_B.States_New[3] = Multirotor_Model_1_B.P_dot_new[0];
  Multirotor_Model_1_B.States_New[4] = Multirotor_Model_1_B.P_dot_new[1];
  Multirotor_Model_1_B.States_New[6] = Multirotor_Model_1_X.Integrator9_CSTATE;
  Multirotor_Model_1_B.States_New[7] = Multirotor_Model_1_X.Integrator10_CSTATE;
  Multirotor_Model_1_B.States_New[8] = Multirotor_Model_1_X.Integrator11_CSTATE;
  Multirotor_Model_1_B.States_New[9] = Multirotor_Model_1_X.Integrator3_CSTATE;
  Multirotor_Model_1_B.States_New[10] = Multirotor_Model_1_X.Integrator4_CSTATE;
  Multirotor_Model_1_B.States_New[11] = Multirotor_Model_1_X.Integrator5_CSTATE;
  Multirotor_Model_1_B.States_New[12] = P_ddot[0];
  Multirotor_Model_1_B.States_New[13] = P_ddot[1];
  Multirotor_Model_1_B.States_New[14] = P_ddot[2];
  Multirotor_Model_1_B.States_New[15] = Multirotor_Model_1_B.om_dot[0];
  Multirotor_Model_1_B.States_New[16] = Multirotor_Model_1_B.om_dot[1];
  Multirotor_Model_1_B.States_New[17] = Multirotor_Model_1_B.om_dot[2];
  Multirotor_Model_1_B.States_New[18] = Multirotor_Model_1_X.Integrator_CSTATE_p;
  Multirotor_Model_1_B.States_New[19] = Multirotor_Model_1_X.Integrator1_CSTATE;
  Multirotor_Model_1_B.States_New[21] = Multirotor_Model_1_B.Eang_dot_new[0];
  Multirotor_Model_1_B.States_New[22] = Multirotor_Model_1_B.Eang_dot_new[1];
  Multirotor_Model_1_B.States_New[23] = Multirotor_Model_1_B.Eang_dot_new[2];

  /* Gain: '<Root>/Gain1' */
  Multirotor_Model_1_B.Gain1_d = Multirotor_Model_1_P.Gain1_Gain_b *
    Multirotor_Model_1_B.States_New[2];
  if (rtmIsMajorTimeStep(Multirotor_Model_1_M)) {
  }

  /* Gain: '<Root>/Gain' */
  Multirotor_Model_1_B.Gain_d = Multirotor_Model_1_P.Gain_Gain *
    Multirotor_Model_1_B.States_New[5];
  if (rtmIsMajorTimeStep(Multirotor_Model_1_M)) {
  }

  /* Gain: '<Root>/Gain2' */
  Multirotor_Model_1_B.Gain2 = Multirotor_Model_1_P.Gain2_Gain *
    Multirotor_Model_1_B.States_New[20];
  if (rtmIsMajorTimeStep(Multirotor_Model_1_M)) {
  }

  /* Gain: '<S39>/Integral Gain' */
  Multirotor_Model_1_B.IntegralGain = Multirotor_Model_1_P.PIDController_I *
    rtb_Sum_d;
  if (rtmIsMajorTimeStep(Multirotor_Model_1_M)) {
  }

  /* Gain: '<S91>/Integral Gain' */
  Multirotor_Model_1_B.IntegralGain_d = Multirotor_Model_1_P.PIDController_I_l *
    rtb_Sum_bj;

  /* Gain: '<S139>/Integral Gain' */
  Multirotor_Model_1_B.IntegralGain_i = Multirotor_Model_1_P.PIDController1_I *
    rtb_Sum1_f;
  if (rtmIsMajorTimeStep(Multirotor_Model_1_M)) {
  }

  /* Gain: '<S190>/Integral Gain' */
  Multirotor_Model_1_B.IntegralGain_k = Multirotor_Model_1_P.PIDController_I_g *
    rtb_Sum_k;

  /* Gain: '<S238>/Integral Gain' */
  Multirotor_Model_1_B.IntegralGain_d3 = Multirotor_Model_1_P.PIDController1_I_a
    * rtb_Sum1_k;

  /* Gain: '<S286>/Integral Gain' */
  Multirotor_Model_1_B.IntegralGain_g = Multirotor_Model_1_P.PIDController2_I *
    rtb_Sum2_j;
  if (rtmIsMajorTimeStep(Multirotor_Model_1_M)) {
    /* Gain: '<S388>/Integral Gain' */
    Multirotor_Model_1_B.IntegralGain_m =
      Multirotor_Model_1_P.PIDController1_I_d * rtb_Sum1_n;
  }

  /* Gain: '<S340>/Integral Gain' */
  Multirotor_Model_1_B.IntegralGain_h = Multirotor_Model_1_P.PIDController_I_a *
    rtb_Clock;

  /* Gain: '<S436>/Integral Gain' */
  Multirotor_Model_1_B.IntegralGain_gm = Multirotor_Model_1_P.PIDController2_I_g
    * rtb_Sum2;
  if (rtmIsMajorTimeStep(Multirotor_Model_1_M)) {
  }

  /* Gain: '<S485>/Integral Gain' */
  Multirotor_Model_1_B.IntegralGain_i1 = Multirotor_Model_1_P.PIDController_I_lu
    * rtb_Sum_f;
  if (rtmIsMajorTimeStep(Multirotor_Model_1_M)) {
  }

  if (rtmIsMajorTimeStep(Multirotor_Model_1_M)) {
    /* Matfile logging */
    rt_UpdateTXYLogVars(Multirotor_Model_1_M->rtwLogInfo,
                        (Multirotor_Model_1_M->Timing.t));
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep(Multirotor_Model_1_M)) {
    if (rtmIsMajorTimeStep(Multirotor_Model_1_M)) {
      /* Update for Delay: '<Root>/Delay' */
      memcpy(&Multirotor_Model_1_DW.Delay_DSTATE[0],
             &Multirotor_Model_1_B.States_New[0], 24U * sizeof(real_T));

      /* Update for Delay: '<S1>/Delay' */
      Multirotor_Model_1_DW.Delay_DSTATE_m = Multirotor_Model_1_B.ssw;
    }

    /* Update for Iterator SubSystem: '<S510>/For Each Subsystem' */
    for (ForEach_itr = 0; ForEach_itr < 4; ForEach_itr++) {
      if (rtmIsMajorTimeStep(Multirotor_Model_1_M)) {
        /* Update for Delay: '<S523>/Delay' */
        Multirotor_Model_1_DW.CoreSubsys[ForEach_itr].Delay_DSTATE =
          Multirotor_Model_1_B.CoreSubsys[ForEach_itr].MotorI;

        /* Update for Delay: '<S525>/Delay' */
        Multirotor_Model_1_DW.CoreSubsys[ForEach_itr].Delay_DSTATE_b =
          Multirotor_Model_1_B.CoreSubsys[ForEach_itr].MotorT;

        /* Update for Memory: '<S574>/Memory' */
        Multirotor_Model_1_DW.CoreSubsys[ForEach_itr].Memory_PreviousInput =
          Multirotor_Model_1_B.CoreSubsys[ForEach_itr].AND3;
      }

      /* Update for Integrator: '<S543>/Integrator' */
      Multirotor_Model_1_DW.CoreSubsys[ForEach_itr].Integrator_IWORK = 0;
    }

    /* End of Update for SubSystem: '<S510>/For Each Subsystem' */
    if (rtmIsMajorTimeStep(Multirotor_Model_1_M)) {
      /* Update for Delay: '<S2>/Delay' */
      Multirotor_Model_1_DW.Delay_DSTATE_e = Multirotor_Model_1_B.reset_flag;
    }
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep(Multirotor_Model_1_M)) {
    /* signal main to stop simulation */
    {                                  /* Sample time: [0.0s, 0.0s] */
      if ((rtmGetTFinal(Multirotor_Model_1_M)!=-1) &&
          !((rtmGetTFinal(Multirotor_Model_1_M)-
             (((Multirotor_Model_1_M->Timing.clockTick1+
                Multirotor_Model_1_M->Timing.clockTickH1* 4294967296.0)) * 0.01))
            > (((Multirotor_Model_1_M->Timing.clockTick1+
                 Multirotor_Model_1_M->Timing.clockTickH1* 4294967296.0)) * 0.01)
            * (DBL_EPSILON))) {
        rtmSetErrorStatus(Multirotor_Model_1_M, "Simulation finished");
      }
    }

    rt_ertODEUpdateContinuousStates(&Multirotor_Model_1_M->solverInfo);

    /* Update absolute time for base rate */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick0 and the high bits
     * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++Multirotor_Model_1_M->Timing.clockTick0)) {
      ++Multirotor_Model_1_M->Timing.clockTickH0;
    }

    Multirotor_Model_1_M->Timing.t[0] = rtsiGetSolverStopTime
      (&Multirotor_Model_1_M->solverInfo);

    {
      /* Update absolute timer for sample time: [0.01s, 0.0s] */
      /* The "clockTick1" counts the number of times the code of this task has
       * been executed. The resolution of this integer timer is 0.01, which is the step size
       * of the task. Size of "clockTick1" ensures timer will not overflow during the
       * application lifespan selected.
       * Timer of this task consists of two 32 bit unsigned integers.
       * The two integers represent the low bits Timing.clockTick1 and the high bits
       * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
       */
      Multirotor_Model_1_M->Timing.clockTick1++;
      if (!Multirotor_Model_1_M->Timing.clockTick1) {
        Multirotor_Model_1_M->Timing.clockTickH1++;
      }
    }
  }                                    /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void Multirotor_Model_1_derivatives(void)
{
  /* local scratch DWork variables */
  int32_T ForEach_itr;
  XDot_Multirotor_Model_1_T *_rtXdot;
  boolean_T lsat;
  boolean_T usat;
  _rtXdot = ((XDot_Multirotor_Model_1_T *) Multirotor_Model_1_M->derivs);

  /* Derivatives for Integrator: '<S343>/Integrator' */
  _rtXdot->Integrator_CSTATE = Multirotor_Model_1_B.IntegralGain_h;

  /* Derivatives for Integrator: '<S338>/Filter' */
  _rtXdot->Filter_CSTATE = Multirotor_Model_1_B.FilterCoefficient;

  /* Derivatives for Integrator: '<S391>/Integrator' */
  _rtXdot->Integrator_CSTATE_b = Multirotor_Model_1_B.IntegralGain_m;

  /* Derivatives for Integrator: '<S386>/Filter' */
  _rtXdot->Filter_CSTATE_j = Multirotor_Model_1_B.FilterCoefficient_n;

  /* Derivatives for Integrator: '<S488>/Integrator' */
  _rtXdot->Integrator_CSTATE_b0 = Multirotor_Model_1_B.IntegralGain_i1;

  /* Derivatives for Integrator: '<S483>/Filter' */
  _rtXdot->Filter_CSTATE_p = Multirotor_Model_1_B.FilterCoefficient_j;

  /* Derivatives for Integrator: '<S439>/Integrator' */
  _rtXdot->Integrator_CSTATE_d = Multirotor_Model_1_B.IntegralGain_gm;

  /* Derivatives for Integrator: '<S434>/Filter' */
  _rtXdot->Filter_CSTATE_a = Multirotor_Model_1_B.FilterCoefficient_f;

  /* Derivatives for Integrator: '<S42>/Integrator' */
  _rtXdot->Integrator_CSTATE_f = Multirotor_Model_1_B.IntegralGain;

  /* Derivatives for Integrator: '<S37>/Filter' */
  _rtXdot->Filter_CSTATE_e = Multirotor_Model_1_B.FilterCoefficient_m;

  /* Derivatives for Integrator: '<S142>/Integrator' */
  _rtXdot->Integrator_CSTATE_e = Multirotor_Model_1_B.IntegralGain_i;

  /* Derivatives for Integrator: '<S137>/Filter' */
  _rtXdot->Filter_CSTATE_o = Multirotor_Model_1_B.FilterCoefficient_p;

  /* Derivatives for Integrator: '<S193>/Integrator' */
  _rtXdot->Integrator_CSTATE_n = Multirotor_Model_1_B.IntegralGain_k;

  /* Derivatives for Integrator: '<S188>/Filter' */
  _rtXdot->Filter_CSTATE_e2 = Multirotor_Model_1_B.FilterCoefficient_jz;

  /* Derivatives for Integrator: '<S94>/Integrator' */
  _rtXdot->Integrator_CSTATE_k = Multirotor_Model_1_B.IntegralGain_d;

  /* Derivatives for Integrator: '<S89>/Filter' */
  _rtXdot->Filter_CSTATE_j2 = Multirotor_Model_1_B.FilterCoefficient_a;

  /* Derivatives for Integrator: '<S241>/Integrator' */
  _rtXdot->Integrator_CSTATE_h = Multirotor_Model_1_B.IntegralGain_d3;

  /* Derivatives for Integrator: '<S236>/Filter' */
  _rtXdot->Filter_CSTATE_eb = Multirotor_Model_1_B.FilterCoefficient_a2;

  /* Derivatives for Integrator: '<S289>/Integrator' */
  _rtXdot->Integrator_CSTATE_h4 = Multirotor_Model_1_B.IntegralGain_g;

  /* Derivatives for Integrator: '<S284>/Filter' */
  _rtXdot->Filter_CSTATE_d = Multirotor_Model_1_B.FilterCoefficient_c;

  /* Derivatives for Iterator SubSystem: '<S510>/For Each Subsystem' */
  for (ForEach_itr = 0; ForEach_itr < 4; ForEach_itr++) {
    /* Derivatives for Integrator: '<S520>/Integrator' */
    _rtXdot->CoreSubsys[ForEach_itr].Integrator_CSTATE_pb =
      Multirotor_Model_1_B.CoreSubsys[ForEach_itr].
      u2piIIInertiaofallcomponentscon;

    /* Derivatives for TransferFcn: '<S523>/Transfer Fcn' */
    _rtXdot->CoreSubsys[ForEach_itr].TransferFcn_CSTATE = 0.0;
    _rtXdot->CoreSubsys[ForEach_itr].TransferFcn_CSTATE +=
      Multirotor_Model_1_P.CoreSubsys.TransferFcn_A *
      Multirotor_Model_1_X.CoreSubsys[ForEach_itr].TransferFcn_CSTATE;
    _rtXdot->CoreSubsys[ForEach_itr].TransferFcn_CSTATE +=
      Multirotor_Model_1_B.CoreSubsys[ForEach_itr].CurrentA;

    /* Derivatives for Integrator: '<S523>/Integrator1' */
    lsat = (Multirotor_Model_1_X.CoreSubsys[ForEach_itr].Integrator1_CSTATE_c <=
            Multirotor_Model_1_P.CoreSubsys.Integrator1_LowerSat);
    usat = (Multirotor_Model_1_X.CoreSubsys[ForEach_itr].Integrator1_CSTATE_c >=
            Multirotor_Model_1_P.Q_max * 3600.0);
    if (((!lsat) && (!usat)) || (lsat &&
         (Multirotor_Model_1_B.CoreSubsys[ForEach_itr].CurrentA > 0.0)) || (usat
         && (Multirotor_Model_1_B.CoreSubsys[ForEach_itr].CurrentA < 0.0))) {
      _rtXdot->CoreSubsys[ForEach_itr].Integrator1_CSTATE_c =
        Multirotor_Model_1_B.CoreSubsys[ForEach_itr].CurrentA;
    } else {
      /* in saturation */
      _rtXdot->CoreSubsys[ForEach_itr].Integrator1_CSTATE_c = 0.0;
    }

    /* End of Derivatives for Integrator: '<S523>/Integrator1' */

    /* Derivatives for Integrator: '<S532>/Integrator' */
    _rtXdot->CoreSubsys[ForEach_itr].Integrator_CSTATE_a =
      Multirotor_Model_1_B.CoreSubsys[ForEach_itr].Divide1;

    /* Derivatives for Integrator: '<S583>/Integrator' */
    _rtXdot->CoreSubsys[ForEach_itr].Integrator_CSTATE_nm =
      Multirotor_Model_1_B.CoreSubsys[ForEach_itr].Switch;

    /* Derivatives for Integrator: '<S578>/Filter' */
    _rtXdot->CoreSubsys[ForEach_itr].Filter_CSTATE_pu =
      Multirotor_Model_1_B.CoreSubsys[ForEach_itr].FilterCoefficient;

    /* Derivatives for Integrator: '<S543>/Integrator' incorporates:
     *  Constant: '<S531>/Constant'
     */
    lsat = (Multirotor_Model_1_X.CoreSubsys[ForEach_itr].Integrator_CSTATE_he <=
            Multirotor_Model_1_P.CoreSubsys.Integrator_LowerSat);
    usat = (Multirotor_Model_1_X.CoreSubsys[ForEach_itr].Integrator_CSTATE_he >=
            Multirotor_Model_1_P.CoreSubsys.Integrator_UpperSat);
    if ((Multirotor_Model_1_P.CoreSubsys.Constant_Value == 0.0) && (((!lsat) &&
          (!usat)) || (lsat && (Multirotor_Model_1_B.CoreSubsys[ForEach_itr].uT >
           0.0)) || (usat && (Multirotor_Model_1_B.CoreSubsys[ForEach_itr].uT <
           0.0)))) {
      _rtXdot->CoreSubsys[ForEach_itr].Integrator_CSTATE_he =
        Multirotor_Model_1_B.CoreSubsys[ForEach_itr].uT;
    } else {
      /* in saturation or level reset is active */
      _rtXdot->CoreSubsys[ForEach_itr].Integrator_CSTATE_he = 0.0;
    }

    /* End of Derivatives for Integrator: '<S543>/Integrator' */
  }

  /* End of Derivatives for SubSystem: '<S510>/For Each Subsystem' */

  /* Derivatives for Integrator: '<S2>/Integrator3' */
  _rtXdot->Integrator3_CSTATE = Multirotor_Model_1_B.om_dot[0];

  /* Derivatives for Integrator: '<S2>/Integrator4' */
  _rtXdot->Integrator4_CSTATE = Multirotor_Model_1_B.om_dot[1];

  /* Derivatives for Integrator: '<S2>/Integrator5' */
  _rtXdot->Integrator5_CSTATE = Multirotor_Model_1_B.om_dot[2];

  /* Derivatives for Integrator: '<S2>/Integrator' */
  _rtXdot->Integrator_CSTATE_p = Multirotor_Model_1_B.a_body[0];

  /* Derivatives for Integrator: '<S2>/Integrator1' */
  _rtXdot->Integrator1_CSTATE = Multirotor_Model_1_B.a_body[1];

  /* Derivatives for Integrator: '<S2>/Integrator6' */
  _rtXdot->Integrator6_CSTATE = Multirotor_Model_1_B.P_dot_new[0];

  /* Derivatives for Integrator: '<S2>/Integrator7' */
  _rtXdot->Integrator7_CSTATE = Multirotor_Model_1_B.P_dot_new[1];

  /* Derivatives for Integrator: '<S2>/Integrator2' incorporates:
   *  Integrator: '<S2>/Integrator8'
   */
  if (Multirotor_Model_1_B.Delay_b == 0.0) {
    _rtXdot->Integrator2_CSTATE = Multirotor_Model_1_B.a_body[2];
    _rtXdot->Integrator8_CSTATE = Multirotor_Model_1_B.P_dot_new[2];
  } else {
    /* level reset is active */
    _rtXdot->Integrator2_CSTATE = 0.0;

    /* level reset is active */
    _rtXdot->Integrator8_CSTATE = 0.0;
  }

  /* End of Derivatives for Integrator: '<S2>/Integrator2' */

  /* Derivatives for Integrator: '<S2>/Integrator9' */
  _rtXdot->Integrator9_CSTATE = Multirotor_Model_1_B.Eang_dot_new[0];

  /* Derivatives for Integrator: '<S2>/Integrator10' */
  _rtXdot->Integrator10_CSTATE = Multirotor_Model_1_B.Eang_dot_new[1];

  /* Derivatives for Integrator: '<S2>/Integrator11' */
  _rtXdot->Integrator11_CSTATE = Multirotor_Model_1_B.Eang_dot_new[2];
}

/* Model initialize function */
void Multirotor_Model_1_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* non-finite (run-time) assignments */
  Multirotor_Model_1_P.CoreSubsys.FilteredDerivativeDiscreteorCon = rtMinusInf;
  Multirotor_Model_1_P.CoreSubsys.FilteredDerivativeDiscreteorC_m = rtInf;
  Multirotor_Model_1_P.CoreSubsys.Integrator1_LowerSat = rtMinusInf;
  Multirotor_Model_1_P.CoreSubsys.Integrator_UpperSat = rtInf;
  Multirotor_Model_1_P.CoreSubsys.Integrator_LowerSat = rtMinusInf;
  Multirotor_Model_1_P.CoreSubsys.Saturation_UpperSat_g = rtInf;
  Multirotor_Model_1_P.CoreSubsys.Saturation_LowerSat_d = rtMinusInf;

  /* initialize real-time model */
  (void) memset((void *)Multirotor_Model_1_M, 0,
                sizeof(RT_MODEL_Multirotor_Model_1_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&Multirotor_Model_1_M->solverInfo,
                          &Multirotor_Model_1_M->Timing.simTimeStep);
    rtsiSetTPtr(&Multirotor_Model_1_M->solverInfo, &rtmGetTPtr
                (Multirotor_Model_1_M));
    rtsiSetStepSizePtr(&Multirotor_Model_1_M->solverInfo,
                       &Multirotor_Model_1_M->Timing.stepSize0);
    rtsiSetdXPtr(&Multirotor_Model_1_M->solverInfo,
                 &Multirotor_Model_1_M->derivs);
    rtsiSetContStatesPtr(&Multirotor_Model_1_M->solverInfo, (real_T **)
                         &Multirotor_Model_1_M->contStates);
    rtsiSetNumContStatesPtr(&Multirotor_Model_1_M->solverInfo,
      &Multirotor_Model_1_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&Multirotor_Model_1_M->solverInfo,
      &Multirotor_Model_1_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&Multirotor_Model_1_M->solverInfo,
      &Multirotor_Model_1_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&Multirotor_Model_1_M->solverInfo,
      &Multirotor_Model_1_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&Multirotor_Model_1_M->solverInfo, (&rtmGetErrorStatus
      (Multirotor_Model_1_M)));
    rtsiSetRTModelPtr(&Multirotor_Model_1_M->solverInfo, Multirotor_Model_1_M);
  }

  rtsiSetSimTimeStep(&Multirotor_Model_1_M->solverInfo, MAJOR_TIME_STEP);
  Multirotor_Model_1_M->intgData.y = Multirotor_Model_1_M->odeY;
  Multirotor_Model_1_M->intgData.f[0] = Multirotor_Model_1_M->odeF[0];
  Multirotor_Model_1_M->intgData.f[1] = Multirotor_Model_1_M->odeF[1];
  Multirotor_Model_1_M->intgData.f[2] = Multirotor_Model_1_M->odeF[2];
  Multirotor_Model_1_M->contStates = ((X_Multirotor_Model_1_T *)
    &Multirotor_Model_1_X);
  rtsiSetSolverData(&Multirotor_Model_1_M->solverInfo, (void *)
                    &Multirotor_Model_1_M->intgData);
  rtsiSetSolverName(&Multirotor_Model_1_M->solverInfo,"ode3");
  rtmSetTPtr(Multirotor_Model_1_M, &Multirotor_Model_1_M->Timing.tArray[0]);
  rtmSetTFinal(Multirotor_Model_1_M, 280.0);
  Multirotor_Model_1_M->Timing.stepSize0 = 0.01;
  rtmSetFirstInitCond(Multirotor_Model_1_M, 1);

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    rt_DataLoggingInfo.loggingInterval = NULL;
    Multirotor_Model_1_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(Multirotor_Model_1_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(Multirotor_Model_1_M->rtwLogInfo, (NULL));
    rtliSetLogT(Multirotor_Model_1_M->rtwLogInfo, "tout");
    rtliSetLogX(Multirotor_Model_1_M->rtwLogInfo, "");
    rtliSetLogXFinal(Multirotor_Model_1_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(Multirotor_Model_1_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(Multirotor_Model_1_M->rtwLogInfo, 4);
    rtliSetLogMaxRows(Multirotor_Model_1_M->rtwLogInfo, 0);
    rtliSetLogDecimation(Multirotor_Model_1_M->rtwLogInfo, 1);
    rtliSetLogY(Multirotor_Model_1_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(Multirotor_Model_1_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(Multirotor_Model_1_M->rtwLogInfo, (NULL));
  }

  /* block I/O */
  (void) memset(((void *) &Multirotor_Model_1_B), 0,
                sizeof(B_Multirotor_Model_1_T));

  /* states (continuous) */
  {
    (void) memset((void *)&Multirotor_Model_1_X, 0,
                  sizeof(X_Multirotor_Model_1_T));
  }

  /* states (dwork) */
  (void) memset((void *)&Multirotor_Model_1_DW, 0,
                sizeof(DW_Multirotor_Model_1_T));

  /* Matfile logging */
  rt_StartDataLoggingWithStartTime(Multirotor_Model_1_M->rtwLogInfo, 0.0,
    rtmGetTFinal(Multirotor_Model_1_M), Multirotor_Model_1_M->Timing.stepSize0,
    (&rtmGetErrorStatus(Multirotor_Model_1_M)));
  Multirotor_Model_1_PrevZCX.Integrator2_Reset_ZCE = UNINITIALIZED_ZCSIG;
  Multirotor_Model_1_PrevZCX.Integrator8_Reset_ZCE = UNINITIALIZED_ZCSIG;

  {
    /* local scratch DWork variables */
    int32_T ForEach_itr;
    int32_T i;

    /* InitializeConditions for Delay: '<Root>/Delay' */
    memcpy(&Multirotor_Model_1_DW.Delay_DSTATE[0],
           &Multirotor_Model_1_P.Delay_InitialCondition[0], 24U * sizeof(real_T));

    /* InitializeConditions for Integrator: '<S343>/Integrator' */
    Multirotor_Model_1_X.Integrator_CSTATE =
      Multirotor_Model_1_P.PIDController_InitialConditio_b;

    /* InitializeConditions for Integrator: '<S338>/Filter' */
    Multirotor_Model_1_X.Filter_CSTATE =
      Multirotor_Model_1_P.PIDController_InitialConditionF;

    /* InitializeConditions for Integrator: '<S391>/Integrator' */
    Multirotor_Model_1_X.Integrator_CSTATE_b =
      Multirotor_Model_1_P.PIDController1_InitialConditi_f;

    /* InitializeConditions for Integrator: '<S386>/Filter' */
    Multirotor_Model_1_X.Filter_CSTATE_j =
      Multirotor_Model_1_P.PIDController1_InitialCondition;

    /* InitializeConditions for Integrator: '<S488>/Integrator' */
    Multirotor_Model_1_X.Integrator_CSTATE_b0 =
      Multirotor_Model_1_P.PIDController_InitialConditio_o;

    /* InitializeConditions for Integrator: '<S483>/Filter' */
    Multirotor_Model_1_X.Filter_CSTATE_p =
      Multirotor_Model_1_P.PIDController_InitialConditio_e;

    /* InitializeConditions for Integrator: '<S439>/Integrator' */
    Multirotor_Model_1_X.Integrator_CSTATE_d =
      Multirotor_Model_1_P.PIDController2_InitialConditi_j;

    /* InitializeConditions for Integrator: '<S434>/Filter' */
    Multirotor_Model_1_X.Filter_CSTATE_a =
      Multirotor_Model_1_P.PIDController2_InitialCondition;

    /* InitializeConditions for Integrator: '<S42>/Integrator' */
    Multirotor_Model_1_X.Integrator_CSTATE_f =
      Multirotor_Model_1_P.PIDController_InitialConditio_g;

    /* InitializeConditions for Integrator: '<S37>/Filter' */
    Multirotor_Model_1_X.Filter_CSTATE_e =
      Multirotor_Model_1_P.PIDController_InitialConditio_l;

    /* InitializeConditions for Delay: '<S1>/Delay' */
    Multirotor_Model_1_DW.Delay_DSTATE_m =
      Multirotor_Model_1_P.Delay_InitialCondition_o;

    /* InitializeConditions for Integrator: '<S142>/Integrator' */
    Multirotor_Model_1_X.Integrator_CSTATE_e =
      Multirotor_Model_1_P.PIDController1_InitialConditi_k;

    /* InitializeConditions for Integrator: '<S137>/Filter' */
    Multirotor_Model_1_X.Filter_CSTATE_o =
      Multirotor_Model_1_P.PIDController1_InitialConditi_h;

    /* InitializeConditions for Integrator: '<S193>/Integrator' */
    Multirotor_Model_1_X.Integrator_CSTATE_n =
      Multirotor_Model_1_P.PIDController_InitialConditio_m;

    /* InitializeConditions for Integrator: '<S188>/Filter' */
    Multirotor_Model_1_X.Filter_CSTATE_e2 =
      Multirotor_Model_1_P.PIDController_InitialConditio_k;

    /* InitializeConditions for Integrator: '<S94>/Integrator' */
    Multirotor_Model_1_X.Integrator_CSTATE_k =
      Multirotor_Model_1_P.PIDController_InitialConditio_j;

    /* InitializeConditions for Integrator: '<S89>/Filter' */
    Multirotor_Model_1_X.Filter_CSTATE_j2 =
      Multirotor_Model_1_P.PIDController_InitialConditi_ek;

    /* InitializeConditions for Integrator: '<S241>/Integrator' */
    Multirotor_Model_1_X.Integrator_CSTATE_h =
      Multirotor_Model_1_P.PIDController1_InitialConditi_e;

    /* InitializeConditions for Integrator: '<S236>/Filter' */
    Multirotor_Model_1_X.Filter_CSTATE_eb =
      Multirotor_Model_1_P.PIDController1_InitialConditi_c;

    /* InitializeConditions for Integrator: '<S289>/Integrator' */
    Multirotor_Model_1_X.Integrator_CSTATE_h4 =
      Multirotor_Model_1_P.PIDController2_InitialConditi_i;

    /* InitializeConditions for Integrator: '<S284>/Filter' */
    Multirotor_Model_1_X.Filter_CSTATE_d =
      Multirotor_Model_1_P.PIDController2_InitialConditi_h;

    /* InitializeConditions for Integrator: '<S2>/Integrator3' */
    Multirotor_Model_1_X.Integrator3_CSTATE =
      Multirotor_Model_1_P.Integrator3_IC;

    /* InitializeConditions for Integrator: '<S2>/Integrator4' */
    Multirotor_Model_1_X.Integrator4_CSTATE =
      Multirotor_Model_1_P.Integrator4_IC;

    /* InitializeConditions for Integrator: '<S2>/Integrator5' */
    Multirotor_Model_1_X.Integrator5_CSTATE =
      Multirotor_Model_1_P.Integrator5_IC;

    /* InitializeConditions for Integrator: '<S2>/Integrator' */
    Multirotor_Model_1_X.Integrator_CSTATE_p =
      Multirotor_Model_1_P.Integrator_IC;

    /* InitializeConditions for Integrator: '<S2>/Integrator1' */
    Multirotor_Model_1_X.Integrator1_CSTATE =
      Multirotor_Model_1_P.Integrator1_IC;

    /* InitializeConditions for Delay: '<S2>/Delay' */
    Multirotor_Model_1_DW.Delay_DSTATE_e =
      Multirotor_Model_1_P.Delay_InitialCondition_h;

    /* InitializeConditions for Integrator: '<S2>/Integrator2' */
    Multirotor_Model_1_X.Integrator2_CSTATE =
      Multirotor_Model_1_P.Integrator2_IC;

    /* InitializeConditions for Integrator: '<S2>/Integrator6' */
    Multirotor_Model_1_X.Integrator6_CSTATE =
      Multirotor_Model_1_P.Integrator6_IC;

    /* InitializeConditions for Integrator: '<S2>/Integrator7' */
    Multirotor_Model_1_X.Integrator7_CSTATE =
      Multirotor_Model_1_P.Integrator7_IC;

    /* InitializeConditions for Integrator: '<S2>/Integrator8' */
    Multirotor_Model_1_X.Integrator8_CSTATE =
      Multirotor_Model_1_P.Integrator8_IC;

    /* InitializeConditions for Integrator: '<S2>/Integrator9' */
    Multirotor_Model_1_X.Integrator9_CSTATE =
      Multirotor_Model_1_P.Integrator9_IC;

    /* InitializeConditions for Integrator: '<S2>/Integrator10' */
    Multirotor_Model_1_X.Integrator10_CSTATE =
      Multirotor_Model_1_P.Integrator10_IC;

    /* InitializeConditions for Integrator: '<S2>/Integrator11' */
    Multirotor_Model_1_X.Integrator11_CSTATE =
      Multirotor_Model_1_P.Integrator11_IC;

    /* SystemInitialize for Iterator SubSystem: '<S510>/For Each Subsystem' */
    for (ForEach_itr = 0; ForEach_itr < 4; ForEach_itr++) {
      /* SystemInitialize for Integrator: '<S520>/Integrator' */
      Multirotor_Model_1_B.CoreSubsys[ForEach_itr].nHzrps = 0.0;

      /* SystemInitialize for Gain: '<S518>/Multiply' */
      Multirotor_Model_1_B.CoreSubsys[ForEach_itr].Torque = 0.0;

      /* SystemInitialize for TransferFcn: '<S523>/Transfer Fcn' */
      Multirotor_Model_1_B.CoreSubsys[ForEach_itr].i = 0.0;

      /* SystemInitialize for DataTypeConversion: '<S523>/Data Type Conversion1' */
      Multirotor_Model_1_B.CoreSubsys[ForEach_itr].DataTypeConversion1 = 0.0;

      /* SystemInitialize for Gain: '<S523>/Gain3' */
      Multirotor_Model_1_B.CoreSubsys[ForEach_itr].it = 0.0;

      /* SystemInitialize for Integrator: '<S532>/Integrator' */
      Multirotor_Model_1_B.CoreSubsys[ForEach_itr].Integrator = 0.0;

      /* SystemInitialize for Fcn: '<S529>/Polarisation Over Voltage' */
      Multirotor_Model_1_B.CoreSubsys[ForEach_itr].PolarisationOverVoltage = 0.0;

      /* SystemInitialize for Fcn: '<S529>/Polarisation Ohmic Voltage' */
      Multirotor_Model_1_B.CoreSubsys[ForEach_itr].PolarisationOhmicVoltage =
        0.0;

      /* SystemInitialize for Sum: '<S529>/Sum' */
      Multirotor_Model_1_B.CoreSubsys[ForEach_itr].Sum = 0.0;

      /* SystemInitialize for DataTypeConversion: '<S523>/Data Type Conversion2' */
      Multirotor_Model_1_B.CoreSubsys[ForEach_itr].DataTypeConversion2 = 0.0;

      /* SystemInitialize for Fcn: '<S528>/Polarisation Over Voltage' */
      Multirotor_Model_1_B.CoreSubsys[ForEach_itr].PolarisationOverVoltage_p =
        0.0;

      /* SystemInitialize for Fcn: '<S528>/Polarisation Ohmic Voltage' */
      Multirotor_Model_1_B.CoreSubsys[ForEach_itr].PolarisationOhmicVoltage_i =
        0.0;

      /* SystemInitialize for Sum: '<S528>/Sum' */
      Multirotor_Model_1_B.CoreSubsys[ForEach_itr].Sum_h = 0.0;

      /* SystemInitialize for Fcn: '<S530>/Exponential Zone' */
      Multirotor_Model_1_B.CoreSubsys[ForEach_itr].ExponentialZone = 0.0;

      /* SystemInitialize for Sum: '<S523>/Sum' */
      Multirotor_Model_1_B.CoreSubsys[ForEach_itr].Sum_p = 0.0;

      /* SystemInitialize for Gain: '<S523>/Gain' */
      Multirotor_Model_1_B.CoreSubsys[ForEach_itr].CurrentA = 0.0;

      /* SystemInitialize for Gain: '<S523>/Internal Resistance [Ohms]' */
      Multirotor_Model_1_B.CoreSubsys[ForEach_itr].InternalResistanceOhms = 0.0;

      /* SystemInitialize for Saturate: '<S523>/Saturation3' */
      Multirotor_Model_1_B.CoreSubsys[ForEach_itr].Saturation3 = 0.0;

      /* SystemInitialize for Gain: '<S523>/Gain2' */
      Multirotor_Model_1_B.CoreSubsys[ForEach_itr].V = 0.0;

      /* SystemInitialize for Gain: '<S547>/[rps] to [rpm]' */
      Multirotor_Model_1_B.CoreSubsys[ForEach_itr].MotorN = 0.0;

      /* SystemInitialize for Sum: '<S547>/Sum1' */
      Multirotor_Model_1_B.CoreSubsys[ForEach_itr].Sum1 = 0.0;

      /* SystemInitialize for Gain: '<S586>/Filter Coefficient' */
      Multirotor_Model_1_B.CoreSubsys[ForEach_itr].FilterCoefficient = 0.0;

      /* SystemInitialize for Saturate: '<S590>/Saturation' */
      Multirotor_Model_1_B.CoreSubsys[ForEach_itr].Saturation = 0.0;

      /* SystemInitialize for Fcn: '<S547>/Mech Power' */
      Multirotor_Model_1_B.CoreSubsys[ForEach_itr].MechPower = 0.0;

      /* SystemInitialize for Delay: '<S525>/Delay' */
      Multirotor_Model_1_B.CoreSubsys[ForEach_itr].Delay = 0.0;

      /* SystemInitialize for Product: '<S546>/Divide1' */
      Multirotor_Model_1_B.CoreSubsys[ForEach_itr].MotorPower = 0.0;

      /* SystemInitialize for Product: '<S546>/i = P//V' */
      Multirotor_Model_1_B.CoreSubsys[ForEach_itr].MotorI = 0.0;

      /* SystemInitialize for Fcn: '<S546>/Motor Torque' */
      Multirotor_Model_1_B.CoreSubsys[ForEach_itr].MotorT = 0.0;

      /* SystemInitialize for Fcn: '<S545>/Motor Heat [W]' */
      Multirotor_Model_1_B.CoreSubsys[ForEach_itr].MotorQ = 0.0;

      /* SystemInitialize for Logic: '<S574>/AND3' */
      Multirotor_Model_1_B.CoreSubsys[ForEach_itr].AND3 = false;

      /* SystemInitialize for Memory: '<S574>/Memory' */
      Multirotor_Model_1_B.CoreSubsys[ForEach_itr].Memory = false;

      /* SystemInitialize for Switch: '<S574>/Switch' */
      Multirotor_Model_1_B.CoreSubsys[ForEach_itr].Switch = 0.0;

      /* SystemInitialize for Gain: '<S523>/Gain6' */
      Multirotor_Model_1_B.CoreSubsys[ForEach_itr].SOC = 0.0;

      /* SystemInitialize for Product: '<S531>/1//T' */
      Multirotor_Model_1_B.CoreSubsys[ForEach_itr].uT = 0.0;

      /* SystemInitialize for Saturate: '<S531>/[A,B]' */
      Multirotor_Model_1_B.CoreSubsys[ForEach_itr].AB = 0.0;

      /* SystemInitialize for Fcn: '<S529>/Polarisation Resistance dch' */
      Multirotor_Model_1_B.CoreSubsys[ForEach_itr].PolarisationResistancedch =
        0.0;

      /* SystemInitialize for Fcn: '<S529>/DCh' */
      Multirotor_Model_1_B.CoreSubsys[ForEach_itr].DCh = 0.0;

      /* SystemInitialize for Fcn: '<S529>/Q_heat_irrv_dch' */
      Multirotor_Model_1_B.CoreSubsys[ForEach_itr].Q_heat_irrv_dch = 0.0;

      /* SystemInitialize for Merge: '<S529>/Merge1' */
      Multirotor_Model_1_B.CoreSubsys[ForEach_itr].Merge1 = 0.0;

      /* SystemInitialize for Fcn: '<S529>/Q_heat_rrv_dch' */
      Multirotor_Model_1_B.CoreSubsys[ForEach_itr].Q_heat_rrv_dch = 0.0;

      /* SystemInitialize for Sum: '<S529>/Sum1' */
      Multirotor_Model_1_B.CoreSubsys[ForEach_itr].Sum1_k = 0.0;

      /* SystemInitialize for Fcn: '<S528>/Polarisation Resistance CH' */
      Multirotor_Model_1_B.CoreSubsys[ForEach_itr].PolarisationResistanceCH =
        0.0;

      /* SystemInitialize for Fcn: '<S528>/Q_heat_irrv_Ch [W]' */
      Multirotor_Model_1_B.CoreSubsys[ForEach_itr].Q_heat_irrv_ChW = 0.0;

      /* SystemInitialize for Merge: '<S528>/Merge1' */
      Multirotor_Model_1_B.CoreSubsys[ForEach_itr].Merge1_d = 0.0;

      /* SystemInitialize for Fcn: '<S528>/Q_heat_rrv_Ch' */
      Multirotor_Model_1_B.CoreSubsys[ForEach_itr].Q_heat_rrv_Ch = 0.0;

      /* SystemInitialize for Sum: '<S528>/Sum1' */
      Multirotor_Model_1_B.CoreSubsys[ForEach_itr].Sum1_h = 0.0;

      /* SystemInitialize for Sum: '<S523>/Sum2' */
      Multirotor_Model_1_B.CoreSubsys[ForEach_itr].QBat = 0.0;

      /* SystemInitialize for Fcn: '<S532>/Cell Core Temp' */
      Multirotor_Model_1_B.CoreSubsys[ForEach_itr].CellCoreTemp = 0.0;

      /* SystemInitialize for Product: '<S523>/Divide2' */
      Multirotor_Model_1_B.CoreSubsys[ForEach_itr].Pcell = 0.0;

      /* SystemInitialize for Product: '<S532>/Divide1' */
      Multirotor_Model_1_B.CoreSubsys[ForEach_itr].Divide1 = 0.0;

      /* SystemInitialize for Gain: '<S520>/1//(2pi*I) I= Inertia of all  components connected  to the shaft' */
      Multirotor_Model_1_B.CoreSubsys[ForEach_itr].
        u2piIIInertiaofallcomponentscon = 0.0;

      /* Start for Probe: '<S539>/Probe' */
      Multirotor_Model_1_B.CoreSubsys[ForEach_itr].Probe[0] = 0.0;
      Multirotor_Model_1_B.CoreSubsys[ForEach_itr].Probe[1] = 0.0;

      /* Start for Constant: '<S542>/Constant' */
      Multirotor_Model_1_B.CoreSubsys[ForEach_itr].Constant =
        Multirotor_Model_1_P.CoreSubsys.FilteredDerivativeDiscreteor_cf;

      /* Start for If: '<S529>/If1' */
      Multirotor_Model_1_DW.CoreSubsys[ForEach_itr].If1_ActiveSubsystem = -1;

      /* Start for If: '<S528>/If1' */
      Multirotor_Model_1_DW.CoreSubsys[ForEach_itr].If1_ActiveSubsystem_g = -1;

      /* InitializeConditions for Integrator: '<S520>/Integrator' */
      Multirotor_Model_1_X.CoreSubsys[ForEach_itr].Integrator_CSTATE_pb =
        Multirotor_Model_1_P.Int_n_PM;

      /* InitializeConditions for TransferFcn: '<S523>/Transfer Fcn' */
      Multirotor_Model_1_X.CoreSubsys[ForEach_itr].TransferFcn_CSTATE = 0.0;

      /* InitializeConditions for Integrator: '<S523>/Integrator1' */
      Multirotor_Model_1_X.CoreSubsys[ForEach_itr].Integrator1_CSTATE_c = (1.0 -
        Multirotor_Model_1_P.SOC_init / 100.0) * Multirotor_Model_1_P.Q_max *
        3600.0;

      /* InitializeConditions for Integrator: '<S532>/Integrator' */
      Multirotor_Model_1_X.CoreSubsys[ForEach_itr].Integrator_CSTATE_a =
        Multirotor_Model_1_P.TcoreI;

      /* InitializeConditions for Delay: '<S523>/Delay' */
      Multirotor_Model_1_DW.CoreSubsys[ForEach_itr].Delay_DSTATE =
        Multirotor_Model_1_P.CoreSubsys.Delay_InitialCondition;

      /* InitializeConditions for Integrator: '<S583>/Integrator' */
      Multirotor_Model_1_X.CoreSubsys[ForEach_itr].Integrator_CSTATE_nm =
        Multirotor_Model_1_P.CoreSubsys.TorqueController_InitialCondi_i;

      /* InitializeConditions for Integrator: '<S578>/Filter' */
      Multirotor_Model_1_X.CoreSubsys[ForEach_itr].Filter_CSTATE_pu =
        Multirotor_Model_1_P.CoreSubsys.TorqueController_InitialConditi;

      /* InitializeConditions for Delay: '<S525>/Delay' */
      Multirotor_Model_1_DW.CoreSubsys[ForEach_itr].Delay_DSTATE_b =
        Multirotor_Model_1_P.CoreSubsys.Delay_InitialCondition_g;

      /* InitializeConditions for Memory: '<S574>/Memory' */
      Multirotor_Model_1_DW.CoreSubsys[ForEach_itr].Memory_PreviousInput =
        Multirotor_Model_1_P.CoreSubsys.Memory_InitialCondition;

      /* InitializeConditions for Integrator: '<S543>/Integrator' */
      if (rtmIsFirstInitCond(Multirotor_Model_1_M)) {
        Multirotor_Model_1_X.CoreSubsys[ForEach_itr].Integrator_CSTATE_he = 1.0;
      }

      Multirotor_Model_1_DW.CoreSubsys[ForEach_itr].Integrator_IWORK = 1;

      /* End of InitializeConditions for Integrator: '<S543>/Integrator' */

      /* SystemInitialize for MATLAB Function: '<S521>/MATLAB Function' */
      for (i = 0; i < 6; i++) {
        Multirotor_Model_1_B.CoreSubsys[ForEach_itr].load[i] = 0.0;
      }

      /* End of SystemInitialize for MATLAB Function: '<S521>/MATLAB Function' */

      /* SystemInitialize for MATLAB Function: '<S544>/Motor Efficiency Function' */
      Multirotor_Model_1_B.CoreSubsys[ForEach_itr].n = 0.0;

      /* SystemInitialize for IfAction SubSystem: '<S529>/If Action Subsystem3' */
      Multiro_IfActionSubsystem3_Init
        (&Multirotor_Model_1_B.CoreSubsys[ForEach_itr].Merge1);

      /* End of SystemInitialize for SubSystem: '<S529>/If Action Subsystem3' */

      /* SystemInitialize for IfAction SubSystem: '<S529>/If Action Subsystem4' */
      Multiro_IfActionSubsystem4_Init
        (&Multirotor_Model_1_B.CoreSubsys[ForEach_itr].Merge1);

      /* End of SystemInitialize for SubSystem: '<S529>/If Action Subsystem4' */

      /* SystemInitialize for IfAction SubSystem: '<S529>/If Action Subsystem5' */
      Multiro_IfActionSubsystem5_Init
        (&Multirotor_Model_1_B.CoreSubsys[ForEach_itr].Merge1);

      /* End of SystemInitialize for SubSystem: '<S529>/If Action Subsystem5' */

      /* SystemInitialize for Merge: '<S529>/Merge1' */
      Multirotor_Model_1_B.CoreSubsys[ForEach_itr].Merge1 =
        Multirotor_Model_1_P.CoreSubsys.Merge1_InitialOutput;

      /* SystemInitialize for IfAction SubSystem: '<S528>/If Action Subsystem3' */
      Multiro_IfActionSubsystem3_Init
        (&Multirotor_Model_1_B.CoreSubsys[ForEach_itr].Merge1_d);

      /* End of SystemInitialize for SubSystem: '<S528>/If Action Subsystem3' */

      /* SystemInitialize for IfAction SubSystem: '<S528>/If Action Subsystem4' */
      Multiro_IfActionSubsystem4_Init
        (&Multirotor_Model_1_B.CoreSubsys[ForEach_itr].Merge1_d);

      /* End of SystemInitialize for SubSystem: '<S528>/If Action Subsystem4' */

      /* SystemInitialize for IfAction SubSystem: '<S528>/If Action Subsystem5' */
      Multiro_IfActionSubsystem5_Init
        (&Multirotor_Model_1_B.CoreSubsys[ForEach_itr].Merge1_d);

      /* End of SystemInitialize for SubSystem: '<S528>/If Action Subsystem5' */

      /* SystemInitialize for Merge: '<S528>/Merge1' */
      Multirotor_Model_1_B.CoreSubsys[ForEach_itr].Merge1_d =
        Multirotor_Model_1_P.CoreSubsys.Merge1_InitialOutput_b;
      Multirotor_Model_1_PrevZCX.CoreSubsys[ForEach_itr].Integrator_Reset_ZCE =
        UNINITIALIZED_ZCSIG;
    }

    /* End of SystemInitialize for SubSystem: '<S510>/For Each Subsystem' */

    /* set "at time zero" to false */
    if (rtmIsFirstInitCond(Multirotor_Model_1_M)) {
      rtmSetFirstInitCond(Multirotor_Model_1_M, 0);
    }
  }
}

/* Model terminate function */
void Multirotor_Model_1_terminate(void)
{
  /* (no terminate code required) */
}
