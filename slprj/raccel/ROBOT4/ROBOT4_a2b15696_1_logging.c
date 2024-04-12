#include <math.h>
#include <string.h>
#include "pm_std.h"
#include "sm_std.h"
#include "ne_std.h"
#include "ne_dae.h"
#include "sm_ssci_run_time_errors.h"
#include "sm_RuntimeDerivedValuesBundle.h"
#include "ROBOT4_a2b15696_1_geometries.h"
PmfMessageId ROBOT4_a2b15696_1_recordLog ( const RuntimeDerivedValuesBundle *
rtdv , const int * eqnEnableFlags , const double * state , const int *
modeVector , const double * input , const double * inputDot , const double *
inputDdot , double * logVector , double * errorResult , NeuDiagnosticManager
* neDiagMgr ) { const double * rtdvd = rtdv -> mDoubles . mValues ; const int
* rtdvi = rtdv -> mInts . mValues ; double xx [ 1 ] ; ( void ) rtdvd ; ( void
) rtdvi ; ( void ) eqnEnableFlags ; ( void ) modeVector ; ( void ) input ; (
void ) inputDot ; ( void ) neDiagMgr ; xx [ 0 ] = 57.29577951308232 ;
logVector [ 0 ] = xx [ 0 ] * state [ 0 ] ; logVector [ 1 ] = xx [ 0 ] * state
[ 1 ] ; logVector [ 2 ] = xx [ 0 ] * state [ 2 ] ; logVector [ 3 ] = xx [ 0 ]
* state [ 3 ] ; logVector [ 4 ] = xx [ 0 ] * state [ 4 ] ; logVector [ 5 ] =
xx [ 0 ] * state [ 5 ] ; logVector [ 6 ] = xx [ 0 ] * state [ 6 ] ; logVector
[ 7 ] = xx [ 0 ] * state [ 7 ] ; logVector [ 8 ] = xx [ 0 ] * inputDdot [ 1 ]
; logVector [ 9 ] = xx [ 0 ] * inputDdot [ 0 ] ; logVector [ 10 ] = xx [ 0 ]
* inputDdot [ 2 ] ; logVector [ 11 ] = xx [ 0 ] * inputDdot [ 3 ] ;
errorResult [ 0 ] = 0.0 ; return NULL ; }
