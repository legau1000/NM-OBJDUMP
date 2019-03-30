/*
** EPITECH PROJECT, 2017
** Duo Stumper
** File description:
** struct.h
*/

#ifndef DEF_STRUCT_H__
#define DEF_STRUCT_H__

#include <elf.h>

typedef enum error_nm
{
    NOTHING = 0,
    OPEN,
    FILES,
    MAP,
    OTHER
}e_err;

typedef struct s_infos_sys
{
    int value;
    char type;
    char *name;
    Elf64_Sym *sys;
    struct s_infos_sys *next;
    struct s_infos_sys *previous;
}t_infos_sys;

typedef struct s_infos_nm
{
    int fd;
    void *lib;
    char *name;
    e_err err;
    Elf64_Ehdr *elf;
    Elf64_Shdr *shdr;
    Elf64_Sym *sym;
    char *strtab;
    void *buf;
    t_infos_sys *data;
    struct s_infos_nm *next;
    struct s_infos_nm *previous;
}t_infos_nm;

#endif
