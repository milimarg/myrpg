/*
** EPITECH PROJECT, 2023
** B-MUL-200-STG-2-1-myrpg-florent.guittre
** File description:
** struct.h
*/

#ifndef STRUCT_START_CINEMATIC_H_
    #define STRUCT_START_CINEMATIC_H_

typedef struct start_cinematic_object {
    sfRectangleShape *fade_in;
    sfColor color;
    double delay_update_char;
    int ms_delay;
    double delay_update_line;
    int display_fade_in;
    int display_dialog;
    int wait_ms_delay;
    int wait_steps;
    sfTexture *map_cache_texture;
    sfSprite *map_cache;
} start_cinematic_object;

#endif /* !STRUCT_START_CINEMATIC_H_ */
