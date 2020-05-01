cmake_minimum_required(VERSION 3.15)
project(EigenTest)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(Eigen)

AUX_SOURCE_DIRECTORY(. DIR_SRCS)
ADD_EXECUTABLE(EigenTest ${DIR_SRCS})
#
#add_executable(EigenTest ${SOURCE_FILES})

#find_package(EigenTest REQUIRED)
#target_link_libraries(EIGENTEST EigenTest::EigenTest)



#add_executable(src
#        cfunct.cpp
#        cfunct.h
#        _cfunct.cpp)