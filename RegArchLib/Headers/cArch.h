/* 
 * File:   cArch.h
 * Author: vungocma
 *
 * Created on 7 décembre 2015, 12:39
 */

#ifndef CARCH_H
#define	CARCH_H
#include "cAbstCondVar.h"
#include "StdAfxVectorAndMatrix.h"
using VectorAndMatrixNameSpace;

class CArch: public CAbstCondVar{
    CArch(cGSLVector mParams);
virtual double mComputeVar(CRegArchData mData, int t);
virtual cGSLVector mComputeGrad(CRegArchData mData, int t);
};


#endif	/* CARCH_H */

