/*
** EPITECH PROJECT, 2025
** my_intlen
** File description:
** returns the numbers of digits an int has
** (+1 if negative)
*/

int my_intlen(long long int n)
{
    int length = 0;
    int negative = 0;

    if (n <= 0) {
        n *= -1;
        negative = 1;
    }
    while (n != 0) {
        n = n / 10;
        length++;
    }
    return length + negative;
}
