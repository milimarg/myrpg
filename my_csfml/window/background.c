/*
** EPITECH PROJECT, 2022
** my_csfml
** File description:
** background
*/

#include <stdlib.h>
#include <unistd.h>
#include "window.h"
#include "../lib.h"

my_background *init_background(char *name_tag, my_textures_list *textures_list)
{
    my_background *background = malloc(sizeof(my_background));
    sfTexture *texture_to_find = NULL;

    for (; textures_list != NULL; textures_list = textures_list->next) {
        if (!extra_my_strcmp(name_tag, textures_list->name_tag)) {
            texture_to_find = textures_list->texture;
            break;
        }
    }
    if (texture_to_find == NULL) {
        write(2, "window: texture not found for background\n", 41);
        return (NULL);
    }
    background->sprite = sfSprite_create();
    sfSprite_setTexture(background->sprite, texture_to_find, sfTrue);
    return (background);
}
