# This is a "GNU make" make file.
#

INSTALL_DIR = $(PREFIX)/bin

PRE_BUILD := programOptions.h
BUILD_NO_INSTALL := programOptions.h


program_SOURCES :=\
 program.c\
 ../lib/debug.c\
 cmdlopt.c

programOptions.h: ../lib/cmdlopt/misc/programHelp
	if ! ./$< -c > $@ ; then\
		rm -f $@; exit 1; fi


include ../quickbuild.make
