/*
** EPITECH PROJECT, 2023
** B-MUL-200-STG-2-1-myrpg-florent.guittre
** File description:
** tp_update
*/

#include "../../../include/my_rpg/my_rpg.h"

static char *PLAYER_ORIENTATION[] = {
    "player.up",
    "player.right",
    "player.down",
    "player.left"
};

int check_update_tp(game_t *game, tp_t *tp)
{
    if (tp->scene_type_switch == CASTLE)
        if (game->quests->index != 2)
            return (1);
    if (tp->scene_type_switch == END)
        if (game->quests->index != 9)
            return (1);
    if (tp->scene_type_switch == MAGIC_TOWER)
        if (game->quests->index != 6 && game->quests->index != 7)
            return (1);
    if (tp->scene_type_switch == MAZE)
        if (game->quests->index != 8)
            return (1);
    return (0);
}

void update_tp_to_maze3d(game_t *game, tp_t *tp)
{
    if (tp->scene_type_switch == MAZE3D) {
        item_infos info = {"star", "star", "", 1, "",
        COMMON};
        add_item(((inventory_scene *)
        (game->inventory_object->struct_type))->container, &info,
        game->textures_list);
        set_item_position_inventory((inventory_scene *)
        (game->inventory_object->struct_type));
        sfText_setString(game->quests->text, game->quests->quests[9]);
        game->quests->index = 9;
    }
}

void update_tp(void *data, game_t *game)
{
    tp_t *tp = CAST_TP(data);
    sfVector2f center_view = sfView_getCenter(game->win->view);

    if (check_update_tp(game, tp))
        return;
    if (game->current_scene->type == tp->trigger_scene) {
        if (((int)center_view.x > tp->start.x
        && (int)center_view.x < tp->end.x) &&
        ((int)center_view.y > tp->start.y
        && (int)center_view.y < tp->end.y)) {
            update_tp_to_maze3d(game, tp);
            switch_scene(game, tp->scene_type_switch,
            SCENE_TYPE_ID[tp->scene_type_switch]);
            sfView_setCenter(game->win->view,
            (sfVector2f){tp->spawn_point.x, tp->spawn_point.y});
            set_entity_animation(game->player->entity->anim,
            PLAYER_ORIENTATION[tp->orientation], game->textures_list);
        }
    }
}
