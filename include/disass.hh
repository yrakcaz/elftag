#ifndef DISASS_HH
# define DISASS_HH

# include "udis86.h"

# include "header.hh"

// ELF64 section header layout.
typedef struct sectionheader
{
    uint32_t name;
    uint32_t type;
    uint64_t flags;
    uint64_t addr;
    uint64_t offset;
    uint64_t size;
    uint32_t link;
    uint32_t info;
    uint64_t addralign;
    uint64_t entsize;
} s_sectionheader;

// Disassembles x86-64 ELF binaries using udis86 (AT&T syntax).
class Disass
{
    public:
        // Constructs with an ELF header.
        Disass(const Header& header);
        // Default destructor.
        ~Disass() = default;

        // Lists sections or disassembles .text depending on the disass flag.
        void print(bool disass) const;

    private:
        // Disassembles the .text section using udis86.
        void disass_text(const s_sectionheader& section) const;

    private:
        // ELF header of the target binary.
        const Header& header_;
};

#endif /* !DISASS_HH */
