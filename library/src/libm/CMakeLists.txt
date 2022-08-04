cmsdk_add_subdirectory(COMMON_SOURCES common)
cmsdk_add_subdirectory(COMPLEX_SOURCES complex)
cmsdk_add_subdirectory(MACHINE_SOURCES machine)
cmsdk_add_subdirectory(MATH_SOURCES math)
#cmsdk_add_subdirectory(MATHFP_SOURCES mathfp)
cmsdk_add_subdirectory(TEST_SOURCES test)


set(SOURCES
	${COMMON_SOURCES}
	${COMPLEX_SOURCES}
	#${MACHINE_SOURCES}
	${MATH_SOURCES}
	${MATHFP_SOURCES}
	#${TEST_SOURCES}
	PARENT_SCOPE)

