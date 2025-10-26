cmake_minimum_required(VERSION 3.10)
project(TrafficLight)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


find_package(OpenCV REQUIRED COMPONENTS core highgui imgproc)
add_executable(${PROJECT_NAME} traffic/test.cpp)
target_compile_definitions(${PROJECT_NAME} PRIVATE OPENCV_VERSION=${OpenCV_VERSION_MAJOR})
target_link_libraries(${PROJECT_NAME} ${OpenCV_LIBS})

target_include_directories(${PROJECT_NAME} PRIVATE ${OpenCV_INCLUDE_DIRS})
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    target_compile_options(${PROJECT_NAME} PRIVATE -g -O0)
else()
    target_compile_options(${PROJECT_NAME} PRIVATE -O2)
endif()