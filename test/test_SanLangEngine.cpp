#include <gtest/gtest.h>
#include <sanlang.hpp>
#include <iostream>

using namespace SANLANG_NAMESPACE;

TEST( SanLangEngine, Interpret )
{
    const char * test_text = "Interpret Is Good Day";
    bool result = SanLangEngine::sInstance->Interpret( test_text, sizeof(test_text));
    if ( result )
        

}

int main( int argc, char * argv[] )
{
    try
    {
        SANLANG_NAMESPACE::StaticInit();
    } catch( Exception & e ) {
        std::cout<< e.WhatIs();
        return -1;
    }

    ::testing::InitGoogleTest( &argc, argv );
    return RUN_ALL_TESTS();
}
