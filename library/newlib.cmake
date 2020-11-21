
if(NOT DEFINED IS_SDK)
	set(COMPILER_RT_CONFIG_LIST release debug)
	sos_sdk_include_target(newlib_libc "${COMPILER_RT_CONFIG_LIST}")
	sos_sdk_include_target(newlib_libm "${COMPILER_RT_CONFIG_LIST}")
endif()
