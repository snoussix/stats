#ifndef _CCONDMEAN_
#define _CCONDMEAN_
#include <vector>
#include "cAbstCondMean.hpp"
#include "cRegArchData.hpp"
#include "StdAfxVectorAndMatrix.h"
using VectorAndMatrixNameSpace;



class CCondMean {
std::vector<CAbstCondMean *> mMean;
 CCondMean(std::vector<CAbstCondMean *> mMean,cGSLVector mParams);
double mComputeMean(CRegArchData mdata, int t);
cGSLVector mComputeGrad(CRegArchData mdata, int t);




};
#endif
