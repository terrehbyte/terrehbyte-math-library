//////////////////////////////////////////////////////////////////////////
//	File:	MatrixFour.cpp
//	Author:	Terry Nguyen
//	Date:	12/18/2013
//	Brief:	Defines functions pertaining to Matrix4
//
//////////////////////////////////////////////////////////////////////////

#include "MatrixFour.h"

namespace tbyte
{
	Matrix4::Matrix4()
	{
	}

	Matrix4::~Matrix4()
	{
	}

	Matrix4 Matrix4::Transpose()
	{
		Matrix4 tempMatrix;

		tempMatrix.m_afArray[0] = m_afArray[0];
		tempMatrix.m_afArray[4] = m_afArray[1];
		tempMatrix.m_afArray[8] = m_afArray[2];
		tempMatrix.m_afArray[12] = m_afArray[3];
		
		tempMatrix.m_afArray[1] = m_afArray[4];
		tempMatrix.m_afArray[5] = m_afArray[5];
		tempMatrix.m_afArray[9] = m_afArray[6];
		tempMatrix.m_afArray[13] = m_afArray[7];
		
		tempMatrix.m_afArray[2] = m_afArray[8];
		tempMatrix.m_afArray[6] = m_afArray[9];
		tempMatrix.m_afArray[10] = m_afArray[10];
		tempMatrix.m_afArray[14] = m_afArray[11];
		
		tempMatrix.m_afArray[3] = m_afArray[12];
		tempMatrix.m_afArray[7] = m_afArray[13];
		tempMatrix.m_afArray[11] = m_afArray[14];
		tempMatrix.m_afArray[15] = m_afArray[15];

		return tempMatrix;
	}

	tbyte::Vector4 Matrix4::PointTransform(const tbyte::Vector4 &a_Point)
	{
		tbyte::Vector4 temp;

		temp.m_fX = a_Point.m_fX * m_afArray[0] + a_Point.m_fY * m_afArray[1] + a_Point.m_fY * m_afArray[2] + a_Point.m_fW * m_afArray[3];
		temp.m_fY = a_Point.m_fX * m_afArray[4] + a_Point.m_fY * m_afArray[5] + a_Point.m_fY * m_afArray[6] + a_Point.m_fW * m_afArray[7];
		temp.m_fZ = a_Point.m_fX * m_afArray[8] + a_Point.m_fY * m_afArray[9] + a_Point.m_fY * m_afArray[10] + a_Point.m_fW * m_afArray[11];
		temp.m_fW = a_Point.m_fX * m_afArray[12] + a_Point.m_fY * m_afArray[13] + a_Point.m_fW * m_afArray[14] + a_Point.m_fW * m_afArray[15];
		
		if (temp.m_fW != 1 && temp.m_fW != 0)
		{
			temp.m_fX /= temp.m_fW;
			temp.m_fY /= temp.m_fW;
			temp.m_fZ /= temp.m_fW;
			temp.m_fW /= temp.m_fW;
		}

		return temp;
	}

	Matrix4 Matrix4::MakeIdentityMatrix()
	{
		Matrix4 temp;

		temp.m_afArray[0] = 1;
		temp.m_afArray[4] = 0;
		temp.m_afArray[8] = 0;
		temp.m_afArray[12] = 0;
		
		temp.m_afArray[1] = 0;
		temp.m_afArray[5] = 1;
		temp.m_afArray[9] = 0;
		temp.m_afArray[13] = 0;

		temp.m_afArray[2] = 0;
		temp.m_afArray[6] = 0;
		temp.m_afArray[10] = 1;
		temp.m_afArray[14] = 0;

		temp.m_afArray[3] = 0;
		temp.m_afArray[7] = 0;
		temp.m_afArray[11] = 0;
		temp.m_afArray[15] = 1;

		(*this) = temp;

		return (*this);
	}

	Matrix4 Matrix4::MakeOGLOrthoProjMatrix(float a_fLeft,
										 float a_fRight,
										 float a_fTop,
										 float a_fBottom,
										 float a_fFar,
										 float a_fNear)
	{
		Matrix4 OrthoProj;

		OrthoProj.MakeIdentityMatrix();

		OrthoProj.m_afArray [0] = 2 / (a_fRight - a_fLeft);
		OrthoProj.m_afArray [12] = -( (a_fRight + a_fLeft) / (a_fRight - a_fLeft));

		OrthoProj.m_afArray [5] = 2 / (a_fTop - a_fBottom);
		OrthoProj.m_afArray [13] = -( (a_fTop + a_fBottom) / (a_fTop - a_fBottom));

		OrthoProj.m_afArray [10] = -2 / (a_fFar - a_fNear);
		OrthoProj.m_afArray [14] = -( (a_fFar + a_fNear) / (a_fFar - a_fNear));
		
		return OrthoProj;
	}

	Matrix4 Matrix4::MakeOrthoProjMatrix(float a_fLeft,
										 float a_fRight,
										 float a_fTop,
										 float a_fBottom,
										 float a_fFar,
										 float a_fNear)
	{
		Matrix4 OrthoProj;

		OrthoProj.MakeIdentityMatrix();

		OrthoProj.m_afArray [0] = 2 / (a_fRight - a_fLeft);
		

		OrthoProj.m_afArray [5] = 2 / (a_fTop - a_fBottom);
		

		OrthoProj.m_afArray [10] = -1 / (a_fFar - a_fNear);

		OrthoProj.m_afArray [3] = -( (a_fRight + a_fLeft) / (a_fRight - a_fLeft));
		OrthoProj.m_afArray [7] = -( (a_fTop + a_fBottom) / (a_fTop - a_fBottom));
		OrthoProj.m_afArray [11] = a_fNear / (a_fFar - a_fNear);
		
		return OrthoProj;
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

		(*this) = temp;

		return (*this);
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

		(*this) = temp;

		return (*this);
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

		(*this) = temp;

		return (*this);
	}

	tbyte::Vector4 Matrix4::VectorTransform(const tbyte::Vector4 &a_Vector)
	{
		tbyte::Vector4 temp;
		temp.m_fX = a_Vector.m_fX * m_afArray[0] + a_Vector.m_fY * m_afArray[1] + a_Vector.m_fZ * m_afArray[2] + a_Vector.m_fW * m_afArray[3];
		temp.m_fY = a_Vector.m_fX * m_afArray[4] + a_Vector.m_fY * m_afArray[5] + a_Vector.m_fZ * m_afArray[6] + a_Vector.m_fW * m_afArray[7];
		temp.m_fZ = a_Vector.m_fX * m_afArray[8] + a_Vector.m_fY * m_afArray[9] + a_Vector.m_fZ * m_afArray[10] + a_Vector.m_fW * m_afArray[11];
		temp.m_fW = a_Vector.m_fX * m_afArray[12] + a_Vector.m_fY * m_afArray[13] + a_Vector.m_fZ * m_afArray[14] + a_Vector.m_fW * m_afArray[15];

		return temp;
	}

	tbyte::Vector3 Matrix4::VectorTransform(const tbyte::Vector3 &a_Vector)
	{
		tbyte::Vector3 temp;
		temp.m_fX = a_Vector.m_fX * m_afArray[0] + a_Vector.m_fY * m_afArray[1] + a_Vector.m_fZ * m_afArray[2];
		temp.m_fY = a_Vector.m_fX * m_afArray[4] + a_Vector.m_fY * m_afArray[5] + a_Vector.m_fZ * m_afArray[6];
		temp.m_fZ = a_Vector.m_fX * m_afArray[8] + a_Vector.m_fY * m_afArray[9] + a_Vector.m_fZ * m_afArray[10];

		return temp;
	}

	Matrix4 Matrix4::operator+ (const Matrix4 &a_Addend)
	{
		Matrix4 tempMatrix = *this;

		for (int i = 0;i < 16;i++)
		{
			
				tempMatrix.m_afArray[i] += a_Addend.m_afArray[i];
			
		}

		return tempMatrix;
	}

	Matrix4 Matrix4::operator+ (const float &a_AddendScalar)
	{
		Matrix4 tempMatrix = *this;

			for (int i = 0;i < 16;i++)
		{
			
				tempMatrix.m_afArray[i] += a_AddendScalar;
			
		}

		return tempMatrix;
	}

	Matrix4 Matrix4::operator+= (const Matrix4 &a_Addend)
	{
		(*this) = (*this) + a_Addend;
		return (*this);
	}

	Matrix4 Matrix4::operator+= (const float &a_AddendScalar)
	{
		(*this) = (*this) + a_AddendScalar;
		return (*this);
	}

	Matrix4 Matrix4::operator- (const Matrix4 &a_Subtrahend)
	{
		Matrix4 tempMatrix = *this;

	for (int i = 0;i < 16;i++)
		{
			
				tempMatrix.m_afArray[i] -= a_Subtrahend.m_afArray[i];
			
		}

		return tempMatrix;
	}

	Matrix4 Matrix4::operator- (const float &a_SubtrahendScalar)
	{
		Matrix4 tempMatrix = *this;

			for (int i = 0;i < 16;i++)
		{
			
				tempMatrix.m_afArray[i] -= a_SubtrahendScalar;
			
		}

		return tempMatrix;
	}

	Matrix4 Matrix4::operator-= (const Matrix4 &a_Subtrahend)
	{
		(*this) = (*this) - a_Subtrahend;
		return (*this);
	}

	Matrix4 Matrix4::operator-= (const float &a_SubtrahendScalar)
	{
		(*this) = (*this) - a_SubtrahendScalar;
		return (*this);
	}

	// Lazy to hard code all of the matrix concatenation stuff so will leave as is
	Matrix4	Matrix4::operator * (const Matrix4 &a_Factor)
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

	Matrix4	Matrix4::operator * (const float &a_FactorScalar)
	{
		Matrix4 tempMatrix;

		for (int i = 0;i < 16;i++)
		{
			
				tempMatrix.m_afArray[i] *= a_FactorScalar;
			
		}

		return tempMatrix;
	}

	Matrix4 Matrix4::operator = (const Matrix4 &a_Source)
	{
		for (int i = 0;i < 16;i++)
		{
			
			m_afArray[i] = a_Source.m_afArray[i];
			
		}

		return *this;
	}

	Matrix4 Matrix4::operator*= (const Matrix4 &a_Factor)
	{
		(*this) = (*this) * a_Factor;
		return (*this);
	}

	Matrix4 Matrix4::operator*= (const float &a_FactorScalar)
	{
		(*this) = (*this) * a_FactorScalar;
		return (*this);
	}

	bool	Matrix4::operator == (const Matrix4 &a_Source)
	{
		for (int i = 0;i < 16;i++)
		{
			
			if(m_afArray[i] != a_Source.m_afArray[i])
					return false;
				
			
		}

		return true;

		return true;
	}

	}