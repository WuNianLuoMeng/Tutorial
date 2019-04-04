#include <stdio.h>
#include <stdlib.h>

void 
print_circle(int map[4][4], int r, int c, int s)
{
	int end_x = c - 1 - s;
	int end_y = r - 1 - s;
	int i;
	for(i = s; i <= end_x; ++i)
		printf("%d ", map[s][i]);

	if(s < end_y) {
		for(i = s + 1; i <= end_y; ++i)
			printf("%d ", map[i][end_x]);
	}

	if(s < end_x && s < end_y) {
		for(i = end_x - 1; i >= s; --i)
			printf("%d ", map[end_y][i]);
	}

	if(s < end_x && s < end_y - 1) {
		for(i = end_y - 1; i >= s; --i)
			printf("%d ", map[i][s]);
	}
}

void
print_matirx(int map[4][4], int r, int c)
{
	if(map == NULL || r <= 0 || c <= 0)
		return;

	int s = 0;
	while(c > s * 2 && r > s * 2) {
		print_circle(map, r, c, s);
		s++;
	}
}

int
main(int argc, char *argv[])
{
	int map[4][4] = {
				{ 1,  2,  3,  4},
				{ 5,  6,  7,  8},
				{ 9, 10, 11, 12},
				{13, 14, 15, 16}
			};
	print_matirx(map, 4, 4);
	printf("\n");
	return 0;
}
