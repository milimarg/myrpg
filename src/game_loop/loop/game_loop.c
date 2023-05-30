/*
** EPITECH PROJECT, 2023
** B-MUL-200-STG-2-1-myrpg-florent.guittre
** File description:
** game_loop
*/

#include "../../../include/my_rpg/my_rpg.h"

void manage_tp(game_t *game)
{
    sfVector2f center_view = sfView_getCenter(game->win->view);

    for (linked_list_object_t *list = game->current_scene->object_list;
    list != NULL; list = list->next) {
        if (list->object->type == TP) {
            list->object->update(list->object->struct_type, game);
        }
    }
}

void manage_death(game_t *game)
{
    if (game->player->current_hp <= 0 && game->current_scene->type != DEATH) {
        switch_scene(game, DEATH, "death");
        game->player->current_hp = game->player->stats->hp;
        update_player_hp_display(game);
    }
}

void game_loop(game_t *game)
{
    static sfInt64 clock_time = 0;
    static sfInt64 current_time = 0;

    clock_time = sfClock_getElapsedTime(game->win->clock).microseconds / 1000;
    manage_death(game);
    manage_tp(game);
    event(game);
    if (clock_time - current_time > game->clock_delay) {
        current_time = clock_time;
        timer(game);
    }
    update(game);
    regeneration_player_hp(game);
    draw(game);
}
