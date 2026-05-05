/*
** EPITECH PROJECT, 2026
** connect4
** File description:
** gets to the next turn
*/

#include "config.h"

void next_turn(int *current_turn, int nb_players)
{
    if (*current_turn == nb_players)
        *current_turn = 0;
    *current_turn += 1;
    return;
}
