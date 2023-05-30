/*
** EPITECH PROJECT, 2023
** B-MUL-200-STG-2-1-myrpg-florent.guittre
** File description:
** ui_functions
*/

#include "../../../include/my_rpg/my_rpg.h"

void set_view_to_coord_pos(game_t *game)
{
    sfView_setCenter(game->win->view,
    game->coord_pos_in_scene[game->current_scene->type]);
    reset_scene_coord_pos(game);
    game->have_to_reset_view = sfFalse;
}

void update_scene_coord_pos(game_t *game, float x_off, float y_off)
{
    sfVector2f view_center = sfView_getCenter(game->win->view);

    game->coord_pos_in_scene[game->old_scene_type].x = view_center.x + x_off;
    game->coord_pos_in_scene[game->old_scene_type].y = view_center.y + y_off;
    game->have_to_reset_view = sfTrue;
}

void reset_scene_coord_pos(game_t *game)
{
    for (int i = 0; i < SCENE_TYPE_NB ; i++)
        game->coord_pos_in_scene[i] = (sfVector2f){SCENE_COORD_BASE_POS[i].x,
        SCENE_COORD_BASE_POS[i].y};
}

void init_scene_coord_pos(game_t *game)
{
    game->coord_pos_in_scene = malloc(sizeof(sfVector2f) * (SCENE_TYPE_NB));
    reset_scene_coord_pos(game);
}

void add_ui_to_list(game_t *game)
{
    add_to_object_list_end(game,
    init_object(game->ui->quest_panel, IMAGE, "quest_panel"), IMAGE);
    add_to_object_list_end(game,
    init_object(game->ui->display_health, IMAGE, "display_health"), IMAGE);
    add_to_object_list_end(game,
    init_object(game->ui->hp_text, TEXT, "hp_text"), TEXT);
}
