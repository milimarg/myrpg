/*
** EPITECH PROJECT, 2023
** B-MUL-200-STG-2-1-myrpg-florent.guittre
** File description:
** main
*/

#include "../include/my_rpg/my_rpg.h"

void destroy_almost_all(game_t *game)
{
    sfView_destroy(game->win->view);
    destroy_window(game->win);
    destroy_container(((inventory_scene *)
    (game->inventory_object->struct_type))->container);
    destroy_textures_list(game->textures_list);
    free(game);
}

int main(void)
{
    game_t *game = malloc(sizeof(game_t));

    init_game_loop(game);
    while (sfRenderWindow_isOpen(game->win->renderer) && !game->end) {
        game_loop(game);
    }
    destroy_almost_all(game);
    return (0);
}
