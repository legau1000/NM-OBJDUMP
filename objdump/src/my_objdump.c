/*
** EPITECH PROJECT, 2018
** objdump.c
** File description:
** objdump
*/

#include <stdio.h>
#include <stdlib.h>
#include "my_objdump.h"
#include "def.h"

static char *search_file(int nb, int ac, char **av)
{
    static int index = 1;

    while (index < ac) {
        if (av[index] && av[index][0] && av[index][0] != '-') {
            index = index + 1;
            return (av[index - 1]);
        }
        index = index + 1;
    }
    if (nb == 0) {
        index = ac;
        return ("a.out");
    } else
        return (NULL);
}

static void free_value(t_infos_nm *list)
{
    t_infos_nm *tmp = list;

    while (tmp) {
        list = list->next;
        close_file(tmp);
        free(tmp);
        tmp = list;
    }
}

int my_objdump(int ac, char **av)
{
    int err = 0;
    t_infos_nm *list = NULL;
    char *stock = search_file(0, ac, av);
    t_arg arg = {search_arg("-f", "--file-headers", ac, av),
                search_arg("-s", "--full-contents", ac, av)};

    while (stock) {
        err = get_info(&list, stock);
        stock = search_file(1, ac, av);
    }
    print_value(list, &arg);
    free_value(list);
    return (err);
}