#ifndef _CREGARCHDATA_
#define _CREGARCHDATA_


#include <gsl/gsl_math.h>

#include "cAr.hpp"
#include <vector>
#include <gsl/gsl_math.h>


class CRegArchData {

cGSLVector mYt;
cGSLVector mHt;
cGSLVector mUt;
cGSLVector mEt;
cGSLVector mXt;

CReArchData(cGSLVector mYt,cGSLVector mHt,cGSLVector mUt,cGSLVector mEt,cGSLVector mXt);
};
#endif
