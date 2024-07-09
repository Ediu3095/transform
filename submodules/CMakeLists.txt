# https://github.com/google/googletest
if (TARGET GTest::gtest_main)
  message(STATUS "(^ submodule) googletest")
else()
  option(INSTALL_GTEST "" OFF)
  add_subdirectory(googletest googletest/build)
  message(STATUS "(+ submodule) googletest")
endif()
