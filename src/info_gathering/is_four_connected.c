/*
** EPITECH PROJECT, 2026
** is_four_connected
** File description:
** ha, did the joke
*/

#include <stdlib.h>
#include <stdio.h>

#include "config.h"
#include "my.h"

static int horizontal_check(settings_t *settings,
    int row, int col, int player_i)
{
    int count = 0;
    int width = settings->width;

    if ((settings->board)[row][col].taken != player_i)
        return 0;
    if (col + 1 <= settings->last_played[1] && col > 0)
        count += horizontal_check(settings, row, col - 1, player_i);
    if (col + 1 >= settings->last_played[1] && col + 1 < width)
        count += horizontal_check(settings, row, col + 1, player_i);
    return count + 1;
}

static int vertical_check(settings_t *settings,
    int row, int col, int player_i)
{
    int count = 0;
    int height = settings->height;

    if ((settings->board)[row][col].taken != player_i)
        return 0;
    if (row + 1 <= settings->last_played[0] && row > 0)
        count += vertical_check(settings, row - 1, col, player_i);
    if (row + 1 >= settings->last_played[0] && row + 1 < height)
        count += vertical_check(settings, row + 1, col, player_i);
    return count + 1;
}

static int main_diagonal_check(settings_t *settings,
    int row, int col, int player_i)
{
    int count = 0;
    int height = settings->height;
    int width = settings->width;

    if ((settings->board)[row][col].taken != player_i)
        return 0;
    if (row + 1 <= settings->last_played[0] && row > 0) {
        if (col + 1 <= settings->last_played[1] && col > 0)
            count += main_diagonal_check(settings, row - 1, col - 1, player_i);
    }
    if (row + 1 >= settings->last_played[0] && row + 1 < height) {
        if (col + 1 >= settings->last_played[1] && col + 1 < width)
            count += main_diagonal_check(settings, row + 1, col + 1, player_i);
    }
    return count + 1;
}

static int anti_diagonal_check(settings_t *settings,
    int row, int col, int player_i)
{
    int count = 0;
    int height = settings->height;
    int width = settings->width;

    if ((settings->board)[row][col].taken != player_i)
        return 0;
    if (row + 1 <= settings->last_played[0] && row > 0) {
        if (col + 1 >= settings->last_played[1] && col + 1 < width)
            count += anti_diagonal_check(settings, row - 1, col + 1, player_i);
    }
    if (row + 1 >= settings->last_played[0] && row + 1 < height) {
        if (col + 1 <= settings->last_played[1] && col > 0)
            count += anti_diagonal_check(settings, row + 1, col - 1, player_i);
    }
    return count + 1;
}

int check_connected(settings_t *set)
{
    int last_row = set->last_played[0];
    int last_col = set->last_played[1];
    int player = (set->board)[last_row - 1][last_col - 1].taken;
    int nb_connected = 0;

    nb_connected = horizontal_check(set, last_row - 1, last_col - 1, player);
    if (nb_connected >= 4)
        disp_finish_bar(set, 1, 0, 0);
    nb_connected = vertical_check(set, last_row - 1, last_col - 1, player);
    if (nb_connected >= 4)
        disp_finish_bar(set, 0, 1, 0);
    nb_connected = main_diagonal_check(set, last_row - 1, last_col - 1, player);
    if (nb_connected >= 4)
        disp_finish_bar(set, 0, 0, 1);
    nb_connected = anti_diagonal_check(set, last_row - 1, last_col - 1, player);
    if (nb_connected >= 4)
        disp_finish_bar(set, 0, 0, -1);
    return 0;
}
