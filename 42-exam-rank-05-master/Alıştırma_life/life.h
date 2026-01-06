
#ifndef LIFE
#define LIFE

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

typedef struct s_game {     // 9 tane değişken var
    int width;
    int height;
    int iterations;
    char alive;
    char dead;
    int i;
    int j;
    int draw;
    char **borad;
}   t_game;

// 5 tane + 1 funcs var
int     init_game(t_game *game, char **argv);
void    fill_board(t_game *game);
int     play(t_game *game);
void    print_board(t_game *game);
void    free_board(t_game *game);

#endif
