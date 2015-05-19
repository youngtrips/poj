#include <stdio.h>
#include <memory.h>
#define N 1001
char visited[N][N];
char flag[N][N];
char map[N][N];
int dx[4] = {1, 0, -1,  0};
int dy[4] = {0, 1,  0, -1};
int max, cnt, n, m;
void init()
{
	int i, j;
	memset(visited, '0', sizeof(visited));
	memset(map, '#', sizeof(map));
	scanf("%d %d", &m, &n);
	getchar();
	for(i = 1;i <= n; i++)
	{
		for(j = 1;j <= m; j++)
			map[i][j] = getchar();
		getchar();
	}
	cnt = 0;
	max = 0;
}
int check(int x, int y)
{
	if(flag[x][y] == '1') cnt++;
	return map[x][y] == '.' && visited[x][y] == '0';
}
void dfs(int x, int y)
{
	int i;
	visited[x][y] = '1';
	flag[x][y] = '1';
	for(i = 0;i < 4; i++)
	{
		if(check(x + dx[i], y + dy[i]))
		{
			cnt++;
			dfs(x + dx[i], y + dy[i]);
			if(max < cnt) max = cnt;
			cnt = 0;
		}
	}
}

int search()
{
	int i, j;
	for(i = 1;i <= n; i++)
	{
		for(j = 1;j <= m; j++)
		{
			if(map[i][j] == '.' && visited[i][j] == '0')
			{
				memset(flag, '0', sizeof(flag));
				dfs(i, j);
			}
		}
	}
	return max > 0 ? max - 1 : 0;
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
