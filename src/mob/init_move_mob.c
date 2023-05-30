/*
** EPITECH PROJECT, 2023
** B-MUL-200-STG-2-1-myrpg-florent.guittre
** File description:
** init_move_mob
*/

#include "../../include/my_rpg/my_rpg.h"

void set_mob_origin_scale(mob_t *mob, sfVector2f origin)
{
    mob->info->origin_x = origin.x;
    mob->info->origin_y = origin.y;
}

my_entity *fill_mob_entity(mob_t *mob, char *name_tag,
my_textures_list *textures_list, my_entity **entity)
{
    (*entity) = spawn_entity(textures_list, name_tag, 0);

    sfSprite_setOrigin((*entity)->anim->sprite,
    (sfVector2f){mob->info->origin_x, mob->info->origin_y});
    sfSprite_setScale((*entity)->anim->sprite,
    (sfVector2f){mob->info->scale_x, mob->info->scale_y});
    return ((*entity));
}

static move_mob_t *init_move_mob(game_t *game, char **tab_arg)
{
    move_mob_t *move = malloc(sizeof(move_mob_t));

    move->move_list = NULL;
    move->mob_left = NULL;
    move->mob_right = NULL;
    move->run_mob_left = NULL;
    move->run_mob_right = NULL;
    move->is_right = 1;
    move->len_move = 0;
    return (move);
}

mob_t *init_mob(game_t *game, char **tab_arg)
{
    mob_t *mob = malloc(sizeof(mob_t));
    info_sprite_t *info = malloc(sizeof(info_sprite_t));

    mob->hp_mob_max = my_getnbr(tab_arg[2]);
    mob->mob_damage = my_getnbr(tab_arg[3]);
    mob->current_hp_mob = mob->hp_mob_max;
    mob->entity_mob = NULL;
    mob->is_attacked = sfFalse;
    mob->mob_pos = (sfVector2f){my_getnbr(tab_arg[4]), my_getnbr(tab_arg[5])};
    info->scale_x = (float)my_getnbr(tab_arg[12]) / 100.0;
    info->scale_y = (float)my_getnbr(tab_arg[13]) / 100.0;
    info->origin_x = 0.0;
    info->origin_y = 0.0;
    mob->info = info;
    mob->move_mob = init_move_mob(game, tab_arg);
    return (mob);
}
