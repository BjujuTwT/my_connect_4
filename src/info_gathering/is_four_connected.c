/*
** EPITECH PROJECT, 2026
** is_four_connected
** File description:
** ha, did the joke
*/

#include <stdlib.h>
#include <stdio.h>

#include "config.h"

static int get_nb_horizontal
(settings_t *settings, int row, int col, int player_i)
{
    int count = 0;
    int width = settings->width;

    if ((settings->board)[row][col].taken != player_i)
        return 0;
    if (col + 1 <= settings->last_played[1] && col > 0)
        count += get_nb_horizontal(settings, row, col - 1, player_i);
    if (col + 1 >= settings->last_played[1] && col + 1 < width)
        count += get_nb_horizontal(settings, row, col + 1, player_i);
    return count + 1;
}

static int get_nb_vertical
(settings_t *settings, int row, int col, int player_i)
{
    int count = 0;
    int height = settings->height;

    if ((settings->board)[row][col].taken != player_i)
        return 0;
    if (row + 1 <= settings->last_played[0] && row > 0)
        count += get_nb_vertical(settings, row - 1, col, player_i);
    if (row + 1 >= settings->last_played[0] && row + 1 < height)
        count += get_nb_vertical(settings, row + 1, col, player_i);
    return count + 1;
}

static int get_nb_main_diagonal
(settings_t *settings, int row, int col, int player_i)
{
    int count = 0;
    int height = settings->height;
    int width = settings->width;

    if ((settings->board)[row][col].taken != player_i)
        return 0;
    if (row + 1 <= settings->last_played[0] && row > 0) {
        if (col + 1 <= settings->last_played[1] && col > 0)
            count += get_nb_main_diagonal(settings, row - 1, col - 1, player_i);
    }
    if (row + 1 >= settings->last_played[0] && row + 1 < height) {
        if (col + 1 >= settings->last_played[1] && col + 1 < width)
            count += get_nb_main_diagonal(settings, row + 1, col + 1, player_i);
    }
    return count + 1;
}

static int get_nb_anti_diagonal
(settings_t *settings, int row, int col, int player_i)
{
    int count = 0;
    int height = settings->height;
    int width = settings->width;

    if ((settings->board)[row][col].taken != player_i)
        return 0;
    if (row + 1 <= settings->last_played[0] && row > 0) {
        if (col + 1 >= settings->last_played[1] && col + 1 < width)
            count += get_nb_anti_diagonal(settings, row - 1, col + 1, player_i);
    }
    if (row + 1 >= settings->last_played[0] && row + 1 < height) {
        if (col + 1 <= settings->last_played[1] && col > 0)
            count += get_nb_anti_diagonal(settings, row + 1, col - 1, player_i);
    }
    return count + 1;
}

void check_connected(settings_t *set)
{
    int last_row = set->last_played[0] - 1;
    int last_col = set->last_played[1] - 1;
    int player = (set->board)[last_row][last_col].taken;

    if (get_nb_horizontal(set, last_row, last_col, player) >= 4) {
        display_bar_horizontal(set);
        set->is_ended = player;
    }
    if (get_nb_vertical(set, last_row, last_col, player) >= 4) {
        display_bar_vertical(set);
        set->is_ended = player;
    }
    if (get_nb_main_diagonal(set, last_row, last_col, player) >= 4) {
        display_bar_diagonal(set, 1);
        set->is_ended = player;
    }
    if (get_nb_anti_diagonal(set, last_row, last_col, player) >= 4) {
        display_bar_diagonal(set, -1);
        set->is_ended = player;
    }
}
