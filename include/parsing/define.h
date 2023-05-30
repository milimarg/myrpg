/*
** EPITECH PROJECT, 2023
** B-MUL-200-STG-2-1-myrpg-florent.guittre
** File description:
** define
*/

#ifndef DEFINE_PARSING_H_
    #define DEFINE_PARSING_H_

int parsing_button(game_t *game, char **tab_arg, char *filepath);
int parsing_map(game_t *game, char **tab_arg, char *filepath);
int parsing_npc(game_t *game, char **tab_arg, char *filepath);
int parsing_tp(game_t *game, char **tab_arg, char *filepath);
int parsing_texture(game_t *game, char **tab_arg, char *filepath);
int parsing_mob(game_t *game, char **tab_arg, char *filepath);
int parsing_image(game_t *game, char **tab_arg, char *filepath);
int parsing_text(game_t *game, char **tab_arg, char *filepath);


    #define PARSING_TAB_SIZE 8
    #define POINTER_TAB_SIZE 31

const static int (*PARSING_TAB[])(game_t *, char **,
char *) = {
    &parsing_button,
    &parsing_map,
    &parsing_tp,
    &parsing_npc,
    &parsing_texture,
    &parsing_mob,
    &parsing_image,
    &parsing_text
};

const static void (*POINTER_TAB[])(void *) = {
    &button_exit,
    &button_start,
    &button_settings,
    &button_continue,
    &button_inventory,
    &button_save,
    &button_load,
    &button_save_and_quit,
    &button_sound_decrease,
    &button_sound_increase,
    &button_music_decrease,
    &button_music_increase,
    &button_set_fullscreen,
    &button_set_windowed,
    &button_resolution1,
    &button_resolution2,
    &button_back_to_main_menu,
    &button_back_to_game,
    &button_title,
    &hp_up,
    &res_up,
    &atk_up,
    &speed_up,
    &back_to_main_menu,
    &button_key_forward,
    &button_key_back,
    &button_key_left,
    &button_key_right,
    &button_key_inventory,
    &button_key_attack,
    &button_key_interact
};

#endif /* !DEFINE_PARSING_H_ */
