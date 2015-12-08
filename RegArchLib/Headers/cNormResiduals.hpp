#ifndef _CNORMRESIDUALS_
#define _CNORMRESIDUALS_

#include "cResiduals.hpp"
#include "StdAfxVectorAndMatrix.h"
using VectorAndMatrixNameSpace;


class CNormResiduals: public CResiduals{

virtual cGSLVector mSimul(int);
virtual double mlogDensity(double);
virtual cGSLVector mgradlogDensity(CRegArchData);

};

#endif
