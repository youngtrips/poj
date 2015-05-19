#include <stdio.h>
#define N 11
char map[N][N][N];
int dis[N][N][N];
int q_x[N * N * N];
int q_y[N * N * N];
int q_z[N * N * N];
int dx[6] = {1, -1, 0,  0, 0,  0};
int dy[6] = {0,  0, 1, -1, 0,  0};
int dz[6] = {0,  0, 0,  0, 1, -1};
int head, tail, endx, endy, endz, n;
int check(int x, int y, int z)
{
	return (x >= 0 && x < n && y >= 0 && y < n && z >= 0 && z < n &&
			map[z][x][y] == 'O' && dis[z][x][y] == -1);
}
void bfs()
{
	int i, k, x1, y1, z1;
	head = 0;
	while(head < tail)
	{
		x1 = q_x[head];
		y1 = q_y[head];
		z1 = q_z[head];
		k = dis[z1][x1][y1];
		for(i = 0;i < 6; i++)
		{
			if(check(x1 + dx[i], y1 + dy[i], z1 + dz[i]))
			{
				dis[z1 + dz[i]][x1 + dx[i]][y1 + dy[i]] = k + 1;
				q_x[tail] = x1 + dx[i];
				q_y[tail] = y1 + dy[i];
				q_z[tail] = z1 + dz[i];
				tail++;
			}
		}
		head++;
	}
}
void debug()
{
	int i, j, k;
	for(i = 0;i < n; i++)
	{
		for(j = 0;j < n; j++)
		{
			for(k = 0;k < n; k++)
				printf("%d ", dis[i][j][k]);
			printf("\n");
		}
	}
	printf("+++++++++++++++++++++++++++++++++++++++++\n");
}
int main()
{
	char str[5];
	int i, j, k, res;
	while(scanf("%s %d", str, &n) != EOF)	
	{
		getchar();
		for(i = 0;i < n; i++)
		{
			for(j = 0;j < n; j++)
			{
				for(k = 0;k < n; k++)
				{
					map[i][j][k] = getchar();
					dis[i][j][k] = -1;
				}
				getchar();
			}
		}
		//debug();
		scanf("%d %d %d", &endy, &endx, &endz);
		//printf("%d %d %d\n", endx, endy, endz);
		dis[endz][endx][endy] = 0;
		q_x[0] = endx;
		q_y[0] = endy;
		q_z[0] = endz;
		tail = 1;
		scanf("%d %d %d", &endy, &endx, &endz);
		//printf("%d %d %d\n", endx, endy, endz);
		scanf("%s", str);
		bfs();
		//debug();
		res = dis[endz][endx][endy];
		if(res == -1)
			printf("NO ROUTE\n");
		else
			printf("%d %d\n", n, res);
	}
	return 0;
}
