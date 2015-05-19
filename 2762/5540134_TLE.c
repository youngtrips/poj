#include <stdio.h>
#include <string.h>
#define MAXM 6002
#define MAXN 1002
typedef struct
{
	int u; int v;
	int next;
}edge_t;
edge_t e[MAXM];
int adj[MAXN][MAXN];
int visited[MAXN];
int first[MAXN];
int tot;
int n;
void add(int u, int v)
{
	e[++tot].u = u; e[tot].v = v;
	e[tot].next = first[u]; first[u] = tot;
}
void init()
{
	int m, u, v;
	memset(first, -1, sizeof(first));
	tot = 0;
	scanf("%d %d", &n, &m);
	while(m--)
	{
		scanf("%d %d", &u, &v);
		add(u, v);
	}
}
void dfs(int s, int t)
{
	int i, j;
	adj[s][t] = 1;
	visited[t] = 1;
	i = first[t];
	while(i != -1)
	{
		j = e[i].v;
		if(visited[j] == 0) dfs(s, j);
		i = e[i].next;
	}
}
void solve()
{
	int i, j, k;
	memset(adj, 0, sizeof(adj));
	for(i = 1;i <= n; i++)
	{
		memset(visited, 0, sizeof(visited));
		dfs(i, i);
	}
	k = 1;
	for(i = 1;i <= n; i++)
	{
		for(j = 1;j <= n; j++) if(adj[i][j] == 0 && adj[j][i] == 0) { k = 0; break;}
		if(k == 0) break;
	}
	printf("%s\n", k == 1 ? "Yes" : "No");
}
int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		init();
		solve();
	}
	return 0;
}
