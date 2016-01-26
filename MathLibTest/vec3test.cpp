#include <gtest\gtest.h>    // Testing Framework

#define _USE_MATH_DEFINES
#include <cmath>

const double M_PI = 3.14159265358979323846f;

#include "tbytemath.h" // Math Library

using tbyte::Vector3;

class Vec3Test : public ::testing::Test
{
protected:

	Vector3 Vec3Zero;
	Vector3 Vec3One;
	Vector3 Vec3Two;
	Vector3 Vec3Three;

	Vector3 Vec3A;
	Vector3 Vec3B;
	Vector3 Vec3C;

	// this is called before each test
	virtual void SetUp()
	{
		Vec3Zero.m_fX = 0.0f;
		Vec3Zero.m_fY = 0.0f;
		Vec3Zero.m_fZ = 0.0f;

		Vec3One.m_fX = 1.0f;
		Vec3One.m_fY = 1.0f;
		Vec3One.m_fZ = 1.0f;

		Vec3Two.m_fX = 2.0f;
		Vec3Two.m_fY = 2.0f;
		Vec3Two.m_fZ = 2.0f;

		Vec3Three.m_fX = 3.0f;
		Vec3Three.m_fY = 3.0f;
		Vec3Three.m_fZ = 3.0f;

		Vec3A.m_fX = 1.1f;
		Vec3A.m_fY = 1.2f;
		Vec3A.m_fY = 1.3f;

		Vec3B.m_fX = 3.1f;
		Vec3B.m_fY = -0.4f;
		Vec3B.m_fZ = 1.2f;

		Vec3C.m_fX = 5.5f;
		Vec3C.m_fY = 3.8f;
		Vec3C.m_fZ = 4.4f;
	}

	// this is called after each test
	virtual void TearDown()
	{
	}


};

// MUST READ for first time test writing: http://bit.ly/1kdVXtH

// ----------------
// - DEFINE TESTS -
// ----------------

// # Constructors

// ## Parameterized Ctors
TEST_F(Vec3Test, FloatCtor)
{
	Vector3 test(5.7f, 3.4f, 4.4f);

	ASSERT_FLOAT_EQ(5.7f, test.m_fX);
	ASSERT_FLOAT_EQ(3.4f, test.m_fY);
	ASSERT_FLOAT_EQ(5.7f, test.m_fZ);
}

// ## Copy Constructor
TEST_F(Vec3Test, Vec3Copy)
{

}

// # Operators

// ## Addition
TEST_F(Vec3Test, Add)
{

}
TEST_F(Vec3Test, AddScalar)
{

}
TEST_F(Vec3Test, AddEqual)
{

}
TEST_F(Vec3Test, AddEqualScalar)
{
}

// ## Subtraction
TEST_F(Vec3Test, Sub)
{

}
TEST_F(Vec3Test, SubScalar)
{

}
TEST_F(Vec3Test, SubEqual)
{

}
TEST_F(Vec3Test, SubEqualScalar)
{

}

// ## Multiplication
TEST_F(Vec3Test, MultiScalar)
{
}
TEST_F(Vec3Test, MultiEqualScalar)
{

}

// ## Division
TEST_F(Vec3Test, DivScalar)
{

}
TEST_F(Vec3Test, DivEqualsScalar)
{

}

// ## Equality & Assignment
TEST_F(Vec3Test, Equality)
{

}
TEST_F(Vec3Test, Assignment)
{

}

// # Functions
TEST_F(Vec3Test, EulerAngle)
{

}

TEST_F(Vec3Test, DotProduct)
{

}

TEST_F(Vec3Test, Normal)
{

}

TEST_F(Vec3Test, Normalise)
{

}

TEST_F(Vec3Test, Magnitude)
{

}

TEST_F(Vec3Test, LERP)
{

}
