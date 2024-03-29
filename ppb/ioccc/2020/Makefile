#!/usr/bin/env make
#
# 2020 makefile
#
# This work by Landon Curt Noll, Simon Cooper, and Leonid A. Broukhis
# is licensed under:
#
#	Creative Commons Attribution-ShareAlike 3.0 Unported License.
#
# See: http://creativecommons.org/licenses/by-sa/3.0/


################
# tool locations
################
#
SHELL= /bin/bash
#
BUNZIP2= bunzip2
BZIP2= bzip2
CP= cp
CPP= cpp
CURL= curl
DD= dd
ECHO= echo
GREP= grep
GUNZIP= gunzip
GZIP_PROG= gzip
LD= ld
MAKE= make
MKDIR= mkdir
MV= mv
RM= rm
SED= sed
SORT= sort
STRIP= strip
TAR= tar
TR= tr
TRUE= true
UNIQ= uniq

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
WINNERS= burton carlini endoh1 endoh2 endoh3 ferguson1 ferguson2 giles \
	 kurdyukov1 kurdyukov2 kurdyukov3 otterness tsoj yang

# Notes for OSCS:
# - kurdyukov4 removed from WINNERS due to requiring Internet connection

# OSCS: bear disabled to avoid regenerating compile_commands.json files with
#       absolute paths.
BEAR=
# Uncomment line below to re-enable bear
#BEAR=bear

###################
# build all entries
###################
#
all:
	@for i in ${WINNERS} ; do \
	    ${ECHO} "(cd $$i && $(BEAR) $(MAKE) X11_LIBDIR=${X11_LIBDIR} X11_INCDIR=${X11_INCDIR} $@)"; \
	    (cd $$i && $(BEAR) $(MAKE) "X11_LIBDIR=${X11_LIBDIR}" "X11_INCDIR=${X11_INCDIR}" $@); \
	done

# alternative executable
#
alt:
	@for i in ${WINNERS} ; do \
	    ${ECHO} "(cd $$i && $(BEAR) $(MAKE) X11_LIBDIR=${X11_LIBDIR} X11_INCDIR=${X11_INCDIR} $@)"; \
	    (cd $$i && $(BEAR) $(MAKE) "X11_LIBDIR=${X11_LIBDIR}" "X11_INCDIR=${X11_INCDIR}" $@); \
	done


###############
# utility rules
###############
#
everything: all alt

clean:
	@for i in ${WINNERS} ; do \
	    ${ECHO} "(cd $$i && $(BEAR) $(MAKE) $@)"; \
	    (cd $$i && $(BEAR) $(MAKE) $@); \
	done

clobber:
	@for i in ${WINNERS} ; do \
	    ${ECHO} "(cd $$i && $(BEAR) $(MAKE) $@)"; \
	    (cd $$i && $(BEAR) $(MAKE) $@); \
	done

nuke: clobber
	@for i in ${WINNERS} ; do \
	    ${ECHO} "(cd $$i && $(BEAR) $(MAKE) $@)"; \
	    (cd $$i && $(BEAR) $(MAKE) $@); \
	done

install:
	@for i in ${WINNERS} ; do \
	    ${ECHO} "(cd $$i && $(BEAR) $(MAKE) $@)"; \
	    (cd $$i && $(BEAR) $(MAKE) $@); \
	done


##################
# 133t hacker rulz
##################
#
love:
	@for i in ${WINNERS} ; do \
	    ${ECHO} "(cd $$i && $(BEAR) $(MAKE) $@)"; \
	    (cd $$i && $(BEAR) $(MAKE) $@); \
	done

haste:
	@for i in ${WINNERS} ; do \
	    ${ECHO} "(cd $$i && $(BEAR) $(MAKE) $@)"; \
	    (cd $$i && $(BEAR) $(MAKE) $@); \
	done

waste:
	@for i in ${WINNERS} ; do \
	    ${ECHO} "(cd $$i && $(BEAR) $(MAKE) $@)"; \
	    (cd $$i && $(BEAR) $(MAKE) $@); \
	done

make:
	@for i in ${WINNERS} ; do \
	    ${ECHO} "(cd $$i && $(BEAR) $(MAKE) $@)"; \
	    (cd $$i && $(BEAR) $(MAKE) $@); \
	done

easter_egg:
	@for i in ${WINNERS} ; do \
	    ${ECHO} "(cd $$i && $(BEAR) $(MAKE) $@)"; \
	    (cd $$i && $(BEAR) $(MAKE) $@); \
	done

fabricate fashion form frame manufacture produce:
	@for i in ${WINNERS} ; do \
	    ${ECHO} "(cd $$i && $(BEAR) $(MAKE) $@)"; \
	    (cd $$i && $(BEAR) $(MAKE) $@); \
	done

sandwich:
	@for i in ${WINNERS} ; do \
	    ${ECHO} "(cd $$i && $(BEAR) $(MAKE) $@)"; \
	    (cd $$i && $(BEAR) $(MAKE) $@); \
	done


# The IOCCC resident astronomer states
#
charon: supernova
	@for i in ${WINNERS} ; do \
	    ${ECHO} "(cd $$i && $(BEAR) $(MAKE) $@)"; \
	    (cd $$i && $(BEAR) $(MAKE) $@); \
	done

pluto: supernova
	@for i in ${WINNERS} ; do \
	    ${ECHO} "(cd $$i && $(BEAR) $(MAKE) $@)"; \
	    (cd $$i && $(BEAR) $(MAKE) $@); \
	done
