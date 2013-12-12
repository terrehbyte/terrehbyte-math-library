//////////////////////////////////////////////////////////////////////////
//	File:	VectorTwo.cpp
//	Author:	Terry Nguyen
//	Date:	11/05/2013
//	Brief:	Defines functions pertaining to Vector2D
//
//////////////////////////////////////////////////////////////////////////

#include <math.h>
#include "VectorTwo.h"

namespace Vector2
{
	Vector2::Vector2()
	{
	}
	
	Vector2::~Vector2()
	{
	}

	float	Vector2::GetDotProduct(const Vector2 &a_Term)
	{
		return (fX * a_Term.fX) + (fY * a_Term.fY);
	}

	Vector2 Vector2::GetNormal()
	{
		Vector2 temp = (*this);
		float fMagnitude = GetMagnitude();
		temp /= fMagnitude;

		return temp;
	}

	float	Vector2::GetMagnitude()
	{
		float fFirst = fX * fX;
		float fSecond = fY * fY;
	
		return sqrt(fFirst + fSecond);
	}

	Vector2 Vector2::Lerp(const Vector2 &a_TerminatingVector, const float &a_fInterpPoint)
	{
		Vector2 InterpolatedVector;
		InterpolatedVector.fX = a_fInterpPoint;
		
		float InterpValue;

		InterpValue = ( (a_fInterpPoint - fX) * (a_TerminatingVector.fY - fY) ) / (a_TerminatingVector.fX - fX);
		InterpValue += fY;

		InterpolatedVector.fY = InterpValue;

		return InterpolatedVector;
	}

	// ** OPERATOR OVERLOADS ** - allows the object to be used with basic operators
	Vector2	Vector2::operator + (const Vector2 &a_Addend)
	{
		// Create a blank Vector2
		Vector2 temp = (*this);

		// Add the two things together
		temp.fX += a_Addend.fX;
		temp.fY += a_Addend.fY;

		// Return dat shit
		return temp;
	}

	// ADDEND + ADDEND = SUM
	Vector2 Vector2::operator + (const float &a_fAddendScalar)
	{		
		Vector2 temp = (*this);

		// Add temp's X and Y to the other X and Y
		temp.fX += a_fAddendScalar;
		temp.fY += a_fAddendScalar;

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

		temp.fX -= a_Subtrahend.fX;
		temp.fY -= a_Subtrahend.fY;

		return temp;
	}

	Vector2 Vector2::operator - (const float &a_fSubtrahendScalar)
	{
		Vector2 temp = (*this);

		temp.fX -= a_fSubtrahendScalar;
		temp.fY -= a_fSubtrahendScalar;

		return temp;
	}

	Vector2	Vector2::operator -= (const Vector2 &a_Subtrahend)
	{
		return (*this) - a_Subtrahend;
	}

	Vector2	Vector2::operator -= (const float &a_fSubtrahendScalar)
	{
		return (*this) - a_fSubtrahendScalar;
	}

	Vector2 Vector2::operator * (const float &a_fScalar)
	{
		Vector2 temp = (*this);

		temp.fX *= a_fScalar;
		temp.fY *= a_fScalar;

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

		temp.fX /= a_fScalar;
		temp.fY /= a_fScalar;

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

		fX = a_Source.fX;
		fY = a_Source.fY;
		
		return *this;
	}

	bool	Vector2::operator == (const Vector2 &a_Source)
	{
		if (fX == a_Source.fX &&
			fY == a_Source.fY)
		{
			return true;
		}

		else
		{
			return false;
		}
	}

}