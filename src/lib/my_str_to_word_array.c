/*
** EPITECH PROJECT, 2023
** B-MUL-200-STG-2-1-myrpg-florent.guittre
** File description:
** my_str_to_word_array
*/

#include "../../include/my_rpg/my_rpg.h"

int my_strlen(char const *str)
{
    int i = 0;

    for (; str[i] != '\0'; i++);
    return (i);
}

int find_line_len(char *str)
{
    char *str_save = str;

    for (; str[0] != '\n' && str[0]; str++);
    return (str - str_save);
}

char **my_str_to_word_array(char *str)
{
    int len = my_strlen(str);
    char **arr = malloc(sizeof(char *) * (len + 1));
    int j = 0;
    int pos_arr = 0;
    int line_len = find_line_len(str);

    for (; str[0]; pos_arr++) {
        arr[pos_arr] = malloc(sizeof(char) * (line_len + 1));
        for (; str[0] != ' ' && str[0]; str++) {
            arr[pos_arr][j] = str[0];
            j++;
        }
        arr[pos_arr][j] = '\0';
        j = 0;
        if (str[0])
            str++;
    }
    arr[pos_arr] = NULL;
    return (arr);
}

char **my_str_to_word_array_specified(char *str, char separator)
{
    int len = my_strlen(str);
    char **arr = malloc(sizeof(char *) * (len + 1));
    int j = 0;
    int pos_arr = 0;
    int line_len = find_line_len(str);

    for (; str[0]; pos_arr++) {
        line_len = find_line_len(str);
        arr[pos_arr] = malloc(sizeof(char) * (line_len + 1));
        for (; str[0] != separator && str[0] != '\0'; str++) {
            arr[pos_arr][j] = str[0];
            j++;
        }
        arr[pos_arr][j] = '\0';
        j = 0;
        if (str[0])
            str++;
    }
    arr[pos_arr] = NULL;
    return (arr);
}

void free_word_array(char **arr)
{
    for (int i = 0; arr[i] != NULL; i++)
        free (arr[i]);
    free (arr);
}
