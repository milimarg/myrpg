/*
** EPITECH PROJECT, 2023
** B-MUL-200-STG-2-1-myrpg-florent.guittre
** File description:
** my_int_to_str.c
*/

#include <stdlib.h>
#include "../../include/my_rpg/my_rpg.h"

static void convert_int_to_str_rec(int nb, char *str, int index)
{
    if (nb == 0)
        return;
    else {
        convert_int_to_str_rec(nb / 10, str, index - 1);
        str[index] = (nb % 10) + '0';
    }
}

char *my_int_to_str(int nb)
{
    int len = my_intlen(nb);
    char *str = malloc(sizeof(char) * (len + 1));

    convert_int_to_str_rec(nb, str, len - 1);
    str[len] = 0;
    return (str);
}
