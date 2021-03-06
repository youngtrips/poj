#include <stdio.h>
#include <string.h>
#define MAX 202
int adj[MAX][MAX], ans[MAX][MAX], n;
int q_x[MAX * MAX], q_y[MAX * MAX], dis[MAX][MAX], has[MAX + MAX], head, tail;
int dx[4] = {0, 1,  0, -1};
int dy[4] = {1, 0, -1,  0};
void init()
{
	int i, j;
	scanf("%d", &n);
	for(i = 1;i <= n; i++)
		for(j = 1;j <= n; j++) scanf("%d", &adj[i][j]);
}
int check(int x, int y)
{
	return x >= 1 && x <= n && y >= 1 && y <= n && dis[x][y] == -1;
}
int bfs(int stx, int sty)
{
	int min, tx, ty, v, x, y, i, k;
	memset(has, 0, sizeof(has));
	memset(dis, -1, sizeof(dis));
	q_x[0] = stx;
	q_y[0] = sty;
	head = 0;
	tail = 1;
	dis[stx][sty] = 0;
	min = -1;
	while(head < tail)
	{
		x = q_x[head];
		y = q_y[head];
		k = dis[x][y];
		for(i = 0;i < 4; i++)
		{
			tx = x + dx[i];
			ty = y + dy[i];
			if(check(tx, ty))
			{
				if(adj[tx][ty] > 0)
				{
					has[k + 1]++;
					if(min == -1)
					{
						min = k + 1;
						v = adj[tx][ty];
					}
				}
				dis[tx][ty] = k + 1;
				q_x[tail] = tx;
				q_y[tail] = ty;
				tail++;
			}
		}
		head++;
	}
	if(min == -1) return 0;
	if(has[min] > 1) return 0;
	return v;
}
void search()
{
	int i, j, k;
	for(i = 1;i <= n; i++)
	{
		for(j = 1;j <= n; j++)
		{
			if(adj[i][j] == 0) ans[i][j] = bfs(i, j);
			else ans[i][j] = adj[i][j];
		}
	}
}
void output()
{
	int i, j;
	for(i = 1;i <= n; i++)
	{
		for(j = 1;j < n; j++) printf("%d ", ans[i][j]);
		printf("%d\n", ans[i][j]);
	}
}
int main()
{
	init();
	search();
	output();
	return 0;
}

