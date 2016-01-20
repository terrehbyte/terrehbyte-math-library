//////////////////////////////////////////////////////////////////////////
//	File:	VectorTwo.cpp
//	Author:	Terry Nguyen
//	Date:	12/18/2013
//	Brief:	Defines functions pertaining to Vector2D
//
//////////////////////////////////////////////////////////////////////////

#include <tbytemath.h>

namespace tbyte
{
	Vector2::Vector2()
	{
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

	float Vector2::EulerAngle(const Vector2 &a_Term)
	{
		Vector2 VectorA = (*this);
		VectorA = VectorA.Normal();
		
		Vector2 VectorB = a_Term;
		VectorB = VectorB.Normal();
		
		float fEuler = acos((VectorA).DotProduct(VectorB));

		return fEuler;
	}

	float	Vector2::DotProduct(const Vector2 &a_Term)
	{
		return (m_fX * a_Term.m_fX) + (m_fY * a_Term.m_fY);
	}

	Vector2 Vector2::Normal()
	{
		Vector2 temp = (*this);
		float fMagnitude = Magnitude();
		temp /= fMagnitude;

		return temp;
	}
	void Vector2::Normalise()
	{
		float fMag = Magnitude();
		m_fX /= fMag;
		m_fY /= fMag;
	
	}

	float	Vector2::Magnitude()
	{
		float fFirst = m_fX * m_fX;
		float fSecond = m_fY * m_fY;
	
		return sqrt(fFirst + fSecond);
	}

	Vector2 Vector2::Lerp(const Vector2 &a_TerminatingVector, const float &a_fInterpPoint)
	{
		Vector2 start = (*this);
		Vector2 end = a_TerminatingVector;

		Vector2 InterpolatedVector = (*this) + (end - start) * a_fInterpPoint;

		return InterpolatedVector;
	}

	// ** OPERATOR OVERLOADS ** - allows the object to be used with basic operators
	Vector2	Vector2::operator + (const Vector2 &a_Addend)
	{
		// Create a blank Vector2
		Vector2 temp = (*this);

		// Add the two things together
		temp.m_fX += a_Addend.m_fX;
		temp.m_fY += a_Addend.m_fY;

		// Return dat shit
		return temp;
	}

	// ADDEND + ADDEND = SUM
	Vector2 Vector2::operator + (const float &a_fAddendScalar)
	{		
		Vector2 temp = (*this);

		// Add temp's X and Y to the other X and Y
		temp.m_fX += a_fAddendScalar;
		temp.m_fY += a_fAddendScalar;

		// Return temp, the sum of two Vector2 things
		return temp;
	}

	Vector2	Vector2::operator += (const Vector2 &a_Addend)
	{
		(*this) = (*this) + a_Addend;
		return (*this);
	}

	Vector2 Vector2::operator += (const float &a_fAddendScalar)
	{
		(*this) = (*this) + a_fAddendScalar;
		return (*this);
	}

	Vector2	Vector2::operator - (const Vector2 &a_Subtrahend)
	{
		Vector2 temp = (*this);

		temp.m_fX -= a_Subtrahend.m_fX;
		temp.m_fY -= a_Subtrahend.m_fY;

		return temp;
	}

	Vector2 Vector2::operator - (const float &a_fSubtrahendScalar)
	{
		Vector2 temp = (*this);

		temp.m_fX -= a_fSubtrahendScalar;
		temp.m_fY -= a_fSubtrahendScalar;

		return temp;
	}

	Vector2	Vector2::operator -= (const Vector2 &a_Subtrahend)
	{
        (*this) = (*this) - a_Subtrahend;
		return (*this);
	}

	Vector2	Vector2::operator -= (const float &a_fSubtrahendScalar)
	{
        (*this)= (*this) - a_fSubtrahendScalar;
		return (*this);
	}

	Vector2 Vector2::operator * (const float &a_fScalar)
	{
		Vector2 temp = (*this);

		temp.m_fX *= a_fScalar;
		temp.m_fY *= a_fScalar;

		return temp;
	}

	Vector2 Vector2::operator *= (const float &a_fScalar)
	{
		(*this) = (*this) * a_fScalar;
		return (*this);
	}

	Vector2 Vector2::operator / (const float &a_fScalar)
	{
		Vector2 temp = (*this);

		temp.m_fX /= a_fScalar;
		temp.m_fY /= a_fScalar;

		return temp;
	}

	Vector2 Vector2::operator /= (const float &a_fScalar)
	{
		(*this) = (*this) / a_fScalar;
		return (*this);
	}

	// Assignment Operator - Assigns the values of an existing vector2 to another existing vector2
	Vector2	Vector2::operator = (const Vector2 &a_Source)
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

	bool	Vector2::operator == (const Vector2 &a_Source)
	{
		if (m_fX == a_Source.m_fX &&
			m_fY == a_Source.m_fY)
		{
			return true;
		}

		else
		{
			return false;
		}
	}

}