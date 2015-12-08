#include "cConstM.hpp"




CConstM::CConstM(double constante,cGSLVector mParams):CAbstCondMean(mParams){
    this->constante = constante;
}
double CConstM::mComputeMean(CRegArchData mData, int t){
//TODO
return 1.0;
}
cGSLVector CConstM::mComputeGrad(CRegArchData mData, int t){
//TODO
cGSLVector reda;
return reda;
}
