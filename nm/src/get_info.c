/*
** EPITECH PROJECT, 2018
** my_nm
** File description:
** my_nm really main
*/

#include <string.h>
#include "nm.h"

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
    return (stok_data(&tmp));
}