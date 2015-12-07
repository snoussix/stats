#ifndef _CCONSTM_
#define _CCONSTM_
#include "cAbstCondMean.hpp"


class CConstM: public CAbstCondMean{
double constante;
virtual double mComputeMean(CRegArchData mData, int t);
virtual std::vector<double> mComputeGrad(CRegArchData mData, int t);

};

#endif
