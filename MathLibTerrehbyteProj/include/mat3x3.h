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
#include "vec2.h"
#include "vec3.h"

namespace tbyte
{
	struct Vector4;
	struct Vector3;
	struct Vector2;

	struct TBYTELIB Matrix3
	{
	public:

		Matrix3();
		Matrix3(const Matrix3 &a_Source);
		~Matrix3();

		// our data is column major
		//   - in the 1D array, every three values forms a column
		union
		{
			float m_afArray[9];
			Vector3 c[3];
		};

		// Transposes the matrix
		void Transpose();

		static Matrix3 IdentityMatrix();
		static Matrix3 Translate(Vector2 move);
		static Matrix3 MakeRotationMatrix(float a_Radians);

		Matrix3		operator +	(const Matrix3	&a_Addend);
		Matrix3		operator +	(const float	&a_fAddendScalar);
		Matrix3&	operator += (const Matrix3	&a_Addend);
		Matrix3&	operator += (const float	&a_fAddendScalar);

		Matrix3		operator -	(const Matrix3	&a_Subtrahend);
		Matrix3		operator -	(const float	&a_fSubtrahendScalar);
		Matrix3&	operator -= (const Matrix3	&a_Subtrahend);
		Matrix3&	operator -= (const float	&a_fSubtrahendScalar);

		Matrix3		operator *	(const Matrix3	&a_Factor);
		Matrix3		operator *	(const float	&a_fFactorScalar);
		Matrix3&	operator *= (const Matrix3	&a_Factor);
		Matrix3&	operator *= (const float	&a_fFactorScalar);

		Matrix3&	operator =	(const Matrix3	&a_Source);
		bool		operator == (const Matrix3	&a_Term);
	};
}

#endif