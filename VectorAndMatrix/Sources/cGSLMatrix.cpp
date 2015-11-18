#include "StdAfxVectorAndMatrix.h"
/*!
	\file cGSLMatrix.cpp
	\brief cGSLMatrix class functions definitions.
	\author Ollivier TARAMASCO 
	\date oct-13-2008
*/
namespace VectorAndMatrixNameSpace
{
	/*!
		\fn cGSLMatrix::cGSLMatrix
		\param uint theNRow, uint theNCol, double theVal
		\brief standard constructor: initializes cGSLMatrix size to theSize and affects theVal to all components
	*/
	cGSLMatrix::cGSLMatrix(int theNRow, int theNCol, double theVal)
	{
		if ( (theNRow == 0) && (theNCol == 0) )
			mvMat = (gsl_matrix *)NULL ;
		else
		{	if ( (theNRow > 0) && (theNCol > 0) )
			{	mvMat = gsl_matrix_alloc(theNRow, theNCol) ;	
				gsl_matrix_set_all(mvMat, theVal) ;
			}
			else
				throw cError("NRow and NCol must be strictly positive") ;
		}
	}

	/*!
		\fn cGSLMatrix::cGSLMatrix
		\param const cGSLVector &theVect
		\brief Constructor: creates a one column matrix = theVect
	*/
	cGSLMatrix::cGSLMatrix(const cGSLVector& theVect) 
	{
	uint myNRow = theVect.GetSize() ;
		if (myNRow != 0)
		{	mvMat = gsl_matrix_alloc(theVect.GetSize(), 1) ;
			for (register int i = 0 ; i < (int)myNRow ; i++)
				gsl_matrix_set(mvMat, i, 0, theVect[i]) ;
		}
		else
			mvMat = NULL ;
	}

	/*!
		\fn cGSLMatrix::cGSLMatrix
		\param const cGSLMatrix& theMat
		\brief Constructor: creates and affects theMat to *this
	*/
		cGSLMatrix::cGSLMatrix(const cGSLMatrix& theMat)
	{
	int myNRow = (int)theMat.GetNRow() ;
	int myNCol = (int)theMat.GetNCol() ;
		if ( (myNRow > 0) && (myNCol > 0) )
		{	mvMat = gsl_matrix_alloc(myNRow, myNCol) ;
	
			for (register int i = 0 ; i < myNRow ; i++)
				for (register int j = 0 ; j < myNCol ; j++)
					gsl_matrix_set(mvMat, i, j, theMat[i][j]) ;
		}
		else
			mvMat = NULL ;
	}

	/*!
		\fn cGSLMatrix::~cGSLMatrix
		\param none
		\brief standard destructor
	*/
	cGSLMatrix::~cGSLMatrix()
	{
		if (mvMat != NULL)
		{	gsl_matrix_free(mvMat) ;
			mvMat = NULL ;
		}
	}

	/*!
		\fn void cGSLMatrix::Delete
		\param void
		\brief destructor
	*/
	void cGSLMatrix::Delete(void)
	{
		if (mvMat != NULL)
		{	gsl_matrix_free(mvMat) ;
			mvMat = NULL ;
		}
	}

	/*!
		\fn void cGSLMatrix::ReAlloc
		\param uint theNRow, uint theNCol, double theVal
		\brief Reallocates the matrix to a theNRow x theNCol matrix and affects theVal to all matrix components
	*/
	void cGSLMatrix::ReAlloc(uint theNRow, uint theNCol, double theVal)
	{
		Delete() ;
		if ( (theNRow > 0) && (theNCol > 0) )
		{	mvMat = gsl_matrix_alloc(theNRow, theNCol) ;	
			gsl_matrix_set_all(mvMat, theVal) ;
		}
		else
			throw cError("NRow and NCol must be strictly positive") ;
	
	}

	/*!
		\fn void cGSLMatrix::ReAlloc
		\param const cGSLVector& theVect
		\brief Reallocates the matrix to a one colum matrix and affects theVect to this matrix
	*/
	void cGSLMatrix::ReAlloc(const cGSLVector& theVect)
	{
	int myNRow = (int)GetNRow() ;
	int myNCol = (int)GetNCol() ;
		if ( (myNRow != (int)theVect.GetSize()) || (myNCol != 1) )
		{	myNRow = (int)theVect.GetSize() ;
			Delete() ;
			mvMat = gsl_matrix_alloc(myNRow, 1) ;
		}
		for (register int i = 0 ; i < myNRow ; i++)
			gsl_matrix_set(mvMat, i, 0, theVect[i]) ;
	}

	/*!
		\fn void cGSLMatrix::ReAlloc
		\param const cGSLMatrix& theMat
		\brief Reallocates the matrix and *this=theMat
	*/
	void cGSLMatrix::ReAlloc(const cGSLMatrix& theMat)
	{
	int myNRow = (int)GetNRow() ;
	int myNCol = (int)GetNCol() ;
		if ( (myNRow != (int)theMat.GetNRow()) || (myNCol != (int)theMat.GetNCol()) )
		{	myNRow = (int)theMat.GetNRow() ;
			myNCol = (int)theMat.GetNCol() ;
			Delete() ;
			mvMat = gsl_matrix_alloc(myNRow, myNCol) ;
		}
		for (register int i = 0 ; i < myNRow ; i++)
			for (register int j = 0 ; j < myNCol ; j++)
				gsl_matrix_set(mvMat, i, j, theMat[i][j]) ;
	}

	/*!
		\fn double* cGSLMatrix::operator []
		\param uint theNRow
		\brief Returns the adress of theMat[theNRow]. 
	*/
	double* cGSLMatrix::operator [](int theNRow) const
	{
		if (theNRow < (int)GetNRow())
		{	
	#ifdef _RDLL_
			return (double *)&(mvMat->mData[theNRow * mvMat->mNCol]) ;
	#else
			return (double *)&(mvMat->data[theNRow * mvMat->tda]) ;
	#endif // _RDLL_
		}
		else
			throw cError("bad index") ;
	}

	/*!
		\fn uint cGSLMatrix::GetNRow
		\param void
		\brief Returns the number of rows of the matrix
	*/
	uint cGSLMatrix::GetNRow(void) const
	{	if (mvMat == NULL)
			return 0 ;
		else
		#ifdef _RDLL_
			return mvMat->mNRow ;
		#else
			return (uint)(mvMat->size1) ;
		#endif // _RDLL_
	}


	/*!
		\fn uint cGSLMatrix::GetNCol
		\param void
		\brief Returns the number of columns of the matrix
	*/
	uint cGSLMatrix::GetNCol(void) const
	{ 	if (mvMat == NULL)
			return 0 ;
		else
		#ifdef _RDLL_
			return mvMat->mNCol ;
		#else
			return (uint)(mvMat->size2) ;
		#endif // _RDLL_
	}

	/*!
		\fn cGSLMatrix& cGSLMatrix::operator =
		\param const cGSLMatrix& theSrcMatrix
		\brief *this=theSrcMatrix
	*/
	cGSLMatrix& cGSLMatrix::operator =(const cGSLMatrix& theSrcMatrix)
	{
	register uint	i,
					j	;
	uint myNRow = GetNRow() ;
	uint myNCol = GetNCol() ;
	uint mySrcNRow = theSrcMatrix.GetNRow() ;
	uint mySrcNCol = theSrcMatrix.GetNCol() ;

		if (myNRow == 0)
			ReAlloc(mySrcNRow, mySrcNCol) ;
		else
		{	if ( (myNRow != mySrcNRow) || (myNCol != mySrcNCol) )
			{	Delete() ;
				ReAlloc(mySrcNRow, mySrcNCol) ;
			}
		}
		for (i = 0 ; i < mySrcNRow ; i++)
			for (j = 0 ; j < mySrcNCol ; j++)
				gsl_matrix_set(mvMat, i, j, theSrcMatrix[i][j]) ;
		return *this ;
	}

	/*!
		\fn cGSLMatrix& cGSLMatrix::operator =
		\param const cGSLVector& theVect
		\brief *this=one column matrix=theVect
	*/
	cGSLMatrix& cGSLMatrix::operator =(const cGSLVector& theVect)
	{
	uint myNRow = GetNRow() ;
	uint myNCol = GetNCol() ;
	uint myVectNRow = theVect.GetSize() ;
	
		if (myNRow == 0)
		{	ReAlloc(myVectNRow, 1) ;
		}
		else
		{	if ( (myNRow != myVectNRow) || (myNCol != 1) )
			{	Delete() ;
				ReAlloc(myVectNRow, 1) ;
			}
		}
		for (register int i = 0 ; i < (int)myVectNRow ; i++)
			gsl_matrix_set(mvMat, i, 0, theVect[i]) ;
		return *this ;
	}

	/*!
		\fn cGSLMatrix& cGSLMatrix::operator =
		\param theVal
		\brief *this[i][j] = theVal for all i,j 
	*/
	cGSLMatrix& cGSLMatrix::operator =(double theVal)
	{
		if ( mvMat != NULL )
		{	gsl_matrix_set_all(mvMat, theVal) ;
		}
		return *this ;
	}

	/*!
		\fn cGSLMatrix& cGSLMatrix::operator +=
		\param const cGSLMatrix& theMatrix
		\brief *this[i][j] += theMatrix[i][j] for all i,j
	*/
	cGSLMatrix& cGSLMatrix::operator +=(const cGSLMatrix& theMatrix)
	{
		*this = *this + theMatrix ;
		return *this ;
	}

	/*!
		\fn cGSLMatrix& cGSLMatrix::operator +=
		\param double theVal
		\brief *this[i][j] += theVal for all i, j
	*/
	cGSLMatrix& cGSLMatrix::operator +=(double theVal)
	{
		*this = *this + theVal ;
		return *this ;
	}

	/*!
		\fn cGSLMatrix& cGSLMatrix::operator -=
		\param const cGSLMatrix& theMatrix
		\brief *this[i][j] += theMatrix[i][j] for all i, j
	*/
	cGSLMatrix& cGSLMatrix::operator -=(const cGSLMatrix& theMatrix)
	{
		*this = *this -theMatrix ;
		return *this ;
	}


	/*!
		\fn cGSLMatrix& cGSLMatrix::operator -=
		\param double theVal
		\brief *this[i][j] += theVal for all i, j
	*/
	cGSLMatrix& cGSLMatrix::operator -=(double theVal)
	{
		*this = *this - theVal ;
		return *this ;
	}

	/*!
		\fn cGSLMatrix& cGSLMatrix::operator *=
		\param double theMatrix
		\brief *this *= theMatrix. Beware to matrices sizes
	*/
	cGSLMatrix& cGSLMatrix::operator *=(const cGSLMatrix& theMatrix)
	{	
		*this = *this * theMatrix ;
		return *this ;
	}

	/*!
		\fn cGSLMatrix& cGSLMatrix::operator *=
		\param double theVal
		\brief *this[i][j] *= theVal for all i, j
	*/
	cGSLMatrix& cGSLMatrix::operator *=(double theVal)
	{
		*this = *this * theVal ;
		return *this ;
	}

	/*!
		\fn cGSLMatrix& cGSLMatrix::operator /=
		\param double theVal
		\brief **this[i][j] /= theVal for all i, j
	*/
	cGSLMatrix& cGSLMatrix::operator /=(double theVal)
	{
		*this = *this / theVal ;
		return *this ;
	}


/*!
		\fn void cGSLMatrix::Print(std::ostream& theStream)
		\param std::ostream& theStream (default cout) 
		\brief Pront the matrix
	*/
	void cGSLMatrix::Print(std::ostream& theStream)
	{	theStream << *this ;
	}

	/*!
		\fn cGSLMatrix operator+
		\param const cGSLMatrix& theLeft, const cGSLMatrix& theRight
		\brief returns matrix operation: theLeft+theRight
	*/
	cGSLMatrix operator+(const cGSLMatrix& theLeft, const cGSLMatrix& theRight) 
	{
	uint myNCol = theLeft.GetNCol() ;
	uint myNRow = theLeft.GetNRow() ;
	//cGSLMatrix myRes = cGSLMatrix(theLeft) ;
	cGSLMatrix myTempMatrix = theLeft ;
		if ( (myNRow == theRight.GetNRow()) && (myNCol == theRight.GetNCol()) )
		{	for (register uint i = 0 ; i < myNRow ; i++)
				for (register uint j = 0 ; j < myNCol ; j++)
					myTempMatrix[i][j] += theRight[i][j] ;
			return cGSLMatrix(myTempMatrix) ;
		}
		else
			throw cError("wrong size") ;
	}

	/*!
		\fn cGSLMatrix operator+
		\param const cGSLMatrix& theLeft, double theVal
		\brief returns matrix theLeft[i][j] + theVal for all i,j
	*/
	cGSLMatrix operator+(const cGSLMatrix& theLeft, double theVal) 
	{
	uint myNCol = theLeft.GetNCol() ;
	uint myNRow = theLeft.GetNRow() ;
	//cGSLMatrix myRes = cGSLMatrix(theLeft) ;
		cGSLMatrix myTempMatrix = theLeft ;
		for (register uint i = 0 ; i < myNRow ; i++)
			for (register uint j = 0 ; j < myNCol ; j++)
				myTempMatrix[i][j] += theVal ;
		return cGSLMatrix(myTempMatrix) ;
	}

	/*!
		\fn cGSLMatrix operator+
		\param double theVal, const cGSLMatrix& theRight
		\brief returns matrix theVal + theRight[i][j] for all i,j
	*/
	cGSLMatrix operator+(double theVal, const cGSLMatrix& theRight) 
	{
		return theRight + theVal ;
	}

	/*!
		\fn cGSLMatrix operator-
		\param const cGSLMatrix& theLeft, const cGSLMatrix& theRight
		\brief returns matrix theLeft[i][j]-theRight[i][j] for all i,j
	*/
	cGSLMatrix operator-(const cGSLMatrix& theLeft, const cGSLMatrix& theRight) 
	{
	uint myNCol = theLeft.GetNCol() ;
	uint myNRow = theLeft.GetNRow() ;
	//cGSLMatrix myRes = cGSLMatrix(theLeft) ;
		cGSLMatrix myTempMatrix = theLeft ;
		if ( (myNRow == theRight.GetNRow()) && (myNCol == theRight.GetNCol()) )
		{	for (register uint i = 0 ; i < myNRow ; i++)
				for (register uint j = 0 ; j < myNCol ; j++)
					myTempMatrix[i][j] -= theRight[i][j] ;
			return cGSLMatrix(myTempMatrix) ;
		}
		else
			throw cError("wrong size") ;
	}

	/*!
		\fn cGSLMatrix operator-
		\param const cGSLMatrix& theLeft, const cGSLMatrix& theRight
		\brief returns matrix theLeft[i][j]-theRight[i][j] for all i,j
	*/
	cGSLMatrix operator-(const cGSLMatrix& theLeft, double theVal) 
	{
	uint myNCol = theLeft.GetNCol() ;
	uint myNRow = theLeft.GetNRow() ;
	//cGSLMatrix myRes = cGSLMatrix(theLeft) ;
		cGSLMatrix myTempMatrix = theLeft ;
		for (register uint i = 0 ; i < myNRow ; i++)
				for (register uint j = 0 ; j < myNCol ; j++)
					myTempMatrix[i][j] -= theVal ;
			return cGSLMatrix(myTempMatrix) ;
	}

	/*!
		\fn cGSLMatrix operator-
		\param double theVal, const cGSLMatrix& theRight
		\brief returns matrix theVal-theRight[i][j] for all i,j
	*/
	cGSLMatrix operator-(double theVal, const cGSLMatrix& theRight) 
	{
	int myNCol = (int)theRight.GetNCol() ;
	int myNRow = (int)theRight.GetNRow() ;
	//cGSLMatrix myRes = cGSLMatrix(myNRow, myNCol, theVal) ;
		cGSLMatrix myTempMatrix(myNRow, myNCol, theVal) ;
		for (register int i = 0 ; i < myNRow ; i++)
			for (register int j = 0 ; j < myNCol ; j++)
				myTempMatrix[i][j] -= theRight[i][j] ;

		return cGSLMatrix(myTempMatrix) ;
	}

	/*!
		\fn cGSLMatrix operator*
		\param const cGSLMatrix& theLeft, const cGSLMatrix &theRight
		\brief returns matrix multiplication theLeft * theRight
	*/
	cGSLMatrix operator *(const cGSLMatrix& theLeft, const cGSLMatrix &theRight)
	{	
	cGSLMatrix myTempMatrix(theLeft.GetNRow(), theRight.GetNCol(), 0.0L) ;
		if ( (theLeft.GetNCol() == theRight.GetNRow()) )
		{	for (register uint i = 0 ; i < theLeft.GetNRow() ; i++)
				for (register uint j = 0 ; j < theRight.GetNCol() ; j++)
					for (register uint k = 0 ; k < theLeft.GetNCol() ; k++)
						myTempMatrix[i][j] += theLeft[i][k] * theRight[k][j] ;
			return cGSLMatrix(myTempMatrix) ;
		}
		else
			throw cError("wrong matrices size") ;
	}

	/*!
		\fn cGSLMatrix operator*
		\param const cGSLMatrix& theLeft, const cGSLVector& theVect
		\brief returns vector theLeft * theVect
	*/
	cGSLVector operator *(const cGSLMatrix& theLeft, const cGSLVector& theVect)
	{
	uint myNCol = theLeft.GetNCol() ;
	uint myNRow = theLeft.GetNRow() ;
		if (myNRow == theVect.GetSize())
		{	
		cGSLVector myTempVector(myNRow, 0.0L) ;
			for (register uint i = 0 ; i < myNRow ; i++)
				for (register uint j = 0 ; j < myNCol ; j++)
					myTempVector[i] += theLeft[i][j] * theVect[j] ;
			return cGSLVector(myTempVector) ;
		}
		else
			throw cError("wrong matrix or vector size") ;
	}

	/*!
		\fn cGSLMatrix operator*
		\param const cGSLVector& theVect, const cGSLMatrix& theRight
		\brief returns  matrix theVect * theRight
	*/
	cGSLMatrix operator *(const cGSLVector& theVect, const cGSLMatrix& theRight)
	{
	uint myNCol = theRight.GetNCol() ;
	uint myNRow = theVect.GetSize() ;
		if  (theRight.GetNRow() == 1)
		{
		cGSLMatrix myTempMatrix(myNRow, myNCol) ;
			for (register uint i = 0 ; i < myNRow ; i++)
				for (register uint j = 0 ; j < myNCol ; j++)
					myTempMatrix[i][j] += theVect[i]*theRight[0][j] ;
			return cGSLMatrix(myTempMatrix) ;
		}
		else
			throw cError("wrong matrix or vector size") ;
	}

	/*!
		\fn cGSLMatrix operator*
		\param const cGSLMatrix& theMatrix, double theLambda
		\brief returns matrix theLambda * theMatrix
	*/
	cGSLMatrix operator *(const cGSLMatrix& theMatrix, double theLambda)
	{	
	cGSLMatrix myTempMatrix(theMatrix.GetNRow(), theMatrix.GetNCol()) ;
		for (register uint i = 0 ; i < theMatrix.GetNRow() ; i++)
			for (register uint j = 0 ; j< theMatrix.GetNCol() ; j++)
				myTempMatrix[i][j] = theLambda*theMatrix[i][j] ;
		return cGSLMatrix(myTempMatrix) ;
	}

	/*!
		\fn cGSLMatrix operator*
		\param double theLambda, const cGSLMatrix& theMatrix
		\brief returns matrix theLambda * theMatrix
	*/
	cGSLMatrix operator *(double theLambda, const cGSLMatrix& theMatrix)
	{
	cGSLMatrix myTempMatrix = theMatrix * theLambda ;
		return cGSLMatrix(myTempMatrix) ;
	}

	/*!
		\fn cGSLMatrix operator/
		\param const cGSLMatrix& theMatrix, double theLambda
		\brief returns matrix theMatrix/theLambda
	*/
	cGSLMatrix operator /(const cGSLMatrix& theMatrix, double theLambda)
	{	
		if (theLambda == 0)
			throw cError("Division by zero") ;
		
	cGSLMatrix myTempMatrix = theMatrix * (1.0/theLambda) ;
		return myTempMatrix ;
	}

	/*!
		\fn std::ostream& operator <<
		\param std::ostream& theStream, const cGSLMatrix& theMat
		\brief prints matrix theMat
	*/
	std::ostream& operator <<(std::ostream& theStream, const cGSLMatrix& theMat)
	{
	uint myNRow = theMat.GetNRow() ;
	uint myNColm1 = theMat.GetNCol() - 1 ;

		for (register uint i = 0 ; i < myNRow ; i++)
		{	for (register uint j = 0 ; j < myNColm1 ; j++)
				theStream << theMat[i][j] << "\t" ;
			theStream << theMat[i][myNColm1] << std::endl ;
		}
		return theStream ;
	}

	/*!
		\fn cGSLMatrix Transpose
		\param const cGSLMatrix& theMatrix
		\brief Transposes matrix theMatrix
	*/
	cGSLMatrix Transpose(const cGSLMatrix& theMatrix)
	{
	cGSLMatrix myTempMatrix(theMatrix.GetNCol(), theMatrix.GetNRow()) ;
		for (register uint i = 0 ; i < theMatrix.GetNRow() ; i++)
			for (register uint j = 0 ; j < theMatrix.GetNCol() ; j++)
				myTempMatrix[j][i] = theMatrix[i][j] ;
		return cGSLMatrix(myTempMatrix) ;
	}

	/*!
		\fn cGSLMatrix Transpose
		\param const cGSLVector& theVect
		\brief Transposes vector theVect
	*/
	cGSLMatrix Transpose(const cGSLVector& theVect)
	{
	cGSLMatrix myTempMatrix(1, theVect.GetSize()) ;
		for (register uint i=0 ; i < theVect.GetSize() ; i++)
				myTempMatrix[0][i] = theVect[i] ;
		return cGSLMatrix(myTempMatrix) ;
	}

	/*!
		\fn cGSLMatrix Zeros
		\param uint theN, uint theP
		\brief creates the theN x theP "0" matrix
	*/
	cGSLMatrix Zeros(uint theN, uint theP)
	{
	cGSLMatrix myTempMatrix(theN, theP) ;
		return cGSLMatrix(myTempMatrix) ;
	}

	/*!
		\fn cGSLMatrix Identity
		\param uint theN
		\brief creates the theN x theN identity matrix
	*/
	cGSLMatrix Identity(uint theN)
	{
	cGSLMatrix myTempMatrix(theN, theN) ;
		for (register uint i = 0 ; i < theN ; i++)
			myTempMatrix[i][i] = 1.0L ;
		return cGSLMatrix(myTempMatrix) ;
	}

	/*!
		\fn cGSLMatrix Diag
		\param const cGSLVector& theVect
		\brief creates the diagonal matrix with diagonal=theVect
	*/
	cGSLMatrix Diag(const cGSLVector& theVect)
	{
	uint mySize = theVect.GetSize() ;
	cGSLMatrix myTempMatrix(mySize, mySize) ;
		for (register uint i = 0 ; i < mySize ; i++)
			myTempMatrix[i][i] = theVect[i] ;
		return cGSLMatrix(myTempMatrix) ;
	}


	#ifdef _RDLL_
	void LapackInvAndDet(const cGSLMatrix& theMatrix, cGSLMatrix& theInvMatrix, double& theDet)
	{
	uint	myNCol = theMatrix.GetNCol(),
			myNRow = theMatrix.GetNRow() ;

	double *myAP = new double[myNCol*(myNCol + 1)/2],
			*myW = new double[myNCol],
			*myZ = new double[myNCol*myNCol],
			*myWork = new double[myNCol * 3] ;
	int myInfo,
		myN = (int)(myNCol),
		myldz = (int)(myNCol) ;

		for (register int i = 0 ; i < myN ; i++)
			for (register int j = i ; j < myldz ; j++)
				myAP[i+(j+1)*j/2]  = theMatrix[i][j] ;

		F77_NAME(dspev)("V", "U", &myN, myAP, myW, myZ, &myldz, myWork, &myInfo) ;

		if (myInfo != 0)
			error("Non inversible matrix") ;
		theDet = 1.0L ;
	cGSLVector myInvEigenValue = cGSLVector(myNCol) ;

	cGSLMatrix myEigenVector = cGSLMatrix(myNCol, myNCol) ;
		for (register uint i = 0 ; i < myNCol ; i++)
		{	theDet *= myW[i] ;
			myInvEigenValue[i] = 1.0 /myW[i] ;
			for (register int j = 0 ; j < myN ; j++)
				myEigenVector[i][j] = myZ[i + j*myN] ;
		}
		theInvMatrix =  myEigenVector * Diag(myInvEigenValue) * Transpose(myEigenVector);
	
		delete myAP ;
		delete myW ;
		delete myZ ;
		delete myWork ;

	}
	#else

	/*!
		\fn void Svd
		\param const cGSLMatrix& theMatrix, cGSLMatrix& theU, cGSLVector& theS, cGSLMatrix& theV
		\brief singular value decomposition of theMatrix
	*/
	void Svd(const cGSLMatrix& theMatrix, cGSLMatrix& theU, cGSLVector& theS, cGSLMatrix& theV) 
	{
	int myNRow = theMatrix.GetNRow() ;
	int myNCol = theMatrix.GetNCol() ;

	gsl_matrix* myA = gsl_matrix_alloc(myNRow, myNCol) ;
	gsl_vector* myWork = gsl_vector_alloc(myNCol) ;
	gsl_matrix* myV = gsl_matrix_alloc(myNRow, myNCol) ;
	gsl_vector* myS = gsl_vector_alloc(myNCol) ;

		for (register int i = 0 ; i < myNRow ; i++)
			for (register int j = 0 ; j < myNCol ; j++)
				gsl_matrix_set(myA, i, j, theMatrix[i][j]) ;
		gsl_linalg_SV_decomp(myA, myV, myS, myWork) ; 
		theS.ReAlloc(myS) ;
		theU.ReAlloc(myNRow, myNCol) ;
		theV.ReAlloc(myNRow, myNCol) ;
		for (register int i = 0 ; i < myNRow ; i++)
			for (register int j = 0 ; j < myNCol ; j++)
			{	theU[i][j] = gsl_matrix_get(myA, i, j) ;
				theV[i][j] = gsl_matrix_get(myV, i, j) ;
			}
		gsl_matrix_free(myA) ;
		gsl_matrix_free(myV) ;
		gsl_vector_free(myWork) ;
	}
	#endif // _RDLL_

	/*!
		\fn cGSLMatrix Inv
		\param const cGSLMatrix& theMatrix
		\brief Returns the inverse of theMatrix
	*/
	cGSLMatrix Inv(const cGSLMatrix& theMatrix)
	#ifdef _RDLL_
	{
	//cOTMatrix	myInv = cOTMatrix(theMatrix.mNRow, theMatrix.mNCol) ;
		myTempMatrix.ReAlloc(theMatrix.GetNRow(), theMatrix.GetNCol()) ;
	double myDet ;

		LapackInvAndDet(theMatrix, myTempMatrix, myDet) ;
		if (fabs(myDet) < MIN_DBLE)
			error("Non inversible matrix") ;
		return myTempMatrix ;
	}
	#else
	{
	int myNRow = theMatrix.GetNRow() ;
	int myNCol = theMatrix.GetNCol() ;
		if (myNRow != myNCol)
			throw cError("not a square matrix") ;
		if (myNRow == 0)
			throw cError("wrong size") ;

	cGSLMatrix myU, myV ;
	cGSLVector myS ;
		Svd(theMatrix, myU, myS, myV) ;

		for (register int i = 0 ; i < myNCol ; i++)
			if (myS[i] == 0)
				throw cError("Not inversible matrix") ;
			else
				myS[i] = 1.0/myS[i] ;
	cGSLMatrix mySInvMat = Diag(myS) ;
	cGSLMatrix myTempMatrix(myNRow, myNRow) ;
		myTempMatrix = myV * mySInvMat ;
		myTempMatrix = myTempMatrix * Transpose(myU) ;
		return cGSLMatrix(myTempMatrix) ;
	}
	#endif // _RDLL_

	/*!
		\fn void ClearMatrix
		\param cGSLMatrix& theMatrix
		\brief Deletes matrix theMatrix
	*/
	void ClearMatrix(cGSLMatrix& theMatrix)
	{
		theMatrix.Delete() ;
	}

}
