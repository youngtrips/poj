#include <stdio.h>
#include <string.h>
#define MIN(a,b) ((a)<(b)?(a):(b))
#define oo 999999999
#define MAXN 250
int adj[MAXN][MAXN];
int dis[MAXN][MAXN];
int que[MAXN];
int has[MAXN];
int pre[MAXN];
int head, tail;
int max, k, c, m, n;
int st, ed;
void init()
{
	int i, j;
	scanf("%d %d %d", &k, &c, &m);
	n = k + c;
	for(i = 1;i <= n; i++)
	{
		for(j = 1;j <= n; j++)
		{
			scanf("%d", &dis[i][j]);
			if(dis[i][j] == 0 && i != j) dis[i][j] = oo;
		}
	}
}
void preprocess()
{
	int i, j, p;
	for(p = 1;p <= n; p++)
		for(i = 1;i <= n; i++)
			for(j = 1;j <= n; j++) dis[i][j] = MIN(dis[i][j], dis[i][p] + dis[p][j]);
	max = 0;
	for(i = 1;i <= k; i++)
		for(j = k + 1;j <= n; j++) if(max < dis[i][j]) max = dis[i][j];
	st = n + 1; ed = 0;
}
int bfs()
{
	int i, j;
	memset(has, -1, sizeof(has));
	memset(pre, -1, sizeof(pre));
	que[0] = st; head = 0; tail = 1;
	has[st] = 1;
	while(head < tail)
	{
		i = que[head];
		for(j = 0;j <= n + 1; j++)
		{
			if(adj[i][j] > 0 && has[j] == -1)
			{
				pre[j] = i;
				has[j] = 0;
				if(j == ed) return 1;
				que[tail++] = j;
			}
		}
		head++;
	}
	return 0;
}
int maxflow(int lmt)
{
	int cnt, i, j;
	memset(adj, 0, sizeof(adj));
	cnt = 0;
	for(i = 1;i <= k; i++) adj[i][ed] = m;
	for(i = k + 1;i <= n; i++) adj[st][i] = 1;
	for(i = 1;i <= k; i++)
		for(j = k + 1;j <= n; j++) if(dis[j][i] <= lmt) adj[j][i] = 1;
	while(bfs())
	{
		cnt++;
		j = ed;
		while(pre[j] != -1)
		{
			i = pre[j];
			adj[i][j]--;
			adj[j][i]++;
			j = pre[j];
		}
	}
	return cnt;
}
void solve()
{
	int high = max;
	int low = 0;
	int mid;
	while(low < high)
	{
		mid = (low + high) / 2;
		if(maxflow(mid) >= c) high = mid;
		else low = mid + 1;
	}
	printf("%d\n", low);
}
int main()
{
	init();
	preprocess();
	solve();
	return 0;
}
