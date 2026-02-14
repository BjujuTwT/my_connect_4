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

static int move_arrow(int key, cell_t **board, int *arrow_pos, int width)
{
    int move = 0;
    int i_pos = *arrow_pos - 1;

    if (key == KEY_LEFT)
        move = -1;
    else
        move = 1;
    i_pos += move;
    for (; i_pos >= 0 && i_pos < width; i_pos += move) {
        if (board[0][i_pos].taken == 0) {
            *arrow_pos = i_pos + 1;
            return 1;
        }
    }
    return 0;
}

static int do_action(int key, cell_t **board, int *arrow_pos, int width)
{
    int exit_1 = 'q';
    int exit_2 = 'a';

    if (key == -1)
        return 0;
    if (check_exit_key(key, exit_1) == 1 || check_exit_key(key, exit_2) == 1) {
        endwin();
        return 1;
    }
    if ((key >= '1' && key <= '9') || key == '\n')
        return add_token_in_row(key, board, arrow_pos);
    if (key == KEY_LEFT || key == KEY_RIGHT)
        return move_arrow(key, board, arrow_pos, width);
    return 0;
}

void wait_for_next_move(settings_t *settings)
{
    WINDOW *screen = settings->screen;
    cell_t **board = settings->board;
    int key_pressed = 0;
    int sleep_interval = 50;
    int *col_arrow = &(settings->col_arrow);
    int width = settings->width;

    flushinp();
    while (key_pressed == 0) {
        napms(sleep_interval);
        key_pressed = do_action(wgetch(screen), board, col_arrow, width);
    }
    return;
}
