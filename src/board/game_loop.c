/*
** EPITECH PROJECT, 2026
** connect4
** File description:
** game loop function, loops the program until it has to end
*/

#include "config.h"

void game_loop(settings_t *settings)
{
    while (isendwin() == FALSE) {
        werase(settings->screen);
        display_ncurses(settings);
        wrefresh(settings->screen);
        wait_for_next_move(settings);
    }
    return;
}
