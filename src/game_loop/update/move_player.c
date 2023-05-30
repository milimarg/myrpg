/*
** EPITECH PROJECT, 2023
** B-MUL-200-STG-2-1-myrpg-florent.guittre
** File description:
** move_player.c
*/

#include "../../../include/my_rpg/my_rpg.h"

static void move_vertically(game_t *game, map_t *map, int delta)
{
    int collision = 0;
    sfVector2u pos = {0};
    sfVector2f speed = {0.f, game->player->speed * - delta};
    sfVector2f view_center = sfView_getCenter(game->win->view);

    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 13; j++) {
            pos.x = (game->current_scene->type != CASTLE) ?
            ((int)(view_center.x - 6) + j) : pos.x;
            pos.y = (game->current_scene->type != CASTLE) ?
            (int)(view_center.y - (i * delta)) : pos.y;
            collision = (check_collisions(map, &pos)) ? 1 : collision;
        }
    }
    if (!collision)
        sfView_move(game->win->view, speed);
}

static void move_horizontally(game_t *game, map_t *map, int delta)
{
    int collision = 0;
    sfVector2u pos = {0};
    sfVector2f speed = {game->player->speed * -delta, 0.f};
    sfVector2f view_center = sfView_getCenter(game->win->view);

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 36; j++) {
            pos.x = (int)view_center.x - (i * delta);
            pos.y = (int)((view_center.y - 18) + j);
            collision = (check_collisions(map, &pos)) ? 1 : collision;
        }
    }
    if (!collision)
        sfView_move(game->win->view, speed);
}

static int check_for_moves(game_t *game, char *anim_names[], map_t *map,
void (*moves[])(game_t *, map_t *, int))
{
    sfKeyCode keys[] = {game->keys[0], game->keys[1], game->keys[2],
    game->keys[3], -1};
    int keys_pushed[4] = {0};
    int deltas[] = {1, -1, 1, -1};
    int is_moving = 0;

    for (int i = 0; keys[i] != -1; i++) {
        for_one(game, keys, keys_pushed, &i);
        if (!game->player->can_i_move && sfKeyboard_isKeyPressed(keys[i])) {
            keys_pushed[i] = 1;
            game->player->current_key = keys[i];
            is_moving = 1;
            update_player_texture(game, anim_names, i);
            moves[i](game, map, deltas[i]);
            game->player->last_key = game->player->current_key;
        }
    }
    return (is_moving);
}

void move_player(game_t *game)
{
    object_t *object = NULL;
    map_t *map = NULL;
    int is_moving = 0;
    static void (*moves[])(game_t *, map_t *, int) = {&move_vertically,
    &move_vertically, &move_horizontally, &move_horizontally};
    static char *anim_names[] = {"player.up", "player.down", "player.left",
    "player.right"};

    game->player->can_i_move = 0;
    if (reset_annimation(game, game->player->current_key))
        return;
    object = find_in_object_list(game, "map");
    if (object == NULL) {
        write(2, "find in object list failed in manage view move\n", 47);
        return;
    }
    map = (map_t *)(object)->struct_type;
    if (check_for_moves(game, anim_names, map, moves))
        is_moving = 1;
    animation_player(game, is_moving, game->player->current_key);
}
