/*
** EPITECH PROJECT, 2023
** B-MUL-200-STG-2-1-myrpg-florent.guittre
** File description:
** init_scene_action
*/

#include "../../../include/my_rpg/my_rpg.h"

void init_inventory_ext(game_t *game, map_t *map_background,
sfImage *temp_bg_image, sfVector2u image_size)
{
    map_background->texture = sfTexture_createFromImage(temp_bg_image, NULL);
    map_background->sprite = sfSprite_create();
    map_background->image = NULL;
    map_background->rect = (sfIntRect){0, 0, image_size.x, image_size.y};
    sfSprite_setTexture(map_background->sprite,
    map_background->texture, sfTrue);
    add_to_object_list(game, game->inventory_object, INVENTORY_OBJECT);
    add_to_object_list(game, init_object(map_background, MAP, "map"), MAP);
}

void grey_image(sfImage *image)
{
    sfVector2u image_size = sfImage_getSize(image);
    sfColor temp_pixel = {0};

    for (int i = 0; i < image_size.y; i++) {
        for (int j = 0; j < image_size.x; j++) {
            temp_pixel = sfImage_getPixel(image, j, i);
            temp_pixel.a = 100;
            sfImage_setPixel(image, j, i, temp_pixel);
        }
    }
}

void init_inventory(game_t *game)
{
    sfImage *temp_bg_image = NULL;
    sfVector2u image_size = {0};
    map_t *map_background = malloc(sizeof(map_t));

    temp_bg_image = take_screenshot(game->win->renderer);
    image_size = sfImage_getSize(temp_bg_image);
    grey_image(temp_bg_image);
    init_inventory_ext(game, map_background, temp_bg_image, image_size);
}
