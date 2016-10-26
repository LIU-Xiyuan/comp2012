#include <iostream>
#include "mat.h"
#include <stdlib.h>
#include <math.h>

using namespace std;

Mat::Mat(const Mat & src)
{
	mRowNum=src.mRowNum;
	mColNum=src.mColNum;

	mData=new double[mRowNum*mColNum];
	mRow=new double*[mRowNum];
	for(size_t r=0;r<mRowNum;r++)
		mRow[r]=mData+r*mColNum;

	for(size_t i=0;i<mRowNum;i++)
		for(size_t j=0;j<mColNum;j++)
			mData[i*mColNum+j]=src.mData[i*mColNum+j];
}

Mat::Mat(const size_t rNum, const size_t cNum)
{
	mRowNum=rNum;
	mColNum=cNum;
	mData=new double[mRowNum*mColNum];
	mRow=new double*[mRowNum];
	for(size_t r=0;r<mRowNum;r++)
		mRow[r]=mData+r*mColNum;
}

Mat::~Mat()
{
	if(mData!=NULL)
		delete []mData;
	mData=NULL;
	if(mRow!=NULL)
		delete []mRow;
	mRow=NULL;

}

Mat& Mat::assign(const Mat & rhs)
{
	if(mData!=NULL)
		delete []mData;
	if(mRow!=NULL)
		delete []mRow;


	mRowNum=rhs.mRowNum;
	mColNum=rhs.mColNum;

	mData=new double[mRowNum*mColNum];
	mRow=new double*[mRowNum];
	for(size_t r=0;r<mRowNum;r++)
		mRow[r]=mData+r*mColNum;

	for(size_t i=0;i<mRowNum;i++)
		for(size_t j=0;j<mColNum;j++)
			mData[i*mColNum+j]=rhs.mData[i*mColNum+j];

	return *this;
}

Mat& Mat::plusEqual(const Mat & rhs)
{
	for(size_t i=0;i<mRowNum;i++)
		for(size_t j=0;j<mColNum;j++)
			mData[i*mColNum+j]+=rhs.mData[i*mColNum+j];

	return *this;
}

Mat& Mat::minusEqual(const Mat & rhs)
{
	for(size_t i=0;i<mRowNum;i++)
		for(size_t j=0;j<mColNum;j++)
			mData[i*mColNum+j]-=rhs.mData[i*mColNum+j];

	return *this;
}

Mat& Mat::multiplyEqual(const Mat & rhs)
{
	size_t _mRowNum=mRowNum;
	size_t _mColNum=rhs.mColNum;
	double* _mData=new double[_mRowNum*_mColNum];
	double** _mRow=new double*[_mRowNum];
	for(size_t r=0;r<_mRowNum;r++)
		_mRow[r]=_mData+r*_mColNum;

	for(size_t i=0;i<_mRowNum;i++)
		for(size_t j=0;j<_mColNum;j++)
			{
				_mData[i*_mColNum+j]=0;
				for(size_t k=0;k<rhs.mRowNum;k++)
					_mData[i*_mColNum+j]+=rhs.mData[k*rhs.mColNum+j]*mData[i*rhs.mColNum+k];
			}

	if(mData!=NULL)
		delete []mData;
	if(mRow!=NULL)
		delete []mRow;
	mRowNum=_mRowNum;
	mColNum=_mColNum;
	mRow=_mRow;
	mData=_mData;

	return *this;
}

Mat& Mat::divideEqual(const Mat & rhs)
{
	for(size_t i=0;i<mRowNum;i++)
		for(size_t j=0;j<mColNum;j++)
			mData[i*mColNum+j]/=rhs.mData[i*mColNum+j];

	return *this;
}

Mat& Mat::assign(const double & val)
{
	for(size_t i=0;i<mRowNum;i++)
		for(size_t j=0;j<mColNum;j++)
			mData[i*mColNum+j]=val;

	return *this;
}

Mat& Mat::plusEqual(const double & val)
{
	for(size_t i=0;i<mRowNum;i++)
		for(size_t j=0;j<mColNum;j++)
			mData[i*mColNum+j]+=val;

	return *this;
}

Mat& Mat::minusEqual(const double & val)
{
	for(size_t i=0;i<mRowNum;i++)
		for(size_t j=0;j<mColNum;j++)
				mData[i*mColNum+j]-=val;

	return *this;
}

Mat& Mat::multiplyEqual(const double & val)
{
	for(size_t i=0;i<mRowNum;i++)
		for(size_t j=0;j<mColNum;j++)
			mData[i*mColNum+j]*=val;

	return *this;
}

Mat& Mat::divideEqual(const double & val)
{
	for(size_t i=0;i<mRowNum;i++)
		for(size_t j=0;j<mColNum;j++)
			mData[i*mColNum+j]/=val;

	return *this;
}

Mat Mat::plus(const Mat & rhs)
{
	size_t _mRowNum=mRowNum;
	size_t _mColNum=mColNum;
	double* _mData=new double[_mRowNum*_mColNum];
	double** _mRow=new double*[_mRowNum];
	for(size_t r=0;r<_mRowNum;r++)
		_mRow[r]=_mData+r*_mColNum;

	for(size_t i=0;i<_mRowNum;i++)
		for(size_t j=0;j<_mColNum;j++)
			_mData[i*_mColNum+j]=mData[i*mColNum+j];

	for(size_t i=0;i<_mRowNum;i++)
		for(size_t j=0;j<_mColNum;j++)
			_mData[i*_mColNum+j]+=rhs.mData[i*mColNum+j];

	Mat m;
	m.mRowNum=_mRowNum;
	m.mColNum=_mColNum;
	m.mRow=_mRow;
	m.mData=_mData;
	return m;
}

Mat Mat::minus(const Mat & rhs)
{
	size_t _mRowNum=mRowNum;
	size_t _mColNum=mColNum;
	double* _mData=new double[_mRowNum*_mColNum];
	double** _mRow=new double*[_mRowNum];
	for(size_t r=0;r<_mRowNum;r++)
		_mRow[r]=_mData+r*_mColNum;

	for(size_t i=0;i<_mRowNum;i++)
		for(size_t j=0;j<_mColNum;j++)
			_mData[i*_mColNum+j]=mData[i*mColNum+j];

	for(size_t i=0;i<_mRowNum;i++)
		for(size_t j=0;j<_mColNum;j++)
			_mData[i*_mColNum+j]-=rhs.mData[i*mColNum+j];

	Mat m;
	m.mRowNum=_mRowNum;
	m.mColNum=_mColNum;
	m.mRow=_mRow;
	m.mData=_mData;
	return m;
}

Mat Mat::multiply(const Mat & rhs)
{
	size_t _mRowNum=mRowNum;
	size_t _mColNum=rhs.mColNum;
	double* _mData=new double[_mRowNum*_mColNum];
	double** _mRow=new double*[_mRowNum];
	for(size_t r=0;r<_mRowNum;r++)
		_mRow[r]=_mData+r*_mColNum;

	for(size_t i=0;i<_mRowNum;i++)
		for(size_t j=0;j<_mColNum;j++)
			{
				_mData[i*_mColNum+j]=0;
				for(size_t k=0;k<rhs.mRowNum;k++)
					_mData[i*_mColNum+j]+=rhs.mData[k*rhs.mColNum+j]*mData[i*mColNum+k];
			}

	Mat m;
	m.mRowNum=_mRowNum;
	m.mColNum=_mColNum;
	m.mRow=_mRow;
	m.mData=_mData;
	return m;
}

Mat Mat::divide(const Mat & rhs)
{
	size_t _mRowNum=mRowNum;
	size_t _mColNum=mColNum;
	double* _mData=new double[_mRowNum*_mColNum];
	double** _mRow=new double*[_mRowNum];
	for(size_t r=0;r<_mRowNum;r++)
		_mRow[r]=_mData+r*_mColNum;

	for(size_t i=0;i<_mRowNum;i++)
		for(size_t j=0;j<_mColNum;j++)
			_mData[i*_mColNum+j]=mData[i*mColNum+j];

	for(size_t i=0;i<_mRowNum;i++)
		for(size_t j=0;j<_mColNum;j++)
			_mData[i*_mColNum+j]/=rhs.mData[i*mColNum+j];

	Mat m;
	m.mRowNum=_mRowNum;
	m.mColNum=_mColNum;
	m.mRow=_mRow;
	m.mData=_mData;
	return m;
}

Mat& Mat::transpose()
{
	size_t _mRowNum=mColNum;
	size_t _mColNum=mRowNum;
	double* _mData=new double[_mRowNum*_mColNum];
	double** _mRow=new double*[_mRowNum];
	for(size_t r=0;r<_mRowNum;r++)
		_mRow[r]=_mData+r*_mColNum;

	for(size_t i=0;i<_mRowNum;i++)
		for(size_t j=0;j<_mColNum;j++)
			_mData[i*_mColNum+j]=mData[j*mColNum+i];

	if(mData!=NULL)
		delete []mData;
	if(mRow!=NULL)
		delete []mRow;
	mRowNum=_mRowNum;
	mColNum=_mColNum;
	mRow=_mRow;
	mData=_mData;
	return *this;
}

void Mat::transposeTo(Mat & dstMat) const
{
	size_t _mRowNum=mColNum;
	size_t _mColNum=mRowNum;
	double* _mData=new double[_mRowNum*_mColNum];
	double** _mRow=new double*[_mRowNum];
	for(size_t r=0;r<_mRowNum;r++)
		_mRow[r]=_mData+r*_mColNum;

	for(size_t i=0;i<_mRowNum;i++)
		for(size_t j=0;j<_mColNum;j++)
			_mData[i*_mColNum+j]=mData[j*mColNum+i];

	if(dstMat.mData!=NULL)
		delete []dstMat.mData;
	if(dstMat.mRow!=NULL)
		delete []dstMat.mRow;
	dstMat.mRowNum=_mRowNum;
	dstMat.mColNum=_mColNum;
	dstMat.mData=_mData;
	dstMat.mRow=_mRow;
}

double Mat::norml1() const
{
	double val=0.0;
	for(size_t i=0;i<mRowNum;i++)
		for(size_t j=0;j<mColNum;j++)
			val+=abs(mRow[i][j]);
	return val;
}

double Mat::norml2() const
{
	double val=0.0;
	for(size_t i=0;i<mRowNum;i++)
		for(size_t j=0;j<mColNum;j++)
			val+=mRow[i][j]*mRow[i][j];
	return sqrt(val);
}

Mat& Mat::normalize()
{
	double val=this->norml2();
	for(size_t i=0;i<mRowNum;i++)
		for(size_t j=0;j<mColNum;j++)
			mRow[i][j]/=val;
	return *this;
}

Mat& Mat::fill(const double val)
{
	for(size_t i=0;i<mRowNum;i++)
		for(size_t j=0;j<mColNum;j++)
			mRow[i][j]=val;
	return *this;
}

void Mat::resize(size_t rNum, size_t cNum)
{
	size_t _mRowNum=rNum;
	size_t _mColNum=cNum;
	double* _mData=new double[_mRowNum*_mColNum];
	double** _mRow=new double*[_mRowNum];
	for(size_t r=0;r<_mRowNum;r++)
		_mRow[r]=_mData+r*_mColNum;

	if(mData!=NULL)
		delete []mData;
	if(mRow!=NULL)
		delete []mRow;
	mRowNum=_mRowNum;
	mColNum=_mColNum;
	mRow=_mRow;
	mData=_mData;
}

void Mat::fillMemory(double * pMemory, size_t rNum, size_t cNum)
{
	size_t _mRowNum=rNum;
	size_t _mColNum=cNum;
	double* _mData=new double[_mRowNum*_mColNum];
	double** _mRow=new double*[_mRowNum];
	for(size_t r=0;r<_mRowNum;r++)
		_mRow[r]=_mData+r*_mColNum;

	for(size_t i=0;i<_mRowNum;i++)
		for(size_t j=0;j<_mColNum;j++)
			_mData[i*_mColNum+j]=pMemory[i*_mColNum+j];

	if(mData!=NULL)
		delete []mData;
	if(mRow!=NULL)
		delete []mRow;
	mRowNum=_mRowNum;
	mColNum=_mColNum;
	mRow=_mRow;
	mData=_mData;
}
