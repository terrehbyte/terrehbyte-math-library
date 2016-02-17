//////////////////////////////////////////////////////////////////////////
//	File:	vec2.cpp
//	Author:	Terry Nguyen
//	Date:	12/18/2013
//	Brief:	Defines functions pertaining to Vector2D
//
//////////////////////////////////////////////////////////////////////////

#include "vec2.h"

#define _USE_MATH_DEFINES
#include <cmath>

#include <limits>

const float eps = std::numeric_limits<float>::epsilon();

namespace tbyte
{
	Vector2::Vector2(void)
	{
		m_fX = 0.0f;
		m_fY = 0.0f;
	}

	Vector2::Vector2(const Vector2 &a_Source)
	{
		m_fX = a_Source.m_fX;
		m_fY = a_Source.m_fY;
	}

	Vector2::Vector2(const float &a_fX, const float &a_fY)
	{
		m_fX = a_fX;
		m_fY = a_fY;
	}

	Vector2::~Vector2()
	{
	}

	float		Vector2::EulerAngle(const Vector2 &a_Term)
	{
		return acos(((*this).Normal()).DotProduct(a_Term.Normal()));
	}

	float		Vector2::DotProduct(const Vector2 &a_Term)
	{
		return (m_fX * a_Term.m_fX) + (m_fY * a_Term.m_fY);
	}

	Vector2		Vector2::Normal() const
	{
		return (*this) / Magnitude();
	}

	void		Vector2::Normalise()
	{
		(*this) /= Magnitude();
	}

	float		Vector2::Magnitude() const
	{
		return sqrt(m_fX * m_fX + m_fY * m_fY);
	}

	Vector2		Vector2::Lerp(const Vector2 &a_end, const float &a_fTime) const
	{
		return (*this) + (a_end - (*this)) * a_fTime;
	}

	Vector2		Vector2::operator + (const Vector2 &a_Addend) const
	{
		return { m_fX + a_Addend.m_fX, m_fY + a_Addend.m_fY };
	}

	Vector2		Vector2::operator + (const float &a_fAddendScalar) const
	{		
		return { m_fX + a_fAddendScalar, m_fY + a_fAddendScalar };
	}

	Vector2&	Vector2::operator += (const Vector2 &a_Addend)
	{
		return (*this) = (*this) + a_Addend;
	}

	Vector2&	Vector2::operator += (const float &a_fAddendScalar)
	{
		return (*this) = (*this) + a_fAddendScalar;
	}

	Vector2		Vector2::operator - (const Vector2 &a_Subtrahend) const
	{
		return{ m_fX - a_Subtrahend.m_fX, m_fY - a_Subtrahend.m_fY };
	}

	Vector2		Vector2::operator - (const float &a_fSubtrahendScalar) const
	{
		return{ m_fX - a_fSubtrahendScalar, m_fY - a_fSubtrahendScalar };
	}

	Vector2&	Vector2::operator -= (const Vector2 &a_Subtrahend)
	{
		return (*this) = (*this) - a_Subtrahend;
	}

	Vector2&	Vector2::operator -= (const float &a_fSubtrahendScalar)
	{
		return (*this) = (*this) - a_fSubtrahendScalar;
	}

	Vector2		Vector2::operator * (const float &a_fScalar) const
	{
		return { m_fX * a_fScalar, m_fY * a_fScalar };
	}

	Vector2&	Vector2::operator *= (const float &a_fScalar)
	{
		return (*this) = (*this) * a_fScalar;
	}

	Vector2		Vector2::operator / (const float &a_fScalar) const
	{
		return{ m_fX / a_fScalar, m_fY / a_fScalar };
	}

	Vector2&	Vector2::operator /= (const float &a_fScalar)
	{
		return (*this) = (*this) / a_fScalar;
	}

	// Assignment Operator - Assigns the values of an existing vector2 to another existing vector2
	Vector2&	Vector2::operator = (const Vector2 &a_Source)
	{
		// avoid self-assignment
		if (this == &a_Source)
		{
			return *this;
		}

		m_fX = a_Source.m_fX;
		m_fY = a_Source.m_fY;
		
		return *this;
	}

	bool		Vector2::operator == (const Vector2 &a_Source) const
	{
		return fabs(m_fX - a_Source.m_fX) < eps &&
			   fabs(m_fY - a_Source.m_fY) < eps;
	}
	bool		Vector2::operator != (const Vector2 &a_Source) const
	{
		return !((*this) == a_Source);
	}
}