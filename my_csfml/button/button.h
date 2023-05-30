/*
** EPITECH PROJECT, 2023
** my_csfml_container
** File description:
** buttons
*/

#ifndef BUTTONS_H_
    #define BUTTONS_H_
    #include <SFML/System.h>
    #include <SFML/Graphics.h>
    #include "../window/window.h"
typedef enum button_state {
    NONE,
    HOVER,
    CLICKED,
    RELEASED,
} button_state;
typedef struct my_button {
    sfTexture *texture;
    sfSprite *sprite;
    sfIntRect rect;
    void (*function)(void *value);
    button_state state;
    sfText *text;
    sfColor base_color;
    sfColor hover_color;
    sfColor click_color;
} my_button;
typedef struct my_dropdown {
    sfRectangleShape *shape;
    sfIntRect rect;
    sfColor color;
    button_state state;
    my_button **buttons;
    sfText *text;
} my_dropdown;
    #define IS_HOVER(state) (state == HOVER)
    #define IS_CLICKED(state) (state == CLICKED)
    #define IS_RELEASED(state) (state == RELEASED)

// @brief Init a buttons array
// @param buttons_number number of buttons in the array
// @return a buttons array
my_button **init_buttons(unsigned int buttons_number);

// @brief Create a button
// @param rectangle rectangle of the button
// @param name_tag_and_display_name array of texture name tag and display name
// @param function function pointer
// @param textures_list textures linked list
// @return pointer to a button
my_button *add_button(sfIntRect *rectangle, char **name_tag_and_display_name,
void (*function)(void *values), my_textures_list *textures_list);

// @brief destroy a buttons array
// @param buttons buttons array to destroy
int destroy_buttons_array(my_button **buttons);

// @brief display buttons of a buttons array
// @param buttons buttons array to display
// @param window window where to display
void display_buttons(my_button **buttons, my_window *window);

// @brief update button state (CLICKED, HOVERED, NONE)
// @param window window where to check the state
// @param button button to update
void update_button_state(my_window *window, my_button *button);

// @brief init a dropdown
// @param rectangle rectangle of the dropdown
// @param color background color
// @param buttons buttons array, children elements of the dropdown
// @param display_name text to display onto the dropdown
// @return a pointer to a dropdown
my_dropdown *init_dropdown(sfIntRect *rectangle, sfColor *color,
my_button **buttons, char *display_name);

// @brief destroy a dropdown
// @param dropdown to destroy
int destroy_dropdown(my_dropdown *dp);

// @brief display a dropdown
// @param dp dropdown to display
// @param window window where to display
void display_dropdown(my_dropdown *dp, my_window *window);

// @brief update dropdown state (CLICKED, HOVERED, NONE)
// @param window window where to check
// @param dp dropdown to update
void update_dropdown_state(my_window *window, my_dropdown *dp);
#endif /* !BUTTONS_H_ */
