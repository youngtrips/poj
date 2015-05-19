#include <stdio.h>
#include <string.h>
#define MAX 1002
int adj_a[MAX][MAX];
int adj_t[MAX][MAX];
int adj[MAX][MAX];
int visited[MAX];
int outdeg[MAX];
int indeg[MAX];
int order[MAX];
int cnt, n, p;
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
void dfs_t(int x, int no)
{
	int i;
	visited[x] = no;
	for(i = 1;i <= n; i++) if(adj_t[x][i] && visited[i] == 0) dfs_t(i, no);
}
void kosaraju()
{
	int i;
	memset(order, 0, sizeof(order));
	memset(visited, 0, sizeof(visited));
	cnt = 0; p = 0;
	for(i = 1;i <= n; i++) if(visited[i] == 0) dfs_a(i);
	memset(visited, 0, sizeof(visited));
	for(i = cnt;i >= 1; i--) if(visited[order[i]] == 0) dfs_t(order[i], ++p);
}
void shrink()
{
	int i, j;
	memset(adj, 0, sizeof(adj));
	for(i = 1;i <= n; i++)
		for(j = 1;j <= n; j++)
			if(adj_a[i][j] && visited[i] != visited[j]) adj[visited[i]][visited[j]] = 1;
}
void cup()
{
	int i, j, k;
	for(k = 1;k <= p; k++)
		for(i = 1;i <= p; i++)
			for(j = 1;j <= p; j++) adj[i][j] |= (adj[i][k] & adj[k][j]);
}
int main()
{
	int flag, t, i, j;
	scanf("%d", &t);
	while(t--)
	{
		init();
		kosaraju();
		if(p == 1) {printf("Yes\n"); continue;}
		shrink();
		memset(outdeg, 0, sizeof(outdeg));
		memset(indeg, 0, sizeof(indeg));
		for(i = 1;i <= p; i++)
		{
		    for(j = 1;j <= p; j++)
		    {
		        indeg[j] += adj[i][j];
		        outdeg[i] += adj[i][j];
		    }
		}
		flag = 1;
		for(i = 1;i <= n; i++) if(indeg[i] == 0 || outdeg[i] == 0) {flag = 0; break;}
		if(flag) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}
