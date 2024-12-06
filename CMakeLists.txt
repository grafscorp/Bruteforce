cmake_minimum_required(VERSION 3.5.0)
project(bruteforce VERSION 0.1.0 LANGUAGES C CXX)





SET(SOURCS 
headers/bruteforce.h
headers/bruteforce.cpp
)

add_executable(bruteforce main.cpp ${SOURCS})

