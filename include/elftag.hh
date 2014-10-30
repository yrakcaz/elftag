#ifndef ELFTAG_HH
# define ELFTAG_HH

# include <iostream>
# include "header.hh"
# include "disass.hh"

/**
** @class Elftag
** @brief Principal class of the program.
*/
class Elftag
{
    public:
        /**
        ** @fn Elftag();
        ** @brief Default constructor.
        */
        Elftag();
        /**
        ** @fn Elftag(int argc, char **argv);
        ** @brief Principal constructor.
        ** @param argc Number of arguments passed to the program.
        ** @param argv Arguments passed to the program.
        */
        Elftag(int argc, char **argv);
        /**
        ** @fn ~Elftag();
        ** @brief Default destructor.
        */
        ~Elftag();

        /**
        ** @fn int run();
        ** @brief Principal function which execute the work to be done.
        ** @return Retuns the exit code.
        */
        int run();

    private:
        /**
        ** @fn void get_args();
        ** @brief Internal function which has to parse the command-line arguments.
        */
        void get_args();
        /**
        ** @fn void display_help(std::ostream& ostr);
        ** @brief Displays the help.
        ** @param ostr Output stream where to display the help.
        */
        void display_help(std::ostream& ostr);

    private:
        /**
        ** @var argc_
        ** @brief Number of arguments passed to the program.
        */
        int argc_;
        /**
        ** @var argv_
        ** @brief Arguments passed to the program.
        */
        char **argv_;
        /**
        ** @var header_
        ** @brief Object representing the header of the elf file.
        */
        Header header_;
        /**
        ** @var display_header_
        ** @brief If true, displays the elf header.
        */
        bool display_header_;
        /**
        ** @var display_sections_
        ** @brief If true, displays elf sections.
        */
        bool display_sections_;
        /**
        ** @var disass_
        ** @brief If true, disassemble the code.
        */
        bool disass_;
        /**
        ** @var help_
        ** @brief If true, displays the help.
        */
        bool help_;
};

#endif /* !ELFTAG_HH */
