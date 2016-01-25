//////////////////////////////////////////////////////////////////////////
//	File:	mat3x3.h  
//	Author:	Terry Nguyen  
//	Date:	01/25/2016
//	Brief:	Contains the class declaration for a Matrix3x3 structure
//
//////////////////////////////////////////////////////////////////////////

#ifndef _MAT3X3_H_
#define _MAT3X3_H_

#include "internal\_compiler.h"

namespace tbyte
{
	struct Vector4;
	struct Vector3;

	struct TBYTELIB Matrix3
	{
	public:

		Matrix3();

		Matrix3(const float &a_f0,
			const float &a_f1,
			const float &a_f2,
			const float &a_f3,
			const float &a_f4,
			const float &a_f5,
			const float &a_f6,
			const float &a_f7,
			const float &a_f8);


		Matrix3(const Matrix3 &a_Source);

		~Matrix3();


		//For better OpenGL use Column Major Order
		float m_afArray[9];

		// Transposes the matrix
		void Transpose();

		// Returns a point that has been transformed by the Matrix3 caller
		tbyte::Vector4 VectorTransform(const tbyte::Vector4 &a_Point);
		tbyte::Vector3 VectorTransform(const tbyte::Vector3 &a_Point);

		// Returns the Identity Matrix for 3x3
		static Matrix3 IdentityMatrix();

		// Returns a Vector4 that has been scaled by the Matrix caller
		tbyte::Vector4 Scale(const tbyte::Vector4 &a_Vector);
		tbyte::Vector3 Scale(const tbyte::Vector3 &a_Vector);

		// Returns a Transform Matrix3 for rotation around the '_'-axis in radians
		static Matrix3 MakeXRotationMatrix(float a_Radians);
		static Matrix3 MakeYRotationMatrix(float a_Radians);
		static Matrix3 MakeZRotationMatrix(float a_Radians);

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