/*
** EPITECH PROJECT, 2022
** my_csfml
** File description:
** destroy
*/

#include <stdlib.h>
#include "animation.h"

void destroy_textures_list(my_textures_list *textures_list)
{
    my_textures_list *temp = NULL;

    while (textures_list != NULL) {
        temp = textures_list;
        textures_list = textures_list->next;
        sfTexture_destroy(temp->texture);
        free(temp);
    }
}
