#ifndef _CCONDMEAN_
#define _CCONDMEAN_
#include <vector>
#include "cGSLVector.h"
#include "cAbstCondMean.hpp"
#include "cRegArchData.hpp"

class CCondMean {
std::vector<CAbstCondMean *> mMean;
double mComputeMean(CRegArchData mdata, int t);
cGSLVector mComputeGrad(CRegArchData mdata, int t);




};
#endif
