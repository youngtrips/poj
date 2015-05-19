#include <stdio.h>
#define BESSIE 0
#define KNIGHT 1
#define N 1001
int map[N][N];
int b[N][N];
int k[N][N];
int q_x[N * N];
int q_y[N * N];
int dx[4] = {1, 0, -1,  0};
int dy[4] = {0, 1,  0, -1};
int head, tail, w, h, bx, by, kx, ky;

void init()
{
	int i, j;
	scanf("%d %d", &w, &h);
	for(i = 0;i < h; i++)
	{
		for(j = 0;j < w; j++)
		{
			b[i][j] = -1;
			k[i][j] = -1;
			scanf("%d", &map[i][j]);
			if(map[i][j] == 2)
			{
				b[i][j] = 0;
				bx = i;
				by = j;
			}
			if(map[i][j] == 3)
			{
				k[i][j] = 0;
				kx = i;
				ky = j;
			}
		}
	}
}
int check(int x, int y, int flag)
{
	int res;
	if(flag == BESSIE) res = b[x][y];
	else res = k[x][y];
	return (x >= 0 && x < h && y >= 0 && y < w && map[x][y] != 1 && res == -1);
}
void bfs(int x, int y, int flag)
{
	int i, v, x1, y1;
	q_x[0] = x;
	q_y[0] = y;
	head = 0;
	tail = 1;
	while(head < tail)
	{
		x1 = q_x[head];
		y1 = q_y[head];
		if(flag == BESSIE)
			v = b[x1][y1];
		else
			v = k[x1][y1];
		for(i = 0;i < 4; i++)
		{
			if(check(x1 + dx[i], y1 + dy[i], flag))
			{
				if(flag == BESSIE)
					b[x1 + dx[i]][y1 + dy[i]] = v + 1;
				else
					k[x1 + dx[i]][y1 + dy[i]] = v + 1;
				q_x[tail] = x1 + dx[i];
				q_y[tail] = y1 + dy[i];
				tail++;
			}
		}
		head++;
	}
}

void debug(int flag)
{
	int i, j;
	for(i = 0;i < h; i++)
	{
		for(j = 0;j < w; j++)
		{
			if(flag == BESSIE)
				printf("%d ", b[i][j]);
			else if(flag == KNIGHT)
				printf("%d ", k[i][j]);
			else
				printf("%d ", map[i][j]);
		}
		printf("\n");
	}
}

int search()
{
	int i, j, res, min = 2000000;
	bfs(bx, by, BESSIE);
	bfs(kx, ky, KNIGHT);
	for(i = 0;i < h; i++)
	{
		for(j = 0;j < w; j++)
		{
			if(map[i][j] == 4)
			{
				res = b[i][j] + k[i][j];
				if(min > res)
					min = res;
			}
		}
	}
	return min;
}
int main()
{
	init();
	printf("%d\n", search());
	return 0;
}
