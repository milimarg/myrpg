/*
** EPITECH PROJECT, 2023
** B-MUL-200-STG-2-1-myrpg-florent.guittre
** File description:
** parsing_texture
*/

#include "../../include/my_rpg/my_rpg.h"

int parsing_texture(game_t *game, char **tab_arg, char *filepath)
{
    int len = 0;

    for (; tab_arg[len] != NULL; len++);
    if (len != 8) {
        write(2, filepath, my_strlen(filepath));
        write(2, ": wrong file\n", 13);
        return (84);
    }
    add_texture(&game->textures_list, tab_arg[1], tab_arg[2],
    &(my_texture_rect){my_getnbr(tab_arg[3]),
    my_getnbr(tab_arg[4]), my_getnbr(tab_arg[5]),
    my_getnbr(tab_arg[6]), my_getnbr(tab_arg[7])});
    return (0);
}
