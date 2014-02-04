//////////////////////////////////////////////////////////////////////////
//	File:	MatrixFour.h
//	Author:	Terry Nguyen
//	Date:	12/18/2013
//	Brief:	Provides access to MatrixFour for 2D sprite games
//
//////////////////////////////////////////////////////////////////////////

#ifndef _MATRIXFOUR_H_
#define _MATRIXFOUR_H_

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
	class DLLEXPORT Matrix4
	{
	private:

	public:
		Matrix4();
		~Matrix4();

		// 4D Array for Easy Traversal
		//float m_afArray[4][4];

		//For better OpenGL use Column Major Order
		float m_afArray[16];

		// Returns the matrix, but transposed
		Matrix4 Transpose();

		// Returns a point that has been transformed by the Matrix caller
		tbyte::Vector4 PointTransform(const tbyte::Vector4 &a_Point);

		// Assigns & Returns the Identity Matrix for 3x3 to the caller
		Matrix4 MakeIdentityMatrix();

		// Assigns & Returns the Orthographic Project Matrix that was created
		Matrix4 MakeOGLOrthoProjMatrix(float a_fLeft,
									float a_fRight,
									float a_fTop,
									float a_fBottom,
									float a_fFar,
									float a_fNear);

		// Assigns & Returns the Orthographic Project Matrix that was created
		Matrix4 MakeOrthoProjMatrix(float a_fLeft,
									float a_fRight,
									float a_fTop,
									float a_fBottom,
									float a_fFar,
									float a_fNear);

		// Returns a Vector4 that has been scaled by the Matrix caller
		tbyte::Vector4 Scale(const tbyte::Vector4 &a_Vector);
		tbyte::Vector3 Scale(const tbyte::Vector3 &a_Vector);

		// Returns a Transform Matrix4 for rotation around the '_'-axis in radians
		Matrix4 MakeXRotationMatrix(float a_Radians);
		Matrix4 MakeYRotationMatrix(float a_Radians);
		Matrix4 MakeZRotationMatrix(float a_Radians);

		// Returns a Vector4 transformed by the Matrix caller
		tbyte::Vector4 VectorTransform(const tbyte::Vector4 &a_Vector);
		tbyte::Vector3 VectorTransform(const tbyte::Vector3 &a_Vector);

		// Operators (explained by their parameters)
		Matrix4	operator + (const Matrix4 &a_Addend);
		Matrix4	operator + (const float &a_AddendScalar);
		Matrix4 operator += (const Matrix4 &a_Addend);
		Matrix4 operator += (const float &a_AddendScalar);

		Matrix4	operator - (const Matrix4 &a_Subtrahend);
		Matrix4	operator - (const float &a_SubtrahendScalar);
		Matrix4	operator -= (const Matrix4 &a_Subtrahend);
		Matrix4	operator -= (const float &a_SubtrahendScalar);

		Matrix4	operator * (const Matrix4 &a_Factor);
		Matrix4	operator * (const float &a_FactorScalar);
		Matrix4	operator *= (const Matrix4 &a_Factor);
		Matrix4	operator *= (const float &a_FactorScalar);

		Matrix4 operator = (const Matrix4 &a_Source);
		bool	operator == (const Matrix4 &a_Source);


	};
}

#endif