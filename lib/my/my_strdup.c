/*
** EPITECH PROJECT, 2025
** my_strdup.c
** File description:
** allocated and write a str
*/

#include <stdlib.h>

static int my_str_the_len(char *str)
{
    int len = 0;

    while (str[len] != '\0')
        len++;
    return len;
}

char *my_strdup(char *str)
{
    size_t len = (size_t)(my_str_the_len(str) + 1);
    char *new = malloc(sizeof(char) * len);

    for (int i = 0; str[i] != '\0'; i++)
        new[i] = str[i];
    new[len - 1] = '\0';
    return new;
}
