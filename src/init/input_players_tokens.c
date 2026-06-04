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

static int is_end_of_selection(settings_t *settings, int key)
{
    if (key == ' ') {
        if (settings->nb_players < 2)
            return 0;
        else
            return 1;
    }
    if (settings->nb_players == MAX_PLAYERS)
        return 1;
    return 0;
}

static void player_input_loop(settings_t *settings, int i_token, int i_color)
{
    int curr_line = 1;
    int key = 0;

    while (is_end_of_selection(settings, key) == 0) {
        key = wgetch(settings->screen);
        if (my_lowercase(key) == KEY_EXIT1 || my_lowercase(key) == KEY_EXIT2) {
            settings->to_terminate = 1;
            return;
        }
        if ((key < KEY_DOWN || key > KEY_RIGHT) && key != '\n')
            continue;
        if (key == '\n')
            init_new_player(settings, i_token, i_color);
        if (settings->nb_players < MAX_PLAYERS) {
            handle_index_keys(&i_token, &i_color, &curr_line, key);
            display_token_screen(settings, i_token, i_color, curr_line);
        }
        wrefresh(settings->screen);
    }
    return;
}

void setup_players_tokens(settings_t *settings)
{
    int *prop = settings->proportions;
    int token_start = 1;
    int color_start = 1;

    settings->pattern_list = create_pattern_list(prop[0], prop[1], color_start);
    display_token_screen(settings, token_start, color_start, 1);
    wrefresh(settings->screen);
    player_input_loop(settings, token_start, color_start);
    destroy_players(settings->pattern_list);
    return;
}
