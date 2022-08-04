

cmsdk_add_subdirectory(ARGZ_SOURCES argz)
cmsdk_add_subdirectory(CTYPE_SOURCES ctype)
cmsdk_add_subdirectory(ERRNO_SOURCES errno)
cmsdk_add_subdirectory(ICONV_SOURCES iconv)
cmsdk_add_subdirectory(LOCALE_SOURCES locale)
cmsdk_add_subdirectory(MACHINE_SOURCES machine)
cmsdk_add_subdirectory(MISC_SOURCES misc)
#cmsdk_add_subdirectory(POSIX_SOURCES posix)
cmsdk_add_subdirectory(REENT_SOURCES reent)
cmsdk_add_subdirectory(SEARCH_SOURCES search)
cmsdk_add_subdirectory(SIGNAL_SOURCES signal)
cmsdk_add_subdirectory(STDIO_SOURCES stdio)
cmsdk_add_subdirectory(STDLIB_SOURCES stdlib)
cmsdk_add_subdirectory(STRING_SOURCES string)
cmsdk_add_subdirectory(SYS_SOURCES sys)
cmsdk_add_subdirectory(SYSCALLS_SOURCES syscalls)
cmsdk_add_subdirectory(TIME_SOURCES time)
cmsdk_add_subdirectory(UNIX_SOURCES unix)
cmsdk_add_subdirectory(XDR_SOURCES xdr)


set(SOURCES
	${ARGZ_SOURCES}
	${CTYPE_SOURCES}
	${ERRNO_SOURCES}
	${ICONV_SOURCES}
	${LOCALE_SOURCES}
	#${MACHINE_SOURCES}
	${MISC_SOURCES}
	#${POSIX_SOURCES}
	${REENT_SOURCES}
	${SEARCH_SOURCES}
	${SIGNAL_SOURCES}
	${SYS_SOURCES}
	${STDIO_SOURCES}
	${STDLIB_SOURCES}
	${STRING_SOURCES}
	${STRING_SOURCES}
	${SYSCALLS_SOURCES}
	${TIME_SOURCES}
	#${UNIX_SOURCES}
	#${XDR_SOURCES}
	PARENT_SCOPE)
