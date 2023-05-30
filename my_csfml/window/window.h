/*
** EPITECH PROJECT, 2022
** my_csfml
** File description:
** window
*/

#ifndef WINDOW_H_
    #define WINDOW_H_
    #include <SFML/Graphics.h>
    #include "../animation/animation.h"
typedef struct my_window {
    int width;
    int height;
    int bitsPerPixel;
    char *title;
    sfRenderWindow *renderer;
    sfClock *clock;
    sfVector2f ratio;
    sfView *view;
} my_window;
typedef struct my_background {
    int width;
    int height;
    sfSprite *sprite;
} my_background;
// @brief Init a window.
// @param title title of window
// @param width width of window
// @param height of window
// @return A window structure.
my_window *create_window(char *title, sfVector2u *window_size,
unsigned int fps);

// @brief Init a background.
// @param name_tag name_tag for the background
// @param textures_list textures linked list
// @return A background structure
my_background *init_background(char *name_tag, my_textures_list *textures_list);

// @brief update the ratio values of the given window
// @param window window where to update values
// @return a structure with the new size of the window
sfVector2u update_window_ratio(my_window *window);

// @brief destroy a window
// @param window window to destroy
int destroy_window(my_window *window);

// @brief destroy a background
// @param background to destroy
int destroy_background(my_background *background);
#endif /* !WINDOW_H_ */
