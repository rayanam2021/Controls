/*
 * Multirotor_Model_1_types.h
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

#ifndef RTW_HEADER_Multirotor_Model_1_types_h_
#define RTW_HEADER_Multirotor_Model_1_types_h_
#include "rtwtypes.h"
#include "builtin_typeid_types.h"
#include "multiword_types.h"

/* Model Code Variants */
#ifndef DEFINED_TYPEDEF_FOR_Quad_bus_
#define DEFINED_TYPEDEF_FOR_Quad_bus_

typedef struct {
  real_T g;
  real_T m;
  real_T l;
  real_T t;
  real_T rot_rad;
  real_T Kd;
  real_T Kdx;
  real_T Kdy;
  real_T Kdz;
  real_T Jx;
  real_T Jy;
  real_T Jz;
  real_T KT;
  real_T Z_KP;
  real_T Z_KD;
  real_T N_rotor;
  real_T rotor1_angle;
  real_T arm_angle;
} Quad_bus;

#endif

#ifndef DEFINED_TYPEDEF_FOR_ip_bus_
#define DEFINED_TYPEDEF_FOR_ip_bus_

typedef struct {
  real_T N_bet;
  real_T flight_cond;
  real_T vc;
  real_T vinf;
  real_T rho;
  real_T mu_visc;
  real_T vc_int;
  real_T Nb;
  real_T rad;
  real_T rad_in;
  real_T chord_inter[26];
  real_T beta_inter[26];
  real_T theta;
  real_T thetac;
  real_T thetas;
  real_T tilt;
  real_T data[504];
  real_T data_high[102];
  real_T data_interference[20];
  real_T use_soln;
  real_T tiploss;
  real_T fp;
  real_T cutoff_bemt;
  real_T cutoff_coax;
  real_T cutoff_trim;
  real_T itermax_bemt;
  real_T itermax_coax;
  real_T itermax_trim;
  real_T rw;
  real_T rot_sep;
  real_T gamma_UL;
  real_T gamma_LU;
  real_T delpsi;
  real_T kp;
  real_T kt;
  real_T fac;
  real_T chd[30];
  real_T sigma[30];
  real_T thetacol[30];
  real_T rc;
  real_T AR;
  real_T root_cut;
  real_T r[30];
  real_T dr;
} ip_bus;

#endif

#ifndef struct_emxArray_real_T
#define struct_emxArray_real_T

struct emxArray_real_T
{
  real_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};

#endif                                 /*struct_emxArray_real_T*/

#ifndef typedef_emxArray_real_T_Multirotor_Mo_T
#define typedef_emxArray_real_T_Multirotor_Mo_T

typedef struct emxArray_real_T emxArray_real_T_Multirotor_Mo_T;

#endif                               /*typedef_emxArray_real_T_Multirotor_Mo_T*/

/* Parameters for system: '<S510>/For Each Subsystem' */
typedef struct P_CoreSubsys_Multirotor_Model_T_ P_CoreSubsys_Multirotor_Model_T;

/* Parameters (default storage) */
typedef struct P_Multirotor_Model_1_T_ P_Multirotor_Model_1_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_Multirotor_Model_1_T RT_MODEL_Multirotor_Model_1_T;

#endif                              /* RTW_HEADER_Multirotor_Model_1_types_h_ */
