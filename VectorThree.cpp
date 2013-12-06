//////////////////////////////////////////////////////////////////////////
//	File:	VectorThree.cpp
//	Author:	Terry Nguyen
//	Date:	11/05/2013
//	Brief:	Defines functions pertaining to Vector3D
//
//////////////////////////////////////////////////////////////////////////

#include <math.h>
#include "VectorThree.h"

// ** CONSTRUCTORS ** - initialize values

namespace Vector3
{
	Vector3::Vector3()
	{
		fY = 0;
		fX = 0;
		fZ = 0;
	}
	
	// ** DESTRUCTORS ** - destroy values in heap
	Vector3::~Vector3()
	{
	}
	
	float	Vector3::GetDotProduct(const Vector3 a_Term)
	{
		return (fX * a_Term.fX) + (fY * a_Term.fY) + (fZ * a_Term.fZ);
	}

	Vector3 Vector3::GetNormal()
	{
		Vector3 temp;

		float fMagnitude = GetMagnitude();

		temp.fX = fX / fMagnitude;
		temp.fY = fY / fMagnitude;
		temp.fZ = fZ / fMagnitude;
		
		return temp;
	}

	Vector3 Vector3::GetCrossProduct(const Vector3 a_Term)
	{
		// X is 1
		// Y is 2
		// Z is 3
		// a x b = (a2b3 - a3b2, a3b1 - a1b3, a1b2 - a2b1)
		Vector3 temp;
		// a2b3 - a3b2
		temp.fX = (fY * a_Term.fZ - fZ * a_Term.fY);
		// a3b1 - a1b3
		temp.fY = (fZ * a_Term.fX - fX * a_Term.fZ);
		// a1b2 - a2b1
		temp.fZ = (fX * a_Term.fY - fY * a_Term.fX);
	
		return temp;
	}

	float	Vector3::GetMagnitude()
	{
		float fFirst	= fX * fX;
		float fSecond	= fY * fY;
		float fThird	= fZ * fZ;

		// consider using something besides costly sqrt
		return sqrt(fFirst + fSecond + fThird);
	}

	Vector3 Vector3::Lerp(const Vector3 a_TerminatingVector, const float a_fInterpPoint)
	{
		Vector3 InterpolatedVector;
		InterpolatedVector.fX = a_fInterpPoint;
		
		float InterpYValue;
		float InterpZValue;

		InterpYValue = ( (a_fInterpPoint - fX) * (a_TerminatingVector.fY - fY) ) / (a_TerminatingVector.fX - fX);
		InterpYValue += fY;

		InterpZValue = ( (a_fInterpPoint - fX) * (a_TerminatingVector.fZ - fZ) ) / (a_TerminatingVector.fX - fX);
		InterpZValue += fY;

		InterpolatedVector.fY = InterpYValue;
		InterpolatedVector.fZ = InterpZValue;

		return InterpolatedVector;
	}

	// ** OPERATOR OVERLOADS ** - allows the object to be used with basic operators
	Vector3	Vector3::operator + (const Vector3 a_Addend)
	{
		Vector3 temp = (*this);

		temp.fX = fX + a_Addend.fX;
		temp.fY = fY + a_Addend.fY;
		temp.fZ = fZ + a_Addend.fZ;
		return temp;
	}

	Vector3	Vector3::operator + (const float a_fAddendScalar)
	{
		Vector3 temp = (*this);

		temp.fX = fX + a_fAddendScalar;
		temp.fY = fY + a_fAddendScalar;
		temp.fZ = fZ + a_fAddendScalar;
		return temp;
	}

	Vector3	Vector3::operator += (const Vector3 a_Addend)
	{
		Vector3 temp = (*this) + a_Addend;

		return temp;
	}

	Vector3	Vector3::operator += (const float a_fAddendScalar)
	{
		Vector3 temp = (*this);

		temp.fX = fX + a_fAddendScalar;
		temp.fY = fY + a_fAddendScalar;
		temp.fZ = fZ + a_fAddendScalar;
		return temp;
	}

	Vector3	Vector3::operator - (const Vector3 a_Subtrahend)
	{
		Vector3 temp = (*this);

		temp.fX = fX - a_Subtrahend.fX;
		temp.fY = fY - a_Subtrahend.fY;
		temp.fZ = fZ - a_Subtrahend.fZ;
		return temp;
	}

	Vector3 Vector3::operator - (const float a_fSubtrahendScalar)
	{
		Vector3 temp = (*this);

		temp.fX = fX - a_fSubtrahendScalar;
		temp.fY = fY - a_fSubtrahendScalar;
		temp.fZ = fZ - a_fSubtrahendScalar;
		return temp;
	}

	Vector3	Vector3::operator -= (const Vector3 a_Subtrahend)
	{
		Vector3 temp = (*this) - a_Subtrahend;
		return temp;
	}

	Vector3 Vector3::operator -= (const float a_fSubtrahendScalar)
	{
		Vector3 temp = (*this);

		temp.fX = fX - a_fSubtrahendScalar;
		temp.fY = fY - a_fSubtrahendScalar;
		temp.fZ = fZ - a_fSubtrahendScalar;

		return temp;
	}

	Vector3 Vector3::operator * (const float a_fScalar)
	{
		Vector3 temp = (*this);

		temp.fX = temp.fX * a_fScalar;
		temp.fY = temp.fY * a_fScalar;
		temp.fZ = temp.fZ * a_fScalar;

		return temp;
	}

	Vector3 Vector3::operator *= (const float a_fScalar)
	{
		Vector3 temp = (*this);

		temp.fX = temp.fX * a_fScalar;
		temp.fY = temp.fY * a_fScalar;
		temp.fZ = temp.fZ * a_fScalar;

		return temp;
	}

	Vector3 Vector3::operator / (const float a_fScalar)
	{
		Vector3 temp = (*this);

		temp.fX = temp.fX / a_fScalar;
		temp.fY = temp.fY / a_fScalar;
		temp.fZ = temp.fZ / a_fScalar;

		return temp;
	}

	Vector3 Vector3::operator /= (const float a_fScalar)
	{
		Vector3 temp = (*this);

		temp.fX = temp.fX / a_fScalar;
		temp.fY = temp.fY / a_fScalar;
		temp.fZ = temp.fZ / a_fScalar;

		return temp;
	}

	// Assignment Operator - Assigns the values of an existing Vector3 to another existing Vector3
	Vector3	Vector3::operator = (const Vector3 a_Source)
	{
		fX = a_Source.fX;
		fY = a_Source.fY;
		fZ = a_Source.fZ;
	
		return *this;
	}

	bool	Vector3::operator == (const Vector3 a_Source)
	{
		if(
			fX == a_Source.fX &&
			fY == a_Source.fY &&
			fZ == a_Source.fZ
		)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}