/*
** EPITECH PROJECT, 2023
** B-MUL-200-STG-2-1-myrpg-florent.guittre
** File description:
** update
*/

#include "../../../include/my_rpg/my_rpg.h"
#include "../../../include/scenes/jewels_room/prototype.h"

void update_pick_up_settings(game_t *game);
void remove_mob_from_list(game_t *game, linked_list_object_t *list);

void general_updates(game_t *game)
{
    game->player->speed = game->player->stats->dexterity / 10.0;
    update_window_ratio(game->win);
}

void update_before_list_ext(game_t *game)
{
    if (game->current_scene->type == THRONE_ROOM)
        update_throne_room(game);
    if (game->current_scene->type == MAIN_MAP)
        if (!my_strcmp(sfText_getString(game->quests->text),
        game->quests->quests[7]))
            take_flower(game);
    if (game->current_scene->can_player_move == sfTrue) {
        sfRenderWindow_setView(game->win->renderer, game->win->view);
        if (game->player->move_steps > game->player->move_steps_max) {
            game->player->move_steps = 0;
            move_player(game);
        }
    }
}

void update_before_list(game_t *game)
{
    general_updates(game);
    if (game->current_scene->type == MAGIC_TOWER)
        update_magic_tower(game);
    if (game->current_scene->type == MAIN_MAP_NIGHT)
        update_main_night(game);
    if (game->current_scene->type == CASTLE)
        update_castle(game);
    if (game->current_scene->type == JEWEL_ROOM)
        update_jewel_room(game);
    update_before_list_ext(game);
}

void update_after_list(game_t *game)
{
    static int anti_spam = 0;
    static int anti_spam2 = 0;

    if (game->current_scene->can_player_move &&
    sfKeyboard_isKeyPressed(game->keys[4]) && !anti_spam &&
    !game->dialog->run) {
        anti_spam = 1;
        switch_scene(game, INVENTORY, "inventory");
    }
    if (game->current_scene->type == INVENTORY &&
    sfKeyboard_isKeyPressed(game->keys[4]) && !anti_spam) {
        anti_spam = 1;
        switch_scene(game, game->inventory_previous_scene,
        SCENE_TYPE_ID[game->inventory_previous_scene]);
    }
    if (!sfKeyboard_isKeyPressed(game->keys[4]) && anti_spam)
        anti_spam = 0;
}

void update(game_t *game)
{
    update_before_list(game);
    for (linked_list_object_t *list = game->current_scene->object_list;
    list != NULL; list = list->next) {
        if (list->object->type == TP)
            continue;
        list->object->update(list->object->struct_type, game);
        if (list->object->type == MOB) {
            remove_mob_from_list(game, list);
        }
    }
    if (game->current_scene->type == SETTINGS && game->pick_up_mode_settings)
        update_pick_up_settings(game);
    if (game->current_scene->type == SETTINGS
    && sfKeyboard_isKeyPressed(sfKeyEscape) && !game->pick_up_mode_settings) {
        switch_scene(game, game->old_scene_type,
        SCENE_TYPE_ID[game->old_scene_type]);
    }
    update_after_list(game);
}
