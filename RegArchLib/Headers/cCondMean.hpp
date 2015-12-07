#ifndef _CCONDMEAN_
#define _CCONDMEAN_
#include <vector>
#include "cAbstCondMean.hpp"
#include "cRegArchData.hpp"

class CCondMean {
std::vector<CAbstCondMean *> mMean;
double mComputeMean(CRegArchData mdata, int t);
std::vector<double> mComputeGrad(CRegArchData mdata, int t);




};
#endif
