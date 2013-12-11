//////////////////////////////////////////////////////////////////////////
//	File:	MatrixFour.h
//	Author:	Terry Nguyen
//	Date:	11/19/2013
//	Brief:	Provides access to MatrixFour for 2D sprite games
//
//////////////////////////////////////////////////////////////////////////

#include "VectorThree.h"
#include "VectorFour.h"

#ifndef _MATRIXFOUR_H_
#define _MATRIXFOUR_H_

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

		float m_afArray[4][4];

		Matrix4 Transpose();

		Vector4::Vector4 PointTransform(const Vector4::Vector4 a_Point);

		Matrix4 MakeIdentityMatrix();
		Vector4::Vector4 Scale(const Vector4::Vector4 a_Vector);

		Matrix4 MakeXRotationMatrix(float a_Radians);
		Matrix4 MakeYRotationMatrix(float a_Radians);
		Matrix4 MakeZRotationMatrix(float a_Radians);

		Vector4::Vector4 VectorTransform(const Vector4::Vector4 a_Vector);

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