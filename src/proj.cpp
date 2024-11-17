/*
 * proj.cpp
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
#include "rtwtypes.h"
#include "proj_types.h"
#include "proj_private.h"
#include <string.h>

/* Block signals (default storage) */
B_proj_T proj_B;

/* Continuous states */
X_proj_T proj_X;

/* Disabled State Vector */
XDis_proj_T proj_XDis;

/* Block states (default storage) */
DW_proj_T proj_DW;

/* Real-time model */
RT_MODEL_proj_T proj_M_ = RT_MODEL_proj_T();
RT_MODEL_proj_T *const proj_M = &proj_M_;

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
  ODE3_IntgData *id = static_cast<ODE3_IntgData *>(rtsiGetSolverData(si));
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T hB[3];
  int_T i;
  int_T nXc = 2;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                static_cast<uint_T>(nXc)*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  proj_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  proj_step();
  proj_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  proj_step();
  proj_derivatives();

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

/* Model step function */
void proj_step(void)
{
  SL_Bus_proj_std_msgs_Float64 rtb_BusAssignment;
  SL_Bus_proj_std_msgs_Float64 rtb_BusAssignment1;
  SL_Bus_proj_std_msgs_Float64 rtb_SourceBlock_o2_0;
  boolean_T b_varargout_1;
  if (rtmIsMajorTimeStep(proj_M)) {
    /* set solver stop time */
    if (!(proj_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&proj_M->solverInfo, ((proj_M->Timing.clockTickH0 +
        1) * proj_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&proj_M->solverInfo, ((proj_M->Timing.clockTick0 + 1)
        * proj_M->Timing.stepSize0 + proj_M->Timing.clockTickH0 *
        proj_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(proj_M)) {
    proj_M->Timing.t[0] = rtsiGetT(&proj_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(proj_M)) {
    /* Outputs for Atomic SubSystem: '<Root>/Subscribe' */
    /* MATLABSystem: '<S6>/SourceBlock' */
    b_varargout_1 = Sub_proj_16.getLatestMessage(&rtb_SourceBlock_o2_0);

    /* Outputs for Enabled SubSystem: '<S6>/Enabled Subsystem' incorporates:
     *  EnablePort: '<S8>/Enable'
     */
    /* Start for MATLABSystem: '<S6>/SourceBlock' */
    if (b_varargout_1) {
      /* SignalConversion generated from: '<S8>/In1' */
      proj_B.In1 = rtb_SourceBlock_o2_0;
    }

    /* End of Start for MATLABSystem: '<S6>/SourceBlock' */
    /* End of Outputs for SubSystem: '<S6>/Enabled Subsystem' */
    /* End of Outputs for SubSystem: '<Root>/Subscribe' */
  }

  /* Integrator: '<S7>/Integrator' */
  if (proj_DW.Integrator_IWORK != 0) {
    proj_X.Integrator_CSTATE = proj_B.In1.Data;
  }

  /* Saturate: '<S7>/Saturation' incorporates:
   *  Integrator: '<S7>/Integrator'
   */
  if (proj_X.Integrator_CSTATE > proj_P.Saturation_UpperSat) {
    /* BusAssignment: '<Root>/Bus Assignment' */
    rtb_BusAssignment.Data = proj_P.Saturation_UpperSat;
  } else if (proj_X.Integrator_CSTATE < proj_P.Saturation_LowerSat) {
    /* BusAssignment: '<Root>/Bus Assignment' */
    rtb_BusAssignment.Data = proj_P.Saturation_LowerSat;
  } else {
    /* BusAssignment: '<Root>/Bus Assignment' */
    rtb_BusAssignment.Data = proj_X.Integrator_CSTATE;
  }

  /* End of Saturate: '<S7>/Saturation' */

  /* Outputs for Atomic SubSystem: '<Root>/Publish' */
  /* MATLABSystem: '<S4>/SinkBlock' */
  Pub_proj_17.publish(&rtb_BusAssignment);

  /* End of Outputs for SubSystem: '<Root>/Publish' */
  if (rtmIsMajorTimeStep(proj_M)) {
    /* MATLAB Function: '<Root>/MATLAB Function1' */
    proj_B.accel_desired = (50.0 - proj_B.In1.Data) * 0.1;

    /* BusAssignment: '<Root>/Bus Assignment1' */
    rtb_BusAssignment1.Data = proj_B.accel_desired;

    /* Outputs for Atomic SubSystem: '<Root>/Publish1' */
    /* MATLABSystem: '<S5>/SinkBlock' */
    Pub_proj_25.publish(&rtb_BusAssignment1);

    /* End of Outputs for SubSystem: '<Root>/Publish1' */
  }

  /* TransferFcn: '<S7>/Transfer Fcn' */
  proj_B.TransferFcn = proj_P.TransferFcn_C * proj_X.TransferFcn_CSTATE;
  if (rtmIsMajorTimeStep(proj_M)) {
    /* Update for Integrator: '<S7>/Integrator' */
    proj_DW.Integrator_IWORK = 0;
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep(proj_M)) {
    rt_ertODEUpdateContinuousStates(&proj_M->solverInfo);

    /* Update absolute time for base rate */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick0 and the high bits
     * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++proj_M->Timing.clockTick0)) {
      ++proj_M->Timing.clockTickH0;
    }

    proj_M->Timing.t[0] = rtsiGetSolverStopTime(&proj_M->solverInfo);

    {
      /* Update absolute timer for sample time: [0.1s, 0.0s] */
      /* The "clockTick1" counts the number of times the code of this task has
       * been executed. The resolution of this integer timer is 0.1, which is the step size
       * of the task. Size of "clockTick1" ensures timer will not overflow during the
       * application lifespan selected.
       * Timer of this task consists of two 32 bit unsigned integers.
       * The two integers represent the low bits Timing.clockTick1 and the high bits
       * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
       */
      proj_M->Timing.clockTick1++;
      if (!proj_M->Timing.clockTick1) {
        proj_M->Timing.clockTickH1++;
      }
    }
  }                                    /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void proj_derivatives(void)
{
  XDot_proj_T *_rtXdot;
  _rtXdot = ((XDot_proj_T *) proj_M->derivs);

  /* Derivatives for Integrator: '<S7>/Integrator' */
  _rtXdot->Integrator_CSTATE = proj_B.TransferFcn;

  /* Derivatives for TransferFcn: '<S7>/Transfer Fcn' */
  _rtXdot->TransferFcn_CSTATE = proj_P.TransferFcn_A * proj_X.TransferFcn_CSTATE;
  _rtXdot->TransferFcn_CSTATE += proj_B.accel_desired;
}

/* Model initialize function */
void proj_initialize(void)
{
  /* Registration code */
  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&proj_M->solverInfo, &proj_M->Timing.simTimeStep);
    rtsiSetTPtr(&proj_M->solverInfo, &rtmGetTPtr(proj_M));
    rtsiSetStepSizePtr(&proj_M->solverInfo, &proj_M->Timing.stepSize0);
    rtsiSetdXPtr(&proj_M->solverInfo, &proj_M->derivs);
    rtsiSetContStatesPtr(&proj_M->solverInfo, (real_T **) &proj_M->contStates);
    rtsiSetNumContStatesPtr(&proj_M->solverInfo, &proj_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&proj_M->solverInfo,
      &proj_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&proj_M->solverInfo,
      &proj_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&proj_M->solverInfo,
      &proj_M->periodicContStateRanges);
    rtsiSetContStateDisabledPtr(&proj_M->solverInfo, (boolean_T**)
      &proj_M->contStateDisabled);
    rtsiSetErrorStatusPtr(&proj_M->solverInfo, (&rtmGetErrorStatus(proj_M)));
    rtsiSetRTModelPtr(&proj_M->solverInfo, proj_M);
  }

  rtsiSetSimTimeStep(&proj_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetIsMinorTimeStepWithModeChange(&proj_M->solverInfo, false);
  rtsiSetIsContModeFrozen(&proj_M->solverInfo, false);
  proj_M->intgData.y = proj_M->odeY;
  proj_M->intgData.f[0] = proj_M->odeF[0];
  proj_M->intgData.f[1] = proj_M->odeF[1];
  proj_M->intgData.f[2] = proj_M->odeF[2];
  proj_M->contStates = ((X_proj_T *) &proj_X);
  proj_M->contStateDisabled = ((XDis_proj_T *) &proj_XDis);
  proj_M->Timing.tStart = (0.0);
  rtsiSetSolverData(&proj_M->solverInfo, static_cast<void *>(&proj_M->intgData));
  rtsiSetSolverName(&proj_M->solverInfo,"ode3");
  rtmSetTPtr(proj_M, &proj_M->Timing.tArray[0]);
  proj_M->Timing.stepSize0 = 0.1;
  rtmSetFirstInitCond(proj_M, 1);

  /* block I/O */
  (void) memset((static_cast<void *>(&proj_B)), 0,
                sizeof(B_proj_T));

  /* states (continuous) */
  {
    (void) memset(static_cast<void *>(&proj_X), 0,
                  sizeof(X_proj_T));
  }

  /* disabled states */
  {
    (void) memset(static_cast<void *>(&proj_XDis), 0,
                  sizeof(XDis_proj_T));
  }

  /* states (dwork) */
  (void) memset(static_cast<void *>(&proj_DW), 0,
                sizeof(DW_proj_T));

  {
    char_T b_zeroDelimTopic_0[21];
    char_T b_zeroDelimTopic[17];
    static const char_T b_zeroDelimTopic_1[17] = "/car/state/vel_x";
    static const char_T b_zeroDelimTopic_2[21] = "/car/state/sim_vel_x";

    /* Start for Atomic SubSystem: '<Root>/Subscribe' */
    /* Start for MATLABSystem: '<S6>/SourceBlock' */
    proj_DW.obj_p.matlabCodegenIsDeleted = false;
    proj_DW.objisempty = true;
    proj_DW.obj_p.isInitialized = 1;
    for (int32_T i = 0; i < 17; i++) {
      b_zeroDelimTopic[i] = b_zeroDelimTopic_1[i];
    }

    Sub_proj_16.createSubscriber(&b_zeroDelimTopic[0], 1);
    proj_DW.obj_p.isSetupComplete = true;

    /* End of Start for MATLABSystem: '<S6>/SourceBlock' */
    /* End of Start for SubSystem: '<Root>/Subscribe' */

    /* Start for Atomic SubSystem: '<Root>/Publish' */
    /* Start for MATLABSystem: '<S4>/SinkBlock' */
    proj_DW.obj_j.matlabCodegenIsDeleted = false;
    proj_DW.objisempty_m = true;
    proj_DW.obj_j.isInitialized = 1;
    for (int32_T i = 0; i < 21; i++) {
      b_zeroDelimTopic_0[i] = b_zeroDelimTopic_2[i];
    }

    Pub_proj_17.createPublisher(&b_zeroDelimTopic_0[0], 1);
    proj_DW.obj_j.isSetupComplete = true;

    /* End of Start for MATLABSystem: '<S4>/SinkBlock' */
    /* End of Start for SubSystem: '<Root>/Publish' */

    /* Start for Atomic SubSystem: '<Root>/Publish1' */
    /* Start for MATLABSystem: '<S5>/SinkBlock' */
    proj_DW.obj.matlabCodegenIsDeleted = false;
    proj_DW.objisempty_g = true;
    proj_DW.obj.isInitialized = 1;
    for (int32_T i = 0; i < 21; i++) {
      b_zeroDelimTopic_0[i] = b_zeroDelimTopic_2[i];
    }

    Pub_proj_25.createPublisher(&b_zeroDelimTopic_0[0], 1);
    proj_DW.obj.isSetupComplete = true;

    /* End of Start for MATLABSystem: '<S5>/SinkBlock' */
    /* End of Start for SubSystem: '<Root>/Publish1' */
  }

  /* InitializeConditions for Integrator: '<S7>/Integrator' */
  if (rtmIsFirstInitCond(proj_M)) {
    proj_X.Integrator_CSTATE = 0.0;
  }

  proj_DW.Integrator_IWORK = 1;

  /* End of InitializeConditions for Integrator: '<S7>/Integrator' */

  /* InitializeConditions for TransferFcn: '<S7>/Transfer Fcn' */
  proj_X.TransferFcn_CSTATE = 0.0;

  /* SystemInitialize for Atomic SubSystem: '<Root>/Subscribe' */
  /* SystemInitialize for Enabled SubSystem: '<S6>/Enabled Subsystem' */
  /* SystemInitialize for SignalConversion generated from: '<S8>/In1' incorporates:
   *  Outport: '<S8>/Out1'
   */
  proj_B.In1 = proj_P.Out1_Y0;

  /* End of SystemInitialize for SubSystem: '<S6>/Enabled Subsystem' */
  /* End of SystemInitialize for SubSystem: '<Root>/Subscribe' */

  /* set "at time zero" to false */
  if (rtmIsFirstInitCond(proj_M)) {
    rtmSetFirstInitCond(proj_M, 0);
  }
}

/* Model terminate function */
void proj_terminate(void)
{
  /* Terminate for Atomic SubSystem: '<Root>/Subscribe' */
  /* Terminate for MATLABSystem: '<S6>/SourceBlock' */
  if (!proj_DW.obj_p.matlabCodegenIsDeleted) {
    proj_DW.obj_p.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S6>/SourceBlock' */
  /* End of Terminate for SubSystem: '<Root>/Subscribe' */

  /* Terminate for Atomic SubSystem: '<Root>/Publish' */
  /* Terminate for MATLABSystem: '<S4>/SinkBlock' */
  if (!proj_DW.obj_j.matlabCodegenIsDeleted) {
    proj_DW.obj_j.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S4>/SinkBlock' */
  /* End of Terminate for SubSystem: '<Root>/Publish' */

  /* Terminate for Atomic SubSystem: '<Root>/Publish1' */
  /* Terminate for MATLABSystem: '<S5>/SinkBlock' */
  if (!proj_DW.obj.matlabCodegenIsDeleted) {
    proj_DW.obj.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S5>/SinkBlock' */
  /* End of Terminate for SubSystem: '<Root>/Publish1' */
}
