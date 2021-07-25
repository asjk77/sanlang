################################################################################
# File Name      : CMakeLists.txt                                              #
# Created Date   : Friday, March 19th 2021, 11:01:17 am                        #
# Author         : Hwang SanHo                                                 #
# Email          : tksgh1000@naver.com                                         #
# Copyright (c) 2021 San Form Co.                                              #
################################################################################

# Description : 테스트 라이브러리를 링크합니다.


find_package( GTest )

file( GLOB TEST_LISTS "test_*.cpp" )

if ( ${GTest_FOUND} )

foreach( ITEM ${TEST_LISTS} )
    get_filename_component( TEST_NAME ${ITEM} NAME_WE )
    set ( TEST_NAME "${PROJECT_NAME}_${TEST_NAME}" ) #이름이 중복되지 않습니다.
    add_executable( ${TEST_NAME} ${ITEM} )
    # ! 해당 Target 이 lib 가 아닐 경우 링크할 수 없습니다.
    target_link_libraries( ${TEST_NAME} PRIVATE ${_PROJECT_NAME} GTest::gtest GTest::gtest_main )
    # target_compile_features( ${TEST_NAME} PRIVATE cxx_std_17 ) # google test가 Cpp 17 버전 이상을 지원합니다.
    message(${TEST_NAME})
    add_test(${TEST_NAME} ${TEST_NAME} )
endforeach( ITEM ${TEST_LISTS} )


else()
    message( FATAL_ERROR "테스트 를 진행하기 위해서는 Google_test가 필요합니다." )
endif()
