cmake_minimum_required (VERSION 3.6)


# Grab the SDK location
if(NOT DEFINED SOS_SDK_PATH)
	if(DEFINED ENV{SOS_SDK_PATH})
		set(SOS_SDK_PATH $ENV{SOS_SDK_PATH})
	endif()
endif()

if(NOT DEFINED SOS_SDK_PATH)
	message(FATAL_ERROR "Please set environment variable SOS_SDK_PATH to location of the StratifyLabs-SDK directory")
endif()

set(SOS_TOOLCHAIN_CMAKE_PATH ${CMAKE_SOURCE_DIR}/../StratifyOS/cmake)

include(${SOS_TOOLCHAIN_CMAKE_PATH}/sos-variables.cmake)
include(${SOS_TOOLCHAIN_CMAKE_PATH}/sos-sdk.cmake)

if( ${SOS_BUILD_CONFIG} STREQUAL arm )
  message(STATUS "Load SOS Lib Toolchain for arm: " ${SOS_TOOLCHAIN_CMAKE_PATH})
  set(CMAKE_TOOLCHAIN_FILE ${SOS_TOOLCHAIN_CMAKE_PATH}/sos-lib-toolchain.cmake)
elseif( ${SOS_BUILD_CONFIG} STREQUAL link )
  set(CMAKE_TOOLCHAIN_FILE ${SOS_TOOLCHAIN_CMAKE_PATH}/link-toolchain.cmake)
endif()

set(SOS_NAME sos)
project(${SOS_NAME} C ASM)

include( ${CMAKE_SOURCE_DIR}/${SOS_BUILD_CONFIG}.cmake )
