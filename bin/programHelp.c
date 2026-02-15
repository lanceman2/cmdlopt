
#include "../lib/cmdlopt/misc/cmdloptHelp.h"

#ifndef PROGRAM
#  define PROGRAM   "PROGRAM"
#endif



const char *usage =
"  Usage: " PROGRAM " OPTIONS\n"
"\n"
"  This program executes code after parsing each command line option"
" in the order that the options are given.\n"
"\n"
"  All command line options require an preceding option flag.  All"
" command line options with no arguments may be given in any of two"
" forms.  The two argument option forms below are equivalent:\n"
"\n"
"**"
"     ##-d\n"
"     ##--display\n"
"&&"
"\n"
"     -display is not a valid option.\n"
"\n"
"  All command line options with arguments may be given in any of three"
" forms.  The three option examples below are equivalent:\n"
"\n"
"**"
"     ##-b stdin\n"
"     ##--block stdin\n"
"     ##--block=stdin\n"
"&&"
"\n"
"\n"
"     -block stdin  and  -block=stdin  are not valid option arguments.\n"
"\n";



struct opts opts[] = {

/*----------------------------------------------------------------------*/
    { "--add-metadata-mk", 'M', "MK KEY ARG0 [ARGS...] MK",

        "Add metadata to be stored in the next super block that is "
        "generated via option --save-block or --save.\n"
        "The argument MK may be any string without a space that serves "
        "to delimit the start and the end of the argument strings to "
        "be saved in the metadata in the super block.  KEY can be used "
        "to access the metadata."
    },
/*----------------------------------------------------------------------*/
    { "--block", 'b', "FILENAME [NAME]",

        "Load block module with filename FILENAME.  An independent"
        " instance of the block will be created for each time any block"
        " is loaded.  For example:\n"
        "\n"
        "    --block fileOut out\n"
        "\n"
        "will load the \"fileOut\" block module and name it \"out\".  "
        "This will automatically generate a block name if one is not "
        "given in the command-line.  The block names must be unique "
        "for a given graph.\n"
        "\n"
        "If there has been no --graph option given yet in the command "
        "a graph will be automatically generated before loading the "
        "block into it.\n"
        "\n"
        "If that has been no --threads option given yet in the command "
        "a thread pool will be automatically generated before loading "
        "the block."
    },
/*----------------------------------------------------------------------*/
    { "--block-unload", 1234, "BLOCK_NAME0 [BLOCK_NAME1 ...]",

        "Remove blocks from the current graph."
    },
/*----------------------------------------------------------------------*/
    { "--block-help", 'B',  "FILENAME",

        "Print the block module help to stdout and then exit."
    },
/*----------------------------------------------------------------------*/
    { "--catch-sig", 'G',  "[SIG_NUM]",

        "If a SIG_NUM signal is sent to this programs catch it "
        "to stop waiting in --sleep.  This will only set the signal "
        "catcher for one use.  You can give this option again before "
        "the next --sleep."
    },
/*----------------------------------------------------------------------*/
    { "--connect", 'c', "BLOCK_A TYPE_A PORT_A BLOCK_B TYPE_B PORT_B",

        "Connect two block's ports.  We are connecting for *_A to *_B."
        "TODO: MORE TEXT HERE."
    },
/*----------------------------------------------------------------------*/
    { "--disconnect", 'I', "BLOCK PORT_TYPE PORT",

        "Disconnect a connection."
        "TODO: MORE TEXT HERE."
    },
/*----------------------------------------------------------------------*/
    { "--display", 'd', 0,

        "Display a graphviz dot graph of the stream graphs.\n\n" 
        "This requires that the program \"display\" is in the users "
        "PATH.  We recommend installing ImageMagick which installs "
        "a program called display which can read and display a graphviz"
        " dot file."
    },
/*----------------------------------------------------------------------*/
    { "--display-wait", 'D', 0,
        
        "Like --display but this waits for the display program to exit "
        "before going on to the next argument option."
    },
/*----------------------------------------------------------------------*/
    { "--help", 'h', 0,
        
        "Print help and then exit."
    },
/*----------------------------------------------------------------------*/
    { "--usage", 'u', 0,
        
        "Print usage and then exit."
    },
/*----------------------------------------------------------------------*/
    { 0,0,0,0 } // Null Terminator.
};

