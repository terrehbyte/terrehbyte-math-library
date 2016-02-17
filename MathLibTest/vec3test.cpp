#include <gtest\gtest.h>    // Testing Framework

#define _USE_MATH_DEFINES
#include <cmath>

const double M_PI = 3.14159265358979323846f;

#include "tbytemath.h" // Math Library

using tbyte::Vector3;

class Vec3Test : public ::testing::Test	
{
protected:

	Vector3 vecA;
	Vector3 vecB;

	// this is called before each test
	virtual void SetUp()
	{
		vecA.m_fX = 0.0f;
		vecA.m_fY = 0.0f;

		vecB.m_fX = 0.0f;
		vecB.m_fY = 0.0f;
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
TEST_F(Vec3Test, DefaultCtor)
{

}

// ## Parameterized Ctors
TEST_F(Vec3Test, FloatCtor)
{
	Vector3 test(5.7f, 3.4f, 4.4f);

	ASSERT_FLOAT_EQ(5.7f, test.m_fX);
	ASSERT_FLOAT_EQ(3.4f, test.m_fY);
	ASSERT_FLOAT_EQ(4.4f, test.m_fZ);
}

// ## Copy Constructor
TEST_F(Vec3Test, Vec3Copy)
{
	Vector3 test = Vec3B;

	ASSERT_FLOAT_EQ(3.1f, test.m_fX);
	ASSERT_FLOAT_EQ(-0.4f, test.m_fY);
	ASSERT_FLOAT_EQ(1.2f, test.m_fZ);
}

// # Operators

// ## Addition
TEST_F(Vec3Test, Add)
{
	ASSERT_FLOAT_EQ(4.2f, (Vec3A + Vec3B).m_fX);
	ASSERT_FLOAT_EQ(1.6f, (Vec3A + Vec3B).m_fY);
	ASSERT_FLOAT_EQ(2.5f, (Vec3A + Vec3B).m_fZ);
}
TEST_F(Vec3Test, AddScalar)
{
	Vector3 result = Vec3A + 1;

	ASSERT_FLOAT_EQ(2.1f, result.m_fX);
	ASSERT_FLOAT_EQ(2.2f, result.m_fY);
	ASSERT_FLOAT_EQ(2.3f, result.m_fZ);
}
TEST_F(Vec3Test, AddEqual)
{
	Vec3A += Vec3B;

	ASSERT_FLOAT_EQ(4.2f, (Vec3A).m_fX);
	ASSERT_FLOAT_EQ(0.8f, (Vec3A).m_fY);
	ASSERT_FLOAT_EQ(2.5f, (Vec3A).m_fZ);
}
TEST_F(Vec3Test, AddEqualScalar)
{
	Vec3A += 1;

	ASSERT_FLOAT_EQ(2.1f, Vec3A.m_fX);
	ASSERT_FLOAT_EQ(2.2f, Vec3A.m_fY);
	ASSERT_FLOAT_EQ(2.3f, Vec3A.m_fZ);
}

// ## Subtraction
TEST_F(Vec3Test, Sub)
{
	ASSERT_FLOAT_EQ(-2.0f, (Vec3A - Vec3B).m_fX);
	ASSERT_FLOAT_EQ(1.6f, (Vec3A - Vec3B).m_fY);
	ASSERT_FLOAT_EQ(0.1f, (Vec3A - Vec3B).m_fZ);
}
TEST_F(Vec3Test, SubScalar)
{
	Vector3 result = Vec3A - 1;

	ASSERT_FLOAT_EQ(0.1f, result.m_fX);
	ASSERT_FLOAT_EQ(0.2f, result.m_fY);
	ASSERT_FLOAT_EQ(0.3f, result.m_fZ);
}
TEST_F(Vec3Test, SubEqual)
{
	Vec3A -= Vec3B;

	ASSERT_FLOAT_EQ(-2.0f, Vec3A.m_fX);
	ASSERT_FLOAT_EQ(1.6f,  Vec3A.m_fY);
	ASSERT_FLOAT_EQ(0.1f,  Vec3A.m_fZ);
}
TEST_F(Vec3Test, SubEqualScalar)
{
	Vec3A -= 1;

	ASSERT_FLOAT_EQ(0.1f, Vec3A.m_fX);
	ASSERT_FLOAT_EQ(0.2f, Vec3A.m_fY);
	ASSERT_FLOAT_EQ(0.3f, Vec3A.m_fZ);
}

// ## Multiplication
TEST_F(Vec3Test, MultiScalar)
{
	Vector3 result = Vec3A * 2.f;

	ASSERT_FLOAT_EQ(2.2f, result.m_fX);
	ASSERT_FLOAT_EQ(2.4f, result.m_fY);
	ASSERT_FLOAT_EQ(2.6f, result.m_fZ);
}
TEST_F(Vec3Test, MultiEqualScalar)
{
	Vec3A *= 2.f;

	ASSERT_FLOAT_EQ(2.2f, Vec3A.m_fX);
	ASSERT_FLOAT_EQ(2.4f, Vec3A.m_fY);
	ASSERT_FLOAT_EQ(2.6f, Vec3A.m_fZ);
}

// ## Division
TEST_F(Vec3Test, DivScalar)
{
	Vector3 result = Vec3A / 2.f;

	ASSERT_FLOAT_EQ(0.55f, result.m_fX);
	ASSERT_FLOAT_EQ(0.6f,  result.m_fY);
	ASSERT_FLOAT_EQ(0.65f, result.m_fZ);
}
TEST_F(Vec3Test, DivEqualsScalar)
{
	Vec3A /= 2.f;

	ASSERT_FLOAT_EQ(0.55f, Vec3A.m_fX);
	ASSERT_FLOAT_EQ(0.6f,  Vec3A.m_fY);
	ASSERT_FLOAT_EQ(0.65f, Vec3A.m_fZ);
}

// ## Equality & Assignment
TEST_F(Vec3Test, Equality)
{
	// compare against the same values
	ASSERT_TRUE(Vec3One == Vec3One);
	ASSERT_FLOAT_EQ(Vec3One.m_fX, Vec3One.m_fX);
	ASSERT_FLOAT_EQ(Vec3One.m_fY, Vec3One.m_fY);
}
TEST_F(Vec3Test, Assignment)
{
	Vector3 Vec3ADoppelganger = Vector3(1.1f, 1.2f, 1.3f);

	ASSERT_FLOAT_EQ(1.1f, Vec3ADoppelganger.m_fX);
	ASSERT_FLOAT_EQ(1.2f, Vec3ADoppelganger.m_fY);
	ASSERT_FLOAT_EQ(1.3f, Vec3ADoppelganger.m_fZ);
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
	Vector3 Normal = Vec3Three.Normal();

	ASSERT_FLOAT_EQ(0.57735f, Normal.m_fX);
	ASSERT_FLOAT_EQ(0.57735f, Normal.m_fY);
	ASSERT_FLOAT_EQ(0.57735f, Normal.m_fZ);
}
TEST_F(Vec3Test, Normalise)
{
	Vec3Three.Normalise();

	ASSERT_FLOAT_EQ(0.57735f, Vec3Three.m_fX);
	ASSERT_FLOAT_EQ(0.57735f, Vec3Three.m_fY);
	ASSERT_FLOAT_EQ(0.57735f, Vec3Three.m_fZ);
}
TEST_F(Vec3Test, Magnitude)
{
	float mag = Vec3Three.Magnitude();
	ASSERT_FLOAT_EQ(5.19615, mag);
}

TEST_F(Vec3Test, LERP)
{
	Vector3 result;
	result = Vec3Three.Lerp(Vec3Two, 0.5f);
	ASSERT_FLOAT_EQ(2.5f, result.m_fX);
	ASSERT_FLOAT_EQ(2.5f, result.m_fY);
	ASSERT_FLOAT_EQ(2.5f, result.m_fZ);
}
