#ifndef _CABSTCONDMEAN_
#define _CABSTCONDMEAN_

#include "cRegArchData.hpp" 
#include "StdAfxVectorAndMatrix.h"
using namespace VectorAndMatrixNameSpace;


class CAbstCondMean {
    
cGSLVector mParams;
 CAbstCondMean(cGSLVector mParams);
virtual double mComputeMean(CRegArchData mData, int t)=0;
virtual cGSLVector mComputeGrad(CRegArchData mData, int t)=0;
};



#endif
