/*
** EPITECH PROJECT, 2023
** B-MUL-200-STG-2-1-myrpg-florent.guittre
** File description:
** draw
*/

#include "../../../include/my_rpg/my_rpg.h"

void draw_five(game_t *game);

void draw_four(game_t *game)
{
    if (game->current_scene->type == MAZE3D) {
        my_idt1 *world =
        (my_idt1 *)game->current_scene->object_list->object->struct_type;
        sfRenderWindow_drawRectangleShape(game->win->renderer,
        world->map.ground, NULL);
        sfRenderWindow_drawRectangleShape(game->win->renderer,
        world->map.sky, NULL);
        display_world(world, game->win->renderer);
    }
    display_dialog(game->dialog, game->win);
    if (game->current_scene->can_player_move)
        sfRenderWindow_drawText(game->win->renderer, game->quests->text, NULL);
}

void draw_three(game_t *game)
{
    sfRenderWindow_setView(game->win->renderer,
    sfRenderWindow_getDefaultView(game->win->renderer));
    for (linked_list_object_t *list = game->current_scene->object_list;
    list != NULL; list = list->next) {
        if (game->already_saved && my_strcmp(list->object->id,
        "locked_continue") == 0)
            continue;
        if (list->object->type == BUTTON || list->object->type == IMAGE)
            list->object->draw(list->object->struct_type, game);
    }
    for (linked_list_object_t *list = game->current_scene->object_list;
    list != NULL; list = list->next) {
        if (game->already_saved && my_strcmp(list->object->id,
        "locked_continue") == 0)
            continue;
        if (list->object->type == TEXT)
            list->object->draw(list->object->struct_type, game);
    }

}

void draw_two(game_t *game)
{
    for (linked_list_object_t *list = game->current_scene->object_list;
    list != NULL; list = list->next) {
        if (list->object->type != BUTTON && list->object->type
        != IMAGE && list->object->type != TEXT && !my_strncmp(list->object->id,
        "capture_guard", 13))
            list->object->draw(list->object->struct_type, game);
        if (list->object->type != BUTTON && list->object->type
        != IMAGE && list->object->type != TEXT && (my_strncmp(list->object->id,
        "capture_guard", 13)
        && my_strcmp(sfText_getString(game->quests->text),
        game->quests->quests[3]) == 0))
            list->object->draw(list->object->struct_type, game);
        set_player_position(game, list);
        if (list->object->type == ENTITY)
            sfRenderWindow_drawSprite(game->win->renderer,
            game->player->entity->anim->sprite, NULL);
    }
}

void draw(game_t *game)
{
    if (game->current_scene->type != DEATH)
        sfRenderWindow_clear(game->win->renderer, sfBlack);
    else
        sfRenderWindow_clear(game->win->renderer, sfRed);
    sfRenderWindow_setView(game->win->renderer, game->win->view);
    draw_two(game);
    draw_three(game);
    draw_four(game);
    draw_five(game);
    sfRenderWindow_display(game->win->renderer);
}
