#include <stdio.h>
#include <memory.h>
#define N 35
char visited[N][N];
char map[N][N];
int dx[4] = {1, 0, -1,  0};
int dy[4] = {0, 1,  0, -1};
int q_x[N * N];
int q_y[N * N];
int head, tail, flag, n;
void init()
{
	int i, j;
	memset(visited, '0', sizeof(visited));
	memset(map, '#', sizeof(map));
	scanf("%d", &n);
	getchar();
	for(i = 1;i <= n; i++)
	{
		for(j = 1;j <= n; j++)
			map[i][j] = getchar();
		getchar();
	}
}
int check(int x, int y)
{
	return map[x][y] != '#' && visited[x][y] == '0';
}
int bfs()
{
	int i, x1, y1, cnt = 0;
	head = 0;
	flag = 0;
	while(head < tail)
	{
		x1 = q_x[head];
		y1 = q_y[head];
		for(i = 0;i < 4; i++)
		{
			if(check(x1 + dx[i], y1 + dy[i]))
			{
				visited[x1 + dx[i]][y1 + dy[i]] = '1';
				q_x[tail] = x1 + dx[i];
				q_y[tail] = y1 + dy[i];
				tail++;
			}
			if(map[x1 + dx[i]][y1 + dy[i]] == '#')
				cnt++;
			if(x1 + dx[i] == n && y1 + dy[i] == n)
				flag = 1;
		}
		head++;
	}
	return cnt;
}
int main()
{
	int res;
	init();
	visited[1][1] = '1';
	q_x[0] = 1;
	q_y[0] = 1;
	tail = 1;
	res = bfs() - 4;
	if(flag == 0)
	{
		memset(visited, '0', sizeof(visited));
		visited[n][n] = '1';
		q_x[0] = n;
		q_y[0] = n;
		tail = 1;
		res += bfs();
	}
	printf("%d\n", res * 9);
	return 0;
}
