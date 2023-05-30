/*
** EPITECH PROJECT, 2023
** B-MUL-200-STG-2-1-myrpg-florent.guittre
** File description:
** init_elems
*/

#include "../../../../include/my_rpg/my_rpg.h"

void init_textures(game_t *game)
{
    parsing_files(game, "/textures");

    my_texture_rect slot_rect = {0, 0, 70, 70, 1};
    add_texture(&game->textures_list, "player.sword",
    "./assets/images/items/sword.png", &slot_rect);
    add_texture(&game->textures_list, "item.monster_candy",
    "./assets/images/items/monster_candy.png", &slot_rect);
}

void splash_screen(sfRenderWindow *window)
{
    sfImage *image = sfImage_createFromFile("./main_screen.png");
    sfTexture *texture =
    sfTexture_createFromImage(image, &(sfIntRect){0, 0, 2400, 2400});
    sfSprite *sprite = sfSprite_create();

    sfSprite_setTexture(sprite, texture, sfTrue);
    sfRenderWindow_clear(window, sfBlack);
    sfRenderWindow_drawSprite(window, sprite, NULL);
    sfRenderWindow_display(window);
}

sfBool init_save_state(game_t *game)
{
    save_t save_filled = {0};
    int fd = open("./save/save.rpgs", O_RDONLY);
    int size = 0;

    if (fd == -1)
        return (sfFalse);
    size = read(fd, &save_filled, sizeof(save_t));
    close(fd);
    return ((size == 0) ? sfFalse : sfTrue);
}

void init_sounds(sounds_t *sounds)
{
    sounds->narrator_buffer =
    sfSoundBuffer_createFromFile("./assets/audio/narrator.ogg");
    sounds->narrator_voice = sfSound_create();
    sfSound_setBuffer(sounds->narrator_voice, sounds->narrator_buffer);
    sounds->shop_music =
    sfMusic_createFromFile("./assets/audio/shop_ambient.ogg");
    sounds->sound_volume = 100;
    sounds->music_volume = 100;
}

void init_texts(game_t *game)
{
    text_t *text = malloc(sizeof(text_t));

    text->id = "hp_text";
    text->pos = (sfVector2f){150, 850};
    text->string = malloc(sizeof(char) * (11));
    for (int i = 0; i < 11; i++)
        text->string[i] = '\0';
    text->string = my_int_to_str(game->player->current_hp);
    text->text = sfText_create();
    sfText_setFont(text->text, game->main_font);
    sfText_setCharacterSize(text->text, 25);
    sfText_setColor(text->text, sfBlack);
    sfText_setPosition(text->text, text->pos);
    sfText_setString(text->text, text->string);
    game->ui->hp_text = text;
}
