/*
** EPITECH PROJECT, 2018
** Duo Stumper
** File description:
** def.h
*/

#ifndef DEH_H__
#define DEF_H__

#include <unistd.h>

#define UNUSED __attribute__((unused))
#define UINT unsigned int
#define FILE __FILE__
#define LINE __LINE__
#define TIME __TIME__
#define DATE __DATE__

#define V_INT(x) if (!x) return (84)
#define V_CHAR(x) if (!x) return (NULL)

#undef		WRITE_DEFINE
#define WRITE_DEFINE(str)	write(1, (str), sizeof((str)) - 1)

#define MPRI MAP_PRIVATE
#define PREAD PROT_READ

#endif
