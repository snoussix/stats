#ifndef _CREGARCHMODEL_
#define _CREGARCHMODEL_

#include "cCondMean.hpp"
#include "cCondVar.h"
#include "cResiduals.hpp"



class CRegArchModel{

CCondMean *mCondMean;
CCondVar *mCondVar;
CResiduals *mResiduals;
public:
CRegArchModel(CCondMean *mCondMean,CCondVar *mCondVar,CResiduals *mResiduals);
};

#endif