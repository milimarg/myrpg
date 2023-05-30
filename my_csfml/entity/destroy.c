/*
** EPITECH PROJECT, 2022
** my_csfml
** File description:
** destroy
*/

#include <stdlib.h>
#include "entity.h"

void destroy_entity_lib(my_entity *entity)
{
    sfTexture_destroy(entity->anim->texture);
    sfSprite_destroy(entity->anim->sprite);
    free(entity->anim);
    free(entity);
}
