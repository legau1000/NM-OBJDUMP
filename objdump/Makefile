##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## makefile
##

INCLUDE		=	-Iinclude

CFLAGS          +=      $(INCLUDE) -W -Wall -Wextra -Wshadow 

CC		=	gcc -g

RM		=	rm

SRC_BASE	=	src/

SRC_FILES	=	main.c			\
				my_objdump.c	\
				get_info.c		\
				add_maillon.c	\
				open_file.c		\
				map_file.c		\
				print.c			\
				print_s.c		\
				print_err.c		\
				get_info_s.c	\
				hexa.c			\
				print_section.c	\
				parse_arg.c

SRC		=	$(addprefix $(SRC_BASE),$(SRC_FILES))

OBJ		=	$(SRC:.c=.o)

NAME		=	../my_objdump

.SILENT:

$(NAME):	$(OBJ)
	$(CC)  -o $(NAME) $(OBJ)

all:	$(NAME)

clean:
	$(RM) -f $(OBJ)

fclean: clean
	$(RM) -f $(NAME)

re:	fclean all

tests_run:
	make -C tests/

.PHONY: clean fclean re all tests_run
