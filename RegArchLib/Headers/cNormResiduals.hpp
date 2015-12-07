#ifndef _CNORMRESIDUALS_
#define _CNORMRESIDUALS_

#include "cResiduals.hpp"

class CNormResiduals: public CResiduals{

virtual std::vector<double> mSimul(int);
virtual double mlogDensity(double);
virtual std::vector<double> mgradlogDensity(CRegArchData);

};

#endif
