#ifndef _CCONSTM_
#define _CCONSTM_
#include "cAbstCondMean.hpp"
#include <gsl/gsl_math.h>


class CConstM: public CAbstCondMean{
double constante;
CAbsCondMean(double constante);
virtual double mComputeMean(CRegArchData mData, int t);
virtual cGSLVector mComputeGrad(CRegArchData mData, int t);

};

#endif
