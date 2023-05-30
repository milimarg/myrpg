/*
** EPITECH PROJECT, 2023
** B-MUL-200-STG-2-1-myrpg-florent.guittre
** File description:
** parsing_image
*/

#include "../../include/my_rpg/my_rpg.h"

int parsing_image(game_t *game, char **tab_arg, char *filepath)
{
    int len = 0;
    image_t *image = NULL;

    for (; tab_arg[len] != NULL; len++);
    if (len != 5) {
        write(2, filepath, my_strlen(filepath));
        write(2, ": wrong file\n", 13);
        return (84);
    }
    image = malloc(sizeof(image_t));
    image->sprite = sfSprite_create();
    sfSprite_setTexture(image->sprite,
    find_texture_in_list(game->textures_list, tab_arg[4])->texture, sfTrue);
    image->pos = (sfVector2f){my_getnbr(tab_arg[2]), my_getnbr(tab_arg[3])};
    add_to_object_list(game, init_object(image, IMAGE, tab_arg[1]), IMAGE);
    return (0);
}
