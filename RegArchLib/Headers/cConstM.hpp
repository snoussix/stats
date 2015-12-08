#ifndef _CCONSTM_
#define _CCONSTM_
#include "cAbstCondMean.hpp"
#include "StdAfxVectorAndMatrix.h"
using namespace VectorAndMatrixNameSpace;

class CConstM: public CAbstCondMean{
double constante;
CConstM(double constante,cGSLVector mParams);
virtual double mComputeMean(CRegArchData mData, int t);
virtual cGSLVector mComputeGrad(CRegArchData mData, int t);

};

#endif
