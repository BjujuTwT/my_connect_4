/*
** EPITECH PROJECT, 2026
** connect4
** File description:
** verifies if the current size is okay to display in a specific resolution
*/

#include "config.h"
#include "macro_colors.h"

int verify_window_size(settings_t *settings)
{
    int curr_width = 0;
    int curr_height = 0;
    int cell_w = settings->proportions[0];
    int cell_h = settings->proportions[1];
    int offset = settings->proportions[2];
    int min_w = (cell_w + 1) * settings->width + offset * 2 + 1;
    int min_h = (cell_h + 1) * settings->height + 3;
    char error_msg[] = "Error: Window size too small.\n\0";

    min_w += OFFSET_NEXT_MOVE_X + cell_w + 2;
    get_window_size(settings->screen, &curr_width, &curr_height);
    if (curr_width < min_w || curr_height < min_h) {
        endwin();
        display_color(error_msg, CRIMSON, 2);
        return -1;
    }
    return 0;
}
