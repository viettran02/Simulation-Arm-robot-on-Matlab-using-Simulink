#include <math.h>
#include <string.h>
#include "pm_std.h"
#include "sm_std.h"
#include "ne_std.h"
#include "ne_dae.h"
#include "sm_ssci_run_time_errors.h"
#include "sm_RuntimeDerivedValuesBundle.h"
#include "sm_CTarget.h"
void ROBOT4_a2b15696_1_setTargets ( const RuntimeDerivedValuesBundle * rtdv ,
CTarget * targets ) { ( void ) rtdv ; ( void ) targets ; } void
ROBOT4_a2b15696_1_resetAsmStateVector ( const void * mech , double * state )
{ double xx [ 1 ] ; ( void ) mech ; xx [ 0 ] = 0.0 ; state [ 0 ] = xx [ 0 ] ;
state [ 1 ] = xx [ 0 ] ; state [ 2 ] = xx [ 0 ] ; state [ 3 ] = xx [ 0 ] ;
state [ 4 ] = xx [ 0 ] ; state [ 5 ] = xx [ 0 ] ; state [ 6 ] = xx [ 0 ] ;
state [ 7 ] = xx [ 0 ] ; } void ROBOT4_a2b15696_1_initializeTrackedAngleState
( const void * mech , const RuntimeDerivedValuesBundle * rtdv , const int *
modeVector , const double * motionData , double * state ) { const double *
rtdvd = rtdv -> mDoubles . mValues ; const int * rtdvi = rtdv -> mInts .
mValues ; ( void ) mech ; ( void ) rtdvd ; ( void ) rtdvi ; ( void ) state ;
( void ) modeVector ; ( void ) motionData ; } void
ROBOT4_a2b15696_1_computeDiscreteState ( const void * mech , const
RuntimeDerivedValuesBundle * rtdv , double * state ) { const double * rtdvd =
rtdv -> mDoubles . mValues ; const int * rtdvi = rtdv -> mInts . mValues ; (
void ) mech ; ( void ) rtdvd ; ( void ) rtdvi ; ( void ) state ; } void
ROBOT4_a2b15696_1_adjustPosition ( const void * mech , const double *
dofDeltas , double * state ) { ( void ) mech ; state [ 0 ] = state [ 0 ] +
dofDeltas [ 0 ] ; state [ 2 ] = state [ 2 ] + dofDeltas [ 1 ] ; state [ 4 ] =
state [ 4 ] + dofDeltas [ 2 ] ; state [ 6 ] = state [ 6 ] + dofDeltas [ 3 ] ;
} static void perturbAsmJointPrimitiveState_0_0 ( double mag , double * state
) { state [ 0 ] = state [ 0 ] + mag ; } static void
perturbAsmJointPrimitiveState_0_0v ( double mag , double * state ) { state [
0 ] = state [ 0 ] + mag ; state [ 1 ] = state [ 1 ] - 0.875 * mag ; } static
void perturbAsmJointPrimitiveState_1_0 ( double mag , double * state ) {
state [ 2 ] = state [ 2 ] + mag ; } static void
perturbAsmJointPrimitiveState_1_0v ( double mag , double * state ) { state [
2 ] = state [ 2 ] + mag ; state [ 3 ] = state [ 3 ] - 0.875 * mag ; } static
void perturbAsmJointPrimitiveState_2_0 ( double mag , double * state ) {
state [ 4 ] = state [ 4 ] + mag ; } static void
perturbAsmJointPrimitiveState_2_0v ( double mag , double * state ) { state [
4 ] = state [ 4 ] + mag ; state [ 5 ] = state [ 5 ] - 0.875 * mag ; } static
void perturbAsmJointPrimitiveState_3_0 ( double mag , double * state ) {
state [ 6 ] = state [ 6 ] + mag ; } static void
perturbAsmJointPrimitiveState_3_0v ( double mag , double * state ) { state [
6 ] = state [ 6 ] + mag ; state [ 7 ] = state [ 7 ] - 0.875 * mag ; } void
ROBOT4_a2b15696_1_perturbAsmJointPrimitiveState ( const void * mech , size_t
stageIdx , size_t primIdx , double mag , boolean_T doPerturbVelocity , double
* state ) { ( void ) mech ; ( void ) stageIdx ; ( void ) primIdx ; ( void )
mag ; ( void ) doPerturbVelocity ; ( void ) state ; switch ( ( stageIdx * 6 +
primIdx ) * 2 + ( doPerturbVelocity ? 1 : 0 ) ) { case 0 :
perturbAsmJointPrimitiveState_0_0 ( mag , state ) ; break ; case 1 :
perturbAsmJointPrimitiveState_0_0v ( mag , state ) ; break ; case 12 :
perturbAsmJointPrimitiveState_1_0 ( mag , state ) ; break ; case 13 :
perturbAsmJointPrimitiveState_1_0v ( mag , state ) ; break ; case 24 :
perturbAsmJointPrimitiveState_2_0 ( mag , state ) ; break ; case 25 :
perturbAsmJointPrimitiveState_2_0v ( mag , state ) ; break ; case 36 :
perturbAsmJointPrimitiveState_3_0 ( mag , state ) ; break ; case 37 :
perturbAsmJointPrimitiveState_3_0v ( mag , state ) ; break ; } } void
ROBOT4_a2b15696_1_computePosDofBlendMatrix ( const void * mech , size_t
stageIdx , size_t primIdx , const double * state , int partialType , double *
matrix ) { ( void ) mech ; ( void ) stageIdx ; ( void ) primIdx ; ( void )
state ; ( void ) partialType ; ( void ) matrix ; switch ( ( stageIdx * 6 +
primIdx ) ) { } } void ROBOT4_a2b15696_1_computeVelDofBlendMatrix ( const
void * mech , size_t stageIdx , size_t primIdx , const double * state , int
partialType , double * matrix ) { ( void ) mech ; ( void ) stageIdx ; ( void
) primIdx ; ( void ) state ; ( void ) partialType ; ( void ) matrix ; switch
( ( stageIdx * 6 + primIdx ) ) { } } void
ROBOT4_a2b15696_1_projectPartiallyTargetedPos ( const void * mech , size_t
stageIdx , size_t primIdx , const double * origState , int partialType ,
double * state ) { ( void ) mech ; ( void ) stageIdx ; ( void ) primIdx ; (
void ) origState ; ( void ) partialType ; ( void ) state ; switch ( (
stageIdx * 6 + primIdx ) ) { } } void ROBOT4_a2b15696_1_propagateMotion (
const void * mech , const RuntimeDerivedValuesBundle * rtdv , const double *
state , double * motionData ) { const double * rtdvd = rtdv -> mDoubles .
mValues ; const int * rtdvi = rtdv -> mInts . mValues ; double xx [ 64 ] ; (
void ) mech ; ( void ) rtdvd ; ( void ) rtdvi ; xx [ 0 ] =
2.345081265286985e-8 ; xx [ 1 ] = 0.5 ; xx [ 2 ] = xx [ 1 ] * state [ 0 ] ;
xx [ 3 ] = sin ( xx [ 2 ] ) ; xx [ 4 ] = 0.9999999999999998 ; xx [ 5 ] = cos
( xx [ 2 ] ) ; xx [ 2 ] = xx [ 0 ] * xx [ 3 ] - xx [ 4 ] * xx [ 5 ] ; xx [ 6
] = 7.111936761727833e-9 ; xx [ 7 ] = xx [ 6 ] * xx [ 3 ] ; xx [ 8 ] =
3.555968380863916e-9 ; xx [ 9 ] = xx [ 4 ] * xx [ 7 ] - xx [ 8 ] * xx [ 3 ] ;
xx [ 10 ] = xx [ 4 ] * xx [ 3 ] + xx [ 0 ] * xx [ 5 ] + xx [ 8 ] * xx [ 7 ] ;
xx [ 3 ] = - xx [ 10 ] ; xx [ 4 ] = xx [ 8 ] * xx [ 5 ] - xx [ 0 ] * xx [ 7 ]
; xx [ 0 ] = 2.0 ; xx [ 11 ] = xx [ 9 ] ; xx [ 12 ] = xx [ 3 ] ; xx [ 13 ] =
xx [ 4 ] ; xx [ 5 ] = 0.2110693376440062 ; xx [ 7 ] = xx [ 5 ] * xx [ 4 ] ;
xx [ 8 ] = 1.651323585286483e-9 ; xx [ 14 ] = xx [ 8 ] * xx [ 4 ] ; xx [ 15 ]
= xx [ 10 ] * xx [ 8 ] - xx [ 5 ] * xx [ 9 ] ; xx [ 16 ] = xx [ 7 ] ; xx [ 17
] = xx [ 14 ] ; xx [ 18 ] = xx [ 15 ] ; pm_math_Vector3_cross_ra ( xx + 11 ,
xx + 16 , xx + 19 ) ; xx [ 10 ] = - 0.4998763623287242 ; xx [ 11 ] = -
0.4999895155531592 ; xx [ 12 ] = - 0.5001270401945291 ; xx [ 13 ] =
0.5000070503384719 ; xx [ 5 ] = xx [ 1 ] * state [ 2 ] ; xx [ 8 ] =
0.9999999368405583 ; xx [ 16 ] = sin ( xx [ 5 ] ) ; xx [ 17 ] =
2.682587515487889e-4 ; xx [ 18 ] = 2.331439939649016e-4 ; xx [ 22 ] = cos (
xx [ 5 ] ) ; xx [ 23 ] = xx [ 8 ] * xx [ 16 ] ; xx [ 24 ] = xx [ 17 ] * xx [
16 ] ; xx [ 25 ] = xx [ 18 ] * xx [ 16 ] ; pm_math_Quaternion_compose_ra ( xx
+ 10 , xx + 22 , xx + 26 ) ; xx [ 10 ] = - 0.09003650109512783 ; xx [ 11 ] =
- 0.1907910922015477 ; xx [ 12 ] = - 1.498417782861893e-5 ;
pm_math_Quaternion_xform_ra ( xx + 26 , xx + 10 , xx + 22 ) ; xx [ 5 ] =
4.945209546473706e-9 + xx [ 22 ] ; xx [ 10 ] = 0.122930662355996 - xx [ 23 ]
; xx [ 11 ] = 0.08999999999999687 - xx [ 24 ] ; xx [ 22 ] = -
0.9973986827596037 ; xx [ 23 ] = 0.07208214792584919 ; xx [ 24 ] =
1.259376296445236e-4 ; xx [ 25 ] = - 1.25377497638246e-4 ; xx [ 12 ] = xx [ 1
] * state [ 4 ] ; xx [ 13 ] = sin ( xx [ 12 ] ) ; xx [ 16 ] =
4.94388030514159e-10 ; xx [ 30 ] = 1.038915287132625e-9 ; xx [ 31 ] = cos (
xx [ 12 ] ) ; xx [ 32 ] = - xx [ 13 ] ; xx [ 33 ] = - ( xx [ 16 ] * xx [ 13 ]
) ; xx [ 34 ] = xx [ 30 ] * xx [ 13 ] ; pm_math_Quaternion_compose_ra ( xx +
22 , xx + 31 , xx + 35 ) ; xx [ 22 ] = 0.0900000001342003 ; xx [ 23 ] = -
0.1510893930791175 ; xx [ 24 ] = 0.1033098699021708 ;
pm_math_Quaternion_xform_ra ( xx + 35 , xx + 22 , xx + 31 ) ; xx [ 12 ] =
0.08982935736427131 - xx [ 31 ] ; xx [ 13 ] = 0.3092571763712736 - xx [ 32 ]
; xx [ 22 ] = 3.038086242508696e-5 - xx [ 33 ] ; xx [ 31 ] = -
0.4626553531997686 ; xx [ 32 ] = - 0.5347407510105774 ; xx [ 33 ] = -
0.4626573453456229 ; xx [ 34 ] = - 0.5347434283485699 ; xx [ 23 ] = xx [ 1 ]
* state [ 6 ] ; xx [ 1 ] = 4.70638862497727e-6 ; xx [ 24 ] = sin ( xx [ 23 ]
) ; xx [ 25 ] = 3.479055778288358e-7 ; xx [ 39 ] = 0.9999999999888645 ; xx [
40 ] = cos ( xx [ 23 ] ) ; xx [ 41 ] = - ( xx [ 1 ] * xx [ 24 ] ) ; xx [ 42 ]
= - ( xx [ 25 ] * xx [ 24 ] ) ; xx [ 43 ] = xx [ 39 ] * xx [ 24 ] ;
pm_math_Quaternion_compose_ra ( xx + 31 , xx + 40 , xx + 44 ) ; xx [ 31 ] =
2.36342441318594e-7 ; xx [ 32 ] = - 4.3089913000657e-3 ; xx [ 33 ] = -
0.05000002126798012 ; pm_math_Quaternion_xform_ra ( xx + 44 , xx + 31 , xx +
40 ) ; xx [ 23 ] = - ( 0.05000000015942875 + xx [ 40 ] ) ; xx [ 24 ] =
0.2606559248742017 - xx [ 41 ] ; xx [ 31 ] = 0.01661624009575827 - xx [ 42 ]
; xx [ 32 ] = xx [ 6 ] * state [ 1 ] ; xx [ 6 ] = 0.0 ; xx [ 33 ] =
5.389682884229411e-15 * state [ 1 ] ; xx [ 34 ] = 1.502118036225308e-10 *
state [ 1 ] ; xx [ 40 ] = xx [ 29 ] * state [ 1 ] ; xx [ 41 ] = xx [ 29 ] *
xx [ 32 ] ; xx [ 42 ] = xx [ 27 ] * state [ 1 ] + xx [ 28 ] * xx [ 32 ] ; xx
[ 48 ] = - xx [ 40 ] ; xx [ 49 ] = - xx [ 41 ] ; xx [ 50 ] = xx [ 42 ] ;
pm_math_Vector3_cross_ra ( xx + 27 , xx + 48 , xx + 51 ) ; xx [ 43 ] = ( xx [
26 ] * xx [ 40 ] + xx [ 51 ] ) * xx [ 0 ] - xx [ 32 ] + xx [ 8 ] * state [ 3
] ; xx [ 8 ] = state [ 1 ] + xx [ 0 ] * ( xx [ 52 ] + xx [ 26 ] * xx [ 41 ] )
+ xx [ 17 ] * state [ 3 ] ; xx [ 17 ] = xx [ 0 ] * ( xx [ 53 ] - xx [ 26 ] *
xx [ 42 ] ) + xx [ 18 ] * state [ 3 ] ; xx [ 40 ] = xx [ 11 ] * state [ 1 ] +
xx [ 33 ] ; xx [ 41 ] = xx [ 32 ] * xx [ 11 ] ; xx [ 42 ] = xx [ 5 ] * state
[ 1 ] - xx [ 32 ] * xx [ 10 ] + xx [ 34 ] ;
pm_math_Quaternion_inverseXform_ra ( xx + 26 , xx + 40 , xx + 48 ) ; xx [ 18
] = xx [ 48 ] - 4.447777761195734e-5 * state [ 3 ] ; xx [ 40 ] = xx [ 49 ] +
6.007292585716716e-6 * state [ 3 ] ; xx [ 41 ] = xx [ 50 ] +
0.1907669270719113 * state [ 3 ] ; xx [ 48 ] = xx [ 43 ] ; xx [ 49 ] = xx [ 8
] ; xx [ 50 ] = xx [ 17 ] ; pm_math_Quaternion_inverseXform_ra ( xx + 35 , xx
+ 48 , xx + 51 ) ; xx [ 42 ] = xx [ 51 ] - state [ 5 ] ; xx [ 54 ] = xx [ 52
] - xx [ 16 ] * state [ 5 ] ; xx [ 16 ] = xx [ 53 ] + xx [ 30 ] * state [ 5 ]
; xx [ 51 ] = xx [ 12 ] ; xx [ 52 ] = xx [ 13 ] ; xx [ 53 ] = xx [ 22 ] ;
pm_math_Vector3_cross_ra ( xx + 48 , xx + 51 , xx + 55 ) ; xx [ 48 ] = xx [
55 ] + xx [ 18 ] ; xx [ 49 ] = xx [ 56 ] + xx [ 40 ] ; xx [ 50 ] = xx [ 57 ]
+ xx [ 41 ] ; pm_math_Quaternion_inverseXform_ra ( xx + 35 , xx + 48 , xx +
51 ) ; xx [ 30 ] = xx [ 51 ] - 1.058939170798771e-10 * state [ 5 ] ; xx [ 48
] = xx [ 52 ] - 0.1033098699956732 * state [ 5 ] ; xx [ 49 ] = xx [ 53 ] -
0.1510893931236125 * state [ 5 ] ; xx [ 50 ] = xx [ 42 ] ; xx [ 51 ] = xx [
54 ] ; xx [ 52 ] = xx [ 16 ] ; pm_math_Quaternion_inverseXform_ra ( xx + 44 ,
xx + 50 , xx + 55 ) ; xx [ 58 ] = xx [ 23 ] ; xx [ 59 ] = xx [ 24 ] ; xx [ 60
] = xx [ 31 ] ; pm_math_Vector3_cross_ra ( xx + 50 , xx + 58 , xx + 61 ) ; xx
[ 50 ] = xx [ 61 ] + xx [ 30 ] ; xx [ 51 ] = xx [ 62 ] + xx [ 48 ] ; xx [ 52
] = xx [ 63 ] + xx [ 49 ] ; pm_math_Quaternion_inverseXform_ra ( xx + 44 , xx
+ 50 , xx + 58 ) ; motionData [ 0 ] = xx [ 2 ] ; motionData [ 1 ] = xx [ 9 ]
; motionData [ 2 ] = xx [ 3 ] ; motionData [ 3 ] = xx [ 4 ] ; motionData [ 4
] = 0.1438316677651026 - xx [ 0 ] * ( xx [ 19 ] + xx [ 7 ] * xx [ 2 ] ) ;
motionData [ 5 ] = 0.5239098597314447 - ( xx [ 14 ] * xx [ 2 ] + xx [ 20 ] )
* xx [ 0 ] ; motionData [ 6 ] = 0.4572493612016191 - ( xx [ 15 ] * xx [ 2 ] +
xx [ 21 ] ) * xx [ 0 ] ; motionData [ 7 ] = xx [ 26 ] ; motionData [ 8 ] = xx
[ 27 ] ; motionData [ 9 ] = xx [ 28 ] ; motionData [ 10 ] = xx [ 29 ] ;
motionData [ 11 ] = - xx [ 5 ] ; motionData [ 12 ] = xx [ 10 ] ; motionData [
13 ] = xx [ 11 ] ; motionData [ 14 ] = xx [ 35 ] ; motionData [ 15 ] = xx [
36 ] ; motionData [ 16 ] = xx [ 37 ] ; motionData [ 17 ] = xx [ 38 ] ;
motionData [ 18 ] = xx [ 12 ] ; motionData [ 19 ] = xx [ 13 ] ; motionData [
20 ] = xx [ 22 ] ; motionData [ 21 ] = xx [ 44 ] ; motionData [ 22 ] = xx [
45 ] ; motionData [ 23 ] = xx [ 46 ] ; motionData [ 24 ] = xx [ 47 ] ;
motionData [ 25 ] = xx [ 23 ] ; motionData [ 26 ] = xx [ 24 ] ; motionData [
27 ] = xx [ 31 ] ; motionData [ 28 ] = - xx [ 32 ] ; motionData [ 29 ] =
state [ 1 ] ; motionData [ 30 ] = xx [ 6 ] ; motionData [ 31 ] = xx [ 33 ] ;
motionData [ 32 ] = xx [ 6 ] ; motionData [ 33 ] = xx [ 34 ] ; motionData [
34 ] = xx [ 43 ] ; motionData [ 35 ] = xx [ 8 ] ; motionData [ 36 ] = xx [ 17
] ; motionData [ 37 ] = xx [ 18 ] ; motionData [ 38 ] = xx [ 40 ] ;
motionData [ 39 ] = xx [ 41 ] ; motionData [ 40 ] = xx [ 42 ] ; motionData [
41 ] = xx [ 54 ] ; motionData [ 42 ] = xx [ 16 ] ; motionData [ 43 ] = xx [
30 ] ; motionData [ 44 ] = xx [ 48 ] ; motionData [ 45 ] = xx [ 49 ] ;
motionData [ 46 ] = xx [ 55 ] - xx [ 1 ] * state [ 7 ] ; motionData [ 47 ] =
xx [ 56 ] - xx [ 25 ] * state [ 7 ] ; motionData [ 48 ] = xx [ 57 ] + xx [ 39
] * state [ 7 ] ; motionData [ 49 ] = xx [ 58 ] - 4.309008695304007e-3 *
state [ 7 ] ; motionData [ 50 ] = xx [ 59 ] - 1.022909971718933e-9 * state [
7 ] ; motionData [ 51 ] = xx [ 60 ] - 2.027986986460884e-8 * state [ 7 ] ; }
size_t ROBOT4_a2b15696_1_computeAssemblyError ( const void * mech , const
RuntimeDerivedValuesBundle * rtdv , size_t constraintIdx , const int *
modeVector , const double * motionData , double * error ) { ( void ) mech ; (
void ) rtdv ; ( void ) modeVector ; ( void ) motionData ; ( void ) error ;
switch ( constraintIdx ) { } return 0 ; } size_t
ROBOT4_a2b15696_1_computeAssemblyJacobian ( const void * mech , const
RuntimeDerivedValuesBundle * rtdv , size_t constraintIdx , boolean_T
forVelocitySatisfaction , const double * state , const int * modeVector ,
const double * motionData , double * J ) { ( void ) mech ; ( void ) rtdv ; (
void ) state ; ( void ) modeVector ; ( void ) forVelocitySatisfaction ; (
void ) motionData ; ( void ) J ; switch ( constraintIdx ) { } return 0 ; }
size_t ROBOT4_a2b15696_1_computeFullAssemblyJacobian ( const void * mech ,
const RuntimeDerivedValuesBundle * rtdv , const double * state , const int *
modeVector , const double * motionData , double * J ) { const double * rtdvd
= rtdv -> mDoubles . mValues ; const int * rtdvi = rtdv -> mInts . mValues ;
( void ) mech ; ( void ) rtdvd ; ( void ) rtdvi ; ( void ) state ; ( void )
modeVector ; ( void ) motionData ; ( void ) J ; return 0 ; } boolean_T
ROBOT4_a2b15696_1_isInKinematicSingularity ( const void * mech , const
RuntimeDerivedValuesBundle * rtdv , size_t constraintIdx , const int *
modeVector , const double * motionData ) { ( void ) mech ; ( void ) rtdv ; (
void ) modeVector ; ( void ) motionData ; switch ( constraintIdx ) { } return
0 ; } void ROBOT4_a2b15696_1_convertStateVector ( const void * asmMech ,
const RuntimeDerivedValuesBundle * rtdv , const void * simMech , const double
* asmState , const int * asmModeVector , const int * simModeVector , double *
simState ) { const double * rtdvd = rtdv -> mDoubles . mValues ; const int *
rtdvi = rtdv -> mInts . mValues ; ( void ) asmMech ; ( void ) rtdvd ; ( void
) rtdvi ; ( void ) simMech ; ( void ) asmModeVector ; ( void ) simModeVector
; simState [ 0 ] = asmState [ 0 ] ; simState [ 1 ] = asmState [ 1 ] ;
simState [ 2 ] = asmState [ 2 ] ; simState [ 3 ] = asmState [ 3 ] ; simState
[ 4 ] = asmState [ 4 ] ; simState [ 5 ] = asmState [ 5 ] ; simState [ 6 ] =
asmState [ 6 ] ; simState [ 7 ] = asmState [ 7 ] ; }
