/*
** EPITECH PROJECT, 2018
** my_nm
** File description:
** add maillon really main
*/

#include <stdlib.h>
#include "nm.h"

static int add_first(t_infos_nm **list, char *path)
{
    t_infos_nm *new = malloc(sizeof(t_infos_nm));

    if (!new)
        return (84);
    new->fd = 0;
    new->name = path;
    new->err = NOTHING;
    new->elf = NULL;
    new->shdr = NULL;
    new->strtab = NULL;
    new->data = NULL;
    new->next = NULL;
    new->previous = NULL;
    (*list) = new;
    return (0);
}

static int add_more(t_infos_nm **list, char *path)
{
    t_infos_nm *tmp = (*list);
    t_infos_nm *new = malloc(sizeof(t_infos_nm));

    if (!new)
        return (84);
    while (tmp->next)
        tmp = tmp->next;
    new->fd = 0;
    new->name = path;
    new->err = NOTHING;
    new->elf = NULL;
    new->shdr = NULL;
    new->strtab = NULL;
    new->data = NULL;
    new->next = NULL;
    new->previous = tmp;
    tmp->next = new;
    return (0);
}

int add_maillon_to_list(t_infos_nm **list, char *path)
{
    if (!(*list))
        return (add_first(list, path));
    else
        return (add_more(list, path));
    return (0);
}