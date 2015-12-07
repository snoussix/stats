/* 
 * File:   cAbstCondVar.h
 * Author: vungocma
 *
 * Created on 7 décembre 2015, 12:36
 */

#ifndef CABSTCONDVAR_H
#define	CABSTCONDVAR_H

#include <vector>
#include "cRegArchData.hpp" 
class CAbstCondVar {
std::vector<double> mParams;
virtual double mComputeVar(CRegArchData mData, int t)=0;
virtual std::vector<double> mComputeGrad(CRegArchData mData, int t)=0;
};



#endif	/* CABSTCONDVAR_H */

