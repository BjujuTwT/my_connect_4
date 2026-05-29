/*
** EPITECH PROJECT, 2025
** connect4
** File description:
** contains all macro needed to display
** a text in a specific color
*/

#ifndef MACRO_COLORS_H_
    #define MACRO_COLORS_H_


    // Error
    #define CRIMSON "\e[38;5;88m"

    // Missing file
    #define CYAN "\x1b[38;5;6m"

    // How to : help menu
    #define PINK "\x1b[38;5;161m"
    #define BLUE "\x1b[38;5;26m"

    // Players
    #define P1 "\x1b[31m"
    #define P2 "\x1b[33m"
    #define P3 "\x1b[34m"
    #define P4 "\x1b[32m"

    // Basic color
    #define WHITE "\x1b[0m"

    // Ncurses color pairs
    #define PAIR_RED 1
    #define PAIR_YELLOW 2
    #define PAIR_BLUE 3
    #define PAIR_GREEN 4
    #define PAIR_PURPLE 5
    #define PAIR_CYAN 6
    #define PAIR_PREVIEW 8
    #define PAIR_WHITE 0


#endif /* MACRO_COLORS_H_ */
