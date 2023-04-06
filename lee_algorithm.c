#include "ft.h"

// this file contain the lee algorithm's functions 

// check if around cells are correct
int check(int **tab, int size, int num, int x, int y)
{
	// check up
	if (y-1 >= 0 && tab[y-1][x] == num)
		return 1;

	//check down
	if (y < size-1 && tab[y+1][x] == num)
		return 1;

	// check right
	if (x < size-1 && tab[y][x+1] == num)
		return 1;

	//check left
	if (x-1 >= 0 && tab[y][x-1] == num)
		return 1;
	return 0;
}

// create the wave into the tab (start to 3 and go on)
int **modified_tab(int **tab, int size, int num, int *count)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (check(tab, size, num - 1, j, i) && tab[i][j] == 0)
			{
				tab[i][j] = num;
				(*count)++;
			}
		}
	}
	return tab;
}

//move the cell forward the good cell
coord	move(int **tab, coord cell, int size, int num)
{
	int x = cell.x;
	int y = cell.y;

	// check up
	if (y-1 >= 0 && tab[y-1][x] == num)
		cell.y--;
	//check down
	else if (y < size-1 && tab[y+1][x] == num)
		cell.y++;
	// check right
	else if (x < size-1 && tab[y][x+1] == num)
		cell.x++;
	//check left
	else if (x-1 >= 0 && tab[y][x-1] == num)
		cell.x--;

	return cell;
}

// first clean function to higlight the path (-1)
int **clear_path(int **tab, int size, coord start, coord end, int num)
{
	coord	cell = end;
	while (!(cell.x == start.x && cell.y == start.y))
	{
		cell = move(tab, cell, size, --num);
		tab[cell.y][cell.x] = -1;
	}
	return tab;
}

// second clean function to remove the wave
int **clear(int **tab, int size)
{
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			if (tab[i][j] > 1)
				tab[i][j] = 0;
	return tab;
}

// main algo to find the quickest path
int **lee_algorithm(int **tab, int size, coord start, coord end)
{
	int num = 3;
	int count = 0;
	tab[start.y][start.x] = 2;

	while (1)
	{
		count = 0;
		tab = modified_tab(tab, size, num, &count);
		if (!count || tab[end.y][end.x] == num)
			break;

		num++;
	}

	// check if the while loop was stopped by the imposibility to access to the end
	if (!count)
	{
		printf("\n \x1B[1m\x1B[31mError: Lee algorithm can't access to the end\x1B[0m\n");
		return tab;
	}

	printf("\n Quickest way is (%d)", num - 2);

	// clean functions
	tab = clear_path(tab, size, start, end, num);
	tab = clear(tab, size);
	return tab;
}