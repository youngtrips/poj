#include <stdio.h>
#include <string.h>
#define oo 9999999
#define MAXN 102
int adj[MAXN][MAXN];
int fee[MAXN][MAXN];
int requ[MAXN][MAXN];
int supp[MAXN][MAXN];
int cost[MAXN][MAXN][MAXN];
int dist[MAXN];
int que[MAXN * MAXN];
int has[MAXN];
int pre[MAXN];
int cnt[MAXN];
int head, tail;
int sum, st, ed;
int n, m, k;
int init()
{
	int i, j, p;
	scanf("%d %d %d", &n, &m, &k);
	if(n == 0 && m == 0 && k == 0) return 0;
	for(i = 1;i <= n; i++)
		for(j = 1;j <= k; j++) scanf("%d", &requ[i][j]);
	for(i = 1;i <= m; i++)
		for(j = 1;j <= k; j++) scanf("%d", &supp[i][j]);
	for(p = 1;p <= k; p++)
		for(i = 1;i <= n; i++)
			for(j = 1;j <= m; j++) scanf("%d", &cost[p][i][j]);
	return 1;
}
void build(int p)
{
	int i, j;
	memset(adj, 0, sizeof(adj));
	memset(fee, 0, sizeof(fee));
	st = 0; ed = n + m + 1;
	sum = 0;
	for(i = 1;i <= n; i++)
	{
		sum += requ[i][p];
		adj[m + i][ed] = requ[i][p];
	}
	for(i = 1;i <= m; i++) adj[st][i] = supp[i][p];
	for(i = 1;i <= n; i++)
	{
		for(j = 1;j <= m; j++)
		{
			adj[j][m + i] = oo;
			fee[j][m + i] = cost[p][i][j];
			fee[m + i][j] = -cost[p][i][j];
		}
	}
}
int spfa()
{
	int i, j;
	for(i = st;i <= ed; i++) dist[i] = oo;
	memset(pre, -1, sizeof(pre));
	memset(has, 0, sizeof(has));
	memset(cnt, 0, sizeof(cnt));
	dist[st] = 0; has[st] = 1;
	que[0] = st; head = 0; tail = 1;
	while(head < tail)
	{
		i = que[head]; has[i] = 0;
		cnt[i]++; if(cnt[i] > ed) break;
		for(j = st;j <= ed; j++)
		{
			if(adj[i][j] > 0 && dist[j] > dist[i] + fee[i][j])
			{
				pre[j] = i;
				dist[j] = dist[i] + fee[i][j];
				if(has[j] == 0)
				{
					que[tail++] = j;
					has[j] = 1;
				}
			}
		}
		head++;
	}
	return dist[ed] != oo;
}
void solve()
{
	int cost, max, min, i, j;
	cost = 0;
	for(j = 1;j <= k; j++)
	{
		build(j);
		max = 0;
		while(spfa())
		{
			min = oo;
			i = ed;
			while(pre[i] != -1)
			{
				if(min > adj[pre[i]][i]) min = adj[pre[i]][i];
				i = pre[i];
			}
			max += min;
			cost += min * dist[ed];
			i = ed;
			while(pre[i] != -1)
			{
				adj[pre[i]][i] -= min;
				adj[i][pre[i]] += min;
				i = pre[i];
			}
		}
		if(max < sum) { cost = -1; break;}
	}
	printf("%d\n", cost);
}
int main()
{
	while(init()) solve();
	return 0;
}
