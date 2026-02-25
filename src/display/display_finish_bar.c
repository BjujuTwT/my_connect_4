/*
** EPITECH PROJECT, 2026
** disp_finish_bar
** File description:
** displays the bar between tokens when a game is finished
*/
#include <stdlib.h>

#include "config.h"

static void disp_hori_bar(settings_t *settings, int corner_x, int corner_y)
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

void check_horizontal_bar(settings_t *settings,
    int corner_x, int corner_y, int width_offset)
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
        disp_hori_bar(settings, corner_x - (width_offset * loop), corner_y);
    }
    for (int col_right = played_col + 1; col_right < width; col_right++) {
        loop = col_right - played_col;
        if (board[played_row][col_right].taken != player_id)
            break;
        disp_hori_bar(settings, corner_x + (width_offset * loop), corner_y);
    }
}

static void disp_vert_bar(settings_t *settings, int corner_x, int corner_y)
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

void check_vertical_bar(settings_t *settings,
    int corner_x, int corner_y, int height_offset)
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
        disp_vert_bar(settings, corner_x, corner_y - (height_offset * loop));
    }
    for (int row_above = played_row + 1; row_above < height; row_above++) {
        loop = row_above - played_row;
        if (board[row_above][played_col].taken != player_id)
            break;
        disp_vert_bar(settings, corner_x, corner_y + (height_offset * loop));
    }
}

static void diagonal_bar(settings_t *settings,
    int corner_x, int corner_y, int diago)
{
    if (diago > 0)
        mvwaddstr(settings->screen, corner_y, corner_x, "╲");
    else
        mvwaddstr(settings->screen, corner_y, corner_x, "╱");
    return;
}

void disp_finish_bar(settings_t *settings, int hori, int verti, int diagos)
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
    if (hori != 0)
        check_horizontal_bar(settings, corner_x, corner_y, props[0] + 1);
    if (verti != 0)
        check_vertical_bar(settings, corner_x, corner_y, props[1] + 1);
    if (diagos != 0)
        diagonal_bar(settings, corner_x, corner_y, diagos);
    if (has_colors() == true)
        wattroff(screen, COLOR_PAIR(color));
    return;
}
