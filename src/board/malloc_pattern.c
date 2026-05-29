/*
** EPITECH PROJECT, 2026
** connect4
** File description:
** allocates memory to a new pattern
*/

#include <stdlib.h>

#include "config.h"

wchar_t **malloc_pattern(int width, int height)
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
