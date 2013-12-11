//////////////////////////////////////////////////////////////////////////
//	File:	MatrixThree.h
//	Author:	Terry Nguyen
//	Date:	11/19/2013
//	Brief:	Provides access to MatrixFour for 2D sprite games
//
//////////////////////////////////////////////////////////////////////////

#ifndef _MATRIXTHREE_H_
#define _MATRIXTHREE_H_

#include "VectorThree.h"
#include "VectorFour.h"

#ifdef DLL
	#define DLLEXPORT __declspec(dllexport)
#else
	#define DLLEXPORT __declspec(dllimport)
#endif

namespace Matrix3
{
	class DLLEXPORT Matrix3
	{
	public:

		Matrix3();
		~Matrix3();

		float m_afArray[3][3];

		Matrix3 Transpose();

		Matrix3 MakeIdentityMatrix();

		Matrix3 MakeXRotationMatrix(float a_Radians);
		Matrix3 MakeYRotationMatrix(float a_Radians);
		Matrix3 MakeZRotationMatrix(float a_Radians);

		Vector4::Vector4 Scale(const Vector4::Vector4 a_Vector);

		Vector4::Vector4 PointTransform(const Vector4::Vector4 a_Point);
		//Vector4::Vector4 VectorTransform(const Vector4::Vector4 a_Vector);

		Matrix3	operator + (const Matrix3 a_Addend);
		Matrix3	operator + (const float a_fAddendScalar);
		Matrix3	operator += (const Matrix3 a_Addend);
		Matrix3	operator += (const float a_fAddendScalar);

		Matrix3	operator - (const Matrix3 a_Subtrahend);
		Matrix3	operator - (const float a_fSubtrahendScalar);
		Matrix3	operator -= (const Matrix3 a_Subtrahend);
		Matrix3	operator -= (const float a_fSubtrahendScalar);

		Matrix3	operator * (const Matrix3 a_Factor);
		Matrix3	operator * (const float a_fFactorScalar);
		Matrix3	operator *= (const Matrix3 a_Factor);
		Matrix3	operator *= (const float a_fFactorScalar);

		Matrix3 operator = (const Matrix3 a_Source);
		bool	operator == (const Matrix3 a_Term);
	};
}

#endif
