cmake_minimum_required (VERSION 3.12)
cmsdk2_minimum_required(2.1.2)

project(newlib
  LANGUAGES C ASM
  VERSION 1.2.1)

set(${PROJECT_NAME}_VERSION ${PROJECT_VERSION} CACHE INTERNAL "StratifyOS newlib project version")

add_subdirectory(library library)
