#######################
# Header only library #
#######################

file(GLOB_RECURSE HEADERS *.h)

# Library target
add_library(${PROJECT_NAME}_header_only INTERFACE)
add_library(${PROJECT_NAME}::${PROJECT_NAME}_header_only ALIAS ${PROJECT_NAME}_header_only)

# Make headers public
target_sources(
  ${PROJECT_NAME}_header_only
  INTERFACE
    ${HEADERS}
)
target_include_directories(
  ${PROJECT_NAME}_header_only
  INTERFACE
    ${PROJECT_SOURCE_DIR}
)

####################
# Compiled library #
####################

file(GLOB_RECURSE SOURCES *.cc)

# Library target
add_library(${PROJECT_NAME} ${SOURCES})
add_library(${PROJECT_NAME}::${PROJECT_NAME} ALIAS ${PROJECT_NAME})

target_link_libraries(
  ${PROJECT_NAME}
  PUBLIC
    ${PROJECT_NAME}_header_only
)
