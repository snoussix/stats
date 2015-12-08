#include "cRegArchModel.hpp"
#include "StdAfxVectorAndMatrix.h"
using VectorAndMatrixNameSpace;
        
int main(int argc, char* argv[]){
    CCondMean *mCondMean;
    CCondVar *mCondVar;
    CResiduals *mResiduals;
    
    cGSLVector mParams;
    std::vector<CAbstCondMean *> mMean;
    
    std::vector<CAbstCondVar *> mVar;
    cGSLVector mParamsVar;
    
    
    
    mCondMean= new CCondMean(mMean,mParams);
    mCondVar = new CCondVar(mVar,mParamsVar);
    
    
    
         CRegArchModel(mCondMean,mCondVar,mResiduals);
         
         
     }   