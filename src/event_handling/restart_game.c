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
    destroy_basic_settings(settings);
    setup_basic_settings(settings);
    return game_loop(settings);
}
