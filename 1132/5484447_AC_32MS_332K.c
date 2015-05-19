#include <stdio.h>
#include <string.h>
#define MAX 33
char bitmap[MAX][MAX];
int x;
int y;
void set(char cmd)
{
	int x1, x2, x3, x4;
	int y1, y2, y3, y4;
	int x0, y0;
	x1 = x; y1 = y;
	switch(cmd)
	{
		case 'W':
			x2 = x;
			y2 = y+1;
			x--;
			x3 = x;
			y3 = y;
			x4 = x;
			y4 = y+1;
			break;
		case 'E':
			x2 = x;
			y2 = y-1;
			x++;
			x3 = x;
			y3 = y;
			x4 = x;
			y4 = y-1;
			break;
		case 'N':
			x2 = x+1;
			y2 = y;
			y++;
			x3 = x;
			y3 = y;
			x4 = x+1;
			y4 = y;
			break;
		case 'S':
			x2 = x-1;
			y2 = y;
			y--;
			x3 = x;
			y3 = y;
			x4 = x-1;
			y4 = y;
			break;
	}
	x0 = (x1 + x2 + x3 + x4) / 4 + 1;
	y0 = (y1 + y2 + y3 + y4) / 4 + 1;
	bitmap[y0][x0] = 'X';
}
void init()
{
	char cmd;
	memset(bitmap, '.', sizeof(bitmap));
	scanf("%d %d", &x, &y);
	getchar();
	while(1)
	{
		cmd = getchar();
		if(cmd == '.') break;
		set(cmd);
	}
}
void output()
{
	int i, j;
	for(i = 32;i >= 1; i--)
	{
		for(j = 1;j <= 32; j++) printf("%c", bitmap[i][j]);
		printf("\n");
	}
}
int main()
{
	int n, i;
	scanf("%d", &n);
	for(i = 1;i <= n; i++)
	{
		init();
		printf("Bitmap #%d\n", i);
		output();
		printf("\n");
	}
	return 0;
}
