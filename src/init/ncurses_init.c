/*
** EPITECH PROJECT, 2026
** connect4
** File description:
** init function for the general structure csfml-orientated
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#include "config.h"
#include "macro_colors.h"

static void color_init(void)
{
    start_color();
    use_default_colors();
    init_pair(PAIR_WHITE, COLOR_WHITE, -1);
    init_color(COLOR_RED, 1000, 106, 59);
    init_pair(PAIR_RED, COLOR_RED, -1);
    init_color(COLOR_YELLOW, 1000, 909, 231);
    init_pair(PAIR_YELLOW, COLOR_YELLOW, -1);
    init_color(COLOR_BLUE, 145, 282, 557);
    init_pair(PAIR_BLUE, COLOR_BLUE, -1);
    init_color(COLOR_GREEN, 80, 600, 0);
    init_pair(PAIR_GREEN, COLOR_GREEN, -1);
    init_pair(PAIR_PURPLE, COLOR_MAGENTA, -1);
    init_color(COLOR_CYAN, 78, 471, 784);
    init_pair(PAIR_CYAN, COLOR_CYAN, -1);
    init_color(COLOR_BLACK, 271, 271, 271);
    init_pair(PAIR_PREVIEW, COLOR_BLACK, -1);
    return;
}

static void setup_with_user_inputs(settings_t *settings)
{
    int is_default = setup_window_size(settings);

    if (settings->to_terminate != 0) {
        endwin();
        return;
    }
    settings->player_info = NULL;
    settings->nb_players = 0;
    if (is_default == 1)
        setup_players_struct(settings);
    else
        setup_players_tokens(settings);
    if (settings->to_terminate != 0)
        endwin();
    return;
}

void ncurses_init(settings_t *settings)
{
    WINDOW *screen = NULL;

    display_help_examples(1);
    screen = initscr();
    noecho();
    keypad(screen, true);
    nodelay(screen, true);
    curs_set(0);
    if (has_colors() == true)
        color_init();
    settings->screen = screen;
    setup_with_user_inputs(settings);
    return;
}
