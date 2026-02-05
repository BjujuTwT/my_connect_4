/*
** EPITECH PROJECT, 2025
** my_compute_square_root
** File description:
** returns the square root of the number given
** as argument
*/
#include <stdio.h>

double my_compute_square_root(int nb)
{
    double sqrt = nb / 2;
    double prev = 0;

    if (nb <= 0) {
        return 0;
    }
    if (nb == 1) {
        return 1;
    }
    while (sqrt != prev) {
        prev = sqrt;
        sqrt = (nb / prev + prev) / 2;
    }
    if (sqrt * sqrt == nb) {
        return sqrt;
    } else {
        return 0;
    }
}
