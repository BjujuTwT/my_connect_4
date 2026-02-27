/*
** EPITECH PROJECT, 2026
** disp_finish_bar
** File description:
** displays the bar between tokens when a game is finished
*/

#include <stdlib.h>

#include "config.h"

void disp_hori_bar(settings_t *settings, int corner_x, int corner_y)
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

void disp_vert_bar(settings_t *settings, int corner_x, int corner_y)
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

void disp_diago_bar(settings_t *settings,
    int corner_x, int corner_y, int diag)
{
    char *chr = malloc(sizeof("⟋"));
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
        check_hori(settings, corner_x, corner_y, props[0] + 1);
    if (verti != 0)
        check_verti(settings, corner_x, corner_y, props[1] + 1);
    if (diagos != 0)
        check_diago(settings, row, col, diagos);
    if (has_colors() == true)
        wattroff(screen, COLOR_PAIR(color));
    return;
}
