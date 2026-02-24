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
		my_put_array.c	\
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
			board/settings_init.c	\
			board/ncurses_init.c	\
			board/csfml_init.c	\
			board/players_init.c	\
			board/pattern_templates.c	\
			board/window_size.c	\
			display/display_ncurses.c	\
			display/display_board.c	\
			display/display_help.c	\
			display/display_color.c	\
			display/display_cells.c	\
			display/display_stand.c	\
			display/display_finish_bar.c	\
			data_mutating/add_token_in_column.c	\
			data_mutating/move_arrow.c	\
			data_mutating/setup_turns.c	\
			info_gathering/get_player_from_turn.c	\
			info_gathering/is_board_filled.c	\
			info_gathering/get_coordinate_from_pos.c	\
			info_gathering/get_window_size.c	\
			info_gathering/is_four_connected.c	\

SRC_PROJ_PREFIX	=	$(addprefix src/, $(SRC_PROJ))

OBJ_PROJ	=	$(SRC_PROJ_PREFIX:.c=.o)

NAME_PROJ	=	connect_4

CC	=	epiclang

LDFLAGS =      	 -l csfml-graphics -l csfml-system -Llib/ -lmy -lncursesw

CPPFLAGS =	-Iinclude

CFLAGS  =       -Wall -Wextra -Wconversion


all:	$(NAME_MY) $(NAME_PROJ)

$(NAME_MY): $(OBJ_MY)
	ar rc $(NAME_MY) $(OBJ_MY)
	cp include/my.h lib/my/
	cp $(NAME_MY) lib/

$(NAME_PROJ): $(OBJ_PROJ)
	$(CC) -o $(NAME_PROJ) $(OBJ_PROJ) $(CPPFLAGS) $(LDFLAGS) $(CFLAGS)

cpy:
	cp include/my.h lib/my/

clean:
	rm -f $(OBJ_MY) $(OBJ_PROJ)
	rm -f include/*~ include/*# include/*.pch
	rm -f *~ *# src/info_gathering/*~ src/info_gathering/*#
	rm -f src/*~ src/*# src/error_handling/*~ src/error_handling/*# src/event_handling/*~ src/event_handling/*#
	rm -f src/display/*~ src/display/*# src/board/*~ src/board/*# ressources/*~ ressources/*# src/data_mutating/*~ src/data_mutating/*#

fclean: clean
	rm -f *.gcda *.gcno
	rm -f $(NAME_MY) lib/$(NAME_MY) $(NAME_PROJ) a.out lib/my/a.out

re: fclean all

.PHONY: all clean fclean re cpy
