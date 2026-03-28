#ifndef ELFTAG_HH
# define ELFTAG_HH

# include <iostream>

# include "disass.hh"
# include "header.hh"

// Main program class: parses arguments and dispatches analysis operations.
class Elftag
{
    public:
        // Default constructor.
        Elftag();
        // Constructor taking command-line arguments.
        Elftag(int argc, char **argv);
        // Default destructor.
        ~Elftag();

        // Runs the program and returns the exit code.
        int run();

    private:
        // Parses command-line arguments and sets flags.
        void get_args();
        // Prints usage information to the given stream.
        void display_help(std::ostream& ostr);

    private:
        // Number of arguments.
        int argc_;
        // Argument values.
        char **argv_;
        // ELF header reader.
        Header header_;
        // Whether to display the ELF header.
        bool display_header_;
        // Whether to display ELF sections.
        bool display_sections_;
        // Whether to disassemble the .text section.
        bool disass_;
        // Whether to show help.
        bool help_;
};

#endif /* !ELFTAG_HH */
