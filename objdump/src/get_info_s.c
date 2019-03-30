/*
** EPITECH PROJECT, 2018
** objdump.c
** File description:
** objdump
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "my_objdump.h"

char *get_name(t_infos_nm *list, char *strtab, int index)
{
    if (list->elf_32->e_ident[EI_CLASS] == ELFCLASS32)
        return (&(strtab)[list->shdr_32[index].sh_name]);
    else
        return (&(strtab)[list->shdr_64[index].sh_name]);
}

int get_size(t_infos_nm *list, int index)
{
    if (list->elf_32->e_ident[EI_CLASS] == ELFCLASS32)
        return (list->shdr_32[index].sh_size);
    else
        return (list->shdr_64[index].sh_size);
}

char *get_data(t_infos_nm *list, int index)
{
    if (list->elf_32->e_ident[EI_CLASS] == ELFCLASS32)
        return (list->buf + list->shdr_32[index].sh_offset);
    else
        return (list->buf + list->shdr_64[index].sh_offset);
}

char *get_str_data(t_infos_nm *list, char *strtab, int index)
{
    if (list->elf_32->e_ident[EI_CLASS] == ELFCLASS32)
        return (&(strtab)[list->shdr_32[index].sh_name]);
    else
        return (&(strtab)[list->shdr_64[index].sh_name]);
}

int get_section(t_infos_nm *list, int index)
{
    if (list->elf_32->e_ident[EI_CLASS] == ELFCLASS32)
        return (list->shdr_32[index].sh_addr);
    else
        return (list->shdr_64[index].sh_addr);
}