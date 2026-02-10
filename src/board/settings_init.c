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

static ll_player_info_t *setup_players_struct(int nb_players)
{
    ll_player_info_t *player_info = NULL;

    player_info = malloc(sizeof(ll_player_info_t));
    player_info->index = 1;
    player_info->next = NULL;
    if (nb_players == 2) {
        player_info->next = malloc(sizeof(ll_player_info_t));
        player_info->next->index = 2;
        player_info->next->next = NULL;
    }
    return player_info;
}

static cell_t *init_cell_row(size_t width)
{
    cell_t *cell = NULL;

    cell = malloc(sizeof(cell_t) * width);
    for (size_t i = 0; i < width; i++)
        cell[i].taken = 0;
    return cell;
}

static void ncurses_init(settings_t *settings, int nb_players)
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
        (settings->board)[i] = init_cell_row(width);
    settings->player_info = setup_players_struct(nb_players);
    return;
}

static void csfml_init(settings_t *settings)
{
    display_help_examples(2);
    settings->to_terminate = 1;
    display_color("This option hasn't been implemented yet.\n", CRIMSON, 2);
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
        ncurses_init(&settings, settings.nb_players);
    if (mode == 'c')
        csfml_init(&settings);
    return settings;
}
