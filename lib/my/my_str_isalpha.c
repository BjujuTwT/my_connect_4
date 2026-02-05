/*
** EPITECH PROJECT, 2025
** my_str_isalpha
** File description:
** returns 1 or 0 if the parameter
** is only letters or not only
*/

static int is_lower_upper(char c)
{
    if (c >= 'a' && c <= 'z')
        return 1;
    if (c >= 'A' && c <= 'Z')
        return 1;
    return 0;
}

static int is_num(char c)
{
    if (c >= '0' && c <= '9')
        return 1;
    return 0;
}

int my_str_isalpha(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (is_lower_upper(str[i]) == 0 && is_num(str[i]) == 0)
            return 0;
    }
    return 1;
}
