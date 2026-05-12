/*
** EPITECH PROJECT, 2026
** connect4
** File description:
** displays the box of a cell at given coordinates
*/

#include "config.h"

void display_box_coordinates(settings_t *settings, int x, int y)
{
    int cell_width = settings->proportions[0];
    int cell_height = settings->proportions[1];
    WINDOW *screen = settings->screen;

    mvwaddstr(screen, y, x, "╔");
    for (int cell_x = 0; cell_x < cell_width; cell_x++)
        waddstr(screen, "─");
    waddstr(screen, "╗");
    for (int cell_y = 0; cell_y < cell_height; cell_y++) {
        mvwaddstr(screen, y + cell_y + 1, x, "│");
        for (int cell_x = 0; cell_x < cell_width; cell_x++)
            waddstr(screen, " ");
        waddstr(screen, "│");
    }
    mvwaddstr(screen, y + cell_height + 1, x, "╚");
    for (int cell_x = 0; cell_x < cell_width; cell_x++)
        waddstr(screen, "─");
    waddstr(screen, "╝");
}
