/*
** EPITECH PROJECT, 2026
** connect4
** File description:
** Displays an diagonal bar on every cell played by
** the current player, starting from a given cell,
** recursively
*/

#include <stdlib.h>

#include "config.h"

static void disp_single_diago_bar(settings_t *settings,
    int corner_x, int corner_y, int diag)
{
    char *chr = NULL;
    int cell_height = settings->proportions[1];
    int side = 0;
    int pos_x = 0;
    int pos_y = 0;

    if (diag > 0) {
        chr = "⟍";
        side = -1;
    } else {
        chr = "⟋";
        side = 1;
        corner_y += cell_height - 1;
    }
    for (int cell_h = 0; cell_h < cell_height; cell_h++) {
        pos_x = corner_x + (cell_h * 2 + 1);
        pos_y = corner_y - (cell_h * side);
        mvwaddstr(settings->screen, pos_y, pos_x, chr);
    }
}

static void disp_all_main_diagonal(settings_t *settings,
    int row, int col, int player)
{
    cell_t **board = settings->board;
    int played_row = settings->last_played[0] - 1;
    int corner_x = get_x_from_column(settings, col + 1);
    int corner_y = get_y_from_row(settings, row + 1);
    int height = settings->height;
    int width = settings->width;

    if (board[row][col].taken == player)
        disp_single_diago_bar(settings, corner_x, corner_y, 1);
    if (row >= played_row) {
        if (row + 1 < height && col + 1 < width)
            disp_all_main_diagonal(settings, row + 1, col + 1, player);
    }
    if (row <= played_row) {
        if (row > 0 && col > 0)
            disp_all_main_diagonal(settings, row - 1, col - 1, player);
    }
    return;
}

static void disp_all_anti_diagonal(settings_t *settings,
    int row, int col, int player)
{
    cell_t **board = settings->board;
    int played_row = settings->last_played[0] - 1;
    int corner_x = get_x_from_column(settings, col + 1);
    int corner_y = get_y_from_row(settings, row + 1);
    int height = settings->height;
    int width = settings->width;

    if (board[row][col].taken == player)
        disp_single_diago_bar(settings, corner_x, corner_y, -1);
    if (row >= played_row) {
        if (row + 1 < height && col > 0)
            disp_all_anti_diagonal(settings, row + 1, col - 1, player);
    }
    if (row <= played_row) {
        if (row > 0 && col + 1 < width)
            disp_all_anti_diagonal(settings, row - 1, col + 1, player);
    }
    return;
}

void display_bar_diagonal(settings_t *settings, int side)
{
    WINDOW *screen = settings->screen;
    int row = settings->last_played[0] - 1;
    int col = settings->last_played[1] - 1;
    int player = (settings->board)[row][col].taken;
    int color = (settings->board)[row][col].taken;

    if (has_colors() == true)
        wattron(screen, COLOR_PAIR(color));
    if (side > 0)
        disp_all_main_diagonal(settings, row, col, player);
    else
        disp_all_anti_diagonal(settings, row, col, player);
    if (has_colors() == true)
        wattroff(screen, COLOR_PAIR(color));
    return;
}
