/*
** EPITECH PROJECT, 2026
** connect4
** File description:
** parses the score file and updates it
*/

#include <stdio.h>
#include <stdlib.h>

#include "config.h"

static void update_scores_from_last_game
(scores_t *score_list, int player_won)
{
    switch (player_won) {
        case (1):
            score_list->p1 += 1;
            break;
        case (2):
            score_list->p2 += 1;
            break;
        case (3):
            score_list->p3 += 1;
            break;
        case (4):
            score_list->p4 += 1;
            break;
    }
    return;
}

static scores_t *init_scores_from_game(settings_t *settings)
{
    scores_t *curr_scores = malloc(sizeof(scores_t));

    curr_scores->p1 = 0;
    curr_scores->p2 = 0;
    if (settings->nb_players >= 3)
        curr_scores->p3 = 0;
    else
        curr_scores->p3 = -1;
    if (settings->nb_players >= 4)
        curr_scores->p4 = 0;
    else
        curr_scores->p4 = -1;
    update_scores_from_last_game(curr_scores, settings->is_ended);
    return curr_scores;
}

static scores_t *init_scores_from_file(settings_t *settings)
{
    FILE *fd = fopen(SCORE_PATH, "rb");
    scores_t *curr_scores = malloc(sizeof(scores_t));

    fread(curr_scores, sizeof(scores_t), 1, fd);
    fclose(fd);
    if (settings->nb_players >= 3 && curr_scores->p3 == -1)
        curr_scores->p3 = 0;
    if (settings->nb_players >= 4 && curr_scores->p4 == -1)
        curr_scores->p4 = 0;
    update_scores_from_last_game(curr_scores, settings->is_ended);
    return curr_scores;
}

static void update_score_file(scores_t *current_scores)
{
    FILE *fd = fopen(SCORE_PATH, "wb");

    if (fd == NULL) {
        free(current_scores);
        return;
    }
    fwrite(current_scores, sizeof(scores_t), 1, fd);
    fclose(fd);
    free(current_scores);
    return;
}

void handle_scores(settings_t *settings)
{
    scores_t *current_scores;

    if (verify_scores(0) < 0) {
        current_scores = init_scores_from_game(settings);
    } else
        current_scores = init_scores_from_file(settings);
    if (current_scores == NULL)
        return;
    return update_score_file(current_scores);
}
