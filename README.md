# cmdlopt

Command line options for C code programs using a separate small helper
program.  Keeping command-line program options consistent for programs
with hundreds of command-line options; and not bloating the size of
the program.

This introduces a method to keep the command line options with the --help
descriptions together in one place in a C compiled helper program that is
kept separate from the program that it is documenting.  The helper program
is also used to generate command-line options code for the program it is
documenting.  This makes it possible to keep the source command-line
option flags in one file; forcing the options to stay consistent; while at
the same time not inserting large strings into program that we wish to
document.

The helper program can by used to generate man and HTML documentation;
which forces the options to stay consistent with all this documentation.
There will be only one place where the option (for example) "--block" is
defined; so the developer can change this string in one file, causing it
to change in all dependent files that the helper program can generate.

The helper program generates code, documentation, and is executed by the
program it serves to generate the ever known "--help" option.

The helper binary is installed in
${PREFIX}/lib/${PROJECT}/misc/${PROJECT}Help and the program it supports
is in ${PREFIX}/bin/PROGRAM.

The files in the software project are intended to be copied to directories
in the source code of other software projects.


### ./bootstrap

Run
~~~
./bootstrap
~~~

That will download some files.  No other build step will download files
like this.

### ./configure

Run

~~~
./configure
~~~

That will generate a very small make file, "config.make".  You can edit
the generated file to change your installation PREFIX, and other
options.


### make

Run

~~~
make
~~~

### make install

Run

~~~
make install
~~~

