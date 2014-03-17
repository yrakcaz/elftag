#include "../include/elftag.hh"

int main(int argc, char** argv)
{
    Elftag elftag(argc, argv);
    return elftag.run();
}
