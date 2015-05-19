#include <stdio.h>
#define MAX 301
char map[MAX][MAX];
int dis[MAX][MAX];
int q_x[MAX * MAX];
int q_y[MAX * MAX];
int dx[4] = {1, 0, -1,  0};
int dy[4] = {0, 1,  0, -1};
int head, tail, startx, starty, endx, endy, m, n;
int check(int x, int y)
{
	return (x >= 0 && x < m && y >= 0 && y < n &&
			map[x][y] != 'R' && map[x][y] != 'S' && dis[x][y] == -1);
}
void bfs()
{
	int i, k, x1, y1, tx, ty;
	head = 0;
	while(head < tail)
	{
		x1 = q_x[head];
		y1 = q_y[head];
		k = dis[x1][y1];
		for(i = 0;i < 4; i++)
		{
			tx = x1 + dx[i];
			ty = y1 + dy[i];
			if(check(tx, ty))
			{
				if(map[tx][ty] == 'B') dis[tx][ty] = k + 2;
				else dis[tx][ty] = k + 1;
				q_x[tail] = tx;
				q_y[tail] = ty;
				tail++;
			}
		}
		head++;
	}
}
int main()
{
	int i, j;
	while(1)
	{
		scanf("%d %d", &m, &n);
		if(m == 0 && n == 0) break;
		getchar();
		for(i = 0;i < m; i++)
		{
			for(j = 0;j < n; j++)
			{
				dis[i][j] = -1;
				map[i][j] = getchar();
				if(map[i][j] == 'Y')
				{
					startx = i;
					starty = j;
					dis[i][j] = 0;
					q_x[0] = i;
					q_y[0] = j;
					tail = 1;
				}
				if(map[i][j] == 'T')
				{
					endx = i;
					endy = j;
				}
			}
			getchar();
		}
		bfs();
		printf("%d\n", dis[endx][endy]);
	}
	return 0;
}
