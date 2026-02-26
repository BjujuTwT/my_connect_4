/*
** EPITECH PROJECT, 2026
** check_finish_bars
** File description:
** Only gather infos for themselves, to then call display function
** Every function test a certain angle to see in which cell they
** should call a display function
*/

#include <stdlib.h>

#include "config.h"

void check_hori(settings_t *settings, int corner_x, int corner_y, int offset)
{
    cell_t **board = settings->board;
    int played_row = settings->last_played[0] - 1;
    int played_col = settings->last_played[1] - 1;
    int player_id = board[played_row][played_col].taken;
    int width = settings->width;
    int loop = 0;

    disp_hori_bar(settings, corner_x, corner_y);
    for (int col_left = played_col - 1; col_left >= 0; col_left--) {
        loop = played_col - col_left;
        if (board[played_row][col_left].taken != player_id)
            break;
        disp_hori_bar(settings, corner_x - (offset * loop), corner_y);
    }
    for (int col_right = played_col + 1; col_right < width; col_right++) {
        loop = col_right - played_col;
        if (board[played_row][col_right].taken != player_id)
            break;
        disp_hori_bar(settings, corner_x + (offset * loop), corner_y);
    }
}

void check_verti(settings_t *settings, int corner_x, int corner_y, int offset)
{
    cell_t **board = settings->board;
    int played_row = settings->last_played[0] - 1;
    int played_col = settings->last_played[1] - 1;
    int player_id = board[played_row][played_col].taken;
    int height = settings->height;
    int loop = 0;

    disp_vert_bar(settings, corner_x, corner_y);
    for (int row_bellow = played_row - 1; row_bellow >= 0; row_bellow--) {
        loop = played_row - row_bellow;
        if (board[row_bellow][played_col].taken != player_id)
            break;
        disp_vert_bar(settings, corner_x, corner_y - (offset * loop));
    }
    for (int row_above = played_row + 1; row_above < height; row_above++) {
        loop = row_above - played_row;
        if (board[row_above][played_col].taken != player_id)
            break;
        disp_vert_bar(settings, corner_x, corner_y + (offset * loop));
    }
}

static void check_main_diagonal(settings_t *settings,
    int row, int col, int player)
{
    cell_t **board = settings->board;
    int played_row = settings->last_played[0] - 1;
    int corner_x = get_x_from_column(settings, col + 1);
    int corner_y = get_y_from_row(settings, row + 1);
    int height = settings->height;
    int width = settings->width;

    if (board[row][col].taken == player)
        disp_diago_bar(settings, corner_x, corner_y, 1);
    if (row >= played_row) {
        if (row + 1 < height && col + 1 < width)
            check_main_diagonal(settings, row + 1, col + 1, player);
    }
    if (row <= played_row) {
        if (row > 0 && col > 0)
            check_main_diagonal(settings, row - 1, col - 1, player);
    }
    return;
}

static void check_anti_diagonal(settings_t *settings,
    int row, int col, int player)
{
    cell_t **board = settings->board;
    int played_row = settings->last_played[0] - 1;
    int corner_x = get_x_from_column(settings, col + 1);
    int corner_y = get_y_from_row(settings, row + 1);
    int height = settings->height;
    int width = settings->width;

    if (board[row][col].taken == player)
        disp_diago_bar(settings, corner_x, corner_y, -1);
    if (row >= played_row) {
        if (row + 1 < height && col > 0)
            check_anti_diagonal(settings, row + 1, col - 1, player);
    }
    if (row <= played_row) {
        if (row > 0 && col + 1 < width)
            check_anti_diagonal(settings, row - 1, col + 1, player);
    }
    return;
}

void check_diago(settings_t *settings, int row, int col, int diago)
{
    int player = 0;

    row -= 1;
    col -= 1;
    player = (settings->board)[row][col].taken;
    if (diago > 0)
        check_main_diagonal(settings, row, col, player);
    else
        check_anti_diagonal(settings, row, col, player);
    return;
}
