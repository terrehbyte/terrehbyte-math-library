//////////////////////////////////////////////////////////////////////////
//	File:	MatrixFour.cpp
//	Author:	Terry Nguyen
//	Date:	12/18/2013
//	Brief:	Defines functions pertaining to Matrix4
//
//////////////////////////////////////////////////////////////////////////

#include <TerrehByteMath.h>

namespace tbyte
{
	Matrix4::Matrix4()
	{
	}

    Matrix4::Matrix4(const float &a_f0,
                     const float &a_f1,
                     const float &a_f2,
                     const float &a_f3,
                     const float &a_f4,
                     const float &a_f5,
                     const float &a_f6,
                     const float &a_f7,
                     const float &a_f8,
                     const float &a_f9,
                     const float &a_f10,
                     const float &a_f11,
                     const float &a_f12,
                     const float &a_f13,
                     const float &a_f14,
                     const float &a_f15)
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
        m_afArray[9] = a_f9;
        m_afArray[10] = a_f10;
        m_afArray[11] = a_f11;
        m_afArray[12] = a_f12;
        m_afArray[13] = a_f13;
        m_afArray[14] = a_f14;
        m_afArray[15] = a_f15;
    }

	Matrix4::Matrix4(const Matrix4 &a_Source)
	{
		for (int i = 0;
			 i < 16;
			 i++)
		{
			m_afArray[i] = a_Source.m_afArray[i];
		}
	}

	Matrix4::~Matrix4()
	{
	}

	void Matrix4::Transpose()
	{
		m_afArray[0] = m_afArray[0];
		m_afArray[4] = m_afArray[1];
		m_afArray[8] = m_afArray[2];
		m_afArray[12] = m_afArray[3];

		m_afArray[1] = m_afArray[4];
		m_afArray[5] = m_afArray[5];
		m_afArray[9] = m_afArray[6];
		m_afArray[13] = m_afArray[7];

		m_afArray[2] = m_afArray[8];
		m_afArray[6] = m_afArray[9];
		m_afArray[10] = m_afArray[10];
		m_afArray[14] = m_afArray[11];

		m_afArray[3] = m_afArray[12];
		m_afArray[7] = m_afArray[13];
		m_afArray[11] = m_afArray[14];
		m_afArray[15] = m_afArray[15];
	}
	Matrix4 Matrix4::IdentityMatrix()
	{
		Matrix4 temp;

		temp.m_afArray[0] =  1;
		temp.m_afArray[4] =  0;
		temp.m_afArray[8] =  0;
		temp.m_afArray[12] = 0;

		temp.m_afArray[1] =  0;
		temp.m_afArray[5] =  1;
		temp.m_afArray[9] =  0;
		temp.m_afArray[13] = 0;

		temp.m_afArray[2] =  0;
		temp.m_afArray[6] =  0;
		temp.m_afArray[10] = 1;
		temp.m_afArray[14] = 0;

		temp.m_afArray[3] =  0;
		temp.m_afArray[7] =  0;
		temp.m_afArray[11] = 0;
		temp.m_afArray[15] = 1;

		return temp;
	}

	tbyte::Vector4 Matrix4::PointTransform(const tbyte::Vector4 &a_Point)
	{
		tbyte::Vector4 temp;

		temp.m_fX = a_Point.m_fX * m_afArray[0] + a_Point.m_fY * m_afArray[4] + a_Point.m_fY * m_afArray[8] + a_Point.m_fW * m_afArray[12];
		temp.m_fY = a_Point.m_fX * m_afArray[1] + a_Point.m_fY * m_afArray[5] + a_Point.m_fY * m_afArray[9] + a_Point.m_fW * m_afArray[13];
		temp.m_fZ = a_Point.m_fX * m_afArray[2] + a_Point.m_fY * m_afArray[6] + a_Point.m_fY * m_afArray[10] + a_Point.m_fW * m_afArray[14];
		temp.m_fW = a_Point.m_fX * m_afArray[3] + a_Point.m_fY * m_afArray[7] + a_Point.m_fW * m_afArray[11] + a_Point.m_fW * m_afArray[15];

		if (temp.m_fW != 1 && temp.m_fW != 0)
		{
			temp.m_fX /= temp.m_fW;
			temp.m_fY /= temp.m_fW;
			temp.m_fZ /= temp.m_fW;
			temp.m_fW /= temp.m_fW;
		}

		return temp;
	}

	Matrix4 Matrix4::MakeOrthoProj(const float &a_fLeft,
                                         const float &a_fRight,
                                         const float &a_fTop,
                                         const float &a_fBottom,
                                         const float &a_fFar,
                                         const float &a_fNear,
                                         Matrix4 * a_Dest)
	{
        // If there isn't a destination, just make one and return it
        if (a_Dest == nullptr)
        {
		    Matrix4 OrthoProj;


		    OrthoProj.m_afArray[0] = 2.0f / (a_fRight - a_fLeft);
            OrthoProj.m_afArray[1] = 0.0f;
            OrthoProj.m_afArray[2] = 0.0f;
            OrthoProj.m_afArray[3] = 0.0f;
            OrthoProj.m_afArray[4] = 0.0f;
		    OrthoProj.m_afArray[5] = 2.0f / (a_fTop - a_fBottom);
            OrthoProj.m_afArray[6] = 0.0f;
            OrthoProj.m_afArray[7] = 0.0f;
            OrthoProj.m_afArray[8] = 0.0f;
            OrthoProj.m_afArray[9] = 0.0f;
		    OrthoProj.m_afArray[10] = 2.0f / (a_fNear - a_fFar);
            OrthoProj.m_afArray[11] = 0.0f;
            OrthoProj.m_afArray[12] = (a_fLeft + a_fRight) / (a_fLeft - a_fRight);
            OrthoProj.m_afArray[13] = (a_fBottom + a_fTop) / (a_fBottom - a_fTop);
            OrthoProj.m_afArray[14] = (-(a_fNear + a_fFar)/(a_fFar - a_fNear));
            OrthoProj.m_afArray[15] = 1.0f;

		    return OrthoProj;
        }
        // If there is a destination, return a copy of that matrix4 after we're done modifying it
        else
        {
		    a_Dest->m_afArray[0] = 2.0f / (a_fRight - a_fLeft);
            a_Dest->m_afArray[1] = 0.0f;
            a_Dest->m_afArray[2] = 0.0f;
            a_Dest->m_afArray[3] = 0.0f;
            a_Dest->m_afArray[4] = 0.0f;
		    a_Dest->m_afArray[5] = 2.0f / (a_fTop - a_fBottom);
            a_Dest->m_afArray[6] = 0.0f;
            a_Dest->m_afArray[7] = 0.0f;
            a_Dest->m_afArray[8] = 0.0f;
            a_Dest->m_afArray[9] = 0.0f;
		    a_Dest->m_afArray[10] = 2.0f / (a_fNear - a_fFar);
            a_Dest->m_afArray[11] = 0.0f;
            a_Dest->m_afArray[12] = (a_fLeft + a_fRight) / (a_fLeft - a_fRight);
            a_Dest->m_afArray[13] = (a_fBottom + a_fTop) / (a_fBottom - a_fTop);
            a_Dest->m_afArray[14] = (-(a_fNear + a_fFar)/(a_fFar - a_fNear));
            a_Dest->m_afArray[15] = 1.0f;

            return *a_Dest;
        }

	}

	tbyte::Vector4 Matrix4::Scale(const tbyte::Vector4 &a_Vector)
	{
		return VectorTransform(a_Vector);
	}

	tbyte::Vector3 Matrix4::Scale(const tbyte::Vector3 &a_Vector)
	{
		return VectorTransform(a_Vector);
	}

	Matrix4 Matrix4::MakeXRotationMatrix(float a_Radians)
	{
		Matrix4 temp;

		temp.m_afArray[0] = 1;
		temp.m_afArray[4] = 0;
		temp.m_afArray[8] = 0;

		temp.m_afArray[1] = 0;
		temp.m_afArray[5] = std::cos(a_Radians);
		temp.m_afArray[9] = std::sin(a_Radians);

		temp.m_afArray[2] = 0;
		temp.m_afArray[6] = std::sin(a_Radians) * -1;
		temp.m_afArray[10] = std::cos(a_Radians);

		return temp;
	}

	Matrix4 Matrix4::MakeYRotationMatrix(float a_Radians)
	{
		Matrix4 temp;

		temp.m_afArray[0] = std::cos(a_Radians);
		temp.m_afArray[4] = 0;
		temp.m_afArray[8] = std::sin(a_Radians) * -1;

		temp.m_afArray[1] = 0;
		temp.m_afArray[5] = 1;
		temp.m_afArray[9] = 0;

		temp.m_afArray[2] = std::sin(a_Radians);
		temp.m_afArray[6] = 0;
		temp.m_afArray[10] = std::cos(a_Radians);

		return temp;
	}

	Matrix4 Matrix4::MakeZRotationMatrix(float a_Radians)
	{
		Matrix4 temp;

		temp.m_afArray[0] = std::cos(a_Radians);
		temp.m_afArray[4] = std::sin(a_Radians);
		temp.m_afArray[8] = 0;

		temp.m_afArray[1] = std::sin(a_Radians) * -1;
		temp.m_afArray[5] = std::cos(a_Radians);
		temp.m_afArray[9] = 0;

		temp.m_afArray[2] = 0;
		temp.m_afArray[6] = 0;
		temp.m_afArray[10] = 1;

		return temp;
	}

    tbyte::Vector4 Matrix4::VectorTransform(const tbyte::Vector4 &a_Vector)
	{
		tbyte::Vector4 temp;
		temp.m_fX = a_Vector.m_fX * m_afArray[0] + a_Vector.m_fY * m_afArray[4] + a_Vector.m_fZ * m_afArray[8] + a_Vector.m_fW * m_afArray[12];
		temp.m_fY = a_Vector.m_fX * m_afArray[1] + a_Vector.m_fY * m_afArray[5] + a_Vector.m_fZ * m_afArray[9] + a_Vector.m_fW * m_afArray[13];
		temp.m_fZ = a_Vector.m_fX * m_afArray[2] + a_Vector.m_fY * m_afArray[6] + a_Vector.m_fZ * m_afArray[10] + a_Vector.m_fW * m_afArray[14];
		temp.m_fW = a_Vector.m_fX * m_afArray[3] + a_Vector.m_fY * m_afArray[7] + a_Vector.m_fZ * m_afArray[11] + a_Vector.m_fW * m_afArray[15];

		return temp;
	}

	tbyte::Vector3 Matrix4::VectorTransform(const tbyte::Vector3 &a_Vector)
	{
		tbyte::Vector3 temp;
		temp.m_fX = a_Vector.m_fX * m_afArray[0] + a_Vector.m_fY * m_afArray[3] + a_Vector.m_fZ * m_afArray[6];
		temp.m_fY = a_Vector.m_fX * m_afArray[1] + a_Vector.m_fY * m_afArray[4] + a_Vector.m_fZ * m_afArray[7];
		temp.m_fZ = a_Vector.m_fX * m_afArray[2] + a_Vector.m_fY * m_afArray[5] + a_Vector.m_fZ * m_afArray[8];

		return temp;
	}

	Matrix4 Matrix4::operator +  (const Matrix4 &a_Addend)
	{
		Matrix4 tempMatrix = *this;

		for (int i = 0;
             i < 16;
             i++)
		{

			tempMatrix.m_afArray[i] += a_Addend.m_afArray[i];

		}

		return tempMatrix;
	}

	Matrix4 Matrix4::operator +  (const float &a_AddendScalar)
	{
		Matrix4 tempMatrix = *this;

		for (int i = 0;
             i < 16;
             i++)
		{

			tempMatrix.m_afArray[i] += a_AddendScalar;

		}

		return tempMatrix;
	}

	Matrix4 Matrix4::operator += (const Matrix4 &a_Addend)
	{
		(*this) = (*this) + a_Addend;
		return (*this);
	}

	Matrix4 Matrix4::operator += (const float &a_AddendScalar)
	{
		(*this) = (*this) + a_AddendScalar;
		return (*this);
	}

	Matrix4 Matrix4::operator -  (const Matrix4 &a_Subtrahend)
	{
		Matrix4 tempMatrix = *this;

		for (int i = 0;
             i < 16;
             i++)
		{

			tempMatrix.m_afArray[i] -= a_Subtrahend.m_afArray[i];

		}

		return tempMatrix;
	}

	Matrix4 Matrix4::operator -  (const float &a_SubtrahendScalar)
	{
		Matrix4 tempMatrix = *this;

		for (int i = 0;
             i < 16;
             i++)
		{
			tempMatrix.m_afArray[i] -= a_SubtrahendScalar;
		}

		return tempMatrix;
	}

	Matrix4 Matrix4::operator -= (const Matrix4 &a_Subtrahend)
	{
		(*this) = (*this) - a_Subtrahend;
		return (*this);
	}

	Matrix4 Matrix4::operator -= (const float &a_SubtrahendScalar)
	{
		(*this) = (*this) - a_SubtrahendScalar;
		return (*this);
	}

	Matrix4	Matrix4::operator *  (const Matrix4 &a_Factor)
	{
		Matrix4 tempMatrix;

		// row 1

		tempMatrix.m_afArray[0] =	m_afArray[0] * a_Factor.m_afArray[0] +
			m_afArray[4] * a_Factor.m_afArray[1] +
			m_afArray[8] * a_Factor.m_afArray[2] +
			m_afArray[12] * a_Factor.m_afArray[3];

		tempMatrix.m_afArray[4] =	m_afArray[0] * a_Factor.m_afArray[4] +
			m_afArray[4] * a_Factor.m_afArray[5] +
			m_afArray[8] * a_Factor.m_afArray[6] +
			m_afArray[12] * a_Factor.m_afArray[7];

		tempMatrix.m_afArray[8] =	m_afArray[0] * a_Factor.m_afArray[8] +
			m_afArray[4] * a_Factor.m_afArray[9] +
			m_afArray[8] * a_Factor.m_afArray[10] +
			m_afArray[12] * a_Factor.m_afArray[11];

		tempMatrix.m_afArray[12] =	m_afArray[0] * a_Factor.m_afArray[12] +
			m_afArray[4] * a_Factor.m_afArray[13] +
			m_afArray[8] * a_Factor.m_afArray[14] +
			m_afArray[12] * a_Factor.m_afArray[15];
		// row 2

		tempMatrix.m_afArray[1] =	m_afArray[1] * a_Factor.m_afArray[0] +
			m_afArray[5] * a_Factor.m_afArray[1] +
			m_afArray[9] * a_Factor.m_afArray[2] +
			m_afArray[13] * a_Factor.m_afArray[3];

		tempMatrix.m_afArray[5] =	m_afArray[1] * a_Factor.m_afArray[4] +
			m_afArray[5] * a_Factor.m_afArray[5] +
			m_afArray[9] * a_Factor.m_afArray[6] +
			m_afArray[13] * a_Factor.m_afArray[7];

		tempMatrix.m_afArray[9] =	m_afArray[1] * a_Factor.m_afArray[8] +
			m_afArray[5] * a_Factor.m_afArray[9] + 
			m_afArray[9] * a_Factor.m_afArray[10] +
			m_afArray[13] * a_Factor.m_afArray[11];

		tempMatrix.m_afArray[13] =	m_afArray[1] * a_Factor.m_afArray[12] +
			m_afArray[5] * a_Factor.m_afArray[13] + 
			m_afArray[9] * a_Factor.m_afArray[14] +
			m_afArray[13] * a_Factor.m_afArray[15];

		// row 3
		tempMatrix.m_afArray[2] =	m_afArray[2] * a_Factor.m_afArray[0] +
			m_afArray[6] * a_Factor.m_afArray[1] +
			m_afArray[10] * a_Factor.m_afArray[2] +
			m_afArray[14] * a_Factor.m_afArray[3];

		tempMatrix.m_afArray[6] =	m_afArray[2] * a_Factor.m_afArray[4] +
			m_afArray[6] * a_Factor.m_afArray[5] +
			m_afArray[10] * a_Factor.m_afArray[6] +
			m_afArray[14] * a_Factor.m_afArray[7];

		tempMatrix.m_afArray[10] =	m_afArray[2] * a_Factor.m_afArray[8] +
			m_afArray[6] * a_Factor.m_afArray[9] +
			m_afArray[10] * a_Factor.m_afArray[10] +
			m_afArray[14] * a_Factor.m_afArray[11];

		tempMatrix.m_afArray[14] =	m_afArray[2] * a_Factor.m_afArray[12] +
			m_afArray[6] * a_Factor.m_afArray[13] +
			m_afArray[10] * a_Factor.m_afArray[14] +
			m_afArray[14] * a_Factor.m_afArray[15];

		// row 4
		tempMatrix.m_afArray[3] =	m_afArray[3] * a_Factor.m_afArray[0] +
			m_afArray[7] * a_Factor.m_afArray[1] +
			m_afArray[11] * a_Factor.m_afArray[2] +
			m_afArray[15] * a_Factor.m_afArray[3];

		tempMatrix.m_afArray[7] =	m_afArray[3] * a_Factor.m_afArray[4] +
			m_afArray[7] * a_Factor.m_afArray[5] +
			m_afArray[11] * a_Factor.m_afArray[6] +
			m_afArray[15] * a_Factor.m_afArray[7];

		tempMatrix.m_afArray[11] =	m_afArray[3] * a_Factor.m_afArray[8] +
			m_afArray[7] * a_Factor.m_afArray[9] +
			m_afArray[11] * a_Factor.m_afArray[10] +
			m_afArray[15] * a_Factor.m_afArray[11];

		tempMatrix.m_afArray[15] =	m_afArray[3] * a_Factor.m_afArray[12] +
			m_afArray[7] * a_Factor.m_afArray[13] +
			m_afArray[11] * a_Factor.m_afArray[14] +
			m_afArray[15] * a_Factor.m_afArray[15];

		return tempMatrix;
	}

	Matrix4	Matrix4::operator *  (const float &a_FactorScalar)
	{
		Matrix4 tempMatrix;

		for (int i = 0;i < 16;i++)
		{

			tempMatrix.m_afArray[i] *= a_FactorScalar;
		}

		return tempMatrix;
	}

	Matrix4 Matrix4::operator =  (const Matrix4 &a_Source)
	{
		// avoid self-assignment
		if (this == &a_Source)
		{
			return *this;
		}

		for (int i = 0;
             i < 16;
             i++)
		{
			m_afArray[i] = a_Source.m_afArray[i];
		}

		return *this;
	}

	Matrix4 Matrix4::operator *= (const Matrix4 &a_Factor)
	{
		(*this) = (*this) * a_Factor;
		return (*this);
	}

	Matrix4 Matrix4::operator *= (const float &a_FactorScalar)
	{
		(*this) = (*this) * a_FactorScalar;
		return (*this);
	}

	bool	Matrix4::operator == (const Matrix4 &a_Source)
	{
		for (int i = 0;i < 16;i++)
		{
			if(m_afArray[i] != a_Source.m_afArray[i])
			{
				return false;
			}
		}

		return true;
	}

}