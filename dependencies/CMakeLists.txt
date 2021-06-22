################################################################################
# File Name      : CMakeLists.txt                                              #
# Created Date   : Friday, March 19th 2021, 11:01:40 am                        #
# Author         : Hwang SanHo                                                 #
# Email          : tksgh1000@naver.com                                         #
# Copyright (c) 2021 San Form Co.                                              #
################################################################################

# Description :

# 의존 라이브러리 를 빌드 및 링크합니다.
# set( PROJECT_INCLUDE_DIRS ) 인클루드 디렉토리에 추가합니다.
# set( PROJECT_LINK_LIBS ) 링크 라이브러리에 추가합니다.
# boost라이브러리 링크
set( _PROJECT_INCLUDE_DIRS )
set( _PROJECT_LINK_LIBS )

set( _PROJECT_PRIVATE_INCLUDE_DIRS ) # PRIVATE INCLUDE DIRS
set( _PROJECT_PRIVATE_LINK_LIBS ) # PRIVATE LINK_LIBS


find_package(Boost REQUIRED)

list( APPEND _PROJECT_PRIVATE_INCLUDE_DIRS ${Boost_INCLUDE_DIRS} )


# PRIVATE
target_include_directories( ${_PROJECT_NAME} PRIVATE ${_PROJECT_PRIVATE_INCLUDE_DIRS} )
target_link_libraries( ${_PROJECT_NAME} PRIVATE ${_PROJECT_PRIVATE_LINK_LIBS} )

# PUBLIC 
target_include_directories( ${_PROJECT_NAME} PUBLIC ${_PROJECT_INCLUDE_DIRS} )
target_link_libraries( ${_PROJECT_NAME} PUBLIC ${_PROJECT_LINK_LIBS} )
