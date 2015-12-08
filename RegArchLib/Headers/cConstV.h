/* 
 * File:   cConstV.h
 * Author: ly
 *
 * Created on 7 décembre 2015, 12:45
 */

#ifndef CCONSTV_H
#define	CCONSTV_H
#include "cAbstCondVar.h"
#include "StdAfxVectorAndMatrix.h"
using VectorAndMatrixNameSpace;

class CConstV: public CAbstCondVar{
double constante;
CConstV(double constante,cGSLVector mParams);
virtual double mComputeVar(CRegArchData mData, int t);
virtual cGSLVector mComputeGrad(CRegArchData mData, int t);

};


#endif	/* CCONSTV_H */

