#ifndef HEADER_HH
# define HEADER_HH

# include <stdio.h>
# include <iostream>

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

        void display();

    private:
        FILE* elf_file_;
        s_elfheader* header_;
};

#endif /* !HEADER_HH */
