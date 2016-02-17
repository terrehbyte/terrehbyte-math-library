//////////////////////////////////////////////////////////////////////////
//	File:	mat3x3.cpp
//	Author:	Terry Nguyen
//	Date:	12/18/2013
//	Brief:	Defines functions pertaining to Matrix3
//
//////////////////////////////////////////////////////////////////////////

#include "mat3x3.h"

#define _USE_MATH_DEFINES
#include <cmath>

#include "vec3.h"
#include "vec4.h"

#include <limits>
const float eps = std::numeric_limits<float>::epsilon();

namespace tbyte
{
	Matrix3::Matrix3()
	{
	}
	Matrix3::Matrix3(const Matrix3 &a_Source)
	{
		for (int i = 0; i < 9; ++i)
		{
			m_afArray[i] = a_Source.m_afArray[i];
		}
	}
	Matrix3::~Matrix3()
	{
	}

	void Matrix3::Transpose()
	{
		for (int i = 0; i < 3; ++i)
		{
			for (int j = i + 1; j < 3; ++j)
			{
				// hold a copy to swap
				int temp = m_afArray[i * 3 + j];

				m_afArray[i * 3 + j] = m_afArray[j * 3 + i];
				m_afArray[j * 3 + i] = temp;
			}
		}
	}
	Matrix3 Matrix3::IdentityMatrix()
	{
		Matrix3 identity;

		// fill everything as zero
		for (int i = 0; i < 9; ++i)
			identity.m_afArray[i] = 0;

		// add ones as needed
		identity.m_afArray[0] = 1.0f;
		identity.m_afArray[4] = 1.0f;
		identity.m_afArray[8] = 1.0f;

		return identity;
	}

	Matrix3 Matrix3::Translate(Vector2 move)
	{
		Matrix3 temp = Matrix3::IdentityMatrix();

		temp.c[2].m_fX = move.m_fX;
		temp.c[2].m_fY = move.m_fY;

		return temp;
	}

	Matrix3 Matrix3::MakeRotationMatrix(float a_Radians)
	{
		Matrix3 temp = Matrix3::IdentityMatrix();
		temp.m_afArray[0] = cos(a_Radians);
		temp.m_afArray[1] = sin(a_Radians);
		temp.m_afArray[3] = -sin(a_Radians);
		temp.m_afArray[4] = cos(a_Radians);

		return temp;
	}

	Matrix3 Matrix3::operator * (const Matrix3 &a_Factor)
	{
		Matrix3 temp;

		for (int i = 0; i < 3; ++i)
		{
			for (int j = 0; j < 3; ++j)
			{
				// initialize to 0 before adding
				temp.m_afArray[i * 3 + j] = 0;
				for (int k = 0; k < 3; ++k)
				{
					temp.m_afArray[i * 3 + j] += m_afArray[i * 3 + k] * a_Factor.m_afArray[k * 3 + j];
				}
			}
		}

		return temp;
	}
	Matrix3& Matrix3::operator = (const Matrix3 &a_Source)
	{
		// copy over values member-wise
		for (int i = 0; i < 9; ++i)
		{
			m_afArray[i] = a_Source.m_afArray[i];
		}

		// TODO: consider doing a memcopy

		return *this;
	}
	bool	Matrix3::operator == (const Matrix3 &a_Term)
	{
		// check if we're checking against ourselves
		if (this == &a_Term)
			return true;

		// member-wise comparison
		for (int i = 0; i < 9; ++i)
		{
			// ensure that the difference between each value is within reason
			if (fabs(m_afArray[i] - a_Term.m_afArray[i]) < eps)
			{
				continue;
			}

			return false;
		}

		// everything should be OK, so let's return true
		return true;
	}
}
