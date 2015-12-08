#ifndef _CREGARCHDATA_
#define _CREGARCHDATA_


#include "StdAfxVectorAndMatrix.h"
using namespace VectorAndMatrixNameSpace;


class CRegArchData {

cGSLVector mYt;
cGSLVector mHt;
cGSLVector mUt;
cGSLVector mEt;
cGSLVector mXt;

CRegArchData(cGSLVector mYt,cGSLVector mHt,cGSLVector mUt,cGSLVector mEt,cGSLVector mXt);
};
#endif
