#ifndef _CRESIDUALS_
#define _CRESIDUALS_
#include <vector>
#include "cRegArchData.hpp"
class CResiduals{
std::vector<double> mparams;
virtual std::vector<double> mSimul(int)=0;
virtual double mlogDensity(double)=0;
virtual std::vector<double> mgradlogDensity(CRegArchData)=0;
};

#endif
