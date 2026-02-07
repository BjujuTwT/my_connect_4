/*
** EPITECH PROJECT, 2026
** settings_init.c
** File description:
** initialisation of the board
*/

#include <stdlib.h>
#include <locale.h>

#include "macro_colors.h"
#include "config.h"

static void ncurses_init(settings_t *settings)
{
    WINDOW *screen;
    size_t width = settings->width;
    size_t height = settings->height;

    display_help_examples(1);
    screen = initscr();
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

static void csfml_init(settings_t *settings)
{
    display_help_examples(2);
    settings->to_terminate = 1;
    display_color("\nThis option hasn't been implemented yet.\n", CRIMSON, 2);
    return;
}

settings_t init(char mode)
{
    settings_t settings;

    setlocale(LC_ALL, "");
    if (mode == 'h' || mode == 'f') {
        settings.to_terminate = display_help(mode);
        return settings;
    }
    settings.to_terminate = 0;
    settings.height = 6;
    settings.width = 7;
    settings.nb_players = 2;
    settings.player_turn = 1;
    if (mode == 'n')
        ncurses_init(&settings);
    if (mode == 'c')
        csfml_init(&settings);
    return settings;
}
