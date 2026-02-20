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

static int do_action(int key, settings_t *settings, int width)
{
    int *arrow_pos = &(settings->col_arrow);
    cell_t **board = settings->board;
    int exit_1 = 'q';
    int exit_2 = 'a';

    if (key == -1)
        return 0;
    if (check_exit_key(key, exit_1) == 1 || check_exit_key(key, exit_2) == 1) {
        endwin();
        return 1;
    }
    if ((key >= '1' && key <= '7') || key == '\n')
        return add_token_in_col(key, board, arrow_pos, settings->player_turn);
    if (key == KEY_LEFT || key == KEY_RIGHT)
        return move_arrow(key, board, arrow_pos, width);
    return 0;
}

void wait_for_next_move(settings_t *settings)
{
    WINDOW *screen = settings->screen;
    int key_pressed = 0;
    int sleep_interval = 50;
    int width = settings->width;

    flushinp();
    while (key_pressed == 0) {
        napms(sleep_interval);
        key_pressed = do_action(wgetch(screen), settings, width);
    }
    if (key_pressed == 2)
        next_turn(&(settings->player_turn), settings->nb_players);
    return;
}
