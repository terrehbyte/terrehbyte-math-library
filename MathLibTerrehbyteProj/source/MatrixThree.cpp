//////////////////////////////////////////////////////////////////////////
//	File:	MatrixThree.cpp
//	Author:	Terry Nguyen
//	Date:	12/18/2013
//	Brief:	Defines functions pertaining to Matrix3
//
//////////////////////////////////////////////////////////////////////////

#include <TerrehByteMath.h>

namespace tbyte
{
	Matrix3::Matrix3()
	{
	}

    Matrix3::Matrix3(const float &a_f0,
                     const float &a_f1,
                     const float &a_f2,
                     const float &a_f3,
                     const float &a_f4,
                     const float &a_f5,
                     const float &a_f6,
                     const float &a_f7,
                     const float &a_f8)
    {
        m_afArray[0] = a_f0;
        m_afArray[1] = a_f1;
        m_afArray[2] = a_f2;
        m_afArray[3] = a_f3;
        m_afArray[4] = a_f4;
        m_afArray[5] = a_f5;
        m_afArray[6] = a_f6;
        m_afArray[7] = a_f7;
        m_afArray[8] = a_f8;
    }

	Matrix3::Matrix3(const Matrix3 &a_Source)
	{
		for (int i = 0;
			 i < 9;
			 i++)
		{
			m_afArray[i] = a_Source.m_afArray[i];
		}
	}

	Matrix3::~Matrix3()
	{
	}

	void Matrix3::Transpose()
	{
		
		//hard coded more efficient than for loop
		
			m_afArray[0] = m_afArray[0];
			m_afArray[1] = m_afArray[3];
			m_afArray[2] = m_afArray[6];
			m_afArray[3] = m_afArray[1];
			m_afArray[4] = m_afArray[4];
			m_afArray[5] = m_afArray[7];
			m_afArray[6] = m_afArray[2];
			m_afArray[7] = m_afArray[5];
			m_afArray[8] = m_afArray[8];
		

	}

	tbyte::Vector4 Matrix3::VectorTransform(const tbyte::Vector4 &a_Point)
	{
		tbyte::Vector4 temp;
		temp.m_fX = a_Point.m_fX * m_afArray[0] + a_Point.m_fY * m_afArray[1] + a_Point.m_fZ * m_afArray[2];
		temp.m_fY = a_Point.m_fX * m_afArray[3] + a_Point.m_fY * m_afArray[4] + a_Point.m_fZ * m_afArray[5];
		temp.m_fZ = a_Point.m_fX * m_afArray[6] + a_Point.m_fY * m_afArray[7] + a_Point.m_fZ * m_afArray[8];
		temp.m_fW = a_Point.m_fW;
		return temp;
	}

	tbyte::Vector3 Matrix3::VectorTransform(const tbyte::Vector3 &a_Point)
	{
		tbyte::Vector3 temp;
		temp.m_fX = a_Point.m_fX * m_afArray[0] + a_Point.m_fY * m_afArray[1] + a_Point.m_fZ * m_afArray[2];
		temp.m_fY = a_Point.m_fX * m_afArray[3] + a_Point.m_fY * m_afArray[4] + a_Point.m_fZ * m_afArray[5];
		temp.m_fZ = a_Point.m_fX * m_afArray[6] + a_Point.m_fY * m_afArray[7] + a_Point.m_fZ * m_afArray[8];
		return temp;
	}

	Matrix3 Matrix3::IdentityMatrix()
	{
		Matrix3 temp;

		temp.m_afArray[0] = 1;
		temp.m_afArray[3] = 0;
		temp.m_afArray[6] = 0;
		
		temp.m_afArray[1] = 0;
		temp.m_afArray[4] = 1;
		temp.m_afArray[7] = 0;

		temp.m_afArray[2] = 0;
		temp.m_afArray[5] = 0;
		temp.m_afArray[8] = 1;

		return temp;
	}

	float Matrix3::Determinant()
	{
		float fDeterminant;

		float fTermA = m_afArray[0] * (m_afArray[4] * m_afArray[8] - m_afArray[7] * m_afArray[5]);
		float fTermB = m_afArray[3] * (m_afArray[1] * m_afArray[8] - m_afArray[7] * m_afArray[2]);
		float fTermC = m_afArray[6] * (m_afArray[1] * m_afArray[5] - m_afArray[7] * m_afArray[2]);

		fDeterminant = fTermA + fTermB + fTermC;

		return fDeterminant;
	}

	tbyte::Vector4 Matrix3::Scale(const tbyte::Vector4 &a_Vector)
	{
		return VectorTransform(a_Vector);
	}

	tbyte::Vector3 Matrix3::Scale(const tbyte::Vector3 &a_Vector)
	{
		return VectorTransform(a_Vector);
	}

	Matrix3 Matrix3::MakeXRotationMatrix(float a_Radians)
	{
		Matrix3 temp;

		temp.m_afArray[0] = 1;
		temp.m_afArray[3] = 0;
		temp.m_afArray[6] = 0;
		
		temp.m_afArray[1] = 0;
		// float imprecision http://stackoverflow.com/questions/1605435/cosfm-pi-2-not-returning-zero
		temp.m_afArray[4] = std::cos(a_Radians);
		temp.m_afArray[7] = std::sin(a_Radians);

		temp.m_afArray[2] = 0;
		temp.m_afArray[5] = std::sin(a_Radians) * -1;
		temp.m_afArray[8] = std::cos(a_Radians);

	    return temp;
	}
	
	Matrix3 Matrix3::MakeYRotationMatrix(float a_Radians)
	{
		Matrix3 temp;

		temp.m_afArray[0] = std::cos(a_Radians);
		temp.m_afArray[3] = 0;
		temp.m_afArray[6] = std::sin(a_Radians) * -1;
		
		temp.m_afArray[1] = 0;
		temp.m_afArray[4] = 1;
		temp.m_afArray[7] = 0;

		temp.m_afArray[2] = std::sin(a_Radians);
		temp.m_afArray[5] = 0;
		temp.m_afArray[8] = std::cos(a_Radians);

		return temp;
	}
	
	Matrix3 Matrix3::MakeZRotationMatrix(float a_Radians)
	{
		Matrix3 temp;

		temp.m_afArray[0] = std::cos(a_Radians);
		temp.m_afArray[3] = std::sin(a_Radians) * -1;
		temp.m_afArray[6] = 0;
		
		temp.m_afArray[1] = std::sin(a_Radians);
		temp.m_afArray[4] = std::cos(a_Radians);
		temp.m_afArray[7] = 0;

		temp.m_afArray[2] = 0;
		temp.m_afArray[5] = 0;
		temp.m_afArray[8] = 1;

		return temp;
	}


	// OPERATORS
	Matrix3 Matrix3::operator+ (const Matrix3 &a_Addend)
	{
		Matrix3 tempMatrix = *this;

		for (int i = 0;i < 9;i++)
		{
			
				tempMatrix.m_afArray[i] += a_Addend.m_afArray[i];
			
		}

		return tempMatrix;
	}

	Matrix3 Matrix3::operator+ (const float &a_fAddendScalar)
	{
		Matrix3 tempMatrix = *this;

		for (int i = 0;i < 9;i++)
		{
			
				tempMatrix.m_afArray[i] += a_fAddendScalar;
			
		}


		return tempMatrix;
	}

	Matrix3 Matrix3::operator+= (const Matrix3 &a_Addend)
	{
		(*this) = (*this) + a_Addend;
		return (*this);
	}

	Matrix3 Matrix3::operator+= (const float &a_fAddendScalar)
	{
		(*this) = (*this) + a_fAddendScalar;
		return (*this);
	}

	Matrix3 Matrix3::operator- (const Matrix3 &a_Subtrahend)
	{
		Matrix3 tempMatrix = *this;

	for (int i = 0;i < 9;i++)
		{
			
				tempMatrix.m_afArray[i] -= a_Subtrahend.m_afArray[i];
			
		}

		return tempMatrix;
	}

	Matrix3 Matrix3::operator- (const float &a_fSubtrahendScalar)
	{
		Matrix3 tempMatrix = *this;

		for (int i = 0;i < 9;i++)
		{
			
				tempMatrix.m_afArray[i] -= a_fSubtrahendScalar;
			
		}

		return tempMatrix;
	}

	Matrix3 Matrix3::operator-= (const Matrix3 &a_Subtrahend)
	{
		(*this) =  (*this) - a_Subtrahend;
		return (*this);
	}

	Matrix3 Matrix3::operator-= (const float &a_fSubtrahendScalar)
	{
		(*this) = (*this) - a_fSubtrahendScalar;
		return (*this);
	}

	Matrix3	Matrix3::operator * (const Matrix3 &a_Factor)
	{
		Matrix3 tempMatrix;

		tempMatrix.m_afArray[0] =	m_afArray[0] * a_Factor.m_afArray[0] +
										m_afArray[3] * a_Factor.m_afArray[1] +
										m_afArray[6] * a_Factor.m_afArray[2];

		tempMatrix.m_afArray[3] =	m_afArray[0] * a_Factor.m_afArray[3] +
										m_afArray[3] * a_Factor.m_afArray[4] +
										m_afArray[6] * a_Factor.m_afArray[5];
		
		tempMatrix.m_afArray[6] =	m_afArray[0] * a_Factor.m_afArray[6] +
										m_afArray[3] * a_Factor.m_afArray[7] +
										m_afArray[6] * a_Factor.m_afArray[8];


		tempMatrix.m_afArray[1] =	m_afArray[1] * a_Factor.m_afArray[0] +
										m_afArray[4] * a_Factor.m_afArray[1] +
										m_afArray[7] * a_Factor.m_afArray[2];

		tempMatrix.m_afArray[4] =	m_afArray[1] * a_Factor.m_afArray[3] +
										m_afArray[4] * a_Factor.m_afArray[4] +
										m_afArray[7] * a_Factor.m_afArray[5];

		tempMatrix.m_afArray[7] =	m_afArray[1] * a_Factor.m_afArray[6] +
										m_afArray[4] * a_Factor.m_afArray[7] + 
										m_afArray[7] * a_Factor.m_afArray[8];

		tempMatrix.m_afArray[2] =	m_afArray[2] * a_Factor.m_afArray[0] +
										m_afArray[5] * a_Factor.m_afArray[1] +
										m_afArray[8] * a_Factor.m_afArray[2];

		tempMatrix.m_afArray[5] =	m_afArray[2] * a_Factor.m_afArray[3] +
										m_afArray[5] * a_Factor.m_afArray[4] +
										m_afArray[8] * a_Factor.m_afArray[5];
		
		tempMatrix.m_afArray[8] =	m_afArray[2] * a_Factor.m_afArray[6] +
										m_afArray[5] * a_Factor.m_afArray[7] +
										m_afArray[8] * a_Factor.m_afArray[8];

		return tempMatrix;
	}

	Matrix3	Matrix3::operator * (const float &a_fFactorScalar)
	{
		Matrix3 tempMatrix = *this;

		for (int i = 0;i < 9;i++)
		{
			
				tempMatrix.m_afArray[i] *= a_fFactorScalar;
			
		}


		return tempMatrix;
	}

	Matrix3 Matrix3::operator = (const Matrix3 &a_Source)
	{
		// avoid self-assignment
		if (this == &a_Source)
		{
			return *this;
		}

		for (int i = 0;i < 9;i++)
		{
			
			m_afArray[i] = a_Source.m_afArray[i];
			
		}

		return *this;
	}

	Matrix3 Matrix3::operator*= (const Matrix3 &a_Factor)
	{
		(*this) = (*this) * a_Factor;
		return (*this);
	}

	Matrix3 Matrix3::operator*= (const float &a_FactorScalar)
	{
		(*this) = (*this) * a_FactorScalar;
		return (*this);
	}

	bool Matrix3::operator == (const Matrix3 &a_Source)
	{
		for (int i = 0;i < 9;i++)
		{
			
			if(m_afArray[i] != a_Source.m_afArray[i])
					return false;
				
			
		}

		return true;
	}
}
