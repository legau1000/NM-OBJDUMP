/*
** EPITECH PROJECT, 2018
** my_nm
** File description:
** my_nm really main
*/

#include <stdio.h>
#include <stdlib.h>
#include "nm.h"

static void free_data(t_infos_nm *list)
{
    t_infos_sys *tmp = list->data;

    while (list->data) {
        tmp = tmp->next;
        free(list->data);
        list->data = tmp;
    }
}

void free_list_and_close(t_infos_nm *list)
{
    t_infos_nm *tmp = list;

    while (list) {
        tmp = tmp->next;
        free_data(list);
        close_file(list);
        free(list);
        list = tmp;
    }
}