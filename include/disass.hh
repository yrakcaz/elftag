#ifndef DISASS_HH
# define DISASS_HH

# include "header.hh"
# include "udis86.h"

/**
** @struct sectionheader
** @brief Structure representing the header section of elf format.
*/
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

/**
** @class Disass
** @brief Class which has to disassemble elf into x86.
*/
class Disass
{
    public:
        /**
        ** @fn Disass();
        ** @brief Default constructor.
        */
        Disass();
        /**
        ** @fn Disass(Header& header);
        ** @brief Secon constructor, which needs a Header.
        ** @param header Object representing the Header of the elf file.
        */
        Disass(Header& header);
        /**
        ** @fn ~Disass();
        ** @brief Default destructor.
        */
        ~Disass();

        /**
        ** @fn void print(bool disass);
        ** @brief Final function which prints the x86 output.
        ** @param disass If disass is true, then print will disass the code, else it will juste display sections of the elf file.
        */
        void print(bool disass);

    private:
        /**
        ** @fn void disass_text(s_sectionheader* section);
        ** @brief Internal function which juste disassemble a .text section.
        ** @param section Pointer on the section header structure.
        */
        void disass_text(s_sectionheader* section);

    private:
        /**
        ** @var header_
        ** @brief Object header attribute.
        */
        Header header_;
};

#endif /* !DISASS_HH */
