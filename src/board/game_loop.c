/*
** EPITECH PROJECT, 2026
** connect4
** File description:
** game loop function, loops the program until it has to end
*/

#include "config.h"
#include "my.h"

void handle_end(void)
{
    int input = my_lowercase(getch());

    while (input != EXIT_KEY1 && input != EXIT_KEY2) {
        input = my_lowercase(getch());
    }
    endwin();
    return;
}

void game_loop(settings_t *settings)
{
    while (isendwin() == FALSE) {
        werase(settings->screen);
        display_ncurses(settings);
        if (settings->is_ended != -1) {
            handle_end();
            break;
        }
        wait_for_next_move(settings);
    }
    return;
}
