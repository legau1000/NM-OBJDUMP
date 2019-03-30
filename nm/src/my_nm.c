/*
** EPITECH PROJECT, 2018
** my_nm
** File description:
** my_nm really main
*/

#include <stdio.h>
#include <stdlib.h>
#include "nm.h"

static void print_error(t_infos_nm *list)
{
    if (list->err == OPEN)
        dprintf(2, "nm: '%s': No such file\n", list->name);
    if (list->err == FILES)
        dprintf(2, "nm: %s: File format not recognized\n", list->name);
    if (list->err == MAP)
        perror("mmap");
    if (list->err == OTHER)
        dprintf(2, "nm: %s: An unknown error have been find\n", list->name);
}

static void print_type(t_infos_sys *tmp_data)
{
    if (tmp_data->type != 'U' && tmp_data->type != 'w')
        printf("%016x ", tmp_data->value);
    else
        printf("                 ");
}

static void print_list(t_infos_nm *list)
{
    t_infos_nm *tmp = list;
    t_infos_sys *tmp_data = NULL;

    while (tmp) {
        if (tmp->err != NOTHING)
            print_error(tmp);
        else if (list && list->next)
            printf("\n%s:\n", tmp->name);
        tmp_data = tmp->data;
        while (tmp_data) {
            print_type(tmp_data);
            printf("%c ", tmp_data->type);
            printf("%s\n", &(list->strtab[tmp_data->sys->st_name]));
            tmp_data = tmp_data->next;
        }
        tmp = tmp->next;
    }
}

int my_nm(int ac, char **av)
{
    int index = 1;
    int err = 0;
    t_infos_nm *list = NULL;

    if (ac < 2)
        err = get_info(&list, "a.out");
    else {
        while (ac != index) {
            err = err + get_info(&list, av[index]);
            index++;
        }
    }
    print_list(list);
    free_list_and_close(list);
    if (err != 0)
        return (1);
    return (0);
}