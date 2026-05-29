/*
** EPITECH PROJECT, 2026
** connect4
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

static int handle_other_flags(char mode)
{
    if (mode == 'h' || mode == 'f')
        return display_help(mode);
    if (mode == 's')
        return display_scores();
    return 0;
}

void setup_basic_settings(settings_t *settings)
{
    size_t width = 7;
    size_t height = 6;
    size_t dimensions = 2;

    settings->width = (int)width;
    settings->height = (int)height;
    settings->col_arrow = (int)width / 2 + 1;
    settings->player_turn = 1;
    settings->last_played = malloc(sizeof(int) * dimensions);
    (settings->last_played[0]) = -1;
    (settings->last_played[1]) = -1;
    settings->is_ended = -1;
    settings->restart = 0;
    settings->board = malloc(sizeof(cell_t *) * height);
    for (size_t i = 0; i < height; i++)
        (settings->board)[i] = init_cell_row(width);
    return;
}

settings_t init(char mode)
{
    settings_t settings;

    setlocale(LC_ALL, "");
    settings.to_terminate = handle_other_flags(mode);
    if (settings.to_terminate != 0)
        return settings;
    setup_basic_settings(&settings);
    if (mode == 'n')
        ncurses_init(&settings);
    if (mode == 'c')
        csfml_init(&settings);
    return settings;
}
