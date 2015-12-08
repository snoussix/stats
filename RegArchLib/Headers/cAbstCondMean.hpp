#ifndef _CABSTCONDMEAN_
#define _CABSTCONDMEAN_
#include <vector>
#include "cRegArchData.hpp" 
#include <gsl/gsl_math.h>

class CAbstCondMean {
cGSLVector mParams;
 CAbstCondMean(cGSLVector mParams);
virtual double mComputeMean(CRegArchData mData, int t)=0;
virtual cGSLVector mComputeGrad(CRegArchData mData, int t)=0;
};



#endif
