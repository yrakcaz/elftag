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

/**
** @struct elfheader
** @brief Structure where to map the ELF64 header.
*/
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

/**
** @class Header
** @brief Class which represents the elf header.
*/
class Header
{
    public:
        /**
        ** @fn Header();
        ** @brief Default constructor.
        */
        Header();
        /**
        ** @fn Header(const char* path);
        ** @brief Principal constructor.
        ** @param path Path to the elf file.
        */
        Header(const char* path);
        /**
        ** @fn ~Header();
        ** @brief Default destructor.
        */
        ~Header();

        /**
        ** @fn void header_set(const char* path);
        ** @brief Setter for the header_ attribute.
        ** @param path Path to an elf file to map.
        */
        void header_set(const char* path);
        /**
        ** @fn s_elfheader* header_get();
        ** @brief Getter for the header_ attribute.
        ** @return Returns the header_ attribute.
        */
        s_elfheader* header_get();

        /**
        ** @fn void display();
        ** @brief Displays the elf header.
        */
        void display();

    private:
        /**
        ** @var elf_file_
        ** @brief File descriptor for the elf file.
        */
        int elf_file_;
        /**
        ** @var header_
        ** @brief Pointer to the section header structure.
        */
        s_elfheader* header_;
        /**
        ** @var isa_
        ** @brief Array indexing the different system architectures.
        */
        const char** isa_;
        /**
        ** @var type_
        ** @brief Array indexing the different elf types.
        */
        const char** type_;
        /**
        ** @var size_
        ** @brief Size of the elf file.
        */
        size_t size_;
};

#endif /* !HEADER_HH */
