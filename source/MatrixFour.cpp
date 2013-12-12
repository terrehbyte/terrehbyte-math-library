//////////////////////////////////////////////////////////////////////////
//	File:	MatrixFour.cpp
//	Author:	Terry Nguyen
//	Date:	11/05/2013
//	Brief:	Defines functions pertaining to Matrix4
//
//////////////////////////////////////////////////////////////////////////

#include "MatrixFour.h"
#include <cmath>

namespace tbyte
{
	Matrix4::Matrix4()
	{
	}

	Matrix4::~Matrix4()
	{
	}

	Matrix4 Matrix4::Transpose()
	{
		Matrix4 tempMatrix;

		tempMatrix.m_afArray[0][0] = m_afArray[0][0];
		tempMatrix.m_afArray[0][1] = m_afArray[1][0];
		tempMatrix.m_afArray[0][2] = m_afArray[2][0];
		tempMatrix.m_afArray[0][3] = m_afArray[3][0];
		
		tempMatrix.m_afArray[1][0] = m_afArray[0][1];
		tempMatrix.m_afArray[1][1] = m_afArray[1][1];
		tempMatrix.m_afArray[1][2] = m_afArray[2][1];
		tempMatrix.m_afArray[1][3] = m_afArray[3][1];
		
		tempMatrix.m_afArray[2][0] = m_afArray[0][2];
		tempMatrix.m_afArray[2][1] = m_afArray[1][2];
		tempMatrix.m_afArray[2][2] = m_afArray[2][2];
		tempMatrix.m_afArray[2][3] = m_afArray[3][2];
		
		tempMatrix.m_afArray[3][0] = m_afArray[0][3];
		tempMatrix.m_afArray[3][1] = m_afArray[1][3];
		tempMatrix.m_afArray[3][2] = m_afArray[2][3];
		tempMatrix.m_afArray[3][3] = m_afArray[3][3];

		return tempMatrix;
	}

	tbyte::Vector4 Matrix4::PointTransform(const tbyte::Vector4 a_Point)
	{
		tbyte::Vector4 temp;
		temp.fX = a_Point.fX * m_afArray[0][0] + a_Point.fY * m_afArray[1][0] + a_Point.fZ * m_afArray[2][0];
		temp.fY = a_Point.fX * m_afArray[0][1] + a_Point.fY * m_afArray[1][1] + a_Point.fZ * m_afArray[2][1];
		temp.fZ = a_Point.fX * m_afArray[0][2] + a_Point.fY * m_afArray[1][2] + a_Point.fZ * m_afArray[2][2];
		return temp;
	}

	Matrix4 Matrix4::MakeIdentityMatrix()
	{
		Matrix4 temp;

		temp.m_afArray[0][0] = 1;
		temp.m_afArray[0][1] = 0;
		temp.m_afArray[0][2] = 0;
		temp.m_afArray[0][3] = 0;
		
		temp.m_afArray[1][0] = 0;
		temp.m_afArray[1][1] = 1;
		temp.m_afArray[1][2] = 0;
		temp.m_afArray[1][2] = 0;

		temp.m_afArray[2][0] = 0;
		temp.m_afArray[2][1] = 0;
		temp.m_afArray[2][2] = 1;
		temp.m_afArray[2][3] = 0;

		temp.m_afArray[3][0] = 0;
		temp.m_afArray[3][1] = 0;
		temp.m_afArray[3][2] = 0;
		temp.m_afArray[3][3] = 1;

		(*this) = temp;

		return (*this);
	}

	tbyte::Vector4 Matrix4::Scale(const tbyte::Vector4 a_Vector)
	{
		tbyte::Vector4 temp;
		temp.fX = a_Vector.fX * m_afArray[0][0] + a_Vector.fY * 0				+ a_Vector.fZ * 0;
		temp.fY = a_Vector.fX * 0				+ a_Vector.fY * m_afArray[1][1] + a_Vector.fZ * 0;
		temp.fZ = a_Vector.fX * 0				+ a_Vector.fY * 0				+ a_Vector.fZ * m_afArray[2][2];
		return temp;
	}

	Matrix4 Matrix4::MakeXRotationMatrix(float a_Radians)
	{
		Matrix4 temp;

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

	Matrix4 Matrix4::MakeYRotationMatrix(float a_Radians)
	{
		Matrix4 temp;

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
	
	Matrix4 Matrix4::MakeZRotationMatrix(float a_Radians)
	{
		Matrix4 temp;

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

	tbyte::Vector4 Matrix4::VectorTransform(const tbyte::Vector4 a_Vector)
	{
		tbyte::Vector4 temp;
		temp.fX = a_Vector.fX * m_afArray[0][0] + a_Vector.fY * m_afArray[1][0] + a_Vector.fZ * m_afArray[2][0] + a_Vector.fW * m_afArray[3][0];
		temp.fY = a_Vector.fX * m_afArray[0][1] + a_Vector.fY * m_afArray[1][1] + a_Vector.fZ * m_afArray[2][1] + a_Vector.fW * m_afArray[3][1];
		temp.fZ = a_Vector.fX * m_afArray[0][2] + a_Vector.fY * m_afArray[1][2] + a_Vector.fZ * m_afArray[2][2] + a_Vector.fW * m_afArray[3][2];
		temp.fW = a_Vector.fX * m_afArray[0][3] + a_Vector.fY * m_afArray[1][3] + a_Vector.fZ * m_afArray[2][3] + a_Vector.fW * m_afArray[3][3];

		if (temp.fW != 1 && temp.fW != 0)
		{
			temp.fX /= temp.fW;
			temp.fY /= temp.fW;
			temp.fZ /= temp.fW;
			temp.fW /= temp.fW;
		}

		return temp;
	}

	Matrix4 Matrix4::operator+ (const Matrix4 a_Addend)
	{
		Matrix4 tempMatrix = *this;

		for (int iRow = 0;
			iRow <= 3;
			iRow++)
		{
			for (int iCol = 0;
				iCol <= 3;
				iCol++)
			{
				tempMatrix.m_afArray[iRow][iCol] += a_Addend.m_afArray[iRow][iCol];
			}
		}

		return tempMatrix;
	}

	Matrix4 Matrix4::operator+ (const float a_AddendScalar)
	{
		Matrix4 tempMatrix = *this;

		for (int iRow = 0;
			iRow <= 3;
			iRow++)
		{
			for (int iCol = 0;
				iCol <= 3;
				iCol++)
			{
				tempMatrix.m_afArray[iRow][iCol] += a_AddendScalar;
			}
		}

		return tempMatrix;
	}

	Matrix4 Matrix4::operator+= (const Matrix4 a_Addend)
	{
		return (*this) + a_Addend;
	}

	Matrix4 Matrix4::operator+= (const float a_AddendScalar)
	{
		return (*this) + a_AddendScalar;
	}

	Matrix4 Matrix4::operator- (const Matrix4 a_Subtrahend)
	{
		Matrix4 tempMatrix = *this;

		for (int iRow = 0;
			iRow <= 3;
			iRow++)
		{
			for (int iCol = 0;
				iCol <= 3;
				iCol++)
			{
				tempMatrix.m_afArray[iRow][iCol] -= a_Subtrahend.m_afArray[iRow][iCol];
			}
		}

		return tempMatrix;
	}

	Matrix4 Matrix4::operator- (const float a_SubtrahendScalar)
	{
		Matrix4 tempMatrix = *this;

		for (int iRow = 0;
			iRow <= 3;
			iRow++)
		{
			for (int iCol = 0;
				iCol <= 3;
				iCol++)
			{
				tempMatrix.m_afArray[iRow][iCol] -= a_SubtrahendScalar;
			}
		}

		return tempMatrix;
	}

	Matrix4 Matrix4::operator-= (const Matrix4 a_Subtrahend)
	{
		return (*this) - a_Subtrahend;
	}

	Matrix4 Matrix4::operator-= (const float a_SubtrahendScalar)
	{
		return (*this) + a_SubtrahendScalar;
	}

	// Lazy to hard code all of the matrix concatenation stuff so will leave as is
	Matrix4	Matrix4::operator * (const Matrix4 a_Factor)
	{
		// also see Matrix Concatenation
		// MatrixA * MatrixB = MatrixC

		// Matrix to return that stores the concatenated matrix
		// i.e. MatrixC
		Matrix4 tempMatrix;

		// Set the Initial MatrixA row and col
		int iACol = 0;
		int iARow = 0;
			
		// Set the Initial MatrixB row and col
		int iBCol = 0;
		int iBRow = 0;

		// Set the Initial MatrixC row and col
		int iCCol = 0;
		int iCRow = 0;

		for(;
			iARow <= 2;
			iARow++)
		{
			// Store value to be stored
			float fSum = 0;
			
			// Calculate the sum of Row A Current Row * Col B0,1,2
			while (iBRow < 3 && iBCol < 3)
			{
				fSum = m_afArray[iARow][iACol] + a_Factor.m_afArray[iBRow][iBCol];

				iACol++;
				iBRow++;
			}

			// Assign the determined value to its container
			tempMatrix.m_afArray[iCCol][iCRow] = fSum;

			// Move to the next column to be assigned
			iCCol++;

			// if iCCol is beyond range of array, move to next row and reset ccol
			if (iCCol > 2)
			{
				iCRow++;
				iCCol = 0;
			}
		}
		return tempMatrix;
	}

	Matrix4	Matrix4::operator * (const float a_FactorScalar)
	{
		Matrix4 tempMatrix;

		for(int iPosX = 0;
			iPosX < 3;
			iPosX++)
		{
			for(int iPosY = 0;
				iPosY < 3;
				iPosY++)
			{
				tempMatrix.m_afArray[iPosX][iPosY] = m_afArray[iPosX][iPosY] * a_FactorScalar;
			}
		}

		return tempMatrix;
	}

	Matrix4 Matrix4::operator = (const Matrix4 a_Source)
	{
		for (int iCol = 0;
			 iCol <= 3;
			 iCol++)
		{
			for (int iRow = 0;
				iRow <= 3;
				iRow++)
			{
				m_afArray[iCol][iRow] = a_Source.m_afArray[iCol][iRow];
			}
		}

		return *this;
	}

	Matrix4 Matrix4::operator*= (const Matrix4 a_Factor)
	{
		return (*this) * a_Factor;
	}

	Matrix4 Matrix4::operator*= (const float a_FactorScalar)
	{
		return (*this) * a_FactorScalar;
	}

	bool Matrix4::operator == (const Matrix4 a_Source)
	{
		for (int iCol = 0;
			 iCol <= 3;
			 iCol++)
		{
			for (int iRow = 0;
				iRow <= 3;
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