/*
** EPITECH PROJECT, 2026
** connect4
** File description:
** User input functions to prepare every player's token
*/

#include <stdlib.h>

#include "config.h"
#include "my.h"
#include "macro_colors.h"

static ll_player_info_t *create_pattern_list(int width, int height)
{
    ll_player_info_t *pattern_list = NULL;
    ll_player_info_t *ptr = NULL;
    wchar_t **next_pattern = NULL;

    for (int i = 7; i > 0; i--) {
        ptr = malloc(sizeof(ll_player_info_t));
        next_pattern = get_pattern_from_index(i, width, height);
        ptr->pattern = next_pattern;
        ptr->color = PAIR_WHITE;
        ptr->next = pattern_list;
        pattern_list = ptr;
    }
    return pattern_list;
}

static void handle_index_keys(int *curr_index, int key)
{
    if (key == KEY_LEFT)
        *curr_index -= 1;
    if (key == KEY_RIGHT)
        *curr_index += 1;
    if (*curr_index == 0)
        *curr_index = 7;
    if (*curr_index == 8)
        *curr_index = 1;
    return;
}

static void display_choice(settings_t *settings, int x, int y, int index)
{
    ll_player_info_t *pattern_list = settings->pattern_list;
    ll_player_info_t *ptr = pattern_list;

    if (index == 0)
        index = 7;
    if (index == 8)
        index = 1;
    for (int count = 1; count != index; count++)
        ptr = ptr->next;
    display_box_coordinates(settings, x, y);
    display_pattern_coordinates(settings, x + 1, y + 1, ptr);
}

static void display_screen(settings_t *settings, int index)
{
    int *prop = settings->proportions;
    int x = 0;
    int y = 0;
    int distance_x = 0;
    int spaces = 5;

    werase(settings->screen);
    get_window_size(settings->screen, &x, &y);
    x = (x / 2) - (prop[0] / 2 + 1);
    y = (y / 2) - (prop[1] / 2 + 1);
    distance_x = prop[0] + spaces + 2;
    display_choice(settings, x - distance_x, y, index - 1);
    display_choice(settings, x, y, index);
    display_choice(settings, x + distance_x, y, index + 1);
    wrefresh(settings->screen);
    return;
}

void setup_players_tokens(settings_t *settings)
{
    int *prop = settings->proportions;
    int current_i = 1;
    int key = 0;

    settings->pattern_list = create_pattern_list(prop[0], prop[1]);
    display_screen(settings, current_i);
    while (key != '\n') {
        key = wgetch(settings->screen);
        if (my_lowercase(key) == KEY_EXIT1 || my_lowercase(key) == KEY_EXIT2) {
            settings->to_terminate = 1;
            return;
        }
        if ((key == '\n' && key != KEY_LEFT && key != KEY_RIGHT) || key == -1)
            continue;
        handle_index_keys(&current_i, key);
        display_screen(settings, current_i);
    }
    return;
}
