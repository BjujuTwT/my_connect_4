/*
** EPITECH PROJECT, 2026
** connect4
** File description:
** Displays an horizontal bar on every cell played by
** the current player, starting from a given cell,
** recursively
*/

#include "config.h"

static void disp_single_hori_bar
(settings_t *settings, int corner_x, int corner_y)
{
    WINDOW *screen = settings->screen;
    int cell_width = settings->proportions[0];
    int cell_height = settings->proportions[1];
    int middle_y = corner_y + (cell_height / 2) - ((cell_height + 1) % 2);
    int width_nb = 1;

    wmove(screen, middle_y, corner_x);
    while (width_nb <= cell_width) {
        waddstr(screen, "─");
        width_nb++;
    }
    return;
}

static void disp_all_horizontal
(settings_t *settings, int corner_x, int corner_y, int offset)
{
    cell_t **board = settings->board;
    int played_row = settings->last_played[0] - 1;
    int played_col = settings->last_played[1] - 1;
    int player_id = board[played_row][played_col].taken;
    int width = settings->width;
    int loop = 0;

    disp_single_hori_bar(settings, corner_x, corner_y);
    for (int col_left = played_col - 1; col_left >= 0; col_left--) {
        loop = played_col - col_left;
        if (board[played_row][col_left].taken != player_id)
            break;
        disp_single_hori_bar(settings, corner_x - (offset * loop), corner_y);
    }
    for (int col_right = played_col + 1; col_right < width; col_right++) {
        loop = col_right - played_col;
        if (board[played_row][col_right].taken != player_id)
            break;
        disp_single_hori_bar(settings, corner_x + (offset * loop), corner_y);
    }
}

void display_bar_horizontal(settings_t *settings)
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
    disp_all_horizontal(settings, corner_x, corner_y, props[0] + 1);
    if (has_colors() == true)
        wattroff(screen, COLOR_PAIR(color));
    return;
}
