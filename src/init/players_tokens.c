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

static ll_player_info_t *create_pattern_list
(int width, int height, int def_color)
{
    ll_player_info_t *pattern_list = NULL;
    ll_player_info_t *ptr = NULL;
    wchar_t **next_pattern = NULL;

    for (int i = 7; i > 0; i--) {
        ptr = malloc(sizeof(ll_player_info_t));
        next_pattern = get_pattern_from_index(i, width, height);
        ptr->pattern = next_pattern;
        ptr->color = def_color;
        ptr->next = pattern_list;
        pattern_list = ptr;
    }
    return pattern_list;
}

static void update_colors(settings_t *settings, int curr_color)
{
    ll_player_info_t *ptr = settings->pattern_list;

    while (ptr != NULL) {
        ptr->color = curr_color;
        ptr = ptr->next;
    }
    return;
}

static void handle_index_keys
(int *i_token, int *i_color, int *curr_line, int key)
{
    if (*curr_line == 1 && key == KEY_LEFT)
        *i_token -= 1;
    if (*curr_line == 1 && key == KEY_RIGHT)
        *i_token += 1;
    if (*curr_line == 2 && key == KEY_LEFT)
        *i_color -= 1;
    if (*curr_line == 2 && key == KEY_RIGHT)
        *i_color += 1;
    if (key == KEY_UP || key == KEY_DOWN)
        *curr_line = (*curr_line % 2) + 1;
    if (*i_token == 0)
        *i_token = MAX_TOKENS;
    if (*i_token > MAX_TOKENS)
        *i_token = 1;
    if (*i_color == 0)
        *i_color = MAX_COLORS;
    if (*i_color > MAX_COLORS)
        *i_color = 1;
}

static void display_token(settings_t *settings, int x, int y, int index)
{
    ll_player_info_t *pattern_list = settings->pattern_list;
    ll_player_info_t *ptr = pattern_list;

    if (index == 0)
        index = MAX_TOKENS;
    if (index > MAX_TOKENS)
        index = 1;
    for (int count = 1; count != index; count++)
        ptr = ptr->next;
    display_box_coordinates(settings, x, y);
    display_pattern_coordinates(settings, x + 1, y + 1, ptr);
}

static void display_colour(settings_t *settings, int x, int y, int index)
{
    ll_player_info_t *pattern_list = settings->pattern_list;
    ll_player_info_t *ptr = pattern_list;
    int *prop = settings->proportions;

    if (index == 0)
        index = MAX_COLORS;
    if (index > MAX_COLORS)
        index = 1;
    for (int count = 1; count != index; count++)
        ptr = ptr->next;
    display_box_coordinates(settings, x, y);
    if (has_colors() == true)
        wattron(settings->screen, COLOR_PAIR(index));
    for (int index_y = 0; index_y < prop[1]; index_y++) {
        mvwaddstr(settings->screen, y + index_y + 1, x + 1, "█");
        for (int index_x = 1; index_x < prop[0]; index_x++)
            waddstr(settings->screen, "█");
    }
    if (has_colors() == true)
        wattroff(settings->screen, COLOR_PAIR(index));
}

static void display_screen(settings_t *settings, int i_token, int i_color)
{
    int *prop = settings->proportions;
    int x = 0;
    int y = 0;
    int distance_x = 0;
    int distance_y = 0;

    werase(settings->screen);
    update_colors(settings, i_color);
    get_window_size(settings->screen, &x, &y);
    x = (x / 2) - (prop[0] / 2 + 1);
    y = (y / 2) - (prop[1] / 2 + 1);
    distance_x = prop[0] + SPACES_CHOICE_X + 2;
    distance_y = (prop[1]) / 2 + SPACES_CHOICE_Y + 1;
    display_token(settings, x - distance_x, y - distance_y, i_token - 1);
    display_token(settings, x, y - distance_y, i_token);
    display_token(settings, x + distance_x, y - distance_y, i_token + 1);
    display_colour(settings, x - distance_x, y + distance_y, i_color - 1);
    display_colour(settings, x, y + distance_y, i_color);
    display_colour(settings, x + distance_x, y + distance_y, i_color + 1);
    wrefresh(settings->screen);
}

void setup_players_tokens(settings_t *settings)
{
    int *prop = settings->proportions;
    int i_token = 1;
    int i_color = 2;
    int curr_line = 1;
    int key = 0;

    settings->pattern_list = create_pattern_list(prop[0], prop[1], i_color);
    display_screen(settings, i_token, i_color);
    while (key != '\n') {
        key = wgetch(settings->screen);
        if (my_lowercase(key) == KEY_EXIT1 || my_lowercase(key) == KEY_EXIT2) {
            settings->to_terminate = 1;
            return;
        }
        if (key < KEY_DOWN || key > KEY_RIGHT)
            continue;
        handle_index_keys(&i_token, &i_color, &curr_line, key);
        display_screen(settings, i_token, i_color);
    }
    return;
}
