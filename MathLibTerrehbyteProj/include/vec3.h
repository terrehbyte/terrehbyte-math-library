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

		float	EulerAngle(const Vector3 &a_Term) const;
		float	DotProduct(const Vector3 &a_Term) const;

		Vector3	Normal() const;		// returns a normalized version of this vector
		void Normalise();			// normalizes the vector in-place
		Vector3	CrossProduct(const Vector3 &a_Term) const;	// returns the cross product

		float	Magnitude() const;	// returns the magnitude of the vector

		// Return a linearly interpolated vector
		Vector3 Lerp(const Vector3 &a_end, const float &a_fTime) const;

		Vector3		operator +	(const Vector3	&a_First) const;
		Vector3		operator +	(const float	&a_fAddendScalar) const;
		Vector3&	operator += (const Vector3	&a_Addend);
		Vector3&	operator += (const float	&a_fAddendScalar);

		Vector3		operator -	(const Vector3	&a_Subtrahend) const;
		Vector3		operator -	(const float	&a_fSubtrahendScalar) const;
		Vector3&	operator -= (const Vector3	&a_Subtrahend);
		Vector3&	operator -= (const float	&a_fSubtrahendScalar);

		Vector3		operator *	(const float	&a_fScalar) const;
		Vector3&	operator *= (const float	&a_fScalar);

		Vector3		operator /	(const float	&a_fScalar) const;
		Vector3&	operator /= (const float	&a_fScalar);

		Vector3&	operator =	(const Vector3	&a_Source);
		bool		operator == (const Vector3	&a_Source) const;
		bool		operator != (const Vector3  &a_Source) const;
	};
}

#endif