/*
** EPITECH PROJECT, 2026
** connect4
** File description:
** main function
*/

#include <stdlib.h>

#include "config.h"

static int end_prog(settings_t *settings)
{
    int return_val = settings->to_terminate;

    free(settings);
    return return_val;
}

int main(int argc, char **argv)
{
    settings_t *settings = NULL;

    if (error_handler(argc, argv) != 0)
        return 84;
    settings = init(argv[1][1]);
    if (settings->to_terminate != 0)
        return end_prog(settings);
    game_loop(settings);
    while (settings->restart == 1)
        restart_game(settings);
    endwin();
    free_function(settings);
    return 0;
}
