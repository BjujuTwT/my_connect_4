/*
** EPITECH PROJECT, 2026
** connect4
** File description:
** waits until a valid key has been pressed, and executes it
*/

#include <stdio.h>
#include <stdlib.h>

#include "config.h"
#include "my.h"

static int do_action(int key, settings_t *setting, int width)
{
    int *arrow_pos = &(setting->col_arrow);
    cell_t **board = setting->board;

    if (key == -1)
        return KEY_NOTHING_PRESSED;
    if (my_lowercase(key) == KEY_EXIT1 || my_lowercase(key) == KEY_EXIT2) {
        endwin();
        return KEY_OTHER_EVENT;
    }
    if ((key >= '1' && key <= '7') || key == '\n')
        return add_token_in_col(setting, key, arrow_pos, setting->player_turn);
    if (key == KEY_LEFT || key == KEY_RIGHT)
        return move_arrow(key, board, arrow_pos, width);
    if (key == KEY_REPLAY) {
        setting->restart = 1;
        return KEY_OTHER_EVENT;
    }
    return KEY_NOTHING_PRESSED;
}

void wait_for_next_move(settings_t *settings)
{
    WINDOW *screen = settings->screen;
    int key_pressed = KEY_NOTHING_PRESSED;
    int sleep_interval = 50;
    int width = settings->width;

    flushinp();
    while (key_pressed == KEY_NOTHING_PRESSED) {
        napms(sleep_interval);
        key_pressed = do_action(wgetch(screen), settings, width);
    }
    if (key_pressed == KEY_PLAYED_EVENT)
        next_turn(&(settings->player_turn), settings->nb_players);
    return;
}
