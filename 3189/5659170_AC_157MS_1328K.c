#include <stdio.h>
#include <string.h>
#define oo 0x7fffffff
#define MAXE 82002
#define MAXV 1024
#define MAXC 1002
#define MAXB 22
typedef struct {int u; int v; int f; int c; int next;}edge_t;
edge_t e[MAXE];
int first[MAXV];
int tmp[MAXE];
int now[MAXV];
int pre[MAXV];
int dis[MAXV];
int cnt[MAXV];
int ret[MAXV];
int tot, num, n, b;
void add(int u, int v, int f, int c)
{
	e[++tot].u = u; e[tot].v = v; e[tot].f = f; e[tot].c = c; e[tot].next = first[u]; first[u] = tot;
	e[++tot].u = v; e[tot].v = u; e[tot].f = 0; e[tot].c = c; e[tot].next = first[v]; first[v] = tot;
}
void init()
{
	int i, j, k, s, t;
	scanf("%d %d", &n, &b);
	memset(first, -1, sizeof(first));
	s = 0; t = n + b + 1; tot = -1;
	for(i = 1;i <= n; i++)
	{
		add(s, i, 1, 0);
		for(j = 1;j <= b; j++)
		{
			scanf("%d", &k);
			add(i, n + k, 1, j);
		}
	}
	for(i = 1;i <= b; i++)
	{
		scanf("%d", &k);
		add(n + i, t, k, 0);
	}
	num = n + b + 2;
}
int sap(int low, int high)
{
	int tot_flow, now_flow, found, min;
	int st, ed, i, j, t;
	memset(now, -1, sizeof(now));
	memset(dis, 0, sizeof(dis));
	memset(cnt, 0, sizeof(cnt));
	st = 0; ed = num - 1; i = st;
	tot_flow = 0; now_flow = oo;
	cnt[0] = num;
	while(dis[st] < num)
	{
		ret[i] = now_flow; found = 0;
		if(now[i] == -1) t = first[i];
		else t = now[i];
		while(t != -1)
		{
			j = e[t].v;
			if(((e[t].c == 0) || (low <= e[t].c && e[t].c <= high)) &&
					 e[t].f + tmp[t] > 0 && dis[j] + 1 == dis[i])
			{
				found = 1; now[i] = t;
				if(e[t].f + tmp[t] < now_flow) now_flow = e[t].f + tmp[t];
				pre[j] = t; i = j;
				if(i == ed)
				{
					tot_flow += now_flow;
					while(i != st)
					{
						tmp[pre[i]] -= now_flow;
						tmp[pre[i]^1] += now_flow;
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
			if(((e[t].c == 0) || (low <= e[t].c && e[t].c <= high)) && 
					e[t].f + tmp[t] > 0 && dis[e[t].v] < min)
			{
				min = dis[e[t].v];
				now[i] = t;
			}
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
	int ans, res, i, j;
	ans = oo; i = 1; j = 1;
	while(i <= j && j <= b)
	{
		memset(tmp, 0, sizeof(tmp));
		res = sap(i, j);
		if(res == n)
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
