#include <stdio.h>
#include <string.h>
#define oo 0x7fffffff
#define MAXE 50002
#define MAXV 1024
#define MAXC 1002
#define MAXB 22
typedef struct {int u; int v; int f; int next;}edge_t;
edge_t e[MAXE];
int first[MAXV];
int pre[MAXV];
int dis[MAXV];
int cnt[MAXV];
int ret[MAXV];
int cow[MAXC][MAXB];
int bar[MAXB];
int tot, num, n, b;
void add(int u, int v, int f)
{
	e[++tot].u = u; e[tot].v = v; e[tot].f = f; e[tot].next = first[u]; first[u] = tot;
	e[++tot].u = v; e[tot].v = u; e[tot].f = 0; e[tot].next = first[v]; first[v] = tot;
}
void init()
{
	int i, j, k;
	scanf("%d %d", &n, &b);
	for(i = 1;i <= n; i++)
		for(j = 1;j <= b; j++) scanf("%d", &cow[i][j]);
	for(i = 1;i <= b; i++) scanf("%d", bar + i);
	num = n + b + 2;
}
void build(int low, int high)
{
	int i, j, s, t;
	s = 0; t = num - 1; tot = -1;
	memset(first, -1, sizeof(first));
	for(i = 1;i <= n; i++)
	{
		for(j = low;j <= high; j++) add(i, n + cow[i][j], 1);
		add(s, i, 1);
	}
	for(i = 1;i <= b; i++) if(bar[i]) add(n + i, t, bar[i]);
}
int sap()
{
	int tot_flow, now_flow, found, min;
	int st, ed, i, j, t;
	memset(dis, 0, sizeof(dis));
	memset(cnt, 0, sizeof(cnt));
	st = 0; ed = num - 1; i = st;
	tot_flow = 0; now_flow = oo;
	cnt[0] = num;
	while(dis[st] < num)
	{
		ret[i] = now_flow; found = 0;
		t = first[i];
		while(t != -1)
		{
			j = e[t].v;
			if(e[t].f > 0 && dis[j] + 1 == dis[i])
			{
				found = 1;
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
		if(--cnt[dis[i]] == 0) break;
		min = num - 1;
		t = first[i];
		while(t != -1)
		{
			if(e[t].f > 0 && dis[e[t].v] < min) min = dis[e[t].v];
			t = e[t].next;
		}
		dis[i] = min + 1; cnt[dis[i]]++;
		if(i != st)
		{
			i = e[pre[i]].u;
			now_flow = ret[i];
		}
	}
	return tot_flow;
}
void solve()
{
	int ans, tmp, i, j;
	ans = oo; i = 1; j = 1;
	while(i <= j && j <= b)
	{
		build(i, j);
		tmp = sap();
		if(tmp == n)
		{
			if(ans > j - i + 1) ans = j - i + 1;
			i++;
		}
		else j++;
	}
	printf("%d\n", ans);
}
int main()
{
	init();
	solve();
	return 0;
}
