#include "../include/header.hh"

int main(int argc, char** argv)
{
    if (argc > 1)
    {
        Header header(argv[1]);
        header.display_raw();
        return 0;
    }
    else
        return 1;
}
