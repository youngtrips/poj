#include <stdio.h>
int dis[8][8];
int dx[8] = { 1,  2, 2, 1, -1, -2, -2, -1};
int dy[8] = {-2, -1, 1, 2, -2, -1,  1,  2};
int q_x[70];
int q_y[70];
int head, tail, startx, starty, endx, endy;
int check(int x, int y)
{
	return (x >= 0 && x < 8 && y >= 0 && y < 8 && dis[x][y] == -1);
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
	char str1[3], str2[3];
	int i, j;
	while(scanf("%s %s", str1, str2) != EOF)
	{
		for(i = 0;i < 8; i++)
			for(j = 0;j < 8; j++)
				dis[i][j] = -1;
		starty = str1[0] - 'a';
		startx = str1[1] - '1';
		endy = str2[0] - 'a';
		endx = str2[1] - '1';
		dis[startx][starty] = 0;
		q_x[0] = startx;
		q_y[0] = starty;
		tail = 1;
		bfs();
		printf("To get from %s to %s takes %d knight moves.\n", str1, str2, dis[endx][endy]);
	}
	return 0;
}
