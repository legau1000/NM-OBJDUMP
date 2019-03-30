/*
** EPITECH PROJECT, 2017
** Test Criterion
** File description:
** nm Units Tests
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <stdio.h>
#include "my_objdump.h"

Test(open_file, good_standard_file)
{
    t_infos_nm *list = malloc(sizeof(t_infos_nm));

    list->name = "Makefile";
    cr_assert(open_file(&list) == 0);
    printf("Units Tests **OBJ** open_file: Good standard file ====> \tOK\n");
}

Test(open_file, file_dont_exist)
{
    t_infos_nm *list = malloc(sizeof(t_infos_nm));

    list->name = "BAD_FILE";
    cr_assert(open_file(&list) == 84);
    printf("Units Tests **OBJ** open_file: File don't exist ====> \tOK\n");
}

Test(open_file, dynamique_library)
{
    t_infos_nm *list = malloc(sizeof(t_infos_nm));

    list->name = "redirect.o";
    cr_assert(open_file(&list) == 0);
    printf("Units Tests **OBJ** open_file: Dynamique library ====> \tOK\n");
}