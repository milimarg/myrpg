/*
** EPITECH PROJECT, 2022
** my_csfml
** File description:
** animations
*/

#include "animation.h"

void update_animation(my_animation *anim)
{
    sfIntRect rect = anim->one_texture_rect;

    anim->i = (anim->i == anim->move_nb - 1) ? 0 : anim->i + 1;
    rect.left = anim->i * anim->one_texture_rect.width;
    sfSprite_setTextureRect(anim->sprite, rect);
}

void update_animation_reverse(my_animation *anim)
{
    sfIntRect rect = anim->one_texture_rect;

    anim->i = (anim->i == 0) ? anim->move_nb - 1 : anim->i - 1;
    rect.left = anim->i * anim->one_texture_rect.width;
    sfSprite_setTextureRect(anim->sprite, rect);
}

void reset_entity_animation(my_animation *anim)
{
    anim->i = 0;
    sfSprite_setTextureRect(anim->sprite, anim->one_texture_rect);
}

void reset_entity_animation_reverse(my_animation *anim)
{
    sfIntRect rect = anim->one_texture_rect;

    anim->i = anim->move_nb - 1;
    rect.left = anim->one_texture_rect.width * anim->i;
    sfSprite_setTextureRect(anim->sprite, rect);
}
