/*
** EPITECH PROJECT, 2023
** doom
** File description:
** move_player.c
*/

#include <math.h>
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <stdio.h>
#include "../../include/my.h"
#include "../../../include/my_rpg/my_rpg.h"

static void move_with_joystick(my_idt1 *world,
void (*functions[])(my_idt1 *, sfVector2i *))
{
    sfVector2i delta = {0};
    float stick_turn = sfJoystick_getAxisPosition(0, sfJoystickU);
    float stick_move = sfJoystick_getAxisPosition(0, sfJoystickY);
    float stick_view = sfJoystick_getAxisPosition(0, sfJoystickV);

    delta.x = world->pre_sin[world->player.angle] * fabs(stick_move) / 15.0;
    delta.y = world->pre_cos[world->player.angle] * fabs(stick_move) / 15.0;
    if (stick_turn == -100)
        functions[2](world, &delta);
    if (stick_turn == 100)
        functions[3](world, &delta);
    if (stick_move < -10)
        functions[0](world, &delta);
    if (stick_move > 10)
        functions[1](world, &delta);
    if (stick_view == 100)
        functions[6](world, &delta);
    if (stick_view == -100)
        functions[7](world, &delta);
}

int cancel_movement_when_collision(my_idt1 *world, int limit_collision,
sfVector2i *delta)
{
    for (int j = 0; j < world->sectors_nb; j++) {
        if (world->sectors[j]->d < limit_collision &&
        world->sectors[j]->z1 != 64) {
            move_back(world, delta);
            return (1);
        }
    }
    return (0);
}

int check_sectors_distance(my_idt1 *world, sfKeyCode key,
void (*function)(my_idt1 *, sfVector2i *))
{
    sfVector2i delta = {0};
    static int limit_collision = 60;

    delta.x = world->pre_sin[world->player.angle] * 15.0;
    delta.y = world->pre_cos[world->player.angle] * 15.0;
    if (function == &move_front)
        if (cancel_movement_when_collision(world, limit_collision, &delta))
            return (1);
    return (0);
}

void free_move(sfKeyCode keys[], void (*functions[])(my_idt1 *, sfVector2i *),
my_idt1 *world, sfVector2i *delta)
{
    for (int i = 0; keys[i] != -1; i++) {
        if (sfKeyboard_isKeyPressed(keys[i])) {
            functions[i](world, delta);
        }
    }
}

void move_player_idt1(my_idt1 *world, game_t *game)
{
    sfKeyCode keys[] = {game->keys[0], -2, game->keys[2], game->keys[3],
    sfKeyPageUp, sfKeyPageDown, sfKeyComma, sfKeySemicolon, -1};
    static void (*functions[])(my_idt1 *, sfVector2i *) = {&move_front,
    &move_back, &turn_left, &turn_right, &go_up, &go_down, &lean_to_ground,
    &lean_to_sky};
    sfVector2i delta = {0};

    if (world->move_steps <= world->move_steps_max)
        return;
    else
        world->move_steps = 0;
    delta.x = world->pre_sin[world->player.angle] * 10.0;
    delta.y = world->pre_cos[world->player.angle] * 10.0;
    for (int i = 0; keys[i] != -1; i++) {
        if (move_handler(world, keys[i], functions[i], &delta))
            continue;
    }
    if (world->joystick_connected)
        move_with_joystick(world, functions);
}
