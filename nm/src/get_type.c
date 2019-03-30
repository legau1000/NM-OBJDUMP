/*
** EPITECH PROJECT, 2018
** my_nm
** File description:
** Catch Data really main
*/

#include <stdlib.h>
#include <stdio.h>
#include "nm.h"

static char min_val(unsigned char st_info, char letter)
{
    if (ELF64_ST_BIND(st_info) == STB_LOCAL && letter != '?')
        letter += 32;
    return (letter);
}

static char thrid_get_type(Elf64_Shdr infos)
{
    char letter = '?';

    if (infos.sh_type == SHT_NOBITS)
        letter = 'B';
    else if (infos.sh_type == SHT_DYNAMIC)
        letter = 'D';
    if (letter == '?')
        letter = 'T';
    return (letter);
}

static char second_get_type(Elf64_Shdr infos)
{
    char letter = '?';

    if (infos.sh_type == SHT_PROGBITS &&
    infos.sh_flags == (SHF_ALLOC | SHF_WRITE))
        letter = 'D';
    else if (infos.sh_type == SHT_PROGBITS && infos.sh_flags == SHF_ALLOC)
        letter = 'R';
    else
        letter = thrid_get_type(infos);
    return (letter);
}

static char first_get(Elf64_Sym *tps, unsigned char st_info)
{
    char letter = '?';

    if (ELF64_ST_BIND(st_info) == STB_WEAK) {
        letter = 'W';
        if (tps->st_shndx == SHN_UNDEF)
            letter = 'w';
    } else if (tps->st_shndx == STT_NOTYPE)
        letter = 'U';
    return (letter);
}

char get_type(t_infos_nm *list, Elf64_Sym *tps, unsigned char st_info)
{
    char letter = first_get(tps, st_info);

    if (letter != '?')
        return (min_val(st_info, letter));
    if (tps->st_shndx == STT_SPARC_REGISTER)
        letter = 'T';
    else if (tps->st_shndx == STT_HIPROC)
        letter = 'R';
    else
        return (min_val(st_info, second_get_type(list->shdr[tps->st_shndx])));
    return (min_val(st_info, letter));
}