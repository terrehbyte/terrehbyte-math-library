#include <gtest\gtest.h>    // Testing Framework

#define _USE_MATH_DEFINES
#include <cmath>

const double M_PI = 3.14159265358979323846f;

#include "tbytemath.h" // Math Library

using tbyte::Vector2;



class Vec2Test : public ::testing::Test
{
protected:

	Vector2 Vec2Zero;
	Vector2 Vec2One;
	Vector2 Vec2Two;
	Vector2 Vec2Three;

	Vector2 Vec2A;
	Vector2 Vec2B;
	Vector2 Vec2C;

	// this is called before each test
    virtual void SetUp()
    {
        Vec2Zero.m_fX = 0.0f;
        Vec2Zero.m_fY = 0.0f;

        Vec2One.m_fX = 1.0f;
        Vec2One.m_fY = 1.0f;
        
        Vec2Two.m_fX = 2.0f;
        Vec2Two.m_fY = 2.0f;
        
        Vec2Three.m_fX = 3.0f;
        Vec2Three.m_fY = 3.0f;

        Vec2A.m_fX = 1.0f;
        Vec2A.m_fY = 1.0f;

        Vec2B.m_fX = 3.1f;
        Vec2B.m_fY = -0.4f;

        Vec2C.m_fX = 5.5f;
        Vec2C.m_fY = 3.8f;
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
TEST_F(Vec2Test, FloatCtor)
{
	Vector2 test(5.7f, 3.4f);

	ASSERT_FLOAT_EQ(5.7f, test.m_fX);
	ASSERT_FLOAT_EQ(3.4f, test.m_fY);
}

// ## Copy Constructor
TEST_F(Vec2Test, Vec2Copy)
{
	Vector2 TestVecA = Vec2One;

    ASSERT_FLOAT_EQ(Vec2One.m_fX, TestVecA.m_fX);
    ASSERT_FLOAT_EQ(Vec2One.m_fY, TestVecA.m_fY);
}

// # Operators

// ## Addition
TEST_F(Vec2Test, Add)
{
	ASSERT_FLOAT_EQ(3.0f, (Vec2One + Vec2Two).m_fX);
	ASSERT_FLOAT_EQ(3.0f, (Vec2One + Vec2Two).m_fY);
}
TEST_F(Vec2Test, AddScalar)
{
	ASSERT_FLOAT_EQ(2.0f, (Vec2One + 1).m_fX);
	ASSERT_FLOAT_EQ(2.0f, (Vec2One + 1).m_fY);
}
TEST_F(Vec2Test, AddEqual)
{
	Vec2One += Vec2Two;
	
    ASSERT_FLOAT_EQ(3.0f, Vec2One.m_fX);
    ASSERT_FLOAT_EQ(3.0f, Vec2One.m_fY);
}
TEST_F(Vec2Test, AddEqualScalar)
{
	Vec2Two += 1.0f;

    ASSERT_FLOAT_EQ(3.0f, Vec2Two.m_fX);
    ASSERT_FLOAT_EQ(3.0f, Vec2Two.m_fY);
}

// ## Subtraction
TEST_F(Vec2Test, Sub)
{
	ASSERT_FLOAT_EQ(-1.0f, (Vec2One - Vec2Two).m_fX);
	ASSERT_FLOAT_EQ(-1.0f, (Vec2One - Vec2Two).m_fY);
}
TEST_F(Vec2Test, SubScalar)
{
	ASSERT_FLOAT_EQ(0.0f, (Vec2One - 1).m_fX);
	ASSERT_FLOAT_EQ(0.0f, (Vec2One - 1).m_fY);
}
TEST_F(Vec2Test, SubEqual)
{
    Vector2 result;
	result.m_fX = 1;
	result.m_fY = 1;

	result -= Vec2Two;

	ASSERT_FLOAT_EQ(-1.0f, result.m_fX);
	ASSERT_FLOAT_EQ(-1.0f, result.m_fY);
}
TEST_F(Vec2Test, SubEqualScalar)
{
	Vec2B -= 2;

    ASSERT_FLOAT_EQ(1.1f, Vec2B.m_fX);
	ASSERT_FLOAT_EQ(-2.4f, Vec2B.m_fY);
}

// ## Multiplication
TEST_F(Vec2Test, MultiScalar)
{
	ASSERT_FLOAT_EQ(11.0f,(Vec2C * 2.f).m_fX);
	ASSERT_FLOAT_EQ(7.6f, (Vec2C * 2.f).m_fY);
}
TEST_F(Vec2Test, MultiEqualScalar)
{
	Vec2B *= 3.5f;

	ASSERT_FLOAT_EQ(10.85f, Vec2B.m_fX);
	ASSERT_FLOAT_EQ(-1.4f, Vec2B.m_fY);
}

// ## Division
TEST_F(Vec2Test, DivScalar)
{
	Vec2Two = Vec2Two / 2;

	ASSERT_FLOAT_EQ(1.0f, Vec2Two.m_fX);
	ASSERT_FLOAT_EQ(1.0f, Vec2Two.m_fY);
}

TEST_F(Vec2Test, DivEqualsScalar)
{
	Vec2Two /= 2;

	ASSERT_FLOAT_EQ(1.0f, Vec2Two.m_fX);
	ASSERT_FLOAT_EQ(1.0f, Vec2Two.m_fY);
}

// ## Equality & Assignment
TEST_F(Vec2Test, Equality)
{
    // compare against the same values
    ASSERT_TRUE(Vec2One == Vec2One);
    ASSERT_FLOAT_EQ(Vec2One.m_fX, Vec2One.m_fX);
    ASSERT_FLOAT_EQ(Vec2One.m_fY, Vec2One.m_fY);
}
TEST_F(Vec2Test, Assignment)
{
	Vector2 VecA;
	VecA.m_fX = 7;
	VecA.m_fY = 8; 
	
	Vector2 VecB;
	VecB = VecA;

	ASSERT_FLOAT_EQ(VecA.m_fX, VecB.m_fX);
	ASSERT_FLOAT_EQ(VecA.m_fY, VecB.m_fY);
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
	Vector2 normal = Vec2Three.Normal();
	
	ASSERT_FLOAT_EQ(0.707107f, normal.m_fX);
	ASSERT_FLOAT_EQ(0.707107f, normal.m_fY);

}

TEST_F(Vec2Test, Normalise)
{
	Vec2Three.Normalise();
	
	ASSERT_FLOAT_EQ(0.707107f, Vec2Three.m_fX);
	ASSERT_FLOAT_EQ(0.707107f, Vec2Three.m_fY);
}
TEST_F(Vec2Test, Magnitude)
{
	float mag = Vec2Three.Magnitude();

	ASSERT_FLOAT_EQ(4.24264f, mag);
}

TEST_F(Vec2Test, LERP)
{
	Vector2 result;
	result = Vec2Two.Lerp(Vec2Three, 0.5f);
	ASSERT_FLOAT_EQ(2.5f, result.m_fX);
	ASSERT_FLOAT_EQ(2.5f, result.m_fY);
}
