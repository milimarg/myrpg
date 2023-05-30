/*
** EPITECH PROJECT, 2023
** B-MUL-200-STG-2-1-myrpg-florent.guittre
** File description:
** my_strcat
*/

#include "../../include/my_rpg/my_rpg.h"

char *my_strcat(char *dest, char const *src)
{
    int i = 0;
    int dest_len = 0;

    dest_len = my_strlen(dest);
    for (; src[i] != '\0'; i ++)
        dest[dest_len + i] = src[i];
    dest[dest_len + i] = '\0';
    return (dest);
}
