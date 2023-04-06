#ifndef __FT__H__
#define __FT__H__

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define R(X) rand()%X

typedef struct Coord {
	int x;
	int y;
}	coord;

// proto lee_algorithm

coord	move(int **tab, coord cell, int size, int num);
int 	check(int **tab, int size, int num, int x, int y);
int 	**lee_algorithm(int **tab, int size, coord start, coord end);
int 	**modified_tab(int **tab, int size, int num, int *count);
int 	**clear_path(int **tab, int size, coord start, coord end, int num);
int 	**clear(int **tab, int size);

// proto ft_tab

int 	**tab_init(int size);
int 	**tab_generate(int size, int **tab);
int 	**select_tab(int **tab, int n);
void	free_tab(int **tab, int size);
void	print_tab_num(int **tab, int size, coord start, coord end);
void	print_tab(int **tab, int size, coord start, coord end);
coord	select_end(int **tab, int n, coord start, coord end);
coord	select_start(int **tab, int n, coord start, coord end);
coord	find_random_point(int **tab, int size, coord cell);

#endif