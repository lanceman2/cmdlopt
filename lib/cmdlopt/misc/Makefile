
topdir := ../../..


INSTALL_DIR = $(PREFIX)/lib/cmdlopt/misc

programHelp_SOURCES := programHelp.c cmdloptHelp.c ../../debug.c


BUILD_NO_INSTALL := programOptions.h

programOptions.h: programHelp
	if ! ./$< -c > $@ ; then\
		rm -f $@; exit 1; fi


include $(topdir)/quickbuild.make
