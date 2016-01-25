//////////////////////////////////////////////////////////////////////////
//	File:	vec2.h  
//	Author:	Terry Nguyen  
//	Date:	01/25/2016
//	Brief:	Contains the class declaration for a Vector2 structure
//
//////////////////////////////////////////////////////////////////////////

#ifndef _VEC2_H_
#define _VEC2_H_

#include "internal\_compiler.h"

namespace tbyte
{
	struct TBYTELIB Vector2
	{
	public:
		Vector2();

		Vector2(const float &a_fX, const float &a_fY);

		Vector2(const Vector2 &a_Source);

		~Vector2();

		float	m_fX;
		float	m_fY;

		// Get Euler Angle Between Two Vectors
		float EulerAngle(const Vector2 &a_Term);

		// Returns the Dot Product between the caller and the Vector2 term
		float	DotProduct(const Vector2 &a_Term);

		// Return what the caller would be when normalized
		Vector2	Normal();
		void Normalise();
		// Return the magnitude of the Vector
		float	Magnitude();

		// Return linearly interpolated vector
		Vector2 Lerp(const Vector2 &a_TerminatingVector, const float &a_fInterpolationPoint);

		// Operators overloaded - see parameters
		Vector2	operator + (const Vector2 &a_Addend);
		Vector2	operator + (const float &a_fAddendScalar);
		Vector2	operator += (const Vector2 &a_Addend);
		Vector2 operator += (const float &a_fAddendScalar);

		Vector2 operator - (const Vector2 &a_Subtrahend);
		Vector2 operator - (const float &a_fSubtrahendScalar);
		Vector2 operator -= (const Vector2 &a_Addend);
		Vector2 operator -= (const float &a_fSubtrahendScalar);

		Vector2 operator * (const float &a_fScalar);
		Vector2 operator *= (const float &a_fScalar);

		Vector2 operator / (const float &a_fScalar);
		Vector2 operator /= (const float &a_fScalar);

		Vector2	operator = (const Vector2 &a_Source);
		bool	operator == (const Vector2 &a_Source);
	};
}

#endif