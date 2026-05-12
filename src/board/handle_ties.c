/*
** EPITECH PROJECT, 2026
** connect4
** File description:
** Handles when the game is tied (no one could make a connect4)
*/

#include "config.h"

void handle_ties(settings_t *settings)
{
    if (settings->is_ended == -1 && is_board_filled(settings) == 1)
        settings->is_ended = 0;
    return;
}
