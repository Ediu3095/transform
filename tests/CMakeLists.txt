include(${CMAKE_CURRENT_SOURCE_DIR}/AddTest.cmake)

if (BUILD_TESTING)
  # Helpful aliases
  set(TEST_DIR ${CMAKE_CURRENT_SOURCE_DIR})
  set(SRCS_DIR ${PROJECT_SOURCE_DIR}/${PROJECT_NAME})

  add_cc_test(
    NAME
      vec1_test
    SRCS
      ${TEST_DIR}/vec/vec1.cc
    DEPS
      GTest::gmock
      GTest::gtest_main
      ${PROJECT_NAME}::${PROJECT_NAME}
  )
  add_cc_test(
    NAME
      vec2_test
    SRCS
      ${TEST_DIR}/vec/vec2.cc
    DEPS
      GTest::gmock
      GTest::gtest_main
      ${PROJECT_NAME}::${PROJECT_NAME}
  )
  
  include(GoogleTest)
  gtest_discover_tests(vec1_test)
  gtest_discover_tests(vec2_test)
endif()
