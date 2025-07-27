cmake_minimum_required(VERSION 3.20)
project(syncsh LANGUAGES CXX)
include(CMakePrintHelpers)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_DEBUG_POSTFIX d)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_POLICY_VERSION_MINIMUM 3.5)

# Get /src/ files
file(GLOB_RECURSE MAIN_SOURCES CONFIGURE_DEPENDS
  "src/*.cpp"
  "src/*.hpp"
)

# Find packages

# Define common libraries used by both main executable and tests
set(COMMON_LIBRARIES
  
)

# Main exec
add_executable(${PROJECT_NAME} ${MAIN_SOURCES})
target_link_libraries(${PROJECT_NAME} PUBLIC
  ${COMMON_LIBRARIES}
)

# Catch2 testing
file(GLOB_RECURSE TEST_SOURCES CONFIGURE_DEPENDS
  "tests/*.cpp"
)
find_package(Catch2 REQUIRED)
include(Catch)
add_executable(${PROJECT_NAME}_tests ${TEST_SOURCES})
target_link_libraries(${PROJECT_NAME}_tests PRIVATE
  Catch2::Catch2WithMain
  ${COMMON_LIBRARIES}
)
