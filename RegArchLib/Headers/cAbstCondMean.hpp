#ifndef _CABSTCONDMEAN_
#define _CABSTCONDMEAN_
#include <vector>
#include "cRegArchData.hpp" 
class CAbstCondMean {
std::vector<double> mParams;
 CAbstCondMean(std::vector<double> mParams);
virtual double mComputeMean(CRegArchData mData, int t)=0;
virtual std::vector<double> mComputeGrad(CRegArchData mData, int t)=0;
};



#endif
