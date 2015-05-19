#include <stdio.h>
#define N 1001
int dis[N][N];
int map[N][N];
int q_x[N * N];
int q_y[N * N];
int dx[4] = {1, 0, -1,  0};
int dy[4] = {0, 1,  0, -1};
int head, tail, r, c;
void init()
{
	int i, j;
	scanf("%d %d", &c, &r);
	getchar();
	for(i = 0;i < r; i++)
	{
		for(j = 0;j < c; j++)
		{
			map[i][j] = getchar();
			dis[i][j] = -1;
		}
		getchar();
	}
}
int check(int x, int y)
{
	return (x >= 0 && x < r && y >= 0 && y < c &&
			map[x][y] == '.' && dis[x][y] == -1);
}
void bfs()
{
	int i, k, x1, y1;
	head = 0;
	while(head < tail)
	{
		x1 = q_x[head];
		y1 = q_y[head];
		k = dis[x1][y1];
		for(i = 0;i < 4; i++)
		{
			if(check(x1 + dx[i], y1 + dy[i]))
			{
				dis[x1 + dx[i]][y1 + dy[i]] = k + 1;
				q_x[tail] = x1 + dx[i];
				q_y[tail] = y1 + dy[i];
				tail++;
			}
		}
		head++;
	}
}
int search()
{
	int i, j, max = 0;
	for(i = 0;i < r; i++)
	{
		for(j = 0;j < c; j++)
		{
			if(map[i][j] == '.' && dis[i][j] == -1)
			{
				dis[i][j] = 0;
				q_x[0] = i;
				q_y[0] = j;
				tail = 1;
				bfs();
			}
		}
	}
	for(i = 0;i < r; i++)
		for(j = 0;j < c; j++)
			if(max < dis[i][j])
				max = dis[i][j];
	return max;
}
int main()
{
	int t, res;
	scanf("%d", &t);
	while(t--)
	{
		init();
		res = search();
		printf("Maximum rope length is %d.\n", res);
	}
	return 0;
}
