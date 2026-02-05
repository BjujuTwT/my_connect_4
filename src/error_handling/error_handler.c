/*
** EPITECH PROJECT, 2026
** error_handler
** File description:
** handles all types of errors that can be
** caused by the executable command
*/

#include "my.h"
#include "config.h"
#include "macro_colors.h"

static int verif_argument(int flag)
{
    const int ncurses_flag = 'n';
    const int csfml_flag = 'c';
    const int help_flag = 'h';

    switch (flag) {
        case (ncurses_flag):
            return 0;
        case (csfml_flag):
            return 0;
        case (help_flag):
            return 0;
    }
    return -1;
}

int error_handler(int argc, char **argv)
{
    if (argc != 2) {
        display_error("Expected a single argument.\n", CRIMSON);
        display_error("Try : ./connect_4 -h\n", LIGHT_BLUE);
        return 84;
    }
    if (argv[1][0] != '-') {
        display_error("Incorrect argument given.\n", CRIMSON);
        display_error("Try : ./connect_4 -h\n", LIGHT_BLUE);
        return 84;
    }
    if (my_strlen(argv[1]) != 2 || verif_argument(argv[1][1]) == -1) {
        display_error("Incorrect flag given.\n", CRIMSON);
        display_error("Try : ./connect_4 -h\n", LIGHT_BLUE);
        return 84;
    }
    return 0;
}
