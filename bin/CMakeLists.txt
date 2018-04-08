########################################################################
# Copyright 2018 Aliakbar Panahi
# CMake build script for Orderbook Pricer.
#

cmake_minimum_required(VERSION 3.9)
project(pricer)

set(CMAKE_CXX_STANDARD 17)

add_executable(pricer ../src/main.cpp ../src/pricer.cpp ../src/pricer.h ../src/exception.h ../src/order.h ../src/parser.h)

