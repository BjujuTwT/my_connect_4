/*
** EPITECH PROJECT, 2025
** my_str_isupper
** File description:
** returns 1 or 0 if the parameter
** contains only lowercase letters or not only
*/

int my_str_isupper(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] < 'A' || str[i] > 'Z')
            return 0;
    }
    return 1;
}
