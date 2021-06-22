/*******************************************************************************
* File Name      : test.cpp                                                    *
* Created Date   : Friday, March 19th 2021, 9:59:49 am                         *
* Author         : Hwang SanHo                                                 *
* Email          : tksgh1000@naver.com                                         *
* Copyright (c) 2021 San Form Co.                                              *
*******************************************************************************/

// Description :

#include <iostream>
#include <config.hpp>
#include <test.hpp>
/**
 * @brief Hello world ! 
 * 
 */
void HelloWorld(void)
{
    printf( "[%s-v%s-%s-%s]: HELLO WORLD",
        LIB_NAME, LIB_VERSION,
        LIB_BUILD_TYPE, LIB_VER_ID
    );
}


