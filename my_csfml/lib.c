/*
** EPITECH PROJECT, 2023
** my_csfml_container
** File description:
** lib.c
*/

#include <stddef.h>

int extra_my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\0')
        i++;
    return (i);
}

int extra_my_strcmp(const char *s1, const char *s2)
{
    int s1_len = extra_my_strlen(s1);
    int s2_len = extra_my_strlen(s2);

    for (int i = 0; i < s1_len || i < s2_len; i++)
        if (s1[i] != s2[i])
            return ((s1_len < s2_len) ? -1 : 1);
    return (0);
}

char *my_extra_char_memset(char *s, int c, size_t n)
{
    for (size_t i = 0; i < n; i++)
        s[i] = c;
    return (s);
}
