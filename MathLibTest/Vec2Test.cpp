#include <gtest\gtest.h>    // Testing Framework

#define _USE_MATH_DEFINES
#include <cmath>

const double M_PI = 3.14159265358979323846f;

#include "tbytemath.h" // Math Library

using tbyte::Vector2;

class Vec2Test : public ::testing::Test
{
protected:

	Vector2 vecA;
	Vector2 vecB;

	// this is called before each test
    virtual void SetUp()
    {
		vecA.m_fX = 0.0f;
		vecA.m_fY = 0.0f;

		vecB.m_fX = 1.0f;
		vecB.m_fY = 1.0f;
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
TEST_F(Vec2Test, DefaultCtor)
{
	Vector2 test;

	ASSERT_FLOAT_EQ(0.0f, test.m_fX);
	ASSERT_FLOAT_EQ(0.0f, test.m_fY);
}

//// ## Parameterized Ctors
TEST_F(Vec2Test, FloatCtor)
{
	Vector2 test(5.7f, 3.4f);

	ASSERT_FLOAT_EQ(5.7f, test.m_fX);
	ASSERT_FLOAT_EQ(3.4f, test.m_fY);
}

// ## Copy Constructor
TEST_F(Vec2Test, Vec2Copy)
{
	Vector2 copyTest = vecA;

    ASSERT_FLOAT_EQ(vecA.m_fX, copyTest.m_fX);
    ASSERT_FLOAT_EQ(vecA.m_fY, copyTest.m_fY);
}

// # Operators

// ## Addition
TEST_F(Vec2Test, Add)
{
	Vector2 vecC = vecA + vecB;

	ASSERT_FLOAT_EQ(1.0f, vecC.m_fX);
	ASSERT_FLOAT_EQ(1.0f, vecC.m_fY);
}
TEST_F(Vec2Test, AddScalar)
{
	Vector2 vecC = vecA + 2.f;

	ASSERT_FLOAT_EQ(2.0f, vecC.m_fX);
	ASSERT_FLOAT_EQ(2.0f, vecC.m_fY);
}
TEST_F(Vec2Test, AddEqual)
{
	Vector2 vecC = Vector2(2.0f, 2.0f);
	vecC += vecB;
	
    ASSERT_FLOAT_EQ(3.0f, vecC.m_fX);
    ASSERT_FLOAT_EQ(3.0f, vecC.m_fY);
}
TEST_F(Vec2Test, AddEqualScalar)
{
	Vector2 vecC = Vector2(2.0f, 2.0f);
	vecC += 1;

    ASSERT_FLOAT_EQ(3.0f, vecC.m_fX);
    ASSERT_FLOAT_EQ(3.0f, vecC.m_fY);
}

// ## Subtraction
TEST_F(Vec2Test, Sub)
{
	Vector2 vecC = vecA - vecB;

	ASSERT_FLOAT_EQ(-1.0f, vecC.m_fX);
	ASSERT_FLOAT_EQ(-1.0f, vecC.m_fY);
}
TEST_F(Vec2Test, SubScalar)
{
	Vector2 vecC = vecB - 1;

	ASSERT_FLOAT_EQ(0.0f, vecC.m_fX);
	ASSERT_FLOAT_EQ(0.0f, vecC.m_fY);
}
TEST_F(Vec2Test, SubEqual)
{
    Vector2 vecC = Vector2(2.0f, 2.0f);
	vecC -= vecB;

	ASSERT_FLOAT_EQ(1.0f, vecC.m_fX);
	ASSERT_FLOAT_EQ(1.0f, vecC.m_fY);
}
TEST_F(Vec2Test, SubEqualScalar)
{
	Vector2 vecC = Vector2(2.0f, 2.0f);
	vecC -= 1.0f;

    ASSERT_FLOAT_EQ(1.0f, vecC.m_fX);
	ASSERT_FLOAT_EQ(1.0f, vecC.m_fY);
}

// ## Multiplication
TEST_F(Vec2Test, MultiScalar)
{
	Vector2 vecC = vecB * 2.0f;

	ASSERT_FLOAT_EQ(2.0f, vecC.m_fX);
	ASSERT_FLOAT_EQ(2.0f, vecC.m_fY);
}
TEST_F(Vec2Test, MultiEqualScalar)
{
	Vector2 vecC = Vector2(2.0f, 2.0f);
	vecC *= 4.f;

	ASSERT_FLOAT_EQ(8.0f, vecC.m_fX);
	ASSERT_FLOAT_EQ(8.0f, vecC.m_fY);
}

// ## Division
TEST_F(Vec2Test, DivScalar)
{
	Vector2 vecC = vecB / 2;

	ASSERT_FLOAT_EQ(0.5f, vecC.m_fX);
	ASSERT_FLOAT_EQ(0.5f, vecC.m_fY);
}
TEST_F(Vec2Test, DivEqualsScalar)
{
	Vector2 vecC = Vector2(2.0f, 2.0f);

	vecC /= 0.5f;

	ASSERT_FLOAT_EQ(4.0f, vecC.m_fX);
	ASSERT_FLOAT_EQ(4.0f, vecC.m_fY);
}

// ## Equality & Assignment
TEST_F(Vec2Test, Equality)
{
    // compare against the same values
	ASSERT_FLOAT_EQ(vecA.m_fX, vecA.m_fX);
	ASSERT_FLOAT_EQ(vecA.m_fY, vecA.m_fY);
    ASSERT_TRUE(vecA == vecA);
}
TEST_F(Vec2Test, Assignment)
{
	Vector2 vecC = Vector2(1.0f, 1.0f);

	ASSERT_FLOAT_EQ(1.0f, vecC.m_fX);
	ASSERT_FLOAT_EQ(1.0f, vecC.m_fY);
}

// # Functions
TEST_F(Vec2Test, EulerAngle)
{
	Vector2 Vec90Deg;
	Vec90Deg.m_fX = 0;
	Vec90Deg.m_fY = 1;

	Vector2 Vec270Deg;
	Vec270Deg.m_fX = 0;
	Vec270Deg.m_fY = -1;

	float angle = Vec90Deg.EulerAngle(Vec270Deg);
	ASSERT_FLOAT_EQ(M_PI, angle);
}

TEST_F(Vec2Test, DotProduct)
{
	Vector2 VecA;
	VecA.m_fX = -6;
	VecA.m_fY = 8;

	Vector2 VecB;
	VecB.m_fX = 5;
	VecB.m_fY = 12;

	float dot = VecA.DotProduct(VecB);
	ASSERT_FLOAT_EQ(66.f, dot);
}

TEST_F(Vec2Test, Normal)
{
	Vector2 normal = Vector2(3.0f, 3.0f).Normal();
	
	ASSERT_FLOAT_EQ(0.707107f, normal.m_fX);
	ASSERT_FLOAT_EQ(0.707107f, normal.m_fY);

}
TEST_F(Vec2Test, Normalise)
{
	Vector2 normalized = Vector2(3.0f, 3.0f);
	normalized.Normalise();
	
	ASSERT_FLOAT_EQ(0.707107f, normalized.m_fX);
	ASSERT_FLOAT_EQ(0.707107f, normalized.m_fY);
}
TEST_F(Vec2Test, Magnitude)
{
	float mag = Vector2(3.0f, 3.0f).Magnitude();

	ASSERT_FLOAT_EQ(4.24264f, mag);
}

TEST_F(Vec2Test, LERP)
{
	Vector2 result;
	result = Vector2(2.0f, 2.0f).Lerp(Vector2(3.0f, 3.0f), 0.5f);
	ASSERT_FLOAT_EQ(2.5f, result.m_fX);
	ASSERT_FLOAT_EQ(2.5f, result.m_fY);
}
