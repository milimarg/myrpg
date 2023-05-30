/*
** EPITECH PROJECT, 2023
** B-MUL-200-STG-2-1-myrpg-florent.guittre
** File description:
** my_intlen.c
*/

#include "../../include/my_rpg/my_rpg.h"

int my_intlen(int nb)
{
    int i = 0;

    for (; nb != 0; nb /= 10)
        i++;
    return (i);
}
