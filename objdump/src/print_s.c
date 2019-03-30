/*
** EPITECH PROJECT, 2018
** objdump.c
** File description:
** objdump
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "my_objdump.h"
#include "def.h"

static int detect_error(char *str)
{
    if (!str || !str[0])
        return (0);
    if (strcmp(str, ".shstrtab") == 0)
        return (0);
    if (strcmp(str, ".symtab") == 0)
        return (0);
    if (strcmp(str, ".strtab") == 0)
        return (0);
    if (strcmp(str, ".bss") == 0)
        return (0);
    return (1);
}

static void print_dt(int index, int limit, char *data)
{
    printf(" ");
    while (index < limit) {
        if (!isgraph(data[index]) && data[index] != ' ')
            printf(".");
        else
            printf("%c", data[index]);
        index++;
    }
    while (index % 16 != 0) {
        index++;
        printf(" ");
    }
    printf("\n");
}

static void print_last_dt(int index, int size, char *data)
{
    int stock = size;

    if (stock % 4 != 0)
        printf(" ");
    while (stock % 16 != 0) {
        printf("  ");
        if (stock % 4 == 0)
            printf(" ");
        stock++;
    }
    if (size % 16 == 15)
        index = size -(size % 16);
    print_dt(index, size, data);
}

static void print_data(char *data, int size, t_infos_nm *list, int idx)
{
    int index = 1;
    int nb_pri = printf(" %04x ", get_section(list, idx));

    while (index <= size) {
        if (data[index - 1] < 0)
            nb_pri += unhexax(data[index - 1]);
        else
            nb_pri += printf("%02x", data[index - 1]);
        if (index % 4 == 0 && index != 1)
            nb_pri += printf(" ");
        if (index % 16 == 0 && index != 1) {
            print_dt(index - 16, index, data);
            nb_pri = 0;
            print_section(index, size, list, idx);
        }
        index++;
    }
    if (nb_pri != 0)
        print_last_dt(index - (index % 16), size, data);
}

void pint_arg_s(t_infos_nm *list, int index)
{
    char *data = NULL;
    char *strt = NULL;
    int limit = 0;

    if (list->elf_32->e_ident[EI_CLASS] == ELFCLASS32) {
        strt = (list->buf + list->shdr_32[list->elf_32->e_shstrndx].sh_offset);
        limit = list->elf_32->e_shnum;
    } else {
        strt = (list->buf + list->shdr_64[list->elf_64->e_shstrndx].sh_offset);
        limit = list->elf_64->e_shnum;
    }
    while (index < limit) {
        if (detect_error(get_str_data(list, strt, index)) == 1) {
            data = get_data(list, index);
            printf("Contents of section %s:\n", get_name(list, strt, index));
            print_data(data, get_size(list, index), list, index);
        }
        index++;
    }
}