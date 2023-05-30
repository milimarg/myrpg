/*
** EPITECH PROJECT, 2023
** B-MUL-200-STG-2-1-myrpg-florent.guittre
** File description:
** struct
*/

#ifndef STRUCT_PLAYER_H_
    #define STRUCT_PLAYER_H_

typedef struct stats_s {
    int hp;
    int strength;
    int dexterity;
    int resistance;
    int strength_xp;
    int resistance_xp;
    int global_xp;
    int level;
    int stat_point;
} stats_t;

typedef struct timer_regeneration_s {
    float interval;
    float elapsed_time;
    float defined_limit;
    float hp_interval;
    float hp_elapsed_time;
    float hp_defined_limit;
    int switch_timer;
} timer_regeneration_t;

typedef struct player_s {
    stats_t *stats;
    my_entity *entity;
    sfBool is_attacked;
    char *name;
    double speed;
    int move_steps;
    int move_steps_max;
    int sprite_steps;
    int sprite_steps_max;
    int current_hp;
    sfBool is_captured;
    int can_i_move;
    sfKeyCode current_key;
    sfKeyCode last_key;
    timer_regeneration_t *regen_timer;
} player_t;

#endif /* !STRUCT_PLAYER_H_ */
