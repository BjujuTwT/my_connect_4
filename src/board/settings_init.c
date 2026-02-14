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

void ncurses_init(settings_t *settings)
{
    WINDOW *screen;

    display_help_examples(1);
    screen = initscr();
    noecho();
    keypad(screen, true);
    nodelay(screen, true);
    curs_set(0);
    if (has_colors() == true) {
        start_color();
        use_default_colors();
    }
    settings->screen = screen;
    return;
}

void csfml_init(settings_t *settings)
{
    display_help_examples(2);
    settings->to_terminate = 1;
    display_color("This option hasn't been implemented yet.\n", CRIMSON, 2);
    return;
}

static cell_t *init_cell_row(size_t width)
{
    cell_t *cell = NULL;

    cell = malloc(sizeof(cell_t) * width);
    for (size_t i = 0; i < width; i++)
        cell[i].taken = 0;
    return cell;
}

static ll_player_info_t *setup_players_struct(settings_t *settings)
{
    ll_player_info_t *player_info = NULL;
    int nb_players = settings->nb_players;
    int *proportions = settings->proportions;

    player_info = malloc(sizeof(ll_player_info_t));
    player_info->index = 1;
    player_info->next = NULL;
    if (nb_players == 2) {
        player_info->next = malloc(sizeof(ll_player_info_t));
        player_info->next->index = 2;
        player_info->next->next = NULL;
    }
    setup_players_patterns(player_info, proportions);
    return player_info;
}

static void basic_settings(settings_t *settings)
{
    size_t dimensions = 2 + 1;
    size_t width = 7;
    size_t height = 6;

    settings->width = (int)width;
    settings->height = (int)height;
    settings->col_arrow = (int)width / 2 + 1;
    settings->nb_players = 2;
    settings->proportions = malloc(sizeof(int) * dimensions);
    settings->proportions[0] = 11;
    settings->proportions[1] = 5;
    settings->proportions[2] = 1;
    settings->board = malloc(sizeof(cell_t *) * height);
    for (size_t i = 0; i < height; i++)
        (settings->board)[i] = init_cell_row(width);
    settings->player_info = setup_players_struct(settings);
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
    basic_settings(&settings);
    if (mode == 'n')
        ncurses_init(&settings);
    if (mode == 'c')
        csfml_init(&settings);
    return settings;
}
