/*
** EPITECH PROJECT, 2018
** Duo Stumper
** File description:
** my.h
*/

#ifndef NM_H__
#define NM_H__

#include "struct.h"
#include "def.h"

int get_info(t_infos_nm **list, char *path);
int open_file(t_infos_nm **list);
int close_file(t_infos_nm *list);
int map_file(t_infos_nm **list);
int add_maillon_to_list(t_infos_nm **list, char *path);
int stok_data(t_infos_nm **list);
void sort_list(t_infos_nm **list);
char get_type(t_infos_nm *list, Elf64_Sym *tps, unsigned char st_info);
void my_swap(t_infos_sys *tmp, t_infos_sys *tmpnext);
void free_list_and_close(t_infos_nm *list);

#endif
