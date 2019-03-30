/*
** EPITECH PROJECT, 2018
** my_nm
** File description:
** My Swap
*/

#include "nm.h"

void my_swap(t_infos_sys *tmp, t_infos_sys *tmpnext)
{
    t_infos_sys stock = *tmpnext;

    tmpnext->name = tmp->name;
    tmpnext->sys = tmp->sys;
    tmpnext->type = tmp->type;
    tmpnext->value = tmp->value;
    tmp->name = stock.name;
    tmp->sys = stock.sys;
    tmp->type = stock.type;
    tmp->value = stock.value;
}