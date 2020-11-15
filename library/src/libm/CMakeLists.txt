sos_sdk_add_subdirectory(COMMON_SOURCES common)
sos_sdk_add_subdirectory(COMPLEX_SOURCES complex)
sos_sdk_add_subdirectory(MACHINE_SOURCES machine)
sos_sdk_add_subdirectory(MATH_SOURCES math)
sos_sdk_add_subdirectory(MATHFP_SOURCES mathfp)
sos_sdk_add_subdirectory(TEST_SOURCES test)


set(SOURCES
	${COMMON_SOURCES}
	${COMPLEX_SOURCES}
	#${MACHINE_SOURCES}
	${MATH_SOURCES}
	${MATHFP_SOURCES}
	#${TEST_SOURCES}
	PARENT_SCOPE)

