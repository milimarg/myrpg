/*
** EPITECH PROJECT, 2023
** B-MUL-200-STG-2-1-myrpg-florent.guittre
** File description:
** prototype
*/

#ifndef PROTOTYPE_PLAYER_H_
    #define PROTOTYPE_PLAYER_H_

void update_player_xp(game_t *game);
void timer_attack_player(game_t *game, mob_t *mob);
void regeneration_player_hp(game_t *game);
void animation_player(game_t *game, int is_moving, sfKeyCode current_key);
int reset_annimation(game_t *game, sfKeyCode current_key);
void for_one(game_t *game, sfKeyCode *keys, int *keys_pushed, int *i);
#endif /* !PROTOTYPE_PLAYER_H_ */
