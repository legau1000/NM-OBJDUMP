/*
** EPITECH PROJECT, 2018
** objdump.c
** File description:
** objdump
*/

#include <stdio.h>
#include "my_objdump.h"
#include "def.h"

void print_err(t_infos_nm *list)
{
    char *string = "An unknown error have been find";

    if (list->err == OPEN)
        dprintf(2, "objdump: '%s': No such file\n", list->name);
    if (list->err == FILES)
        dprintf(2, "objdump: %s: File format not recognized\n", list->name);
    if (list->err == MAP)
        perror("mmap");
    if (list->err == OTHER)
        dprintf(2, "objdump: %s: %s\n", list->name, string);
}