/*
** EPITECH PROJECT, 2023
** B-MUL-200-STG-2-1-myrpg-florent.guittre
** File description:
** move_map_main_menu
*/

#include "../../../include/my_rpg/my_rpg.h"

static void init_move_map_main_menu(game_t *game, sfVector2u *sprite_size)
{
    map_t *ayya = NULL;

    for (linked_list_object_t *list = game->current_scene->object_list;
    list != NULL; list = list->next) {
        if (list->object->type == MAP) {
            ayya = (map_t *)list->object->struct_type;
            *sprite_size = sfTexture_getSize(ayya->texture);
        }
    }
}

static void edit_view_values(game_t *game, sfVector2f *left_top,
sfVector2f *right_bottom)
{
    static sfVector2f view_size = {0};
    static sfVector2f view_center = {0};

    view_size = sfView_getSize(game->win->view);
    view_center = sfView_getCenter(game->win->view);
    *left_top = (sfVector2f){view_center.x - (view_size.x / 2),
    view_center.y - (view_size.y / 2)};
    *right_bottom = (sfVector2f){view_center.x + (view_size.x / 2),
    view_center.y + (view_size.y / 2)};
}

static int move_manager(game_t *game, sfVector2u *sprite_size, int moves[4],
int i)
{
    static sfVector2f left_top = {0};
    static sfVector2f right_bottom = {0};

    edit_view_values(game, &left_top, &right_bottom);
    if (moves[i] == 0 && left_top.y > 0)
        sfView_move(game->win->view,
        (sfVector2f){0.f, -(game->main_menu_move_speed)});
    if (moves[i] == 1 && right_bottom.y < sprite_size->y)
        sfView_move(game->win->view,
        (sfVector2f){0.f, game->main_menu_move_speed});
    if (moves[i] == 2 && left_top.x > 0)
        sfView_move(game->win->view,
        (sfVector2f){-(game->main_menu_move_speed), 0.f});
    if (moves[i] == 3 && right_bottom.x < sprite_size->x)
        sfView_move(game->win->view,
        (sfVector2f){game->main_menu_move_speed, 0.f});
}

void move_map_main_menu(game_t *game, int *move_map_steps)
{
    static sfVector2u sprite_size = {0};
    static int idx = 0;
    static int moves[4] = {0};
    static int moves_nb = 4;
    static int a = 0;

    if (!a) {
        a = 1;
        init_move_map_main_menu(game, &sprite_size);
    }
    if (*move_map_steps > (10 * 200)) {
        *move_map_steps = 0;
        idx = rand() % 2;
        for (int i = moves_nb - 1; i >= 0; i--)
            moves[i] = rand() % 4;
    }
    for (int i = 0; i < idx + 1; i++)
        move_manager(game, &sprite_size, moves, i);
}
