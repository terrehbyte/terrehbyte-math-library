#include <gtest\gtest.h>    // Testing Framework

#define _USE_MATH_DEFINES
#include <cmath>

const double M_PI = 3.14159265358979323846f;

#include "tbytemath.h" // Math Library

using tbyte::Matrix3;

class Mat3Test : public ::testing::Test
{
protected:
	// this is called before each test
	virtual void SetUp()
	{

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

// Operators
TEST_F(Mat3Test, CopyCtor)
{
	Matrix3 identity;
	
	// create the identity matrix
	for (int i = 0; i < 9; ++i)
	{
		if (i % 4 == 0)
			identity.m_afArray[i] = 1;
		else
			identity.m_afArray[i] = 0;
	}

	Matrix3 test(identity);

	// test the values
	//  - don't use == we haven't tested it yet
	for (int i = 0; i < 9; ++i)
	{
		ASSERT_FLOAT_EQ(identity.m_afArray[i], test.m_afArray[i]);
	}
}

TEST_F(Mat3Test, Assignment)
{
	Matrix3 identity;
	Matrix3 test;

	// create the identity matrix
	for (int i = 0; i < 9; ++i)
	{
		if (i % 4 == 0)
			identity.m_afArray[i] = 1;
		else
			identity.m_afArray[i] = 0;
	}

	test = identity;

	// test the values
	//  - don't use == we haven't tested it yet
	for (int i = 0; i < 9; ++i)
	{
		ASSERT_FLOAT_EQ(identity.m_afArray[i], test.m_afArray[i]);
	}
}

TEST_F(Mat3Test, Equality)
{
	Matrix3 left  = Matrix3::IdentityMatrix();
	Matrix3 right = Matrix3::IdentityMatrix();

	ASSERT_TRUE(left == right);
}

TEST_F(Mat3Test, Multiplication)
{
	Matrix3 left = Matrix3::IdentityMatrix();
	Matrix3 right = Matrix3::IdentityMatrix();

	Matrix3 expected = Matrix3::IdentityMatrix();

	Matrix3 actual = left * right;

	ASSERT_TRUE(expected == actual);
}

// Methods
TEST_F(Mat3Test, Identity)
{
	Matrix3 identity = Matrix3::IdentityMatrix();

	for (int i = 0; i < 9; ++i)
	{
		if (i % 4 == 0)
			ASSERT_FLOAT_EQ(1, identity.m_afArray[i]);
		else
			ASSERT_FLOAT_EQ(0, identity.m_afArray[i]);
	}
}

TEST_F(Mat3Test, Transpose)
{
	/*
		0	3	6
		1	4	7
		2	5	8
	
	*/
	Matrix3 example;
	for (int i = 0; i < 9; ++i)
	{
		example.m_afArray[i] = i;
	}

	example.Transpose();

	// values are now row major
	/*
		0	1	2
		3	4	5
		6	7	8
	*/

	Matrix3 expected;
	expected.m_afArray[0] = 0;
	expected.m_afArray[3] = 1;
	expected.m_afArray[6] = 2;

	expected.m_afArray[1] = 3;
	expected.m_afArray[4] = 4;
	expected.m_afArray[7] = 5;
	
	expected.m_afArray[2] = 6;
	expected.m_afArray[5] = 7;
	expected.m_afArray[8] = 8;

	for (int i = 0; i < 9; ++i)
	{
		ASSERT_FLOAT_EQ(expected.m_afArray[i], example.m_afArray[i]);
	}
}

TEST_F(Mat3Test, Translate)
{
	Matrix3 transform = Matrix3::IdentityMatrix() * Matrix3::Translate({ 2,3 });
	Matrix3 expected = Matrix3::IdentityMatrix();
	expected.c[2].m_fX = 2;
	expected.c[2].m_fY = 3;

	ASSERT_TRUE(expected == transform);
}