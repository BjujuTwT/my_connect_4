/*
** EPITECH PROJECT, 2026
** connect4
** File description:
** returns an allocated pattern based on its index
*/

#include "config.h"

wchar_t **get_pattern_from_index(int index, int width, int height)
{
    wchar_t **pattern = malloc_pattern(width, height);

    if (index == 1)
        pattern = cross_pattern(pattern, width, height);
    if (index == 2)
        pattern = circle_pattern(pattern, width, height);
    if (index == 3)
        pattern = triangle_pattern(pattern, width, height);
    if (index == 4)
        pattern = square_pattern(pattern, width, height);
    if (index == 5)
        pattern = arrow_pattern(pattern, width, height);
    if (index == 6)
        pattern = four_pattern(pattern, width, height);
    if (index == 7)
        pattern = cute_cube_pattern(pattern, width, height);
    return pattern;
}
