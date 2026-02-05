/*
** EPITECH PROJECT, 2025
** my_revstr
** File description:
** returns the string in parameter,
** but reversed
*/

static int that_strlen(char const *str)
{
    int i;

    for (i = 0; str[i] != '\0'; i++) {
    }
    return i;
}

char *my_revstr(char *str)
{
    int len_str = that_strlen(str);
    char reverse[len_str];

    for (int i = 0; i <= len_str; i++) {
        reverse[i] = str[i];
    }
    for (int i = 0; str[i] != '\0'; i++) {
        str[i] = reverse[len_str - i - 1];
    }
    return str;
}
