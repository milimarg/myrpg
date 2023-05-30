/*
** EPITECH PROJECT, 2023
** B-MUL-200-STG-2-1-myrpg-florent.guittre
** File description:
** throne_functions
*/

#include "../../../include/my_rpg/my_rpg.h"

void dialog_throne_room(game_t *game)
{
    static int antispam = 0;
    static double delay_update_line = 0;

    if (!antispam) {
        set_dialog_mode(game->dialog, DISCUSSION);
        game->dialog->fd = fopen("./data/scenes/throne_room/text/king", "r");
        game->dialog->run = 1;
        antispam = 1;
    }
    dialog_go_to_next_line(game->dialog, game->win, &delay_update_line);
}

void update_throne_room(game_t *game)
{
    int index = 0;

    dialog_throne_room(game);
    update_dialog_text(game->dialog, NULL, game->win);
    if (game->dialog->run == 0) {
        switch_scene(game, MAIN_MAP, "main_map");
        index = find_item_in_container(((inventory_scene *)
        (game->inventory_object->struct_type))->container, "necklace");
        remove_item(((inventory_scene *)
        (game->inventory_object->struct_type))->container, index);
        sfText_setString(game->quests->text, game->quests->quests[5]);
        game->quests->index = 5;
    }
}

void timer_throne_room(void *data,game_t *game)
{
}
