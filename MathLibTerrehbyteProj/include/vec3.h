//////////////////////////////////////////////////////////////////////////
//	File:	vec3.h  
//	Author:	Terry Nguyen  
//	Date:	01/25/2016
//	Brief:	Contains the class declaration for a Vector3 structure
//
//////////////////////////////////////////////////////////////////////////

#ifndef _VEC3_H_
#define _VEC3_H_

#include "internal\_compiler.h"

namespace tbyte
{
	struct TBYTELIB Vector3
	{
	public:
		Vector3();

		Vector3(const float &a_fX, const float &a_fY, const float &a_fZ);

		Vector3(const Vector3 &a_Source);

		~Vector3();

		float	m_fX;
		float	m_fY;
		float	m_fZ;

		// Get Euler Angle Between Two Vectors
		float	EulerAngle(const Vector3 &a_Term);

		// Returns the Dot Product between the caller and the Vector3 term
		float	DotProduct(const Vector3 &a_Term);

		// Return what the caller would be when normalized
		Vector3	Normal();
		void Normalise();
		// Returns the cross product between caller and term
		Vector3	CrossProduct(const Vector3 &a_Term);

		// Returns the magnitude of the vector
		float	Magnitude();

		// Return a linearly interpolated Vector3
		Vector3 Lerp(const Vector3 &a_TerminatingVector, const float &a_fInterpPoint);

		Vector3	operator + (const Vector3 &a_First);
		Vector3	operator + (const float &a_fAddendScalar);
		Vector3 operator += (const Vector3 &a_Addend);
		Vector3 operator += (const float &a_fAddendScalar);

		Vector3 operator - (const Vector3 &a_Subtrahend);
		Vector3 operator - (const float &a_fSubtrahendScalar);
		Vector3 operator -= (const Vector3 &a_Subtrahend);
		Vector3 operator -= (const float &a_fSubtrahendScalar);

		Vector3 operator * (const float &a_fScalar);
		Vector3 operator *= (const float &a_fScalar);

		Vector3 operator / (const float &a_fScalar);
		Vector3 operator /= (const float &a_fScalar);

		Vector3	operator = (const Vector3 &a_Source);
		bool	operator == (const Vector3 &a_Source);
	};
}

#endif