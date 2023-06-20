/*
	Help system
	Copyright
		(C) 1992 Joseph H. Allen
		(C) 2001 Marek 'Marx' Grac

	This file is part of JOE (Joe's Own Editor)
*/

#ifndef _JOEhelp
#define _JOEhelp 1

#include "config.h"
#include "w.h"				/* definitions of BASE & SCREEN */

struct help {
	char *hlptxt;			/* help text with attributes */
	int hlplns;			/* number of lines */
	struct help *prev;		/* previous help screen */
	struct help *next;		/* nex help screen */
};

void help_display(SCREEN * t);		/* display text in help window */
int help_on(SCREEN * t);		/* turn help on */
int help_init(char *filename);		/* load help file */

int u_help(BASE * base);		/* toggle help on/off */
int u_help_next(BASE * base);		/* goto next help screen */
int u_help_prev(BASE * base);		/* goto prev help screen */

#endif
