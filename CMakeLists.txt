cmake_minimum_required(VERSION 3.16)
project(hvm LANGUAGES C CXX)

# ---- Paths ----
set(HVM_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/includes)
set(HVM_SRC_DIR ${CMAKE_SOURCE_DIR}/src)

# ---- Library ----
find_package(fmt REQUIRED)
find_package(spdlog REQUIRED)

set(HVM_LIB_SOURCES ${HVM_SRC_DIR}/helper.cc)

add_library(hvm_lib ${HVM_LIB_SOURCES})

target_include_directories(hvm_lib PUBLIC ${HVM_INCLUDE_DIR})
target_link_libraries(hvm_lib PUBLIC fmt::fmt spdlog::spdlog)

# ---- Tests ----
enable_testing()
find_package(GTest REQUIRED)

add_executable(hvm_tests tests/test_parser.cc # tests/test_translate.cc
)

target_link_libraries(hvm_tests PRIVATE hvm_lib GTest::gtest
                                         GTest::gtest_main)

# ---- Executable ----
add_executable(hvm main.cc)

target_link_libraries(hvm PRIVATE hvm_lib)
