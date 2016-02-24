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

#include "vec3.h"

namespace tbyte
{
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

		union
		{
			float m_afArray[9];
			Vector3 cols[3];
		};

		// Transposes the matrix
		void Transpose();

		// Returns the Identity Matrix for 3x3
		static Matrix3 IdentityMatrix();

		// Returns a Transform Matrix3 for rotation around the '_'-axis in radians
		static Matrix3 MakeXRotationMatrix(float a_Radians);
		static Matrix3 MakeYRotationMatrix(float a_Radians);
		static Matrix3 MakeZRotationMatrix(float a_Radians);

		static Matrix3 MakeScaleMatrix(float a_xScale, float a_yScale);

		static float Determinant();

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