#include "../include/header.hh"

Header::Header()
{
}

Header::Header(const char* path)
    : elf_file_(fopen(path, "r"))
    , header_(new s_elfheader)
{
    fread(header_, 400, 1, elf_file_);
}

Header::~Header()
{
}

void Header::display()
{
    std::cout << header_->identifier << std::endl;
}
