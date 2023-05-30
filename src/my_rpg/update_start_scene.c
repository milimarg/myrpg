/*
** EPITECH PROJECT, 2023
** B-MUL-200-STG-2-1-myrpg-florent.guittre
** File description:
** update_start_scene
*/

#include "../../include/my_rpg/my_rpg.h"
#include "../../include/scenes/start_cinematic/struct.h"

void check_display_dialogbox_attack(game_t *game, npc_t *guard)
{
    sfVector2f pos_player =
    sfSprite_getPosition(game->player->entity->anim->sprite);
    sfVector2f pos_guard = sfSprite_getPosition(guard->entity->anim->sprite);
    static int antispam = 0;
    static double delay_update_line = 0;

    if (pos_player.x - pos_guard.x > -150
    && pos_player.x - pos_guard.x < 150
    && pos_player.y - pos_guard.y > -150
    && pos_player.y - pos_guard.y < 150
    && !antispam) {
        game->dialog->fd
        = fopen("./data/scenes/start_cinematic/text/tuto_attack", "r");
        game->dialog->run = 1;
        sfText_setString(game->quests->text, game->quests->quests[1]);
        game->quests->index = 1;
        antispam = 1;
    }
    dialog_go_to_next_line(game->dialog, game->win, &delay_update_line);
}

void update_main_night(game_t *game)
{
    npc_t *guard = (npc_t *)(find_in_object_list(game, "guard")->struct_type);
    static int anti_spam_key = 0;

    if (sfView_getCenter(game->win->view).x > 705
    && sfView_getCenter(game->win->view).x < 760
    && sfView_getCenter(game->win->view).y > 820
    && sfView_getCenter(game->win->view).y < 880) {
        if (sfKeyboard_isKeyPressed(game->keys[5]) && !anti_spam_key) {
            sfSprite_setOrigin(guard->entity->anim->sprite,
            (sfVector2f){(float)(guard->entity->anim->one_texture_rect.width),
            (float)(guard->entity->anim->one_texture_rect.height)});
            sfSprite_setRotation(guard->entity->anim->sprite, 90.0);
            guard->entity->position.y += 50.0;
            anti_spam_key = 1;
            sfText_setString(game->quests->text, game->quests->quests[2]);
            game->quests->index = 2;
        }
    }
    check_display_dialogbox_attack(game, guard);
}
