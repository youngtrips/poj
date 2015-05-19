#include <stdio.h>
#include <stdlib.h>
#define MAXV 28
#define MAXE 800
typedef struct
{
	int u;
	int v;
	int w;
}Edge;
Edge e[MAXE];
int parent[MAXV];
int rank[MAXV];
char flag[MAXV][MAXV];
int cmp(const void* p1, const void* p2)
{
	Edge* e1 = (Edge*)p1;
	Edge* e2 = (Edge*)p2;
	return e1->w - e2->w;
}
int findSet(int x)
{
	if(x != parent[x]) parent[x] = findSet(parent[x]);
	return parent[x];
}
int  unionSet(int root1, int root2)
{
	int x = findSet(root1);
	int y = findSet(root2);
	if(x == y) return 0;
	if(rank[x] > rank[y]) parent[y] = x;
	else
	{
		parent[x] = y;
		if(rank[x] == rank[y]) rank[y]++;
	}
	return 1;
}
void makeSet(int n)
{
	int i;
	for(i = 0;i <= n; i++)
	{
		parent[i] = i;
		rank[i] = 0;
	}
}
int kruskal(Edge* e, int n_edge, int n_v)
{
	int cost, i;
	makeSet(n_v);
	qsort((void*)e, n_edge, sizeof(e[0]), cmp);
	cost = 0;
	for(i = 0;i < n_edge; i++)
	{
			if(unionSet(e[i].u, e[i].v)) cost += e[i].w;
	}
	return cost;
}
int main()
{
	char from[2], to[2];
	int n_edge, n_v, res, i, j, w, n, k;
	while(1)
	{
		for(i = 0;i < MAXV; i++)
			for(j = 0;j < MAXV; j++) flag[i][j] = '0';
		scanf("%d", &n_v);
		if(n_v == 0) break;
		n_edge = 0;
		for(k = 1;k < n_v; k++)
		{
			scanf("%s %d", from, &n);
			i = from[0] - 'A';
			while(n--)
			{
				scanf("%s %d", to, &w);
				j = to[0] - 'A';
				if(flag[i][j] == '0')
				{
					flag[i][j] = '1';
					flag[j][i] = '1';
					e[n_edge].u = i;
					e[n_edge].v = j;
					e[n_edge].w = w;
					n_edge++;
				}
			}
		}
		res = kruskal(e, n_edge, n_v);
		printf("%d\n", res);
	}
	return 0;
}
