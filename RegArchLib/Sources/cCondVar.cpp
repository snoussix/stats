#include "cCondVar.h"
#include <vector>



CCondVar::CCondVar(std::vector<CAbstCondVar *> mVar,cGSLVector mParams):CAbstCondVar(mParams){
    this->mMean=mMean;
}
        
double CCondVar::mComputeVar(CRegArchData mData, int t){
//TODO
return 1.0;
}
cGSLVector CCondVar::mComputeGrad(CRegArchData mData, int t){
//TODO
cGSLVector reda;
return reda;
}
