/*******************************************************************************
* File Name      : test_test.cpp                                               *
* Created Date   : Friday, March 19th 2021, 1:35:36 pm                         *
* Author         : Hwang SanHo                                                 *
* Email          : tksgh1000@naver.com                                         *
* Copyright (c) 2021 San Form Co.                                              *
*******************************************************************************/

// Description :
// #include <gtest/gtest.h>

#include <gtest/gtest.h>

TEST( test1, 테스트_입니다 )
{
    EXPECT_TRUE( true );
}

#include <test.hpp>
int main( int argc, char * argv[] )
{
    ::testing::InitGoogleTest( &argc, argv );
    return RUN_ALL_TESTS();

    HelloWorld();
    return 0;
}
