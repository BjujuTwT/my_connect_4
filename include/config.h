/*
** EPITECH PROJECT, 2026
** config
** File description:
** header for structures, functions, and macros used by the prog
*/

#ifndef CONFIG_C4_H_
    #define CONFIG_C4_H_
    #include <ncurses.h>


// error handling
int error_handler(int argc, char **argv);
void display_error(char *msg, char *color);


// event handling
void wait_for_next_move(WINDOW *screen);



#endif /* CONFIG_C4_H_ */
