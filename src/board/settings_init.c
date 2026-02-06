/*
** EPITECH PROJECT, 2026
** settings_init.c
** File description:
** initialisation of the board
*/

#include <stdlib.h>

#include "config.h"

static void ncurses_init(settings_t *settings)
{
    WINDOW *screen = initscr();
    size_t width = settings->width;
    size_t height = settings->height;

    noecho();
    nodelay(screen, true);
    if (has_colors() == true) {
        start_color();
        use_default_colors();
    }
    settings->screen = screen;
    settings->board = malloc(sizeof(cell_t *) * height);
    for (size_t i = 0; i < height; i++)
        (settings->board)[i] = malloc(sizeof(cell_t) * width);
    return;
}

settings_t init(char mode)
{
    settings_t settings;

    if (mode == 'h' || mode == 'f') {
        settings.to_terminate = display_help(mode);
        return settings;
    }
    settings.to_terminate = 0;
    settings.height = 6;
    settings.width = 7;
    settings.nb_players = 2;
    settings.player_turn = 1;
    ncurses_init(&settings);
    return settings;
}
