/*
** EPITECH PROJECT, 2026
** connect4
** File description:
** displays all the things in the window, for ncurses
** also handles the end of the game to display it,
** cause you can only do so after displaying the cells,
*/

#include <stdlib.h>

#include "config.h"

void display_ncurses(settings_t *settings)
{
    WINDOW *screen = settings->screen;

    display_board(screen, settings);
    display_cells(settings);
    if (settings->last_played[0] >= 0 && settings->last_played[1] >= 0) {
        check_connected(settings);
        if (settings->is_ended != -1)
            settings->col_arrow = -1;
    }
    display_stand(settings, screen);
    display_preview(settings, screen);
    return;
}
