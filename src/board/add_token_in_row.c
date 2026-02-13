/*
** EPITECH PROJECT, 2026
** add_token_in_row
** File description:
** adds the needed token into the deepest available row
*/

#include "config.h"

int add_token_in_row(int key, cell_t **board)
{
    int column = key - '0' - 1;
    int row = 5;

    while (row >= 0) {
        if ((board[row][column]).taken == 0) {
            board[row][column].taken = 1;
            return 1;
        }
        row--;
    }
    return 0;
}
