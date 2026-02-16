# This is a "GNU make" make file.
#

INSTALL_DIR = $(PREFIX)/bin

PRE_BUILD := options.h
BUILD_NO_INSTALL := options.h


program_SOURCES :=\
 program.c\
 ../lib/debug.c\
 cmdlopt.c

options.h: ../lib/cmdlopt/misc/programHelp
	if ! ./$< -c > $@ ; then\
		rm -f $@; exit 1; fi


include ../quickbuild.make
