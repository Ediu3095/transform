file(GLOB_RECURSE HEADERS *.h)
# file(GLOB_RECURSE SOURCES *.cc)

# Library target
add_library(${PROJECT_NAME} INTERFACE)
add_library(${PROJECT_NAME}::${PROJECT_NAME} ALIAS ${PROJECT_NAME})

# Make headers public
target_sources(
  ${PROJECT_NAME}
  INTERFACE
    ${HEADERS}
)
target_include_directories(
  ${PROJECT_NAME}
  INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}/..
)
# target_link_libraries(
#   ${PROJECT_NAME}
#   INTERFACE
#     tl::expected
# )
