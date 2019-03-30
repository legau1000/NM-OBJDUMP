##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## makefile
##

DEBUG		=	no

include 	../make_tools/rules.mk

INCLUDE		=	-Iinclude

CFLAGS          +=      $(INCLUDE) -W -Wall -Wextra -Wshadow 

CC		=	gcc -g

RM		=	rm

SRC_BASE	=	src/

SRC_FILES	=	main.c					\
				catch_data.c			\
				get_info.c				\
				map_file.c				\
				my_nm.c					\
				open_file.c				\
				sort_list.c				\
				get_type.c				\
				free_list_and_close.c 	\
				my_swap.c 				\
				add_maillon.c

SRC		=	$(addprefix $(SRC_BASE),$(SRC_FILES))

OBJ		=	$(SRC:.c=.o)

NAME		=	../my_nm

.SILENT:

$(NAME):	$(OBJ)
	$(CC)  -o $(NAME) $(OBJ) -ldl

all:	$(NAME)

clean:
	$(RM) -f $(OBJ)

fclean: clean
	$(RM) -f $(NAME)

re:	fclean all

tests_run:
	make -C tests/

.PHONY: clean fclean re all tests_run
