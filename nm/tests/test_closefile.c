/*
** EPITECH PROJECT, 2017
** Test Criterion
** File description:
** nm Units Tests
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <dlfcn.h>
#include <fcntl.h>
#include <stdio.h>
#include "nm.h"

Test(close_file, good_standard_file)
{
    t_infos_nm *list = malloc(sizeof(t_infos_nm));

    list->name = "Makefile";
    cr_assert(open_file(&list) == 0);
    cr_assert(close_file(list) == 0);
    printf("Units Tests **NM** close_file: Good standard file ====> \tOK\n");
}

Test(close_file, dynamique_library)
{
    t_infos_nm *list = malloc(sizeof(t_infos_nm));

    list->name = "a.out";
    list->fd = -1;
    list->lib = dlopen(list->name, O_RDONLY);
    cr_assert(close_file(list) == -1);
    printf("Units Tests **NM** close_file: Dynamique library ====> \tOK\n");
}