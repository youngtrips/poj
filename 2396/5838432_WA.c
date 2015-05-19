#include <stdio.h>
#include <string.h>
#define oo 0x7fffffff
#define MAXN 602
typedef struct
{
	int u; int v; int cap; int next;
}edge_t;
edge_t e[MAXN * MAXN];
int max[MAXN][MAXN];
int min[MAXN][MAXN];
int flow[MAXN][MAXN];
int first[MAXN];
int dist[MAXN];
int now[MAXN];
int pre[MAXN];
int cnt[MAXN];
int cur[MAXN];
int row[MAXN];
int col[MAXN];
int sum, tot, st, ed;
int m, n, x, y;
void add(int u, int v, int cap)
{
	e[++tot].u = u; e[tot].v = v; e[tot].cap = cap; e[tot].next = first[u]; first[u] = tot;
	e[++tot].u = v; e[tot].v = u; e[tot].cap = 0;   e[tot].next = first[v]; first[v] = tot;
}
void modify(char ch, int x, int y, int d)
{
	switch(ch)
	{
		case '>': if(min[x][y] < d + 1) min[x][y] = d + 1; break;
		case '=': max[x][y] = d; min[x][y] = d; break;
		case '<': if(max[x][y] > d - 1) max[x][y] = d - 1; break;
	}
}
void init()
{
	char str[2];
	int i, j, k, c, x, y;
	scanf("%d %d", &m, &n);
	st = 0; ed = m + n + 1; sum = 0;
	for(i = st;i <= ed; i++) for(j = st;j <= ed; j++) { max[i][j] = oo; min[i][j] = 0;}
	for(i = 1;i <= m; i++)
	{
		scanf("%d", &k);
		max[st][i] = k;
		min[st][i] = k;
		sum += k;
	}
	for(i = 1;i <= n; i++)
	{
		scanf("%d", &k);
		max[i][ed] = k;
		min[i][ed] = k;
		sum += k;
	}
	scanf("%d", &c);
	while(c--)
	{
		scanf("%d %d %s %d", &x, &y, str, &k);
		if(x == 0 && y == 0) for(i = 1;i <= m; i++) for(j = 1;j <= n; j++) modify(str[0], i, j, k);
		else if(x == 0) for(i = 1;i <= m; i++) modify(str[0], i, y, k);
		else if(y == 0) for(j = 1;j <= n; j++) modify(str[0], x, j, k);
		else modify(str[0], x, y, k);
	}
}
void build()
{
	int i, j;
	memset(first, -1, sizeof(first)); tot = -1;
	st = m + n + 2; ed = m + n + 3;
	x = m; y = n;
	for(i = 1;i <= m; i++)
	{
		add(0, i, max[0][i] - min[0][i]);
		add(st, i, min[0][i]);
		add(0, ed, min[0][i]);
		for(j = 1;j <= n; j++)
		{
			add(i, m + j, max[i][j] - min[i][j]);
			add(st, m + j, min[i][j]);
			add(i, ed, min[i][j]);
		}
	}
	for(j = 1;j <= n; j++)
	{
		add(m + j, m + n + 1, max[j][m + n + 1] - min[j][m + n + 1]);
		add(st, m + n + 1, min[j][m + n + 1]);
		add(m + j, ed, min[j][m + n + 1]);
	}
	add(m + n + 1, 0, oo);
	add(st, 0, 0);
	add(m + n + 1, ed, 0);
	n = m + n + 4;
}
int sap()
{
	int tot_flow;
	int now_flow, found, min;
	int i, j, t;
	memset(flow, 0, sizeof(flow));
	memset(dist, 0, sizeof(dist));
	memset(now, -1, sizeof(now));
	memset(cnt, 0, sizeof(cnt));
	tot_flow = 0; now_flow = oo;
	cnt[0] = n; i = st;
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
						if(e[pre[i]^1].u >= x + 1 && e[pre[i]^1].u <= x + y &&
							e[pre[i]^1].v >= 1 && e[pre[i]^1].v <= x)
							flow[e[pre[i]^1].v][e[pre[i]^1].u - x] += now_flow;
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
void solve()
{
	int res, i, j, t;
	memset(flow, 0, sizeof(flow));
	for(i = 1;i <= x; i++) for(j = 1;j <= y; j++) sum += min[i][j];
	res = sap();
	if(res != sum) printf("IMPOSSIBLE\n");
	else
	{
		for(i = 1;i <= x; i++) 
		{
			for(j = 1;j < y; j++) printf("%d ", flow[i][j] + min[i][j]);
			printf("%d\n", flow[i][j] + min[i][j]);
		}
	}
	printf("\n");
}
int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		init();
		build();
		solve();
	}
	return 0;
}
