/*
** EPITECH PROJECT, 2023
** doom
** File description:
** main.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/OpenGL.h>
#include "../include/my.h"

void clip_behind_player(sfVector3i *one, sfVector3i *two)
{
    float da = one->y;
    float db = two->y;
    float s = da / (da - db);

    one->x = one->x + s * (two->x - one->x);
    one->y = one->y + s * (two->y - one->y);
    one->y = (one->y == 0) ? 1 : one->y;
    one->z = one->z + s * (two->z - one->z);
}

void display_world(my_idt1 *world, sfRenderWindow *window)
{
    sfVector3i *wpos = malloc(sizeof(sfVector3i) * 4);

    sfVertexArray_clear(world->points);
    sort_sectors(world);
    for (int s = 0; s < world->sectors_nb; s++) {
        world->sectors[s]->d = 0;
        set_surface_type(world, s);
        for (int loop = 0; loop < 2; loop++) {
            draw_one_wall(world, loop, s, wpos);
            world->sectors[s]->d /= world->sectors[s]->walls_nb;
            world->sectors[s]->surface *= -1;
        }
    }
    sfRenderWindow_drawVertexArray(window, world->points, NULL);
    free(wpos);
}

void set_ground_and_sky(sfRenderWindow *window, my_idt1 *world)
{
    sfVector2u win_size = sfRenderWindow_getSize(window);
    double sky_height = ((double)win_size.y / 2.0) + 20;
    sfColor ceiling_color = {50, 50, 50, 255};
    sfColor ground_color = {81, 81, 81, 255};
    sfVector2f sky_size = {win_size.x, sky_height};
    sfVector2f ground_size = {win_size.x, 5000};

    sfRenderWindow_setActive(window, sfTrue);
    world->map.ground = sfRectangleShape_create();
    world->map.sky = sfRectangleShape_create();
    sfRectangleShape_setSize(world->map.sky, sky_size);
    sfRectangleShape_setPosition(world->map.sky, (sfVector2f){0, 0});
    sfRectangleShape_setSize(world->map.ground, ground_size);
    sfRectangleShape_setPosition(world->map.ground, (sfVector2f){0, 0});
    sfRectangleShape_setFillColor(world->map.ground, ground_color);
    sfRectangleShape_setFillColor(world->map.sky, ceiling_color);
    sfRectangleShape_setOutlineThickness(world->map.ground, 0);
    sfRectangleShape_setOutlineThickness(world->map.ground, 0);
    glPointSize(world->map.pixel_scale);
    gluOrtho2D(0, world->map.opengl_size.x, 0, world->map.opengl_size.y);
}
