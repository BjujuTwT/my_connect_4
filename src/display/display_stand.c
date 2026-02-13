/*
** EPITECH PROJECT, 2026
** display_stand
** File description:
** displays the stand right bellow the board
*/

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
    return;
}
