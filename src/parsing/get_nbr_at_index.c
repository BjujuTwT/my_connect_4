/*
** EPITECH PROJECT, 2026
** connect4
** File description:
** Returns the unsigned at a given index
** If it's not an unsigned, returns -1
*/

int get_nbr_at_index(char *str, int index)
{
    int nb = 0;

    if (str[index] == '\n' || str[index] == '\0')
        return -1;
    for (int i = index; str[i] != '\0'; i++) {
        if (str[i] == '\n' && str[i + 1] == '\0')
            break;
        if (str[i] < '0' || str[i] > '9')
            return -1;
        nb = nb * 10 + (str[i] - '0');
    }
    return nb;
}
