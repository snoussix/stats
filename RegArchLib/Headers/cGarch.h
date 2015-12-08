/* 
 * File:   cGarch.h
 * Author: vungocma
 *
 * Created on 7 décembre 2015, 12:40
 */

#ifndef CGARCH_H
#define	CGARCH_H
#include "cAbstCondVar.h"


class CGarch: public CAbstCondVar{

virtual double mComputeVar(CRegArchData mData, int t);
virtual cGSLVector mComputeGrad(CRegArchData mData, int t);
};



#endif	/* CGARCH_H */

