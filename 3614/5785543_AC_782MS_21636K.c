#include <stdio.h>
#include <string.h>
#define oo 0x7fffffff
#define MAXM 690000
#define MAXN 5003
typedef struct{int u; int v; int cap; int next;}edge_t;
edge_t e[MAXM * 2];
int first[MAXN];
int dist[MAXN];
int now[MAXN];
int pre[MAXN];
int cnt[MAXN];
int cur[MAXN];
int tot, n;
void add(int u, int v, int cap)
{
	e[++tot].u = u; e[tot].v = v; e[tot].cap = cap; e[tot].next = first[u]; first[u] = tot;
	e[++tot].u = v; e[tot].v = u; e[tot].cap = 0; e[tot].next = first[v]; first[v] = tot;
}
void init()
{
	int covers, spf, st, ed;
	int c, l, i, j;
	scanf("%d %d", &c, &l);
	for(i = 1;i <= c; i++) scanf("%d %d", &cnt[i], &cur[i]);
	memset(first, -1, sizeof(first)); tot = -1;
	st = 1;
	ed = c + l + 2;
	for(i = 1;i <= l; i++)
	{
		scanf("%d %d", &spf, &covers);
		add(st, i + 1, covers);
		for(j = 1;j <= c; j++) if(cnt[j] <= spf && spf <= cur[j]) add(i + 1, l + j + 1, oo);
	}
	for(i = 1;i <= c; i++) add(l + i + 1, ed, 1);
	n = ed;
}
int sap()
{
	int tot_flow;
	int now_flow, found, min;
	int st, ed, i, j, t;
	memset(dist, 0, sizeof(dist));
	memset(now, -1, sizeof(now));
	memset(cnt, 0, sizeof(cnt));
	st = 1; ed = n; i = st;
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
int main()
{
	int res;
	init();
	res = sap();
	printf("%d\n", res);
	return 0;
}
