#include "cRegArchModel.hpp"
#include "StdAfxVectorAndMatrix.h"
using namespace VectorAndMatrixNameSpace;
        
int main(int argc, char* argv[]){
    CCondMean *mCondMean;
    CCondVar *mCondVar;
    CResiduals *mResiduals;
    
    cGSLVector mParams;
    std::vector<CAbstCondMean *> mMean;
    
    std::vector<CAbstCondVar *> mVar;
    cGSLVector mParamsVar;
    
    
    
    mCondMean= new CCondMean(mMean);
    mCondVar = new CCondVar(mVar);
    
    
    
         CRegArchModel(mCondMean,mCondVar,mResiduals);
         
         
     }   