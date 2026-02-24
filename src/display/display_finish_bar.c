/*
** EPITECH PROJECT, 2026
** disp_finish_bar
** File description:
** displays the bar between tokens when a game is finished
*/

#include "config.h"

void my_disp_diagonal(settings_t *settings,
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

    if (has_colors() == true)
        wattron(screen, COLOR_PAIR(color));
    if (hori != 0)
        mvwaddstr(settings->screen, corner_y, corner_x, "─");
    if (verti != 0)
        mvwaddstr(settings->screen, corner_y, corner_x, "│");
    if (diagos != 0)
        my_disp_diagonal(settings, corner_x, corner_y, diagos);
    if (has_colors() == true)
        wattroff(screen, COLOR_PAIR(color));
    return;
}
