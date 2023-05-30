/*
** EPITECH PROJECT, 2023
** doom
** File description:
** world_handler.c
*/

#include <stdlib.h>
#include <math.h>
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include "../include/my.h"

static void set_map_infos(my_idt1 *world, map_type type, sfKeyCode reload_key,
sfVector2f *size)
{
    world->map.pixel_scale = 2;
    world->map.win_size = (sfVector2f){size->x / (double)world->map.pixel_scale,
    size->y / (double)world->map.pixel_scale};
    world->map.opengl_size.x = world->map.win_size.x * world->map.pixel_scale;
    world->map.opengl_size.y = world->map.win_size.y * world->map.pixel_scale;
    world->map.type = type;
    world->map.reload_key = reload_key;
    if (world->map.type == DANTE)
        convert_dante_to_config(world->filepath);
}

my_idt1 *create_world(char *filepath, map_type type, sfKeyCode reload_key,
sfVector2f *size)
{
    my_idt1 *world = malloc(sizeof(my_idt1));

    world->pre_cos = malloc(sizeof(double) * 360);
    world->pre_sin = malloc(sizeof(double) * 360);
    for (int i = 0; i < 360; i++) {
        world->pre_cos[i] = cos(deg_to_rad(i));
        world->pre_sin[i] = sin(deg_to_rad(i));
    }
    world->move_steps = 0;
    world->move_steps_max = 1;
    world->player = (my_idt1_player){3250, 3280, 50, 90, 0};
    world->points = sfVertexArray_create();
    world->no_spam_key = 0;
    world->filepath = filepath;
    world->joystick_connected = sfJoystick_isConnected(0);
    set_map_infos(world, type, reload_key, size);
    parse_file(world);
    return (world);
}

void destroy_world(my_idt1 *world)
{
    for (int i = 0; i < world->sectors_nb; i++) {
        free(world->sectors[i]->walls);
        free(world->sectors[i]->points_surface);
        free(world->sectors[i]);
    }
    free(world->sectors);
    free(world->pre_cos);
    free(world->pre_sin);
    free(world);
}
