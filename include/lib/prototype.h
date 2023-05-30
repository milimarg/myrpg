/*
** EPITECH PROJECT, 2023
** B-MUL-200-STG-2-1-myrpg-florent.guittre
** File description:
** prototype
*/

#ifndef PROTOTYPE_LIB_H_
    #define PROTOTYPE_LIB_H_

char **my_str_to_word_array(char *str);
char **my_str_to_word_array_specified(char *str, char separator);
int my_strlen(char const *str);
char *my_strcat(char *dest, char const *src);
int my_strcmp(const char *s1, const char *s2);
int my_strncmp(const char *string_two, const char *string_one, int nb);
int my_get_nbr(char const *str);
int my_intlen(int nb);
char *my_int_to_str(int nb);

#endif /* !PROTOTYPE_LIB_H_ */
