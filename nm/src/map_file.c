/*
** EPITECH PROJECT, 2018
** my_nm
** File description:
** MapFile really main
*/

#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dlfcn.h>
#include "nm.h"

static void init_buf(t_infos_nm **list, struct stat *s)
{
    if ((*list)->fd != -1)
        (*list)->buf = mmap(NULL , s->st_size , PREAD , MPRI , (*list)->fd, 0);
    else
        (*list)->buf = dlsym((*list)->lib, "cos");
}

int map_file(t_infos_nm **list)
{
    struct stat s;

    if (fstat((*list)->fd, &s) == -1) {
        (*list)->err = OTHER;
        return (84);
    }
    init_buf(list, &s);
    if ((*list)->buf == (void*) -1) {
        (*list)->err = MAP;
        return (1);
    }
    (*list)->elf = (Elf64_Ehdr *)(*list)->buf;
    if ((*list)->elf->e_ident[EI_MAG0] != ELFMAG0) {
        (*list)->err = FILES;
        return (1);
    }
    (*list)->shdr = (Elf64_Shdr *)((*list)->buf + (*list)->elf->e_shoff);
    return (0);
}