##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## makefile
##

CFLAGS	=	-I../include --coverage

SRC	=	redirect.c 			\
		test_openfile.c		\
		test_closefile.c 	\
		test_my_swap.c	 	\
		../src/my_swap.c	\
		../src/open_file.c

OBJ	=	$(SRC:.c=.o)

NAME	=	units_tests

.SILENT:

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) -lcriterion -lgcov -ldl
	@echo "Units tests **NM**"
	./units_tests
	@echo "END Units tests **NM**"

all:	$(NAME)

clean:
	rm -f $(OBJ)
		@echo Clean fait!

fclean: clean
	find ../ -name "*.gcda" -delete
	find ../ -name "*.gcno" -delete
	rm units_tests
		@echo Fclean fait!

re:	fclean all
		@echo RE fait!

.PHONY: clean fclean re all
