#include "../include/disass.hh"

Disass::Disass()
{
}

Disass::Disass(Header& header)
    : header_(header)
{
}

Disass::~Disass()
{
}

void Disass::print_sections()
{
    s_elfheader* hdr = header_.header_get();
    s_sectionheader* stab = (s_sectionheader*)((char*)hdr + hdr->shoff);
    s_sectionheader start = stab[hdr->shstrndx];
    char* strs = (char*)((char*)hdr + start.offset);
    s_sectionheader section;
    std::cout << "\033[31mELF64 SECTIONS DISPLAY :\033[0m" << std::endl;
    for (int i = 0; i < hdr->shnum; i++)
    {
        section = stab[i];
        std::cout << strs + section.name << std::endl;
    }
}
