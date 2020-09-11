

#Add sources to the project
sos_sdk_add_subdirectory(SOS_SOURCELIST src/libc)

set(SOS_DEFINITIONS
	-DPACKAGE_NAME=\"newlib\"
	-DPACKAGE_TARNAME=\"newlib\"
	-DPACKAGE_VERSION=\"2.3.0\"
	-DPACKAGE_STRING=\"newlib\ 2.3.0\"
	-DPACKAGE_BUGREPORT=\"\"
	-DPACKAGE_URL=\"\"
	-D__StratifyOS__
	-D__NO_SYSCALLS__
	-DSIGNAL_PROVIDED
	-DMALLOC_PROVIDED
	-DHAVE_SYSTEM
	-DHAVE_FCNTL
	-DHAVE_RENAME
	-D__BUFSIZ__=64
	-D__IEEE_LITTLE_ENDIAN
	-D__IEEE_BYTES_LITTLE_ENDIAN
	)

set(SOS_INCLUDE_DIRECTORIES
	${CMAKE_SOURCE_DIR}/src/libc/include
	)


set(SOS_BUILD_FLAGS
	-fno-builtin
	-fsingle-precision-constant
	)

# Lib C
set(SOS_CONFIG libc)
set(SOS_OPTION "")
include(${SOS_TOOLCHAIN_CMAKE_PATH}/sos-lib-std.cmake)

set(SOS_SOURCELIST "")
sos_sdk_add_subdirectory(SOS_SOURCELIST src/libm)

set(SOS_DEFINITIONS
	-DPACKAGE_NAME=\"newlib\"
	-DPACKAGE_TARNAME=\"newlib\"
	-DPACKAGE_VERSION=\"2.3.0\"
	-DPACKAGE_STRING=\"newlib\ 2.3.0\"
	-DPACKAGE_BUGREPORT=\"\"
	-DPACKAGE_URL=\"\"
	-D__StratifyOS__
	-D__NO_SYSCALLS__
	-DSIGNAL_PROVIDED
	-DMALLOC_PROVIDED
	-DHAVE_SYSTEM
	-DHAVE_FCNTL
	-DHAVE_RENAME
	-D__BUFSIZ__=64
	-D__IEEE_LITTLE_ENDIAN
	-D__IEEE_BYTES_LITTLE_ENDIAN
	)

set(SOS_INCLUDE_DIRECTORIES
	${CMAKE_SOURCE_DIR}/src/libc/include
	${CMAKE_SOURCE_DIR}/src/libm/common
	)


set(SOS_BUILD_FLAGS
	-fno-builtin
	-fsingle-precision-constant
	)

# Lib M
set(SOS_CONFIG libm)
set(SOS_OPTION "")
include(${SOS_TOOLCHAIN_CMAKE_PATH}/sos-lib-std.cmake)

