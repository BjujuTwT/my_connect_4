/*
** EPITECH PROJECT, 2025
** my_find_n_in_array
** File description:
** If nb is in the array in second parameter,
** it returns the index of the first occurence
** of nb in this array.
** If it wasn't found, it returns -1 instead
*/

int my_find_n_in_array(int nb, int *array, int size)
{
    for (int i = 0; i < size; i++) {
        if (array[i] == nb)
            return i;
    }
    return -1;
}
