

extern const char *usage;

struct opts {
  char *long_op;
  int short_op;
  char *arg;    // like  "--option ARG"  in the help spew
  char *description;
};

extern struct opts opts[];

