include(${CMAKE_CURRENT_SOURCE_DIR}/AddTest.cmake)

if (BUILD_TESTING)
  # Helpful aliases
  set(TEST_DIR ${CMAKE_CURRENT_SOURCE_DIR})
  set(SRCS_DIR ${PROJECT_SOURCE_DIR}/${PROJECT_NAME})

  # vec
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
  add_cc_test(
    NAME
      vec3_test
    SRCS
      ${TEST_DIR}/vec/vec3.cc
    DEPS
      GTest::gmock
      GTest::gtest_main
      ${PROJECT_NAME}::${PROJECT_NAME}
  )
  add_cc_test(
    NAME
      vec4_test
    SRCS
      ${TEST_DIR}/vec/vec4.cc
    DEPS
      GTest::gmock
      GTest::gtest_main
      ${PROJECT_NAME}::${PROJECT_NAME}
  )
  add_cc_test(
    NAME
      vecn_test
    SRCS
      ${TEST_DIR}/vec/vecn.cc
    DEPS
      GTest::gmock
      GTest::gtest_main
      ${PROJECT_NAME}::${PROJECT_NAME}
  )

  # mat
  add_cc_test(
    NAME
      mat1x1_test
    SRCS
      ${TEST_DIR}/mat/mat1x1.cc
    DEPS
      GTest::gmock
      GTest::gtest_main
      ${PROJECT_NAME}::${PROJECT_NAME}
  )
  add_cc_test(
    NAME
      mat1xr_test
    SRCS
      ${TEST_DIR}/mat/mat1xr.cc
    DEPS
      GTest::gmock
      GTest::gtest_main
      ${PROJECT_NAME}::${PROJECT_NAME}
  )
  add_cc_test(
    NAME
      matcx1_test
    SRCS
      ${TEST_DIR}/mat/matcx1.cc
    DEPS
      GTest::gmock
      GTest::gtest_main
      ${PROJECT_NAME}::${PROJECT_NAME}
  )
  add_cc_test(
    NAME
      matcxr_test
    SRCS
      ${TEST_DIR}/mat/matcxr.cc
    DEPS
      GTest::gmock
      GTest::gtest_main
      ${PROJECT_NAME}::${PROJECT_NAME}
  )

  # glsl
  add_cc_test(
    NAME
      glsl_geometric_test
    SRCS
      ${TEST_DIR}/glsl/geometric.cc
    DEPS
      GTest::gmock
      GTest::gtest_main
      ${PROJECT_NAME}::${PROJECT_NAME}
  )
  add_cc_test(
    NAME
      glsl_matrix_test
    SRCS
      ${TEST_DIR}/glsl/matrix.cc
    DEPS
      GTest::gmock
      GTest::gtest_main
      ${PROJECT_NAME}::${PROJECT_NAME}
  )

  include(GoogleTest)

  gtest_discover_tests(vec1_test)
  gtest_discover_tests(vec2_test)
  gtest_discover_tests(vec3_test)
  gtest_discover_tests(vec4_test)
  gtest_discover_tests(vecn_test)

  gtest_discover_tests(mat1x1_test)
  gtest_discover_tests(mat1xr_test)
  gtest_discover_tests(matcx1_test)
  gtest_discover_tests(matcxr_test)

  gtest_discover_tests(glsl_geometric_test)
  gtest_discover_tests(glsl_matrix_test)
endif()
