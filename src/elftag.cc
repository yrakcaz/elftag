#include "../include/elftag.hh"

Elftag::Elftag()
{
}

Elftag::Elftag(int argc, char **argv)
    : argc_(argc)
    , argv_(argv)
    , display_header_(false)
    , display_sections_(false)
    , help_(false)
{
}

Elftag::~Elftag()
{
}

void Elftag::get_args()
{
    for (int i = 1; i < argc_; i++)
    {
        std::string str(argv_[i]);
        if (str == "-d" || str == "--display-header")
            display_header_ = true;
        else if (str == "-s" || str == "--display-sections")
            display_sections_ = true;
        else if (str == "-h" || str == "--help")
            help_ = true;
    }
}

void Elftag::display_help(std::ostream& ostr)
{
    ostr << "Usage:\telftag [options] [file]" << std::endl;
    ostr << "Options:\t-d, --display-header\tDisplays elf64 header." << std::endl;
    ostr << "        \t-s, --display-sections\tDisplays elf64 sections." << std::endl;
    ostr << "        \t-h, --help\t\tDisplays this help." << std::endl;
}

int Elftag::run()
{
    get_args();
    if (help_)
        display_help(std::cout);
    else if (argc_ > 2)
    {
        header_.header_set(argv_[argc_ - 1]);
        if (display_header_ || display_sections_)
        {
            if (display_header_)
                header_.display();
            if (display_sections_)
            {
                Disass disass(header_);
                disass.print_sections();
            }
        }
        else
        {
            display_help(std::cerr);
            return 1;
        }
    }
    else
    {
        display_help(std::cerr);
        return 1;
    }
    return 0;
}
