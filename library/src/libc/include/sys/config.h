#ifndef __SYS_CONFIG_H__
#define __SYS_CONFIG_H__

#include <machine/ieeefp.h>  /* floating point macros */
#include <sys/features.h>	/* POSIX defs */


#define __SMALL_BITFIELDS



/* This block should be kept in sync with GCC's limits.h.  The point
   of having these definitions here is to not include limits.h, which
   would pollute the user namespace, while still using types of the
   the correct widths when deciding how to define __int32_t and
   __int64_t.  */
#ifndef __INT_MAX__
# ifdef INT_MAX
#  define __INT_MAX__ INT_MAX
# else
#  define __INT_MAX__ 2147483647
# endif
#endif

#ifndef __LONG_MAX__
# ifdef LONG_MAX
#  define __LONG_MAX__ LONG_MAX
# else
#  if defined (__alpha__) || (defined (__sparc__) && defined(__arch64__)) \
      || defined (__sparcv9)
#   define __LONG_MAX__ 9223372036854775807L
#  else
#   define __LONG_MAX__ 2147483647L
#  endif /* __alpha__ || sparc64 */
# endif
#endif
/* End of block that should be kept in sync with GCC's limits.h.  */

#ifndef _POINTER_INT
#define _POINTER_INT long
#endif

#ifdef __frv__
#define __ATTRIBUTE_IMPURE_PTR__ __attribute__((__section__(".sdata")))
#endif
#undef __RAND_MAX
#if __INT_MAX__ == 32767
#define __RAND_MAX 32767
#else
#define __RAND_MAX 0x7fffffff
#endif

#if defined(__CYGWIN__)
#include <cygwin/config.h>
#if !defined (__STRICT_ANSI__) || (__STDC_VERSION__ >= 199901L)
#define __USE_XOPEN2K 1
#endif
#endif

#if defined(__rtems__)
#define __FILENAME_MAX__ 255
#define _READ_WRITE_RETURN_TYPE _ssize_t
#define __DYNAMIC_REENT__
#define _REENT_GLOBAL_ATEXIT
#endif

#ifndef __EXPORT
#define __EXPORT
#endif

#ifndef __IMPORT
#define __IMPORT
#endif

/* Define return type of read/write routines.  In POSIX, the return type
   for read()/write() is "ssize_t" but legacy newlib code has been using
   "int" for some time.  If not specified, "int" is defaulted.  */
#ifndef _READ_WRITE_RETURN_TYPE
#define _READ_WRITE_RETURN_TYPE int
#endif
/* Define `count' parameter of read/write routines.  In POSIX, the `count'
   parameter is "size_t" but legacy newlib code has been using "int" for some
   time.  If not specified, "int" is defaulted.  */
#ifndef _READ_WRITE_BUFSIZE_TYPE
#define _READ_WRITE_BUFSIZE_TYPE int
#endif

#ifndef __WCHAR_MAX__
#if __INT_MAX__ == 32767 || defined (_WIN32)
#define __WCHAR_MAX__ 0xffffu
#endif
#endif

/* See if small reent asked for at configuration time and
   is not chosen by the platform by default.  */
#ifdef _WANT_REENT_SMALL
#ifndef _REENT_SMALL
#define _REENT_SMALL
#endif
#endif

/* If _MB_EXTENDED_CHARSETS_ALL is set, we want all of the extended
   charsets.  The extended charsets add a few functions and a couple
   of tables of a few K each. */
#ifdef _MB_EXTENDED_CHARSETS_ALL
#define _MB_EXTENDED_CHARSETS_ISO 1
#define _MB_EXTENDED_CHARSETS_WINDOWS 1
#endif

#endif /* __SYS_CONFIG_H__ */
