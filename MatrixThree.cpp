//////////////////////////////////////////////////////////////////////////
//	File:	MatrixThree.cpp
//	Author:	Terry Nguyen
//	Date:	11/05/2013
//	Brief:	Defines functions pertaining to Matrix3
//
//////////////////////////////////////////////////////////////////////////

#include "MatrixThree.h"

namespace Matrix3
{
	Matrix3::Matrix3()
	{
	}

	Matrix3::~Matrix3()
	{
	}

	Matrix3 Matrix3::Transpose()
	{
		// not ready for prime time
		Matrix3 tempMatrix;

		tempMatrix = *this;

		// gap @ [FIRST][0]
		tempMatrix.m_afArray[0][1] = m_afArray[1][0];
		tempMatrix.m_afArray[0][2] = m_afArray[2][0];
		tempMatrix.m_afArray[0][3] = m_afArray[3][0];
		
		// gap @ [FIRST][1]
		tempMatrix.m_afArray[1][0] = m_afArray[0][1];
		tempMatrix.m_afArray[1][2] = m_afArray[2][1];
		tempMatrix.m_afArray[1][3] = m_afArray[3][1];
		
		// gap @ [FIRST][2]
		tempMatrix.m_afArray[2][0] = m_afArray[0][2];
		tempMatrix.m_afArray[2][1] = m_afArray[1][2];
		tempMatrix.m_afArray[2][3] = m_afArray[3][2];
		
		// gap @ [FIRST][3]
		tempMatrix.m_afArray[3][0] = m_afArray[0][3];
		tempMatrix.m_afArray[3][1] = m_afArray[1][3];
		tempMatrix.m_afArray[3][2] = m_afArray[2][3];

		return tempMatrix;
	}

	Matrix3 Matrix3::Scale(const float a_fFactorScalar)
	{
		Matrix3 tempMatrix = *this;

		for (int iRow = 0;
			iRow <= 2;
			iRow++)
		{
			for (int iCol = 0;
				iCol <= 2;
				iCol++)
			{
				tempMatrix.m_afArray[iRow][iCol] *= a_fFactorScalar;
			}
		}

		return tempMatrix;
	}

	Matrix3 Matrix3::operator+ (const Matrix3 a_Addend)
	{
		Matrix3 tempMatrix = *this;

		for (int iRow = 0;
			iRow <= 2;
			iRow++)
		{
			for (int iCol = 0;
				iCol <= 2;
				iCol++)
			{
				tempMatrix.m_afArray[iRow][iCol] += a_Addend.m_afArray[iRow][iCol];
			}
		}

		return tempMatrix;
	}

	Matrix3 Matrix3::operator+ (const float a_fAddendScalar)
	{
		Matrix3 tempMatrix = *this;

		for (int iRow = 0;
			iRow <= 2;
			iRow++)
		{
			for (int iCol = 0;
				iCol <= 2;
				iCol++)
			{
				tempMatrix.m_afArray[iRow][iCol] += a_fAddendScalar;
			}
		}

		return tempMatrix;
	}

	// ISSUE! += doesn't return the added value.
	// Try seeing http://courses.cms.caltech.edu/cs11/material/cpp/donnie/cpp-ops.html
	Matrix3 Matrix3::operator+= (const Matrix3 a_Addend)
	{
		(*this) = (*this) + a_Addend;
		return (*this);
	}

	Matrix3 Matrix3::operator+= (const float a_fAddendScalar)
	{
		(*this) = (*this) + a_fAddendScalar;
		return (*this);
	}

	Matrix3 Matrix3::operator- (const Matrix3 a_Subtrahend)
	{
		Matrix3 tempMatrix = *this;

		for (int iRow = 0;
			iRow <= 2;
			iRow++)
		{
			for (int iCol = 0;
				iCol <= 2;
				iCol++)
			{
				tempMatrix.m_afArray[iRow][iCol] -= a_Subtrahend.m_afArray[iRow][iCol];
			}
		}

		return tempMatrix;
	}

	Matrix3 Matrix3::operator- (const float a_fSubtrahendScalar)
	{
		Matrix3 tempMatrix = *this;

		for (int iRow = 0;
			iRow <= 2;
			iRow++)
		{
			for (int iCol = 0;
				iCol <= 2;
				iCol++)
			{
				tempMatrix.m_afArray[iRow][iCol] -= a_fSubtrahendScalar;
			}
		}

		return tempMatrix;
	}

	Matrix3 Matrix3::operator-= (const Matrix3 a_Subtrahend)
	{
		(*this) =  (*this) - a_Subtrahend;
		return (*this);
	}

	Matrix3 Matrix3::operator-= (const float a_fSubtrahendScalar)
	{
		(*this) = (*this) - a_fSubtrahendScalar;
		return (*this);
	}

	Matrix3	Matrix3::operator * (const Matrix3 a_Factor)
	{
		Matrix3 tempMatrix;

		tempMatrix.m_afArray[0][0] =	m_afArray[0][0] * a_Factor.m_afArray[0][0] +
										m_afArray[0][1] * a_Factor.m_afArray[1][0] +
										m_afArray[0][2] * a_Factor.m_afArray[2][0];

		tempMatrix.m_afArray[0][1] =	m_afArray[0][0] * a_Factor.m_afArray[0][1] +
										m_afArray[0][1] * a_Factor.m_afArray[1][1] +
										m_afArray[0][2] * a_Factor.m_afArray[2][1];
		
		tempMatrix.m_afArray[0][2] =	m_afArray[0][0] * a_Factor.m_afArray[0][2] +
										m_afArray[0][1] * a_Factor.m_afArray[1][2] +
										m_afArray[0][2] * a_Factor.m_afArray[2][2];


		tempMatrix.m_afArray[1][0] =	m_afArray[1][0] * a_Factor.m_afArray[0][0] +
										m_afArray[1][1] * a_Factor.m_afArray[1][0] +
										m_afArray[1][2] * a_Factor.m_afArray[2][0];

		tempMatrix.m_afArray[1][1] =	m_afArray[1][0] * a_Factor.m_afArray[0][1] +
										m_afArray[1][1] * a_Factor.m_afArray[1][1] +
										m_afArray[1][2] * a_Factor.m_afArray[2][1];

		tempMatrix.m_afArray[1][2] =	m_afArray[1][0] * a_Factor.m_afArray[0][2] +
										m_afArray[1][1] * a_Factor.m_afArray[1][2] + 
										m_afArray[1][2] * a_Factor.m_afArray[2][2];

		tempMatrix.m_afArray[2][0] =	m_afArray[2][0] * a_Factor.m_afArray[0][0] +
										m_afArray[2][1] * a_Factor.m_afArray[1][0] +
										m_afArray[2][2] * a_Factor.m_afArray[2][0];

		tempMatrix.m_afArray[2][1] =	m_afArray[2][0] * a_Factor.m_afArray[0][1] +
										m_afArray[2][1] * a_Factor.m_afArray[1][1] +
										m_afArray[2][2] * a_Factor.m_afArray[2][1];
		
		tempMatrix.m_afArray[2][2] =	m_afArray[2][0] * a_Factor.m_afArray[0][2] +
										m_afArray[2][1] * a_Factor.m_afArray[1][2] +
										m_afArray[2][2] * a_Factor.m_afArray[2][2];

		return tempMatrix;
	}

	Matrix3	Matrix3::operator * (const float a_fFactorScalar)
	{
		Matrix3 tempMatrix = *this;

		for (int iRow = 0;
			iRow <= 2;
			iRow++)
		{
			for (int iCol = 0;
				iCol <= 2;
				iCol++)
			{
				tempMatrix.m_afArray[iRow][iCol] *= a_fFactorScalar;
			}
		}


		return tempMatrix;
	}

	Matrix3 Matrix3::operator = (const Matrix3 a_Source)
	{
		for (int iCol = 0;
			 iCol <= 2;
			 iCol++)
		{
			for (int iRow = 0;
				iRow <= 2;
				iRow++)
			{
				m_afArray[iCol][iRow] = a_Source.m_afArray[iCol][iRow];
			}
		}

		return *this;
	}

	Matrix3 Matrix3::operator*= (const Matrix3 a_Factor)
	{
		(*this) = (*this) * a_Factor;
		return (*this);
	}

	Matrix3 Matrix3::operator*= (const float a_FactorScalar)
	{
		(*this) = (*this) * a_FactorScalar;
		return (*this);
	}

	bool Matrix3::operator == (const Matrix3 a_Source)
	{
		for (int iCol = 0;
			 iCol <= 2;
			 iCol++)
		{
			for (int iRow = 0;
				iRow <= 2;
				iRow++)
			{
				if (m_afArray[iCol][iRow] != a_Source.m_afArray[iCol][iRow])
				{
					return false;
				}
			}
		}

		return true;
	}
}
