/*
** EPITECH PROJECT, 2023
** B-MUL-200-STG-2-1-myrpg-florent.guittre
** File description:
** define
*/

#ifndef DEFINE_SCENES_H_
    #define DEFINE_SCENES_H_

    #define IS_SCENE(scene_type, to_compare) (scene_type == to_compare)

const static void (*INIT_SCENE_POINTER[])(game_t *) = {
    &init_main_menu,
    &init_main_map,
    &init_settings,
    &init_castle,
    &init_cave,
    &init_inventory,
    &init_jail,
    &init_magic_tower,
    &init_maze,
    &init_pause,
    &init_shop,
    &init_tavern,
    &init_death,
    &init_start_cinematic,
    &init_maze3d,
    &init_main_map_night,
    &init_jewels_room,
    &init_throne_room,
    &init_blacksmith,
    &init_end
};

const static void (*INIT_SCENE_POINTER_ACTION[])(game_t *) = {
    &init_main_menu_action,
    &init_main_map_action,
    &init_settings_action,
    &init_castle_action,
    &init_cave_action,
    &init_inventory_action,
    &init_jail_action,
    &init_magic_tower_action,
    &init_maze_action,
    &init_pause_action,
    &init_shop_action,
    &init_tavern_action,
    &init_death_action,
    &init_start_cinematic_action,
    &init_maze3d_action,
    &init_main_map_night_action,
    &init_jewels_room_action,
    &init_throne_room_action,
    &init_blacksmith_action,
    &init_end_action
};

#endif /* !DEFINE_SCENES_H_ */
