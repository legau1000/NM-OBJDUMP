/*
** EPITECH PROJECT, 2018
** objdump.c
** File description:
** objdump
*/

#include <stdio.h>

int unhexax(int letter)
{
    char *calc = {"fedcba9876543210"};
    char *tmp = {"0123456789abcdef"};
    int nb_one = 0;
    int nb_two = 0;

    letter = -letter;
    while (letter > 16) {
        nb_one++;
        letter = letter - 16;
    }
    nb_two = -(letter - 16);
    printf("%c%c", calc[nb_one], tmp[nb_two]);
    return (2);
}
