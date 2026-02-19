/*
** EPITECH PROJECT, 2026
** display_ncurses
** File description:
** displays all the things in the window, for ncurses
*/

#include "config.h"

void display_ncurses(settings_t *settings)
{
    WINDOW *screen = settings->screen;

    display_board(screen, settings);
    display_stand(screen, settings);
    display_cells(settings);
    return;
}
