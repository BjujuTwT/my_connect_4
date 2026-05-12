/*
** EPITECH PROJECT, 2026
** connect4
** File description:
** display a given player's pattern at given coordinates
*/

#include <stddef.h>

#include "config.h"

void display_pattern_coordinates(settings_t *settings,
    int x, int y, ll_player_info_t *player_info)
{
    WINDOW *screen = settings->screen;
    wchar_t **pattern = player_info->pattern;
    int color = player_info->color;

    if (has_colors() == true)
        wattron(screen, COLOR_PAIR(color));
    for (int i = 0; pattern[i] != NULL; i++)
        mvwprintw(screen, y + i, x, "%ls", pattern[i]);
    if (has_colors() == true)
        wattroff(screen, COLOR_PAIR(color));
    return;
}
