#ifndef _CAR_
#define _CAR_
#include "cAbstCondMean.hpp"
#include <gsl/gsl_math.h>


class CAr: public CAbstCondMean{
    CAr(cGSLVector mParams);
virtual double mComputeMean(CRegArchData mData, int t);
virtual cGSLVector mComputeGrad(CRegArchData mData, int t);
};

#endif
