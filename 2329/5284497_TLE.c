#include <stdio.h>
#include <string.h>
#define MAX 202
int adj[MAX][MAX], n;
int q_x[MAX * MAX], q_y[MAX * MAX], dis[MAX][MAX], has[MAX + MAX], head, tail;
int dx[4] = {0, 1,  0, -1};
int dy[4] = {1, 0, -1,  0};
int check(int x, int y) {return x >= 1 && x <= n && y >= 1 && y <= n && dis[x][y] == -1;}
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
int main()
{
	int i, j, k;
	scanf("%d", &n);
	for(i = 1;i <= n; i++)
		for(j = 1;j <= n; j++) scanf("%d", &adj[i][j]);
	for(i = 1;i <= n; i++)
	{
		for(j = 1;j < n; j++)
		{
			if(adj[i][j] == 0) k = bfs(i, j);
			else k = adj[i][j];
			printf("%d ", k);
		}
		if(adj[i][j] == 0) k = bfs(i, j);
		else k = adj[i][j];
		printf("%d\n", k);
	}
	return 0;
}
