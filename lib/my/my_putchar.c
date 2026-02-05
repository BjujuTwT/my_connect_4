/*
** EPITECH PROJECT, 2025
** my_putchar
** File description:
** displays a character
*/
#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}
