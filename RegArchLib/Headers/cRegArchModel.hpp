#ifndef _CREGARCHMODEL_
#define _CREGARCHMODEL_

class CRegArchModel{

CCondMean *mCondMean;
CCondVar *mCondVar;
CResiduals *mResiduals;
CRegArcModel(CCondMean *mCondMean,CCondVar *mCondVar,CResiduals *mResiduals);
};
