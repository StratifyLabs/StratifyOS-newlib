

sos_sdk_add_subdirectory(ARGZ_SOURCES argz)
sos_sdk_add_subdirectory(CTYPE_SOURCES ctype)
sos_sdk_add_subdirectory(ERRNO_SOURCES errno)
sos_sdk_add_subdirectory(ICONV_SOURCES iconv)
sos_sdk_add_subdirectory(LOCALE_SOURCES locale)
sos_sdk_add_subdirectory(MACHINE_SOURCES machine)
sos_sdk_add_subdirectory(MISC_SOURCES misc)
#sos_sdk_add_subdirectory(POSIX_SOURCES posix)
sos_sdk_add_subdirectory(REENT_SOURCES reent)
sos_sdk_add_subdirectory(SEARCH_SOURCES search)
sos_sdk_add_subdirectory(SIGNAL_SOURCES signal)
sos_sdk_add_subdirectory(STDIO_SOURCES stdio)
sos_sdk_add_subdirectory(STDLIB_SOURCES stdlib)
sos_sdk_add_subdirectory(STRING_SOURCES string)
sos_sdk_add_subdirectory(SYSCALLS_SOURCES syscalls)
sos_sdk_add_subdirectory(TIME_SOURCES time)
sos_sdk_add_subdirectory(UNIX_SOURCES unix)
sos_sdk_add_subdirectory(XDR_SOURCES xdr)


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
	${STDIO_SOURCES}
	${STDLIB_SOURCES}
	${STRING_SOURCES}
	${STRING_SOURCES}
	${SYSCALLS_SOURCES}
	${TIME_SOURCES}
	#${UNIX_SOURCES}
	#${XDR_SOURCES}
	PARENT_SCOPE)
