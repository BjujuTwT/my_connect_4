/*
** EPITECH PROJECT, 2025
** my_seek_int
** File description:
** returns the index of the first occurence of
** the int in parameter inside the int array
** in second parameter.
** If it is not in it at all, the function will
** instead return -1
*/

int my_seek_int(int n, int *array, int nb_cols)
{
    for (int i = 0; i < nb_cols; i++) {
        if (array[i] == n)
            return i;
    }
    return -1;
}
