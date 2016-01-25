//////////////////////////////////////////////////////////////////////////
//	File:	mat4x4.h  
//	Author:	Terry Nguyen  
//	Date:	01/25/2016
//	Brief:	Contains the class declaration for a Matrix4x4 structure
//
//////////////////////////////////////////////////////////////////////////

#ifndef _MAT4X4_H_
#define _MAT4X4_H_

#include "internal\_compiler.h"

namespace tbyte
{
	struct Vector3;
	struct Vector4;

	struct TBYTELIB Matrix4
	{
	private:

	public:
		Matrix4();

		Matrix4(const float &a_f0,
			const float &a_f1,
			const float &a_f2,
			const float &a_f3,
			const float &a_f4,
			const float &a_f5,
			const float &a_f6,
			const float &a_f7,
			const float &a_f8,
			const float &a_f9,
			const float &a_f10,
			const float &a_f11,
			const float &a_f12,
			const float &a_f13,
			const float &a_f14,
			const float &a_f15);

		Matrix4(const Matrix4 &a_Source);

		~Matrix4();

		//For better OpenGL use Column Major Order
		float m_afArray[16];

		// Transposes the matrix
		void Transpose();

		// Returns a point that has been transformed by the Matrix caller
		tbyte::Vector4 PointTransform(const tbyte::Vector4 &a_Point);

		// Returns the Identity Matrix for 4x4
		static Matrix4 IdentityMatrix();

		// Assigns & Returns the Orthographic Project Matrix that was created
		static Matrix4 MakeOrthoProj(const float &a_fLeft,
			const float &a_fRight,
			const float &a_fTop,
			const float &a_fBottom,
			const float &a_fFar,
			const float &a_fNear,
			Matrix4 * a_Dest = nullptr);

		// Returns a Vector4 that has been scaled by the Matrix caller
		tbyte::Vector4 Scale(const tbyte::Vector4 &a_Vector);
		tbyte::Vector3 Scale(const tbyte::Vector3 &a_Vector);

		// Returns a Transform Matrix4 for rotation around the '_'-axis in radians
		static Matrix4 MakeXRotationMatrix(float a_Radians);
		static Matrix4 MakeYRotationMatrix(float a_Radians);
		static Matrix4 MakeZRotationMatrix(float a_Radians);

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