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

void  Disass::disass_text(s_sectionheader* section)
{
    s_elfheader* hdr = header_.header_get();
    unsigned char* text = (unsigned char*)((char*)hdr + section->offset);
    ud_t obj;
    ud_init(&obj);
    ud_set_input_buffer(&obj, text, section->size);
    ud_set_mode(&obj, 64);
    ud_set_syntax(&obj, UD_SYN_INTEL);
    while (ud_disassemble(&obj))
        std::cout << "\t" << ud_insn_asm(&obj) << std::endl;
}

void Disass::print(bool disass)
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
        if (!disass)
            std::cout << strs + section.name << std::endl;
        else if (disass && std::string(strs + section.name) == ".text")
            disass_text(&section);
    }
}
