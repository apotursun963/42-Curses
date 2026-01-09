
#include "life.h"


int init_game(t_game *game, char **argv) {
    game->width = atoi(argv[1]);
    game->height = atoi(argv[2]);
    game->iterations = atoi(argv[3]);
    game->alive = 'O';
    game->dead = ' ';
    game->i = 0;
    game->j = 0;
    game->draw = 0;
    game->board = (char **)malloc(game->height * sizeof(char *));
    if (!game->board) return (-1);
    for (int i=0; i < game->height; i++) {
        game->board[i] = (char *)malloc(game->width * sizeof(char));
        if (!game->board[i]) return (free_board(game), -1);
        for (int j=0; j < game->width; j++)
            game->board[i][j] = ' ';
    }
    return (0);
}
void fill_board(t_game *game) {

}
int play(t_game *game) {

}
void print_board(t_game *game) {
    for (int i=0; i < game->height; i++) {
        for (int j=0; j < game->width; j++) {
            putchar(game->board[i][j]);
        }
        putchar('\n');
    }
}
void free_board(t_game *game) {
    if (game->board) {
        for (int i=0; i < game->height; i++) {
            if (game->board[i])
                free(game->board[i]);
        }
        free(game->board);
    }
}

int main(int argc, char **argv) {
    
    t_game game;

    if (argc != 4 || init_game(&game, argv) == -1)
        return (-1);
    fill_board(&game);
    for (int i=0; i < game.iterations; i++) {
        if (play(&game) == -1)
            return (free_board(&game), 1);
    }
    print_board(&game);
    free_board(&game);
    return (0);
}


