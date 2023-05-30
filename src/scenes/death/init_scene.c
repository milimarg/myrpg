/*
** EPITECH PROJECT, 2023
** B-MUL-200-STG-2-1-myrpg-florent.guittre
** File description:
** init_scene_action
*/

#include "../../../include/my_rpg/my_rpg.h"

void init_death_ext(game_t *game, map_t *map_background,
sfImage *temp_bg_image, sfVector2u image_size)
{
    map_background->texture = sfTexture_createFromImage(temp_bg_image, NULL);
    map_background->sprite = sfSprite_create();
    map_background->image = NULL;
    map_background->rect = (sfIntRect){0, 0, image_size.x, image_size.y};
    sfSprite_setTexture(map_background->sprite,
    map_background->texture, sfTrue);
    add_to_object_list(game, init_object(map_background, MAP, "map"), MAP);
}

void init_death(game_t *game)
{
    sfImage *temp_bg_image = NULL;
    sfVector2u image_size = {0};
    sfColor temp_pixel = {0};
    map_t *map_background = malloc(sizeof(map_t));

    temp_bg_image = take_screenshot(game->win->renderer);
    image_size = sfImage_getSize(temp_bg_image);
    grey_image(temp_bg_image);
    init_death_ext(game, map_background, temp_bg_image, image_size);
}
