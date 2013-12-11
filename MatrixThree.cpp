//////////////////////////////////////////////////////////////////////////
//	File:	MatrixThree.cpp
//	Author:	Terry Nguyen
//	Date:	11/05/2013
//	Brief:	Defines functions pertaining to Matrix3
//
//////////////////////////////////////////////////////////////////////////

#include "MatrixThree.h"
#include <cmath>

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
		Matrix3 tempMatrix;

		tempMatrix.m_afArray[0][0] = m_afArray[0][0];
		tempMatrix.m_afArray[0][1] = m_afArray[1][0];
		tempMatrix.m_afArray[0][2] = m_afArray[2][0];
		
		tempMatrix.m_afArray[1][0] = m_afArray[0][1];
		tempMatrix.m_afArray[1][1] = m_afArray[1][1];
		tempMatrix.m_afArray[1][2] = m_afArray[2][1];

		tempMatrix.m_afArray[2][0] = m_afArray[0][2];
		tempMatrix.m_afArray[2][1] = m_afArray[1][2];
		tempMatrix.m_afArray[2][2] = m_afArray[2][2];

		return tempMatrix;
	}

	Vector4::Vector4 Matrix3::PointTransform(const Vector4::Vector4 a_Point)
	{
		Vector4::Vector4 temp;
		temp.fX = a_Point.fX * m_afArray[0][0] + a_Point.fY * m_afArray[1][0] + a_Point.fZ * m_afArray[2][0];
		temp.fY = a_Point.fX * m_afArray[0][1] + a_Point.fY * m_afArray[1][1] + a_Point.fZ * m_afArray[2][1];
		temp.fZ = a_Point.fX * m_afArray[0][2] + a_Point.fY * m_afArray[1][2] + a_Point.fZ * m_afArray[2][2];
		return temp;
	}

	Matrix3 Matrix3::MakeIdentityMatrix()
	{
		Matrix3 temp;

		temp.m_afArray[0][0] = 1;
		temp.m_afArray[0][1] = 0;
		temp.m_afArray[0][2] = 0;
		
		temp.m_afArray[1][0] = 0;
		temp.m_afArray[1][1] = 1;
		temp.m_afArray[1][2] = 0;

		temp.m_afArray[2][0] = 0;
		temp.m_afArray[2][1] = 0;
		temp.m_afArray[2][2] = 1;

		(*this) = temp;

		return (*this);
	}

	Vector4::Vector4 Matrix3::Scale(const Vector4::Vector4 a_Vector)
	{
		Vector4::Vector4 temp;
		temp.fX = a_Vector.fX * m_afArray[0][0] + a_Vector.fY * 0				+ a_Vector.fZ * 0;
		temp.fY = a_Vector.fX * 0				+ a_Vector.fY * m_afArray[1][1] + a_Vector.fZ * 0;
		temp.fZ = a_Vector.fX * 0				+ a_Vector.fY * 0				+ a_Vector.fZ * m_afArray[2][2];
		return temp;
	}

	Matrix3 Matrix3::MakeXRotationMatrix(float a_Radians)
	{
		Matrix3 temp;

		temp.m_afArray[0][0] = 1;
		temp.m_afArray[0][1] = 0;
		temp.m_afArray[0][2] = 0;
		
		temp.m_afArray[1][0] = 0;
		temp.m_afArray[1][1] = std::cos(a_Radians);
		temp.m_afArray[1][2] = std::sin(a_Radians);

		temp.m_afArray[2][0] = 0;
		temp.m_afArray[2][1] = std::sin(a_Radians) * -1;
		temp.m_afArray[2][2] = std::cos(a_Radians);

		(*this) = temp;

		return (*this);
	}
	
	Matrix3 Matrix3::MakeYRotationMatrix(float a_Radians)
	{
		Matrix3 temp;

		temp.m_afArray[0][0] = std::cos(a_Radians);
		temp.m_afArray[0][1] = 0;
		temp.m_afArray[0][2] = std::sin(a_Radians) * -1;
		
		temp.m_afArray[1][0] = 0;
		temp.m_afArray[1][1] = 1;
		temp.m_afArray[1][2] = 0;

		temp.m_afArray[2][0] = std::sin(a_Radians);
		temp.m_afArray[2][1] = 0;
		temp.m_afArray[2][2] = std::cos(a_Radians);

		(*this) = temp;

		return (*this);
	}
	
	Matrix3 Matrix3::MakeZRotationMatrix(float a_Radians)
	{
		Matrix3 temp;

		temp.m_afArray[0][0] = std::cos(a_Radians);
		temp.m_afArray[0][1] = std::sin(a_Radians);
		temp.m_afArray[0][2] = 0;
		
		temp.m_afArray[1][0] = std::sin(a_Radians) * -1;
		temp.m_afArray[1][1] = std::cos(a_Radians);
		temp.m_afArray[1][2] = 0;

		temp.m_afArray[2][0] = 0;
		temp.m_afArray[2][1] = 0;
		temp.m_afArray[2][2] = 1;

		(*this) = temp;

		return (*this);
	}


	// OPERATORS
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
