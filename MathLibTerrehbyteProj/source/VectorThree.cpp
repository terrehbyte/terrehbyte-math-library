//////////////////////////////////////////////////////////////////////////
//	File:	VectorThree.cpp
//	Author:	Terry Nguyen
//	Date:	12/18/2013
//	Brief:	Defines functions pertaining to Vector3D
//
//////////////////////////////////////////////////////////////////////////

#include <TerrehByteMath.h>

namespace tbyte
{
	Vector3::Vector3()
	{
	}
	
	Vector3::Vector3(const float &a_fX, const float &a_fY, const float &a_fZ)
	{
		m_fX = a_fX;
		m_fY = a_fY;
		m_fZ = a_fZ;
	}

	Vector3::Vector3(const Vector3 &a_Source)
	{
		m_fX = a_Source.m_fX;
		m_fY = a_Source.m_fY;
		m_fZ = a_Source.m_fZ;
	}

	Vector3::~Vector3()
	{
	}
	
	float Vector3::EulerAngle(const Vector3 &a_Term)
	{
		Vector3 VectorA = (*this);
		VectorA = VectorA.Normal();
		
		Vector3 VectorB = a_Term;
		VectorB = VectorB.Normal();
		
		float fEuler = acos( (VectorA).DotProduct(VectorB) );
		return fEuler;
	}

	float	Vector3::DotProduct(const Vector3 &a_Term)
	{
		return (m_fX * a_Term.m_fX) + (m_fY * a_Term.m_fY) + (m_fZ * a_Term.m_fZ);
	}

	Vector3 Vector3::Normal()
	{
		Vector3 temp = (*this);

		float fMagnitude = Magnitude();

		temp /= fMagnitude;
		
		return temp;
	}

	void Vector3::Normalise()
	{
		float fMag = sqrtf(m_fX*m_fX + m_fY*m_fY + m_fZ*m_fZ);
		m_fX /= fMag;
		m_fY /= fMag;
		m_fZ /= fMag;
	}
	Vector3 Vector3::CrossProduct(const Vector3 &a_Term)
	{
		// X is 1
		// Y is 2
		// Z is 3
		// a x b = (a2b3 - a3b2, a3b1 - a1b3, a1b2 - a2b1)
		Vector3 temp;
		// a2b3 - a3b2
		temp.m_fX = (m_fY * a_Term.m_fZ - m_fZ * a_Term.m_fY);
		// a3b1 - a1b3
		temp.m_fY = (m_fZ * a_Term.m_fX - m_fX * a_Term.m_fZ);
		// a1b2 - a2b1
		temp.m_fZ = (m_fX * a_Term.m_fY - m_fY * a_Term.m_fX);
	
		return temp;
	}

	float	Vector3::Magnitude()
	{
		float fFirst	= m_fX * m_fX;
		float fSecond	= m_fY * m_fY;
		float fThird	= m_fZ * m_fZ;

		// consider using something besides costly sqrt
		return sqrt(fFirst + fSecond + fThird);
	}

	Vector3 Vector3::Lerp(const Vector3 &a_TerminatingVector, const float &a_fInterpPoint)
	{
		Vector3 InterpolatedVector;
		InterpolatedVector.m_fX = a_fInterpPoint;
		
		float InterpYValue = ( (a_fInterpPoint - m_fX) * (a_TerminatingVector.m_fY - m_fY) ) / (a_TerminatingVector.m_fX - m_fX);
		float InterpZValue = ( (a_fInterpPoint - m_fX) * (a_TerminatingVector.m_fZ - m_fZ) ) / (a_TerminatingVector.m_fX - m_fX);

		InterpYValue += m_fY;
		InterpZValue += m_fY;

		InterpolatedVector.m_fY = InterpYValue;
		InterpolatedVector.m_fZ = InterpZValue;

		return InterpolatedVector;
	}

	// ** OPERATOR OVERLOADS ** - allows the object to be used with basic operators
	Vector3	Vector3::operator + (const Vector3 &a_Addend)
	{
		Vector3 temp = (*this);

		temp.m_fX = m_fX + a_Addend.m_fX;
		temp.m_fY = m_fY + a_Addend.m_fY;
		temp.m_fZ = m_fZ + a_Addend.m_fZ;
		return temp;
	}

	Vector3	Vector3::operator + (const float &a_fAddendScalar)
	{
		Vector3 temp = (*this);

		temp.m_fX = m_fX + a_fAddendScalar;
		temp.m_fY = m_fY + a_fAddendScalar;
		temp.m_fZ = m_fZ + a_fAddendScalar;
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

		temp.m_fX = m_fX - a_Subtrahend.m_fX;
		temp.m_fY = m_fY - a_Subtrahend.m_fY;
		temp.m_fZ = m_fZ - a_Subtrahend.m_fZ;
		return temp;
	}

	Vector3 Vector3::operator - (const float &a_fSubtrahendScalar)
	{
		Vector3 temp = (*this);

		temp.m_fX = m_fX - a_fSubtrahendScalar;
		temp.m_fY = m_fY - a_fSubtrahendScalar;
		temp.m_fZ = m_fZ - a_fSubtrahendScalar;
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

		temp.m_fX = temp.m_fX * a_fScalar;
		temp.m_fY = temp.m_fY * a_fScalar;
		temp.m_fZ = temp.m_fZ * a_fScalar;

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

		temp.m_fX = temp.m_fX / a_fScalar;
		temp.m_fY = temp.m_fY / a_fScalar;
		temp.m_fZ = temp.m_fZ / a_fScalar;

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

		m_fX = a_Source.m_fX;
		m_fY = a_Source.m_fY;
		m_fZ = a_Source.m_fZ;
	
		return *this;
	}

	bool	Vector3::operator == (const Vector3 &a_Source)
	{
		if(m_fX == a_Source.m_fX &&
		   m_fY == a_Source.m_fY &&
		   m_fZ == a_Source.m_fZ
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