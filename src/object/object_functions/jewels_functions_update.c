/*
** EPITECH PROJECT, 2023
** B-MUL-200-STG-2-1-myrpg-florent.guittre
** File description:
** jewels_functions_two
*/

#include "../../../include/my_rpg/my_rpg.h"

void check_captured(game_t *game);

void update_jewel_room_ext(game_t *game)
{

}

static void get_necklace(game_t *game, int *antispamkey, my_entity *stand)
{
    if (sfKeyboard_isKeyPressed(game->keys[6]) && !*antispamkey) {
        update_animation(stand->anim);
        sfText_setString(game->quests->text, game->quests->quests[3]);
        game->quests->index = 3;
        item_infos info = {"necklace", "necklace_item", "", 1, "", NECKLACE};
        add_item(((inventory_scene *)
        (game->inventory_object->struct_type))->container, &info,
        game->textures_list);
        set_item_position_inventory((inventory_scene *)
        (game->inventory_object->struct_type));
        *antispamkey = 1;
    }
}

static void detect_player_on_necklace(int *antispamdialog, game_t *game,
int *antispamkey, my_entity *stand)
{
    static double delay_update_line = 0;

    if (!*antispamdialog) {
        set_dialog_mode(game->dialog, DISCUSSION);
        game->dialog->fd =
        fopen("./data/scenes/start_cinematic/text/tuto_interact", "r");
        game->dialog->run = 1;
        *antispamdialog = 1;
    }
    dialog_go_to_next_line(game->dialog, game->win, &delay_update_line);
    get_necklace(game, antispamkey, stand);
}

void update_jewel_room(game_t *game)
{
    static int antispam = 0;
    static int antispamdialog = 0;
    static int antispamkey = 0;
    my_entity *stand = find_in_object_list(game, "stand")->struct_type;
    sfFloatRect rect1 = sfSprite_getGlobalBounds(stand->anim->sprite);
    sfFloatRect rect2 =

    sfSprite_getGlobalBounds(game->player->entity->anim->sprite);
    if (!antispam) {
        sfView_setCenter(game->win->view,
        (sfVector2f){sfView_getCenter(game->win->view).x,
        sfView_getCenter(game->win->view).y - 210});
        sfView_zoom(game->win->view, 1.4);
        antispam = 1;
    }
    if (sfFloatRect_intersects(&rect1, &rect2, NULL))
        detect_player_on_necklace(&antispamdialog, game, &antispamkey, stand);
    check_captured(game);
}
