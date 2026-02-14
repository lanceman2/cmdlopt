
// This does not return.
extern void help(void);

// This does not return.
extern void usage(void);

// See comments in cmdlopt.c
//
extern int getOpt(int argc, const char * const *argv, int i,
        const struct opts *options/*array of options*/,
        const char **command);

