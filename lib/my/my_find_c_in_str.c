/*
** EPITECH PROJECT, 2025
** my_find_c_in_str.c
** File description:
** If the character c exists
** in the string str, the function
** returns the index of c in str
** If it doesn't, returns -1
*/

int my_find_c_in_str(char c, char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == c)
            return i;
    }
    return -1;
}
