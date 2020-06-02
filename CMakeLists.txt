cmake_minimum_required(VERSION 3.14)
project(OakProject)

option(OAK_BUILD_SANDBOX "Build sandbox application" ON)

add_subdirectory(Oak)

if(OAK_BUILD_SANDBOX)
	add_subdirectory(Sandbox)
endif()