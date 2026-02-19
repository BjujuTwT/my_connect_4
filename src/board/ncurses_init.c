/*
** EPITECH PROJECT, 2026
** ncurses_init
** File description:
** init function for the general structure csfml-orientated
*/

#include "config.h"

static void color_init(void)
{
    start_color();
    use_default_colors();
    init_color(COLOR_RED, 1000, 106, 59);
    init_pair(1, COLOR_RED, -1);
    init_color(COLOR_YELLOW, 1000, 909, 231);
    init_pair(2, COLOR_YELLOW, -1);
    init_color(COLOR_BLACK, 271, 271, 271);
    init_pair(PREVIEW_COL, COLOR_BLACK, -1);
    return;
}

void ncurses_init(settings_t *settings)
{
    WINDOW *screen;

    display_help_examples(1);
    screen = initscr();
    noecho();
    keypad(screen, true);
    nodelay(screen, true);
    curs_set(0);
    if (has_colors() == true)
        color_init();
    settings->screen = screen;
    return;
}
