/*
** EPITECH PROJECT, 2017
** Test Criterion
** File description:
** nm Units Tests
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "nm.h"

void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}