cmake_minimum_required(VERSION 3.5.0)

project(RomanParser)

add_library(rp STATIC)

set_target_properties(rp PROPERTIES
  CXX_STANDARD 17
  CXX_STANDARD_REQUIRED ON

  LINKER_LANGUAGE CXX
)

set(HEADERS
  include/number_type.hpp
  include/number_info.hpp
  include/tokenize.hpp
  include/analyze.hpp
  include/rule.hpp
)

set(SOURCES
  src/number_type.cpp
  src/number_info.cpp
  src/analyze.cpp
)


target_include_directories(rp PUBLIC include/)

target_sources(rp PRIVATE ${HEADERS} ${SOURCES})