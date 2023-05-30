/*
** EPITECH PROJECT, 2023
** B-MUL-200-STG-2-1-myrpg-florent.guittre
** File description:
** init_scene_action
*/

#include "../../../include/my_rpg/my_rpg.h"

void init_pause_ext(game_t *game, map_t *map_background)
{
    object_t *object = NULL;
    pause_object *pause = malloc(sizeof(pause_object));

    sfSprite_setTexture(map_background->sprite,
    map_background->texture, sfTrue);
    add_to_object_list(game, init_object(map_background, MAP, "map"), MAP);
    game->current_scene->can_player_move = sfFalse;
    pause->anti_spam_keyboard = 0;
    pause->anti_spam_mouse = 0;
    pause->filter = sfRectangleShape_create();
    sfRectangleShape_setSize(pause->filter, (sfVector2f){game->win->width,
    game->win->height});
    sfRectangleShape_setFillColor(pause->filter, game->filter_color);
    sfRectangleShape_setOutlineThickness(pause->filter, 0);
    object = init_object(pause, PAUSE_OBJECT, "pause_object");
    add_to_object_list(game, object, PAUSE_OBJECT);
    pause->previous_scene = game->old_scene_type;
}

void init_pause(game_t *game)
{
    sfImage *temp_bg_image = NULL;
    map_t *map_background = malloc(sizeof(map_t));
    sfVector2u image_size = {0};
    sfColor temp_pixel = {0};

    temp_bg_image = take_screenshot(game->win->renderer);
    image_size = sfImage_getSize(temp_bg_image);
    grey_image(temp_bg_image);
    map_background->texture = sfTexture_createFromImage(temp_bg_image, NULL);
    map_background->sprite = sfSprite_create();
    map_background->image = NULL;
    map_background->rect = (sfIntRect){0, 0,
    (int)(image_size.x), (int)(image_size.y)};
    init_pause_ext(game, map_background);
}
