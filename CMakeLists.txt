cmake_minimum_required(VERSION 3.5)

if("$ENV{TRAVIS_BUILD_NUMBER}" STREQUAL "")
  message("Warning: Could not find TRAVIS_BUILD_NUMBER environment variable")
  set(VERSION_NUMBER "0.0.42")
else()
  set(VERSION_NUMBER "0.0.$ENV{TRAVIS_BUILD_NUMBER}")
endif()

project(timus VERSION ${VERSION_NUMBER})

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/bin)

function (my_executable TARGET)
  add_executable(${TARGET} src/${TARGET}.cpp)
endfunction(my_executable)

my_executable(1196)
my_executable(1496)
my_executable(1545)
my_executable(1837)


