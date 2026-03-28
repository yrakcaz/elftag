#ifndef HEADER_HH
# define HEADER_HH

# include <cstdint>
# include <iostream>
# include <string>
# include <unordered_map>
# include <fcntl.h>
# include <sys/mman.h>
# include <sys/stat.h>
# include <unistd.h>

// ELF64 header layout, mapped directly from the binary via mmap.
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

// Reads and displays an ELF64 header from a file.
class Header
{
    public:
        // Default constructor.
        Header();
        // Constructs from an ELF file at the given path.
        Header(const char* path);
        // Default destructor.
        ~Header();

        // Maps the ELF header from the file at the given path.
        void header_set(const char* path);
        // Returns the mapped ELF header.
        s_elfheader* header_get() const;
        // Prints the ELF header fields to stdout.
        void display();

    private:
        // Populates isa_ and type_ lookup tables.
        void init_tables();

    private:
        // File descriptor for the ELF file.
        int elf_file_ = -1;
        // Pointer to the mapped ELF header.
        s_elfheader* header_ = nullptr;
        // ISA name lookup table indexed by e_machine.
        std::unordered_map<uint16_t, std::string> isa_;
        // ELF type name lookup table indexed by e_type.
        std::unordered_map<uint16_t, std::string> type_;
        // Size of the mapped file.
        size_t size_ = 0;
};

#endif /* !HEADER_HH */
