/*
** EPITECH PROJECT, 2018
** objdump
** File description:
** my_objdump.h
*/

#ifndef OBJDUMP_H__
#define OBJDUMP_H__

#include "struct.h"

int my_objdump(int ac, char **av);
bool search_arg(char *s1, char *s2, int ac, char **av);
int get_info(t_infos_nm **list, char *path);
int add_maillon_to_list(t_infos_nm **list, char *path);
int open_file(t_infos_nm **list);
int close_file(t_infos_nm *list);
int map_file(t_infos_nm **list);
void print_value(t_infos_nm *list, t_arg *arg);
void print_err(t_infos_nm *list);
void pint_arg_s(t_infos_nm *list, int index);
char *get_str_data(t_infos_nm *list, char *strtab, int index);
char *get_name(t_infos_nm *list, char *strtab, int index);
char *get_data(t_infos_nm *list, int index);
int get_size(t_infos_nm *list, int index);
int get_section(t_infos_nm *list, int index);
int unhexax(int letter);
void print_section(int index, int size, t_infos_nm *list, int idx);

#endif
