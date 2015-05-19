#include <stdio.h>
#include <string.h>
#define oo 0x7fffffff
#define MAXM 100502
#define MAXN 208
typedef struct
{
	int u; int v; int cap; int next;
}edge_t;
edge_t e[MAXM];
int first[MAXN];
char adj[MAXN][MAXN];
int dist[MAXN];
int now[MAXN];
int pre[MAXN];
int cnt[MAXN];
int cur[MAXN];
int vec[MAXN + MAXN][2];
int tot, st, ed, n2, n;
void add(int u, int v, int cap)
{
	e[++tot].u = u; e[tot].v = v; e[tot].cap = cap; e[tot].next = first[u]; first[u] = tot;
	e[++tot].u = v; e[tot].v = u; e[tot].cap = 0;	e[tot].next = first[v]; first[v] = tot;
}
void init()
{
	int i, j, k, m;
	scanf("%d %d", &n, &m);
	memset(first, -1, sizeof(first));
	memset(adj, 0, sizeof(adj));
	tot = -1; n2 = n; st = 0; ed = n + n + 1;
	for(i = 1;i <= n; i++)
	{
		scanf("%d", &k);
		add(n + i, ed, k);
	}
	for(i = 1;i <= n; i++)
	{
		scanf("%d", &k);
		add(st, i, k);
	}
	while(m--)
	{
		scanf("%d %d", &i, &j);
		if(adj[i][j] == 0)
		{
			adj[i][j] = 1;
			add(i, n + j, oo);
		}
	}
	n = n * 2 + 2;
}
int sap()
{
	int tot_flow;
	int now_flow, found, min;
	int i, j, t;
	memset(dist, 0, sizeof(dist));
	memset(now, -1, sizeof(now));
	memset(cnt, 0, sizeof(cnt));
	i = st;
	tot_flow = 0; now_flow = oo;
	cnt[0] = n;
	while(dist[st] < n)
	{
		cur[i] = now_flow; found = 0;
		if(now[i] == -1) t = first[i];
		else t = now[i];
		while(t != -1)
		{
			j = e[t].v;
			if(e[t].cap > 0 && dist[j] + 1 == dist[i])
			{
				found = 1; now[i] = t;
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
					now_flow = oo;
				}
				break;
			}
			t = e[t].next;
		}
		if(found) continue;
		if(--cnt[dist[i]] == 0) break;
		min = n - 1;
		t = first[i];
		while(t != -1)
		{
			if(e[t].cap > 0 && dist[e[t].v] < min)
			{
				min = dist[e[t].v];
				now[i] = t;
			}
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
void dfs(int u)
{
	int v, t;
	cnt[u] = 1;
	t = first[u];
	while(t != -1)
	{
		v = e[t].v;
		if(e[t].cap > 0 && cnt[v] == 0) dfs(v);
		t = e[t].next;
	}
}
void solve()
{
	int ans, num, i, j;
	ans = sap();
	printf("%d\n", ans);
	memset(cnt, 0, sizeof(cnt));
	dfs(st);
	num = 0;
	for(i = 0;i <= tot; i++)
	{
		if((i & 1)) continue;
		if(cnt[e[i].u] != cnt[e[i].v])
		{
			if(e[i].u == st)
			{
				num++;
				vec[num][0] = e[i].v;
				vec[num][1] = 0;
			}
			if(e[i].v == ed)
			{
				num++;
				vec[num][0] = e[i].u - n2;
				vec[num][1] = 1;
			}
		}
	}
	printf("%d\n", num);
	for(i = 1;i <= num; i++) printf("%d %c\n", vec[i][0], (vec[i][1] == 0 ? '-' : '+'));
}
int main()
{
	init();
	solve();
	return 0;
}
