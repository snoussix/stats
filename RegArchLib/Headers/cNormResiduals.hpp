#ifndef _CNORMRESIDUALS_
#define _CNORMRESIDUALS_

#include <gsl/gsl_math.h>
#include "cResiduals.hpp"

class CNormResiduals: public CResiduals{

virtual cGSLVector mSimul(int);
virtual double mlogDensity(double);
virtual cGSLVector mgradlogDensity(CRegArchData);

};

#endif
