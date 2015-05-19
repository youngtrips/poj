#include <stdio.h>
#define N 31
char map[N][N][N];
int dis[N][N][N];
int q_x[N * N * N];
int q_y[N * N * N];
int q_z[N * N * N];
int head, tail, l, r, c, endx, endy, endz;
int dx[6] = {1, -1, 0,  0, 0,  0};
int dy[6] = {0,  0, 1, -1, 0,  0};
int dz[6] = {0,  0, 0,  0, 1, -1};
int init()
{
	int i, j, k;
	scanf("%d %d %d", &l, &r, &c);
	if(l == 0 && r == 0 && c == 0)
		return 0;
	getchar();
	for(i = 1;i <= l; i++)
	{
		for(j = 1;j <= r; j++)
		{
			for(k = 1;k <= c; k++)
			{
				map[i][j][k] = getchar();
				dis[i][j][k] = -1;
				if(map[i][j][k] == 'S')
				{
					q_x[0] = j;
					q_y[0] = k;
					q_z[0] = i;
					tail = 1;
					dis[i][j][k] = 0;
				}
				if(map[i][j][k] == 'E')
				{
					endx = j;
					endy = k;
					endz = i;
				}
			}
			getchar();
		}
		getchar();
	}
	return 1;
}
void debug()
{
	int i, j, k;
	for(i = 1;i <= l; i++)
	{
		for(j =  1;j <= r; j++)
		{
			for(k = 1;k <= c; k++)
				printf("%d ", dis[i][j][k]);
			printf("\n");
		}
		printf("\n");
	}
}
int check(int x, int y, int z)
{
	return (x >= 1 && x <= r && y >= 1 && y <= c && z >= 1 && z <= l && 
			map[z][x][y] != '#' && dis[z][x][y] == -1);
}
void bfs()
{
	int x1, y1, z1, i, k;
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

int main()
{
	int res;
	while(init())
	{	
		bfs();
		res = dis[endz][endx][endy];
		if(res == -1) printf("Trapped!\n");
		else printf("Escaped in %d minute(s).\n", res);
	}
	return 0;
}
