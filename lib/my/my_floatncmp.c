/*
** EPITECH PROJECT, 2025
** my_floatncmp
** File description:
** compares the two float in parameters
** for a total of n digits,
** Returns the difference between the first
** and second parameter
*/
#include <stdio.h>
#include "my.h"

float my_floatncmp(float f1, float f2, unsigned n)
{
    int int_f1;
    int int_f2;
    int power = (int)n - my_intlen((int)f1);

    int_f1 = (int)(f1 * my_compute_power_rec(10, power));
    int_f2 = (int)(f2 * my_compute_power_rec(10, power));
    return (float)(int_f1 - int_f2) * my_compute_power_rec(10, -power);
}
