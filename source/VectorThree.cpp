//////////////////////////////////////////////////////////////////////////
//	File:	VectorThree.cpp
//	Author:	Terry Nguyen
//	Date:	12/18/2013
//	Brief:	Defines functions pertaining to Vector3D
//
//////////////////////////////////////////////////////////////////////////

#include "VectorThree.h"

namespace tbyte
{
	Vector3::Vector3()
	{
	}
	
	Vector3::Vector3(const float a_fX, const float a_fY, const float a_fZ)
	{
		fX = a_fX;
		fY = a_fY;
		fZ = a_fZ;
	}

	Vector3::~Vector3()
	{
	}
	
	float Vector3::GetEulerAngle(const Vector3 &a_Term)
	{
		Vector3 VectorA = (*this);
		VectorA = VectorA.GetNormal();
		
		Vector3 VectorB = a_Term;
		VectorB = VectorB.GetNormal();
		
		float fEuler = acos( (VectorA).GetDotProduct(VectorB) );
		return fEuler;
	}

	float	Vector3::GetDotProduct(const Vector3 &a_Term)
	{
		return (fX * a_Term.fX) + (fY * a_Term.fY) + (fZ * a_Term.fZ);
	}

	Vector3 Vector3::GetNormal()
	{
		Vector3 temp = (*this);

		float fMagnitude = GetMagnitude();

		temp /= fMagnitude;
		
		return temp;
	}

	Vector3 Vector3::GetCrossProduct(const Vector3 &a_Term)
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

	Vector3 Vector3::Lerp(const Vector3 &a_TerminatingVector, const float &a_fInterpPoint)
	{
		Vector3 InterpolatedVector;
		InterpolatedVector.fX = a_fInterpPoint;
		
		float InterpYValue = ( (a_fInterpPoint - fX) * (a_TerminatingVector.fY - fY) ) / (a_TerminatingVector.fX - fX);
		float InterpZValue = ( (a_fInterpPoint - fX) * (a_TerminatingVector.fZ - fZ) ) / (a_TerminatingVector.fX - fX);

		InterpYValue += fY;
		InterpZValue += fY;

		InterpolatedVector.fY = InterpYValue;
		InterpolatedVector.fZ = InterpZValue;

		return InterpolatedVector;
	}

	// ** OPERATOR OVERLOADS ** - allows the object to be used with basic operators
	Vector3	Vector3::operator + (const Vector3 &a_Addend)
	{
		Vector3 temp = (*this);

		temp.fX = fX + a_Addend.fX;
		temp.fY = fY + a_Addend.fY;
		temp.fZ = fZ + a_Addend.fZ;
		return temp;
	}

	Vector3	Vector3::operator + (const float &a_fAddendScalar)
	{
		Vector3 temp = (*this);

		temp.fX = fX + a_fAddendScalar;
		temp.fY = fY + a_fAddendScalar;
		temp.fZ = fZ + a_fAddendScalar;
		return temp;
	}

	Vector3	Vector3::operator += (const Vector3 &a_Addend)
	{
		(*this) = (*this) + a_Addend;
		return (*this);
	}

	Vector3	Vector3::operator += (const float &a_fAddendScalar)
	{
		(*this) = (*this) + a_fAddendScalar;
		return (*this);
	}

	Vector3	Vector3::operator - (const Vector3 &a_Subtrahend)
	{
		Vector3 temp = (*this);

		temp.fX = fX - a_Subtrahend.fX;
		temp.fY = fY - a_Subtrahend.fY;
		temp.fZ = fZ - a_Subtrahend.fZ;
		return temp;
	}

	Vector3 Vector3::operator - (const float &a_fSubtrahendScalar)
	{
		Vector3 temp = (*this);

		temp.fX = fX - a_fSubtrahendScalar;
		temp.fY = fY - a_fSubtrahendScalar;
		temp.fZ = fZ - a_fSubtrahendScalar;
		return temp;
	}

	Vector3	Vector3::operator -= (const Vector3 &a_Subtrahend)
	{
		(*this) = (*this) - a_Subtrahend;
		return (*this);
	}

	Vector3 Vector3::operator -= (const float &a_fSubtrahendScalar)
	{
		(*this) = (*this) - a_fSubtrahendScalar;
		return (*this);
	}

	Vector3 Vector3::operator * (const float &a_fScalar)
	{
		Vector3 temp = (*this);

		temp.fX = temp.fX * a_fScalar;
		temp.fY = temp.fY * a_fScalar;
		temp.fZ = temp.fZ * a_fScalar;

		return temp;
	}

	Vector3 Vector3::operator *= (const float &a_fScalar)
	{
		(*this) = (*this) * a_fScalar;
		return (*this);
	}

	Vector3 Vector3::operator / (const float &a_fScalar)
	{
		Vector3 temp = (*this);

		temp.fX = temp.fX / a_fScalar;
		temp.fY = temp.fY / a_fScalar;
		temp.fZ = temp.fZ / a_fScalar;

		return temp;
	}

	Vector3 Vector3::operator /= (const float &a_fScalar)
	{
		(*this) = (*this) / a_fScalar;
		return (*this);
	}

	// Assignment Operator - Assigns the values of an existing Vector3 to another existing Vector3
	Vector3	Vector3::operator = (const Vector3 &a_Source)
	{
		// avoid self-assignment
		if (this == &a_Source)
		{
			return *this;
		}

		fX = a_Source.fX;
		fY = a_Source.fY;
		fZ = a_Source.fZ;
	
		return *this;
	}

	bool	Vector3::operator == (const Vector3 &a_Source)
	{
		if(fX == a_Source.fX &&
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