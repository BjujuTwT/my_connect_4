/*
** EPITECH PROJECT, 2025
** my_str_islower
** File description:
** returns 1 or 0 if the parameter
** contains only uppercase letters or not only
*/

int my_str_islower(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] < 'a' || str[i] > 'z')
            return 0;
    }
    return 1;
}
