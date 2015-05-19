#include <stdio.h>
#include <string.h>
#define MAXM 10002
#define MAXN 1002
typedef struct
{
	int u; int v;
	int next;
}edge_t;
edge_t e[MAXM];
int relation[MAXN][MAXN];
int visited[MAXN];
int first[MAXN];
int tot;
int n, m;
void add(int u, int v)
{
	e[++tot].u = u; e[tot].v = v;
	e[tot].next = first[u]; first[u] = tot;
}
void init()
{
	int i, j;
	memset(relation, 0, sizeof(relation));
	memset(first, -1, sizeof(first));
	tot = 0;
	scanf("%d %d", &n, &m);
	while(m--)
	{
		scanf("%d %d", &i, &j);
		add(i, j);
	}
}
void dfs(int s, int t)
{
	int i, j;
	relation[s][t] = 1;
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
	int ans, i, j;
	for(i = 1;i <= n; i++)
	{
		memset(visited, 0, sizeof(visited));
		dfs(i, i);
	}
	ans = 0;
	for(i = 1;i <= n; i++)
		for(j = i + 1;j <= n; j++) if(relation[i][j] == 0 && relation[j][i] == 0) ans++;
	printf("%d\n", ans);
}
int main()
{
	init();
	solve();
	return 0;
}
