#ifndef _CAR_
#define _CAR_
#include "cAbstCondMean.hpp"


class CAr: public CAbstCondMean{
CAr(std::vector<double> mParams);
virtual double mComputeMean(CRegArchData mData, int t);
virtual std::vector<double> mComputeGrad(CRegArchData mData, int t);
};

#endif
