#include "cNormResiduals.hpp"


CNormResiduals::CNormResiduals(cGSLVector mparams):CResiduals(mparams){
  
}
  
double CNormResiduals::mlogDensity(double){
//TODO
return 1.0;
}

cGSLVector CNormResiduals::mgradlogDensity(CRegArchData){
//TODO
cGSLVector reda;
return reda;
}
cGSLVector CNormResiduals::mSimul(int){
//TODO
cGSLVector reda;
return reda;
}
