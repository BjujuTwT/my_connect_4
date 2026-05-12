/*
** EPITECH PROJECT, 2026
** connect4
** File description:
** all functions to setup the window's size, by asking the user
*/

#include <stdlib.h>
#include <stdio.h>

#include "my.h"
#include "config.h"

static void display_request
(WINDOW *screen, int x_max, int y_max)
{
    char msg1[] = "Window size?\0";
    char msg2[] = "Number between 1 and 4 (default : 'ENTER') :\0";
    int x_pos = 0;
    int y_pos = 0;

    werase(screen);
    x_pos = x_max / 2 - my_strlen(msg1) / 2;
    y_pos = y_max / 2 - 1;
    mvwaddstr(screen, y_pos, x_pos, msg1);
    x_pos = x_max / 2 - my_strlen(msg2) / 2;
    y_pos += 1;
    mvwaddstr(screen, y_pos, x_pos, msg2);
    wrefresh(screen);
    return;
}

static void verify_size_is_possible
(int *input, int curr_width, int curr_height, settings_t *settings)
{
    int size_index = *input - '0' - 1;
    int offset = 1;
    int input_x = (size_index * 2 + 8) * settings->width + offset * 2 + 1;
    int input_y = (size_index + 4) * settings->height + 3;
    char msg[] = "Please enter a smaller size\0";
    int msg_pos_x = 0;
    int msg_pos_y = 0;

    input_x += OFFSET_NEXT_MOVE_X + (size_index * 2 + 9);
    if (input_x <= curr_width && input_y <= curr_height)
        return;
    *input = -1;
    display_request(settings->screen, curr_width, curr_height);
    msg_pos_x = curr_width / 2 - my_strlen(msg) / 2;
    msg_pos_y = curr_height / 2 + 1;
    mvwaddstr(settings->screen, msg_pos_y, msg_pos_x, msg);
    wrefresh(settings->screen);
    return;
}

static int get_size_from_user(settings_t *settings)
{
    int curr_width = 0;
    int curr_height = 0;
    int size = -1;

    get_window_size(settings->screen, &curr_width, &curr_height);
    display_request(settings->screen, curr_width, curr_height);
    while (size < MINIMUM_RESOLUTION || size > MAXIMUM_RESOLUTION) {
        size = my_lowercase(wgetch(settings->screen));
        if (size == KEY_EXIT1 || size == KEY_EXIT2)
            return -1;
        if (size == '\n')
            size = DEFAULT_RESOLUTION;
        if (size < '0' || size > '9')
            continue;
        get_window_size(settings->screen, &curr_width, &curr_height);
        verify_size_is_possible(&size, curr_width, curr_height, settings);
    }
    size = size - '0' - 1;
    return size;
}

void setup_window_size(settings_t *settings)
{
    size_t dimensions = 2 + 1;
    int size = get_size_from_user(settings);

    if (size == -1) {
        endwin();
        settings->to_terminate = -1;
        return;
    }
    settings->proportions = malloc(sizeof(int) * dimensions);
    settings->proportions[0] = size * 2 + 7;
    settings->proportions[1] = size + 3;
    settings->proportions[2] = 1;
    return;
}
