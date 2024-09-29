CMAKE_MINIMUM_REQUIRED(VERSION 3.0)
project(simple-login)

ADD_EXECUTABLE(login
    src/main.cpp
    src/User.cpp 
    header/User.hpp
    )