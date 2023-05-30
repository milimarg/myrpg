/*
** EPITECH PROJECT, 2023
** B-MUL-200-STG-2-1-myrpg-florent.guittre
** File description:
** update_tower
*/

#include "../../../include/my_rpg/my_rpg.h"

void update_dialog_magic_intro(game_t *game)
{
    static int antispam = 0;
    static double delay_update_line = 0;

    if (!antispam) {
        set_dialog_mode(game->dialog, DISCUSSION);
        set_triangle_visibility(game->dialog, 1);
        sfRectangleShape_setPosition(game->dialog->gui,
        (sfVector2f){sfRectangleShape_getPosition(game->dialog->gui).x, 750});
        sfText_setPosition(game->dialog->text,
        (sfVector2f){sfText_getPosition(game->dialog->text).x, 800});
        game->dialog->fd = fopen("./data/scenes/magic_tower/text/intro", "r");
        game->dialog->run = 1;
        antispam = 1;
    }
    dialog_go_to_next_line(game->dialog, game->win, &delay_update_line);
}

void update_dialog_magic_retrieve(game_t *game)
{
    static int antispam = 0;
    static double delay_update_line = 0;

    if (!antispam) {
        set_dialog_mode(game->dialog, DISCUSSION);
        set_triangle_visibility(game->dialog, 1);
        sfRectangleShape_setPosition(game->dialog->gui,
        (sfVector2f){sfRectangleShape_getPosition(game->dialog->gui).x, 750});
        sfText_setPosition(game->dialog->text,
        (sfVector2f){sfText_getPosition(game->dialog->text).x, 800});
        game->dialog->fd =
        fopen("./data/scenes/magic_tower/text/retrieve", "r");
        game->dialog->run = 1;
        remove_flowers(game);
        antispam = 1;
    }
    dialog_go_to_next_line(game->dialog, game->win, &delay_update_line);
}

void update_magic_tower(game_t *game)
{
    npc_t *merlingustin =
    (npc_t *)find_in_object_list(game, "wizard")->struct_type;
    sfVector2f pos_m = sfSprite_getPosition(merlingustin->entity->anim->sprite);
    sfVector2f pos_p = sfSprite_getPosition(game->player->entity->anim->sprite);
    static int never_seen = 1;
    int is_in_range = 0;
    if (pos_m.x - pos_p.x < 30 && pos_m.x - pos_p.x > -30
    && pos_m.y - pos_p.y > -75 && pos_m.y - pos_p.y < -20)
        is_in_range = 1;
    if (is_in_range && never_seen) {
        update_dialog_magic_intro(game);
        sfText_setString(game->quests->text, game->quests->quests[7]);
        game->quests->index = 7;
        if (game->dialog->run == 0)
            never_seen = 0;
    }
    if (is_in_range && game->quests->counter == 3) {
        update_dialog_magic_retrieve(game);
    }
    update_dialog_text(game->dialog, NULL, game->win);
}
