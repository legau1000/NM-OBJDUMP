/*
** EPITECH PROJECT, 2018
** init_list.c
** File description:
** init_list
*/

#include <stdlib.h>
#include "my_objdump.h"

int get_info(t_infos_nm **list, char *path)
{
    t_infos_nm *tmp = NULL;

    if (add_maillon_to_list(list, path) == 84)
        return (84);
    tmp = (*list);
    while (tmp->next)
        tmp = tmp->next;
    if (open_file(&tmp) == 84)
        return (1);
    if (map_file(&tmp) != 0)
        return (1);
    return (0);
}
