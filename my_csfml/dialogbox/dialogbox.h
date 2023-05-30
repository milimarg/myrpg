/*
** EPITECH PROJECT, 2023
** B-MUL-200-STG-2-1-myrpg-florent.guittre
** File description:
** dialogbox.h
*/
#ifndef DIALOGBOX_H_
    #define DIALOGBOX_H_
    #include <SFML/Audio.h>
    #include "../lib.h"
    #include "../window/window.h"
    #define char_is_visible(c) (c >= 33 && c <= 126)

typedef enum dialog_mode {
    CINEMATIC = 0,
    DISCUSSION
} dialog_mode;

typedef struct my_dialogbox {
    int ms_delay;
    int ms_delay_punc;
    int ms_delay_current;
    int run;
    int clicked;
    int reading;
    int i;
    int text_idx;
    int skip_delay;
    int display_triangle;
    int ms_wait_delay;
    int is_begin_of_dialog;
    unsigned int character_size;
    int triangle_visibility;
    double timer;
    double thickness;
    char *punc_array;
    char *buffer;
    char *text_content;
    sfKeyCode key;
    sfVector2f triangle_pos;
    sfVector2f inner_offset;
    sfRectangleShape *gui;
    sfText *text;
    sfVertexArray *wait_triangle;
    sfColor triangle_color;
    FILE *fd;
    size_t getline_bytes;
    dialog_mode mode;
} my_dialogbox;

void push_word_to_new_line(my_dialogbox *dialog, my_window *window);
void skip_current_line(my_dialogbox *dialog, my_window *window);
void update_triangle(my_dialogbox *dialog);
void update_triangle_pos(my_dialogbox *dialog);
int check_if_char_is_punctuation(my_dialogbox *dialog);
void read_line(my_dialogbox *dialog, int run_function, ssize_t *output);

// @brief init a dialogbox (part 1 / 3)
// @param key key to interact with when displaying dialog lines
// @param ms_delay_char default delay (in ms) between each character
// @param ms_delay_punc_char delay (in ms) for each punctuation character
// @param ms_delay_wait delay (in ms) between each line of text (CINEMATIC ONLY)
// @return a pointer to a dialogbox
my_dialogbox *init_dialog(sfKeyCode key, int ms_delay_char,
int ms_delay_punc_char, int ms_delay_wait);

// @brief init a dialogbox (part 2 / 3)
// ...
void init_dialog_gui(my_dialogbox *dialog, sfFloatRect *rect,
my_window *window);

// @brief init a dialogbox (part 3 / 3)
// @param dialog dialogbox pointer created in part 1
// @param background_outline STATIC ARRAY of background and outline colors
// @param font font of the text
// @param font_size font size of the text
void init_dialog_text(my_dialogbox *dialog, sfColor background_outline[2],
sfFont *font, unsigned int font_size);

// @brief update the current displayed text, by one character
// @param dialog dialogbox pointer
// @param sound sound made when reading a character
// @param window window where to display the dialogbox
void update_dialog_text(my_dialogbox *dialog, sfSound *sound,
my_window *window);

// @brief set dialog mode (CINEMATIC or DISCUSSION)
// @param dialog dialogbox pointer
// @param mode dialog mode to set
void set_dialog_mode(my_dialogbox *dialog, dialog_mode mode);

// @brief update the dialogbox content to the next line of text
// @param dialog dialogbox pointer
// @param window window where to display the dialogbox
// @param ...
void dialog_go_to_next_line(my_dialogbox *dialog, my_window *window,
double *delay_update_line);

// @brief display the dialogbox
// @param dialog dialogbox pointer
// @param window window where to display
void display_dialog(my_dialogbox *dialog, my_window *window);

// ...
void set_triangle_visibility(my_dialogbox *dialog, int is_visible);

// @brief close the current dialog
// @param dialogbox pointer
void close_dialog(my_dialogbox *dialog);
#endif /*DIALOGBOX_H_*/
