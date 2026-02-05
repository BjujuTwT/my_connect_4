##
## EPITECH PROJECT, 2025
## Makefile
## File description:
## builds the library of 30 or so func
##

SRC_MY	=	my_compute_square_root.c	\
		my_compute_power_rec.c	\
		my_find_n_in_array.c	\
		my_str_isprintable.c	\
		my_find_prime_sup.c	\
		my_find_c_in_str.c	\
		my_put_int_array.c	\
		my_strcapitalize.c	\
		my_put_2d_array.c	\
		my_str_isalpha.c	\
		my_str_islower.c	\
		my_str_isupper.c	\
		my_merge_sort.c	\
		my_strlowcase.c	\
		my_floatncmp.c	\
		my_strcutcpy.c	\
		my_strupcase.c	\
		my_is_prime.c	\
		my_maximum.c	\
		my_minimum.c	\
		my_put_nbr.c	\
		my_putchar.c	\
		my_strncat.c	\
		my_strncmp.c	\
		my_strncpy.c	\
		my_getnbr.c	\
		my_intlen.c	\
		my_putstr.c	\
		my_revstr.c	\
		my_strcat.c	\
		my_strcmp.c	\
		my_strcpy.c	\
		my_strlen.c	\
		my_strstr.c	\
		my_isneg.c	\
		my_swap.c	\

SRC_MY_PREFIX =	$(addprefix lib/my/, $(SRC_MY))

OBJ_MY =       $(SRC_MY_PREFIX:.c=.o)

NAME_MY =       libmy.a

SRC_PROJ	=	main.c	\
			event_handling/wait_for_next_move.c	\
			error_handling/error_handler.c	\
			error_handling/display_error.c	\

SRC_PROJ_PREFIX	=	$(addprefix src/, $(SRC_PROJ))

OBJ_PROJ	=	$(SRC_PROJ_PREFIX:.c=.o)

NAME_PROJ	=	connect_4

CC	=	epiclang

LDFLAGS =      	 -l csfml-graphics -l csfml-system -Llib/ -lmy -lncurses

CPPFLAGS =	-Iinclude

CFLAGS  =       -Wall -Wextra -Wconversion -Werror


all:	$(NAME_MY) $(NAME_PROJ)

$(NAME_MY): $(OBJ_MY)
	ar rc $(NAME_MY) $(OBJ_MY)
	cp include/my.h lib/my/
	mv $(NAME_MY) lib/

$(NAME_PROJ): $(OBJ_PROJ)
	$(CC) -o $(NAME_PROJ) $(OBJ_PROJ) $(CPPFLAGS) $(LDFLAGS) $(CFLAGS)

cpy:
	cp include/my.h lib/my/

clean:
	rm -f $(OBJ_MY) $(OBJ_PROJ)
	rm -f include/*~ include/*# include/*.pch
	rm -f src/*~ 
	rm -f src/*~ src/*# src/error_handling/*~ src/error_handling/*# src/event_handling/*~ src/event_handling/*#

fclean: clean
	rm -f *.gcda *.gcno
	rm -f $(NAME_MY) lib/$(NAME_MY) $(NAME_PROJ) a.out lib/my/a.out

re: fclean all

.PHONY: all clean fclean re cpy
