#ifndef _CNORMRESIDUALS_
#define _CNORMRESIDUALS_

#include "cResiduals.hpp"
#include "StdAfxVectorAndMatrix.h"
using namespace VectorAndMatrixNameSpace;


class CNormResiduals: public CResiduals{
     CNormResiduals(cGSLVector mparams);
virtual cGSLVector mSimul(int);
virtual double mlogDensity(double);
virtual cGSLVector mgradlogDensity(CRegArchData);

};

#endif
