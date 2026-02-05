/*
** EPITECH PROJECT, 2025
** my_get_nbr
** File description:
** Returns the number contained in the string in parameter.
** Doesn't handle error cases, up to ya'
*/

int my_getnbr(char *num)
{
    int n = 0;

    for (int i = 0; num[i] != '\0'; i++)
        n = n * 10 + (num[i] - '0');
    return n;
}
