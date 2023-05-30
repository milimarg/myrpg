/*
** EPITECH PROJECT, 2023
** B-MUL-200-STG-2-1-myrpg-florent.guittre
** File description:
** struct
*/

#ifndef STRUCT_MOB_H_
    #define STRUCT_MOB_H_
    #include "../../my_rpg/my_rpg.h"

typedef struct link_list_pos_s {
    float x;
    float y;
    struct link_list_pos_s *next;
} link_list_pos_t;

typedef struct info_sprite_s {
    float origin_x;
    float origin_y;
    float scale_x;
    float scale_y;
} info_sprite_t;

typedef struct move_mob_s {
    link_list_pos_t *move_list;
    my_entity *mob_left;
    my_entity *mob_right;
    my_entity *run_mob_left;
    my_entity *run_mob_right;
    int len_move;
    int is_right;
} move_mob_t;

typedef struct mob_s {
    move_mob_t *move_mob;
    my_entity *entity_mob;
    info_sprite_t *info;
    sfBool is_attacked;
    sfVector2f mob_pos;
    int coin_mob;
    int hp_mob_max;
    int current_hp_mob;
    int mob_damage;
    int xp;
    float mob_speed_tavern;
    float elapsed_time;
    float interval_run;
    float interval_attack;
    float interval_attacked;
    float run_limit;
    float attack_limit;
    float attacked_limit;
    sfBool mob_can_attack;
    sfBool can_be_attacked;
    int count;
} mob_t;

#endif /* !STRUCT_MOB_H_ */
