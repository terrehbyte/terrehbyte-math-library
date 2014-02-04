//////////////////////////////////////////////////////////////////////////
//	File:	VectorThree.cpp
//	Author:	Terry Nguyen
//	Date:	12/18/2013
//	Brief:	Defines functions pertaining to Vector3D
//
//////////////////////////////////////////////////////////////////////////

#include "VectorFour.h"

namespace tbyte
{
	Vector4::Vector4()
	{
	}
	
	Vector4::Vector4(const float a_m_fW, const float a_m_fX, const float a_m_fY, const float a_m_fZ)
	{
		m_fW = a_m_fW;
		m_fX = a_m_fX;
		m_fY = a_m_fY;
		m_fZ = a_m_fZ;
	}

	Vector4::~Vector4()
	{
	}

	float	Vector4::Magnitude()
	{
		float fFirst	= m_fW * m_fW;
		float fSecond	= m_fX * m_fX;
		float fThird	= m_fY * m_fY;
		float fFourth	= m_fZ * m_fZ;
		
		return sqrt(fFirst + fSecond + fThird + fFourth);
	}

	Vector4 Vector4::Normal()
	{
		Vector4 temp = (*this);

		float fMagnitude = Magnitude();

		temp /= fMagnitude;
		temp.m_fW = 0;		
		return temp;
	}
	void Vector4::Normalise()
	{
		float fMag = sqrtf(m_fX*m_fX + m_fY*m_fY + m_fZ*m_fZ);
		m_fX /= fMag;
		m_fY /= fMag;
		m_fZ /= fMag;
		m_fW = 0;
	}

	Vector4 Vector4::ConstructFromHex(
		float a_iRED,
		float a_iGREEN,
		float a_iBLUE,
		float a_iALPHA
		)
	{	
		m_fW = a_iRED   / 255;
		m_fX = a_iGREEN / 255;
		m_fY = a_iBLUE  / 255;
		m_fZ = a_iALPHA / 255;

		return (*this);
	}

	Vector4 Vector4::ConstructFromHex(int a_iHEXValue)
	{	
		m_fW = ((a_iHEXValue >> 24) & 0xFF) / 255.0;
		m_fX = ((a_iHEXValue >> 16) & 0xFF) / 255.0;
		m_fY = ((a_iHEXValue >> 8) & 0xFF) / 255.0;
		m_fZ = ((a_iHEXValue) & 0xFF) / 255.0;

		return (*this);
	}
	 Vector4 Vector4::CrossProduct(const Vector4 &a_Term) 
	{
		return Vector4(m_fY * a_Term.m_fZ - a_Term.m_fY  * m_fZ, m_fZ * a_Term.m_fX - a_Term.m_fZ * m_fX, m_fX * a_Term.m_fY  - a_Term.m_fX * m_fY , 0);
	} 
	float Vector4::DotProduct(const Vector4 &a_Term)
	{
		return m_fX * a_Term.m_fX + m_fY * a_Term.m_fY + m_fZ * a_Term.m_fZ;
	}

	
	Vector4 Vector4::operator + (const Vector4 &a_Addend)
	{
		// Create a temp Vector4
		Vector4 temp = (*this);

		// Add temp's X and Y to the other X and Y
		temp.m_fW = temp.m_fW + a_Addend.m_fW;
		temp.m_fX = temp.m_fX + a_Addend.m_fX;
		temp.m_fY = temp.m_fY + a_Addend.m_fY;
		temp.m_fZ = temp.m_fZ + a_Addend.m_fZ;

		// Return temp, the sum of two Vector4 things
		return temp;
	}
	
	Vector4 Vector4::operator + (const float &a_fAddendScalar)
	{
		// Create a temp Vector4
		Vector4 temp = (*this);

		// Add temp's X and Y to the other X and Y
		temp.m_fW = temp.m_fW + a_fAddendScalar;
		temp.m_fX = temp.m_fX + a_fAddendScalar;
		temp.m_fY = temp.m_fY + a_fAddendScalar;
		temp.m_fZ = temp.m_fZ + a_fAddendScalar;

		// Return temp, the sum of two Vector4 things
		return temp;
	}

	Vector4	Vector4::operator += (const Vector4 &a_Addend)
	{
		(*this) = (*this) + a_Addend;
		return (*this);
	}

	Vector4 Vector4::operator += (const float &a_fAddendScalar)
	{
		(*this) = (*this) + a_fAddendScalar;
		return (*this);
	}

	Vector4	Vector4::operator - (const Vector4 &a_Subtrahend)
	{
		Vector4 temp = (*this);

		temp.m_fW = m_fW - a_Subtrahend.m_fW;
		temp.m_fX = m_fX - a_Subtrahend.m_fX;
		temp.m_fY = m_fY - a_Subtrahend.m_fY;
		temp.m_fZ = m_fZ - a_Subtrahend.m_fZ;
		return temp;
	}

	Vector4 Vector4::operator - (const float &a_fSubtrahendScalar)
	{
		Vector4 temp = (*this);
		
		temp.m_fW = temp.m_fW - a_fSubtrahendScalar;
		temp.m_fX = temp.m_fX - a_fSubtrahendScalar;
		temp.m_fY = temp.m_fY - a_fSubtrahendScalar;
		temp.m_fZ = temp.m_fZ - a_fSubtrahendScalar;

		return temp;
	}

	Vector4	Vector4::operator -= (const Vector4 &a_Subtrahend)
	{
		(*this) = (*this) - a_Subtrahend;
		return (*this);
	}

	Vector4	Vector4::operator -= (const float &a_fSubtrahendScalar)
	{
		(*this) = (*this) - a_fSubtrahendScalar;
		return (*this);
	}

	Vector4 Vector4::operator * (const float &a_fScalar)
	{
		Vector4 temp = (*this);

		temp.m_fW = temp.m_fW * a_fScalar;
		temp.m_fX = temp.m_fX * a_fScalar;
		temp.m_fY = temp.m_fY * a_fScalar;
		temp.m_fZ = temp.m_fZ * a_fScalar;

		return temp;
	}

	Vector4 Vector4::operator *= (const float &a_fScalar)
	{
		(*this) = (*this) * a_fScalar;
		return (*this);
	}

	Vector4 Vector4::operator / (const float &a_fScalar)
	{
		Vector4 temp = (*this);

		temp.m_fW = temp.m_fW / a_fScalar;
		temp.m_fX = temp.m_fX / a_fScalar;
		temp.m_fY = temp.m_fY / a_fScalar;
		temp.m_fZ = temp.m_fZ / a_fScalar;

		return temp;
	}

	Vector4 Vector4::operator /= (const float &a_fScalar)
	{
		(*this) = (*this) / a_fScalar;
		return (*this);
	}

	// Assignment Operator - Assigns the values of an existing Vector4 to another existing Vector4
	Vector4	Vector4::operator = (const Vector4 &a_Source)
	{
		m_fW = a_Source.m_fW;
		m_fX = a_Source.m_fX;
		m_fY = a_Source.m_fY;
		m_fZ = a_Source.m_fZ;
		
		return *this;
	}

	bool	Vector4::operator == (const Vector4 &a_Source)
	{
		if (m_fW == a_Source.m_fW &&
			m_fX == a_Source.m_fX &&
			m_fY == a_Source.m_fY &&
			m_fZ == a_Source.m_fZ)
		{
			return true;
		}

		else
		{
			return false;
		}
	}
}
