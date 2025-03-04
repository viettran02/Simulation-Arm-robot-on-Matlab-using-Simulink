#include <math.h>
#include <string.h>
#include "pm_std.h"
#include "sm_std.h"
#include "ne_std.h"
#include "ne_dae.h"
#include "sm_ssci_run_time_errors.h"
#include "sm_RuntimeDerivedValuesBundle.h"
void ROBOT4_a2b15696_1_resetSimStateVector ( const void * mech , double *
state ) { double xx [ 1 ] ; ( void ) mech ; xx [ 0 ] = 0.0 ; state [ 0 ] = xx
[ 0 ] ; state [ 1 ] = xx [ 0 ] ; state [ 2 ] = xx [ 0 ] ; state [ 3 ] = xx [
0 ] ; state [ 4 ] = xx [ 0 ] ; state [ 5 ] = xx [ 0 ] ; state [ 6 ] = xx [ 0
] ; state [ 7 ] = xx [ 0 ] ; } static void perturbSimJointPrimitiveState_0_0
( double mag , double * state ) { state [ 0 ] = state [ 0 ] + mag ; } static
void perturbSimJointPrimitiveState_0_0v ( double mag , double * state ) {
state [ 0 ] = state [ 0 ] + mag ; state [ 1 ] = state [ 1 ] - 0.875 * mag ; }
static void perturbSimJointPrimitiveState_1_0 ( double mag , double * state )
{ state [ 2 ] = state [ 2 ] + mag ; } static void
perturbSimJointPrimitiveState_1_0v ( double mag , double * state ) { state [
2 ] = state [ 2 ] + mag ; state [ 3 ] = state [ 3 ] - 0.875 * mag ; } static
void perturbSimJointPrimitiveState_2_0 ( double mag , double * state ) {
state [ 4 ] = state [ 4 ] + mag ; } static void
perturbSimJointPrimitiveState_2_0v ( double mag , double * state ) { state [
4 ] = state [ 4 ] + mag ; state [ 5 ] = state [ 5 ] - 0.875 * mag ; } static
void perturbSimJointPrimitiveState_3_0 ( double mag , double * state ) {
state [ 6 ] = state [ 6 ] + mag ; } static void
perturbSimJointPrimitiveState_3_0v ( double mag , double * state ) { state [
6 ] = state [ 6 ] + mag ; state [ 7 ] = state [ 7 ] - 0.875 * mag ; } void
ROBOT4_a2b15696_1_perturbSimJointPrimitiveState ( const void * mech , size_t
stageIdx , size_t primIdx , double mag , boolean_T doPerturbVelocity , double
* state ) { ( void ) mech ; ( void ) stageIdx ; ( void ) primIdx ; ( void )
mag ; ( void ) doPerturbVelocity ; ( void ) state ; switch ( ( stageIdx * 6 +
primIdx ) * 2 + ( doPerturbVelocity ? 1 : 0 ) ) { case 0 :
perturbSimJointPrimitiveState_0_0 ( mag , state ) ; break ; case 1 :
perturbSimJointPrimitiveState_0_0v ( mag , state ) ; break ; case 12 :
perturbSimJointPrimitiveState_1_0 ( mag , state ) ; break ; case 13 :
perturbSimJointPrimitiveState_1_0v ( mag , state ) ; break ; case 24 :
perturbSimJointPrimitiveState_2_0 ( mag , state ) ; break ; case 25 :
perturbSimJointPrimitiveState_2_0v ( mag , state ) ; break ; case 36 :
perturbSimJointPrimitiveState_3_0 ( mag , state ) ; break ; case 37 :
perturbSimJointPrimitiveState_3_0v ( mag , state ) ; break ; } } void
ROBOT4_a2b15696_1_perturbFlexibleBodyState ( const void * mech , size_t
stageIdx , double mag , boolean_T doPerturbVelocity , double * state ) { (
void ) mech ; ( void ) stageIdx ; ( void ) mag ; ( void ) doPerturbVelocity ;
( void ) state ; switch ( stageIdx * 2 + ( doPerturbVelocity ? 1 : 0 ) ) { }
} void ROBOT4_a2b15696_1_constructStateVector ( const void * mech , const
double * solverState , const double * u , const double * uDot , double *
discreteState , double * fullState ) { ( void ) mech ; ( void ) solverState ;
( void ) discreteState ; fullState [ 0 ] = u [ 1 ] ; fullState [ 1 ] = uDot [
1 ] ; fullState [ 2 ] = u [ 0 ] ; fullState [ 3 ] = uDot [ 0 ] ; fullState [
4 ] = u [ 2 ] ; fullState [ 5 ] = uDot [ 2 ] ; fullState [ 6 ] = u [ 3 ] ;
fullState [ 7 ] = uDot [ 3 ] ; } void
ROBOT4_a2b15696_1_extractSolverStateVector ( const void * mech , const double
* fullState , double * solverState ) { ( void ) mech ; ( void ) fullState ; (
void ) solverState ; } boolean_T ROBOT4_a2b15696_1_isPositionViolation (
const void * mech , const RuntimeDerivedValuesBundle * rtdv , const int *
eqnEnableFlags , const double * state , const int * modeVector ) { const
double * rtdvd = rtdv -> mDoubles . mValues ; const int * rtdvi = rtdv ->
mInts . mValues ; ( void ) mech ; ( void ) rtdvd ; ( void ) rtdvi ; ( void )
eqnEnableFlags ; ( void ) state ; ( void ) modeVector ; return 0 ; }
boolean_T ROBOT4_a2b15696_1_isVelocityViolation ( const void * mech , const
RuntimeDerivedValuesBundle * rtdv , const int * eqnEnableFlags , const double
* state , const int * modeVector ) { const double * rtdvd = rtdv -> mDoubles
. mValues ; const int * rtdvi = rtdv -> mInts . mValues ; ( void ) mech ; (
void ) rtdvd ; ( void ) rtdvi ; ( void ) eqnEnableFlags ; ( void ) state ; (
void ) modeVector ; return 0 ; } PmfMessageId
ROBOT4_a2b15696_1_projectStateSim ( const void * mech , const
RuntimeDerivedValuesBundle * rtdv , const int * eqnEnableFlags , const int *
modeVector , double * state , void * neDiagMgr0 ) { const double * rtdvd =
rtdv -> mDoubles . mValues ; const int * rtdvi = rtdv -> mInts . mValues ;
NeuDiagnosticManager * neDiagMgr = ( NeuDiagnosticManager * ) neDiagMgr0 ; (
void ) mech ; ( void ) rtdvd ; ( void ) rtdvi ; ( void ) eqnEnableFlags ; (
void ) modeVector ; ( void ) state ; ( void ) neDiagMgr ; return NULL ; }
void ROBOT4_a2b15696_1_computeConstraintError ( const void * mech , const
RuntimeDerivedValuesBundle * rtdv , const double * state , const int *
modeVector , double * error ) { const double * rtdvd = rtdv -> mDoubles .
mValues ; const int * rtdvi = rtdv -> mInts . mValues ; ( void ) mech ; (
void ) rtdvd ; ( void ) rtdvi ; ( void ) state ; ( void ) modeVector ; ( void
) error ; } void ROBOT4_a2b15696_1_resetModeVector ( const void * mech , int
* modeVector ) { ( void ) mech ; ( void ) modeVector ; } boolean_T
ROBOT4_a2b15696_1_hasJointDisToNormModeChange ( const void * mech , const int
* prevModeVector , const int * modeVector ) { ( void ) mech ; ( void )
prevModeVector ; ( void ) modeVector ; return 0 ; } PmfMessageId
ROBOT4_a2b15696_1_performJointDisToNormModeChange ( const void * mech , const
RuntimeDerivedValuesBundle * rtdv , const int * eqnEnableFlags , const int *
prevModeVector , const int * modeVector , const double * input , double *
state , void * neDiagMgr0 ) { const double * rtdvd = rtdv -> mDoubles .
mValues ; const int * rtdvi = rtdv -> mInts . mValues ; NeuDiagnosticManager
* neDiagMgr = ( NeuDiagnosticManager * ) neDiagMgr0 ; ( void ) mech ; ( void
) rtdvd ; ( void ) rtdvi ; ( void ) eqnEnableFlags ; ( void ) prevModeVector
; ( void ) modeVector ; ( void ) input ; ( void ) state ; ( void ) neDiagMgr
; return NULL ; } void ROBOT4_a2b15696_1_onModeChangedCutJoints ( const void
* mech , const int * prevModeVector , const int * modeVector , double * state
) { ( void ) mech ; ( void ) prevModeVector ; ( void ) modeVector ; ( void )
state ; }
