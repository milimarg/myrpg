/*
** EPITECH PROJECT, 2023
** B-MUL-200-STG-2-1-myrpg-florent.guittre
** File description:
** prototype
*/

#ifndef PROTOTYPE_PAUSE_H_
    #define PROTOTYPE_PAUSE_H_

void draw_pause(void *data, game_t *game);
void update_pause(void *data, game_t *game);
void event_pause(void *data, sfEvent event, game_t *game);
void destroy_pause(void *data, game_t *game);
void timer_pause(void *data, game_t *game);

#endif /* !PROTOTYPE_PAUSE_H_ */
