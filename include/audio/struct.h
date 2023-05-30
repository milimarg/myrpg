/*
** EPITECH PROJECT, 2023
** B-MUL-200-STG-2-1-myrpg-florent.guittre
** File description:
** struct
*/

#ifndef STRUCT_AUDIO_H_
    #define STRUCT_AUDIO_H_
typedef struct sounds_t {
    int sound_volume;
    int music_volume;
    sfSound *narrator_voice;
    sfSoundBuffer *narrator_buffer;
    sfMusic *shop_music;
    sfMusic *test_music;
} sounds_t;
#endif /* !STRUCT_AUDIO_H_ */
