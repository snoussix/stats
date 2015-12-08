#ifndef _CCONDMEAN_
#define _CCONDMEAN_
#include <vector>
#include "cAbstCondMean.hpp"
#include "cRegArchData.hpp"
#include "StdAfxVectorAndMatrix.h"
using namespace VectorAndMatrixNameSpace;



class CCondMean {
std::vector<CAbstCondMean *> mMean;
public:
 CCondMean(std::vector<CAbstCondMean *> mMean);
double mComputeMean(CRegArchData mdata, int t);
cGSLVector mComputeGrad(CRegArchData mdata, int t);




};
#endif
