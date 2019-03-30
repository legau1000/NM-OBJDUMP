/*
** EPITECH PROJECT, 2017
** Test Criterion
** File description:
** nm Units Tests
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <stdio.h>
#include "nm.h"

Test(my_swap, strandard_swap)
{
    t_infos_sys list = {-1, '?', "FIRST", NOTHING};
    t_infos_sys tmp = {-1, '?', "SECOND", NOTHING};

    my_swap(&list, &tmp);
    cr_assert(strcmp(list.name, "SECOND") == 0);
    cr_assert(strcmp(tmp.name, "FIRST") == 0);
    printf("Units Tests **NM** My Swap\t\t\t ====> \tOK\n");
}