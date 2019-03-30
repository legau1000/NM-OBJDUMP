/*
** EPITECH PROJECT, 2018
** objdump.c
** File description:
** objdump
*/

#include <string.h>
#include "my_objdump.h"

bool search_arg(char *s1, char *s2, int ac, char **av)
{
    int index = 1;

    while (index != ac) {
        if (strcmp(av[index], s1) == 0 || strcmp(av[index], s2) == 0)
            return (true);
        index++;
    }
    return (true);
}