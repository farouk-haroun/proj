/*
 * proj_data.cpp
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "proj".
 *
 * Model version              : 1.3
 * Simulink Coder version : 24.1 (R2024a) 19-Nov-2023
 * C++ source code generated on : Sun Nov 17 16:48:22 2024
 *
 * Target selection: ert.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Generic->Unspecified (assume 32-bit Generic)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "proj.h"

/* Block parameters (default storage) */
P_proj_T proj_P = {
  /* Computed Parameter: Constant_Value
   * Referenced by: '<S1>/Constant'
   */
  {
    0.0                                /* Data */
  },

  /* Computed Parameter: Constant_Value_b
   * Referenced by: '<S2>/Constant'
   */
  {
    0.0                                /* Data */
  },

  /* Computed Parameter: Out1_Y0
   * Referenced by: '<S8>/Out1'
   */
  {
    0.0                                /* Data */
  },

  /* Computed Parameter: Constant_Value_h
   * Referenced by: '<S6>/Constant'
   */
  {
    0.0                                /* Data */
  },

  /* Expression: 80
   * Referenced by: '<S7>/Saturation'
   */
  80.0,

  /* Expression: 0
   * Referenced by: '<S7>/Saturation'
   */
  0.0,

  /* Computed Parameter: TransferFcn_A
   * Referenced by: '<S7>/Transfer Fcn'
   */
  -0.5,

  /* Computed Parameter: TransferFcn_C
   * Referenced by: '<S7>/Transfer Fcn'
   */
  0.5
};
