/*
** EPITECH PROJECT, 2026
** connect4
** File description:
** functions to create the different patterns for the tokens of a player
** second part
*/

#include <stdlib.h>
#include <wchar.h>

#include "config.h"
#include "my.h"

wchar_t **four_pattern(wchar_t **pattern, int width, int height)
{
    int middle_x = width / 2;
    int pos_corner_x = 0;
    int pos_corner_y = 0;
    int space = 2;

    if (height == 3)
        space = 1;
    pos_corner_y = height - space;
    pos_corner_x = space;
    pattern[pos_corner_y][pos_corner_x] = L'╰';
    for (int pos_x = pos_corner_x + 1; pos_x < width - space; pos_x++)
        pattern[pos_corner_y][pos_x] = L'─';
    for (int pos_y = pos_corner_y - 1; pos_y >= 0; pos_y--) {
        pattern[pos_y][pos_corner_x] = L'│';
        pattern[pos_y + space][middle_x + 1] = L'│';
    }
    return pattern;
}

wchar_t **cute_cube_pattern(wchar_t **pattern, int width, int height)
{
    size_t nb_corners_in_square = 4;
    wchar_t *corners = malloc(sizeof(wchar_t) * (nb_corners_in_square));
    int middle_x = width / 2;
    int space_left = height - 2;

    corners[0] = L'◸';
    corners[1] = L'◹';
    corners[2] = L'◺';
    corners[3] = L'◿';
    pattern = make_a_square_with_corners(pattern, corners, width, height);
    free(corners);
    if (height >= 4) {
        pattern[height - 2][middle_x] = L'▫';
        space_left -= 1;
    }
    if (space_left >= 3)
        space_left -= 1;
    pattern[space_left][middle_x - space_left] = L'■';
    pattern[space_left][middle_x + space_left] = L'■';
    return pattern;
}
