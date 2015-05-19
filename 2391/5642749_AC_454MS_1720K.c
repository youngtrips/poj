#include <stdio.h>
#include <string.h>
#define oo 999999999999999ll
#define inf 999999999
#define MAXM 1502
#define MAXN 202
typedef long long int64;
typedef struct{ int u; int v; int cap; int next;}edge_t;
edge_t e[MAXM * 100];
int64 adj[MAXN][MAXN];
int cur[MAXN + MAXN];
int first[MAXN + MAXN];
int ni[MAXN], mi[MAXN];
int dist[MAXN + MAXN];
int pre[MAXN + MAXN];
int cnt[MAXN + MAXN];
int tot, sum, num, n;
void add(int u, int v, int c)
{
	e[++tot].u = u; e[tot].v = v; e[tot].cap = c; e[tot].next = first[u]; first[u] = tot;
	e[++tot].u = v; e[tot].v = u; e[tot].cap = 0; e[tot].next = first[v]; first[v] = tot;
}
void init()
{
	int m, i, j, k;
	scanf("%d %d", &n, &m);
	for(i = 1;i <= n; i++)
		for(j = 1;j <= n; j++) adj[i][j] = (i == j ? 0 : oo);
	for(i = 1;i <= n; i++) scanf("%d %d", &ni[i], &mi[i]);
	while(m--)
	{
		scanf("%d %d %d", &i, &j, &k);
		if(adj[i][j] > k)
		{
			adj[i][j] = k;
			adj[j][i] = k;
		}
	}
	num = n; n = 2 * n + 1;
}
void floyd()
{
	int i, j, k;
	for(k = 1;k <= num; k++)
		for(i = 1;i <= num; i++)
			for(j = 1;j <= num; j++)
				if(adj[i][j] > adj[i][k] + adj[k][j]) adj[i][j] = adj[i][k] + adj[k][j];
}
void build(int64 lmt)
{
	int s, t, i, j;
	memset(first, -1, sizeof(first)); tot = -1; sum = 0;
	s = 0; t = 2 * num + 1;
	for(i = 1;i <= num; i++)
	{
		if(ni[i] > 0) add(s, 2 * i - 1, ni[i]);
		add(2 * i - 1, 2 * i, inf);
		if(mi[i] > 0) add(2 * i , t, mi[i]);
	}
	for(i = 1;i <= num; i++)
	{
		sum += ni[i];
		for(j = 1;j <= num; j++)
		{
			if(i == j) continue;
			if(adj[i][j] <= lmt)
				add(2 * i - 1, 2 * j, inf);
		}
	}
}
int sap()
{
	int tot_flow, now_flow;
	int found, min;
	int st, ed, i, j, t;
	memset(dist, 0, sizeof(dist));
	memset(cnt, 0, sizeof(cnt));
	st = 0; ed = n; i = st;
	tot_flow = 0; now_flow = inf;
	cnt[0] = n + 1;
	while(dist[st] < n + 1)
	{
		cur[i] = now_flow; found = 0;
		t = first[i];
		while(t != -1)
		{
			j = e[t].v;
			if(e[t].cap > 0 && dist[j] + 1 == dist[i])
			{
				found = 1;
				if(e[t].cap < now_flow) now_flow = e[t].cap;
				pre[j] = t; i = j;
				if(i == ed)
				{
					tot_flow += now_flow;
					while(i != st)
					{
						e[pre[i]].cap -= now_flow;
						e[pre[i]^1].cap += now_flow;
						i = e[pre[i]].u;
					}
					now_flow = inf;
				}
				break;
			}
			t = e[t].next;
		}
		if(found) continue;
		if(--cnt[dist[i]] == 0) break;
		min = n;
		t = first[i];
		while(t != -1)
		{
			if(e[t].cap > 0 && dist[e[t].v] < min) min = dist[e[t].v];
			t = e[t].next;
		}
		dist[i] = min + 1;
		cnt[dist[i]]++;
		if(i != st)
		{
			i = e[pre[i]].u;
			now_flow = cur[i];
		}
	}
	return tot_flow;
}
void solve()
{
	int64 max = 200000000000ll;
	int64 high = max;
	int64 low = 0;
	int64 mid;
	int res;
	while(low < high)
	{
		mid = (low + high) / 2;
		build(mid);
		res = sap();
		if(res >= sum) high = mid;
		else low = mid + 1;
	}
	printf("%lld\n", low == max ? -1 : low);
}
int main()
{
	init();
	floyd();
	solve();
	return 0;
}
