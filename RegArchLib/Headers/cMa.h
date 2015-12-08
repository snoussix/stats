/* 
 * File:   cMa.h
 * Author: vungocma
 *
 * Created on 7 décembre 2015, 12:42
 */

#ifndef CMA_H
#define	CMA_H
#include "cAbstCondMean.hpp"
#include "StdAfxVectorAndMatrix.h"
using namespace VectorAndMatrixNameSpace;

class CMa: public CAbstCondMean{
    CMa(cGSLVector mParams);
virtual double mComputeMean(CRegArchData mData, int t);
virtual cGSLVector mComputeGrad(CRegArchData mData, int t);
};



#endif	/* CMA_H */

