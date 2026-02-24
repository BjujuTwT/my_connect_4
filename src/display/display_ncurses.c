/*
** EPITECH PROJECT, 2026
** display_ncurses
** File description:
** displays all the things in the window, for ncurses
*/

#include <stdlib.h>

#include "config.h"

void display_ncurses(settings_t *settings)
{
    WINDOW *screen = settings->screen;

    display_board(screen, settings);
    display_stand(screen, settings);
    display_cells(settings);
    if (settings->last_played[0] >= 0 && settings->last_played[1] >= 0)
        check_connected(settings);
    return;
}
