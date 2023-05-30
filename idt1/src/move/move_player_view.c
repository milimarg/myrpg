/*
** EPITECH PROJECT, 2023
** doom
** File description:
** move_player_view.c
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include "../../include/my.h"

void go_up(my_idt1 *world, sfVector2i *delta)
{
    world->player.z++;
}

void go_down(my_idt1 *world, sfVector2i *delta)
{
    world->player.z--;
}

void lean_to_ground(my_idt1 *world, sfVector2i *delta)
{
    sfVector2f sky_size = {0};
    sfVector2f ground_size = {0};
    int change = 10;

    world->player.look++;
    if (world->player.look < -change) {
        world->player.look = -change;
        return;
    }
    if (world->player.look > change) {
        world->player.look = change;
        return;
    }
    sky_size = sfRectangleShape_getSize(world->map.sky);
    sky_size.y += (change + 2);
    sfRectangleShape_setSize(world->map.sky, sky_size);
    ground_size = sfRectangleShape_getSize(world->map.ground);
    ground_size.y -= (change + 2);
    sfRectangleShape_setSize(world->map.ground, ground_size);
}

void lean_to_sky(my_idt1 *world, sfVector2i *delta)
{
    sfVector2f sky_size = {0};
    sfVector2f ground_size = {0};
    int change = 10;

    world->player.look--;
    if (world->player.look < -change) {
        world->player.look = -change;
        return;
    }
    if (world->player.look > change) {
        world->player.look = change;
        return;
    }
    sky_size = sfRectangleShape_getSize(world->map.sky);
    sky_size.y -= (change + 2);
    sfRectangleShape_setSize(world->map.sky, sky_size);
    ground_size = sfRectangleShape_getSize(world->map.ground);
    ground_size.y += (change + 2);
    sfRectangleShape_setSize(world->map.ground, ground_size);
}
