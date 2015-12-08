#ifndef _CRESIDUALS_
#define _CRESIDUALS_
#include <vector>
#include "cRegArchData.hpp"
#include "cGSLVector.h"

class CResiduals{
cGSLVector mparams;
 CResiduals(cGSLVector mparams);
virtual cGSLVector mSimul(int)=0;
virtual double mlogDensity(double)=0;
virtual cGSLVector mgradlogDensity(CRegArchData)=0;
};

#endif
