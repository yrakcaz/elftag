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

void Header::display_raw()
{
    std::cout << "\n\033[31mRAW ELF64 HEADER DISPLAY :\033[0m" << std::endl << std::endl;
    std::cout << "Magic:\t        " << header_->identifier << std::endl;
    std::cout << "Type:\t\t" << header_->type << std::endl;
    std::cout << "Machine:\t" << header_->machine << std::endl;
    std::cout << "Version:\t" << header_->version << std::endl;
    std::cout << "Entry:\t\t" << header_->entry << std::endl;
    std::cout << "Phoff:\t\t" << header_->phoff << std::endl;
    std::cout << "Shoff:\t\t" << header_->shoff << std::endl;
    std::cout << "Flags:\t\t" << header_->flags << std::endl;
    std::cout << "Ehsize:\t\t" << header_->ehsize << std::endl;
    std::cout << "Phentsize:\t" << header_->phentsize << std::endl;
    std::cout << "Phnum:\t\t" << header_->phnum << std::endl;
    std::cout << "Shentsize:\t" << header_->shentsize << std::endl;
    std::cout << "Shnum:\t\t" << header_->shnum << std::endl;
    std::cout << "Shstrndx:\t" << header_->shstrndx << std::endl << std::endl;;
}
