#include <stdio.h>
#include <string.h>
#define MAX 1002
int adj_a[MAX][MAX];
int adj_t[MAX][MAX];
int visited[MAX];
int order[MAX], cnt;
int n, p;
void init()
{
	int m, u, v;
	scanf("%d %d", &n, &m);
	memset(adj_a, 0, sizeof(adj_a));
	memset(adj_t, 0, sizeof(adj_t));
	while(m--)
	{
		scanf("%d %d", &u, &v);
		adj_a[u][v] = 1;
		adj_t[v][u] = 1;
	}
}
void dfs_a(int x)
{
	int i;
	visited[x] = 1;
	for(i = 1;i <= n; i++) if(adj_a[x][i] && visited[i] == 0) dfs_a(i);
	order[++cnt] = x;
}
void dfs_t(int x)
{
	int i;
	visited[x] = 1;
	for(i = 1;i <= n; i++) if(adj_t[x][i] && visited[i] == 0) dfs_t(i);
}
int kosaraju()
{
	int max = 0, i;
	memset(order, 0, sizeof(order));
	memset(visited, 0, sizeof(visited));
	cnt = 0;
	for(i = 1;i <= n; i++) if(visited[i] == 0) dfs_a(i);
	memset(visited, 0, sizeof(visited));
	for(i = cnt;i >= 1; i--)
		if(visited[order[i]] == 0) { max++;dfs_t(order[i]);}
	return max;
}
int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		init();
		if(kosaraju() == 1) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}
