#include <stdio.h>
#include <string.h>
#define MAX 102
int adj_a[MAX][MAX];
int adj_t[MAX][MAX];
int adj[MAX][MAX];
int visited[MAX];
int order[MAX];
int outdeg[MAX];
int indeg[MAX];
int cnt, n, p;
void init()
{
	int i, j, m;
	scanf("%d", &n);
	memset(adj_a, 0, sizeof(adj_a));
	memset(adj_t, 0, sizeof(adj_t));
	for(i = 1;i <= n; i++)
	{
		while(1)
		{
			scanf("%d", &j); if(j == 0) break;
			adj_a[i][j] = 1;
			adj_t[j][i] = 1;
		}
	}
}
void dfs_a(int x)
{
	int i;
	visited[x] = 1;
	for(i = 1;i <= n; i++)
		if(adj_a[x][i] && visited[i] == 0) dfs_a(i);
	order[++cnt] = x;
}
void dfs_t(int st, int no)
{
	int i;
	visited[st] = no;
	for(i = 1;i <= n; i++) if(adj_t[st][i] && visited[i] == 0) dfs_t(i, no);
}
void kosaraju()
{
	int i;
	memset(visited, 0, sizeof(visited));
	cnt = 0;;
	for(i = 1;i <= n; i++) if(visited[i] == 0) dfs_a(i);
	memset(visited, 0, sizeof(visited));
	p = 0;
	for(i = cnt;i >= 1; i--)
	{
		if(visited[order[i]] == 0) dfs_t(order[i], ++p);
	}
}
void shrink()
{
	int i, j;
	memset(adj, 0, sizeof(adj));
	for(i = 1;i <= n; i++)
		for(j = 1;j <= n; j++)
			if(adj_a[i][j] && visited[i] != visited[j]) adj[visited[i]][visited[j]] = 1;
}
int main()
{
	int out, in, i, j;
	init();
	kosaraju();
	shrink();
	memset(outdeg, 0, sizeof(outdeg));
	memset(indeg, 0, sizeof(indeg));
	out = 0; in  = 0;
	for(i = 1;i <= p; i++)
	{
		for(j = 1;j <= p; j++)
		{
			outdeg[i] += adj[i][j];
			indeg[j] += adj[i][j];
		}
	}
	for(i = 1;i <= p; i++)
	{
		if(outdeg[i] == 0) out++;
		if(indeg[i] == 0) in++;
	}	
	printf("%d\n", in);
	if(p == 1) printf("0\n");
	else printf("%d\n", in > out ? in : out);
	return 0;
}
