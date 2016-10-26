/*
 * mat.h
 *
 *  Created on: 3 Oct 2016
 *      Author: sam
 */

#ifndef MAT_H_
#define MAT_H_

#include <assert.h>
#include <iostream>

class Mat
{
    /**  Pointer to the matrix data, you should handle the memory allocation (delection) yourself */
    double * mData;
    /**  Pointer of the pointers, mRow[i] is the pointer that point to the first element of the i-th row */
    double * * mRow;
    /**  Row number of the matrix.*/
    size_t mRowNum;
    /**  Column number of the matrix.*/
    size_t mColNum;

public:
    /**  Default constructor.*/
    Mat(): mData(NULL), mRow(NULL), mRowNum(0), mColNum(0) {}

    /**  functions for mat information.*/
    inline size_t rowNum() const {return mRowNum;}
    inline size_t colNum() const {return mColNum;}
    inline size_t elementNum() const {return colNum() * rowNum();}
    inline size_t rawBufferLength() const {return colNum() * rowNum() * sizeof(double);}
    inline double * const * rawMat() const {return mRow;}
    inline double * * rawMat() {return mRow;}
    inline double const * rawVec() const {return mData;}
    inline double * rawVec() {return mData;}

    /**  functions and operators for access the matrix elements.*/
    inline double operator()(size_t r, size_t c) const {assert(NULL != mData); return mRow[r][c];}
    inline double & operator()(size_t r, size_t c) {assert(NULL != mData); return mRow[r][c];}
    inline double operator()(size_t i) const {assert(NULL != mData); return mData[i];}
    inline double & operator()(size_t i) {assert(NULL != mData); return mData[i];}
    inline const double * row(size_t r) const {assert(NULL != mData); return mRow[r];}
    inline double * row(size_t r) {assert(NULL != mData); return mRow[r];}

    /**  Reshape the matrix. The number of elements of the reshaped matrix
		should be the same as the number of elements of the original matrix.
		@param rNum The number of rows of the reshaped matrix
		@param cNum The number of columns of the reshaped matrix
    */
    void reshape(size_t rNum, size_t cNum)
	{
		assert(rNum*cNum == elementNum() && "[Mat<>::reshape] Cannot reshape a dynamic matrix to a matrix with different total number of elements.");
		if (NULL != mRow)
			delete[] mRow;
		mRowNum = rNum;
		mColNum = cNum;
		mRow = new double *[rowNum()];
		for (size_t r = 0; r < rowNum(); ++r)
			mRow[r] = mData + r * colNum();
	}

    /**  Print out all elements of the matrix */
    void printMat()
    {
        if (mRowNum == 0 || mColNum == 0)
        	std::cout << "[]" << std::endl;
        else
        {
            for (size_t r = 0; r < mRowNum; r++)
            {
                for (size_t c = 0; c < mColNum; c++)
                    std::cout << (*this)(r, c) << " ";
                std::cout << std::endl;
            }
        }
    }


    /***** YOU ARE REQUESTED TO IMPLEMENT ALL THE FOLLOWING FUNCTIONS *****/
    /**  Copy constructor.*/
    Mat(const Mat & src);

    /**  Constructor that set the matrix's dimention.*/
    Mat(const size_t rNum, const size_t cNum);

    /**  Destructor.*/
    ~Mat();

    /**  Operations for matrix, every element of the matrix should change according to the parameter value.*/
    Mat & assign(const double & val); /**  Element-wise assign, equals to "=" operation*/
    Mat & plusEqual(const double & val); /**  Element-wise addition, equals to "+=" operation*/
    Mat & minusEqual(const double & val); /**  Element-wise subtraction, equals to "-=" operation*/
    Mat & multiplyEqual(const double & val); /**  Matrix multiplication, equals to "*=" operation*/
    Mat & divideEqual(const double & val); /**  Element-wise division, equals to "/=" operation*/

    /**  Matrix operations.*/
    Mat & assign(const Mat & rhs); /**  Element-wise operator, equals to "=" operation*/
    Mat & plusEqual(const Mat & rhs); /**  Element-wise operation, equals to "+=" operation*/
    Mat & minusEqual(const Mat & rhs); /**  Element-wise operation, equals to "-=" operation*/
    Mat & multiplyEqual(const Mat & rhs); /**  Matrix multiplication, equals to "*=" operation*/
    Mat & divideEqual(const Mat & rhs); /**  Element-wise operation. equals to "/=" operation*/

    /**  Matrix operations.*/
    Mat plus(const Mat & rhs); /**  Element-wise operation, equals to "+" operation*/
    Mat minus(const Mat & rhs); /**  Element-wise operation, equals to "-" operation*/
    Mat multiply(const Mat & rhs); /**  Matrix multiplication, equals to "*" operation*/
    Mat divide(const Mat & rhs); /**  Element-wise operation, equals to "/" operation*/

    /**  Transpose a mat. */
    Mat & transpose();
    void transposeTo(Mat & dstMat) const;

    /**  L1, L2 norms of the matrix.*/
    double norml1() const; /**  The sum of absolute values of all the elements, namely, \sum_{ij}|a_{ij}| */
    double norml2() const; /**  The square root of the sum of the square of all the elements, namely, sqrt{\sum_{ij} (a_{ij})^2} */

    /**  Normalize the matrix.*/
    Mat & normalize(); /**  Divide the matrix by its L2 norms */

    /**  Fill all elements of the matrix with the same value.*/
    Mat & fill(const double val);

    /**  Resize the matrix.
        @param rNum The number of rows of the resized matrix
        @param cNum The number of columns of the resized matrix
        */
    void resize(size_t rNum, size_t cNum);

    /**  fill the matrix with an array. */
    void fillMemory(double * pMemory, size_t rNum, size_t cNum);
    /**  You need to COPY instead of to MOVE the data to make sure the safety of the function.
     Specifically, you need to reallocate the matrix memory and copy each element in the array
     instead of doing mData = pMemory.(Think: Why?) */

};



#endif /* MAT_H_ */
