#ifndef __SYS_LOCK_H__
#define __SYS_LOCK_H__

/* dummy lock routines for single-threaded aps */
#ifdef __StratifyOS__

#include <_ansi.h>
#include <sys/features.h>
#include <sys/syslimits.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
  int   is_initialized;
#if defined(_POSIX_THREAD_PROCESS_SHARED)
  int   process_shared;  /* allow mutex to be shared amongst processes */
#endif
#if defined(_POSIX_THREAD_PRIO_PROTECT)
  int   prio_ceiling;
  int   protocol;
#endif
#if defined(_UNIX98_THREAD_MUTEX_ATTRIBUTES)
  int type;
#endif
  int   recursive;
} pthread_mutexattr_t;


typedef struct {
	int pid;
	int pthread;
	int prio_ceiling;
	int flags;
	int lock;
} pthread_mutex_t;

typedef pthread_mutex_t _LOCK_T;
typedef pthread_mutex_t _LOCK_RECURSIVE_T;


typedef struct {
	const void * fs;
	void * handle;
	int flags;
	int loc;
} open_file_t;


typedef unsigned long  __sigset_t;

#define _PROC_FLAG_SIGCAUGHT 0
#define _PROC_FLAG_SIGCHLD 1

typedef struct {
	int size;
	_LOCK_RECURSIVE_T __malloc_lock_object;
	_LOCK_T __tz_lock_object;
	_LOCK_RECURSIVE_T __atexit_lock;
	_LOCK_RECURSIVE_T __sfp_lock;
	_LOCK_RECURSIVE_T __sinit_lock;
	_LOCK_RECURSIVE_T __env_lock_object;
	struct sigaction ** sigactions;
	void * siginfos;
	int flags;
	open_file_t open_file[OPEN_MAX];
	const char * proc_name;
	void * base;
} proc_mem_t;

extern int pthread_mutex_init(pthread_mutex_t * mutex, _CONST pthread_mutexattr_t * attr);
extern int pthread_mutex_destroy(pthread_mutex_t * mutex);
extern int pthread_mutex_lock(pthread_mutex_t * mutex);
extern int pthread_mutex_unlock(pthread_mutex_t * mutex);

#ifdef __cplusplus
}
#endif

#define __lock_init_global(lock) pthread_mutex_init(&(_REENT->procmem_base->lock), NULL)
#define __lock_init_recursive_global(lock) do { pthread_mutex_init(&(_REENT->procmem_base->lock), NULL); _REENT->procmem_base->lock.flags |= PTHREAD_MUTEX_FLAGS_RECURSIVE; } while(0)
#define __lock_close_global(lock) pthread_mutex_destroy(&(_REENT->procmem_base->lock))
#define __lock_close_recursive_global(lock) pthread_mutex_destroy(&(_REENT->procmem_base->lock))
#define __lock_acquire_global(lock) pthread_mutex_lock(&(_REENT->procmem_base->lock))
#define __lock_acquire_recursive_global(lock) pthread_mutex_lock(&(_REENT->procmem_base->lock))
#define __lock_try_acquire_global(lock) pthread_mutex_trylock(&(_REENT->procmem_base->lock))
#define __lock_try_acquire_recursive_global(lock) pthread_mutex_trylock(&(_REENT->procmem_base->lock))
#define __lock_release_global(lock) pthread_mutex_unlock(&(_REENT->procmem_base->lock))
#define __lock_release_recursive_global(lock) pthread_mutex_unlock(&(_REENT->procmem_base->lock))


#define __lock_init(lock) pthread_mutex_init(&lock, NULL)
#define __lock_init_recursive(lock) do { pthread_mutex_init(&lock, NULL); lock.flags |= PTHREAD_MUTEX_FLAGS_RECURSIVE; } while(0)
#define __lock_close(lock) pthread_mutex_destroy(&lock)
#define __lock_close_recursive(lock) pthread_mutex_destroy(&lock)
#define __lock_acquire(lock) pthread_mutex_lock(&lock)
#define __lock_acquire_recursive(lock) pthread_mutex_lock(&lock)
#define __lock_try_acquire(lock) pthread_mutex_trylock(&lock)
#define __lock_try_acquire_recursive(lock) pthread_mutex_trylock(&lock)
#define __lock_release(lock) pthread_mutex_unlock(&lock)
#define __lock_release_recursive(lock) pthread_mutex_unlock(&lock)

#define __LOCK_INIT(class,lock) class _LOCK_T lock;
#define __LOCK_INIT_RECURSIVE(class,lock) class _LOCK_RECURSIVE_T lock;
#else

typedef int _LOCK_T;
typedef int _LOCK_RECURSIVE_T;
 
#include <_ansi.h>

#define __LOCK_INIT(class,lock) static int lock = 0;
#define __LOCK_INIT_RECURSIVE(class,lock) static int lock = 0;
#define __lock_init(lock) (_CAST_VOID 0)
#define __lock_init_recursive(lock) (_CAST_VOID 0)
#define __lock_close(lock) (_CAST_VOID 0)
#define __lock_close_recursive(lock) (_CAST_VOID 0)
#define __lock_acquire(lock) (_CAST_VOID 0)
#define __lock_acquire_recursive(lock) (_CAST_VOID 0)
#define __lock_try_acquire(lock) (_CAST_VOID 0)
#define __lock_try_acquire_recursive(lock) (_CAST_VOID 0)
#define __lock_release(lock) (_CAST_VOID 0)
#define __lock_release_recursive(lock) (_CAST_VOID 0)
#endif

#endif /* __SYS_LOCK_H__ */
