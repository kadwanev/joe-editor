/*
 *	Various utilities
 *	Copyright
 *		(C) 1992 Joseph H. Allen
 *		(C) 2001 Marek 'Marx' Grac
 *
 *	This file is part of JOE (Joe's Own Editor)
 */
#include "config.h"

#include <ctype.h>
#include <errno.h>
#ifdef HAVE_UNISTD_H
#include <unistd.h>
#endif
#ifdef HAVE_STDLIB_H
#include <stdlib.h>
#endif

#include "utils.h"

/*
 * Whitespace characters are characters like tab, space, ...
 *      Every config line in *rc must be end by whitespace but
 *      EOF is not considered as whitespace by isspace()
 *      This is because I don't want to be forced to end
 *      *rc file with \n
 */
int isspace_eof(int c)
{
	return(isspace(c) || (!c));
}

/*
 * Define function isblank(c)
 *	!!! code which uses isblank() assumes tested char is evaluated
 *	only once, so it musn't be a macro
 */
#ifndef HAVE_WORKING_ISBLANK
int isblank(int c)
{
        return((c == 32) || (c == 9));
}
#endif

/*
 * return minimum/maximum of two numbers
 */
unsigned int uns_min(unsigned int a, unsigned int b)
{
	return a < b ? a : b;
}

signed int int_min(signed int a, signed int b)
{
	return a < b ? a : b;
}

signed long int long_max(signed long int a, signed long int b)
{
	return a > b ? a : b;
}

signed long int long_min(signed long int a, signed long int b)
{
	return a < b ? a : b;
}

/* 
 * Characters which are considered as word characters 
 * 	_ is considered as word character because is often used 
 *	in the names of C/C++ functions
 */
unsigned int isalnum_(unsigned int c)
{
	return (isalnum(c) || (c == 95));
}

/* Versions of 'read' and 'write' which automatically retry when interrupted */
ssize_t joe_read(int fd, void *buf, size_t size)
{
	ssize_t rt;

	do {
		rt = read(fd, buf, size);
	} while (rt < 0 && errno == EINTR);
	return rt;
}

ssize_t joe_write(int fd, void *buf, size_t size)
{
	ssize_t rt;

	do {
		rt = write(fd, buf, size);
	} while (rt < 0 && errno == EINTR);
	return rt;
}

/* wrappers to *alloc routines */
void *joe_malloc(size_t size)
{
	return malloc(size);
}

void *joe_calloc(size_t nmemb, size_t size)
{
	return calloc(nmemb, size);
}

void *joe_realloc(void *ptr, size_t size)
{
	return realloc(ptr, size);
}

void joe_free(void *ptr)
{
	free(ptr);
}
