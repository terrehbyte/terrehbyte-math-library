#include <gtest\gtest.h>    // Testing Framework

#define _USE_MATH_DEFINES
#include <cmath>

const double M_PI = 3.14159265358979323846f;

#include "tbytemath.h" // Math Library


using tbyte::Matrix3;

class Mat3Test : public ::testing::Test
{
protected:

	Matrix3 matA;
	Matrix3 matB;

	// this is called before each test
	virtual void SetUp()
	{
	}

	// this is called after each test
	virtual void TearDown()
	{
	}
};

TEST_F(Mat3Test, DefaultCtor)
{

}

TEST_F(Mat3Test, FloatCtor)
{

}

TEST_F(Mat3Test, Mat3Copy)
{

}

TEST_F(Mat3Test, Assignment)
{

}

TEST_F(Mat3Test, Equality)
{

}

TEST_F(Mat3Test, Add)
{

}

TEST_F(Mat3Test, AddEqual)
{

}

TEST_F(Mat3Test, Sub)
{

}

TEST_F(Mat3Test, SubEqual)
{

}

TEST_F(Mat3Test, Multi)
{

}

TEST_F(Mat3Test, MultiScalar)
{

}

TEST_F(Mat3Test, Inverse)
{

}

TEST_F(Mat3Test, MakeScale)
{

}

TEST_F(Mat3Test, MakeXRot)
{

}

TEST_F(Mat3Test, MakeYRot)
{

}

TEST_F(Mat3Test, MakeZRot)
{

}

TEST_F(Mat3Test, Determinant)
{

}