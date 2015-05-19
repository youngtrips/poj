#include <stdio.h>
#include <string.h>
#define oo 999999999
#define MAXM 102402
#define MAXN 320
typedef struct{ int u; int v; int f; int c; int next;}edge_t;
edge_t e[MAXM * 2];
int first[MAXN];
int tmp[MAXN][MAXN];
int que[MAXN * 2];
int has[MAXN * 2];
int dis[MAXN * 2];
int pre[MAXN * 2];
int cnt[MAXN * 2];
int head, tail, sum;
int tot, st, ed;
void add(int u, int v, int f, int c)
{
	e[++tot].u = u; e[tot].v = v; e[tot].f = f; e[tot].c = c; e[tot].next = first[u]; first[u] = tot;
	e[++tot].u = v; e[tot].v = u; e[tot].f = 0; e[tot].c = -c; e[tot].next = first[v]; first[v] = tot;
}
int init()
{
	int n, m, k;
	int i, j, x, p;
	scanf("%d %d %d", &n, &m, &k);
	if(n == 0 && m == 0 && k == 0) return 0;
	memset(first, -1, sizeof(first)); tot = -1;
	st = 0; ed = m * k + n * k + 1;
	sum = 0;
	for(i = 1;i <= n; i++)
	{
		for(j = 1;j <= k; j++)
		{
			scanf("%d", &x);
			sum += x;
			add(m * k + (i - 1) * k + j, ed, 1, 0);
		}
	}
	for(i = 1;i <= m; i++)
		for(j = 1;j <= k; j++) scanf("%d", &tmp[i][j]);
	for(p = 1;p <= k; p++)
	{
		for(i = 1;i <= n; i++)
		{
			for(j = 1;j <= m; j++)
			{
				scanf("%d", &x);
				add((j-1) * k + p, m * k + (i - 1) * k + p, tmp[j][p], x);
			}
		}
	}
	for(i = 1;i <= m * k; i++) add(st, i, oo, 0);
	return 1;
}
int spfa()
{
	int i, j, t;
	memset(pre, -1, sizeof(pre));
	memset(has, 0, sizeof(has));
	memset(cnt, 0, sizeof(cnt));
	for(i = st;i <= ed; i++) dis[i] = oo;
	dis[st] = 0; has[st] = 1;
	que[0] = st; head = 0; tail = 1;
	while(head < tail)
	{
		i = que[head]; has[i] = 0;
		cnt[i]++; if(cnt[i] > ed + 1) break;
		t = first[i];
		while(t != -1)
		{
			j = e[t].v;
			if(e[t].f > 0 && dis[j] > dis[i] + e[t].c)
			{
				dis[j] = dis[i] + e[t].c;
				pre[j] = t;
				if(has[j] == 0)
				{
					que[tail++] = j;
					has[j] = 1;
				}
			}
			t = e[t].next;
		}
		head++;
	}
	return dis[ed] != oo;
}
void solve()
{
	int cost, max, min, i, j, t;
	cost = 0; max = 0;
	while(spfa())
	{
		min = oo;
		j = ed;
		while(j != st)
		{
			if(min > e[pre[j]].f) min = e[pre[j]].f;
			j = e[pre[j]].u;
		}
		j = ed;
		cost += dis[ed];
		max += min;
		while(j != st)
		{
			e[pre[j]].f -= min;
			e[pre[j]^1].f += min;
			j = e[pre[j]].u;
		}
	}
	if(max == sum) printf("%d\n", cost);
	else printf("%d\n", -1);
}
int main()
{
	while(init()) solve();
	return 0;
}
