/*
** EPITECH PROJECT, 2026
** connect4
** File description:
** Frees the given player linked list
*/

#include <stdlib.h>

#include "config.h"

static void destroy_single_player(ll_player_info_t *node)
{
    if (node->pattern != NULL) {
        for (int i = 0; (node->pattern)[i] != NULL; i++)
            free((node->pattern)[i]);
    }
    return;
}

void destroy_players(ll_player_info_t *list)
{
    if (list == NULL)
        return;
    if (list->next == NULL)
        return destroy_single_player(list);
    destroy_players(list->next);
    return;
}
