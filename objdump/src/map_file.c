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
#include "my_objdump.h"
#include "def.h"

int map_file(t_infos_nm **list)
{
    struct stat s;

    if (fstat((*list)->fd, &s) == -1) {
        (*list)->err = OTHER;
        return (84);
    }
    (*list)->buf = mmap(NULL , s.st_size , PREAD , MPRI , (*list)->fd, 0);
    if ((*list)->buf == (void*) -1) {
        (*list)->err = MAP;
        return (1);
    }
    (*list)->elf_64 = (Elf64_Ehdr *)(*list)->buf;
    (*list)->elf_32 = (Elf32_Ehdr *)(*list)->buf;
    if ((*list)->elf_64->e_ident[EI_MAG0] != ELFMAG0) {
        (*list)->err = FILES;
        return (1);
    }
    (*list)->shdr_64 = (Elf64_Shdr *)((*list)->buf + (*list)->elf_64->e_shoff);
    (*list)->shdr_32 = (Elf32_Shdr *)((*list)->buf + (*list)->elf_32->e_shoff);
    return (0);
}