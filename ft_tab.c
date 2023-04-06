#include "ft.h"

// this file contain the matrice's functions 


// INITIALIZATION
// ###########################################################

// create the matrice and initialize it
int **tab_init(int size)
{
	time_t	t1;
	srand ((unsigned) time(&t1));
	int **ret = malloc(sizeof(int *) * size);
	for (int i = 0; i < size; i++)
		ret[i] = malloc(sizeof(int) * size);

	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			ret[i][j] = (R(10)==0)?1:0;

	return ret;
}

// change value in the matrice
int **tab_generate(int size, int **tab)
{
	time_t	t1;
	srand ((unsigned) time(&t1));

	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			tab[i][j] = (R(10)==0)?1:0;

	return tab;
}

// function to give random coord
coord	find_random_point(int **tab, int size, coord cell)
{
	int r, count = 0;
	coord	ret;
	ret.y = 0;
	ret.x = 0;

	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			if (tab[i][j] == 0)
				count++;

	r = R(count);
	r = r>0?r-1:r;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (tab[i][j] == 0)
				r--;
			if (r <= 0 && !(cell.x == j && cell.y == i) && tab[i][j] == 0)
			{
				ret.x = j;
				ret.y = i;
				return ret;
			}
		}
	}
	return ret;
}

// SHOW
// ###########################################################

// main function to print the matrice (colors, edge, ...)
void	print_tab(int **tab, int size, coord start, coord end)
{
	printf("\n");
	for (int j = 0; j < size; j++)
	{
		if (j == 0)
			printf(" +--");
		else if (j == size - 1)
			printf("--+");
		else
			printf("--");
	}
	printf("\n");

	for (int i = 0; i < size; i++)
	{	
		printf(" |");
		for (int j = 0; j < size; j++)
		{
			if (start.x == j && start.y == i)
				printf("\x1B[47m  \x1B[0m");
			else if (end.x == j && end.y == i)
				printf("\x1B[40m  \x1B[0m");
			else if (tab[i][j] == 0)
				printf("\x1B[48;5;235m  \x1B[0m");
			else if (tab[i][j] == 1)
				printf("\x1B[42m  \x1B[0m");
			else
				printf("\x1B[48;5;245m  \x1B[0m");
				
		}
		printf("|");
		printf("\n");
	}
	for (int j = 0; j < size; j++)
	{
		if (j == 0)
			printf(" +--");
		else if (j == size - 1)
			printf("--+");
		else
			printf("--");
	}
	printf("\n\n");
}

// alternate function to print the tab (show the numbers in the matrice)
void	print_tab_num(int **tab, int size, coord start, coord end)
{
	printf("\n");
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (start.x == j && start.y == i)
				printf(" S ");
			else if (end.x == j && end.y == i)
				printf(" E ");
			else
			printf(" %d ", tab[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

// SELETIONS
// ###########################################################

// function used to select the start's coord
coord	select_start(int **tab, int n, coord start, coord end)
{
	int ok = 1;
	print_tab(tab, n, start, end);
	while(ok)
	{
		printf(" Select start coord (x, y) : ");
		scanf("%d %d", &start.x, &start.y);
		print_tab(tab, n, start, end);
		printf(" Change ? (yes: 1/ no: 0) : ");
		scanf("%d", &ok);
	}
	return start;
}

// function used to select the end's coord
coord	select_end(int **tab, int n, coord start, coord end)
{
	int ok = 1;
	while(ok)
	{
		printf(" Select end coord (x, y) : ");
		scanf("%d %d", &end.x, &end.y);
		while(end.x == start.x && end.y == start.y)
		{
			printf("\n End coord should be diff to start\n Select end coord (x, y) : ");
			scanf("%d %d", &end.x, &end.y);
		}
		print_tab(tab, n, start, end);
		printf(" Change ? (yes: 1/ no: 0) : ");
		scanf("%d", &ok);
	}
	return end;
}

// function used for the matrice's selection
int **select_tab(int **tab, int n)
{
	int ok = 1;
	coord	cell;
	cell.x = -1;
	cell.y = -1;

	print_tab(tab, n, cell, cell);
	printf(" New generation ? (yes: 1/ no: 0) : ");
	scanf("%d", &ok);
	while(ok)
	{
		tab = tab_generate(n, tab);
		print_tab(tab, n, cell, cell);
		printf(" New generation ? (yes: 1/ no: 0) : ");
		scanf("%d", &ok);
	}
	return tab;
}

// ###########################################################

// function to free the matrice
void	free_tab(int **tab, int size)
{
	for (int i = 0; i < size; i++)
		free(tab[i]);
	free(tab);
}