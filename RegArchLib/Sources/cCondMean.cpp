#include "cCondMean.hpp"
#include <vector>



CCondMean::CCondMean(std::vector<CAbstCondMean *> mMean,cGSLVector mParams):CAbstCondMean(mParams){
    this->mMean=mMean;
}
double CCondMean::mComputeMean(CRegArchData mdata,int t){
//TODO 
return 0.0;
}



cGSLVector CCondMean::mComputeGrad(CRegArchData mdata,int t)
{
//TODO
cGSLVector ly; 
return ly;
}
