#include <stdio.h>
#include <string.h>
#define oo 0x7fffffff
#define MAXM 402
#define MAXN 202
typedef struct{int u; int v; int cap; int next;}edge_t;
edge_t e[MAXM + 2];
int first[MAXN];
int dist[MAXN];
int pre[MAXN];
int cnt[MAXN];
int cur[MAXN];
int tot, n;
void add(int u, int v, int cap)
{
	e[++tot].u = u; e[tot].v = v; e[tot].cap = cap; e[tot].next = first[u]; first[u] = tot;
	e[++tot].u = v; e[tot].v = u; e[tot].cap = 0; e[tot].next = first[v]; first[v] = tot;
}
int init()
{
	int m, i, j, c;
	if(scanf("%d %d", &m, &n) == EOF) return 0;
	memset(first, -1, sizeof(first));
	tot = -1;
	while(m--)
	{
		scanf("%d %d %d", &i, &j, &c);
		add(i, j, c);
	}
	return 1;
}
void sap()
{
	long long tot_flow;
	int now_flow, found, min;
	int st, ed, i, j, t, k;
	memset(dist, 0, sizeof(dist));
	memset(cnt, 0, sizeof(cnt));
	st = 1; ed = n; i = st;
	tot_flow = 0; now_flow = oo;
	cnt[0] = n;
	while(dist[st] < n)
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
	printf("%lld\n", tot_flow);
}
int main()
{
	while(init()) sap();
	return 0;
}
