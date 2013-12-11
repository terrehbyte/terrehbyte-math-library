//////////////////////////////////////////////////////////////////////////
//	File:	MatrixFour.h
//	Author:	Terry Nguyen
//	Date:	12/11/2013
//	Brief:	Provides access to MatrixFour for 2D sprite games
//
//////////////////////////////////////////////////////////////////////////

#ifndef _MATRIXFOUR_H_
#define _MATRIXFOUR_H_

#include "VectorThree.h"
#include "VectorFour.h"

#ifdef DLL
	#define DLLEXPORT __declspec(dllexport)
#else
	#define DLLEXPORT __declspec(dllimport)
#endif

namespace Matrix4
{
	class DLLEXPORT Matrix4
	{
	private:

	public:
		Matrix4();
		~Matrix4();

		// 4D Array for Easy Traversal
		float m_afArray[4][4];

		Matrix4 Transpose();

		// Returns a point that has been transformed by the Matrix caller
		Vector4::Vector4 PointTransform(const Vector4::Vector4 a_Point);

		// Assigns & Returns the Identity Matrix for 3x3 to the caller
		Matrix4 MakeIdentityMatrix();

		// Returns a Vector4 that has been scaled by the Matrix caller
		Vector4::Vector4 Scale(const Vector4::Vector4 a_Vector);

		// Returns a Transform Matrix4 for rotation around the '_'-axis in radians
		Matrix4 MakeXRotationMatrix(float a_Radians);
		Matrix4 MakeYRotationMatrix(float a_Radians);
		Matrix4 MakeZRotationMatrix(float a_Radians);

		// Returns a Vector4 transformed by the Matrix caller
		Vector4::Vector4 VectorTransform(const Vector4::Vector4 a_Vector);

		// Operators (explained by their parameters)
		Matrix4	operator + (const Matrix4 a_Addend);
		Matrix4	operator + (const float a_AddendScalar);
		Matrix4 operator += (const Matrix4 a_Addend);
		Matrix4 operator += (const float a_AddendScalar);

		Matrix4	operator - (const Matrix4 a_Subtrahend);
		Matrix4	operator - (const float a_SubtrahendScalar);
		Matrix4	operator -= (const Matrix4 a_Subtrahend);
		Matrix4	operator -= (const float a_SubtrahendScalar);

		Matrix4	operator * (const Matrix4 a_Factor);
		Matrix4	operator * (const float a_FactorScalar);
		Matrix4	operator *= (const Matrix4 a_Factor);
		Matrix4	operator *= (const float a_FactorScalar);

		Matrix4 operator = (const Matrix4 a_Source);
		bool	operator == (const Matrix4 a_Source);
	};
}

#endif