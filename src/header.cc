#include <header.hh>

Header::Header()
{
    init_tables();
}

Header::Header(const char* path)
    : elf_file_(open(path, O_RDONLY))
{
    struct stat sb;
    stat(path, &sb);
    size_ = sb.st_size;
    header_ = reinterpret_cast<s_elfheader*>(mmap(0, size_, PROT_READ, MAP_PRIVATE, elf_file_, 0));
    init_tables();
}

Header::~Header()
{
    if (header_ && header_ != MAP_FAILED)
        munmap(header_, size_);
    if (elf_file_ >= 0)
        close(elf_file_);
}

void Header::init_tables()
{
    isa_[2]   = "SPARC";
    isa_[3]   = "x86";
    isa_[8]   = "MIPS";
    isa_[20]  = "PowerPC";
    isa_[40]  = "ARM";
    isa_[50]  = "IA-64";
    isa_[62]  = "x86-64";
    isa_[183] = "AArch64";
    type_[1]  = "relocatable file";
    type_[2]  = "executable file";
    type_[3]  = "shared file";
    type_[4]  = "core file";
}

void Header::header_set(const char* path)
{
    struct stat sb;
    stat(path, &sb);
    size_ = sb.st_size;
    elf_file_ = open(path, O_RDONLY);
    header_ = reinterpret_cast<s_elfheader*>(mmap(0, size_, PROT_READ, MAP_PRIVATE, elf_file_, 0));
}

s_elfheader* Header::header_get() const
{
    return header_;
}

void Header::display()
{
    std::cout << "\n\033[31mRAW ELF64 HEADER DISPLAY :\033[0m" << std::endl << std::endl;
    std::cout << "Identifier:\t" << *reinterpret_cast<const int*>(header_->identifier) << std::endl;
    std::cout << "Type:\t\t" << type_.at(header_->type) << std::endl;
    std::cout << "Machine:\t" << isa_.at(header_->machine) << std::endl;
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
