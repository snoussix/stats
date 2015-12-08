#include "cRegArchModel.hpp"

CRegArchModel::CRegArchModel(CCondMean *mCondMean,CCondVar *mCondVar,CResiduals *mResiduals){
    this->mCondMean=mCondMean;
    this->mCondVar=mCondVar;
    this->mResiduals=mResiduals;
}