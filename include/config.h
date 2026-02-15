/*
** EPITECH PROJECT, 2026
** config
** File description:
** header for structures, functions, and macros used by the prog
*/

#ifndef CONFIG_C4_H_
    #define CONFIG_C4_H_
    #include <ncurses.h>
    #include <wchar.h>


typedef struct cell {
    int taken;
    int ncurses_color;
} cell_t;

typedef struct linked_list_player_info {
    int index;
    wchar_t **pattern;
    int color;
    struct linked_list_player_info *next;
} ll_player_info_t;

typedef struct game {

    // For both
    struct linked_list_player_info *player_info;   // ^
    cell_t **board;
    int nb_players;
    int player_turn;
    int col_arrow;

    // For Ncurses
    int width;
    int height;
    int *proportions;  // [cell width, cell height, left offset]
    WINDOW *screen;
    int to_terminate; // temporary, CSFML not implemented

} settings_t;


// -- error handling
int error_handler(int argc, char **argv);


// -- board related funcs
settings_t init(char mode);
void setup_players_patterns(ll_player_info_t *player_info, int *proportions);


// -- Data mutating functions (they change some data with calculations)
int add_token_in_col(int key, cell_t **board, int *arrow_pos, int player_turn);
int move_arrow(int key, cell_t **board, int *arrow_pos, int width);
void next_turn(int *current_turn, int nb_players);


// -- display functions
// pre game
void display_color(char *msg, char *color, int std);
void display_help_examples(int std);
int display_help(char language);
// in game
void display_ncurse(settings_t *settings);
void display_cells(settings_t *settings);
void display_stand(WINDOW *screen, settings_t *settings);


// -- event handling
void wait_for_next_move(settings_t *settings);



#endif /* CONFIG_C4_H_ */
