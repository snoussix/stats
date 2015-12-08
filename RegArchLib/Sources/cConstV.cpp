#include "cConstV.h"




CConstV::CConstV(double constante,cGSLVector mParams):CAbstCondVar(mParams){
    this->constante = constante;
}
double CConstV::mComputeVar(CRegArchData mData, int t){
//TODO
return 1.0;
}
cGSLVector CConstV::mComputeGrad(CRegArchData mData, int t){
//TODO
cGSLVector reda;
return reda;
}
