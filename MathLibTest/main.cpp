// Google Test
//  - for more tests and help, see http://code.google.com/p/googletest/wiki/V1_7_Primer
#include <gtest\gtest.h>

// Math Library
#include <tbytemath.h>

// Program Entry Point
int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}