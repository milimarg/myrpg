/*
** EPITECH PROJECT, 2023
** B-MUL-200-STG-2-1-myrpg-florent.guittre
** File description:
** my_strncmp
*/

int my_strncmp(const char *string_two, const char *string_one, int nb)
{
    if (nb == 0)
        return (1);
    for (int i = 0; string_one[i] && string_two[i] && i < nb; i++) {
        if (string_one[i] != string_two[i])
            return (0);
    }
    return (1);
}
