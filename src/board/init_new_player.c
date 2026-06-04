/*
** EPITECH PROJECT, 2026
** connect4
** File description:
** creates a new player
*/

#include <stddef.h>
#include <stdlib.h>

#include "config.h"

void init_new_player(settings_t *settings, int i_token, int i_color)
{
    ll_player_info_t *new_player = malloc(sizeof(ll_player_info_t));
    int id = 1;
    int *prop = settings->proportions;

    if (settings->player_info != NULL)
        id = settings->player_info->index + 1;
    new_player->index = id;
    new_player->color = i_color;
    new_player->pattern = get_pattern_from_index(i_token, prop[0], prop[1]);
    new_player->next = settings->player_info;
    settings->player_info = new_player;
    settings->nb_players += 1;
    return;
}
