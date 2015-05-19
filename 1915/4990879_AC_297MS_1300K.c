#include <stdio.h>
#define N 301
int dis[N][N];
int dx[8] = { 1,  2, 2, 1, -1, -2, -2, -1};
int dy[8] = {-2, -1, 1, 2, -2, -1,  1,  2};
int q_x[N * N];
int q_y[N * N];
int head, tail, startx, starty, endx, endy, l;
int check(int x, int y)
{
	return (x >= 0 && x < l && y >= 0 && y < l && dis[x][y] == -1);
}
void bfs()
{
	int i, x1, y1, k;
	head = 0;
	while(head < tail)
	{
		x1 = q_x[head];
		y1 = q_y[head];
		k = dis[x1][y1];
		for(i = 0;i < 8; i++)
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
int main()
{
	int t, i, j;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d", &l);
		scanf("%d %d", &startx, &starty);
		scanf("%d %d", &endx, &endy);
		for(i = 0;i < l; i++)
			for(j = 0;j < l; j++)
				dis[i][j] = -1;
		dis[startx][starty] = 0;
		q_x[0] = startx;
		q_y[0] = starty;
		tail = 1;
		bfs();
		printf("%d\n", dis[endx][endy]);
	}
	return 0;
}
