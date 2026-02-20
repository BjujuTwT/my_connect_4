/*
** EPITECH PROJECT, 2026
** setup_players
** File description:
** setups the linked list needed to identify every player,
** their tokens and IDs
*/

#include <stdlib.h>
#include <stddef.h>

#include "config.h"

static wchar_t **malloc_pattern(int width, int height)
{
    wchar_t **pattern = NULL;

    pattern = malloc(sizeof(wchar_t *) * (size_t)(height + 1));
    for (int i = 0; i < height; i++) {
        pattern[i] = malloc(sizeof(wchar_t) * (size_t)(width + 1));
        for (int j = 0; j < width; j++)
            pattern[i][j] = L' ';
        pattern[i][width] = L'\0';
    }
    pattern[height] = NULL;
    return pattern;
}

static wchar_t **new_pattern(settings_t *settings, int pattern_index)
{
    int width = (settings->proportions)[0];
    int height = (settings->proportions)[1];
    wchar_t **pattern = malloc_pattern(width, height);

    if (pattern_index == 1)
        return cross_pattern(pattern, width, height);
    if (pattern_index == 2)
        return circle_pattern(pattern, width, height);
    return pattern;
}

static void new_player(ll_player_info_t **head, int index_player,
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

void setup_players_struct(settings_t *settings)
{
    ll_player_info_t *player_info = NULL;
    int nb_players = 2;
    wchar_t **pattern = NULL;

    settings->nb_players = nb_players;
    for (int player_id = 1; player_id <= nb_players; player_id++) {
        pattern = new_pattern(settings, player_id);
        new_player(&player_info, player_id, player_id, pattern);
    }
    settings->player_info = player_info;
    return;
}
