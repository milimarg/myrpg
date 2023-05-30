/*
** EPITECH PROJECT, 2022
** my_csfml
** File description:
** entity
*/

#include <stdio.h>
#include <stdlib.h>
#include "../lib.h"
#include "entity.h"

void set_spawnpoint(my_entity *entity, sfVector2f *spawnpoint, double angle)
{
    double last_angle = sfSprite_getRotation(entity->anim->sprite);

    entity->position.x = spawnpoint->x;
    entity->position.y = spawnpoint->y;
    sfSprite_setPosition(entity->anim->sprite, entity->position);
    sfSprite_rotate(entity->anim->sprite, (last_angle * (-1)));
    sfSprite_rotate(entity->anim->sprite, angle);
}

void move_entity(my_entity *entity, sfVector2f *move, double angle)
{
    entity->position.x = move->x;
    entity->position.y = move->y;
    sfSprite_move(entity->anim->sprite, entity->position);
    sfSprite_rotate(entity->anim->sprite, angle);
}

my_entity *spawn_entity(my_textures_list *head, char *name_tag,
double timer_max)
{
    my_entity *entity = NULL;

    for (my_textures_list *temp = head; temp; temp = temp->next) {
        if (!extra_my_strcmp(temp->name_tag, name_tag)) {
            entity = malloc(sizeof(my_entity));
            entity->type = name_tag;
            entity->is_clicked = 0;
            entity->timer = 0;
            entity->timer_max = timer_max;
            entity->drop_rate = 1;
            entity->anim = malloc(sizeof(my_animation));
            entity->anim->sprite = sfSprite_create();
            set_entity_animation(entity->anim, name_tag, head);
            break;
        }
    }
    return (entity);
}

static void fill_entity_anim_infos(my_animation *anim, sfIntRect *one_texture,
sfIntRect *rect, my_textures_list *node)
{
    anim->texture = node->texture;
    anim->full_texture_rect = node->rect;
    anim->i = 0;
    anim->move_nb = node->moves_nb;
    one_texture->left = 0;
    one_texture->top = 0;
    one_texture->width = (double)anim->full_texture_rect.width /
    (double)anim->move_nb;
    one_texture->height = anim->full_texture_rect.height;
    rect->left = anim->i * one_texture->width;
    rect->top = 0;
    rect->width = one_texture->width;
    rect->height = one_texture->height;
    anim->one_texture_rect = *one_texture;
    anim->path = node->path;
    anim->has_sprite_been_defined = 0;
    sfSprite_setTexture(anim->sprite, anim->texture, 1);
    sfSprite_setTextureRect(anim->sprite, anim->one_texture_rect);
}

int set_entity_animation(my_animation *anim, char *name_tag,
my_textures_list *head)
{
    sfIntRect one_texture = {0};
    sfIntRect rect = {0};

    for (my_textures_list *node = head; node != NULL; node = node->next) {
        if (!extra_my_strcmp(name_tag, node->name_tag)) {
            fill_entity_anim_infos(anim, &one_texture, &rect, node);
            return (0);
        }
    }
    return (1);
}
