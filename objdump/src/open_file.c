/*
** EPITECH PROJECT, 2018
** my_nm
** File description:
** Openfile
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dlfcn.h>
#include <unistd.h>
#include "my_objdump.h"

int open_file(t_infos_nm **list)
{
    (*list)->fd = open((*list)->name, O_RDONLY);
    if ((*list)->fd == -1) {
        (*list)->err = OPEN;
        return (84);
    }
    return (0);
}

int close_file(t_infos_nm *list)
{
    return (close(list->fd));
}