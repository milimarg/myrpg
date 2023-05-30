/*
** EPITECH PROJECT, 2023
** doom
** File description:
** move_player_body.c
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include "../../include/my.h"

void move_front(my_idt1 *world, sfVector2i *delta)
{
    world->player.x += delta->x;
    world->player.y += delta->y;
}

void move_back(my_idt1 *world, sfVector2i *delta)
{
    world->player.x -= delta->x;
    world->player.y -= delta->y;
}

void turn_left(my_idt1 *world, sfVector2i *delta)
{
    world->player.angle = fix_angle(world->player.angle - 10);
}

void turn_right(my_idt1 *world, sfVector2i *delta)
{
    world->player.angle = fix_angle(world->player.angle + 10);
}

int move_handler(my_idt1 *world, sfKeyCode key,
void (*function)(my_idt1 *, sfVector2i *), sfVector2i *delta)
{
    if (sfKeyboard_isKeyPressed(key)) {
        if (check_sectors_distance(world, key, function)
            && (function == &move_front || function == &move_back))
            return (1);
        function(world, delta);
    }
    return (0);
}
