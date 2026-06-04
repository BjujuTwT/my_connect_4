/*
** EPITECH PROJECT, 2026
** connect4
** File description:
** displays all the necessary things on the second user input screen
*/

#include <stddef.h>

#include "config.h"
#include "my.h"
#include "macro_colors.h"

static void update_colors(settings_t *settings, int curr_color)
{
    ll_player_info_t *ptr = settings->pattern_list;

    while (ptr != NULL) {
        ptr->color = curr_color;
        ptr = ptr->next;
    }
    return;
}

static void display_middle_text
(settings_t *settings, char *text, int win_width, int win_height)
{
    int x = (win_width / 2) - (my_strlen(text) / 2);
    int y = win_height / 2;
    int id = 0;

    if (settings->player_info != NULL) {
        id = settings->player_info->index;
        if (text[INDEX_STR_PLAYER_ID] == '0')
            text[INDEX_STR_PLAYER_ID] = (char)id + '0';
    }
    mvwaddstr(settings->screen, y, x, text);
    return;
}

static void handle_middle_text
(settings_t *settings, int win_width, int win_height)
{
    char *msg = NULL;
    int color = PAIR_PREVIEW;

    if (settings->player_info != NULL) {
        color = settings->player_info->color;
        if (settings->nb_players >= 2)
            msg = my_strdup(STR_CHOICE_CAN_START);
        else
            msg = my_strdup(STR_CHOICE_ONE_PLAYER);
    } else
        msg = my_strdup(STR_CHOICE_NO_PLAYER);
    if (has_colors() == true)
        wattron(settings->screen, COLOR_PAIR(color));
    display_middle_text(settings, msg, win_width, win_height);
    if (has_colors() == true)
        wattroff(settings->screen, COLOR_PAIR(color));
    return;
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

static void display_select_arrow(settings_t *settings, int line, int color)
{
    int x = 0;
    int y = 0;

    get_window_size(settings->screen, &x, &y);
    x /= 2;
    if (line == 1)
        y = (y / 2) - SPACES_CHOICE_Y + 1;
    else
        y = (y / 2) + SPACES_CHOICE_Y + settings->proportions[1] + 2;
    if (has_colors() == true)
        wattron(settings->screen, COLOR_PAIR(color));
    mvwaddstr(settings->screen, y, x, "🠵");
    if (has_colors() == true)
        wattroff(settings->screen, COLOR_PAIR(color));
    return;
}

void display_token_screen
(settings_t *settings, int i_token, int i_color, int curr_line)
{
    int x = 0;
    int y = 0;
    int distance_x = 0;
    int distance_y = 0;

    werase(settings->screen);
    update_colors(settings, i_color);
    get_window_size(settings->screen, &x, &y);
    handle_middle_text(settings, x, y);
    x = (x / 2) - ((settings->proportions)[0] / 2 + 1);
    y = (y / 2) - ((settings->proportions)[1] / 2 + 1);
    distance_x = (settings->proportions)[0] + SPACES_CHOICE_X + 2;
    distance_y = ((settings->proportions)[1]) / 2 + SPACES_CHOICE_Y + 1;
    display_token(settings, x - distance_x, y - distance_y, i_token - 1);
    display_token(settings, x, y - distance_y, i_token);
    display_token(settings, x + distance_x, y - distance_y, i_token + 1);
    display_colour(settings, x - distance_x, y + distance_y, i_color - 1);
    display_colour(settings, x, y + distance_y, i_color);
    display_colour(settings, x + distance_x, y + distance_y, i_color + 1);
    display_select_arrow(settings, curr_line, i_color);
}
