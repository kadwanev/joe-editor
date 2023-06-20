/*
 *	Various utilities
 *	
 *	Copyright
 *		(C) 1992 Joseph H. Allen
 *		(C) 2001 Marek 'Marx' Grac
 *
 *	This file is part of JOE (Joe's Own Editor)
 */
#ifndef _JOE_UTILS_H
#define _JOE_UTILS_H 1

#include "config.h"

#ifdef HAVE_SYS_TYPES_H
#include <sys/types.h>			/* we need size_t, ssize_t */
#endif
#ifdef HAVE_SIGNAL_H
#include <signal.h>
#endif

/* 
 * Characters which are considered as word characters 
 * 	_ is considered as word character because is often used 
 *	in the names of C/C++ functions
 */
int isalnum_ PARAMS((int wide,int c));

/* 
 * Whitespace characters are characters like tab, space, ...
 *	Every config line in *rc must be end by whitespace but
 *	EOF is not considered as whitespace by isspace()
 *	This is because I don't want to be forced to end 
 *	*rc file with \n
 */
int isspace_eof PARAMS((int c));

/*
 * Define function isblank(c)
 *	isblank() is GNU extension;
 *	even #including <ctype.h> without additional hackery doesn't import
 *	the prototype, so we define it here unconditionaly
 */
int joe_isblank PARAMS((int c));

unsigned char *lowerize PARAMS((unsigned char *s));

/*
 * Functions which return minimum/maximum of two numbers  
 */
unsigned int uns_min PARAMS((unsigned int a, unsigned int b));
signed int int_min PARAMS((signed int a, int signed b));
signed long long_max PARAMS((signed long a, signed long b));
signed long long_min PARAMS((signed long a, signed long b));

/* Versions of 'read' and 'write' which automatically retry when interrupted */
ssize_t joe_read PARAMS((int fd, void *buf, size_t siz));
ssize_t joe_write PARAMS((int fd, void *buf, size_t siz));

/* wrappers to *alloc routines */
void *joe_malloc PARAMS((size_t size));
void *joe_calloc PARAMS((size_t nmemb, size_t size));
void *joe_realloc PARAMS((void *ptr, size_t size));
void joe_free PARAMS((void *ptr));


#ifndef HAVE_SIGHANDLER_T
typedef RETSIGTYPE (*sighandler_t)(int);
#endif

#ifdef NEED_TO_REINSTALL_SIGNAL
#define REINSTALL_SIGHANDLER(sig, handler) joe_set_signal(sig, handler)
#else
#define REINSTALL_SIGHANDLER(sig, handler) do {} while(0)
#endif

/* wrapper to hide signal interface differrencies */
int joe_set_signal PARAMS((int signum, sighandler_t handler));

int parse_ws PARAMS((unsigned char **p));
int parse_ident PARAMS((unsigned char **p,unsigned char *buf,int len));
int parse_kw PARAMS((unsigned char **p,unsigned char *kw));
int parse_field PARAMS((unsigned char **p,unsigned char *field));
int parse_char PARAMS((unsigned char  **p,unsigned char c));
int parse_int PARAMS((unsigned char **p,int *buf));
int parse_string PARAMS((unsigned char **p,unsigned char *buf,int len));
int parse_range PARAMS((unsigned char **p,int *first,int *second));


#endif
