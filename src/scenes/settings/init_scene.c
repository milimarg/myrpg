/*
** EPITECH PROJECT, 2023
** B-MUL-200-STG-2-1-myrpg-florent.guittre
** File description:
** init_scene_action
*/

#include "../../../include/my_rpg/my_rpg.h"

void init_settings_ext(game_t *game, map_t *map_background)
{
    map_background->sprite = sfSprite_create();
    sfSprite_setTexture(map_background->sprite,
    map_background->texture, sfTrue);
    add_to_object_list(game, init_object(map_background, MAP, "map"), MAP);
}

void init_settings(game_t *game)
{
    sfImage *image = take_screenshot(game->win->renderer);
    map_t *map_background = malloc(sizeof(map_t));
    sfVector2u image_size = sfImage_getSize(image);
    sfColor temp_pixel = {0};

    grey_image(image);
    map_background->image = NULL;
    map_background->texture = sfTexture_createFromImage(image, NULL);
    map_background->rect = (sfIntRect){0, 0,
    (int)(image_size.x), (int)(image_size.y)};
    init_settings_ext(game, map_background);
}
