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
#include "nm.h"

int open_file(t_infos_nm **list)
{
    (*list)->fd = open((*list)->name, O_RDONLY);
    if ((*list)->fd == -1) {
        (*list)->lib = dlopen((*list)->name, O_RDONLY);
        if ((*list)->lib == NULL) {
            (*list)->err = OPEN;
            return (84);
        }
    }
    return (0);
}

int close_file(t_infos_nm *list)
{
    if (list->fd == -1 && list->lib)
        return (dlclose(list->lib));
    else
        return (close(list->fd));
}