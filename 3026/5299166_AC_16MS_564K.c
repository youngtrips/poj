#include <stdio.h>
#include <string.h>
#define oo 999999999
#define MAXM 128
#define MAXN  64
char map[MAXN][MAXN];
int adj[MAXM][MAXM];
int has[MAXN][MAXN];
int key[MAXM], flag[MAXM], n, x, y, r;
int q_x[MAXN * MAXN], q_y[MAXN * MAXN], head, tail;
int dis[MAXN][MAXN];
int stx[MAXM], sty[MAXM], tot;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
void init()
{
	int i, j;
	scanf("%d %d", &x, &y);
	memset(adj, 0, sizeof(adj));
	memset(has, -1, sizeof(has));
	memset(map, '#', sizeof(map));
	while(getchar() != '\n');
	tot = 1;
	for(i = 1;i <= y; i++)
	{
		for(j = 1;j <= x; j++)
		{
			map[i][j] = getchar();
			if(map[i][j] == 'A' || map[i][j] == 'S')
			{
				stx[tot] = i;
				sty[tot] = j;
				has[i][j] = tot;
				if(map[i][j] == 'S') r = tot;
				tot++;
			}
		}
		getchar();
	}
	n = tot - 1;
}
void bfs(int x0, int y0)
{
	int tx, ty, curx, cury, i, k;
	memset(dis, -1, sizeof(dis));
	dis[x0][y0] = 0;
	q_x[0] = x0;
	q_y[0] = y0;
	head = 0; tail = 1;
	while(head < tail)
	{
		curx = q_x[head];
		cury = q_y[head];
		k = dis[curx][cury];
		for(i = 0;i < 4; i++)
		{
			tx = curx + dx[i]; ty = cury + dy[i];
			if(map[tx][ty] != '#' && dis[tx][ty] == -1)
			{
				dis[tx][ty] = k + 1;
				if(has[tx][ty] != -1) adj[has[x0][y0]][has[tx][ty]] = k + 1;
				q_x[tail] = tx;
				q_y[tail] = ty;
				tail++;
			}
		}
		head++;
	}
}
int prim(int r)
{
	int ans, min, i, j, k;
	ans = 0;
	for(i = 1;i <= n; i++)
	{
		key[i] = adj[r][i];
		flag[i] = 0;
	}
	flag[r] = 1;
	for(i = 1;i < n; i++)
	{
		min = oo;
		k = 1;
		for(j = 1;j <= n; j++)
		{
			if(min > key[j] && flag[j] == 0)
			{
				min = key[j];
				k = j;
			}
		}
		flag[k] = 1;
		ans += min;
		for(j = 1;j <= n; j++) if(key[j] > adj[k][j]) key[j] = adj[k][j];
	}
	return ans;
}
int main()
{
	int t, i;
	scanf("%d", &t);
	while(t--)
	{
		init();
		for(i = 1;i < tot; i++) bfs(stx[i], sty[i]);
		printf("%d\n", prim(r));
	}
	return 0;
}
