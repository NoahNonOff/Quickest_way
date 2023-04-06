#include "ft.h"

/* 

Tab has only 0 and 1 (1 == obstacle)
we start Lee algorithm whith 3 --> (3, 4, 5, 6, 7, ...) (2 is the beginning)
the quickest way is mark by -1;

--> to check how it work, print with `print_tab_num(tab, size, start, end)`
    and you can remove clean function in "lee_algorithm.c"

*/

int main(void)
{
	int n = 0;
	int choose = 0;
	int **tab;
	coord	start;
	coord	end;
	end.x = -1;
	end.y = -1;

	// settings selection
	printf(" Select the map's size : ");
	scanf("%d", &n);
	while (n < 2)
	{
		printf("\n The map size should be at least 2\n Select the map's size : ");
		scanf("%d", &n);
	}

	tab = tab_init(n);
	tab = select_tab(tab, n);

	printf("\n Choose or RNG (1/0) : ");
	scanf("%d", &choose);

	start = choose?select_start(tab, n, start, end):find_random_point(tab, n, end);;
	end = choose?select_end(tab, n, start, end):find_random_point(tab, n, start);

	// algorithm
	lee_algorithm(tab, n, start, end);
	print_tab(tab, n, start, end);

	free_tab(tab, n);
	
	return 0;
}
