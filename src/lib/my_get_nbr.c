/*
** EPITECH PROJECT, 2023
** B-MUL-200-STG-2-1-myrpg-florent.guittre
** File description:
** my_getnbr
*/

#include "../../include/my_rpg/my_rpg.h"

int my_get_nbr(char const *str)
{
    int res = 0;
    int c = 1;
    int cc = 0;

    for (int i = 0; str[i]; i++) {
        if ((str[i] >= '0' && str[i] <= '9') &&
        (str[i + 1] >= '0' && str[i + 1] <= '9')){
            res = res * 10 + (str[i] - '0');
            c++;
        }
        if ((str[i] >= '0' && str[i] <= '9') &&
        (str[i + 1] < '0' || str[i + 1] > '9')){
            res = res * 10 + (str[i] - '0');
            i = my_strlen(str) - 1;
        }
        cc++;
    }
    if ((str[cc - c] >= '0' && str[cc - c] <= '9') && str[cc - c - 1] == '-')
        res = -res;
    return res;
}
