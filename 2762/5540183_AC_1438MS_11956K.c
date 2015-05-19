#

#include <stdio.h>
#include <string.h>
#define MAX 1002
int adj_a[MAX][MAX];
int adj_t[MAX][MAX];
int adj[MAX][MAX];
int visited[MAX];
int order[MAX];
int indeg[MAX];
int q[MAX], head, tail;
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
int toposort()
{
    int flag, cnt, i, j;
    memset(indeg, 0, sizeof(indeg));
    flag = 1;
    head = 0; tail = 0;
    for(i = 1;i <= n; i++)
        for(j = 1;j <= n; j++) indeg[j] += adj[i][j];
    for(i = 1;i <= n; i++) if(indeg[i] == 0) q[tail++] = i;
    if(tail > 1) return 0;
    while(head < tail)
    {
        i = q[head];
        cnt = 0;
        for(j = 1;j <= n; j++)
        {
            if(adj[i][j])
            {
                 indeg[j]--;
                 if(indeg[j] == 0) { q[tail++] = j; cnt++;}
            }
        }
        if(cnt > 1) return 0;
        head++;
    }
    return 1;
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
		n = p;
		if(toposort()) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}

