
#include "life.h"

int init_game(t_game* game, char** argv) {
	game->width = atoi(argv[1]);
	game->height = atoi(argv[2]);
	game->iterations = atoi(argv[3]);
	game->alive = 'O';	// 0 mı yoksa O mu karar ver
	game->dead = ' ';
	game->i = 0;
	game->j = 0;
	game->draw = 0;	// başta çizim kapalı 0 (açık ise 1)
	game->board = (char**)malloc((game->height) * sizeof(char *));	// Tahta için bellek ayırma (2D array)
	if(!(game->board))
		return(-1);
	for(int i = 0; i < game->height; i++) {
		game->board[i] = (char *)malloc((game->width) * sizeof(char));	// Her satır için bellek ayırma
		if(!(game->board[i])) {
			free_board(game);
			return(-1);
		}
		for(int j = 0; j < game->width; j++)
			game->board[i][j] = ' ';	// Tüm hücreler başlangıçta ölü
	}
	return(0);
}

/*
Oyun durumu, imleç konumu ve tahta bilgileri burada tutuluyor.
i -> satır indexidir
j -> sütün indexidir
*/
void fill_board(t_game* game) {
	char buffer;
	int flag = 0;	// girilen tuşun geçerli bir kontrol tuşu olup olmadığını ayırt etmek için

	while(read(STDIN_FILENO, &buffer, 1) == 1) {	// Her seferinde 1 byte / 1 karakter okunur
		switch (buffer) {	// w, s, a, d -> Bu kontroller sayesinde imleç tahta sınırları dışına çıkamaz.
		case 'w':
			if(game->i > 0)	// Tahtanın üst sınırını geçmez
			game->i--;
			break;
		case 's':
			if(game->i < (game->height - 1))	// Tahtanın alt sınırını geçmez
			game->i++;
			break;
		case 'a':
			if(game->j > 0)	// Tahtanın sağ sütününü geçme
			game->j--;
			break;
		case 'd':
			if(game->j < (game->width - 1))	// Tahtanın sol sütününü geçme
			game->j++;
			break;
		case 'x':
			game->draw = !(game->draw);		
			break;
		default:	// Geçersiz tuşlar (w,s,a,d,x dışında tuşlar gelirse o zaman flag = 1)
			flag = 1;
			break;
		}
		if(game->draw && (flag == 0)) {	// çizim modu açık ve geçerli bir tuş varsa o zaman if'e gir
			if((game->i >= 0 ) && (game->i < game->height)		// Sınır kontrolü
				&& (game->j >= 0) && (game->j < game->width))
				game->board[game->i][game->j] = game->alive;	// İmlecin olduğu hücre canlı olur
		}
	}
}

int count_neighbors(t_game* game, int i, int j) {
	int count = 0;
	for(int di = -1; di < 2; di++) {
		for(int dj = -1; dj < 2; dj++) {
			if((di == 0) && (dj == 0))
				continue;
			int ni = i + di;
			int nj = j + dj;
			if((ni >= 0) && (nj >=0) 
				&& (ni < game->height) && (nj < game->width)) {
				if(game->board[ni][nj] == game->alive)
					count++;
			}
		}
	}
	return(count);
}

int play(t_game* game) {
	char** temp = (char**)malloc((game->height) * sizeof(char *));
	if(!temp)
		return(-1);
	for(int i = 0; i < game->height; i++) {
		temp[i] = (char *)malloc((game->width) * sizeof(char));
		if(!(temp[i]))
			return(-1); 
	}
	for(int i = 0; i < game->height; i++) {
		for(int j = 0; j < game->width; j++) {
			int neighbors = count_neighbors(game, i, j);
			if(game->board[i][j] == game->alive) {
				if(neighbors == 2 || neighbors == 3)
					temp[i][j] = game->alive;
				else
					temp[i][j] = game->dead;
			}
			else {
				if(neighbors == 3)
					temp[i][j] = game->alive;
				else
					temp[i][j] = game->dead;
			}
		}
	}
	free_board(&game);
	game->board = temp;
	return(0);
}

void print_board(t_game* game) {
	for(int i = 0; i < game->height; i++) {
		for(int j = 0; j < game->width; j++)
			putchar(game->board[i][j]);
		putchar('\n');
	}
}

void free_board(t_game* game) {
	if(game->board) {
		for(int i = 0; i < game->height; i++) {
			if(game->board[i])
				free(game->board[i]);
		}
		free(game->board);
	}
}

int main(int argc, char** argv)
{
	t_game game;

	if (argc != 4 || init_game(&game, argv) == -1)
		return (1);
	fill_board(&game);
	for(int i = 0; i < game.iterations; i++) {
		if(play(&game) == -1) {
			free_board(&game);
			return(1);
		}
	}
	print_board(&game);
	free_board(&game);
	return (0);
}

