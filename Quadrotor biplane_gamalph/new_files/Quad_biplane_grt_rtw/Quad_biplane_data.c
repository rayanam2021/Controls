/*
 * Quad_biplane_data.c
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

/* Block parameters (default storage) */
P_Quad_biplane_T Quad_biplane_P = {
  /* Variable: ip
   * Referenced by:
   *   '<S619>/Constant'
   *   '<S620>/Constant'
   *   '<S621>/Constant'
   *   '<S622>/Constant'
   */
  {
    30.0,
    0.0,
    0.0,
    0.0,
    1.2256,
    1.825e-5,
    0.0,
    2.0,
    0.328084,
    0.049212599999999995,

    { 0.109, 0.12433333333333332, 0.13999999999999999, 0.156,
      0.16933333333333334, 0.18166666666666664, 0.193, 0.20166666666666666,
      0.20933333333333332, 0.216, 0.22066666666666668, 0.22400000000000003,
      0.226, 0.22533333333333333, 0.22300000000000003, 0.219,
      0.21300000000000002, 0.20566666666666666, 0.197, 0.18500000000000005,
      0.17166666666666669, 0.15700000000000003, 0.13900000000000007,
      0.11566666666666672, 0.087000000000000147, 0.057000000000000106 },

    { 21.11, 22.97, 24.15, 24.65, 24.29, 23.666666666666668, 22.78, 21.6,
      20.340000000000003, 19.0, 17.706666666666667, 16.483333333333334, 15.33,
      14.323333333333338, 13.383333333333336, 12.510000000000002,
      11.743333333333336, 10.996666666666668, 10.270000000000001,
      9.6366666666666685, 9.0, 8.3600000000000012, 7.6333333333333346,
      6.8966666666666674, 6.1500000000000039, 5.4100000000000019 },
    0.0,
    0.0,
    0.0,
    0.0,

    { -7.75, -7.5, -7.25, -7.0, -6.75, -6.5, -6.25, -6.0, -5.75, -5.5, -5.25,
      -4.25, -4.0, -3.75, -3.5, -3.25, -3.0, -2.75, -1.25, -1.0, -0.75, -0.5,
      -0.25, 0.0, 0.25, 0.5, 0.75, 1.0, 1.25, 1.5, 1.75, 2.0, 2.25, 2.5, 2.75,
      3.0, 3.25, 3.5, 3.75, 4.0, 4.25, 4.5, 4.75, 5.0, 5.25, 5.5, 5.75, 6.0,
      6.25, 6.5, 6.75, 7.0, 7.25, 7.5, 7.75, 8.0, 8.25, 8.5, 8.75, 9.0, 9.25,
      9.5, 9.75, 10.0, 10.25, 10.5, 10.75, 11.0, 11.25, 11.5, 11.75, 12.0,
      -0.1832, -0.17, -0.1679, -0.1577, -0.1463, -0.1336, -0.118, -0.1135,
      -0.0936, -0.0702, -0.0432, 0.027, 0.0722, 0.1274, 0.1803, 0.2346, 0.2878,
      0.3388, 0.5998, 0.6389, 0.6751, 0.7002, 0.7363, 0.7753, 0.8063, 0.8399,
      0.8813, 0.93, 0.9689, 0.9981, 1.0209, 1.0411, 1.0585, 1.0748, 1.0957,
      1.1158, 1.137, 1.1589, 1.1808, 1.2018, 1.224, 1.2488, 1.2733, 1.2974,
      1.3211, 1.3443, 1.3668, 1.3885, 1.4086, 1.4254, 1.4427, 1.4656, 1.4871,
      1.5081, 1.5294, 1.5503, 1.5688, 1.5791, 1.5988, 1.6137, 1.6305, 1.64,
      1.659, 1.6775, 1.6517, 1.6647, 1.6478, 1.6296, 1.6013, 1.5757, 1.5452,
      1.5238, 0.08151, 0.07771, 0.07487, 0.07133, 0.06763, 0.06385, 0.05986,
      0.05694, 0.05261, 0.04811, 0.04335, 0.047, 0.04268, 0.03805, 0.03399,
      0.02943, 0.02508, 0.02122, 0.00822, 0.00737, 0.00696, 0.00673, 0.00608,
      0.00528, 0.00477, 0.00428, 0.00414, 0.00406, 0.00412, 0.00435, 0.0047,
      0.00513, 0.00575, 0.00663, 0.00732, 0.00818, 0.00898, 0.00971, 0.01048,
      0.0114, 0.0122, 0.01259, 0.01303, 0.01353, 0.01407, 0.0147, 0.01543,
      0.01627, 0.01739, 0.0193, 0.02183, 0.02248, 0.02379, 0.02529, 0.02586,
      0.02617, 0.02708, 0.0315, 0.03204, 0.03405, 0.03491, 0.03751, 0.03709,
      0.03667, 0.04347, 0.0437, 0.04787, 0.05224, 0.05808, 0.06389, 0.07078,
      0.07684, 0.07995, 0.07615, 0.07333, 0.06979, 0.06609, 0.06232, 0.05832,
      0.05542, 0.05108, 0.04658, 0.04181, 0.04525, 0.04087, 0.03615, 0.03198,
      0.02726, 0.02269, 0.01856, 0.00387, 0.00288, 0.00245, 0.00217, 0.00195,
      0.002, 0.00202, 0.00172, 0.00154, 0.00139, 0.00132, 0.00135, 0.00146,
      0.00162, 0.00188, 0.00221, 0.0025, 0.00286, 0.00323, 0.0036, 0.00405,
      0.00458, 0.00515, 0.00561, 0.00611, 0.00671, 0.00733, 0.00805, 0.00888,
      0.00982, 0.01105, 0.01317, 0.01592, 0.01665, 0.0181, 0.01975, 0.02041,
      0.02075, 0.02168, 0.02656, 0.02726, 0.02952, 0.03049, 0.03337, 0.03292,
      0.03246, 0.03988, 0.04018, 0.04471, 0.0494, 0.05558, 0.06168, 0.06883,
      0.07508, -0.0484, -0.0516, -0.0516, -0.0538, -0.0567, -0.0599, -0.0639,
      -0.0646, -0.0699, -0.076, -0.0832, -0.111, -0.1202, -0.1307, -0.1394,
      -0.1481, -0.1558, -0.1624, -0.1852, -0.1876, -0.1893, -0.1885, -0.1905,
      -0.1935, -0.1942, -0.1952, -0.1982, -0.2029, -0.2053, -0.2055, -0.2042,
      -0.2024, -0.2, -0.1976, -0.1962, -0.1949, -0.1937, -0.1928, -0.1917,
      -0.1906, -0.1894, -0.1888, -0.188, -0.1872, -0.1863, -0.1853, -0.1841,
      -0.1828, -0.1812, -0.1788, -0.1766, -0.1757, -0.1744, -0.173, -0.172,
      -0.1711, -0.1699, -0.1667, -0.1654, -0.1631, -0.1615, -0.1586, -0.1576,
      -0.1565, -0.1485, -0.1461, -0.1398, -0.1342, -0.1286, -0.1248, -0.1227,
      -0.1225, 0.9855, 0.9849, 0.9799, 0.9778, 0.9761, 0.9748, 0.9736, 0.9667,
      0.9647, 0.9634, 0.9625, 0.9572, 0.9555, 0.9547, 0.9541, 0.9538, 0.9536,
      0.9535, 0.952, 0.9512, 0.9501, 0.9437, 0.9406, 0.9383, 0.9319, 0.9248,
      0.9133, 0.8979, 0.8693, 0.8291, 0.7809, 0.7259, 0.6472, 0.5349, 0.4522,
      0.3516, 0.2643, 0.1922, 0.1241, 0.0536, 0.0131, 0.0114, 0.0106, 0.0102,
      0.0096, 0.0094, 0.0091, 0.0088, 0.0083, 0.0077, 0.0069, 0.0066, 0.0063,
      0.0059, 0.0051, 0.0045, 0.004, 0.0034, 0.0031, 0.0028, 0.0024, 0.0023,
      0.002, 0.0019, 0.0016, 0.0014, 0.0014, 0.0014, 0.0013, 0.0013, 0.0013,
      0.0014, 0.0048, 0.0049, 0.005, 0.005, 0.005, 0.005, 0.0051, 0.0051, 0.0051,
      0.0051, 0.0051, 0.0062, 0.007, 0.0085, 0.009, 0.0091, 0.0091, 0.0091,
      0.0085, 0.0105, 0.0137, 0.0152, 0.2074, 0.5852, 0.8242, 1.0, 1.0, 1.0, 1.0,
      1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
      1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
      1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0 },

    { 25.0, 26.0, 27.0, 30.0, 35.0, 40.0, 45.0, 50.0, 55.0, 60.0, 65.0, 70.0,
      75.0, 80.0, 85.0, 90.0, 95.0, 100.0, 105.0, 110.0, 115.0, 120.0, 125.0,
      130.0, 135.0, 140.0, 145.0, 150.0, 155.0, 160.0, 165.0, 170.0, 175.0,
      180.0, 0.8276, 0.881, 0.9345, 0.915, 1.02, 1.075, 1.085, 1.04, 0.965,
      0.875, 0.765, 0.65, 0.515, 0.37, 0.22, 0.07, -0.07, -0.22, -0.37, -0.51,
      -0.625, -0.735, -0.84, -0.91, -0.945, -0.945, -0.91, -0.85, -0.74, -0.66,
      -0.675, -0.85, -0.69, 0.0, 0.42, 0.446, 0.473, 0.57, 0.745, 0.92, 1.075,
      1.215, 1.345, 1.47, 1.575, 1.665, 1.735, 1.78, 1.8, 1.8, 1.78, 1.75, 1.7,
      1.635, 1.555, 1.465, 1.35, 1.225, 1.085, 0.925, 0.755, 0.575, 0.42, 0.32,
      0.23, 0.14, 0.055, 0.025 },

    { 0.0, 0.0746, 0.1491, 0.1789, 0.2237, 0.86, 0.8, 0.74, 0.71, 0.7, 0.53,
      0.58, 0.6, 0.65, 0.7, 0.7, 0.8, 0.9, 0.94, 1.0 },
    0.0,
    1.0,
    3.0,
    0.05,
    1.0e-5,
    0.0001,
    30.0,
    10.0,
    10.0,
    1.0,
    0.25,
    0.6,
    0.4,
    10.0,
    1.0,
    1.0,
    0.05,

    { 0.0, 0.0, 0.0, 0.0, 0.109, 0.12433333333333332, 0.13999999999999999, 0.156,
      0.16933333333333334, 0.18166666666666664, 0.193, 0.20166666666666666,
      0.20933333333333332, 0.216, 0.22066666666666668, 0.22400000000000003,
      0.226, 0.22533333333333333, 0.22300000000000003, 0.219,
      0.21300000000000002, 0.20566666666666666, 0.197, 0.18500000000000005,
      0.17166666666666669, 0.15700000000000003, 0.13900000000000007,
      0.11566666666666672, 0.087000000000000147, 0.057000000000000106 },

    { 0.0, 0.0, 0.0, 0.0, 0.069391555188066376, 0.079153058364369283,
      0.089126768131461379, 0.09931268448934269, 0.10780094812091046,
      0.1156525919801106, 0.12286761606694321, 0.12838498742746224,
      0.1332657390156137, 0.13750987083139757, 0.14048076310244631,
      0.14260282901033824, 0.1438760685550734, 0.143451655373495,
      0.14196620923797068, 0.13941973014850031, 0.13560001151429485,
      0.13093146651693258, 0.12541409515641352, 0.11777465788800259,
      0.10928639425643481, 0.0999493042617103, 0.088490148359093856,
      0.073635687003850286, 0.055385920195979675, 0.036287327024952208 },

    { 0.0, 0.0, 0.0, 0.0, 0.36843900509600297, 0.40090212918309748,
      0.42149701435663056, 0.43022366061660222, 0.42394047530942264,
      0.4130612563053247, 0.39758600360430829, 0.37699111843077521,
      0.35499996985564669, 0.33161255787892263, 0.30903963288646263,
      0.28768843837039865, 0.26755897433073073, 0.2499893265273212,
      0.23358323155857449, 0.21834068942449064, 0.20495983182586747,
      0.19192804007764314, 0.17924531417981768, 0.16819156225052026,
      0.15707963267948966, 0.14590952546672598, 0.13322679956890052,
      0.12036954074587561, 0.10733774899765133, 0.094422312532893266 },
    0.13333333333333333,
    5.5843492225709905,
    5.0,

    { 0.016666666666666666, 0.05, 0.083333333333333343, 0.11666666666666667,
      0.15, 0.18333333333333335, 0.21666666666666667, 0.25, 0.28333333333333333,
      0.31666666666666665, 0.35, 0.3833333333333333, 0.41666666666666669, 0.45,
      0.48333333333333334, 0.51666666666666661, 0.55, 0.58333333333333326,
      0.6166666666666667, 0.64999999999999991, 0.68333333333333335,
      0.71666666666666656, 0.75, 0.78333333333333344, 0.81666666666666665,
      0.85000000000000009, 0.8833333333333333, 0.91666666666666674, 0.95,
      0.98333333333333339 },
    0.033333333333333333
  },

  /* Variable: Quad
   * Referenced by:
   *   '<S1>/Constant'
   *   '<S2>/Constant'
   *   '<S613>/Constant'
   *   '<S614>/Constant'
   */
  {
    9.8,
    12.0,
    0.4675,
    0.02,
    0.1,
    6.6355e-8,
    0.16481,
    0.31892,
    1.1e-6,

    { 1.86, 0.0, 0.0, 0.0, 2.031, 0.0, 0.0, 0.0, 3.617 },

    { 0.5376344086021505, 0.0, -0.0, 0.0, 0.49236829148202854, -0.0, -0.0, -0.0,
      0.27647221454243848 }
  },

  /* Mask Parameter: PIDController2_D
   * Referenced by: '<S537>/Derivative Gain'
   */
  10.0,

  /* Mask Parameter: PIDController1_D
   * Referenced by: '<S388>/Derivative Gain'
   */
  0.0,

  /* Mask Parameter: PIDController_D
   * Referenced by: '<S585>/Derivative Gain'
   */
  0.0,

  /* Mask Parameter: PIDController2_D_n
   * Referenced by: '<S436>/Derivative Gain'
   */
  10.0,

  /* Mask Parameter: PIDController3_D
   * Referenced by: '<S484>/Derivative Gain'
   */
  0.0,

  /* Mask Parameter: PIDController1_D_m
   * Referenced by: '<S36>/Derivative Gain'
   */
  0.05,

  /* Mask Parameter: PIDController1_D_f
   * Referenced by: '<S138>/Derivative Gain'
   */
  0.25,

  /* Mask Parameter: PIDController_D_m
   * Referenced by: '<S189>/Derivative Gain'
   */
  0.01,

  /* Mask Parameter: PIDController_D_mc
   * Referenced by: '<S90>/Derivative Gain'
   */
  2.0,

  /* Mask Parameter: PIDController2_D_l
   * Referenced by: '<S237>/Derivative Gain'
   */
  1.0,

  /* Mask Parameter: PIDController3_D_m
   * Referenced by: '<S285>/Derivative Gain'
   */
  0.01,

  /* Mask Parameter: PIDController_D_h
   * Referenced by: '<S340>/Derivative Gain'
   */
  0.0,

  /* Mask Parameter: PIDController2_I
   * Referenced by: '<S540>/Integral Gain'
   */
  0.0,

  /* Mask Parameter: PIDController1_I
   * Referenced by: '<S39>/Integral Gain'
   */
  0.0,

  /* Mask Parameter: PIDController_I
   * Referenced by: '<S93>/Integral Gain'
   */
  0.0,

  /* Mask Parameter: PIDController1_I_j
   * Referenced by: '<S141>/Integral Gain'
   */
  0.005,

  /* Mask Parameter: PIDController_I_c
   * Referenced by: '<S192>/Integral Gain'
   */
  1.0,

  /* Mask Parameter: PIDController2_I_j
   * Referenced by: '<S240>/Integral Gain'
   */
  1.0,

  /* Mask Parameter: PIDController3_I
   * Referenced by: '<S288>/Integral Gain'
   */
  1.0,

  /* Mask Parameter: PIDController_I_a
   * Referenced by: '<S343>/Integral Gain'
   */
  0.0,

  /* Mask Parameter: PIDController1_I_d
   * Referenced by: '<S391>/Integral Gain'
   */
  0.0,

  /* Mask Parameter: PIDController2_I_g
   * Referenced by: '<S439>/Integral Gain'
   */
  0.0,

  /* Mask Parameter: PIDController3_I_g
   * Referenced by: '<S487>/Integral Gain'
   */
  0.0,

  /* Mask Parameter: PIDController_I_l
   * Referenced by: '<S588>/Integral Gain'
   */
  0.0,

  /* Mask Parameter: PIDController2_InitialCondition
   * Referenced by: '<S538>/Filter'
   */
  0.0,

  /* Mask Parameter: PIDController1_InitialCondition
   * Referenced by: '<S389>/Filter'
   */
  0.0,

  /* Mask Parameter: PIDController_InitialConditionF
   * Referenced by: '<S586>/Filter'
   */
  0.0,

  /* Mask Parameter: PIDController2_InitialConditi_n
   * Referenced by: '<S437>/Filter'
   */
  0.0,

  /* Mask Parameter: PIDController3_InitialCondition
   * Referenced by: '<S485>/Filter'
   */
  0.0,

  /* Mask Parameter: PIDController1_InitialConditi_o
   * Referenced by: '<S37>/Filter'
   */
  0.0,

  /* Mask Parameter: PIDController1_InitialConditi_e
   * Referenced by: '<S139>/Filter'
   */
  0.0,

  /* Mask Parameter: PIDController_InitialConditio_i
   * Referenced by: '<S190>/Filter'
   */
  0.0,

  /* Mask Parameter: PIDController_InitialConditio_k
   * Referenced by: '<S91>/Filter'
   */
  0.0,

  /* Mask Parameter: PIDController2_InitialConditi_k
   * Referenced by: '<S238>/Filter'
   */
  0.0,

  /* Mask Parameter: PIDController3_InitialConditi_f
   * Referenced by: '<S286>/Filter'
   */
  0.0,

  /* Mask Parameter: PIDController_InitialConditio_l
   * Referenced by: '<S341>/Filter'
   */
  0.0,

  /* Mask Parameter: PIDController2_InitialConditi_e
   * Referenced by: '<S543>/Integrator'
   */
  0.0,

  /* Mask Parameter: PIDController1_InitialConditi_f
   * Referenced by: '<S394>/Integrator'
   */
  0.0,

  /* Mask Parameter: PIDController_InitialConditio_o
   * Referenced by: '<S591>/Integrator'
   */
  0.0,

  /* Mask Parameter: PIDController2_InitialConditi_j
   * Referenced by: '<S442>/Integrator'
   */
  0.0,

  /* Mask Parameter: PIDController3_InitialConditi_n
   * Referenced by: '<S490>/Integrator'
   */
  0.0,

  /* Mask Parameter: PIDController1_InitialConditi_k
   * Referenced by: '<S42>/Integrator'
   */
  0.0,

  /* Mask Parameter: PIDController1_InitialConditi_d
   * Referenced by: '<S144>/Integrator'
   */
  0.0,

  /* Mask Parameter: PIDController_InitialConditio_p
   * Referenced by: '<S195>/Integrator'
   */
  0.0,

  /* Mask Parameter: PIDController_InitialConditio_g
   * Referenced by: '<S96>/Integrator'
   */
  0.0,

  /* Mask Parameter: PIDController2_InitialCondit_eb
   * Referenced by: '<S243>/Integrator'
   */
  0.0,

  /* Mask Parameter: PIDController3_InitialConditi_g
   * Referenced by: '<S291>/Integrator'
   */
  0.0,

  /* Mask Parameter: PIDController_InitialConditio_b
   * Referenced by: '<S346>/Integrator'
   */
  0.0,

  /* Mask Parameter: PIDController2_LowerSaturationL
   * Referenced by: '<S550>/Saturation'
   */
  -0.87266462599716477,

  /* Mask Parameter: PIDController1_LowerSaturationL
   * Referenced by: '<S401>/Saturation'
   */
  -1.0,

  /* Mask Parameter: PIDController_LowerSaturationLi
   * Referenced by: '<S598>/Saturation'
   */
  -4.0,

  /* Mask Parameter: PIDController2_LowerSaturatio_e
   * Referenced by: '<S449>/Saturation'
   */
  -0.87266462599716477,

  /* Mask Parameter: PIDController3_LowerSaturationL
   * Referenced by: '<S497>/Saturation'
   */
  -0.87266462599716477,

  /* Mask Parameter: PIDController1_LowerSaturatio_e
   * Referenced by: '<S151>/Saturation'
   */
  -0.87266462599716477,

  /* Mask Parameter: PIDController_LowerSaturation_g
   * Referenced by: '<S103>/Saturation'
   */
  -0.87266462599716477,

  /* Mask Parameter: PIDController2_N
   * Referenced by: '<S546>/Filter Coefficient'
   */
  100.0,

  /* Mask Parameter: PIDController1_N
   * Referenced by: '<S397>/Filter Coefficient'
   */
  100.0,

  /* Mask Parameter: PIDController_N
   * Referenced by: '<S594>/Filter Coefficient'
   */
  100.0,

  /* Mask Parameter: PIDController2_N_h
   * Referenced by: '<S445>/Filter Coefficient'
   */
  100.0,

  /* Mask Parameter: PIDController3_N
   * Referenced by: '<S493>/Filter Coefficient'
   */
  100.0,

  /* Mask Parameter: PIDController1_N_j
   * Referenced by: '<S45>/Filter Coefficient'
   */
  100.0,

  /* Mask Parameter: PIDController1_N_h
   * Referenced by: '<S147>/Filter Coefficient'
   */
  100.0,

  /* Mask Parameter: PIDController_N_n
   * Referenced by: '<S198>/Filter Coefficient'
   */
  100.0,

  /* Mask Parameter: PIDController_N_a
   * Referenced by: '<S99>/Filter Coefficient'
   */
  100.0,

  /* Mask Parameter: PIDController2_N_g
   * Referenced by: '<S246>/Filter Coefficient'
   */
  100.0,

  /* Mask Parameter: PIDController3_N_n
   * Referenced by: '<S294>/Filter Coefficient'
   */
  100.0,

  /* Mask Parameter: PIDController_N_ah
   * Referenced by: '<S349>/Filter Coefficient'
   */
  100.0,

  /* Mask Parameter: PIDController2_P
   * Referenced by: '<S548>/Proportional Gain'
   */
  1.0,

  /* Mask Parameter: PIDController1_P
   * Referenced by: '<S399>/Proportional Gain'
   */
  0.2,

  /* Mask Parameter: PIDController_P
   * Referenced by: '<S596>/Proportional Gain'
   */
  0.1,

  /* Mask Parameter: PIDController2_P_a
   * Referenced by: '<S447>/Proportional Gain'
   */
  1.0,

  /* Mask Parameter: PIDController3_P
   * Referenced by: '<S495>/Proportional Gain'
   */
  0.2,

  /* Mask Parameter: PIDController1_P_c
   * Referenced by: '<S47>/Proportional Gain'
   */
  0.01,

  /* Mask Parameter: PIDController1_P_j
   * Referenced by: '<S149>/Proportional Gain'
   */
  0.1,

  /* Mask Parameter: PIDController_P_e
   * Referenced by: '<S200>/Proportional Gain'
   */
  1.5,

  /* Mask Parameter: PIDController_P_eb
   * Referenced by: '<S101>/Proportional Gain'
   */
  0.1,

  /* Mask Parameter: PIDController2_P_l
   * Referenced by: '<S248>/Proportional Gain'
   */
  1.5,

  /* Mask Parameter: PIDController3_P_l
   * Referenced by: '<S296>/Proportional Gain'
   */
  1.5,

  /* Mask Parameter: PIDController2_UpperSaturationL
   * Referenced by: '<S550>/Saturation'
   */
  0.87266462599716477,

  /* Mask Parameter: PIDController1_UpperSaturationL
   * Referenced by: '<S401>/Saturation'
   */
  1.0,

  /* Mask Parameter: PIDController_UpperSaturationLi
   * Referenced by: '<S598>/Saturation'
   */
  4.0,

  /* Mask Parameter: PIDController2_UpperSaturatio_e
   * Referenced by: '<S449>/Saturation'
   */
  0.87266462599716477,

  /* Mask Parameter: PIDController3_UpperSaturationL
   * Referenced by: '<S497>/Saturation'
   */
  0.87266462599716477,

  /* Mask Parameter: PIDController1_UpperSaturatio_o
   * Referenced by: '<S151>/Saturation'
   */
  0.87266462599716477,

  /* Mask Parameter: PIDController_UpperSaturation_g
   * Referenced by: '<S103>/Saturation'
   */
  0.87266462599716477,

  /* Computed Parameter: theta_dot_des_Y0
   * Referenced by: '<S509>/theta_dot_des'
   */
  0.0,

  /* Expression: [0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0]
   * Referenced by: '<Root>/Delay'
   */
  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  /* Expression: 0
   * Referenced by: '<S8>/Constant'
   */
  0.0,

  /* Computed Parameter: Merge_InitialOutput
   * Referenced by: '<S310>/Merge'
   */
  0.0,

  /* Expression: -1
   * Referenced by: '<S9>/Gain1'
   */
  -1.0,

  /* Expression: 300
   * Referenced by: '<S1>/Delay'
   */
  300.0,

  /* Expression: -1
   * Referenced by: '<S59>/Gain1'
   */
  -1.0,

  /* Expression: 0
   * Referenced by: '<S8>/Constant2'
   */
  0.0,

  /* Expression: 180/pi
   * Referenced by: '<S612>/Gain1'
   */
  57.295779513082323,

  /* Expression: -1
   * Referenced by: '<S615>/Gain'
   */
  -1.0,

  /* Expression: 180/pi
   * Referenced by: '<S615>/Gain1'
   */
  57.295779513082323,

  /* Expression: 0
   * Referenced by: '<S2>/Integrator3'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S2>/Integrator4'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S2>/Integrator5'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S2>/Integrator'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S2>/Integrator1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S2>/Delay'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S2>/Integrator2'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S2>/Integrator6'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S2>/Integrator7'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S2>/Integrator8'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S2>/Integrator9'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S2>/Integrator10'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S2>/Integrator11'
   */
  0.0,

  /* Expression: -1
   * Referenced by: '<Root>/Gain1'
   */
  -1.0,

  /* Expression: -1
   * Referenced by: '<Root>/Gain'
   */
  -1.0,

  /* Expression: -1
   * Referenced by: '<Root>/Gain2'
   */
  -1.0,

  /* Expression: 180/pi
   * Referenced by: '<Root>/Gain3'
   */
  57.295779513082323,

  /* Expression: 60/(2*pi)
   * Referenced by: '<S1>/Gain'
   */
  9.5492965855137211,

  /* Expression: -1
   * Referenced by: '<S619>/Gain'
   */
  -1.0,

  /* Expression: -1
   * Referenced by: '<S620>/Gain'
   */
  -1.0,

  /* Expression: -1
   * Referenced by: '<S621>/Gain'
   */
  -1.0,

  /* Expression: -1
   * Referenced by: '<S622>/Gain'
   */
  -1.0
};
