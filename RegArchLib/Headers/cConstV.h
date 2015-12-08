/* 
 * File:   cConstV.h
 * Author: ly
 *
 * Created on 7 décembre 2015, 12:45
 */

#ifndef CCONSTV_H
#define	CCONSTV_H
#include "cAbstCondVar.h"


class CConstV: public CAbstCondVar{
double constante;
virtual double mComputeVar(CRegArchData mData, int t);
virtual std::vector<double> mComputeGrad(CRegArchData mData, int t);

};


#endif	/* CCONSTV_H */

