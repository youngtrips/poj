#include <stdio.h>
#include <string.h>
#define MAXM 10002
#define MAXN 1002
typedef struct
{
	int v;
	int next;
}edge_t;
edge_t e[MAXM];
int first[MAXN];
int visited[MAXN];
int tot, ans, n;
void add(int u, int v)
{
	e[++tot].v = v; e[tot].next = first[u]; first[u] = tot;
}
int init()
{
	int m, i, j;
	if(scanf("%d %d", &n, &m) == EOF) return 0;
	memset(first, -1, sizeof(first)); tot = -1;
	while(m--)
	{
		scanf("%d %d", &i, &j);
		add(i + 1, j + 1);
	}
	return 1;
}
void dfs(int i, int s)
{
	int j, t;
	ans++;
	visited[i] = 1;
	t = first[i];
	while(t != -1)
	{
		j = e[t].v;
		if(visited[j] == 0) dfs(j, s);
		t = e[t].next;
	}
}
void solve()
{
	int i, j;
	ans = 0;
	for(i = 1;i <= n; i++)
	{
		memset(visited, 0, sizeof(visited));
		dfs(i, i);
	}
	printf("%d\n", ans);
}
int main()
{
	while(init()) solve();
	return 0;
}
