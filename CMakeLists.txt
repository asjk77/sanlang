################################################################################
# File Name      : CMakeLists.txt                                              #
# Created Date   : Friday, March 19th 2021, 9:18:16 am                         #
# Author         : Hwang SanHo                                                 #
# Email          : tksgh1000@naver.com                                         #
# Copyright (c) 2021 San Form Co.                                              #
################################################################################

# Description : 프로젝트 최상위 빌드 스크립트

cmake_minimum_required( VERSION 3.2.0 )

################################################################################
    SET( _PROJECT_NAME "template_project" )
    SET( _PROJECT_VERSION 1.0.0.0 )
    SET( _PROJECT_ID 1 )
    SET( _LIBRARY_TYPE SHARED )
    SET( _DEV_STAGE "dev" )
################################################################################
    option( BUILD_UNIT_TEST "유닛 테스트를 빌드합니다." ON )
    option( BUILD_DOC "문서를 빌드합니다." OFF )
################################################################################
project( ${_PROJECT_NAME} VERSION ${_PROJECT_VERSION} )

set( PROJECT_INCLUDE_DIRS "${PROJECT_SOURCE_DIR}/include" )
set( PROJECT_LINK_LIBS )
# Get source_files
file( GLOB SOURCE_LISTS
    "src/*.cpp"
    # "src/model/*.cpp"
)
# message( ${SOURCE_LISTS} )

# CMAKE_MODULE_PATH SETTING
list( APPEND CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake" )

# Target 설정
# add_executable( ${PROJECT_NAME} ${SOURCE_LISTS} )
add_library( ${PROJECT_NAME} ${_LIBRARY_TYPE} ${SOURCE_LISTS} )
target_include_directories( ${PROJECT_NAME} PUBLIC ${PROJECT_INCLUDE_DIRS} )
target_link_libraries( ${PROJECT_NAME} PUBLIC ${PROJECT_LINK_LIBS} )

# 의존 라이브러리들..
add_subdirectory( dependencies )

# c++ VersionSetting 해당 프로젝트는 CPP_17 을 지원합니다.
target_compile_features( ${PROJECT_NAME} PUBLIC cxx_std_17 )

# Version_template
configure_file( "${PROJECT_SOURCE_DIR}/cmake/template/config.hpp.in" "${PROJECT_BINARY_DIR}/${PROJECT_NAME}_config.hpp" )
target_include_directories( ${PROJECT_NAME} PRIVATE "${PROJECT_BINARY_DIR}" )

# 유닛 테스트를 빌드합니다.
if ( ${BUILD_UNIT_TEST} )
    include(CTest)
    add_subdirectory( test )
endif()

# 문서를 빌드합니다.
if ( ${BUILD_DOC} )
    # include( tools/build_doc )
    configure_file( "${PROJECT_SOURCE_DIR}/cmake/template/doxyfile.in" "${PROJECT_SOURCE_DIR}/doxyfile" )
endif()
