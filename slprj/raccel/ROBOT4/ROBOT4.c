#include "rt_logging_mmi.h"
#include "ROBOT4_capi.h"
#include <math.h>
#include "ROBOT4.h"
#include "ROBOT4_private.h"
#include "ROBOT4_dt.h"
extern void * CreateDiagnosticAsVoidPtr_wrapper ( const char * id , int nargs
, ... ) ; RTWExtModeInfo * gblRTWExtModeInfo = NULL ; void
raccelForceExtModeShutdown ( boolean_T extModeStartPktReceived ) { if ( !
extModeStartPktReceived ) { boolean_T stopRequested = false ;
rtExtModeWaitForStartPkt ( gblRTWExtModeInfo , 1 , & stopRequested ) ; }
rtExtModeShutdown ( 1 ) ; }
#include "slsv_diagnostic_codegen_c_api.h"
#include "slsa_sim_engine.h"
const int_T gblNumToFiles = 0 ; const int_T gblNumFrFiles = 0 ; const int_T
gblNumFrWksBlocks = 0 ;
#ifdef RSIM_WITH_SOLVER_MULTITASKING
boolean_T gbl_raccel_isMultitasking = 1 ;
#else
boolean_T gbl_raccel_isMultitasking = 0 ;
#endif
boolean_T gbl_raccel_tid01eq = 0 ; int_T gbl_raccel_NumST = 2 ; const char_T
* gbl_raccel_Version = "9.6 (R2021b) 14-May-2021" ; void
raccel_setup_MMIStateLog ( SimStruct * S ) {
#ifdef UseMMIDataLogging
rt_FillStateSigInfoFromMMI ( ssGetRTWLogInfo ( S ) , & ssGetErrorStatus ( S )
) ;
#else
UNUSED_PARAMETER ( S ) ;
#endif
} static DataMapInfo rt_dataMapInfo ; DataMapInfo * rt_dataMapInfoPtr = &
rt_dataMapInfo ; rtwCAPI_ModelMappingInfo * rt_modelMapInfoPtr = & (
rt_dataMapInfo . mmi ) ; const int_T gblNumRootInportBlks = 0 ; const int_T
gblNumModelInputs = 0 ; extern const char * gblInportFileName ; extern
rtInportTUtable * gblInportTUtables ; const int_T gblInportDataTypeIdx [ ] =
{ - 1 } ; const int_T gblInportDims [ ] = { - 1 } ; const int_T
gblInportComplex [ ] = { - 1 } ; const int_T gblInportInterpoFlag [ ] = { - 1
} ; const int_T gblInportContinuous [ ] = { - 1 } ; int_T enableFcnCallFlag [
] = { 1 , 1 } ; const char * raccelLoadInputsAndAperiodicHitTimes ( SimStruct
* S , const char * inportFileName , int * matFileFormat ) { return
rt_RAccelReadInportsMatFile ( S , inportFileName , matFileFormat ) ; }
#include "simstruc.h"
#include "fixedpoint.h"
#include "slsa_sim_engine.h"
#include "simtarget/slSimTgtSLExecSimBridge.h"
B rtB ; DW rtDW ; static SimStruct model_S ; SimStruct * const rtS = &
model_S ; void MdlStart ( void ) { NeModelParameters modelParameters ;
NeslSimulationData * tmp_e ; NeslSimulator * tmp ; NeuDiagnosticManager *
diagnosticManager ; NeuDiagnosticTree * diagnosticTree ; char * msg ; real_T
tmp_i ; int32_T tmp_m ; boolean_T tmp_p ; boolean_T val ; { bool
externalInputIsInDatasetFormat = false ; void * pISigstreamManager =
rt_GetISigstreamManager ( rtS ) ;
rtwISigstreamManagerGetInputIsInDatasetFormat ( pISigstreamManager , &
externalInputIsInDatasetFormat ) ; if ( externalInputIsInDatasetFormat ) { }
} tmp = nesl_lease_simulator ( "ROBOT4/Solver Configuration_1" , 0 , 0 ) ;
rtDW . cprcs12blm = ( void * ) tmp ; tmp_p = pointer_is_null ( rtDW .
cprcs12blm ) ; if ( tmp_p ) { ROBOT4_a2b15696_1_gateway ( ) ; tmp =
nesl_lease_simulator ( "ROBOT4/Solver Configuration_1" , 0 , 0 ) ; rtDW .
cprcs12blm = ( void * ) tmp ; } slsaSaveRawMemoryForSimTargetOP ( rtS ,
"ROBOT4/Solver Configuration_100" , ( void * * ) ( & rtDW . cprcs12blm ) , 0U
* sizeof ( real_T ) , nesl_save_simdata , nesl_restore_simdata ) ; tmp_e =
nesl_create_simulation_data ( ) ; rtDW . cuvqd4ac0y = ( void * ) tmp_e ;
diagnosticManager = rtw_create_diagnostics ( ) ; rtDW . pyozqcgn5e = ( void *
) diagnosticManager ; modelParameters . mSolverType = NE_SOLVER_TYPE_DAE ;
modelParameters . mSolverTolerance = 0.001 ; modelParameters .
mVariableStepSolver = true ; modelParameters . mIsUsingODEN = false ;
modelParameters . mFixedStepSize = 0.001 ; modelParameters . mStartTime = 0.0
; modelParameters . mLoadInitialState = false ; modelParameters .
mUseSimState = false ; modelParameters . mLinTrimCompile = false ;
modelParameters . mLoggingMode = SSC_LOGGING_NONE ; modelParameters .
mRTWModifiedTimeStamp = 6.2256738E+8 ; modelParameters . mZcDisabled = false
; tmp_i = ( - 1.0 ) ; modelParameters . mSolverTolerance = tmp_i ; tmp_i =
0.0 ; modelParameters . mFixedStepSize = tmp_i ; tmp_p = true ;
modelParameters . mVariableStepSolver = tmp_p ; tmp_p = false ;
modelParameters . mIsUsingODEN = tmp_p ; val = false ; tmp_p =
slIsRapidAcceleratorSimulating ( ) ; if ( tmp_p ) { tmp_p =
ssGetGlobalInitialStatesAvailable ( rtS ) ; val = ( tmp_p &&
ssIsFirstInitCond ( rtS ) ) ; } modelParameters . mLoadInitialState = val ;
modelParameters . mZcDisabled = false ; diagnosticManager = (
NeuDiagnosticManager * ) rtDW . pyozqcgn5e ; diagnosticTree =
neu_diagnostic_manager_get_initial_tree ( diagnosticManager ) ; tmp_m =
nesl_initialize_simulator ( ( NeslSimulator * ) rtDW . cprcs12blm , &
modelParameters , diagnosticManager ) ; if ( tmp_m != 0 ) { tmp_p =
error_buffer_is_empty ( ssGetErrorStatus ( rtS ) ) ; if ( tmp_p ) { msg =
rtw_diagnostics_msg ( diagnosticTree ) ; ssSetErrorStatus ( rtS , msg ) ; } }
} void MdlOutputs ( int_T tid ) { NeslSimulationData * simulationData ;
NeuDiagnosticManager * diagnosticManager ; NeuDiagnosticTree * diagnosticTree
; char * msg ; real_T tmp_p [ 16 ] ; real_T time ; int32_T tmp_i ; int_T
tmp_e [ 5 ] ; boolean_T tmp ; rtB . fsgcwkxv0t [ 0 ] = rtB . axk21xke2l ; rtB
. fsgcwkxv0t [ 1 ] = 0.0 ; rtB . fsgcwkxv0t [ 2 ] = 0.0 ; if (
ssIsMajorTimeStep ( rtS ) ) { rtDW . k40gehsdny [ 0 ] = ! ( rtB . fsgcwkxv0t
[ 0 ] == rtDW . k40gehsdny [ 1 ] ) ; rtDW . k40gehsdny [ 1 ] = rtB .
fsgcwkxv0t [ 0 ] ; } rtB . fsgcwkxv0t [ 0 ] = rtDW . k40gehsdny [ 1 ] ; rtB .
fsgcwkxv0t [ 3 ] = rtDW . k40gehsdny [ 0 ] ; rtB . p0rdu0sokj [ 0 ] = rtB .
c4il5yindt ; rtB . p0rdu0sokj [ 1 ] = 0.0 ; rtB . p0rdu0sokj [ 2 ] = 0.0 ; if
( ssIsMajorTimeStep ( rtS ) ) { rtDW . kolnwf1ve2 [ 0 ] = ! ( rtB .
p0rdu0sokj [ 0 ] == rtDW . kolnwf1ve2 [ 1 ] ) ; rtDW . kolnwf1ve2 [ 1 ] = rtB
. p0rdu0sokj [ 0 ] ; } rtB . p0rdu0sokj [ 0 ] = rtDW . kolnwf1ve2 [ 1 ] ; rtB
. p0rdu0sokj [ 3 ] = rtDW . kolnwf1ve2 [ 0 ] ; rtB . j0hnrtmcm5 [ 0 ] = rtB .
a2zcetliah ; rtB . j0hnrtmcm5 [ 1 ] = 0.0 ; rtB . j0hnrtmcm5 [ 2 ] = 0.0 ; if
( ssIsMajorTimeStep ( rtS ) ) { rtDW . nhbk55zy0w [ 0 ] = ! ( rtB .
j0hnrtmcm5 [ 0 ] == rtDW . nhbk55zy0w [ 1 ] ) ; rtDW . nhbk55zy0w [ 1 ] = rtB
. j0hnrtmcm5 [ 0 ] ; } rtB . j0hnrtmcm5 [ 0 ] = rtDW . nhbk55zy0w [ 1 ] ; rtB
. j0hnrtmcm5 [ 3 ] = rtDW . nhbk55zy0w [ 0 ] ; rtB . grqe23nqie [ 0 ] = rtB .
lghtyz5ywp ; rtB . grqe23nqie [ 1 ] = 0.0 ; rtB . grqe23nqie [ 2 ] = 0.0 ; if
( ssIsMajorTimeStep ( rtS ) ) { rtDW . egcxye3s0y [ 0 ] = ! ( rtB .
grqe23nqie [ 0 ] == rtDW . egcxye3s0y [ 1 ] ) ; rtDW . egcxye3s0y [ 1 ] = rtB
. grqe23nqie [ 0 ] ; } rtB . grqe23nqie [ 0 ] = rtDW . egcxye3s0y [ 1 ] ; rtB
. grqe23nqie [ 3 ] = rtDW . egcxye3s0y [ 0 ] ; simulationData = (
NeslSimulationData * ) rtDW . cuvqd4ac0y ; time = ssGetT ( rtS ) ;
simulationData -> mData -> mTime . mN = 1 ; simulationData -> mData -> mTime
. mX = & time ; simulationData -> mData -> mContStates . mN = 0 ;
simulationData -> mData -> mContStates . mX = NULL ; simulationData -> mData
-> mDiscStates . mN = 0 ; simulationData -> mData -> mDiscStates . mX = &
rtDW . b4sk5zre3g ; simulationData -> mData -> mModeVector . mN = 0 ;
simulationData -> mData -> mModeVector . mX = & rtDW . i545gev3qr ; tmp = (
ssIsMajorTimeStep ( rtS ) && ssGetRTWSolverInfo ( rtS ) -> foundContZcEvents
) ; simulationData -> mData -> mFoundZcEvents = tmp ; simulationData -> mData
-> mIsMajorTimeStep = ssIsMajorTimeStep ( rtS ) ; tmp = ( ssGetMdlInfoPtr (
rtS ) -> mdlFlags . solverAssertCheck == 1U ) ; simulationData -> mData ->
mIsSolverAssertCheck = tmp ; tmp = ssIsSolverCheckingCIC ( rtS ) ;
simulationData -> mData -> mIsSolverCheckingCIC = tmp ; simulationData ->
mData -> mIsComputingJacobian = false ; simulationData -> mData ->
mIsEvaluatingF0 = false ; tmp = ssIsSolverRequestingReset ( rtS ) ;
simulationData -> mData -> mIsSolverRequestingReset = tmp ; simulationData ->
mData -> mIsOkayToUpdateMode = ssIsMajorTimeStep ( rtS ) ; tmp_e [ 0 ] = 0 ;
tmp_p [ 0 ] = rtB . fsgcwkxv0t [ 0 ] ; tmp_p [ 1 ] = rtB . fsgcwkxv0t [ 1 ] ;
tmp_p [ 2 ] = rtB . fsgcwkxv0t [ 2 ] ; tmp_p [ 3 ] = rtB . fsgcwkxv0t [ 3 ] ;
tmp_e [ 1 ] = 4 ; tmp_p [ 4 ] = rtB . p0rdu0sokj [ 0 ] ; tmp_p [ 5 ] = rtB .
p0rdu0sokj [ 1 ] ; tmp_p [ 6 ] = rtB . p0rdu0sokj [ 2 ] ; tmp_p [ 7 ] = rtB .
p0rdu0sokj [ 3 ] ; tmp_e [ 2 ] = 8 ; tmp_p [ 8 ] = rtB . j0hnrtmcm5 [ 0 ] ;
tmp_p [ 9 ] = rtB . j0hnrtmcm5 [ 1 ] ; tmp_p [ 10 ] = rtB . j0hnrtmcm5 [ 2 ]
; tmp_p [ 11 ] = rtB . j0hnrtmcm5 [ 3 ] ; tmp_e [ 3 ] = 12 ; tmp_p [ 12 ] =
rtB . grqe23nqie [ 0 ] ; tmp_p [ 13 ] = rtB . grqe23nqie [ 1 ] ; tmp_p [ 14 ]
= rtB . grqe23nqie [ 2 ] ; tmp_p [ 15 ] = rtB . grqe23nqie [ 3 ] ; tmp_e [ 4
] = 16 ; simulationData -> mData -> mInputValues . mN = 16 ; simulationData
-> mData -> mInputValues . mX = & tmp_p [ 0 ] ; simulationData -> mData ->
mInputOffsets . mN = 5 ; simulationData -> mData -> mInputOffsets . mX = &
tmp_e [ 0 ] ; simulationData -> mData -> mOutputs . mN = 0 ; simulationData
-> mData -> mOutputs . mX = NULL ; simulationData -> mData -> mSampleHits .
mN = 0 ; simulationData -> mData -> mSampleHits . mX = NULL ; simulationData
-> mData -> mIsFundamentalSampleHit = false ; simulationData -> mData ->
mTolerances . mN = 0 ; simulationData -> mData -> mTolerances . mX = NULL ;
simulationData -> mData -> mCstateHasChanged = false ; diagnosticManager = (
NeuDiagnosticManager * ) rtDW . pyozqcgn5e ; diagnosticTree =
neu_diagnostic_manager_get_initial_tree ( diagnosticManager ) ; tmp_i =
ne_simulator_method ( ( NeslSimulator * ) rtDW . cprcs12blm ,
NESL_SIM_OUTPUTS , simulationData , diagnosticManager ) ; if ( tmp_i != 0 ) {
tmp = error_buffer_is_empty ( ssGetErrorStatus ( rtS ) ) ; if ( tmp ) { msg =
rtw_diagnostics_msg ( diagnosticTree ) ; ssSetErrorStatus ( rtS , msg ) ; } }
if ( ssIsMajorTimeStep ( rtS ) && simulationData -> mData ->
mCstateHasChanged ) { ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; }
UNUSED_PARAMETER ( tid ) ; } void MdlOutputsTID1 ( int_T tid ) { rtB .
c4il5yindt = rtP . SliderGain_gain * rtP . Constant_Value * rtP . Gain_Gain ;
rtB . axk21xke2l = rtP . SliderGain1_gain * rtP . Constant1_Value * rtP .
Gain1_Gain ; rtB . a2zcetliah = rtP . SliderGain2_gain * rtP .
Constant2_Value * rtP . Gain2_Gain ; rtB . lghtyz5ywp = rtP .
SliderGain3_gain * rtP . Constant3_Value * rtP . Gain3_Gain ;
UNUSED_PARAMETER ( tid ) ; } void MdlUpdate ( int_T tid ) {
NeslSimulationData * simulationData ; NeuDiagnosticManager *
diagnosticManager ; NeuDiagnosticTree * diagnosticTree ; char * msg ; real_T
tmp_p [ 16 ] ; real_T time ; int32_T tmp_i ; int_T tmp_e [ 5 ] ; boolean_T
tmp ; simulationData = ( NeslSimulationData * ) rtDW . cuvqd4ac0y ; time =
ssGetT ( rtS ) ; simulationData -> mData -> mTime . mN = 1 ; simulationData
-> mData -> mTime . mX = & time ; simulationData -> mData -> mContStates . mN
= 0 ; simulationData -> mData -> mContStates . mX = NULL ; simulationData ->
mData -> mDiscStates . mN = 0 ; simulationData -> mData -> mDiscStates . mX =
& rtDW . b4sk5zre3g ; simulationData -> mData -> mModeVector . mN = 0 ;
simulationData -> mData -> mModeVector . mX = & rtDW . i545gev3qr ; tmp = (
ssIsMajorTimeStep ( rtS ) && ssGetRTWSolverInfo ( rtS ) -> foundContZcEvents
) ; simulationData -> mData -> mFoundZcEvents = tmp ; simulationData -> mData
-> mIsMajorTimeStep = ssIsMajorTimeStep ( rtS ) ; tmp = ( ssGetMdlInfoPtr (
rtS ) -> mdlFlags . solverAssertCheck == 1U ) ; simulationData -> mData ->
mIsSolverAssertCheck = tmp ; tmp = ssIsSolverCheckingCIC ( rtS ) ;
simulationData -> mData -> mIsSolverCheckingCIC = tmp ; simulationData ->
mData -> mIsComputingJacobian = false ; simulationData -> mData ->
mIsEvaluatingF0 = false ; tmp = ssIsSolverRequestingReset ( rtS ) ;
simulationData -> mData -> mIsSolverRequestingReset = tmp ; simulationData ->
mData -> mIsOkayToUpdateMode = ssIsMajorTimeStep ( rtS ) ; tmp_e [ 0 ] = 0 ;
tmp_p [ 0 ] = rtB . fsgcwkxv0t [ 0 ] ; tmp_p [ 1 ] = rtB . fsgcwkxv0t [ 1 ] ;
tmp_p [ 2 ] = rtB . fsgcwkxv0t [ 2 ] ; tmp_p [ 3 ] = rtB . fsgcwkxv0t [ 3 ] ;
tmp_e [ 1 ] = 4 ; tmp_p [ 4 ] = rtB . p0rdu0sokj [ 0 ] ; tmp_p [ 5 ] = rtB .
p0rdu0sokj [ 1 ] ; tmp_p [ 6 ] = rtB . p0rdu0sokj [ 2 ] ; tmp_p [ 7 ] = rtB .
p0rdu0sokj [ 3 ] ; tmp_e [ 2 ] = 8 ; tmp_p [ 8 ] = rtB . j0hnrtmcm5 [ 0 ] ;
tmp_p [ 9 ] = rtB . j0hnrtmcm5 [ 1 ] ; tmp_p [ 10 ] = rtB . j0hnrtmcm5 [ 2 ]
; tmp_p [ 11 ] = rtB . j0hnrtmcm5 [ 3 ] ; tmp_e [ 3 ] = 12 ; tmp_p [ 12 ] =
rtB . grqe23nqie [ 0 ] ; tmp_p [ 13 ] = rtB . grqe23nqie [ 1 ] ; tmp_p [ 14 ]
= rtB . grqe23nqie [ 2 ] ; tmp_p [ 15 ] = rtB . grqe23nqie [ 3 ] ; tmp_e [ 4
] = 16 ; simulationData -> mData -> mInputValues . mN = 16 ; simulationData
-> mData -> mInputValues . mX = & tmp_p [ 0 ] ; simulationData -> mData ->
mInputOffsets . mN = 5 ; simulationData -> mData -> mInputOffsets . mX = &
tmp_e [ 0 ] ; diagnosticManager = ( NeuDiagnosticManager * ) rtDW .
pyozqcgn5e ; diagnosticTree = neu_diagnostic_manager_get_initial_tree (
diagnosticManager ) ; tmp_i = ne_simulator_method ( ( NeslSimulator * ) rtDW
. cprcs12blm , NESL_SIM_UPDATE , simulationData , diagnosticManager ) ; if (
tmp_i != 0 ) { tmp = error_buffer_is_empty ( ssGetErrorStatus ( rtS ) ) ; if
( tmp ) { msg = rtw_diagnostics_msg ( diagnosticTree ) ; ssSetErrorStatus (
rtS , msg ) ; } } UNUSED_PARAMETER ( tid ) ; } void MdlUpdateTID1 ( int_T tid
) { UNUSED_PARAMETER ( tid ) ; } void MdlTerminate ( void ) {
neu_destroy_diagnostic_manager ( ( NeuDiagnosticManager * ) rtDW . pyozqcgn5e
) ; nesl_destroy_simulation_data ( ( NeslSimulationData * ) rtDW . cuvqd4ac0y
) ; nesl_erase_simulator ( "ROBOT4/Solver Configuration_1" ) ;
nesl_destroy_registry ( ) ; } static void mr_ROBOT4_cacheDataAsMxArray (
mxArray * destArray , mwIndex i , int j , const void * srcData , size_t
numBytes ) ; static void mr_ROBOT4_cacheDataAsMxArray ( mxArray * destArray ,
mwIndex i , int j , const void * srcData , size_t numBytes ) { mxArray *
newArray = mxCreateUninitNumericMatrix ( ( size_t ) 1 , numBytes ,
mxUINT8_CLASS , mxREAL ) ; memcpy ( ( uint8_T * ) mxGetData ( newArray ) , (
const uint8_T * ) srcData , numBytes ) ; mxSetFieldByNumber ( destArray , i ,
j , newArray ) ; } static void mr_ROBOT4_restoreDataFromMxArray ( void *
destData , const mxArray * srcArray , mwIndex i , int j , size_t numBytes ) ;
static void mr_ROBOT4_restoreDataFromMxArray ( void * destData , const
mxArray * srcArray , mwIndex i , int j , size_t numBytes ) { memcpy ( (
uint8_T * ) destData , ( const uint8_T * ) mxGetData ( mxGetFieldByNumber (
srcArray , i , j ) ) , numBytes ) ; } static void
mr_ROBOT4_cacheBitFieldToMxArray ( mxArray * destArray , mwIndex i , int j ,
uint_T bitVal ) ; static void mr_ROBOT4_cacheBitFieldToMxArray ( mxArray *
destArray , mwIndex i , int j , uint_T bitVal ) { mxSetFieldByNumber (
destArray , i , j , mxCreateDoubleScalar ( ( double ) bitVal ) ) ; } static
uint_T mr_ROBOT4_extractBitFieldFromMxArray ( const mxArray * srcArray ,
mwIndex i , int j , uint_T numBits ) ; static uint_T
mr_ROBOT4_extractBitFieldFromMxArray ( const mxArray * srcArray , mwIndex i ,
int j , uint_T numBits ) { const uint_T varVal = ( uint_T ) mxGetScalar (
mxGetFieldByNumber ( srcArray , i , j ) ) ; return varVal & ( ( 1u << numBits
) - 1u ) ; } static void mr_ROBOT4_cacheDataToMxArrayWithOffset ( mxArray *
destArray , mwIndex i , int j , mwIndex offset , const void * srcData ,
size_t numBytes ) ; static void mr_ROBOT4_cacheDataToMxArrayWithOffset (
mxArray * destArray , mwIndex i , int j , mwIndex offset , const void *
srcData , size_t numBytes ) { uint8_T * varData = ( uint8_T * ) mxGetData (
mxGetFieldByNumber ( destArray , i , j ) ) ; memcpy ( ( uint8_T * ) & varData
[ offset * numBytes ] , ( const uint8_T * ) srcData , numBytes ) ; } static
void mr_ROBOT4_restoreDataFromMxArrayWithOffset ( void * destData , const
mxArray * srcArray , mwIndex i , int j , mwIndex offset , size_t numBytes ) ;
static void mr_ROBOT4_restoreDataFromMxArrayWithOffset ( void * destData ,
const mxArray * srcArray , mwIndex i , int j , mwIndex offset , size_t
numBytes ) { const uint8_T * varData = ( const uint8_T * ) mxGetData (
mxGetFieldByNumber ( srcArray , i , j ) ) ; memcpy ( ( uint8_T * ) destData ,
( const uint8_T * ) & varData [ offset * numBytes ] , numBytes ) ; } static
void mr_ROBOT4_cacheBitFieldToCellArrayWithOffset ( mxArray * destArray ,
mwIndex i , int j , mwIndex offset , uint_T fieldVal ) ; static void
mr_ROBOT4_cacheBitFieldToCellArrayWithOffset ( mxArray * destArray , mwIndex
i , int j , mwIndex offset , uint_T fieldVal ) { mxSetCell (
mxGetFieldByNumber ( destArray , i , j ) , offset , mxCreateDoubleScalar ( (
double ) fieldVal ) ) ; } static uint_T
mr_ROBOT4_extractBitFieldFromCellArrayWithOffset ( const mxArray * srcArray ,
mwIndex i , int j , mwIndex offset , uint_T numBits ) ; static uint_T
mr_ROBOT4_extractBitFieldFromCellArrayWithOffset ( const mxArray * srcArray ,
mwIndex i , int j , mwIndex offset , uint_T numBits ) { const uint_T fieldVal
= ( uint_T ) mxGetScalar ( mxGetCell ( mxGetFieldByNumber ( srcArray , i , j
) , offset ) ) ; return fieldVal & ( ( 1u << numBits ) - 1u ) ; } mxArray *
mr_ROBOT4_GetDWork ( ) { static const char * ssDWFieldNames [ 3 ] = { "rtB" ,
"rtDW" , "NULL_PrevZCX" , } ; mxArray * ssDW = mxCreateStructMatrix ( 1 , 1 ,
3 , ssDWFieldNames ) ; mr_ROBOT4_cacheDataAsMxArray ( ssDW , 0 , 0 , ( const
void * ) & ( rtB ) , sizeof ( rtB ) ) ; { static const char *
rtdwDataFieldNames [ 7 ] = { "rtDW.k40gehsdny" , "rtDW.kolnwf1ve2" ,
"rtDW.nhbk55zy0w" , "rtDW.egcxye3s0y" , "rtDW.b4sk5zre3g" , "rtDW.i545gev3qr"
, "rtDW.d3whuwnaay" , } ; mxArray * rtdwData = mxCreateStructMatrix ( 1 , 1 ,
7 , rtdwDataFieldNames ) ; mr_ROBOT4_cacheDataAsMxArray ( rtdwData , 0 , 0 ,
( const void * ) & ( rtDW . k40gehsdny ) , sizeof ( rtDW . k40gehsdny ) ) ;
mr_ROBOT4_cacheDataAsMxArray ( rtdwData , 0 , 1 , ( const void * ) & ( rtDW .
kolnwf1ve2 ) , sizeof ( rtDW . kolnwf1ve2 ) ) ; mr_ROBOT4_cacheDataAsMxArray
( rtdwData , 0 , 2 , ( const void * ) & ( rtDW . nhbk55zy0w ) , sizeof ( rtDW
. nhbk55zy0w ) ) ; mr_ROBOT4_cacheDataAsMxArray ( rtdwData , 0 , 3 , ( const
void * ) & ( rtDW . egcxye3s0y ) , sizeof ( rtDW . egcxye3s0y ) ) ;
mr_ROBOT4_cacheDataAsMxArray ( rtdwData , 0 , 4 , ( const void * ) & ( rtDW .
b4sk5zre3g ) , sizeof ( rtDW . b4sk5zre3g ) ) ; mr_ROBOT4_cacheDataAsMxArray
( rtdwData , 0 , 5 , ( const void * ) & ( rtDW . i545gev3qr ) , sizeof ( rtDW
. i545gev3qr ) ) ; mr_ROBOT4_cacheDataAsMxArray ( rtdwData , 0 , 6 , ( const
void * ) & ( rtDW . d3whuwnaay ) , sizeof ( rtDW . d3whuwnaay ) ) ;
mxSetFieldByNumber ( ssDW , 0 , 1 , rtdwData ) ; } return ssDW ; } void
mr_ROBOT4_SetDWork ( const mxArray * ssDW ) { ( void ) ssDW ;
mr_ROBOT4_restoreDataFromMxArray ( ( void * ) & ( rtB ) , ssDW , 0 , 0 ,
sizeof ( rtB ) ) ; { const mxArray * rtdwData = mxGetFieldByNumber ( ssDW , 0
, 1 ) ; mr_ROBOT4_restoreDataFromMxArray ( ( void * ) & ( rtDW . k40gehsdny )
, rtdwData , 0 , 0 , sizeof ( rtDW . k40gehsdny ) ) ;
mr_ROBOT4_restoreDataFromMxArray ( ( void * ) & ( rtDW . kolnwf1ve2 ) ,
rtdwData , 0 , 1 , sizeof ( rtDW . kolnwf1ve2 ) ) ;
mr_ROBOT4_restoreDataFromMxArray ( ( void * ) & ( rtDW . nhbk55zy0w ) ,
rtdwData , 0 , 2 , sizeof ( rtDW . nhbk55zy0w ) ) ;
mr_ROBOT4_restoreDataFromMxArray ( ( void * ) & ( rtDW . egcxye3s0y ) ,
rtdwData , 0 , 3 , sizeof ( rtDW . egcxye3s0y ) ) ;
mr_ROBOT4_restoreDataFromMxArray ( ( void * ) & ( rtDW . b4sk5zre3g ) ,
rtdwData , 0 , 4 , sizeof ( rtDW . b4sk5zre3g ) ) ;
mr_ROBOT4_restoreDataFromMxArray ( ( void * ) & ( rtDW . i545gev3qr ) ,
rtdwData , 0 , 5 , sizeof ( rtDW . i545gev3qr ) ) ;
mr_ROBOT4_restoreDataFromMxArray ( ( void * ) & ( rtDW . d3whuwnaay ) ,
rtdwData , 0 , 6 , sizeof ( rtDW . d3whuwnaay ) ) ; } } mxArray *
mr_ROBOT4_GetSimStateDisallowedBlocks ( ) { mxArray * data =
mxCreateCellMatrix ( 3 , 3 ) ; mwIndex subs [ 2 ] , offset ; { static const
char * blockType [ 3 ] = { "SimscapeSinkBlock" , "SimscapeExecutionBlock" ,
"SimscapeExecutionBlock" , } ; static const char * blockPath [ 3 ] = {
"ROBOT4/Solver Configuration/EVAL_KEY/SINK_1" ,
"ROBOT4/Solver Configuration/EVAL_KEY/STATE_1" ,
"ROBOT4/Solver Configuration/EVAL_KEY/STATE_1" , } ; static const int reason
[ 3 ] = { 0 , 0 , 5 , } ; for ( subs [ 0 ] = 0 ; subs [ 0 ] < 3 ; ++ ( subs [
0 ] ) ) { subs [ 1 ] = 0 ; offset = mxCalcSingleSubscript ( data , 2 , subs )
; mxSetCell ( data , offset , mxCreateString ( blockType [ subs [ 0 ] ] ) ) ;
subs [ 1 ] = 1 ; offset = mxCalcSingleSubscript ( data , 2 , subs ) ;
mxSetCell ( data , offset , mxCreateString ( blockPath [ subs [ 0 ] ] ) ) ;
subs [ 1 ] = 2 ; offset = mxCalcSingleSubscript ( data , 2 , subs ) ;
mxSetCell ( data , offset , mxCreateDoubleScalar ( ( double ) reason [ subs [
0 ] ] ) ) ; } } return data ; } void MdlInitializeSizes ( void ) {
ssSetNumContStates ( rtS , 0 ) ; ssSetNumY ( rtS , 0 ) ; ssSetNumU ( rtS , 0
) ; ssSetDirectFeedThrough ( rtS , 0 ) ; ssSetNumSampleTimes ( rtS , 1 ) ;
ssSetNumBlocks ( rtS , 57 ) ; ssSetNumBlockIO ( rtS , 8 ) ;
ssSetNumBlockParams ( rtS , 12 ) ; } void MdlInitializeSampleTimes ( void ) {
ssSetSampleTime ( rtS , 0 , 0.0 ) ; ssSetOffsetTime ( rtS , 0 , 0.0 ) ; }
void raccel_set_checksum ( ) { ssSetChecksumVal ( rtS , 0 , 30862523U ) ;
ssSetChecksumVal ( rtS , 1 , 2887169577U ) ; ssSetChecksumVal ( rtS , 2 ,
2888939878U ) ; ssSetChecksumVal ( rtS , 3 , 1544626987U ) ; }
#if defined(_MSC_VER)
#pragma optimize( "", off )
#endif
SimStruct * raccel_register_model ( ssExecutionInfo * executionInfo ) {
static struct _ssMdlInfo mdlInfo ; ( void ) memset ( ( char * ) rtS , 0 ,
sizeof ( SimStruct ) ) ; ( void ) memset ( ( char * ) & mdlInfo , 0 , sizeof
( struct _ssMdlInfo ) ) ; ssSetMdlInfoPtr ( rtS , & mdlInfo ) ;
ssSetExecutionInfo ( rtS , executionInfo ) ; { static time_T mdlPeriod [
NSAMPLE_TIMES ] ; static time_T mdlOffset [ NSAMPLE_TIMES ] ; static time_T
mdlTaskTimes [ NSAMPLE_TIMES ] ; static int_T mdlTsMap [ NSAMPLE_TIMES ] ;
static int_T mdlSampleHits [ NSAMPLE_TIMES ] ; static boolean_T
mdlTNextWasAdjustedPtr [ NSAMPLE_TIMES ] ; static int_T mdlPerTaskSampleHits
[ NSAMPLE_TIMES * NSAMPLE_TIMES ] ; static time_T mdlTimeOfNextSampleHit [
NSAMPLE_TIMES ] ; { int_T i ; for ( i = 0 ; i < NSAMPLE_TIMES ; i ++ ) {
mdlPeriod [ i ] = 0.0 ; mdlOffset [ i ] = 0.0 ; mdlTaskTimes [ i ] = 0.0 ;
mdlTsMap [ i ] = i ; mdlSampleHits [ i ] = 1 ; } } ssSetSampleTimePtr ( rtS ,
& mdlPeriod [ 0 ] ) ; ssSetOffsetTimePtr ( rtS , & mdlOffset [ 0 ] ) ;
ssSetSampleTimeTaskIDPtr ( rtS , & mdlTsMap [ 0 ] ) ; ssSetTPtr ( rtS , &
mdlTaskTimes [ 0 ] ) ; ssSetSampleHitPtr ( rtS , & mdlSampleHits [ 0 ] ) ;
ssSetTNextWasAdjustedPtr ( rtS , & mdlTNextWasAdjustedPtr [ 0 ] ) ;
ssSetPerTaskSampleHitsPtr ( rtS , & mdlPerTaskSampleHits [ 0 ] ) ;
ssSetTimeOfNextSampleHitPtr ( rtS , & mdlTimeOfNextSampleHit [ 0 ] ) ; }
ssSetSolverMode ( rtS , SOLVER_MODE_SINGLETASKING ) ; { ssSetBlockIO ( rtS ,
( ( void * ) & rtB ) ) ; ( void ) memset ( ( ( void * ) & rtB ) , 0 , sizeof
( B ) ) ; } { void * dwork = ( void * ) & rtDW ; ssSetRootDWork ( rtS , dwork
) ; ( void ) memset ( dwork , 0 , sizeof ( DW ) ) ; } { static
DataTypeTransInfo dtInfo ; ( void ) memset ( ( char_T * ) & dtInfo , 0 ,
sizeof ( dtInfo ) ) ; ssSetModelMappingInfo ( rtS , & dtInfo ) ; dtInfo .
numDataTypes = 20 ; dtInfo . dataTypeSizes = & rtDataTypeSizes [ 0 ] ; dtInfo
. dataTypeNames = & rtDataTypeNames [ 0 ] ; dtInfo . BTransTable = &
rtBTransTable ; dtInfo . PTransTable = & rtPTransTable ; dtInfo .
dataTypeInfoTable = rtDataTypeInfoTable ; } ROBOT4_InitializeDataMapInfo ( )
; ssSetIsRapidAcceleratorActive ( rtS , true ) ; ssSetRootSS ( rtS , rtS ) ;
ssSetVersion ( rtS , SIMSTRUCT_VERSION_LEVEL2 ) ; ssSetModelName ( rtS ,
"ROBOT4" ) ; ssSetPath ( rtS , "ROBOT4" ) ; ssSetTStart ( rtS , 0.0 ) ;
ssSetTFinal ( rtS , rtInf ) ; { static RTWLogInfo rt_DataLoggingInfo ;
rt_DataLoggingInfo . loggingInterval = ( NULL ) ; ssSetRTWLogInfo ( rtS , &
rt_DataLoggingInfo ) ; } { { static int_T rt_LoggedStateWidths [ ] = { 2 , 2
, 2 , 2 } ; static int_T rt_LoggedStateNumDimensions [ ] = { 1 , 1 , 1 , 1 }
; static int_T rt_LoggedStateDimensions [ ] = { 2 , 2 , 2 , 2 } ; static
boolean_T rt_LoggedStateIsVarDims [ ] = { 0 , 0 , 0 , 0 } ; static
BuiltInDTypeId rt_LoggedStateDataTypeIds [ ] = { SS_DOUBLE , SS_DOUBLE ,
SS_DOUBLE , SS_DOUBLE } ; static int_T rt_LoggedStateComplexSignals [ ] = { 0
, 0 , 0 , 0 } ; static RTWPreprocessingFcnPtr
rt_LoggingStatePreprocessingFcnPtrs [ ] = { ( NULL ) , ( NULL ) , ( NULL ) ,
( NULL ) } ; static const char_T * rt_LoggedStateLabels [ ] = { "Discrete" ,
"Discrete" , "Discrete" , "Discrete" } ; static const char_T *
rt_LoggedStateBlockNames [ ] = {
"ROBOT4/Solver\nConfiguration/EVAL_KEY/INPUT_2_1_1" ,
"ROBOT4/Solver\nConfiguration/EVAL_KEY/INPUT_1_1_1" ,
"ROBOT4/Solver\nConfiguration/EVAL_KEY/INPUT_3_1_1" ,
"ROBOT4/Solver\nConfiguration/EVAL_KEY/INPUT_4_1_1" } ; static const char_T *
rt_LoggedStateNames [ ] = { "Discrete" , "Discrete" , "Discrete" , "Discrete"
} ; static boolean_T rt_LoggedStateCrossMdlRef [ ] = { 0 , 0 , 0 , 0 } ;
static RTWLogDataTypeConvert rt_RTWLogDataTypeConvert [ ] = { { 0 , SS_DOUBLE
, SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 ,
0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 ,
0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } } ; static
int_T rt_LoggedStateIdxList [ ] = { 0 , 1 , 2 , 3 } ; static RTWLogSignalInfo
rt_LoggedStateSignalInfo = { 4 , rt_LoggedStateWidths ,
rt_LoggedStateNumDimensions , rt_LoggedStateDimensions ,
rt_LoggedStateIsVarDims , ( NULL ) , ( NULL ) , rt_LoggedStateDataTypeIds ,
rt_LoggedStateComplexSignals , ( NULL ) , rt_LoggingStatePreprocessingFcnPtrs
, { rt_LoggedStateLabels } , ( NULL ) , ( NULL ) , ( NULL ) , {
rt_LoggedStateBlockNames } , { rt_LoggedStateNames } ,
rt_LoggedStateCrossMdlRef , rt_RTWLogDataTypeConvert , rt_LoggedStateIdxList
} ; static void * rt_LoggedStateSignalPtrs [ 4 ] ; rtliSetLogXSignalPtrs (
ssGetRTWLogInfo ( rtS ) , ( LogSignalPtrsType ) rt_LoggedStateSignalPtrs ) ;
rtliSetLogXSignalInfo ( ssGetRTWLogInfo ( rtS ) , & rt_LoggedStateSignalInfo
) ; rt_LoggedStateSignalPtrs [ 0 ] = ( void * ) rtDW . k40gehsdny ;
rt_LoggedStateSignalPtrs [ 1 ] = ( void * ) rtDW . kolnwf1ve2 ;
rt_LoggedStateSignalPtrs [ 2 ] = ( void * ) rtDW . nhbk55zy0w ;
rt_LoggedStateSignalPtrs [ 3 ] = ( void * ) rtDW . egcxye3s0y ; } rtliSetLogT
( ssGetRTWLogInfo ( rtS ) , "tout" ) ; rtliSetLogX ( ssGetRTWLogInfo ( rtS )
, "" ) ; rtliSetLogXFinal ( ssGetRTWLogInfo ( rtS ) , "xFinal" ) ;
rtliSetLogVarNameModifier ( ssGetRTWLogInfo ( rtS ) , "none" ) ;
rtliSetLogFormat ( ssGetRTWLogInfo ( rtS ) , 4 ) ; rtliSetLogMaxRows (
ssGetRTWLogInfo ( rtS ) , 0 ) ; rtliSetLogDecimation ( ssGetRTWLogInfo ( rtS
) , 1 ) ; rtliSetLogY ( ssGetRTWLogInfo ( rtS ) , "" ) ;
rtliSetLogYSignalInfo ( ssGetRTWLogInfo ( rtS ) , ( NULL ) ) ;
rtliSetLogYSignalPtrs ( ssGetRTWLogInfo ( rtS ) , ( NULL ) ) ; } { static
ssSolverInfo slvrInfo ; ssSetStepSize ( rtS , 0.2 ) ; ssSetMinStepSize ( rtS
, 0.0 ) ; ssSetMaxNumMinSteps ( rtS , - 1 ) ; ssSetMinStepViolatedError ( rtS
, 0 ) ; ssSetMaxStepSize ( rtS , 0.2 ) ; ssSetSolverMaxOrder ( rtS , - 1 ) ;
ssSetSolverRefineFactor ( rtS , 1 ) ; ssSetOutputTimes ( rtS , ( NULL ) ) ;
ssSetNumOutputTimes ( rtS , 0 ) ; ssSetOutputTimesOnly ( rtS , 0 ) ;
ssSetOutputTimesIndex ( rtS , 0 ) ; ssSetZCCacheNeedsReset ( rtS , 0 ) ;
ssSetDerivCacheNeedsReset ( rtS , 0 ) ; ssSetNumNonContDerivSigInfos ( rtS ,
0 ) ; ssSetNonContDerivSigInfos ( rtS , ( NULL ) ) ; ssSetSolverInfo ( rtS ,
& slvrInfo ) ; ssSetSolverName ( rtS , "VariableStepDiscrete" ) ;
ssSetVariableStepSolver ( rtS , 1 ) ; ssSetSolverConsistencyChecking ( rtS ,
0 ) ; ssSetSolverAdaptiveZcDetection ( rtS , 0 ) ;
ssSetSolverRobustResetMethod ( rtS , 0 ) ; ssSetSolverStateProjection ( rtS ,
0 ) ; ssSetSolverMassMatrixType ( rtS , ( ssMatrixType ) 0 ) ;
ssSetSolverMassMatrixNzMax ( rtS , 0 ) ; ssSetModelOutputs ( rtS , MdlOutputs
) ; ssSetModelLogData ( rtS , rt_UpdateTXYLogVars ) ;
ssSetModelLogDataIfInInterval ( rtS , rt_UpdateTXXFYLogVars ) ;
ssSetModelUpdate ( rtS , MdlUpdate ) ; ssSetTNextTid ( rtS , INT_MIN ) ;
ssSetTNext ( rtS , rtMinusInf ) ; ssSetSolverNeedsReset ( rtS ) ;
ssSetNumNonsampledZCs ( rtS , 0 ) ; } ssSetChecksumVal ( rtS , 0 , 30862523U
) ; ssSetChecksumVal ( rtS , 1 , 2887169577U ) ; ssSetChecksumVal ( rtS , 2 ,
2888939878U ) ; ssSetChecksumVal ( rtS , 3 , 1544626987U ) ; { static const
sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE ; static RTWExtModeInfo
rt_ExtModeInfo ; static const sysRanDType * systemRan [ 1 ] ;
gblRTWExtModeInfo = & rt_ExtModeInfo ; ssSetRTWExtModeInfo ( rtS , &
rt_ExtModeInfo ) ; rteiSetSubSystemActiveVectorAddresses ( & rt_ExtModeInfo ,
systemRan ) ; systemRan [ 0 ] = & rtAlwaysEnabled ;
rteiSetModelMappingInfoPtr ( ssGetRTWExtModeInfo ( rtS ) , &
ssGetModelMappingInfo ( rtS ) ) ; rteiSetChecksumsPtr ( ssGetRTWExtModeInfo (
rtS ) , ssGetChecksums ( rtS ) ) ; rteiSetTPtr ( ssGetRTWExtModeInfo ( rtS )
, ssGetTPtr ( rtS ) ) ; } slsaDisallowedBlocksForSimTargetOP ( rtS ,
mr_ROBOT4_GetSimStateDisallowedBlocks ) ; slsaGetWorkFcnForSimTargetOP ( rtS
, mr_ROBOT4_GetDWork ) ; slsaSetWorkFcnForSimTargetOP ( rtS ,
mr_ROBOT4_SetDWork ) ; rt_RapidReadMatFileAndUpdateParams ( rtS ) ; if (
ssGetErrorStatus ( rtS ) ) { return rtS ; } return rtS ; }
#if defined(_MSC_VER)
#pragma optimize( "", on )
#endif
const int_T gblParameterTuningTid = 1 ; void MdlOutputsParameterSampleTime (
int_T tid ) { MdlOutputsTID1 ( tid ) ; }
