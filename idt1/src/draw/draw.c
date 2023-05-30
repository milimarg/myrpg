/*
** EPITECH PROJECT, 2023
** doom
** File description:
** draw.c
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include "../../include/my.h"

void draw_point(int x, int y, sfColor color, my_idt1 *world)
{
    sfVertex vertex = {0};

    vertex.color = color;
    vertex.position = (sfVector2f){x * world->map.pixel_scale,
    y * world->map.pixel_scale};
    sfVertexArray_append(world->points, vertex);
}

sfColor get_texture_pixel(sfVector2u *pos, sfVector2u *texture_size,
sfImage *image)
{
    if (pos->x < 0)
        pos->x = 0;
    if (pos->y < 0)
        pos->y = 0;
    while (pos->x >= texture_size->x)
        pos->x -= texture_size->x;
    while (pos->y >= texture_size->y)
        pos->y -= texture_size->y;
    return (sfImage_getPixel(image, pos->x, pos->y));
}
