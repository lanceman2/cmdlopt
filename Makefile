
SUBDIRS :=\
 lib/cmdlopt/misc\
 bin


ifneq ($(wildcard quickbuild.make),quickbuild.make)
$(error "First run './bootstrap'")
endif
ifneq ($(wildcard config.make),config.make)
$(error "Now run './configure'")
endif



include quickbuild.make
