#include <stdio.h>
#include <string.h>
#define MIN(a,b) ((a)<(b)?(a):(b))
#define MAXM 10002
#define MAXN 5002
typedef struct { int v; int next;}edge_t;
edge_t e[MAXM * 3];
char has[MAXN][MAXN];
int visited[MAXN];
int first[MAXN];
int low[MAXN];
int pre[MAXN];
int deg[MAXN];
int tot, cnt, n;
void add(int u, int v) { e[++tot].v = v; e[tot].next = first[u]; first[u] = tot;}
void dfs(int i, int fa)
{
	int j, t;
	visited[i] = 1;
	pre[i] = cnt; low[i] = cnt++;
	t = first[i];
	while(t != -1)
	{
		j = e[t].v;
		if(j != fa)
		{
			if(visited[j] == 0) dfs(j, i);
			low[i] = MIN(low[i], low[j]);
		}
		t = e[t].next;
	}
	visited[i] = 2;
}
void init()
{
	int m, i, j;
	memset(first, -1, sizeof(first));
	memset(has, 0, sizeof(has));
	scanf("%d %d", &n, &m);
	while(m--)
	{
		scanf("%d %d", &i, &j);
		if(has[i][j] == 0)
		{
			has[i][j] = 1;
			has[j][i] = 1;
			add(i, j);
			add(j, i);
		}
	}
	cnt = 0;
}
void solve()
{
	int i, j, t;
	dfs(1, 1);
	memset(deg, 0, sizeof(deg));
	for(i = 1;i <= n; i++)
	{
		t = first[i];
		while(t != -1)
		{
			j = e[t].v;
			if(low[i] != low[j]) deg[low[i]]++;
			t = e[t].next;
		}
	}
	for(i = 0, t = 0;i <= n; i++) if(deg[i] == 1) t++;
	printf("%d\n", (t + 1) >> 1);
}
int main()
{
	init();
	solve();
	return 0;
}
