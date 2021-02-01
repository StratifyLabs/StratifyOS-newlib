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

sos_sdk_library_target(LIBC_RELEASE ${LIBC_NAME} "${LIB_OPTION}" release ${SOS_ARCH})
sos_sdk_library_target(LIBM_RELEASE ${LIBM_NAME} "${LIB_OPTION}" release ${SOS_ARCH})
sos_sdk_library_target(LIBA ${LIBA_NAME} "STRING_ONLY" release ${SOS_ARCH})
sos_sdk_library_target(LIBA_INTEGER ${LIBA_NAME} "INTEGER_ONLY" release ${SOS_ARCH})

add_library(${LIBC_RELEASE_TARGET} STATIC)
add_library(${LIBM_RELEASE_TARGET} STATIC)

add_library(${LIBA_TARGET} OBJECT)
add_library(${LIBA_INTEGER_TARGET} OBJECT)

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

target_sources(${LIBA_TARGET}
	PRIVATE
	${LIBA_SOURCES}
)

target_sources(${LIBA_INTEGER_TARGET}
	PRIVATE
	${LIBA_SOURCES}
)

target_compile_definitions(${LIBA_TARGET}
	PUBLIC
	${PUBLIC_DEFINITIONS}
	PRIVATE
	${PRIVATE_DEFINITIONS}
	-DSTRING_ONLY
	)

target_compile_definitions(${LIBA_INTEGER_TARGET}
	PUBLIC
	${PUBLIC_DEFINITIONS}
	PRIVATE
	${PRIVATE_DEFINITIONS}
	-DSTRING_ONLY
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

sos_sdk_library_target(LIBC_DEBUG ${LIBC_NAME} "${LIB_OPTION}" debug ${SOS_ARCH})
sos_sdk_library_target(LIBM_DEBUG ${LIBM_NAME} "${LIB_OPTION}" debug ${SOS_ARCH})
add_library(${LIBC_DEBUG_TARGET} STATIC)
add_library(${LIBM_DEBUG_TARGET} STATIC)

sos_sdk_copy_target(${LIBC_RELEASE_TARGET} ${LIBC_DEBUG_TARGET})
sos_sdk_copy_target(${LIBM_RELEASE_TARGET} ${LIBM_DEBUG_TARGET})

sos_sdk_library_add_arch_targets("${LIBA_OPTIONS}" ${SOS_ARCH} "")
sos_sdk_library_add_arch_targets("${LIBA_INTEGER_OPTIONS}" ${SOS_ARCH} "")
sos_sdk_library_add_arch_targets("${LIBC_DEBUG_OPTIONS}" ${SOS_ARCH} "")
sos_sdk_library_add_arch_targets("${LIBC_RELEASE_OPTIONS}" ${SOS_ARCH} "")
sos_sdk_library_add_arch_targets("${LIBM_DEBUG_OPTIONS}" ${SOS_ARCH} "")
sos_sdk_library_add_arch_targets("${LIBM_RELEASE_OPTIONS}" ${SOS_ARCH} "")

target_sources(${LIBC_RELEASE_TARGET}
	PUBLIC
	PRIVATE
	${LIBC_SOURCES}
	$<TARGET_OBJECTS:${LIBA_TARGET}>
	$<TARGET_OBJECTS:${LIBA_INTEGER_TARGET}>
	)

foreach(ARCH ${SOS_ARCH_LIST})
	target_sources(${LIBC_NAME}_release_${ARCH}
		PUBLIC
		PRIVATE
		${LIBC_SOURCES}
		$<TARGET_OBJECTS:${LIBA_NAME}_STRING_ONLY_release_${ARCH}>
		$<TARGET_OBJECTS:${LIBA_NAME}_INTEGER_ONLY_release_${ARCH}>
		)

	target_sources(${LIBC_NAME}_debug_${ARCH}
		PUBLIC
		PRIVATE
		${LIBC_SOURCES}
		$<TARGET_OBJECTS:${LIBA_NAME}_STRING_ONLY_release_${ARCH}>
		$<TARGET_OBJECTS:${LIBA_NAME}_INTEGER_ONLY_release_${ARCH}>
		)
endforeach()

install(DIRECTORY
	src/libc/include/
	DESTINATION include
	PATTERN CMakelists.txt EXCLUDE)


install(FILES
	${CMAKE_CURRENT_SOURCE_DIR}/newlib.cmake
	DESTINATION
	${SOS_SDK_PATH}/cmake/targets)


