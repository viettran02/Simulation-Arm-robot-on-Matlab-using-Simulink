#include "rtw_capi.h"
#ifdef HOST_CAPI_BUILD
#include "ROBOT4_capi_host.h"
#define sizeof(s) ((size_t)(0xFFFF))
#undef rt_offsetof
#define rt_offsetof(s,el) ((uint16_T)(0xFFFF))
#define TARGET_CONST
#define TARGET_STRING(s) (s)
#else
#include "builtin_typeid_types.h"
#include "ROBOT4.h"
#include "ROBOT4_capi.h"
#include "ROBOT4_private.h"
#ifdef LIGHT_WEIGHT_CAPI
#define TARGET_CONST
#define TARGET_STRING(s)               ((NULL))
#else
#define TARGET_CONST                   const
#define TARGET_STRING(s)               (s)
#endif
#endif
static const rtwCAPI_Signals rtBlockSignals [ ] = { { 0 , 0 , TARGET_STRING (
"ROBOT4/Gain" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 1 , 0 ,
TARGET_STRING ( "ROBOT4/Gain1" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 }
, { 2 , 0 , TARGET_STRING ( "ROBOT4/Gain2" ) , TARGET_STRING ( "" ) , 0 , 0 ,
0 , 0 , 0 } , { 3 , 0 , TARGET_STRING ( "ROBOT4/Gain3" ) , TARGET_STRING ( ""
) , 0 , 0 , 0 , 0 , 0 } , { 4 , 0 , TARGET_STRING (
"ROBOT4/Solver Configuration/EVAL_KEY/INPUT_1_1_1" ) , TARGET_STRING ( "" ) ,
0 , 0 , 1 , 0 , 1 } , { 5 , 0 , TARGET_STRING (
"ROBOT4/Solver Configuration/EVAL_KEY/INPUT_2_1_1" ) , TARGET_STRING ( "" ) ,
0 , 0 , 1 , 0 , 1 } , { 6 , 0 , TARGET_STRING (
"ROBOT4/Solver Configuration/EVAL_KEY/INPUT_3_1_1" ) , TARGET_STRING ( "" ) ,
0 , 0 , 1 , 0 , 1 } , { 7 , 0 , TARGET_STRING (
"ROBOT4/Solver Configuration/EVAL_KEY/INPUT_4_1_1" ) , TARGET_STRING ( "" ) ,
0 , 0 , 1 , 0 , 1 } , { 0 , 0 , ( NULL ) , ( NULL ) , 0 , 0 , 0 , 0 , 0 } } ;
static const rtwCAPI_BlockParameters rtBlockParameters [ ] = { { 8 ,
TARGET_STRING ( "ROBOT4/Slider Gain" ) , TARGET_STRING ( "gain" ) , 0 , 0 , 0
} , { 9 , TARGET_STRING ( "ROBOT4/Slider Gain1" ) , TARGET_STRING ( "gain" )
, 0 , 0 , 0 } , { 10 , TARGET_STRING ( "ROBOT4/Slider Gain2" ) ,
TARGET_STRING ( "gain" ) , 0 , 0 , 0 } , { 11 , TARGET_STRING (
"ROBOT4/Slider Gain3" ) , TARGET_STRING ( "gain" ) , 0 , 0 , 0 } , { 12 ,
TARGET_STRING ( "ROBOT4/Constant" ) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 }
, { 13 , TARGET_STRING ( "ROBOT4/Constant1" ) , TARGET_STRING ( "Value" ) , 0
, 0 , 0 } , { 14 , TARGET_STRING ( "ROBOT4/Constant2" ) , TARGET_STRING (
"Value" ) , 0 , 0 , 0 } , { 15 , TARGET_STRING ( "ROBOT4/Constant3" ) ,
TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 16 , TARGET_STRING (
"ROBOT4/Gain" ) , TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 17 ,
TARGET_STRING ( "ROBOT4/Gain1" ) , TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , {
18 , TARGET_STRING ( "ROBOT4/Gain2" ) , TARGET_STRING ( "Gain" ) , 0 , 0 , 0
} , { 19 , TARGET_STRING ( "ROBOT4/Gain3" ) , TARGET_STRING ( "Gain" ) , 0 ,
0 , 0 } , { 0 , ( NULL ) , ( NULL ) , 0 , 0 , 0 } } ; static int_T
rt_LoggedStateIdxList [ ] = { - 1 } ; static const rtwCAPI_Signals
rtRootInputs [ ] = { { 0 , 0 , ( NULL ) , ( NULL ) , 0 , 0 , 0 , 0 , 0 } } ;
static const rtwCAPI_Signals rtRootOutputs [ ] = { { 0 , 0 , ( NULL ) , (
NULL ) , 0 , 0 , 0 , 0 , 0 } } ; static const rtwCAPI_ModelParameters
rtModelParameters [ ] = { { 0 , ( NULL ) , 0 , 0 , 0 } } ;
#ifndef HOST_CAPI_BUILD
static void * rtDataAddrMap [ ] = { & rtB . c4il5yindt , & rtB . axk21xke2l ,
& rtB . a2zcetliah , & rtB . lghtyz5ywp , & rtB . p0rdu0sokj [ 0 ] , & rtB .
fsgcwkxv0t [ 0 ] , & rtB . j0hnrtmcm5 [ 0 ] , & rtB . grqe23nqie [ 0 ] , &
rtP . SliderGain_gain , & rtP . SliderGain1_gain , & rtP . SliderGain2_gain ,
& rtP . SliderGain3_gain , & rtP . Constant_Value , & rtP . Constant1_Value ,
& rtP . Constant2_Value , & rtP . Constant3_Value , & rtP . Gain_Gain , & rtP
. Gain1_Gain , & rtP . Gain2_Gain , & rtP . Gain3_Gain , } ; static int32_T *
rtVarDimsAddrMap [ ] = { ( NULL ) } ;
#endif
static TARGET_CONST rtwCAPI_DataTypeMap rtDataTypeMap [ ] = { { "double" ,
"real_T" , 0 , 0 , sizeof ( real_T ) , ( uint8_T ) SS_DOUBLE , 0 , 0 , 0 } }
;
#ifdef HOST_CAPI_BUILD
#undef sizeof
#endif
static TARGET_CONST rtwCAPI_ElementMap rtElementMap [ ] = { { ( NULL ) , 0 ,
0 , 0 , 0 } , } ; static const rtwCAPI_DimensionMap rtDimensionMap [ ] = { {
rtwCAPI_SCALAR , 0 , 2 , 0 } , { rtwCAPI_VECTOR , 2 , 2 , 0 } } ; static
const uint_T rtDimensionArray [ ] = { 1 , 1 , 4 , 1 } ; static const real_T
rtcapiStoredFloats [ ] = { 0.0 } ; static const rtwCAPI_FixPtMap rtFixPtMap [
] = { { ( NULL ) , ( NULL ) , rtwCAPI_FIX_RESERVED , 0 , 0 , ( boolean_T ) 0
} , } ; static const rtwCAPI_SampleTimeMap rtSampleTimeMap [ ] = { { ( NULL )
, ( NULL ) , 1 , 0 } , { ( const void * ) & rtcapiStoredFloats [ 0 ] , (
const void * ) & rtcapiStoredFloats [ 0 ] , ( int8_T ) 0 , ( uint8_T ) 0 } }
; static rtwCAPI_ModelMappingStaticInfo mmiStatic = { { rtBlockSignals , 8 ,
rtRootInputs , 0 , rtRootOutputs , 0 } , { rtBlockParameters , 12 ,
rtModelParameters , 0 } , { ( NULL ) , 0 } , { rtDataTypeMap , rtDimensionMap
, rtFixPtMap , rtElementMap , rtSampleTimeMap , rtDimensionArray } , "float"
, { 30862523U , 2887169577U , 2888939878U , 1544626987U } , ( NULL ) , 0 , (
boolean_T ) 0 , rt_LoggedStateIdxList } ; const
rtwCAPI_ModelMappingStaticInfo * ROBOT4_GetCAPIStaticMap ( void ) { return &
mmiStatic ; }
#ifndef HOST_CAPI_BUILD
void ROBOT4_InitializeDataMapInfo ( void ) { rtwCAPI_SetVersion ( ( *
rt_dataMapInfoPtr ) . mmi , 1 ) ; rtwCAPI_SetStaticMap ( ( *
rt_dataMapInfoPtr ) . mmi , & mmiStatic ) ; rtwCAPI_SetLoggingStaticMap ( ( *
rt_dataMapInfoPtr ) . mmi , ( NULL ) ) ; rtwCAPI_SetDataAddressMap ( ( *
rt_dataMapInfoPtr ) . mmi , rtDataAddrMap ) ; rtwCAPI_SetVarDimsAddressMap (
( * rt_dataMapInfoPtr ) . mmi , rtVarDimsAddrMap ) ;
rtwCAPI_SetInstanceLoggingInfo ( ( * rt_dataMapInfoPtr ) . mmi , ( NULL ) ) ;
rtwCAPI_SetChildMMIArray ( ( * rt_dataMapInfoPtr ) . mmi , ( NULL ) ) ;
rtwCAPI_SetChildMMIArrayLen ( ( * rt_dataMapInfoPtr ) . mmi , 0 ) ; }
#else
#ifdef __cplusplus
extern "C" {
#endif
void ROBOT4_host_InitializeDataMapInfo ( ROBOT4_host_DataMapInfo_T * dataMap
, const char * path ) { rtwCAPI_SetVersion ( dataMap -> mmi , 1 ) ;
rtwCAPI_SetStaticMap ( dataMap -> mmi , & mmiStatic ) ;
rtwCAPI_SetDataAddressMap ( dataMap -> mmi , ( NULL ) ) ;
rtwCAPI_SetVarDimsAddressMap ( dataMap -> mmi , ( NULL ) ) ; rtwCAPI_SetPath
( dataMap -> mmi , path ) ; rtwCAPI_SetFullPath ( dataMap -> mmi , ( NULL ) )
; rtwCAPI_SetChildMMIArray ( dataMap -> mmi , ( NULL ) ) ;
rtwCAPI_SetChildMMIArrayLen ( dataMap -> mmi , 0 ) ; }
#ifdef __cplusplus
}
#endif
#endif
