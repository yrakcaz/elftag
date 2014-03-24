#ifndef HEADER_HH
# define HEADER_HH

# include <stdio.h>
# include <stdlib.h>
# include <iostream>
# include <map>
# include <sys/stat.h>
# include <sys/mman.h>
# include <unistd.h>
# include <fcntl.h>

// Structure for mapping the ELF64 header
typedef struct elfheader
{
    unsigned char identifier[16];
    uint16_t type;
    uint16_t machine;
    uint32_t version;
    uint64_t entry;
    uint64_t phoff;
    uint64_t shoff;
    uint32_t flags;
    uint16_t ehsize;
    uint16_t phentsize;
    uint16_t phnum;
    uint16_t shentsize;
    uint16_t shnum;
    uint16_t shstrndx;
} s_elfheader;

// Class which represent this header
class Header
{
    public:
        Header();
        Header(const char* path);
        ~Header();

        void header_set(const char* path);
        s_elfheader* header_get();

        void display();

    private:
        int elf_file_;
        s_elfheader* header_;
        const char** abi_;
        const char** isa_;
        const char** type_;
        size_t size_;
};

#endif /* !HEADER_HH */
