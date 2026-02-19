/*
** EPITECH PROJECT, 2026
** display_stand
** File description:
** displays the stand right bellow the board
*/

#include <stdlib.h>

#include "config.h"

static void stand_number(WINDOW *screen, int cell_w,
    int column_number, int column_filled)
{
    for (int cell_i = 1; cell_i < cell_w; cell_i++) {
        waddstr(screen, " ");
        if (cell_w / 2 == cell_i && column_filled == 0)
            wprintw(screen, "%i", column_number);
    }
    if (column_filled != 0)
        waddstr(screen, " ");
    waddstr(screen, "│");
    return;
}

void display_arrow(settings_t *settings, int cell_w, int line_arrow)
{
    int trn = settings->player_turn;
    ll_player_info_t *player = get_player_from_turn(settings->player_info, trn);
    int color = player->color;
    WINDOW *screen = settings->screen;
    int arrow_column = settings->col_arrow;
    int offset = settings->proportions[2];
    int coord_x = (cell_w + 1) * (arrow_column - 1) + (cell_w / 2) + 1 + offset;

    if (arrow_column <= 0 || is_board_filled(settings) == 1)
        return;
    if (has_colors() == true)
        wattron(screen, COLOR_PAIR(color));
    mvwaddstr(screen, line_arrow, coord_x, "🠵");
    if (has_colors() == true)
        wattroff(screen, COLOR_PAIR(color));
    return;
}

void display_stand(WINDOW *screen, settings_t *settings)
{
    int width = settings->width;
    int height = settings->height;
    int cell_w = settings->proportions[0];
    int cell_h = settings->proportions[1];
    int offset = settings->proportions[2];
    int line_stand = cell_h * height + height;
    int column_filled = 0;

    waddstr(screen, "╮");
    mvwaddstr(screen, line_stand, offset - 1, "╭");
    mvwaddstr(screen, line_stand + 1, offset - 1, "╰│");
    for (int cell_nb = 0; cell_nb < width; cell_nb++) {
        column_filled = (settings->board)[0][cell_nb].taken;
        stand_number(screen, cell_w, cell_nb + 1, column_filled);
    }
    waddstr(screen, "╯");
    display_arrow(settings, cell_w, line_stand + 2);
    return;
}
