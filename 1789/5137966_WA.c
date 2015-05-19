#include <stdio.h>
#include <stdlib.h>
#define MAXV 2002
#define MAXE 14004
typedef struct
{
	int u;
	int v;
	int w;
}Edge;
Edge e[MAXE];
int parent[MAXV];
int rank[MAXV];
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
	char w;
	int n_edge, n_v, res, i, j;
	while(1)
	{
		scanf("%d", &n_v);
		getchar();
		if(n_v == 0) break;
		n_edge = 0;
		for(i = 1;i <= n_v; i++)
		{
			for(j = 1;j <= 7; j++)
			{
				w = getchar();
				if(w != 'a')
				{
					e[n_edge].u = i;
					e[n_edge].v = j;
					e[n_edge].w = w - 'a';
					n_edge++;
				}
			}
			getchar();
		}
		res = kruskal(e, n_edge, n_v);
		printf("The highest possible quality is 1/%d.\n", res);
	}
	return 0;
}
