/*
** EPITECH PROJECT, 2018
** my_nm
** File description:
** Catch Data really main
*/

#include <stdlib.h>
#include <stdio.h>
#include "nm.h"

static int add_list(t_infos_nm **list, Elf64_Sym *tps)
{
    t_infos_sys *new = malloc(sizeof(t_infos_sys));
    t_infos_sys *tmp = (*list)->data;

    if (!new)
        return (84);
    new->value = tps->st_value;
    new->type = get_type((*list), tps, tps->st_info);
    new->name = &((*list)->strtab[tps->st_name]);
    new->sys = tps;
    new->next = NULL;
    new->previous = NULL;
    if (!(*list)->data) {
        (*list)->data = new;
    } else {
        while (tmp && tmp->next)
            tmp = tmp->next;
        tmp->next = new;
        new->previous = tmp;
    }
    return (0);
}

static void stock_sys_data(t_infos_nm **list, Elf64_Shdr *shdr)
{
    char *buff = (char*)(*list)->buf + (*list)->shdr[shdr->sh_link].sh_offset;
    Elf64_Sym	*tmp = NULL;
    Elf64_Sym	*end = NULL;

    tmp = (Elf64_Sym*)((char *)(*list)->buf + shdr->sh_offset);
    end = (Elf64_Sym*)((char *)(*list)->buf + shdr->sh_offset + shdr->sh_size);
    (*list)->strtab = buff;
    while (tmp != end) {
        if (tmp->st_name && ((tmp->st_info) != STT_FILE))
            add_list(list, tmp);
        tmp++;
    }
}

int stok_data(t_infos_nm **list)
{
    int index = 0;

    while (index < (*list)->elf->e_shnum) {
        if ((*list)->shdr[index].sh_type == SHT_SYMTAB) {
            stock_sys_data(list, &(*list)->shdr[index]);
            sort_list(list);
            return (0);
        }
        index++;
    }
    (*list)->err = OTHER;
    printf("error\n");
    return (1);
}