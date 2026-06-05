/*
** EPITECH PROJECT, 2026
** connect4
** File description:
** Function that frees allocated memory of the whole program
** It's like a nuke
*/

#include <stdlib.h>

#include "config.h"

void free_function(settings_t *settings)
{
    destroy_basic_settings(settings);
    free(settings->proportions);
    destroy_players(settings->player_info);
    free(settings);
    return;
}
