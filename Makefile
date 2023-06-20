# Generated automatically from Makefile.in by configure.
###########################################################
##### Makefile for Joe's Own Editor #######################
###########################################################
SHELL = /bin/sh
.SUFFIXES:
.SUFFIXES: .c .o

###########################################################
##### Directories
#####
### If you want to build package just set package_prefix
### to directory where you want to build it
###########################################################
package_prefix = 

prefix = /usr/local
exec_prefix = ${prefix}
srcdir = .
bindir = ${exec_prefix}/bin
sysconfdir = ${prefix}/etc
mandir = ${prefix}/man
man1dir = $(mandir)/man1

###########################################################
##### Programs
###########################################################
INSTALL = /usr/bin/ginstall -c
INSTALL_PROGRAM = ${INSTALL}
INSTALL_DATA = ${INSTALL} -m 644
CC = gcc

###########################################################
##### System dependant variables
###########################################################

# If you want to use TERMINFO, you have to set
# the following variable to 1.  Also you have to
# include some additional libraries- see below.

TERMINFO = 1

# You may also have to add some additional
# defines to get the include files to work
# right on some systems.
#
# for some HPUX systems, you need to add:  -D_HPUX_SOURCE

# C compiler options: make's built-in rules use this variable

CFLAGS = -O2 -fsigned-char -fomit-frame-pointer -pipe -Wall

# You may have to include some extra libraries
# for some systems
#
# for Xenix, add (in this order!!): -ldir -lx

# For some systems you might have to add: -lbsd
# to get access to the timer system calls.

# If you wish to use terminfo, you have to
# add '-ltinfo', '-lcurses' or '-ltermlib',
# depending on the system.

EXTRALIBS = -lncurses

###########################################################
##### Rules for compilation, installation, ...
###########################################################
OBJS = b.o blocks.o bw.o cmd.o hash.o help.o kbd.o macro.o main.o menu.o \
 path.o poshist.o pw.o queue.o qw.o rc.o regex.o scrn.o tab.o \
 termcap.o tty.o tw.o ublock.o uedit.o uerror.o ufile.o uformat.o uisrch.o \
 umath.o undo.o usearch.o ushell.o utag.o va.o vfile.o vs.o w.o \
 utils.o

joe: $(OBJS)
	rm -f jmacs jstar rjoe jpico
	$(CC) $(CFLAGS) -o joe $(OBJS) $(EXTRALIBS)
	ln -s joe jmacs
	ln -s joe jstar
	ln -s joe rjoe
	ln -s joe jpico

$(OBJS): config.h

config.h:
	$(CC) conf.c -o conf
	./conf $(sysconfdir) $(TERMINFO)

termidx: termidx.o
	$(CC) $(CFLAGS) -o termidx termidx.o

install: joe termidx installdirs
	rm -f $(package_prefix)$(bindir)/joe $(package_prefix)$(bindir)/jmacs $(package_prefix)$(bindir)/jstar $(package_prefix)$(bindir)/jpico $(package_prefix)$(bindir)/rjoe $(package_prefix)$(bindir)/termidx

	$(INSTALL_PROGRAM) -s joe $(package_prefix)$(bindir)

	(cd $(package_prefix)/$(bindir) && ln -s joe jmacs)
	(cd $(package_prefix)/$(bindir) && ln -s joe jstar)
	(cd $(package_prefix)/$(bindir) && ln -s joe jpico)
	(cd $(package_prefix)/$(bindir) && ln -s joe rjoe)

	$(INSTALL_PROGRAM) -s termidx $(package_prefix)$(bindir)

	if [ -a $(package_prefix)$(sysconfdir)/joerc ]; then echo; else $(INSTALL_DATA) joerc $(package_prefix)$(sysconfdir); fi
	if [ -a $(package_prefix)$(sysconfdir)/jmacsrc ]; then echo; else $(INSTALL_DATA) jmacsrc $(package_prefix)$(sysconfdir); fi
	if [ -a $(package_prefix)$(sysconfdir)/jstarrc ]; then echo; else $(INSTALL_DATA) jstarrc $(package_prefix)$(sysconfdir); fi
	if [ -a $(package_prefix)$(sysconfdir)/rjoerc ]; then echo; else $(INSTALL_DATA) rjoerc $(package_prefix)$(sysconfdir); fi
	if [ -a $(package_prefix)$(sysconfdir)/jpicorc ]; then echo; else $(INSTALL_DATA) jpicorc $(package_prefix)$(sysconfdir); fi

	rm -f $(package_prefix)$(man1dir)/joe.1
	$(INSTALL_DATA) joe.1 $(package_prefix)$(man1dir)

clean:
	rm -f $(OBJS) termidx.o conf conf.o config.h joe jmacs jpico jstar rjoe termidx
	rm -f joe-config.h config.log config.status config.cache config.status

installdirs: mkinstalldirs
	$(srcdir)/mkinstalldirs $(package_prefix)$(bindir) $(package_prefix)$(man1dir) $(package_prefix)$(sysconfdir)
