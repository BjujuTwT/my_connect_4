/*
** EPITECH PROJECT, 2026
** wait_for_next_move
** File description:
** waits until a valid key has been pressed, and executes it
*/

#include <stdio.h>
#include <stdlib.h>

#include "config.h"

static int check_exit_key(int key, int exit_key)
{
    if (key == exit_key || key == exit_key - 32)
        return 1;
    return 0;
}

static int do_action(int key, cell_t **board)
{
    int exit_1 = 'q';
    int exit_2 = 'a';

    if (key == -1)
        return 0;
    if (check_exit_key(key, exit_1) == 1 || check_exit_key(key, exit_2) == 1) {
        endwin();
        return 1;
    }
    if (key >= '1' && key <= '9')
        return add_token_in_row(key, board);
    return 0;
}

void wait_for_next_move(settings_t *settings)
{
    WINDOW *screen = settings->screen;
    cell_t **board = settings->board;
    int key_pressed = 0;
    int sleep_interval = 50;

    flushinp();
    while (key_pressed == 0) {
        napms(sleep_interval);
        key_pressed = do_action(wgetch(screen), board);
    }
    return;
}
