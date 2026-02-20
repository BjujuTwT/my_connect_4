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

static cell_t *init_cell_row(size_t width)
{
    cell_t *cell = NULL;

    cell = malloc(sizeof(cell_t) * width);
    for (size_t i = 0; i < width; i++)
        cell[i].taken = 0;
    return cell;
}

static ll_player_info_t *setup_players_struct(int nb_players)
{
    ll_player_info_t *player_info = NULL;

    player_info = malloc(sizeof(ll_player_info_t));
    player_info->index = 1;
    player_info->color = 1;
    player_info->next = NULL;
    if (nb_players == 2) {
        player_info->next = malloc(sizeof(ll_player_info_t));
        player_info->next->index = 2;
        player_info->next->color = 2;
        player_info->next->next = NULL;
    }
    return player_info;
}

static void basic_settings(settings_t *settings)
{
    size_t width = 7;
    size_t height = 6;

    settings->width = (int)width;
    settings->height = (int)height;
    settings->col_arrow = (int)width / 2 + 1;
    settings->nb_players = 2;
    settings->player_turn = 1;
    settings->board = malloc(sizeof(cell_t *) * height);
    for (size_t i = 0; i < height; i++)
        (settings->board)[i] = init_cell_row(width);
    settings->player_info = setup_players_struct(settings->nb_players);
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
