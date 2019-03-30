/*
** EPITECH PROJECT, 2018
** objdump.c
** File description:
** objdump
*/

#include <stdio.h>
#include "my_objdump.h"

void print_section(int index, int size, t_infos_nm *list, int idx)
{
    if (index != size)
        printf(" %04x ", get_section(list, idx) + index);
}
