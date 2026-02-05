/*
** EPITECH PROJECT, 2025
** my_strcapitalize
** File description:
** capitalizes the first letter of each word
*/

static int my_is_letter_number(char c)
{
    if (c >= 'a' || c >= 'A' || c >= '0') {
        if (c <= 'z' || c <= 'Z' || c <= '9') {
            return 1;
        }
    }
    return 0;
}

static int my_is_lwc(char c)
{
    if (c >= 'a' && c <= 'z') {
        return 1;
    }
    return 0;
}

static int my_is_upc(char c)
{
    if (c >= 'A' && c <= 'Z') {
        return 1;
    }
    return 0;
}

char *my_strcapitalize(char *str)
{
    if (str[0] >= 'a' && str[0] <= 'z') {
        str[0] -= 32;
    }
    for (int i = 0; str[i] != '\0'; i++) {
        if (my_is_letter_number(str[i]) == 0 && my_is_lwc(str[i + 1]) == 1) {
            str[i + 1] -= 32;
        }
        if (my_is_letter_number(str[i]) == 1 && my_is_upc(str[i + 1]) == 1) {
            str[i + 1] += 32;
        }
    }
    return str;
}
