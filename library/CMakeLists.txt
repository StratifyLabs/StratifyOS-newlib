project(newlib CXX C)


set(PUBLIC_DEFINITIONS
	-D__StratifyOS__
	)

set(PRIVATE_DEFINITIONS
	-DPACKAGE_NAME=\"newlib\"
	-DPACKAGE_TARNAME=\"newlib\"
	-DPACKAGE_VERSION=\"2.3.0\"
	-DPACKAGE_STRING=\"newlib\ 2.3.0\"
	-DPACKAGE_BUGREPORT=\"\"
#	-DPACKAGE_URL=\"\"
	-D__NO_SYSCALLS__
	-DSIGNAL_PROVIDED
	-DMALLOC_PROVIDED
	-DHAVE_SYSTEM
	-DHAVE_FCNTL
	-DHAVE_RENAME
	-D_COMPILING_NEWLIB=1
	-D__BUFSIZ__=64
	-D_DOUBLE_IS_32BITS=1
	-D__IEEE_LITTLE_ENDIAN
	-D__IEEE_BYTES_LITTLE_ENDIAN
	)

set(BUILD_FLAGS
	-fno-builtin
	-fsingle-precision-constant
	-ffunction-sections
	-fdata-sections
	)

#Add sources to the project
sos_sdk_add_subdirectory(LIBC_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/src/libc)
sos_sdk_add_subdirectory(LIBM_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/src/libm)

set(LIBC_NAME newlib_libc)
set(LIBM_NAME newlib_libm)
set(LIBA_NAME newlib_liba)

sos_sdk_library_target(LIBC_RELEASE ${LIBC_NAME} "" release ${SOS_ARCH})
sos_sdk_library_target(LIBM_RELEASE ${LIBM_NAME} "" release ${SOS_ARCH})

sos_sdk_library_target(LIBA_VSPRINTF_RELEASE ${LIBA_NAME} "vsprintf" release ${SOS_ARCH})
sos_sdk_library_target(LIBA_VPRINTF_RELEASE ${LIBA_NAME} "vprintf" release ${SOS_ARCH})
sos_sdk_library_target(LIBA_VSIPRINTF_RELEASE ${LIBA_NAME} "vsiprintf" release ${SOS_ARCH})
sos_sdk_library_target(LIBA_VIPRINTF_RELEASE ${LIBA_NAME} "viprintf" release ${SOS_ARCH})

add_library(${LIBA_VSPRINTF_RELEASE_TARGET} STATIC)
add_library(${LIBA_VPRINTF_RELEASE_TARGET} STATIC)
add_library(${LIBA_VSIPRINTF_RELEASE_TARGET} STATIC)
add_library(${LIBA_VIPRINTF_RELEASE_TARGET} STATIC)

add_library(${LIBC_RELEASE_TARGET} STATIC)
add_library(${LIBM_RELEASE_TARGET} STATIC)

target_sources(${LIBC_RELEASE_TARGET}
	PUBLIC
	PRIVATE
	${LIBC_SOURCES}
	)

target_sources(${LIBM_RELEASE_TARGET}
	PUBLIC
	PRIVATE
	${LIBM_SOURCES}
	)

set(LIBA_SOURCES
	${CMAKE_CURRENT_SOURCE_DIR}/src/libc/stdio/vfprintf.c
	${CMAKE_CURRENT_SOURCE_DIR}/src/libc/stdio/vfscanf.c
	${CMAKE_CURRENT_SOURCE_DIR}/src/libc/stdio/vfwscanf.c
	${CMAKE_CURRENT_SOURCE_DIR}/src/libc/stdio/vfwprintf.c
)

target_sources(${LIBA_VSPRINTF_RELEASE_TARGET}
	PRIVATE
	${LIBA_SOURCES}
)

target_sources(${LIBA_VPRINTF_RELEASE_TARGET}
	PRIVATE
	${LIBA_SOURCES}
)

target_sources(${LIBA_VSIPRINTF_RELEASE_TARGET}
	PRIVATE
	${LIBA_SOURCES}
)

target_sources(${LIBA_VIPRINTF_RELEASE_TARGET}
	PRIVATE
	${LIBA_SOURCES}
)

target_compile_definitions(${LIBA_VSPRINTF_RELEASE_TARGET}
	PUBLIC
	${PUBLIC_DEFINITIONS}
	PRIVATE
	${PRIVATE_DEFINITIONS}
	-DSTRING_ONLY
	)

target_compile_definitions(${LIBA_VPRINTF_RELEASE_TARGET}
	PUBLIC
	${PUBLIC_DEFINITIONS}
	PRIVATE
	${PRIVATE_DEFINITIONS}
	)

target_compile_definitions(${LIBA_VSIPRINTF_RELEASE_TARGET}
	PUBLIC
	${PUBLIC_DEFINITIONS}
	PRIVATE
	${PRIVATE_DEFINITIONS}
	-DSTRING_ONLY
	-DINTEGER_ONLY
	)

target_compile_definitions(${LIBA_VIPRINTF_RELEASE_TARGET}
	PUBLIC
	${PUBLIC_DEFINITIONS}
	PRIVATE
	${PRIVATE_DEFINITIONS}
	-DINTEGER_ONLY
	)

target_compile_definitions(${LIBC_RELEASE_TARGET}
	PUBLIC
	${PUBLIC_DEFINITIONS}
	PRIVATE
	${PRIVATE_DEFINITIONS}
	)

target_compile_definitions(${LIBM_RELEASE_TARGET}
	PUBLIC
	${PUBLIC_DEFINITIONS}
	PRIVATE
	${PRIVATE_DEFINITIONS}
	)

target_compile_options(${LIBC_RELEASE_TARGET}
	PUBLIC
	PRIVATE
	${BUILD_FLAGS}
	)

target_compile_options(${LIBM_RELEASE_TARGET}
	PUBLIC
	PRIVATE
	${BUILD_FLAGS}
	)

target_include_directories(${LIBC_RELEASE_TARGET}
	PUBLIC
	$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src/libc/include>
	PRIVATE
	${CMAKE_CURRENT_SOURCE_DIR}/src/libc/machine/arm
	)

target_include_directories(${LIBM_RELEASE_TARGET}
	PUBLIC
	$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src/libc/include>
	PRIVATE
	${CMAKE_CURRENT_SOURCE_DIR}/src/libc/machine/arm
	${CMAKE_CURRENT_SOURCE_DIR}/src/libm/math
	${CMAKE_CURRENT_SOURCE_DIR}/src/libm/common

	)

target_compile_options(${LIBC_RELEASE_TARGET}
	PRIVATE
	-Os
	)

target_compile_options(${LIBM_RELEASE_TARGET}
	PRIVATE
	-Os
	)

sos_sdk_library_target(LIBA_VSPRINTF_DEBUG ${LIBA_NAME} "vsprintf" debug ${SOS_ARCH})
sos_sdk_library_target(LIBA_VPRINTF_DEBUG ${LIBA_NAME} "vprintf" debug ${SOS_ARCH})
sos_sdk_library_target(LIBA_VSIPRINTF_DEBUG ${LIBA_NAME} "vsiprintf" debug ${SOS_ARCH})
sos_sdk_library_target(LIBA_VIPRINTF_DEBUG ${LIBA_NAME} "viprintf" debug ${SOS_ARCH})
sos_sdk_library_target(LIBA_DEBUG ${LIBA_NAME} "${LIB_OPTION}" debug ${SOS_ARCH})

sos_sdk_library_target(LIBC_DEBUG ${LIBC_NAME} "${LIB_OPTION}" debug ${SOS_ARCH})
sos_sdk_library_target(LIBM_DEBUG ${LIBM_NAME} "${LIB_OPTION}" debug ${SOS_ARCH})

add_library(${LIBA_VSPRINTF_DEBUG_TARGET} STATIC)
add_library(${LIBA_VPRINTF_DEBUG_TARGET} STATIC)
add_library(${LIBA_VSIPRINTF_DEBUG_TARGET} STATIC)
add_library(${LIBA_VIPRINTF_DEBUG_TARGET} STATIC)

add_library(${LIBC_DEBUG_TARGET} STATIC)
add_library(${LIBM_DEBUG_TARGET} STATIC)

sos_sdk_copy_target(${LIBA_VSPRINTF_RELEASE_TARGET} ${LIBA_VSPRINTF_DEBUG_TARGET})
sos_sdk_copy_target(${LIBA_VPRINTF_RELEASE_TARGET} ${LIBA_VPRINTF_DEBUG_TARGET})
sos_sdk_copy_target(${LIBA_VSIPRINTF_RELEASE_TARGET} ${LIBA_VSIPRINTF_DEBUG_TARGET})
sos_sdk_copy_target(${LIBA_VIPRINTF_RELEASE_TARGET} ${LIBA_VIPRINTF_DEBUG_TARGET})

sos_sdk_copy_target(${LIBC_RELEASE_TARGET} ${LIBC_DEBUG_TARGET})
sos_sdk_copy_target(${LIBM_RELEASE_TARGET} ${LIBM_DEBUG_TARGET})

sos_sdk_library_add_arch_targets("${LIBA_VSPRINTF_RELEASE_OPTIONS}" ${SOS_ARCH} "")
sos_sdk_library_add_arch_targets("${LIBA_VPRINTF_RELEASE_OPTIONS}" ${SOS_ARCH} "")
sos_sdk_library_add_arch_targets("${LIBA_VSIPRINTF_RELEASE_OPTIONS}" ${SOS_ARCH} "")
sos_sdk_library_add_arch_targets("${LIBA_VIPRINTF_RELEASE_OPTIONS}" ${SOS_ARCH} "")

set(DEPENDENCIES
	${LIBA_NAME}_vsprintf
	${LIBA_NAME}_vprintf
	${LIBA_NAME}_vsiprintf
	${LIBA_NAME}_viprintf)

set(LIBA_DEPENDENCIES "")

sos_sdk_library_add_arch_targets("${LIBC_RELEASE_OPTIONS}" ${SOS_ARCH} "${DEPENDENCIES}")
sos_sdk_library_add_arch_targets("${LIBM_RELEASE_OPTIONS}" ${SOS_ARCH} "")

sos_sdk_library_add_arch_targets("${LIBA_VSPRINTF_DEBUG_OPTIONS}" ${SOS_ARCH} "${LIBA_DEPENDENCIES}")
sos_sdk_library_add_arch_targets("${LIBA_VPRINTF_DEBUG_OPTIONS}" ${SOS_ARCH} "${LIBA_DEPENDENCIES}")
sos_sdk_library_add_arch_targets("${LIBA_VSIPRINTF_DEBUG_OPTIONS}" ${SOS_ARCH} "${LIBA_DEPENDENCIES}")
sos_sdk_library_add_arch_targets("${LIBA_VIPRINTF_DEBUG_OPTIONS}" ${SOS_ARCH} "${LIBA_DEPENDENCIES}")

sos_sdk_library_add_arch_targets("${LIBC_DEBUG_OPTIONS}" ${SOS_ARCH} "${DEPENDENCIES}")
sos_sdk_library_add_arch_targets("${LIBM_DEBUG_OPTIONS}" ${SOS_ARCH} "")

install(DIRECTORY
	src/libc/include/
	DESTINATION include
	PATTERN CMakelists.txt EXCLUDE)


install(FILES
	${CMAKE_CURRENT_SOURCE_DIR}/newlib.cmake
	DESTINATION
	${SOS_SDK_PATH}/cmake/targets)


