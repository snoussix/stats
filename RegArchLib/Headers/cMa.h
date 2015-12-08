/* 
 * File:   cMa.h
 * Author: vungocma
 *
 * Created on 7 décembre 2015, 12:42
 */

#ifndef CMA_H
#define	CMA_H
#include "cAbstCondMean.hpp"


class CMa: public CAbstCondMean{

virtual double mComputeMean(CRegArchData mData, int t);
virtual std::vector<double> mComputeGrad(CRegArchData mData, int t);
};



#endif	/* CMA_H */

