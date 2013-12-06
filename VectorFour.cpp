//////////////////////////////////////////////////////////////////////////
//	File:	VectorThree.cpp
//	Author:	Terry Nguyen
//	Date:	11/05/2013
//	Brief:	Defines functions pertaining to Vector3D
//
//////////////////////////////////////////////////////////////////////////

#include <math.h>
#include "VectorFour.h"
#include <iostream>

// ** CONSTRUCTORS ** - initialize values

namespace Vector4
{
	Vector4::Vector4()
	{
		fW = 0;
		fY = 0;
		fX = 0;
		fZ = 0;
	}
	
	// ** DESTRUCTORS ** - destroy values in heap
	Vector4::~Vector4()
	{
	}

	float	Vector4::GetMagnitude()
	{
		float fFirst	= fW * fW;
		float fSecond	= fX * fX;
		float fThird	= fY * fY;
		float fFourth	= fZ * fZ;
		
		return sqrt(fFirst + fSecond + fThird + fFourth);
	}

	Vector4 Vector4::GetNormal()
	{
		Vector4 temp;

		float fMagnitude = GetMagnitude();

		temp.fW = fW / fMagnitude;
		temp.fX = fX / fMagnitude;
		temp.fY = fY / fMagnitude;
		temp.fZ = fZ / fMagnitude;
		
		return temp;
	}

	void Vector4::ConstructFromHex(
		float a_iRED,
		float a_iGREEN,
		float a_iBLUE,
		float a_iALPHA
		)
	{	
		fW = a_iRED   / 255;
		fX = a_iGREEN / 255;
		fY = a_iBLUE  / 255;
		fZ = a_iALPHA / 255;
	}
	
	Vector4 Vector4::operator + (const Vector4 a_Addend)
	{
		// Create a temp Vector4
		Vector4 temp = (*this);

		// Add temp's X and Y to the other X and Y
		temp.fW = temp.fW + a_Addend.fW;
		temp.fX = temp.fX + a_Addend.fX;
		temp.fY = temp.fY + a_Addend.fY;
		temp.fZ = temp.fZ + a_Addend.fZ;

		// Return temp, the sum of two Vector4 things
		return temp;
	}
	
	Vector4 Vector4::operator + (const float a_fAddendScalar)
	{
		// Create a temp Vector4
		Vector4 temp = (*this);

		// Add temp's X and Y to the other X and Y
		temp.fW = temp.fW + a_fAddendScalar;
		temp.fX = temp.fX + a_fAddendScalar;
		temp.fY = temp.fY + a_fAddendScalar;
		temp.fZ = temp.fZ + a_fAddendScalar;

		// Return temp, the sum of two Vector4 things
		return temp;
	}

	Vector4	Vector4::operator += (const Vector4 a_Addend)
	{
		return (*this) + a_Addend;
	}

	Vector4 Vector4::operator += (const float a_fAddendScalar)
	{
		return (*this) + a_fAddendScalar;
	}

	Vector4	Vector4::operator - (const Vector4 a_Subtrahend)
	{
		Vector4 temp = (*this);

		temp.fW = fW - a_Subtrahend.fW;
		temp.fX = fX - a_Subtrahend.fX;
		temp.fY = fY - a_Subtrahend.fY;
		temp.fZ = fZ - a_Subtrahend.fZ;
		return temp;
	}

	Vector4 Vector4::operator - (const float a_fSubtrahendScalar)
	{
		Vector4 temp = (*this);
		
		temp.fW = temp.fW - a_fSubtrahendScalar;
		temp.fX = temp.fX - a_fSubtrahendScalar;
		temp.fY = temp.fY - a_fSubtrahendScalar;
		temp.fZ = temp.fZ - a_fSubtrahendScalar;

		return temp;
	}

	Vector4	Vector4::operator -= (const Vector4 a_Subtrahend)
	{
		return (*this) - a_Subtrahend;
	}

	Vector4	Vector4::operator -= (const float a_fSubtrahendScalar)
	{
		return (*this) - a_fSubtrahendScalar;
	}

	Vector4 Vector4::operator * (const float a_fScalar)
	{
		return (*this) - a_fScalar;
	}

	Vector4 Vector4::operator *= (const float a_fScalar)
	{
		Vector4 temp = (*this);

		temp.fW = temp.fW * a_fScalar;
		temp.fX = temp.fX * a_fScalar;
		temp.fY = temp.fY * a_fScalar;
		temp.fZ = temp.fZ * a_fScalar;

		return temp;
	}

	Vector4 Vector4::operator / (const float a_fScalar)
	{
		Vector4 temp = (*this);

		temp.fW = temp.fW / a_fScalar;
		temp.fX = temp.fX / a_fScalar;
		temp.fY = temp.fY / a_fScalar;
		temp.fZ = temp.fZ / a_fScalar;

		return temp;
	}

	Vector4 Vector4::operator /= (const float a_fScalar)
	{
		Vector4 temp =  (*this);

		temp.fW = temp.fW / a_fScalar;
		temp.fX = temp.fX / a_fScalar;
		temp.fY = temp.fY / a_fScalar;
		temp.fZ = temp.fZ / a_fScalar;

		return temp;
	}

	// Assignment Operator - Assigns the values of an existing Vector4 to another existing Vector4
	Vector4	Vector4::operator = (const Vector4 a_Source)
	{
		fW = a_Source.fW;
		fX = a_Source.fX;
		fY = a_Source.fY;
		fZ = a_Source.fZ;
		
		return *this;
	}

	bool	Vector4::operator == (const Vector4 a_Source)
	{
		if (fW == a_Source.fW &&
			fX == a_Source.fX &&
			fY == a_Source.fY &&
			fZ == a_Source.fZ)
		{
			return true;
		}

		else
		{
			return false;
		}
	}
}
