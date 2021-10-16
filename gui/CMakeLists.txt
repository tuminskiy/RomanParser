cmake_minimum_required(VERSION 3.5.0)
project(RomanParser)

add_executable(converter)

set_target_properties(converter PROPERTIES
  CXX_STANDARD 17
  CXX_STANDARD_REQUIRED ON

  RUNTIME_OUTPUT_DIRECTORY_DEBUG "${CMAKE_BINARY_DIR}/debug/bin"
  RUNTIME_OUTPUT_DIRECTORY_RELEASE "${CMAKE_BINARY_DIR}/release/bin"

  AUTOUIC_SEARCH_PATHS ui/converter

  AUTOUIC ON
  AUTOMOC ON
)

set(HEADERS include/converter/mainwindow.hpp)

set(SOURCES
  src/converter/main.cpp
  src/converter/mainwindow.cpp
)

find_package(Qt6 COMPONENTS Widgets REQUIRED)


target_include_directories(converter PRIVATE include)

target_sources(converter PRIVATE ${HEADERS} ${SOURCES})

target_link_libraries(converter PRIVATE rp Qt6::Widgets)