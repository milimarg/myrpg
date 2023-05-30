/*
** EPITECH PROJECT, 2023
** B-MUL-200-STG-2-1-myrpg-florent.guittre
** File description:
** prototype
*/

#ifndef PROTOTYPE_PARSING_H_
    #define PROTOTYPE_PARSING_H_
    #include "../my_rpg/my_rpg.h"

int parsing_files(game_t *game, char *dir_path_name);
void button_start(void *data);
void button_continue(void *data);
void button_exit(void *data);
void button_title(void *data);
void back_to_main_menu(void *data);
void speed_up(void *data);
void atk_up(void *data);
void hp_up(void *data);
void res_up(void *data);
void button_settings(void *data);
void button_inventory(void *data);
void button_back_to_game(void *data);
void button_save(void *data);
void button_load(void *data);
void button_save_and_quit(void *data);

void button_sound_decrease(void *data);
void button_sound_increase(void *data);
void button_music_decrease(void *data);
void button_music_increase(void *data);
void button_set_fullscreen(void *data);
void button_set_windowed(void *data);
void button_resolution1(void *data);
void button_resolution2(void *data);
void button_back_to_main_menu(void *data);
void button_key_forward(void *data);
void button_key_back(void *data);
void button_key_left(void *data);
void button_key_right(void *data);
void button_key_inventory(void *data);
void button_key_attack(void *data);
void button_key_interact(void *data);

#endif /* !PROTOTYPE_PARSING_H_ */
