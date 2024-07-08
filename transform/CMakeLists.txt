file(GLOB_RECURSE SOURCES *.cc)
file(GLOB_RECURSE HEADERS *.h)

# Library target
add_library(${PROJECT_NAME} ${SOURCES})
add_library(${PROJECT_NAME}::${PROJECT_NAME} ALIAS ${PROJECT_NAME})

# Make headers public
target_sources(
  ${PROJECT_NAME}
  PUBLIC
    ${HEADERS}
)
target_include_directories(
  ${PROJECT_NAME}
  PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/..
)

# Compile with all warnings
target_compile_options(
  ${PROJECT_NAME}
  PRIVATE
    -Wall
    -Wextra
    -Wpedantic
    -Werror
)
# target_link_libraries(
#   ${PROJECT_NAME}
#   PRIVATE
#     tl::expected
# )
