#ifndef _CREGARCHMODEL_
#define _CREGARCHMODEL_

#include "cCondMean.hpp"
#include "cCondVar.h"
#include "cResiduals.hpp"



class CRegArchModel{

CCondMean *mCondMean;
CCondVar *mCondVar;
CResiduals *mResiduals;
CRegArcModel(CCondMean *mCondMean,CCondVar *mCondVar,CResiduals *mResiduals);
};
