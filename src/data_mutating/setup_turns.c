/*
** EPITECH PROJECT, 2026
** setup_turns
** File description:
** all functions related to setting up turns or getting to the next one
*/

#include "config.h"

void next_turn(int *current_turn, int nb_players)
{
    if (*current_turn == nb_players)
        *current_turn = 0;
    *current_turn += 1;
    return;
}
