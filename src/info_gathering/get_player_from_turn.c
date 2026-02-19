/*
** EPITECH PROJECT, 2026
** get_player_from_index
** File description:
** returns the player struct of this turn's player
*/

#include "config.h"

ll_player_info_t *get_player_from_turn(ll_player_info_t *player,
    int turn)
{
    if (player->index == turn)
        return player;
    return get_player_from_turn(player->next, turn);
}
