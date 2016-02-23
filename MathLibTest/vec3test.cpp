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
		vecA = { 0.0f, 0.0f, 0.0f };
		vecB = { 1.0f, 1.0f, 1.0f };
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
	Vector3 testList = { 5.7f, 3.4f, 4.4f };
	Vector3 test(5.7f, 3.4f, 4.4f);

	ASSERT_FLOAT_EQ(5.7f, testList.m_fX);
	ASSERT_FLOAT_EQ(3.4f, testList.m_fY);
	ASSERT_FLOAT_EQ(4.4f, testList.m_fZ);

	ASSERT_FLOAT_EQ(5.7f, test.m_fX);
	ASSERT_FLOAT_EQ(3.4f, test.m_fY);
	ASSERT_FLOAT_EQ(4.4f, test.m_fZ);
}

// ## Copy Constructor
TEST_F(Vec3Test, Vec3Copy)
{
	Vector3 test = vecB;

	ASSERT_FLOAT_EQ(1.0f, test.m_fX);
	ASSERT_FLOAT_EQ(1.0f, test.m_fY);
	ASSERT_FLOAT_EQ(1.0f, test.m_fZ);
}

// # Operators

// ## Addition
TEST_F(Vec3Test, Add)
{
	ASSERT_FLOAT_EQ(1.0f, (vecA + vecB).m_fX);
	ASSERT_FLOAT_EQ(1.0f, (vecA + vecB).m_fY);
	ASSERT_FLOAT_EQ(1.0f, (vecA + vecB).m_fZ);
}
TEST_F(Vec3Test, AddScalar)
{
	Vector3 result = vecB + 1;

	ASSERT_FLOAT_EQ(2.0f, result.m_fX);
	ASSERT_FLOAT_EQ(2.0f, result.m_fY);
	ASSERT_FLOAT_EQ(2.0f, result.m_fZ);
}
TEST_F(Vec3Test, AddEqual)
{
	vecA += vecB;

	ASSERT_FLOAT_EQ(1.0f, (vecA).m_fX);
	ASSERT_FLOAT_EQ(1.0f, (vecA).m_fY);
	ASSERT_FLOAT_EQ(1.0f, (vecA).m_fZ);
}
TEST_F(Vec3Test, AddEqualScalar)
{
	vecB += 1;

	ASSERT_FLOAT_EQ(2.0f, vecB.m_fX);
	ASSERT_FLOAT_EQ(2.0f, vecB.m_fY);
	ASSERT_FLOAT_EQ(2.0f, vecB.m_fZ);
}

// ## Subtraction
TEST_F(Vec3Test, Sub)
{
	ASSERT_FLOAT_EQ(-1.0f, (vecA - vecB).m_fX);
	ASSERT_FLOAT_EQ(-1.0f, (vecA - vecB).m_fY);
	ASSERT_FLOAT_EQ(-1.0f, (vecA - vecB).m_fZ);
}
TEST_F(Vec3Test, SubScalar)
{
	Vector3 result = vecB - 1;

	ASSERT_FLOAT_EQ(0.0f, result.m_fX);
	ASSERT_FLOAT_EQ(0.0f, result.m_fY);
	ASSERT_FLOAT_EQ(0.0f, result.m_fZ);
}
TEST_F(Vec3Test, SubEqual)
{
	vecA -= vecB;

	ASSERT_FLOAT_EQ(-1.0f,  vecA.m_fX);
	ASSERT_FLOAT_EQ(-1.0f,  vecA.m_fY);
	ASSERT_FLOAT_EQ(-1.0f,  vecA.m_fZ);
}
TEST_F(Vec3Test, SubEqualScalar)
{
	vecA -= -1;

	ASSERT_FLOAT_EQ(1.0f, vecA.m_fX);
	ASSERT_FLOAT_EQ(1.0f, vecA.m_fY);
	ASSERT_FLOAT_EQ(1.0f, vecA.m_fZ);
}

// ## Multiplication
TEST_F(Vec3Test, MultiScalar)
{
	Vector3 result = vecB * 2.f;

	ASSERT_FLOAT_EQ(2.0f, result.m_fX);
	ASSERT_FLOAT_EQ(2.0f, result.m_fY);
	ASSERT_FLOAT_EQ(2.0f, result.m_fZ);
}
TEST_F(Vec3Test, MultiEqualScalar)
{
	vecB *= 2.f;

	ASSERT_FLOAT_EQ(2.0f, vecB.m_fX);
	ASSERT_FLOAT_EQ(2.0f, vecB.m_fY);
	ASSERT_FLOAT_EQ(2.0f, vecB.m_fZ);
}

// ## Division
TEST_F(Vec3Test, DivScalar)
{
	Vector3 result = vecA / 2.f;

	ASSERT_FLOAT_EQ(0.0f, result.m_fX);
	ASSERT_FLOAT_EQ(0.0f, result.m_fY);
	ASSERT_FLOAT_EQ(0.0f, result.m_fZ);
}
TEST_F(Vec3Test, DivEqualsScalar)
{
	vecB /= 2.f;

	ASSERT_FLOAT_EQ(0.5f, vecB.m_fX);
	ASSERT_FLOAT_EQ(0.5f, vecB.m_fY);
	ASSERT_FLOAT_EQ(0.5f, vecB.m_fZ);
}

// ## Equality & Assignment
TEST_F(Vec3Test, Equality)
{
	// compare against the same object
	ASSERT_TRUE(vecB == vecB);
	ASSERT_FLOAT_EQ(vecB.m_fX, vecB.m_fX);
	ASSERT_FLOAT_EQ(vecB.m_fY, vecB.m_fY);

	Vector3 vecBcopy = vecB;

	// compare against different object, same values
	ASSERT_TRUE(vecB == vecBcopy);
}
TEST_F(Vec3Test, Assignment)
{
	Vector3 vecADoppelganger = Vector3(1.1f, 1.2f, 1.3f);

	ASSERT_FLOAT_EQ(1.1f, vecADoppelganger.m_fX);
	ASSERT_FLOAT_EQ(1.2f, vecADoppelganger.m_fY);
	ASSERT_FLOAT_EQ(1.3f, vecADoppelganger.m_fZ);
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
	Vector3 Normal = Vector3(3.0f, 3.0f, 3.0f).Normal();

	ASSERT_FLOAT_EQ(0.57735032f, Normal.m_fX);
	ASSERT_FLOAT_EQ(0.57735032f, Normal.m_fY);
	ASSERT_FLOAT_EQ(0.57735032f, Normal.m_fZ);
}
TEST_F(Vec3Test, Normalise)
{
	Vector3 Normal = Vector3(3.0f, 3.0f, 3.0f);
	Normal.Normalise();

	ASSERT_FLOAT_EQ(0.57735032f, Normal.m_fX);
	ASSERT_FLOAT_EQ(0.57735032f, Normal.m_fY);
	ASSERT_FLOAT_EQ(0.57735032f, Normal.m_fZ);
}
TEST_F(Vec3Test, Magnitude)
{
	float mag = Vector3(3.0f, 3.0f, 3.0f).Magnitude();
	ASSERT_FLOAT_EQ(5.1961522f, mag);
}

TEST_F(Vec3Test, LERP)
{
	Vector3 result;
	result = Vector3(3.0f, 3.0f, 3.0f).Lerp(vecA, 0.5f);
	ASSERT_FLOAT_EQ(1.5f, result.m_fX);
	ASSERT_FLOAT_EQ(1.5f, result.m_fY);
	ASSERT_FLOAT_EQ(1.5f, result.m_fZ);
}
