##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## makefile
##

.SILENT:

all:
	make -C nm/
	make -C objdump/
		@echo "Compilation global faite!"

nm:
	make -C nm/
		@echo "Compilation nm faite!"

objdump:
	make -C objdump/
		@echo "Compilation objdump faite!"

clean:
	make clean -C nm
	make clean -C objdump
		@echo "Clean faite!"

fclean: clean
	make fclean -C nm
	make fclean -C objdump
		@echo "FClean faite!"

re:	fclean all
	make re -C nm
	make re -C objdump
		@echo "Re fait!"

tests_run:
	@echo "STARTING CRITERION'S UNITS TESTS"
	@echo "----------------------------------------------------------------------------------------------------------------------"
	make -C nm/tests/
	@echo "----------------------------------------------------------------------------------------------------------------------"
	make -C objdump/tests/
	@echo "----------------------------------------------------------------------------------------------------------------------"
	@echo "UNITS TESTS END"

.PHONY: clean fclean re all tests_run nm objdump
