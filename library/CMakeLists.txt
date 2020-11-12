project(newlib CXX C)

#Add sources to the project
sos_sdk_add_subdirectory(LIBC_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/src/libc)

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
#	-D__BUFSIZ__=64
	-D__IEEE_LITTLE_ENDIAN
	-D__IEEE_BYTES_LITTLE_ENDIAN
	)

set(BUILD_FLAGS
	-fno-builtin
	-fsingle-precision-constant
	)

sos_sdk_add_subdirectory(LIBM_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/src/libm)

set(LIBC_NAME c)
set(LIBM_NAME m)

sos_sdk_library_target(LIBC_RELEASE ${LIBC_NAME} "${LIB_OPTION}" release ${SOS_ARCH})
sos_sdk_library_target(LIBM_RELEASE ${LIBM_NAME} "${LIB_OPTION}" release ${SOS_ARCH})

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
	${SOS_INCLUDE_DIRECTORIES}
	)

target_include_directories(${LIBM_RELEASE_TARGET}
	PUBLIC
	$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src/libc/include>
	$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src/libm/common>
	PRIVATE
	${SOS_INCLUDE_DIRECTORIES}
	)

target_compile_options(${LIBC_RELEASE_TARGET}
	PUBLIC
	-Os
	)

target_compile_options(${LIBM_RELEASE_TARGET}
	PUBLIC
	-Os
	)

sos_sdk_library_target(LIBC_DEBUG ${LIBC_NAME} "${LIB_OPTION}" debug ${SOS_ARCH})
sos_sdk_library_target(LIBM_DEBUG ${LIBM_NAME} "${LIB_OPTION}" debug ${SOS_ARCH})
add_library(${LIBC_DEBUG_TARGET} STATIC)
add_library(${LIBM_DEBUG_TARGET} STATIC)
sos_sdk_copy_target(${LIBC_RELEASE_TARGET} ${LIBC_DEBUG_TARGET})
sos_sdk_copy_target(${LIBM_RELEASE_TARGET} ${LIBM_DEBUG_TARGET})
sos_sdk_library_add_arch_targets("${LIBC_DEBUG_OPTIONS}" ${SOS_ARCH} "")
sos_sdk_library_add_arch_targets("${LIBC_RELEASE_OPTIONS}" ${SOS_ARCH} "")
sos_sdk_library_add_arch_targets("${LIBM_DEBUG_OPTIONS}" ${SOS_ARCH} "")
sos_sdk_library_add_arch_targets("${LIBM_RELEASE_OPTIONS}" ${SOS_ARCH} "")

add_custom_target(
	libc_format
	COMMAND /usr/local/bin/clang-format
	-i
	--verbose
	${FORMAT_LIST}
	)


