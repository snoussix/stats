/* 
 * File:   cArch.h
 * Author: vungocma
 *
 * Created on 7 décembre 2015, 12:39
 */

#ifndef CARCH_H
#define	CARCH_H
#include "cAbstCondVar.h"


class CArch: public CAbstCondVar{

virtual double mComputeVar(CRegArchData mData, int t);
virtual cGSLVector mComputeGrad(CRegArchData mData, int t);
};


#endif	/* CARCH_H */

