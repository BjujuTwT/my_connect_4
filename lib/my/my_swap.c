/*
** EPITECH PROJECT, 2025
** my_swap
** File description:
** Task1, swaps the content of two integers, whose
** addresses are given as parameters
*/

void my_swap(int *a, int *b)
{
    int x;

    x = *a;
    *a = *b;
    *b = x;
}
