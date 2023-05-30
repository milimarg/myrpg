/*
** EPITECH PROJECT, 2023
** B-MUL-200-STG-2-1-myrpg-florent.guittre
** File description:
** move_mob
*/

// #include "../../../include/my_rpg/my_rpg.h"

// void move_sprite_mob(game_t *game, mob_t *mob)
// {
//     if (sfKeyboard_isKeyPressed(sfKeyRight)) {
//         mob->entity_mob = mob->move_mob->run_mob_right;
//         mob->move_mob->is_right = 1;
//     }
//     if (sfKeyboard_isKeyPressed(sfKeyLeft)) {
//         mob->entity_mob = mob->move_mob->run_mob_left;
//         mob->move_mob->is_right = 0;
//     }
//     add_node(sfView_getCenter(game->win->view).x,
//     sfView_getCenter(game->win->view).y, &mob->move_mob->move_list);
//     mob->move_mob->len_move++;
//     mob->mob_pos = sfSprite_getPosition(mob->entity_mob->anim->sprite);
//     if (mob->mob_pos.x >= sfView_getCenter(game->win->view).x
//     - 20 && mob->mob_pos.x <= sfView_getCenter(game->win->view).x + 20
//     && mob->mob_pos.y >= sfView_getCenter(game->win->view).y
//     - 20 && mob->mob_pos.y <= sfView_getCenter(game->win->view).y + 20)
//         mob->is_attacked = sfTrue;
//     else {
//         mob->is_attacked = sfFalse;
//         if (mob->entity_mob == mob->move_mob->mob_left
//         || mob->entity_mob == mob->move_mob->mob_right)
//             reset_entity_animation(mob->entity_mob->anim);
//     }
// }
