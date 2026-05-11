/*
** EPITECH PROJECT, 2026
** connect4
** File description:
** header for structures, functions, and macros used by the prog
*/

#ifndef CONFIG_C4_H_
    #define CONFIG_C4_H_
    #include <ncurses.h>
    #include <wchar.h>



    // Colors
    #define PREVIEW_COLOR 5

    // Keybinds
    #define EXIT_KEY1 'q'
    #define EXIT_KEY2 'x'

    // Events
    #define KEY_NOTHING_PRESSED 0
    #define KEY_PLAYED_EVENT 1
    #define KEY_OTHER_EVENT 2

    // Ressources
    #define EN_PATH "ressources/english_menu"
    #define FR_PATH "ressources/french_menu"
    #define SCORE_PATH "ressources/scores"

    // Resolution
    #define MINIMUM_RESOLUTION '1'
    #define MAXIMUM_RESOLUTION '4'
    #define DEFAULT_RESOLUTION '3'

    // Board
    #define OFFSET_NEXT_MOVE_X 5
    #define OFFSET_NEXT_MOVE_Y 1
    #define MAX_PLAYERS 4
    #define DEFAULT_NB_PLAYERS 2


typedef struct score {
    int p1;
    int p2;
    int p3;
    int p4;
} scores_t;

typedef struct cell {
    int taken;
    int ncurses_color;
} cell_t;

typedef struct linked_list_player_info {
    int index;  // 1-4
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
    int *last_played;  // [row, column]
    int is_ended;  // Player ID

    // For Ncurses
    int width;
    int height;
    int *proportions;  // [cell width, cell height, left offset]
    WINDOW *screen;
    int to_terminate;

} settings_t;



// -- Error handling
int error_handler(int argc, char **argv);
int verify_window_size(settings_t *settings);
int verify_scores(int display_errors);


// -- Creation functions
// initialisation
settings_t init(char mode);
void ncurses_init(settings_t *settings);
void csfml_init(settings_t *settings);
void setup_players_struct(settings_t *settings);
void setup_window_size(settings_t *settings);


// -- Board related functions
// game loop
void game_loop(settings_t *settings);
void handle_end_game(settings_t *settings);
// token templates
wchar_t **cross_pattern(wchar_t **pattern, int width, int height);
wchar_t **circle_pattern(wchar_t **pattern, int width, int height);
wchar_t **triangle_pattern(wchar_t **pattern, int width, int height);
wchar_t **square_pattern(wchar_t **pattern, int width, int height);
wchar_t **arrow_pattern(wchar_t **pattern, int width, int height);
wchar_t **four_pattern(wchar_t **pattern, int width, int height);
wchar_t **cute_cube_pattern(wchar_t **pattern, int width, int height);
// function for square token templates
wchar_t **make_a_square_with_corners
(wchar_t **pattern, wchar_t *corners, int width, int height);


// -- Data mutating functions (they change some data with calculations)
int add_token_in_col(settings_t *set, int key, int *arrow_pos, int player_turn);
int move_arrow(int key, cell_t **board, int *arrow_pos, int width);
void next_turn(int *current_turn, int nb_players);


// -- Information gathering functions
ll_player_info_t *get_player_from_turn(ll_player_info_t *player, int turn);
int is_column_filled(settings_t *settings, int column);
int is_board_filled(settings_t *settings);
int get_x_from_column(settings_t *settings, int col);
int get_y_from_row(settings_t *settings, int row);
void check_connected(settings_t *set);
int get_highest_played(settings_t *settings, int col);
// Not coding style (Epitech's)
void get_window_size(WINDOW *screen, int *x, int *y);


// -- Parsing
int get_nbr_at_index(char *str, int index);
void handle_scores(settings_t *settings);


// -- display functions
// pre game
void display_color(char *msg, char *color, int std);
void display_file_unavailable(char *filepath);
void display_help_examples(int std);
int display_help(char language);
int display_scores(void);
// in game
void display_ncurses(settings_t *settings);
void display_board(settings_t *settings, WINDOW *screen);
void display_cells(settings_t *settings);
void display_stand(settings_t *settings, WINDOW *screen);
void display_preview(settings_t *settings, WINDOW *screen);
// finish
void display_bar_horizontal(settings_t *settings);
void display_bar_vertical(settings_t *settings);
void display_bar_diagonal(settings_t *settings, int side);


// -- event handling
void wait_for_next_move(settings_t *settings);



#endif /* CONFIG_C4_H_ */
