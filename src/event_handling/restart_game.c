/*
** EPITECH PROJECT, 2026
** connect4
** File description:
** Resets the board and restarts
** (only if the according key was pressed)
*/

#include <stdlib.h>

#include "config.h"

void restart_game(settings_t *settings)
{
    for (int i = 0; i < settings->height; i++)
        free((settings->board)[i]);
    free(settings->board);
    setup_basic_settings(settings);
    return game_loop(settings);
}
