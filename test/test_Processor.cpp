#include <gtest/gtest.h>
#include <sanlang.hpp>

using namespace SANLANG_NAMESPACE;

TEST( Feature_Test, Interpret )
{
    SanLangEngine engine;

    char example_text[] = "Hello World MyName is Sanho<GOOD>{ISSANHO}";
    engine.Interpret( example_text, sizeof(example_text) );

    EXPECT_TRUE( true );
}

int main( int argc, char * argv[] )
{
    ::testing::InitGoogleTest( &argc, argv );
    return RUN_ALL_TESTS();
}
