/* 
 * File:   cCondVar.h
 * Author: vungocma
 *
 * Created on 7 décembre 2015, 12:37
 */

#ifndef CCONDVAR_H
#define	CCONDVAR_H
#include <vector>
#include "cAbstCondVar.h"
#include "cRegArchData.hpp"
#include "StdAfxVectorAndMatrix.h"
using VectorAndMatrixNameSpace;


class CCondVar {
std::vector<CAbstCondVar *> mMean;
CCondVar(std::vector<CAbstCondVar *> mMean,cGSLVector mParams);
double mComputeVar(CRegArchData mdata, int t);
cGSLVector mComputeGrad(CRegArchData mdata, int t);




};


#endif	/* CCONDVAR_H */

