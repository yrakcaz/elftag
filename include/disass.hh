#ifndef DISASS_HH
# define DISASS_HH

# include "header.hh"

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

class Disass
{
    public:
        Disass();
        Disass(Header& header);
        ~Disass();

        void print_sections();

    private:
        Header header_;
};

#endif /* !DISASS_HH */
