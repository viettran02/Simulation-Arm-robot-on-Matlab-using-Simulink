#ifndef RTW_HEADER_ROBOT4_h_
#define RTW_HEADER_ROBOT4_h_
#include <stddef.h>
#include <string.h>
#include "rtw_modelmap_simtarget.h"
#ifndef ROBOT4_COMMON_INCLUDES_
#define ROBOT4_COMMON_INCLUDES_
#include <stdlib.h>
#include "rtwtypes.h"
#include "sigstream_rtw.h"
#include "simtarget/slSimTgtSigstreamRTW.h"
#include "simtarget/slSimTgtSlioCoreRTW.h"
#include "simtarget/slSimTgtSlioClientsRTW.h"
#include "simtarget/slSimTgtSlioSdiRTW.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "raccel.h"
#include "slsv_diagnostic_codegen_c_api.h"
#include "rt_logging_simtarget.h"
#include "dt_info.h"
#include "ext_work.h"
#include "nesl_rtw.h"
#include "ROBOT4_a2b15696_1_gateway.h"
#endif
#include "ROBOT4_types.h"
#include "multiword_types.h"
#include "rt_defines.h"
#include "rtGetInf.h"
#include "rt_nonfinite.h"
#define MODEL_NAME ROBOT4
#define NSAMPLE_TIMES (2) 
#define NINPUTS (0)       
#define NOUTPUTS (0)     
#define NBLOCKIO (8) 
#define NUM_ZC_EVENTS (0) 
#ifndef NCSTATES
#define NCSTATES (0)   
#elif NCSTATES != 0
#error Invalid specification of NCSTATES defined in compiler command
#endif
#ifndef rtmGetDataMapInfo
#define rtmGetDataMapInfo(rtm) (*rt_dataMapInfoPtr)
#endif
#ifndef rtmSetDataMapInfo
#define rtmSetDataMapInfo(rtm, val) (rt_dataMapInfoPtr = &val)
#endif
#ifndef IN_RACCEL_MAIN
#endif
typedef struct { real_T fsgcwkxv0t [ 4 ] ; real_T p0rdu0sokj [ 4 ] ; real_T
j0hnrtmcm5 [ 4 ] ; real_T grqe23nqie [ 4 ] ; real_T c4il5yindt ; real_T
axk21xke2l ; real_T a2zcetliah ; real_T lghtyz5ywp ; } B ; typedef struct {
real_T k40gehsdny [ 2 ] ; real_T kolnwf1ve2 [ 2 ] ; real_T nhbk55zy0w [ 2 ] ;
real_T egcxye3s0y [ 2 ] ; real_T b4sk5zre3g ; void * oznuzhcmyp ; void *
julbp2wfok ; void * a41edtezl2 ; void * cprcs12blm ; void * cuvqd4ac0y ; void
* pyozqcgn5e ; void * jlkd40o1yu ; void * bvvoplpurz ; int_T i545gev3qr ;
boolean_T d3whuwnaay ; } DW ; typedef struct { rtwCAPI_ModelMappingInfo mmi ;
} DataMapInfo ; struct P_ { real_T SliderGain_gain ; real_T SliderGain1_gain
; real_T SliderGain2_gain ; real_T SliderGain3_gain ; real_T Constant_Value ;
real_T Gain_Gain ; real_T Constant1_Value ; real_T Gain1_Gain ; real_T
Constant2_Value ; real_T Gain2_Gain ; real_T Constant3_Value ; real_T
Gain3_Gain ; } ; extern const char * RT_MEMORY_ALLOCATION_ERROR ; extern B
rtB ; extern DW rtDW ; extern P rtP ; extern mxArray * mr_ROBOT4_GetDWork ( )
; extern void mr_ROBOT4_SetDWork ( const mxArray * ssDW ) ; extern mxArray *
mr_ROBOT4_GetSimStateDisallowedBlocks ( ) ; extern const
rtwCAPI_ModelMappingStaticInfo * ROBOT4_GetCAPIStaticMap ( void ) ; extern
SimStruct * const rtS ; extern const int_T gblNumToFiles ; extern const int_T
gblNumFrFiles ; extern const int_T gblNumFrWksBlocks ; extern rtInportTUtable
* gblInportTUtables ; extern const char * gblInportFileName ; extern const
int_T gblNumRootInportBlks ; extern const int_T gblNumModelInputs ; extern
const int_T gblInportDataTypeIdx [ ] ; extern const int_T gblInportDims [ ] ;
extern const int_T gblInportComplex [ ] ; extern const int_T
gblInportInterpoFlag [ ] ; extern const int_T gblInportContinuous [ ] ;
extern const int_T gblParameterTuningTid ; extern DataMapInfo *
rt_dataMapInfoPtr ; extern rtwCAPI_ModelMappingInfo * rt_modelMapInfoPtr ;
void MdlOutputs ( int_T tid ) ; void MdlOutputsParameterSampleTime ( int_T
tid ) ; void MdlUpdate ( int_T tid ) ; void MdlTerminate ( void ) ; void
MdlInitializeSizes ( void ) ; void MdlInitializeSampleTimes ( void ) ;
SimStruct * raccel_register_model ( ssExecutionInfo * executionInfo ) ;
#endif
