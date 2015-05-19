#include <stdio.h>
#include <string.h>
#define oo 0x7fffffff
#define MAXM 160002
#define MAXN 402
typedef struct
{
	int u; int v;
	int cap; int next;
}edge_t;
edge_t e[MAXM * 2];
int map[MAXN][MAXN];
int first[MAXN];
int stack[MAXN];
int dist[MAXN];
int now[MAXN];
int pre[MAXN];
int cnt[MAXN];
int cur[MAXN];
int cut[MAXN];
int top, tot, st, ed, n2, n;
void add(int u, int v, int cap)
{
	e[++tot].u = u; e[tot].v = v; e[tot].cap = cap; e[tot].next = first[u]; first[u] = tot;
	e[++tot].u = v; e[tot].v = u; e[tot].cap = 0;   e[tot].next = first[v]; first[v] = tot;
}
void init()
{
	int i, j, k;
	scanf("%d %d %d", &n, &st, &ed);
	for(i = 1;i <= n; i++)
	{
		for(j = 1;j <= n; j++) scanf("%d", &map[i][j]);
		map[i][i] = 0;
	}
	ed += n;
	n2 = n;
	n <<= 1;
}
void build()
{
	int i, j;
	memset(first, -1, sizeof(first));
	tot = -1;
	for(i = 1;i <= n2; i++)
	{
		add(n2 + i, i, 1 - cut[i]);
		for(j = 1;j <= n2; j++) if(map[i][j]) add(i, n2 + j, oo);
	}
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
int main()
{
	int maxflow, res, i;
	init();
	if(map[st][ed - n2] == 1) printf("NO ANSWER!\n");
	else
	{
		memset(cut, 0, sizeof(cut));
		build();
		maxflow = sap();
		if(maxflow == 0) printf("0\n");
		else
		{
			printf("%d\n", maxflow);
			top = 0;
			for(i = 1;i <= n2; i++)
			{
				if(i == st || i + n2 == ed) continue;
				cut[i] = 1;
				build();
				res = sap();
				if(res < maxflow)
				{
					stack[++top] = i;
					maxflow = res;
				}
				else cut[i] = 0;
				if(res == 0) break;
			}
			for(i = 1;i < top; i++) printf("%d ", stack[i]);
			printf("%d\n", stack[top]);
		}
	}
	return 0;
}
