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

//
// ** DEFINE TESTS **
//

// Parameterized Ctors
TEST_F(Vec2Test, FloatCtor)
{
    Vector2 TestVec = Vector2(0.0f, 0.0f);

    ASSERT_FLOAT_EQ(0.0f, TestVec.m_fX);
    ASSERT_FLOAT_EQ(0.0f, TestVec.m_fY);
}

// - Copy Ctors -

// Vec2 & Vec2
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

// - Operators -

// Vec2 == Vec2
TEST_F(Vec2Test, Equal)
{
    // compare against the same values
    ASSERT_TRUE(Vec2One == Vec2One);
    ASSERT_FLOAT_EQ(Vec2One.m_fX, Vec2One.m_fX);
    ASSERT_FLOAT_EQ(Vec2One.m_fY, Vec2One.m_fY);
}

// Vec2 + Vec2
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

// Vec2 + Scalar
TEST_F(Vec2Test, AddScalar)
{
    Vector2 TestVecA;
    TestVecA.m_fX = 1.0f;
    TestVecA.m_fY = 1.0f;

    TestVecA = TestVecA + 1;

    ASSERT_FLOAT_EQ(2.0f, TestVecA.m_fX);
    ASSERT_FLOAT_EQ(2.0f, TestVecA.m_fY);
}

// Vec2 += Vec2
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

// Vec2 += Scalar
TEST_F(Vec2Test, AddEqualScalar)
{
    Vector2 TestVecA;
    TestVecA.m_fX = 1.0f;
    TestVecA.m_fY = 2.0f;
    TestVecA += 1;

    ASSERT_FLOAT_EQ(2.0f, TestVecA.m_fX);
    ASSERT_FLOAT_EQ(3.0f, TestVecA.m_fY);
}

// Vec2 - Vec2
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

// Vec2 - Scalar
TEST_F(Vec2Test, SubScalar)
{
    Vector2 TestVecA;
    TestVecA.m_fX = 2.0f;
    TestVecA.m_fY = 2.0f;

    TestVecA = TestVecA - 1;

    ASSERT_FLOAT_EQ(1.0f, TestVecA.m_fX);
    ASSERT_FLOAT_EQ(1.0f, TestVecA.m_fY);
}

// Vec2 -= Vec2
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

// Vec2 -= Scalar
TEST_F(Vec2Test, SubEqualScalar)
{
    Vector2 TestVecA;
    TestVecA.m_fX = 4.0f;
    TestVecA.m_fY = 2.0f;
    TestVecA -= 1;

    ASSERT_FLOAT_EQ(3.0f, TestVecA.m_fX);
    ASSERT_FLOAT_EQ(1.0f, TestVecA.m_fY);
}

// Vec2 * Scalar
TEST_F(Vec2Test, MultiScalar)
{
    Vector2 TestVecA;
    TestVecA.m_fX = 6.0f;
    TestVecA.m_fY = 4.7f;
}
// Vec2 *= Scalar

// Vec2 / Scalar
// Vec2 /= Scalar

// Vec2 = Vec2

// .EulerAngle()
// .DotProduct()
// .Normal()
// .Normalise()
// .Magnitude()
// .Lerp()
