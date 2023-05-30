/*
** EPITECH PROJECT, 2023
** B-MUL-200-STG-2-1-myrpg-florent.guittre
** File description:
** init_scene_action
*/

#include "../../../include/my_rpg/my_rpg.h"

void init_pause_action(game_t *game)
{
    object_t *object = NULL;
    map_t *map = NULL;
    sfImage *temp_bg_image = NULL;
    sfVector2u image_size = {0};
    sfVector2u miam = sfRenderWindow_getSize(game->win->renderer);

    update_scene_coord_pos(game, 0.0, 0.0);
    sfView_reset(game->win->view, (sfFloatRect){0, 0, miam.x, miam.y});
    game->current_scene->can_player_move = sfFalse;
    sfRenderWindow_setMouseCursorVisible(game->win->renderer, sfTrue);
    object = find_in_object_list(game, "map");
    if (object != NULL) {
        map = object->struct_type;
        temp_bg_image = take_screenshot(game->win->renderer);
        grey_image(temp_bg_image);
        map->image = temp_bg_image;
        image_size = sfImage_getSize(temp_bg_image);
        map->texture = sfTexture_createFromImage(temp_bg_image, NULL);
        sfSprite_setTexture(map->sprite, map->texture, sfTrue);
    }
}
