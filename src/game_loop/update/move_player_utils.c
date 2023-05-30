/*
** EPITECH PROJECT, 2023
** B-MUL-200-STG-2-1-myrpg-florent.guittre
** File description:
** move_player_utils.c
*/

#include "../../../include/my_rpg/my_rpg.h"

void update_player_texture(game_t *game, char *anim_names[], int i)
{
    if (game->player->current_key != game->player->last_key)
        set_entity_animation(game->player->entity->anim, anim_names[i],
        game->textures_list);
}

int check_collisions(map_t *map, sfVector2u *pos)
{
    return (sfColor_toInteger(sfImage_getPixel(map->image, pos->x, pos->y)) ==
    sfColor_toInteger(sfRed));
}
