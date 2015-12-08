#include "cRegArchModel.hpp"

CRegArchModel::CRegArcModel(CCondMean *mCondMean,CCondVar *mCondVar,CResiduals *mResiduals){
    this->mCondMean=mCondMean;
    this->mCondVar=mCondVar;
    this->mResiduals=mResiduals;
}