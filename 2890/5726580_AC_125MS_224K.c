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
char visited[MAXN];
int first[MAXN];
int tot, ans, n;
void add(int u, int v)
{
	e[++tot].v = v; e[tot].next = first[u]; first[u] = tot;
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
int main()
{
	int m, i, j;
	while(scanf("%d %d", &n, &m) != EOF)
	{
		memset(first, -1, sizeof(first)); tot = -1;
		while(m--)
		{
			scanf("%d %d", &i, &j);
			add(i + 1, j + 1);
		}
		ans = 0;
		for(i = 1;i <= n; i++)
		{
			memset(visited, 0, sizeof(visited));
			dfs(i, i);
		}
		printf("%d\n", ans);
	}
	return 0;
}
