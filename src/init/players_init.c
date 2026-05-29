/*
** EPITECH PROJECT, 2026
** connect4
** File description:
** setups the linked list needed to identify every player,
** their tokens and IDs
*/

#include <stdlib.h>
#include <stddef.h>

#include "config.h"

static wchar_t **new_pattern(settings_t *settings, int pattern_index)
{
    int width = (settings->proportions)[0];
    int height = (settings->proportions)[1];
    wchar_t **pattern = malloc_pattern(width, height);

    if (pattern_index == 1)
        return cross_pattern(pattern, width, height);
    if (pattern_index == 2)
        return circle_pattern(pattern, width, height);
    if (pattern_index == 3)
        return triangle_pattern(pattern, width, height);
    return pattern;
}

static void add_new_player(ll_player_info_t **head, int index_player,
    int color, wchar_t **pattern)
{
    ll_player_info_t *new_player = malloc(sizeof(ll_player_info_t));

    new_player->index = index_player;
    new_player->color = color;
    new_player->pattern = pattern;
    new_player->next = *head;
    *head = new_player;
    return;
}

void addd_new_player(settings_t *settings, int pattern_index, int color)
{
    ll_player_info_t *new_player = malloc(sizeof(ll_player_info_t));
    int id = 1;
    int width = settings->width;
    int height = settings->height;

    if (settings->player_info != NULL)
        id = settings->player_info->index + 1;
    new_player->index = id;
    new_player->color = color;
    new_player->pattern = get_pattern_from_index(pattern_index, width, height);
    new_player->next = settings->player_info;
    settings->player_info = new_player;
    return;
}

void setup_players_struct(settings_t *settings)
{
    ll_player_info_t *player_info = NULL;
    int nb_players = DEFAULT_NB_PLAYERS;
    wchar_t **pattern = NULL;

    settings->nb_players = nb_players;
    for (int player_id = 1; player_id <= nb_players; player_id++) {
        pattern = new_pattern(settings, player_id);
        add_new_player(&player_info, player_id, player_id, pattern);
    }
    settings->player_info = player_info;
    return;
}
