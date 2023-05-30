/*
** EPITECH PROJECT, 2023
** B-MUL-200-STG-2-1-myrpg-florent.guittre
** File description:
** parsing_mob
*/

#include "../../include/my_rpg/my_rpg.h"

static void init_mob_values(mob_t *mob)
{
    mob->elapsed_time = 0.0;
    mob->interval_attack = 0.0;
    mob->interval_run = 0.0;
    mob->interval_attacked = 0.0;
    mob->run_limit = 0.8;
    mob->attack_limit = 0.8;
    mob->attacked_limit = 0.15;
    mob->mob_can_attack = sfFalse;
    mob->can_be_attacked = sfFalse;
    mob->count = 0;
}

static void init_mob_scale(game_t *game, mob_t *mob, char **tab_arg)
{
    set_mob_origin_scale(mob, (sfVector2f){my_getnbr(tab_arg[14]),
    my_getnbr(tab_arg[15])});
    mob->move_mob->mob_left = fill_mob_entity(mob, tab_arg[6],
    game->textures_list, &(mob->move_mob->mob_left));
    set_mob_origin_scale(mob, (sfVector2f){my_getnbr(tab_arg[16]),
    my_getnbr(tab_arg[17])});
    mob->move_mob->mob_right = fill_mob_entity(mob, tab_arg[7],
    game->textures_list, &(mob->move_mob->mob_right));
    set_mob_origin_scale(mob, (sfVector2f){my_getnbr(tab_arg[18]),
    my_getnbr(tab_arg[19])});
    mob->move_mob->run_mob_left = fill_mob_entity(mob, tab_arg[8],
    game->textures_list, &(mob->move_mob->run_mob_left));
    set_mob_origin_scale(mob, (sfVector2f){my_getnbr(tab_arg[20]),
    my_getnbr(tab_arg[21])});
    mob->move_mob->run_mob_right = fill_mob_entity(mob, tab_arg[9],
    game->textures_list, &(mob->move_mob->run_mob_right));
    mob->entity_mob = mob->move_mob->mob_right;
    mob->xp = my_getnbr(tab_arg[10]);
    mob->coin_mob = my_getnbr(tab_arg[22]);
}

int parsing_mob(game_t *game, char **tab_arg, char *filepath)
{
    int len = 0;
    mob_t *mob = NULL;

    for (; tab_arg[len] != NULL; len++);
    if (len != 14 + 9) {
        write(2, filepath, my_strlen(filepath));
        write(2, ": wrong file\n", 13);
        return (84);
    }
    mob = init_mob(game, tab_arg);
    init_mob_scale(game, mob, tab_arg);

    mob->mob_speed_tavern = ((float)my_getnbr(tab_arg[11]));
    sfSprite_setPosition(mob->entity_mob->anim->sprite, mob->mob_pos);
    init_mob_values(mob);
    add_to_object_list(game, init_object(mob, MOB, tab_arg[1]), MOB);
    return (0);
}
