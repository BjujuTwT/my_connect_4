/*
** EPITECH PROJECT, 2026
** pattern_templates
** File description:
** functions to create the different patterns for the tokens of a player
*/

#include <stdlib.h>
#include <uchar.h>

#include "config.h"
#include "my.h"

static wchar_t **even_cross_pattern(wchar_t **pattern, int width, int height)
{
    int middle_x = width / 2 + 1 - 1;
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
    int middle_x = width / 2 + 1 - 1;
    int middle_y = height / 2 + 1 - 1;

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
    for (int circle_up = 1; circle_up + 1 < width; circle_up++)
        pattern[0][circle_up] = L'─';
    for (int circle_down = 1; circle_down + 1 < width; circle_down++)
        pattern[height - 1][circle_down] = L'─';
    for (int circle_left = 0; circle_left < height; circle_left++)
        pattern[circle_left][1] = L'│';
    for (int circle_right = 1; circle_right < height; circle_right++)
        pattern[circle_right][width - 2] = L'│';
    pattern[0][1] = L'╭';
    pattern[0][width - 2] = L'╮';
    pattern[height - 1][1] = L'╰';
    pattern[height - 1][width - 2] = L'╯';
    return pattern;
}

wchar_t **triangle_pattern(wchar_t **pattern, int width, int height)
{
    int middle_x = width / 2 + 1 - 1;
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
