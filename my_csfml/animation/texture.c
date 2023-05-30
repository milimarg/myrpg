/*
** EPITECH PROJECT, 2023
** B-MUL-200-STG-2-1-myrpg-florent.guittre
** File description:
** texture.c
*/

#include <stdlib.h>
#include "animation.h"
#include "../lib.h"

void add_texture(my_textures_list **textures_list, char *name_tag, char *path,
my_texture_rect *rect)
{
    sfIntRect int_rect = {rect->left, rect->top, rect->width, rect->height};
    my_textures_list *element = malloc(sizeof(my_textures_list));

    element->name_tag = name_tag;
    element->path = path;
    element->rect = int_rect;
    element->moves_nb = rect->moves_nb;
    element->texture = sfTexture_createFromFile(element->path, &int_rect);
    element->next = *textures_list;
    *textures_list = element;
}

my_textures_list *find_texture_in_list(my_textures_list *list, char *name_tag)
{
    for (my_textures_list *temp = list; temp != NULL; temp = temp->next) {
        if (!extra_my_strcmp(name_tag, temp->name_tag)) {
            return (temp);
        }
    }
    return (NULL);
}

my_textures_list *init_textures_list(void)
{
    return (NULL);
}
