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
		return (fX * a_Term.fX) + (fY * a_Term.fY);
	}

	Vector3 Vector3::GetNormal()
	{
		Vector3 temp;
		float fMagnitude = this->GetMagnitude();
		temp.fX = fX / fMagnitude;
		temp.fY = fY / fMagnitude;
		temp.fZ = fZ / fMagnitude;
		return temp;
	}

	Vector3 Vector3::GetCrossProduct(const Vector3 a_Term)
	{
		Vector3 temp;
		temp.fX = fY * a_Term.fZ - fZ * a_Term.fY;
		temp.fY = fZ * a_Term.fX - fX * a_Term.fZ;
		temp.fZ = fX * a_Term.fY - fY * a_Term.fX;
	
		return temp;
	}

	float	Vector3::GetMagnitude()
	{
		float fFirst = fX * fX;
		float fSecond = fY * fY;
		float fThird = fZ * fZ;
	
		return sqrt(fFirst + fSecond + fThird);
	}

	// ** OPERATOR OVERLOADS ** - allows the object to be used with basic operators
	Vector3	Vector3::operator + (const Vector3 a_Addend)
	{
		Vector3 temp;

		temp.fX = fX;
		temp.fY = fY;
		temp.fZ = fZ;

		temp.fX = fX + a_Addend.fX;
		temp.fY = fY + a_Addend.fY;
		temp.fZ = fZ + a_Addend.fZ;
		return temp;
	}

	Vector3	Vector3::operator + (const float a_fAddendScalar)
	{
		Vector3 temp;

		temp.fX = fX;
		temp.fY = fY;
		temp.fZ = fZ;

		temp.fX = fX + a_fAddendScalar;
		temp.fY = fY + a_fAddendScalar;
		temp.fZ = fZ + a_fAddendScalar;
		return temp;
	}

	Vector3	Vector3::operator += (const Vector3 a_Addend)
	{
		Vector3 temp;

		temp.fX = fX;
		temp.fY = fY;
		temp.fZ = fZ;

		temp.fX = fX + a_Addend.fX;
		temp.fY = fY + a_Addend.fY;
		temp.fZ = fZ + a_Addend.fZ;
		return temp;
	}

	Vector3	Vector3::operator += (const float a_fAddendScalar)
	{
		Vector3 temp;

		temp.fX = fX;
		temp.fY = fY;
		temp.fZ = fZ;

		temp.fX = fX + a_fAddendScalar;
		temp.fY = fY + a_fAddendScalar;
		temp.fZ = fZ + a_fAddendScalar;
		return temp;
	}

	Vector3	Vector3::operator - (const Vector3 a_Subtrahend)
	{
		Vector3 temp;

		temp.fX = fX;
		temp.fY = fY;
		temp.fZ = fZ;

		temp.fX = fX - a_Subtrahend.fX;
		temp.fY = fY - a_Subtrahend.fY;
		temp.fZ = fZ - a_Subtrahend.fZ;
		return temp;
	}

	Vector3 Vector3::operator - (const float a_fSubtrahendScalar)
	{
		Vector3 temp;

		temp.fX = fX;
		temp.fY = fY;
		temp.fZ = fZ;

		temp.fX = fX - a_fSubtrahendScalar;
		temp.fY = fY - a_fSubtrahendScalar;
		temp.fZ = fZ - a_fSubtrahendScalar;
		return temp;
	}

	Vector3	Vector3::operator -= (const Vector3 a_Subtrahend)
	{
		Vector3 temp;

		temp.fX = fX;
		temp.fY = fY;
		temp.fZ = fZ;

		temp.fX = fX - a_Subtrahend.fX;
		temp.fY = fY - a_Subtrahend.fY;
		temp.fZ = fZ - a_Subtrahend.fZ;
		return temp;
	}

	Vector3 Vector3::operator -= (const float a_fSubtrahendScalar)
	{
		Vector3 temp;

		temp.fX = fX;
		temp.fY = fY;
		temp.fZ = fZ;

		temp.fX = fX - a_fSubtrahendScalar;
		temp.fY = fY - a_fSubtrahendScalar;
		temp.fZ = fZ - a_fSubtrahendScalar;

		return temp;
	}

	Vector3 Vector3::operator * (const float a_fScalar)
	{
		Vector3 temp;
		temp.fX = fX;
		temp.fY = fY;
		temp.fZ = fZ;

		temp.fX = temp.fX * a_fScalar;
		temp.fY = temp.fY * a_fScalar;
		temp.fZ = temp.fZ * a_fScalar;

		return temp;
	}

	Vector3 Vector3::operator *= (const float a_fScalar)
	{
		Vector3 temp;
		temp.fX = fX;
		temp.fY = fY;
		temp.fZ = fZ;

		temp.fX = temp.fX * a_fScalar;
		temp.fY = temp.fY * a_fScalar;
		temp.fZ = temp.fZ * a_fScalar;

		return temp;
	}

	Vector3 Vector3::operator / (const float a_fScalar)
	{
		Vector3 temp;
		temp.fX = fX;
		temp.fY = fY;
		temp.fZ = fZ;

		temp.fX = temp.fX / a_fScalar;
		temp.fY = temp.fY / a_fScalar;
		temp.fZ = temp.fZ / a_fScalar;

		return temp;
	}

	Vector3 Vector3::operator /= (const float a_fScalar)
	{
		Vector3 temp;
		temp.fX = fX;
		temp.fY = fY;
		temp.fZ = fZ;

		temp.fX = temp.fX / a_fScalar;
		temp.fY = temp.fY / a_fScalar;
		temp.fZ = temp.fZ / a_fScalar;

		return temp;
	}

	// Assignment Operator - Assigns the values of an existing Vector3 to another existing Vector3
	void	Vector3::operator = (const Vector3 a_Source)
	{
		fX = a_Source.fX;
		fY = a_Source.fY;
		fZ = a_Source.fZ;
		return;
	}
}