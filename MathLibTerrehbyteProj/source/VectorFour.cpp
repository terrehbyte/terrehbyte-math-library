//////////////////////////////////////////////////////////////////////////
//	File:	VectorFour.cpp
//	Author:	Terry Nguyen
//	Date:	03/06/2014
//	Brief:	Defines functions pertaining to Vector4D
//
//////////////////////////////////////////////////////////////////////////

#include <TerrehByteMath.h>

namespace tbyte
{
	Vector4::Vector4()
	{
	}
	
	Vector4::Vector4(const float &a_fX, const float &a_fY, const float &a_fZ, const float &a_fW)
	{
		m_fX = a_fX;
		m_fY = a_fY;
		m_fZ = a_fZ;
		m_fW = a_fW;
	}

	Vector4::Vector4(const Vector4 &a_Source)
	{
		m_fX = a_Source.m_fX;
		m_fY = a_Source.m_fY;
		m_fZ = a_Source.m_fZ;
		m_fW = a_Source.m_fW;
	}

	Vector4::~Vector4()
	{
	}

	float	Vector4::Magnitude()
	{
		return sqrt(m_fX * m_fX +
					m_fY * m_fY + 
					m_fZ * m_fZ +
					m_fW * m_fW);
	}

	/*
	can check returned Vector4 for Vector4(0,0,0,0) to see if failed
	*/
	Vector4 Vector4::Normal()
	{
		Vector4 temp = (*this);

		float fMagnitude = Magnitude();

		//if magnitude == 0, return empty vector
		if (fMagnitude == 0)
			return Vector4(0,0,0,0);

		temp /= fMagnitude;
		temp.m_fW = 0;

		return temp;
	}
	
	/*
	return true if able to normalize else returns false (i.e. Magnitude() == 0
	*/
	bool Vector4::Normalise()
	{
		float fMag = Magnitude();
		if (fMag == 0)
			return false;
		m_fX /= fMag;
		m_fY /= fMag;
		m_fZ /= fMag;
		m_fW = 0;
		return true;
	}

	Vector4 Vector4::ConstructFromHex(float a_iRED,
		                              float a_iGREEN,
		                              float a_iBLUE,
		                              float a_iALPHA)
	{
        Vector4 Color;
		
        Color.m_fW = a_iRED   / 255;
		Color.m_fX = a_iGREEN / 255;
		Color.m_fY = a_iBLUE  / 255;
		Color.m_fZ = a_iALPHA / 255;

		return (Color);
	}

	Vector4 Vector4::ConstructFromHex(int a_iHEXValue)
	{	
        Vector4 Color;

		Color.m_fW = ((a_iHEXValue >> 24) & 0xFF) / 255.0f;
		Color.m_fX = ((a_iHEXValue >> 16) & 0xFF) / 255.0f;
		Color.m_fY = ((a_iHEXValue >> 8) & 0xFF) / 255.0f;
		Color.m_fZ = ((a_iHEXValue) & 0xFF) / 255.0f;

		return (Color);
	}
	Vector4 Vector4::CrossProduct(const Vector4 &a_Term) 
	{
		return Vector4(m_fY * a_Term.m_fZ - a_Term.m_fY * m_fZ,
				       m_fZ * a_Term.m_fX - a_Term.m_fZ * m_fX,
                       m_fX * a_Term.m_fY - a_Term.m_fX * m_fY,
                       0);
	} 
	float Vector4::DotProduct(const Vector4 &a_Term)
	{
		return m_fX * a_Term.m_fX +
               m_fY * a_Term.m_fY +
               m_fZ * a_Term.m_fZ;
	}

	
	Vector4 Vector4::operator + (const Vector4 &a_Addend)
	{
		// Create a temp Vector4
		Vector4 temp = (*this);

		// Add temp's X and Y to the other X and Y
		temp.m_fX += a_Addend.m_fX;
		temp.m_fY += a_Addend.m_fY;
		temp.m_fZ += a_Addend.m_fZ;
        temp.m_fW += a_Addend.m_fW;

		// Return temp, the sum of two Vector4 things
		return temp;
	}
	
	Vector4 Vector4::operator + (const float &a_fAddendScalar)
	{
		/*
		adding scalar to vector MAKES NO SENSE!!
		*/
		// Create a temp Vector4
		Vector4 temp = (*this);

		// Add temp's X and Y to the other X and Y
		temp.m_fW += a_fAddendScalar;
		temp.m_fX += a_fAddendScalar;
		temp.m_fY += a_fAddendScalar;
		temp.m_fZ += a_fAddendScalar;

		// Return temp, the sum of two Vector4 things
		return temp;
	}

	Vector4& Vector4::operator += (const Vector4 &a_Addend)
	{
		(*this) = (*this) + a_Addend;
		return (*this);
	}

	Vector4& Vector4::operator += (const float &a_fAddendScalar)
	{
		(*this) = (*this) + a_fAddendScalar;
		return (*this);
	}

	Vector4	Vector4::operator - (const Vector4 &a_Subtrahend)
	{
		Vector4 temp = (*this);

		temp.m_fW -= a_Subtrahend.m_fW;
		temp.m_fX -= a_Subtrahend.m_fX;
		temp.m_fY -= a_Subtrahend.m_fY;
		temp.m_fZ -= a_Subtrahend.m_fZ;
		return temp;
	}

	Vector4 Vector4::operator - (const float &a_fSubtrahendScalar)
	{
		Vector4 temp = (*this);
		
		temp.m_fW -= a_fSubtrahendScalar;
		temp.m_fX -= a_fSubtrahendScalar;
		temp.m_fY -= a_fSubtrahendScalar;
		temp.m_fZ -= a_fSubtrahendScalar;

		return temp;
	}

	Vector4& Vector4::operator -= (const Vector4 &a_Subtrahend)
	{
		(*this) = (*this) - a_Subtrahend;
		return (*this);
	}

	Vector4& Vector4::operator -= (const float &a_fSubtrahendScalar)
	{
		(*this) = (*this) - a_fSubtrahendScalar;
		return (*this);
	}

	Vector4 Vector4::operator * (const float &a_fScalar)
	{
		Vector4 temp = (*this);

		temp.m_fW *= a_fScalar;
		temp.m_fX *= a_fScalar;
		temp.m_fY *= a_fScalar;
		temp.m_fZ *= a_fScalar;

		return temp;
	}

	Vector4& Vector4::operator *= (const float &a_fScalar)
	{
		(*this) = (*this) * a_fScalar;
		return (*this);
	}

	Vector4 Vector4::operator / (const float &a_fScalar)
	{
		Vector4 temp = (*this);

		temp.m_fW /= a_fScalar;
		temp.m_fX /= a_fScalar;
		temp.m_fY /= a_fScalar;
		temp.m_fZ /= a_fScalar;

		return temp;
	}

	Vector4& Vector4::operator /= (const float &a_fScalar)
	{
		(*this) = (*this) / a_fScalar;
		return (*this);
	}

	Vector4& Vector4::operator = (const Vector4 &a_Source)
	{
		// avoid self-assignment
		if (this == &a_Source)
		{
			return *this;
		}

		m_fX = a_Source.m_fX;
		m_fY = a_Source.m_fY;
		m_fZ = a_Source.m_fZ;
		m_fW = a_Source.m_fW;
		return *this;
	}

	bool Vector4::operator == (const Vector4 &a_Source)
	{
		if (m_fX == a_Source.m_fX &&
			m_fY == a_Source.m_fY &&
			m_fZ == a_Source.m_fZ &&
            m_fW == a_Source.m_fW)
		{
			return true;
		}

		else
		{
			return false;
		}
	}
	
	bool Vector4::operator!=(const Vector4& rhs)
	{
		return !(*this == rhs);
	}
}
