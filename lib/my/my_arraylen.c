/*
** EPITECH PROJECT, 2025
** my_arraylen
** File description:
** returns the length of an array
*/
#include <stddef.h>

int my_arraylen(char **array)
{
    int S = 0;

    for (int i = 0; array[i] != NULL; i++)
        S += 1;
    return S;
}
