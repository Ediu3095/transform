cmake_minimum_required(VERSION 3.30)
project(
  transform
  VERSION 0.0.1
  LANGUAGES C CXX
  DESCRIPTION "Transform operations library"
)

# C++ standard 14/17/20 (the highest we can work with)
set(CMAKE_CXX_STANDARD 20)

# Enable testing
include(CTest)
enable_testing()

# Submodules (both external & internal)
add_subdirectory(submodules)

# The actual project
add_subdirectory(${PROJECT_NAME})

if (PROJECT_IS_TOP_LEVEL)
  # Documentation
  add_subdirectory(docs)

  # Test definitions
  add_subdirectory(tests)
endif()
