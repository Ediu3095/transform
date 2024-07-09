# add_cc_test()
#
# CMake function to easily add tests.
#
# Parameters:
# NAME: name of target (see Usage below)
# SRCS: List of source files for the binary
# HDRS: List of header files for the binary
# DEPS: List of other libraries to be linked in to the binary targets
# LINKOPTS: List of link options
#
# Usage:
# add_cc_test(
#   NAME
#     awesome_test
#   SRCS
#     awesome_test.cc
#   DEPS
#     GTest::gmock
#     GTest::gtest_main
# )
function(add_cc_test)
  cmake_parse_arguments(
    ADD_CC_TEST
    ""
    "NAME"
    "SRCS;HDRS;DEPS"
    ${ARGN}
  )

  add_executable(
    ${ADD_CC_TEST_NAME}
    ${ADD_CC_TEST_SRCS}
    ${ADD_CC_TEST_HDRS}
  )

  target_include_directories(
    ${ADD_CC_TEST_NAME}
    PRIVATE
      ${PROJECT_SOURCE_DIR}
  )

  target_compile_options(
    ${ADD_CC_TEST_NAME}
    PRIVATE
      -Wall
      -Wextra
      -Wpedantic
      -Werror
  )

  target_link_libraries(
    ${ADD_CC_TEST_NAME}
    PRIVATE
      ${ADD_CC_TEST_DEPS}
  )
endfunction()
