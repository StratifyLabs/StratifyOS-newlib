
set(SOURCES
	arm/access.c
	arm/acle-compat.h

	arm/aeabi_memclr.c
	#arm/aeabi_memcpy-armv7a.S
	arm/aeabi_memcpy.c
	#arm/aeabi_memmove-arm.S
	#arm/aeabi_memmove-soft.S
	#arm/aeabi_memmove-thumb.S
	#arm/aeabi_memmove-thumb2.S
	arm/aeabi_memmove.c
	#arm/aeabi_memset-arm.S
	#arm/aeabi_memset-soft.S
	#arm/aeabi_memset-thumb.S
	#arm/aeabi_memset-thumb2.S
	arm/aeabi_memset.c
	arm/arm_asm.h


	arm/memchr-stub.c
	arm/memchr.S
	#arm/memcpy-armv7a.S
	#arm/memcpy-armv7m.S
	arm/memcpy-stub.c
	arm/memcpy.S
	arm/setjmp.S
	#arm/strcmp-arm-tiny.S
	#arm/strcmp-armv4.S
	#arm/strcmp-armv4t.S
	#arm/strcmp-armv6.S
	#arm/strcmp-armv6m.S
	#arm/strcmp-armv7.S
	#arm/strcmp-armv7m.S
	arm/strcmp.S
	arm/strcpy.c
	#arm/strlen-armv7.S
	arm/strlen-stub.c
	#arm/strlen-thumb1-Os.S
	#arm/strlen-thumb2-Os.S
	arm/strlen.S
	arm/endian.h
	arm/param.h


	PARENT_SCOPE)
