cmake_minimum_required(VERSION 3.14)
project(Oak-Engine)

set(CMAKE_CXX_STANDARD 17)

option(OAK_BUILD_SANDBOX "Build sandbox application" ON)

add_subdirectory(Oak)

if(OAK_BUILD_SANDBOX)
	add_subdirectory(Sandbox)
endif()