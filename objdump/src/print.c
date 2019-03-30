/*
** EPITECH PROJECT, 2018
** objdump.c
** File description:
** objdump
*/

#include <stdio.h>
#include "my_objdump.h"
#include "def.h"

static char *get_flag(t_infos_nm *list)
{
    int index = 0;
    int macro[] = {ET_REL, ET_EXEC, ET_DYN, ET_CORE, 84};
    char *flag[] = {"0x00000011:\nHAS_RELOC, HAS_SYMS\n",
                    "0x00000112:\nEXEC_P, HAS_SYMS, D_PAGED\n",
                    "0x00000150:\nHAS_SYMS, DYNAMIC, D_PAGED\n",
                    "Core\n",
                    "ERROR\n"};

    while (macro[index] != 84) {
        if (macro[index] == list->elf_64->e_type)
            return (flag[index]);
        index++;
    }
    return (NULL);
}

static char *get_archi(t_infos_nm *list)
{
    if (list->elf_64->e_machine == EM_386)
        return ("i386");
    else if (list->elf_64->e_machine == EM_X86_64)
        return ("i386:x86-64");
    else
        return ("None");
}

static char *get_format(t_infos_nm *list)
{
    if (list->elf_64->e_machine == EM_386)
        return ("elf32-i386");
    else if (list->elf_64->e_machine == EM_X86_64)
        return ("elf64-x86-64");
    else
        return ("None");
}

static void pint_arg_f(t_infos_nm *list)
{
    if (list->err == NOTHING) {
        printf("%s:     file format %s\n", list->name, get_format(list));
        printf("architecture: %s, flags %s", get_archi(list), get_flag(list));
        if (list->elf_32->e_ident[EI_CLASS] == ELFCLASS32)
            printf("start address 0x%08x\n\n", list->elf_32->e_entry);
        else
            printf("start address 0x%016lx\n\n", list->elf_64->e_entry);
    }
}

void print_value(t_infos_nm *list, UNUSED t_arg *arg)
{
    t_infos_nm *tmp = list;

    while (tmp) {
        if (tmp->err != NOTHING)
            print_err(tmp);
        else {
            printf("\n");
            pint_arg_f(tmp);
            pint_arg_s(tmp, 0);
        }
        tmp = tmp->next;
    }
}