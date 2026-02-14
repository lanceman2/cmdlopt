#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "../lib/debug.h"

#include "../lib/cmdlopt/misc/programOptions.h"

#include "cmdlopt.h"


// How many additional arguments are given past the i-th argv[i]
// until hitting the next - or -- option argument argv[ ? ].
// We have no need to look at argv[0] which is the program.
//
// Example:
//   argc = 11
//   argv[ 0   1   2     3     4    5            6   7   8  9  10 11
//  $ program -i --block stdin in --configure-mk MK foo bar 3 MK  -g
//
// Note: programs that can take a starting "-" in an argument option
// need code to be added to do that case.
//
//   i=1  returns 0
//   i=2  returns 2
//   i=5  returns 5
//
static inline
int GetNumArgs(int i, int argc, const char * const *argv,
        const char *command) {
    DASSERT(i);
    DASSERT(argv);
    // We need command to do special cases for command line options that
    // can have an argument like "-99" with a starting minus sign; and
    // -99 is an argument and not a new starting option argument.
    DASSERT(command);

    int numArgs = 0;

    const char * const *arg = argv + i + 1;
    // argv is null terminated.
    for(; *arg && arg[0][0] != '-'; ++arg)
        ++numArgs;
    return numArgs;
}

static void catcher(int signum) {
    ASSERT(0, "Caught signal %d\n", signum);
}

// c is the command to switch on.
//
// command is the command as a long option string like "help" for --help.
//
// argc is the number of arg strings and argv[] is the strings.
//
int RunCommand(int c, int argc, const char *command,
        const char * const * argv, bool *exitOnError) {
    DASSERT(argc >= 1);
    DASSERT(command);
    DASSERT(c);
    DASSERT(argv);
    DASSERT(argv[0]);
    DASSERT(exitOnError);

#ifdef DEBUG
    fprintf(stderr, "Got command line option: \"%s[%c:%d]\":  ", command, c, c);
    for(int i=0; i<argc; ++i)
        fprintf(stderr, " %s", argv[i]);
    fprintf(stderr, "\n");
#endif

    switch(c) {

        case HELP:
            help(); // Does not return.
        case USAGE:
            usage(); // Does not return.

        default:
    }

    return 0; // 0 --> success
}


int main(int argc, const char * const *argv) {

    // Hang the program for debugging, if we segfault.
    ASSERT(signal(SIGSEGV, catcher) != SIG_ERR);
    ASSERT(signal(SIGABRT, catcher) != SIG_ERR);

    int exitStatus = 0;
    int i = 1;

    while(i < argc) {

        const char *command = 0;
        bool exitOnError = 1;

        //
        // Returns &command as the long opt from in options[].
        // Returns the short opt as an int:
        //
        int c = getOpt(argc, argv, i, options, &command);

        if(!c) {
            fprintf(stderr, "Error: unknown option at argv[%d]: %s\n",
                    i, argv[i]);
            if(exitOnError) {
                exitStatus = 1;
                break;
            }
            ++i;
            continue;
        }

        // GetNumArgs() is more particular to this program
        // than getOpt(), so that's why getOpt() does not set numArgs.
        //
        // Now we know that we have an option argument from the struct
        // opts option[] thingy, though more particular testing will be
        // done before we can run part of this program.
        //
        int numArgs = GetNumArgs(i, argc, argv, command);

        if((exitStatus = RunCommand(c, numArgs+1,
                        command, argv + i, &exitOnError))) {
            if(exitOnError)
                break;
            // else keep going.
        }

        ++i;
        i += numArgs;
    }

    return exitStatus;
}
