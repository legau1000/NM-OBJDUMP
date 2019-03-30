/*
** EPITECH PROJECT, 2017
** objdump
** File description:
** struct.h
*/

#ifndef DEF_STRUCT_H__
#define DEF_STRUCT_H__

#include <stdbool.h>
#include <elf.h>

typedef enum error_nm
{
    NOTHING = 0,
    OPEN,
    FILES,
    MAP,
    OTHER
}e_err;

typedef struct s_arg
{
    bool f;
    bool s;
}t_arg;

typedef struct s_infos_nm
{
    int fd;
    void *buf;
    e_err err;
    char *name;
    Elf64_Ehdr *elf_64;
    Elf64_Shdr *shdr_64;
    Elf32_Ehdr *elf_32;
    Elf32_Shdr *shdr_32;
    char *strtab;
    struct s_infos_nm *next;
    struct s_infos_nm *previous;
}t_infos_nm;

#endif
