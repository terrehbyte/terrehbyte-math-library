#include <gtest\gtest.h>    // Testing Framework
#include <TerrehByteMath.h> // Math Library

using tbyte::Vector2;

class Vec2Test : public ::testing::Test
{
protected:
    // Run Before Each Test
    virtual void SetUp()
    {
        // Zero
        Vec2Zero.m_fX = 0.0f;
        Vec2Zero.m_fY = 0.0f;

        // One
        Vec2One.m_fX = 1.0f;
        Vec2One.m_fY = 1.0f;
        
        // Two
        Vec2Two.m_fX = 2.0f;
        Vec2Two.m_fY = 2.0f;
        
        // Three
        Vec2Three.m_fX = 3.0f;
        Vec2Three.m_fY = 3.0f;

        // Examples
        
        Vec2A.m_fX = 1.0f;
        Vec2A.m_fY = 1.0f;

        Vec2B.m_fX = 0.1f;
        Vec2B.m_fY = 0.1f;

        Vec2C.m_fX = 5.5f;
        Vec2C.m_fY = 3.8f;
    }

    // Run After Each Test
    virtual void TearDown()
    {
    }

    // Variables Accessible to Tests
    Vector2 Vec2Zero;
    Vector2 Vec2One;
    Vector2 Vec2Two;
    Vector2 Vec2Three;

    Vector2 Vec2A;
    Vector2 Vec2B;
    Vector2 Vec2C;
};

// MUST READ for first time test writing: http://bit.ly/1kdVXtH

// ----------------
// - DEFINE TESTS -
// ----------------

// # Constructors
// ## Parameterized Ctors
TEST_F(Vec2Test, FloatCtor)
{
    Vector2 TestVec = Vector2(0.0f, 0.0f);

    ASSERT_FLOAT_EQ(0.0f, TestVec.m_fX);
    ASSERT_FLOAT_EQ(0.0f, TestVec.m_fY);
}

// ## Copy Constructor
TEST_F(Vec2Test, Vec2Copy)
{
    // compare that the values are the same
    Vector2 TestVecA;

    TestVecA.m_fX = 3.0f;
    TestVecA.m_fY = 3.0f;

    Vector2 TestVecB = TestVecA;

    ASSERT_FLOAT_EQ(TestVecA.m_fX, TestVecB.m_fX);
    ASSERT_FLOAT_EQ(TestVecA.m_fY, TestVecB.m_fY);
}

// # Operators
// ## Addition
TEST_F(Vec2Test, Add)
{
	// manually check against math
	Vector2 TestVecA;
	TestVecA.m_fX = 1.3f;
	TestVecA.m_fY = 1.4f;

	Vector2 TestVecB;
	TestVecB.m_fX = 1.7f;
	TestVecB.m_fY = 1.6f;

	ASSERT_FLOAT_EQ(3.0f, (TestVecA.m_fX + TestVecB.m_fX));
	ASSERT_FLOAT_EQ(3.0f, (TestVecA.m_fY + TestVecB.m_fY));
}
TEST_F(Vec2Test, AddScalar)
{
    Vector2 TestVecA;
    TestVecA.m_fX = 1.0f;
    TestVecA.m_fY = 1.0f;

    TestVecA = TestVecA + 1;

    ASSERT_FLOAT_EQ(2.0f, TestVecA.m_fX);
    ASSERT_FLOAT_EQ(2.0f, TestVecA.m_fY);
}
TEST_F(Vec2Test, AddEqual)
{
    // manually check against math

    Vector2 TestVecA;
    TestVecA.m_fX = 1.3f;
    TestVecA.m_fY = 1.4f;

    Vector2 TestVecB;
    TestVecB.m_fX = 1.7f;
    TestVecB.m_fY = 1.6f;

    Vector2 TestVecC;
    TestVecC.m_fX = TestVecA.m_fX;
    TestVecC.m_fY = TestVecA.m_fY;

    TestVecC += TestVecB;

    ASSERT_FLOAT_EQ(3.0f, TestVecC.m_fX);
    ASSERT_FLOAT_EQ(3.0f, TestVecC.m_fY);
}
TEST_F(Vec2Test, AddEqualScalar)
{
    Vector2 TestVecA;
    TestVecA.m_fX = 1.0f;
    TestVecA.m_fY = 2.0f;
    TestVecA += 1;

    ASSERT_FLOAT_EQ(2.0f, TestVecA.m_fX);
    ASSERT_FLOAT_EQ(3.0f, TestVecA.m_fY);
}

// ## Subtraction
TEST_F(Vec2Test, Sub)
{
    // manually check against math
    Vector2 TestVecA;
    TestVecA.m_fX = 5.0f;
    TestVecA.m_fY = 5.0f;

    Vector2 TestVecB;
    TestVecB.m_fX = 4.0f;
    TestVecB.m_fY = 4.0f;

    ASSERT_FLOAT_EQ(1.0f, (TestVecA.m_fX - TestVecB.m_fX));
    ASSERT_FLOAT_EQ(1.0f, (TestVecA.m_fY - TestVecB.m_fY));
}
TEST_F(Vec2Test, SubScalar)
{
    Vector2 TestVecA;
    TestVecA.m_fX = 2.0f;
    TestVecA.m_fY = 2.0f;

    TestVecA = TestVecA - 1;

    ASSERT_FLOAT_EQ(1.0f, TestVecA.m_fX);
    ASSERT_FLOAT_EQ(1.0f, TestVecA.m_fY);
}
TEST_F(Vec2Test, SubEqual)
{
    // manually check against math

    Vector2 TestVecA;
    TestVecA.m_fX = 7.0f;
    TestVecA.m_fY = 5.0f;

    Vector2 TestVecB;
    TestVecB.m_fX = 3.0f;
    TestVecB.m_fY = 4.0f;

    Vector2 TestVecC;
    TestVecC.m_fX = TestVecA.m_fX;
    TestVecC.m_fY = TestVecA.m_fY;

    TestVecC -= TestVecB;

    ASSERT_FLOAT_EQ(4.0f, TestVecC.m_fX);
    ASSERT_FLOAT_EQ(1.0f, TestVecC.m_fY);
}
TEST_F(Vec2Test, SubEqualScalar)
{
    Vector2 TestVecA;
    TestVecA.m_fX = 4.0f;
    TestVecA.m_fY = 2.0f;
    TestVecA -= 1;

    ASSERT_FLOAT_EQ(3.0f, TestVecA.m_fX);
    ASSERT_FLOAT_EQ(1.0f, TestVecA.m_fY);
}

// ## Multiplication
TEST_F(Vec2Test, MultiScalar)
{
    Vector2 TestVecA;
    TestVecA.m_fX = 6.0f;
    TestVecA.m_fY = 4.7f;
	TestVecA = TestVecA * 2;

	ASSERT_FLOAT_EQ(12.0f, TestVecA.m_fX);
	ASSERT_FLOAT_EQ(9.4f, TestVecA.m_fY);
}
TEST_F(Vec2Test, MultiEqualScalar)
{
	Vector2 TestVecA;
	TestVecA.m_fX = 4.2f;
	TestVecA.m_fY = 7.9f;

	TestVecA *= 3;

	ASSERT_FLOAT_EQ(12.6f, TestVecA.m_fX);
	ASSERT_FLOAT_EQ(23.7f, TestVecA.m_fY);
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
