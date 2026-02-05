/*
** EPITECH PROJECT, 2025
** my_compute_power_rec
** File description:
** Recursive, returns the first parameter
** raised to the power of the second
*/

float my_compute_power_rec(float nb, int p)
{
    if (p < 0)
        return 1 / my_compute_power_rec(nb, -p);
    if (p == 0)
        return 1;
    if (p == 1)
        return nb;
    return nb * my_compute_power_rec(nb, p - 1);
}
