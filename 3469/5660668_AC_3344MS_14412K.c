#include <stdio.h>
#include <string.h>
#define oo 0x7fffffff
#define MAXM 900000
#define MAXN 20004
typedef struct{ int u; int v; int f; int next;}edge_t;
edge_t e[MAXM];
int first[MAXN];
int dist[MAXN];
int now[MAXN];
int pre[MAXN];
int cnt[MAXN];
int ret[MAXN];
int tot, n;
void add(int u, int v, int f)
{
	e[++tot].u = u; e[tot].v = v; e[tot].f = f; e[tot].next = first[u]; first[u] = tot;
	e[++tot].u = v; e[tot].v = u; e[tot].f = 0; e[tot].next = first[v]; first[v] = tot;
}
void init()
{
	int i, x, y, k, s, t, m;
	scanf("%d %d", &n, &m);
	memset(first, -1, sizeof(first)); tot = -1;
	s = 0; t= n + 1;
	for(i = 1;i <= n; i++)
	{
		scanf("%d %d", &x, &y);
		add(s, i, x);
		add(i, t, y);
	}
	for(i = 1;i <= m; i++)
	{
		scanf("%d %d %d", &x, &y, &k);
		add(x, y, k);
		add(y, x, k);
	}
	n += 2;
}
int sap()
{
	int tot_flow, now_flow, found, min;
	int st, ed, i, j, t;
	memset(dist, 0, sizeof(dist));
	memset(now, -1, sizeof(dist));
	memset(cnt, 0, sizeof(cnt));
	st = 0; ed = n - 1; i = st;
	tot_flow = 0; now_flow = oo;
	cnt[0] = n;
	while(dist[st] < n)
	{
		ret[i] = now_flow; found = 0;
		if(now[i] == -1) t = first[i];
		else t = now[i];
		while(t != -1)
		{
			j = e[t].v;
			if(e[t].f > 0 && dist[j] + 1 == dist[i])
			{
				found = 1; now[i] = t;
				if(e[t].f < now_flow) now_flow = e[t].f;
				pre[j] = t; i = j;
				if(i == ed)
				{
					tot_flow += now_flow;
					while(i != st)
					{
						e[pre[i]].f -= now_flow;
						e[pre[i]^1].f += now_flow;
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
			if(e[t].f > 0 && dist[e[t].v] < min)
			{
				min = dist[e[t].v];
				now[i] = t;
			}
			t = e[t].next;
		}
		dist[i] = min + 1; cnt[dist[i]]++;
		if(i != st)
		{
			i = e[pre[i]].u;
			now_flow = ret[i];
		}
	}
	return tot_flow;
}
int main()
{
	int res;
	init();
	res = sap();
	printf("%d\n", res);
	return 0;
}
