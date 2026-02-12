/*
** EPITECH PROJECT, 2026
** wait_for_next_move
** File description:
** waits until a valid key has been pressed, and executes it
*/

#include <stdio.h>
#include <stdlib.h>

#include "config.h"

static int is_valid_key(int *key)
{
    if (key >= '1' && key <= '7')
        return 1;
    return 0;
}

int add_token_in_row(int key, cell_t **board)
{
    int column = key - '0' - 1;
    int row = 5;

    while (row >= 0) {
        if ((board[row][column]).taken == 0) {
            board[row][column].taken = 1;
            return 1;
        }
        row--;
    }
    return 0;
}

static int do_action(int key, cell_t **board)
{
    int exit_key = 'q';

    if (key == exit_key || key + 32 == exit_key) {
        endwin();
        return 1;
    }
    if (is_valid_key(&key) == 1) {
        return add_token_in_row(key, board);
    }
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
