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
		Matrix3 tempMatrix;

		for(int iPosX = 0;
			iPosX < 3;
			iPosX++)
		{
			for(int iPosY = 0;
				iPosY < 3;
				iPosY++)
			{
				tempMatrix.m_afArray[iPosX][iPosY] = m_afArray[iPosY][iPosX];
			}
		}

		return tempMatrix;
	}

	Matrix3 Matrix3::operator+ (const Matrix3 a_Addend)
	{
		Matrix3 tempMatrix;

		for(int iPosX = 0;
			iPosX < 3;
			iPosX++)
		{
			for(int iPosY = 0;
				iPosY < 3;
				iPosY++)
			{
				tempMatrix.m_afArray[iPosX][iPosY] = m_afArray[iPosX][iPosY] + a_Addend.m_afArray[iPosX][iPosY];
			}
		}

		return tempMatrix;
	}

	Matrix3 Matrix3::operator+ (const float a_AddendScalar)
	{
		Matrix3 tempMatrix;

		for(int iPosX = 0;
			iPosX < 3;
			iPosX++)
		{
			for(int iPosY = 0;
				iPosY < 3;
				iPosY++)
			{
				tempMatrix.m_afArray[iPosX][iPosY] = m_afArray[iPosX][iPosY] + a_AddendScalar;
			}
		}

		return tempMatrix;
	}

	Matrix3 Matrix3::operator- (const Matrix3 a_Subtrahend)
	{
		Matrix3 tempMatrix;

		for(int iPosX = 0;
			iPosX < 3;
			iPosX++)
		{
			for(int iPosY = 0;
				iPosY < 3;
				iPosY++)
			{
				tempMatrix.m_afArray[iPosX][iPosY] = m_afArray[iPosX][iPosY] - a_Subtrahend.m_afArray[iPosX][iPosY];
			}
		}

		return tempMatrix;
	}

	Matrix3 Matrix3::operator- (const float a_SubtrahendScalar)
	{
		Matrix3 tempMatrix;

		for(int iPosX = 0;
			iPosX < 3;
			iPosX++)
		{
			for(int iPosY = 0;
				iPosY < 3;
				iPosY++)
			{
				tempMatrix.m_afArray[iPosX][iPosY] = m_afArray[iPosX][iPosY] + a_SubtrahendScalar;
			}
		}

		return tempMatrix;
	}

	Matrix3	Matrix3::operator * (const Matrix3 a_Factor)
	{
		// also see Matrix Concatenation
		// MatrixA * MatrixB = MatrixC

		// Matrix to return that stores the concatenated matrix
		// i.e. MatrixC
		Matrix3 tempMatrix;

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

	Matrix3	Matrix3::operator * (const float a_FactorScalar)
	{
		Matrix3 tempMatrix;

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
}