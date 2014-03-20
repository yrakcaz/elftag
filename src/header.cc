#include "../include/header.hh"

Header::Header()
    : header_(new s_elfheader)
    , abi_(new const char*[13])
    , isa_(new const char*[200])
    , type_(new const char*[5])
{
    abi_[0] = "System V";
    abi_[1] = "HP-UX";
    abi_[2] = "NetBSD";
    abi_[3] = "Linux";
    abi_[6] = "OpenBSD";
    abi_[7] = "AIX";
    abi_[8] = "IRIX";
    abi_[9] = "FreeBSD";
    isa_[2] = "SPARC";
    isa_[3] = "x86";
    isa_[8] = "MIPS";
    isa_[20] = "PowerPC";
    isa_[40] = "ARM";
    isa_[50] = "IA-64";
    isa_[62] = "x86-64";
    isa_[183] = "AArch64";
    type_[1] = "relocatable file";
    type_[2] = "executable file";
    type_[3] = "shared file";
    type_[4] = "core file";
}

Header::Header(const char* path)
    : elf_file_(fopen(path, "r"))
    , header_(new s_elfheader)
    , abi_(new const char*[13])
    , isa_(new const char*[200])
    , type_(new const char*[5])
{
    fread(header_, 400, 1, elf_file_);
    abi_[0] = "System V";
    abi_[1] = "HP-UX";
    abi_[2] = "NetBSD";
    abi_[3] = "Linux";
    abi_[6] = "OpenBSD";
    abi_[7] = "AIX";
    abi_[8] = "IRIX";
    abi_[9] = "FreeBSD";
    isa_[2] = "SPARC";
    isa_[3] = "x86";
    isa_[8] = "MIPS";
    isa_[20] = "PowerPC";
    isa_[40] = "ARM";
    isa_[50] = "IA-64";
    isa_[62] = "x86-64";
    isa_[183] = "AArch64";
    type_[1] = "relocatable file";
    type_[2] = "executable file";
    type_[3] = "shared file";
    type_[4] = "core file";
}

Header::~Header()
{
}

void Header::header_set(const char* path)
{
    elf_file_ = fopen(path, "r");
    fread(header_, 400, 1, elf_file_);
}

void Header::display()
{
    std::cout << "\n\033[31mRAW ELF64 HEADER DISPLAY :\033[0m" << std::endl << std::endl;
    std::cout << "Identifier:\t" << /*abi_[*/*(int *)header_->identifier/*[7]]*/ << std::endl;
    std::cout << "Type:\t\t" << type_[header_->type] << std::endl;
    std::cout << "Machine:\t" << isa_[header_->machine] << std::endl;
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
