/*
** EPITECH PROJECT, 2023
** B-MUL-200-STG-2-1-myrpg-florent.guittre
** File description:
** define
*/

#ifndef DEFINE_MY_RPG_H_
    #define DEFINE_MY_RPG_H_

    #define CAST_TP(tp) (tp_t *)(tp)
    #define CAST_TP(tp) (tp_t *)(tp)
    #define CAST_TEXT(text) (text_t *)(text)
    #define CAST_START_CINEMATIC(start) (start_cinematic_object *)(start)
    #define CAST_SHOP(shop) (shop_t *)(shop)
    #define CAST_PAUSE(pause) (pause_object *)(pause)
    #define CAST_NPC(npc) (npc_t *)(npc)
    #define CAST_MOB(mob) (mob_t *)(mob)
    #define CAST_MAP(map) (map_t *)(map)
    #define CAST_MAIN_MAP_NIGHT(night) (main_map_night *)(night)
    #define CAST_IMAGE(image) (image_t *)(image)
    #define CAST_BUTTON(button) (my_button *)(button)
    #define CAST_ENTITY(entity) (my_entity *)(entity)
    #define CAST_MAZE3D(maze3d) (my_idt1 *)(maze3d)

const static void *OBJECT_DRAW_TAB[] = {
    &draw_button,
    &draw_map,
    &draw_inventory,
    &draw_pause,
    &draw_start_cinematic,
    &draw_tp,
    &draw_npc,
    &draw_maze3d,
    &draw_mob,
    &draw_map_night,
    &draw_image,
    &draw_entity,
    &draw_shop,
    &draw_text
};

const static void *OBJECT_UPDATE_TAB[] = {
    &update_button,
    &update_map,
    &update_inventory,
    &update_pause,
    &update_start_cinematic,
    &update_tp,
    &update_npc,
    &update_maze3d,
    &update_mob,
    &update_map_night,
    &update_image,
    &update_entity,
    &update_shop,
    &update_text
};

const static void *OBJECT_EVENT_TAB[] = {
    &event_button,
    &event_map,
    &event_inventory,
    &event_pause,
    &event_start_cinematic,
    &event_tp,
    &event_npc,
    &event_maze3d,
    &event_mob,
    &event_map_night,
    &event_image,
    &event_entity,
    &event_shop,
    &event_text
};

const static void *OBJECT_TIMER_TAB[] = {
    &timer_button,
    &timer_map,
    &timer_inventory,
    &timer_pause,
    &timer_start_cinematic,
    &timer_tp,
    &timer_npc,
    &timer_maze3d,
    &timer_mob,
    &timer_map_night,
    &timer_image,
    &timer_entity,
    &timer_shop,
    &timer_text
};

const static void *OBJECT_DESTROY_TAB[] = {
    &destroy_button,
    &destroy_map,
    &destroy_inventory,
    &destroy_pause,
    &destroy_start_cinematic,
    &destroy_tp,
    &destroy_npc,
    &destroy_maze3d,
    &destroy_mob,
    &destroy_map_night,
    &destroy_image,
    &destroy_entity,
    &destroy_shop,
    &destroy_text
};

#endif /* !DEFINE_MY_RPG_H_ */
