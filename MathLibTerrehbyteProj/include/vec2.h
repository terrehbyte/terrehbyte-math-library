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

        float	EulerAngle(const Vector2 &a_Term);
        float	DotProduct(const Vector2 &a_Term);

		Vector2	Normal() const;		// returns a normalized version of this vector
        void	Normalise();		// normalizes the vector in-place
       
        float	Magnitude() const;	// returns the magnitude of the Vector

        // Return linearly interpolated vector
        Vector2 Lerp(const Vector2 &a_end, const float &a_fTime) const;

        Vector2		operator +	(const Vector2	&a_Addend) const;
        Vector2		operator +	(const float	&a_fAddendScalar) const;
        Vector2&	operator += (const Vector2	&a_Addend);
        Vector2&	operator += (const float	&a_fAddendScalar);

        Vector2		operator -	(const Vector2	&a_Subtrahend) const;
        Vector2		operator -	(const float	&a_fSubtrahendScalar) const;
        Vector2&	operator -= (const Vector2	&a_Addend);
        Vector2&	operator -= (const float	&a_fSubtrahendScalar);

        Vector2		operator *	(const float	&a_fScalar) const;
        Vector2&	operator *= (const float	&a_fScalar);

        Vector2		operator /	(const float	&a_fScalar) const;
        Vector2&	operator /= (const float	&a_fScalar);

        Vector2&	operator =	(const Vector2	&a_Source);
        bool		operator == (const Vector2	&a_Source) const;
		bool		operator != (const Vector2  &a_Source) const;
    };
}

#endif