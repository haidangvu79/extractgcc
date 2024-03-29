#!/usr/bin/env make
#
# 2019 makefile
#
# This work by Landon Curt Noll, Simon Cooper, and Leonid A. Broukhis
# is licensed under:
#
#	Creative Commons Attribution-ShareAlike 3.0 Unported License.
#
# See: http://creativecommons.org/licenses/by-sa/3.0/

#############################
# shell used by this Makefile
#############################
#
SHELL= /bin/bash

# Set X11_LIBDIR to the directory where the X11 library resides
#
#X11_LIBDIR= /usr/X11R6/lib
#X11_LIBDIR= /usr/X11/lib
X11_LIBDIR= /opt/X11/lib

# Set X11_INCLUDEDIR to the directory where the X11 include files reside
#
#X11_INCDIR= /usr/X11R6/include
#X11_INCDIR= /usr/X11/include
X11_INCDIR= /opt/X11/include

# ANSI compiler
#
# Set CC to the name of your ANSI compiler.
#
CC= cc


###############
# IOCCC winners
###############
#
WINNERS= giles diels-grabsch1 poikola lynn burton dogon karns ciura diels-grabsch2 endoh yang adamovsky

# Notes for OSCS:
# - adamovsky only partially compiles with GCC 12; its Makefile was modified
#   to disable the problematic programs
# - duble no longer compiles with GCC 12; it has been removed from WINNERS
# - mills had some large files removed; it has been removed from WINNERS

###################
# build all entries
###################
#
all:
	@for i in ${WINNERS} ; do \
	    echo "(cd $$i && $(MAKE) X11_LIBDIR=${X11_LIBDIR} X11_INCDIR=${X11_INCDIR} $@)"; \
	    (cd $$i && $(MAKE) "X11_LIBDIR=${X11_LIBDIR}" "X11_INCDIR=${X11_INCDIR}" $@); \
	done

# alternative executable
#
alt:
	@for i in ${WINNERS} ; do \
	    echo "(cd $$i && $(MAKE) X11_LIBDIR=${X11_LIBDIR} X11_INCDIR=${X11_INCDIR} $@)"; \
	    (cd $$i && $(MAKE) "X11_LIBDIR=${X11_LIBDIR}" "X11_INCDIR=${X11_INCDIR}" $@); \
	done


###############
# utility rules
###############
#
everything: all alt

clean:
	@for i in ${WINNERS} ; do \
	    echo "(cd $$i && $(MAKE) $@)"; \
	    (cd $$i && $(MAKE) $@); \
	done

clobber:
	@for i in ${WINNERS} ; do \
	    echo "(cd $$i && $(MAKE) $@)"; \
	    (cd $$i && $(MAKE) $@); \
	done

nuke: clobber
	@for i in ${WINNERS} ; do \
	    echo "(cd $$i && $(MAKE) $@)"; \
	    (cd $$i && $(MAKE) $@); \
	done

install:
	@for i in ${WINNERS} ; do \
	    echo "(cd $$i && $(MAKE) $@)"; \
	    (cd $$i && $(MAKE) $@); \
	done


##################
# 133t hacker rulz
##################
#
love:
	@for i in ${WINNERS} ; do \
	    echo "(cd $$i && $(MAKE) $@)"; \
	    (cd $$i && $(MAKE) $@); \
	done

haste:
	@for i in ${WINNERS} ; do \
	    echo "(cd $$i && $(MAKE) $@)"; \
	    (cd $$i && $(MAKE) $@); \
	done

waste:
	@for i in ${WINNERS} ; do \
	    echo "(cd $$i && $(MAKE) $@)"; \
	    (cd $$i && $(MAKE) $@); \
	done

make:
	@for i in ${WINNERS} ; do \
	    echo "(cd $$i && $(MAKE) $@)"; \
	    (cd $$i && $(MAKE) $@); \
	done

easter_egg:
	@for i in ${WINNERS} ; do \
	    echo "(cd $$i && $(MAKE) $@)"; \
	    (cd $$i && $(MAKE) $@); \
	done

fabricate fashion form frame manufacture produce:
	@for i in ${WINNERS} ; do \
	    echo "(cd $$i && $(MAKE) $@)"; \
	    (cd $$i && $(MAKE) $@); \
	done

sandwich:
	@for i in ${WINNERS} ; do \
	    echo "(cd $$i && $(MAKE) $@)"; \
	    (cd $$i && $(MAKE) $@); \
	done


# The IOCCC resident astronomer states
#
charon: supernova
	@for i in ${WINNERS} ; do \
	    echo "(cd $$i && $(MAKE) $@)"; \
	    (cd $$i && $(MAKE) $@); \
	done

pluto: supernova
	@for i in ${WINNERS} ; do \
	    echo "(cd $$i && $(MAKE) $@)"; \
	    (cd $$i && $(MAKE) $@); \
	done
