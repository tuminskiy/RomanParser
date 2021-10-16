cmake_minimum_required(VERSION 3.5.0)

project(RomanParser)

if (POLICY CMP0074)
  cmake_policy(SET CMP0074 NEW)
endif (POLICY CMP0074)

add_executable(rp_test_runner)


set_target_properties(rp_test_runner PROPERTIES
  CXX_STANDARD 17
  CXX_STANDARD_REQUIRED ON

  RUNTIME_OUTPUT_DIRECTORY_DEBUG    "${CMAKE_BINARY_DIR}/debug/test"
  RUNTIME_OUTPUT_DIRECTORY_RELEASE  "${CMAKE_BINARY_DIR}/release/test"
)

set(SOURCES src/main.cpp

  src/number_1_9_tests.cpp
  src/number_10_19_tests.cpp
  src/number_20_90_tests.cpp
  src/number_100_900_tests.cpp

  src/tokenize_tests.cpp
  src/analyze_tests.cpp
)


find_package(Boost REQUIRED COMPONENTS unit_test_framework)


target_include_directories(rp_test_runner PRIVATE include ${Boost_INCLUDE_DIR})

target_sources(rp_test_runner PRIVATE ${SOURCES})

target_link_libraries(rp_test_runner PRIVATE ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY} rp)