/*
** EPITECH PROJECT, 2026
** connect4
** File description:
** destroys the program from the point when the user
** left the token input screen
*/

#include <stdlib.h>

#include "config.h"

void destroy_from_token_input(settings_t *settings)
{
    free(settings->proportions);
    destroy_players(settings->player_info);
    return;
}
