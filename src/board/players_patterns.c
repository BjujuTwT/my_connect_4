/*
** EPITECH PROJECT, 2026
** players_patterns
** File description:
** functions to setup the different patterns for the tokens of each player
*/

#include <stdlib.h>
#include <uchar.h>

#include "config.h"
#include "my.h"

static wchar_t **cross_pattern(wchar_t **pattern, int width, int height)
{
    int middle_x = width / 2 + 1 - 1;
    int middle_y = height / 2 + 1 - 1;

    pattern[middle_y][middle_x] = L'╳';
    for (int offset = 1; offset <= middle_y; offset++) {
        pattern[middle_y - offset][middle_x - offset] = L'╲';
        pattern[middle_y + offset][middle_x - offset] = L'╱';
        pattern[middle_y - offset][middle_x + offset] = L'╱';
        pattern[middle_y + offset][middle_x + offset] = L'╲';
    }
    return pattern;
}

static wchar_t **malloc_pattern(int width, int height)
{
    wchar_t **pattern = NULL;

    pattern = malloc(sizeof(wchar_t *) * (size_t)(height + 1));
    for (int i = 0; i < height; i++) {
        pattern[i] = malloc(sizeof(wchar_t) * (size_t)(width + 1));
        for (int j = 0; j < width; j++)
            pattern[i][j] = L' ';
        pattern[i][width] = L'\0';
    }
    pattern[height] = NULL;
    return pattern;
}

void setup_players_patterns(ll_player_info_t *player_info, int *proportions)
{
    int width = proportions[0];
    int height = proportions[1];
    wchar_t **pattern_p1 = malloc_pattern(width, height);
    wchar_t **pattern_p2 = malloc_pattern(width, height);

    pattern_p1 = cross_pattern(pattern_p1, width, height);
    pattern_p2 = cross_pattern(pattern_p2, width, height);
    player_info->pattern = pattern_p1;
    player_info->next->pattern = pattern_p2;
    return;
}
