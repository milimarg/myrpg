/*
** EPITECH PROJECT, 2023
** B-MUL-200-STG-2-1-myrpg-florent.guittre
** File description:
** struct
*/

#ifndef STRUCT_PAUSE_H_
    #define STRUCT_PAUSE_H_

typedef struct pause_object {
    int anti_spam_keyboard;
    int anti_spam_mouse;
    sfRectangleShape *filter;
    scene_type previous_scene;
} pause_object;

#endif /* !STRUCT_PAUSE_H_ */
