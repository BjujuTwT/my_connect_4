/*
** EPITECH PROJECT, 2026
** connect4
** File description:
** Displays a vertical bar on every cell played by
** the current player, starting from a given cell,
** recursively
*/

#include "config.h"

static void disp_single_vert_bar
(settings_t *settings, int corner_x, int corner_y)
{
    WINDOW *screen = settings->screen;
    int cell_width = settings->proportions[0];
    int cell_height = settings->proportions[1];
    int middle_x = corner_x + (cell_width / 2);
    int height_nb = 1;

    wmove(screen, corner_y, middle_x);
    while (height_nb <= cell_height) {
        waddstr(screen, "│");
        wmove(screen, corner_y + height_nb, middle_x);
        height_nb++;
    }
    return;
}

static void disp_all_vertical
(settings_t *settings, int corner_x, int corner_y, int offset)
{
    cell_t **board = settings->board;
    int played_row = settings->last_played[0] - 1;
    int played_col = settings->last_played[1] - 1;
    int player_id = board[played_row][played_col].taken;
    int height = settings->height;
    int loop = 0;

    disp_single_vert_bar(settings, corner_x, corner_y);
    for (int row_bellow = played_row - 1; row_bellow >= 0; row_bellow--) {
        loop = played_row - row_bellow;
        if (board[row_bellow][played_col].taken != player_id)
            break;
        disp_single_vert_bar(settings, corner_x, corner_y - (offset * loop));
    }
    for (int row_above = played_row + 1; row_above < height; row_above++) {
        loop = row_above - played_row;
        if (board[row_above][played_col].taken != player_id)
            break;
        disp_single_vert_bar(settings, corner_x, corner_y + (offset * loop));
    }
}

void display_bar_vertical(settings_t *settings)
{
    WINDOW *screen = settings->screen;
    int row = settings->last_played[0];
    int col = settings->last_played[1];
    int corner_x = get_x_from_column(settings, col);
    int corner_y = get_y_from_row(settings, row);
    int color = (settings->board)[row - 1][col - 1].taken;
    int *props = settings->proportions;

    if (has_colors() == true)
        wattron(screen, COLOR_PAIR(color));
    disp_all_vertical(settings, corner_x, corner_y, props[1] + 1);
    if (has_colors() == true)
        wattroff(screen, COLOR_PAIR(color));
    return;
}
