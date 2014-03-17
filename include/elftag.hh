#ifndef ELFTAG_HH
# define ELFTAG_HH

# include <iostream>
# include "header.hh"

class Elftag
{
    public:
        Elftag();
        Elftag(int argc, char **argv);
        ~Elftag();

        int run();

    private:
        void get_args();
        void display_help(std::ostream& ostr);

    private:
        int argc_;
        char **argv_;
        Header header_;
        bool display_header_;
        bool help_;
};

#endif /* !ELFTAG_HH */
