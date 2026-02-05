/*
** EPITECH PROJECT, 2025
** my_str_isprintable
** File description:
** returns 1 or 0 if parameter contains
** only printable characters or not only
*/

int my_str_isprintable(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] <= 32 || str[i] == 127)
            return 0;
    }
    return 1;
}
