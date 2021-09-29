/*
 * Copyright (c) 1988, 1993
 *	The Regents of the University of California.  All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. All advertising materials mentioning features or use of this software
 *    must display the following acknowledgement:
 *	This product includes software developed by the University of
 *	California, Berkeley and its contributors.
 * 4. Neither the name of the University nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 *	@(#)syslimits.h	8.1 (Berkeley) 6/2/93
 * $FreeBSD: src/sys/sys/syslimits.h,v 1.10 2001/06/18 20:24:54 wollman Exp $
 */

#ifndef _SYS_SYSLIMITS_H_
#define _SYS_SYSLIMITS_H_

#define PATH_MAX_LARGE 255
#define PATH_MAX_MEDIUM 127
#define PATH_MAX_SMALL 63

#define ARG_MAX_LARGE 511
#define ARG_MAX_MEDIUM 255
#define ARG_MAX_SMALL 127

#define NAME_MAX_LARGE 127
#define NAME_MAX_MEDIUM 63
#define NAME_MAX_SMALL 31

#define OPEN_MAX_LARGE 64
#define OPEN_MAX_MEDIUM 32
#define OPEN_MAX_SMALL 32

#if defined __v7em_f5sh || defined __v7em_f5dh
#define NAME_MAX NAME_MAX_LARGE
#define PATH_MAX PATH_MAX_LARGE
#define OPEN_MAX OPEN_MAX_LARGE
#define ARG_MAX ARG_MAX_LARGE
#define LINE_MAX 2048
#elif defined __v7em_f4sh || defined __v7em
#define NAME_MAX NAME_MAX_MEDIUM
#define PATH_MAX PATH_MAX_MEDIUM
#define OPEN_MAX OPEN_MAX_SMALL
#define ARG_MAX ARG_MAX_MEDIUM
#define LINE_MAX 2048
#else
#define NAME_MAX NAME_MAX_SMALL
#define PATH_MAX PATH_MAX_SMALL
#define OPEN_MAX OPEN_MAX_SMALL
#define ARG_MAX ARG_MAX_SMALL
#define LINE_MAX 2048
#endif

#ifndef CHILD_MAX
#define CHILD_MAX 6 /* max simultaneous processes */
#endif
#define LINK_MAX 32767 /* max file link count */
#define MAX_CANON 255  /* max bytes in term canon input line */
#define MAX_INPUT 255  /* max bytes in terminal input */
#define NGROUPS_MAX 16 /* max supplemental group id's */

#define PIPE_BUF 512       /* max bytes for atomic pipe writes */
#define IOV_MAX 1024       /* max elements in i/o vector */
#define BC_BASE_MAX 99     /* max ibase/obase values in bc(1) */
#define BC_DIM_MAX 2048    /* max array elements in bc(1) */
#define BC_SCALE_MAX 99    /* max scale value in bc(1) */
#define BC_STRING_MAX 1000 /* max const string length in bc(1) */
#define COLL_WEIGHTS_MAX 0 /* max weights for order keyword */
#define EXPR_NEST_MAX 32   /* max expressions nested in expr(1) */
#define LINE_MAX 2048      /* max bytes in an input line */
#define RE_DUP_MAX 255     /* max RE's in interval notation */

#endif
