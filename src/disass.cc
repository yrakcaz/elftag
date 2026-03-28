#include <disass.hh>

Disass::Disass(const Header& header)
    : header_(header)
{
}

void Disass::disass_text(const s_sectionheader& section) const
{
    s_elfheader* hdr = header_.header_get();
    unsigned char* text = reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(hdr) + section.offset);
    ud_t obj;
    ud_init(&obj);
    ud_set_input_buffer(&obj, text, section.size);
    ud_set_mode(&obj, 64);
    ud_set_syntax(&obj, UD_SYN_ATT);
    while (ud_disassemble(&obj))
        std::cout << "\t" << ud_insn_asm(&obj) << std::endl;
}

void Disass::print(bool disass) const
{
    s_elfheader* hdr = header_.header_get();
    s_sectionheader* stab = reinterpret_cast<s_sectionheader*>(reinterpret_cast<char*>(hdr) + hdr->shoff);
    s_sectionheader start = stab[hdr->shstrndx];
    char* strs = reinterpret_cast<char*>(hdr) + start.offset;
    s_sectionheader section;
    if (!disass)
        std::cout << "\033[31mELF64 SECTIONS DISPLAY :\033[0m" << std::endl;
    for (int i = 0; i < hdr->shnum; i++)
    {
        section = stab[i];
        if (!disass)
            std::cout << strs + section.name << std::endl;
        else if (disass && std::string(strs + section.name) == ".text")
            disass_text(section);
    }
}
