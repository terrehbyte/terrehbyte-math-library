//////////////////////////////////////////////////////////////////////////
//	File:	MatrixThree.h
//	Author:	Terry Nguyen
//	Date:	12/18/2013
//	Brief:	Provides access to MatrixFour for 2D sprite games
//
//////////////////////////////////////////////////////////////////////////

#ifndef _MATRIXTHREE_H_
#define _MATRIXTHREE_H_

#include "VectorThree.h"
#include "VectorFour.h"

#include <cmath>

#ifdef DLL
	#define DLLEXPORT __declspec(dllexport)
#else
	#define DLLEXPORT __declspec(dllimport)
#endif

namespace tbyte
{
	class DLLEXPORT Matrix3
	{
	public:

		Matrix3();
		~Matrix3();

		// 3D Array for Easy Traversal
		//float m_afArray[3][3];

		//For better OpenGL use Column Major Order
		float m_afArray[9];

		// Returns the matrix, but transposed
		Matrix3 Transpose();

		// Returns a point that has been transformed by the Matrix3 caller
		tbyte::Vector4 VectorTransform(const tbyte::Vector4 &a_Point);
		tbyte::Vector3 VectorTransform(const tbyte::Vector3 &a_Point);

		// Assigns & Returns the Identity Matrix for 3x3 to the caller
		Matrix3 MakeIdentityMatrix();

		// Returns the determinant of the matrix
		float GetDeterminant();

		// Returns a Vector4 that has been scaled by the Matrix caller
		tbyte::Vector4 Scale(const tbyte::Vector4 &a_Vector);
		tbyte::Vector3 Scale(const tbyte::Vector3 &a_Vector);

		// Returns a Transform Matrix3 for rotation around the '_'-axis in radians
		Matrix3 MakeXRotationMatrix(float a_Radians);
		Matrix3 MakeYRotationMatrix(float a_Radians);
		Matrix3 MakeZRotationMatrix(float a_Radians);

		// Operators (explained by their parameters)
		Matrix3	operator + (const Matrix3 &a_Addend);
		Matrix3	operator + (const float &a_fAddendScalar);
		Matrix3	operator += (const Matrix3 &a_Addend);
		Matrix3	operator += (const float &a_fAddendScalar);

		Matrix3	operator - (const Matrix3 &a_Subtrahend);
		Matrix3	operator - (const float &a_fSubtrahendScalar);
		Matrix3	operator -= (const Matrix3 &a_Subtrahend);
		Matrix3	operator -= (const float &a_fSubtrahendScalar);

		Matrix3	operator * (const Matrix3 &a_Factor);
		Matrix3	operator * (const float &a_fFactorScalar);
		Matrix3	operator *= (const Matrix3 &a_Factor);
		Matrix3	operator *= (const float &a_fFactorScalar);

		Matrix3 operator = (const Matrix3 &a_Source);
		bool	operator == (const Matrix3 &a_Term);
	};
}

#endif
