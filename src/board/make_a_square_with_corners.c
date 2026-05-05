/*
** EPITECH PROJECT, 2026
** connect4
** File description:
** makes a square shaped pattern with given corners
*/

#include <wchar.h>

wchar_t **make_a_square_with_corners
(wchar_t **pattern, wchar_t *corners, int width, int height)
{
    for (int circle_up = 1; circle_up + 1 < width; circle_up++)
        pattern[0][circle_up] = L'─';
    for (int circle_down = 1; circle_down + 1 < width; circle_down++)
        pattern[height - 1][circle_down] = L'─';
    for (int circle_left = 0; circle_left < height; circle_left++)
        pattern[circle_left][1] = L'│';
    for (int circle_right = 1; circle_right < height; circle_right++)
        pattern[circle_right][width - 2] = L'│';
    pattern[0][1] = corners[0];
    pattern[0][width - 2] = corners[1];
    pattern[height - 1][1] = corners[2];
    pattern[height - 1][width - 2] = corners[3];
    return pattern;
}
