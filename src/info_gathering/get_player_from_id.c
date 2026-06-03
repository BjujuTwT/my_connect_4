/*
** EPITECH PROJECT, 2026
** connect4
** File description:
** returns the player struct corresponding to the given id
*/

#include "config.h"

ll_player_info_t *get_player_from_id(ll_player_info_t *player,
    int id)
{
    if (player->index == id)
        return player;
    return get_player_from_id(player->next, id);
}
