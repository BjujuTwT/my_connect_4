/*
** EPITECH PROJECT, 2026
** connect4
** File description:
** main function
*/

#include <stdlib.h>

#include "config.h"

int main(int argc, char **argv)
{
    settings_t *settings = NULL;

    if (error_handler(argc, argv) != 0)
        return 84;
    settings = init(argv[1][1]);
    if (settings->to_terminate != 0) {
        free(settings);
        return 84;
    }
    game_loop(settings);
    while (settings->restart == 1)
        restart_game(settings);
    endwin();
    free_function(settings);
    return 0;
}
