

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


void    fill_board(t_game *game) {
    char buffer;
    int flag = 0;

    while (read(STDIN_FILENO, &buffer, 1) == 1) {
        switch (buffer) {
            case 'w':
                if (game->i > 0)
                game->i--;
                break;
            case 's':
                if (game->i < (game->height - 1))
                game->i++;
                break;
            case 'a':
                if (game->j > 0)
                game->j--;
                break;
            case 'd':
                if (game->j < (game->width - 1))
                game->j++;
                break;
            case 'x':
                game->draw = !(game->draw);
                break;
            default:
                flag = 1;
                break;
        }
        if (game->draw && flag == 0) {
            if (((game->i >= 0) && (game->j >= 0))
                && (game->i < game->height) && (game->j < game->width))
                game->board[game->i][game->j] = game->alive;
        }
    }
}

int count_neighbors(t_game *game, int i, int j) {
    int count = 0;
    for (int di=-1; di < 2; di++) {
        for (int dj=-1; dj < 2; dj++) {
            if ((di == 0) && (dj == 0))
                continue;
            int ni = i + di;
            int nj = j + dj;
            if ((ni >= 0) && (nj >= 0)
                && (ni < game->height) && (nj < game->width)) {
                if (game->board[ni][nj] == game->alive)
                    count++;        
            }
        }
    }
    return (count);
}

int     play(t_game *game) {

    char **tmp = (char **)malloc(game->height * sizeof(char *));
    if (!tmp) return (-1);
    for (int i=0; i < game->width; i++) {
        tmp[i] = (char *)malloc(game->width * sizeof(char));
        if (!tmp[i]) return (-1);
    }
    for (int i=0; i < game->height; i++) {
        for (int j=0; j < game->width; j++) {
            int neighbor = count_neighbors(game, i, j);
            if (game->board[i][j] == game->alive) {
                if (neighbor == 2 || neighbor == 3)
                    tmp[i][j] = game->alive;
                else
                    tmp[i][j] = game->dead;
            }
            else {
                if (neighbor == 3)
                    tmp[i][j] = game->alive;
                else
                    tmp[i][j] = game->dead;
            }
        }
    }
    free_board(game);
    game->board = tmp;
    return (0);
}
void    print_board(t_game *game) {
    for (int i=0; i < game->height; i++) {
        for (int j=0; j < game->width; j++)
            putchar(game->board[i][j]);
        putchar('\n');
    }
}
void    free_board(t_game *game) {
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
        return (1);
    fill_board(&game);
    for (int i=0; i < game.iterations; i++) {
        if (play(&game) == -1)
            return (free_board(&game), 1);
    }
    print_board(&game);
    free_board(&game);
    return (0);
}

