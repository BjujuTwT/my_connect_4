/*
** EPITECH PROJECT, 2026
** connect4
** File description:
** game loop function, loops the program until it has to end
*/

#include "config.h"

void game_loop(settings_t *settings)
{
    while (isendwin() == FALSE && settings->restart != 1) {
        werase(settings->screen);
        if (verify_window_size(settings) != 0)
            break;
        handle_ties(settings);
        display_ncurses(settings);
        if (settings->is_ended != -1) {
            handle_end_game(settings);
            break;
        }
        wait_for_next_move(settings);
    }
    return;
}
