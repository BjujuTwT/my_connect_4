/*
** EPITECH PROJECT, 2026
** connect4
** File description:
** functions to create the different patterns for the tokens of a player
*/

#include <stdlib.h>
#include <wchar.h>

#include "config.h"
#include "my.h"

static wchar_t **even_cross_pattern(wchar_t **pattern, int width, int height)
{
    int middle_x = width / 2;
    int lower_y = height / 2 - 1;
    int higher_y = height / 2;
    int offset_x = 1;
    int offset_y = 1;

    for (; offset_x < middle_x; offset_x += 2) {
        pattern[lower_y - offset_y + 1][middle_x - offset_x] = L'╲';
        pattern[higher_y + offset_y - 1][middle_x - offset_x] = L'╱';
        pattern[lower_y - offset_y + 1][middle_x + offset_x] = L'╱';
        pattern[higher_y + offset_y - 1][middle_x + offset_x] = L'╲';
        offset_y++;
    }
    return pattern;
}

wchar_t **cross_pattern(wchar_t **pattern, int width, int height)
{
    int middle_x = width / 2;
    int middle_y = height / 2;

    if (height % 2 == 0)
        return even_cross_pattern(pattern, width, height);
    pattern[middle_y][middle_x] = L'╳';
    for (int offset = 1; offset <= middle_y; offset++) {
        pattern[middle_y - offset][middle_x - offset] = L'╲';
        pattern[middle_y + offset][middle_x - offset] = L'╱';
        pattern[middle_y - offset][middle_x + offset] = L'╱';
        pattern[middle_y + offset][middle_x + offset] = L'╲';
    }
    return pattern;
}

wchar_t **circle_pattern(wchar_t **pattern, int width, int height)
{
    size_t nb_corners_in_square = 4;
    wchar_t *corners = malloc(sizeof(wchar_t) * (nb_corners_in_square));

    corners[0] = L'╭';
    corners[1] = L'╮';
    corners[2] = L'╰';
    corners[3] = L'╯';
    pattern = make_a_square_with_corners(pattern, corners, width, height);
    free(corners);
    return pattern;
}

wchar_t **triangle_pattern(wchar_t **pattern, int width, int height)
{
    int middle_x = width / 2;
    int offset = 1;

    for (int i = 0; i + 1 < height; i++) {
        pattern[i][middle_x - offset] = L'╱';
        pattern[i][middle_x + offset] = L'╲';
        offset++;
    }
    for (int j = 1; j + 1 < width; j++)
        pattern[height - 1][j] = L'─';
    return pattern;
}

wchar_t **square_pattern(wchar_t **pattern, int width, int height)
{
    size_t nb_corners_in_square = 4;
    wchar_t *corners = malloc(sizeof(wchar_t) * (nb_corners_in_square));

    corners[0] = L'╱';
    corners[1] = L'╲';
    corners[2] = L'╲';
    corners[3] = L'╱';
    pattern = make_a_square_with_corners(pattern, corners, width, height);
    free(corners);
    return pattern;
}

wchar_t **arrow_pattern(wchar_t **pattern, int width, int height)
{
    int middle_x = width / 2;
    int middle_y = height / 2 + height % 2;
    int offset = 1;

    for (; offset <= width / 4; offset++) {
        pattern[offset - 1][middle_x - offset] = L'╱';
        pattern[offset - 1][middle_x + offset] = L'╲';
        pattern[middle_y + offset - 1][middle_x - offset] = L'╱';
        pattern[middle_y + offset - 1][middle_x + offset] = L'╲';
    }
    if (height % 2 == 1) {
        pattern[middle_y - height % 2][middle_x - offset] = L'╱';
        pattern[middle_y - height % 2][middle_x + offset] = L'╲';
    }
    return pattern;
}
