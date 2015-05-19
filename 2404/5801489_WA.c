#include <stdio.h>
#include <string.h>
#define oo 999999999
#define MAXM 5002
#define MAXN 502
typedef struct
{
	int u;
	int v;
	int f;
	int c;
	int next;
}edge_t;
edge_t e[MAXM * 2];
int visited[MAXN];
int first[MAXN];
int adj[MAXN][MAXN];
int odd[MAXN];
int deg[MAXN];
int que[MAXN * MAXN];
int dis[MAXN];
int pre[MAXN];
int head, tail;
int ans;
int cnt;
int tot;
int st, ed;
int n;
void add(int u, int v, int f, int c)
{
	e[++tot].u = u; e[tot].v = v; e[tot].f = f; e[tot].c = c; e[tot].next = first[u]; first[u] = tot;
	e[++tot].u = v; e[tot].v = u; e[tot].f = 0; e[tot].c = -c;e[tot].next = first[v]; first[v] = tot;
}
int init()
{
	int m, i, j, k;
	scanf("%d", &n);
	if(n == 0) return 0;
	scanf("%d", &m);
	memset(deg, 0, sizeof(deg));
	for(i = 1;i <= n; i++)
		for(j = 1;j <= n; j++) adj[i][j] = (i == j ? 0 : oo);
	ans = 0;
	while(m--)
	{
		scanf("%d %d %d", &i, &j, &k);
		if(adj[i][j] > k) adj[i][j] = k;
		if(adj[j][i] > k) adj[j][i] = k;
		deg[i]++;
		deg[j]++;
		ans += k;
	}
	cnt = 0;
	for(i = 1;i <= n; i++) if(deg[i] & 1) odd[++cnt] = i;
	return 1;
}
void floyd()
{
	int i, j, k;
	for(k = 1;k <= n; k++)
		for(i = 1;i <= n; i++)
			for(j = 1;j <= n; j++)
				if(adj[i][j] > adj[i][k] + adj[k][j]) adj[i][j] = adj[i][k] + adj[k][j];
}
void rebuild()
{
	int i, j;
	memset(first, -1, sizeof(first)); tot = -1;
	for(i = 1;i <= cnt; i++)
	{
		for(j = 1;j <= cnt; j++)
		{
			if(i == j) continue;
			if(adj[odd[i]][odd[j]] == oo) continue;
			add(i, cnt + j, 1, adj[odd[i]][odd[j]]);
		}
	}
	st = 0; ed = cnt + cnt + 1;
	for(i = 1;i <= cnt; i++) add(st, i, 1, 0);
	for(i = 1;i <= cnt; i++) add(cnt + i, ed, 1, 0);
}
int spfa()
{
	int i, j, k, t;
	memset(visited, 0, sizeof(visited));
	memset(pre, -1, sizeof(pre));
	for(i = st;i <= ed; i++) dis[i] = oo;
	dis[st] = 0; visited[st] = 1;
	que[0] = st; head = 0; tail = 1;
	while(head < tail)
	{
		i = que[head];
		visited[i] = 0;
		t = first[i];
		while(t != -1)
		{
			j = e[t].v;
			if(e[t].f > 0 && dis[j] > dis[i] + e[t].c)
			{
				dis[j] = dis[i] + e[t].c;
				pre[j] = t;
				if(visited[j] == 0)
				{
					visited[j] = 1;
					que[tail++] = j;
				}
			}
			t = e[t].next;
		}
		head++;
	}
	return dis[ed] != oo;
}
int mincost_maxflow()
{
	int res, i, t;
	res = 0;
	while(spfa())
	{
		i = ed;
		while(pre[i] != -1)
		{
			t = pre[i];
			e[t].f--;
			e[t^1].f++;
			e[t^1].c = -e[t].c;
			i = e[t].u;
		}
		res += dis[ed];
	}
	return res;
}
int main()
{
	int res;
	while(init())
	{
		if(cnt == 0) { printf("%d\n", ans); continue;}
		floyd();
		rebuild();
		res = mincost_maxflow();
		printf("%d\n", ans + (res>>1));
	}
	return 0;
}
