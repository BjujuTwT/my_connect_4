/*
** EPITECH PROJECT, 2026
** wait_for_next_move
** File description:
** waits until a valid key has been pressed, and executes it
*/

#include "config.h"

static int do_action(int key)
{
    int exit_key = 'q';
    int first_row = '1';
    int last_row = '7';

    if (key == exit_key) {
        endwin();
        return 1;
    }
    if (key >= first_row && key <= last_row)
        return 1;
    return 0;
}

void wait_for_next_move(WINDOW *screen)
{
    int key_pressed = 0;
    int sleep_interval = 50;

    flushinp();
    while (key_pressed == 0) {
        napms(sleep_interval);
        key_pressed = do_action(wgetch(screen));
    }
    return;
}
