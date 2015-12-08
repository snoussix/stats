/* 
 * File:   cAbstCondVar.h
 * Author: vungocma
 *
 * Created on 7 décembre 2015, 12:36
 */

#ifndef CABSTCONDVAR_H
#define	CABSTCONDVAR_H

#include "cRegArchData.hpp" 
#include "StdAfxVectorAndMatrix.h"
using VectorAndMatrixNameSpace;

class CAbstCondVar {
cGSLVector mParams;
CAbstCondVar(cGSLVector mParams);

virtual double mComputeVar(CRegArchData mData, int t)=0;
virtual cGSLVector mComputeGrad(CRegArchData mData, int t)=0;
};



#endif	/* CABSTCONDVAR_H */

