#include <stdio.h>
#include <memory.h>
#define N 1001
char visited[N][N];
char map[N][N];
int stack_x[N * N];
int stack_y[N * N];
int top;
int dx[4] = {1, 0, -1,  0};
int dy[4] = {0, 1,  0, -1};
int n, m;
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
}
int check(int x, int y){return map[x][y] == '.' && visited[x][y] == '0';}
int dfs()
{
	int i, x1, y1, flag, cnt = 0, max = 0;
	while(top >= 0)
	{
		x1 = stack_x[top];
		y1 = stack_y[top];
		top--;
		cnt++;
		flag = 1;
		visited[x1][y1] = '1';
		for(i = 0;i < 4; i++)
		{
			if(check(x1 + dx[i], y1 + dy[i]))
			{
				flag = 0;
				top++;
				stack_x[top] = x1 + dx[i];
				stack_y[top] = y1 + dy[i];
			}
		}
		if(flag)
		{
			if(max < cnt) max = cnt;
			cnt = 0;
		}
	}
	return max;
}
int search()
{
	int i, j, res, max = 0;
	for(i = 1;i <= n; i++)
	{
		for(j = 1;j <= m; j++)
		{
			if(map[i][j] == '.' && visited[i][j] == '0')
			{
				visited[i][j] = '1';
				stack_x[0] = i;
				stack_y[0] = j;
				top = 0;
				res = dfs();
				if(max < res) max = res;
			}
		}
	}
	return (max <= 0 ? 0 : max - 1);
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
