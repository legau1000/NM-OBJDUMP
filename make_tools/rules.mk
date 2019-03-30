##
## EPITECH PROJECT, 2018
## Tools Makefile
## File description:
## np_objdump project
##

ifeq ($(DEBUG), no)
	CFLAGS  += $(INCLUDE) -W -Wall -Wextra -Wshadow
else
	CFLAGS  += -Werror -pedantic-errors
endif
