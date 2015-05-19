#include <stdio.h>
#include <string.h>
#define MAX 1001
char map[MAX][MAX];
int dis[MAX][MAX];
int q_x[MAX * MAX];
int q_y[MAX * MAX];
int dx[4] = {1, 0, -1,  0};
int dy[4] = {0, 1,  0, -1};
int head, tail, edx, edy;
void init()
{
	int n, i, j;
	memset(map, '0', sizeof(map));
	scanf("%d %d %d", &edx, &edy, &n);
	edx += 500;
	edy += 500;
	while(n--)
	{
		scanf("%d %d", &i, &j);
		i += 500;
		j += 500;
		map[i][j] = '1';
	}
	for(i = 0;i < MAX; i++)
		for(j = 0;j < MAX; j++) dis[i][j] = -1;
}
int  check(int x, int y)
{
	return (x >= 0 && x < MAX && y >= 0 && y < MAX && dis[x][y] == -1 && map[x][y] == '0');
}
void bfs()
{
	int x, y, i, k;
	dis[500][500] = 0;
	q_x[0] = 500;
	q_y[0] = 500;
	head = 0;
	tail = 1;
	while(head < tail)
	{
		x = q_x[head];
		y = q_y[head];
		k = dis[x][y];
		for(i = 0;i < 4; i++)
		{
			if(check(x + dx[i], y + dy[i]))
			{
				dis[x + dx[i]][y + dy[i]] = k + 1;
				q_x[tail] = x + dx[i];
				q_y[tail] = y + dy[i];
				tail++;
				if(x + dx[i] == edx && y + dy[i] == edy) return;
			}
		}
		head++;
	}
}
int main()
{
	init();
	bfs();
	printf("%d\n", dis[edx][edy]);
	return 0;
}
