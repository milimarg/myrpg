/*
** EPITECH PROJECT, 2023
** B-MUL-200-STG-2-1-myrpg-florent.guittre
** File description:
** jewels_function
*/

#include "../../../include/my_rpg/my_rpg.h"

void check_captured(game_t *game)
{
    npc_t *guard =
    (npc_t *)find_in_object_list(game, "capture_guard")->struct_type;
    sfVector2f pos_guard = sfSprite_getPosition(guard->entity->anim->sprite);
    sfVector2f pos_player =
    sfSprite_getPosition(game->player->entity->anim->sprite);

    if (!my_strcmp(sfText_getString(game->quests->text),
    game->quests->quests[3])
    && pos_guard.x - pos_player.x < 310) {
        game->current_scene->can_player_move = sfFalse;
        game->player->is_captured = sfTrue;
    }
}

void timer_jewels_room(void *data, game_t *game)
{
    static float seconds = 0;
    static int counter = 0;
    float time = sfClock_getElapsedTime(game->win->clock).microseconds
    / 1000000.0f;

    update_dialog_text(game->dialog, NULL, game->win);
    if (game->player->is_captured) {
        if (time - seconds >= 1) {
            seconds = time;
            counter++;
        }
    }
    if (counter == 3) {
        game->player->is_captured = 0;
        switch_scene(game, THRONE_ROOM, "throne_room");
        set_entity_animation(game->player->entity->anim, "player.up",
        game->textures_list);
        sfText_setString(game->quests->text, game->quests->quests[4]);
        game->quests->index = 4;
    }
}
