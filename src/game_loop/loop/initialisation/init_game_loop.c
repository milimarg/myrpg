/*
** EPITECH PROJECT, 2023
** B-MUL-200-STG-2-1-myrpg-florent.guittre
** File description:
** init_game_loop
*/

#include "../../../../include/my_rpg/my_rpg.h"

void init_game_images(game_t *game)
{
    game->ui = malloc(sizeof(ui_t));
    game->ui->quest_panel = malloc(sizeof(image_t));
    game->ui->display_health = malloc(sizeof(image_t));

    game->ui->quest_panel->pos = (sfVector2f){0, 0};
    game->ui->quest_panel->sprite = sfSprite_create();
    sfSprite_setTexture(game->ui->quest_panel->sprite,
    find_texture_in_list(game->textures_list, "quest_panel")->texture, sfTrue);
    game->ui->display_health->pos = (sfVector2f){50, 800};
    game->ui->display_health->sprite = sfSprite_create();
    sfSprite_setTexture(game->ui->display_health->sprite,
    find_texture_in_list(game->textures_list, "display_health")->texture,
    sfTrue);
}

void init_pickup_keys(game_t *game)
{
    sfKeyCode keys[] = {sfKeyUp, sfKeyDown, sfKeyLeft, sfKeyRight, sfKeyTab,
    sfKeyZ, sfKeyE};
    game->pick_up_mode_settings = 0;
    game->pick_up_index = 0;
    game->keys = malloc(sizeof(sfKeyCode) * 7);
    for (int i = 0; i < 7; i++)
        game->keys[i] = keys[i];
}

void init_game_loop_three(game_t *game)
{
    game->sounds = malloc(sizeof(sounds_t));
    init_sounds(game->sounds);
    game->fullscreen = 0;
    game->win->ratio = (sfVector2f){1.0, 1.0};
    init_game_images(game);
    init_texts(game);
    init_pickup_keys(game);
}

void init_game_loop_two(game_t *game)
{
    sfFloatRect dialog_gui_size = {160, 500, 5, 200};
    sfColor dialog_gui_colors[4] = {sfBlack, sfWhite, sfYellow, sfYellow};
    game->main_font = sfFont_createFromFile("./assets/fonts/KELMSCOT.TTF");
    init_textures(game);
    switch_scene(game, MAIN_MENU, "main_menu");
    game->player = init_player(game);
    game->dialog_font = sfFont_createFromFile("./assets/fonts/ARIAL.TTF");
    game->filter_color = (sfColor){0, 0, 0, 255 * 0.30};
    game->anti_spam_keyboard = 0;
    game->clock_delay = 25;
    game->main_menu_move_speed = 0.025;
    game->already_saved = init_save_state(game);
    init_inventory_object(game);
    init_scene_coord_pos(game);
    game->dialog = init_dialog(sfKeySpace, 5, 500, 1000);
    set_dialog_mode(game->dialog, CINEMATIC);
    init_dialog_gui(game->dialog, &dialog_gui_size, game->win);
    init_dialog_text(game->dialog, dialog_gui_colors, game->dialog_font, 27);
    init_quests(game);
    set_triangle_visibility(game->dialog, 0);
}

void init_game_loop(game_t *game)
{
    srand(time(NULL));
    game->window_name = "Realm Of Marvin";
    game->win =
    create_window(game->window_name, &(sfVector2u){1919, 1079}, 60);
    game->current_mode = (sfVideoMode){1919, 1079, 32};
    game->end = sfFalse;
    game->window_style = sfDefaultStyle;
    splash_screen(game->win->renderer);
    game->win->view = sfView_create();
    game->previous_scene = NULL;
    game->current_scene = NULL;
    game->textures_list = init_textures_list();
    game->have_to_reset_view = sfFalse;
    init_game_loop_two(game);
    init_game_loop_three(game);
}
