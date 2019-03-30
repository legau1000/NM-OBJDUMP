/*
** EPITECH PROJECT, 2018
** my_nm
** File description:
** Sort List
*/

#include <string.h>
#include "nm.h"

static char cast_min(char c)
{
    if (c <= 'Z' && c >= 'A')
        return (c + 32);
    return (c);
}

static int execp_bss(char *s1, char *s2)
{
    if (strcmp(s1, "data_start") == 0 && strcmp(s2, "__data_start") == 0)
        return (1);
    return (0);
}

static int manual_comp(char *s1, char *s2, int index_one, int index_two)
{
    if (!s1 || !s2)
        return (0);
    while (s1 && s2 && s1[index_one] && s2[index_two]) {
        while (s1[index_one] == '_')
            index_one++;
        while (s2[index_two] == '_')
            index_two++;
        if (cast_min(s1[index_one]) > cast_min(s2[index_two]))
            return (1);
        else if (cast_min(s1[index_one]) < cast_min(s2[index_two]))
            return (-1);
        index_one++;
        index_two++;
    }
    if (s1[index_one])
        return (1);
    if (s2[index_two])
        return (-1);
    return (execp_bss(s1, s2));
}

static int tri_list(t_infos_sys *tps)
{
    t_infos_sys *tmp = tps;
    int ret = 0;

    while (tmp && tmp->next) {
        if (manual_comp(tmp->name, tmp->next->name, 0, 0) > 0) {
            my_swap(tmp, tmp->next);
            ret = 1;
        }
        tmp = tmp->next;
    }
    return (ret);
}

void sort_list(t_infos_nm **list)
{
    t_infos_sys *tmp = (*list)->data;

    while (tri_list(tmp) == 1);
}