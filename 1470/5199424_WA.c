#include <stdio.h>
#include <string.h>
#define CLS(x) memset(x,0,sizeof(x))
#define MAX 1000
int tree[MAX][MAX];
int q[MAX][MAX];
int parent[MAX];
int rank[MAX];
int ancestor[MAX];
int color[MAX];
int num[MAX];
int n;
void init()
{
	CLS(parent);
	CLS(color);
	CLS(rank);
	CLS(tree);
	CLS(num);
	CLS(q);
}
void make_set(int u)
{
	parent[u] = u;
}
int find_set(int x)
{
	if(x != parent[x]) parent[x] = find_set(parent[x]);
	return parent[x];
}
void union_set(int r1, int r2)
{
	int x = find_set(r1);
	int y = find_set(r2);
	if(x == y) return;
	if(rank[x] > rank[y]) parent[y] = x;
	else
	{
		parent[x] = y;
		if(rank[x] == rank[y]) rank[y]++;
	}
}
void lca(int u)
{
	int i, j;
	make_set(u);
	ancestor[find_set(u)] = u;
	for(i = 1;i <= n; i++)
	{
		if(tree[u][i] == 1)
		{
			lca(i);
			union_set(u, i);
			ancestor[find_set(u)] = u;
		}
	}
	color[u] = 1;
	for(i = 1;i <= n; i++)
		if(q[u][i] && color[i] == 1) num[ancestor[find_set(i)]]++;
}
int main()
{
	char ch;
	int i, j, k, m;
	while(scanf("%d", &n) != EOF)
	{
		init();
		for(k = 0;k < n; k++)
		{
			scanf("%d:(%d)", &i, &m);
			while(m--)
			{
				scanf("%d", &j);
				tree[i][j] = 1;
			}
		}
		scanf("%d", &m);
		for(k = 0;k < m; k++)
		{
			while(getchar() != '(');
			scanf("%d", &i);
			scanf("%d", &j);
			q[i][j] = 1;
			q[j][i] = 1;
			while(getchar() != ')');
		}
		for(i = 1;i <= n; i++)
		{
			k = 0;
			for(j = 1;j <= n; j++) k += tree[j][i];
			if(k == 0) break;
		}
		lca(i);
		for(i = 1;i <= n; i++) if(num[i]) printf("%d:%d\n", i, num[i]);
	}
	return 0;
}
