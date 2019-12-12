cmake_minimum_required(VERSION 3.15)
project(complexNumberCalculator)

set(CMAKE_CXX_STANDARD 14)

add_executable(complexNumberCalculator main.cpp memories.cpp memories.h complexNumber.cpp complexNumber.h mixedNumber.cpp mixedNumber.h fraction.cpp fraction.h streamutilities.cpp streamutilities.h friendsoffraction.cpp friendsofComplexNumber.cpp)