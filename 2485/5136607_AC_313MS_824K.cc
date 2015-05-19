#include <stdio.h>
#include <stdlib.h>
#define MAXV 502
#define MAXE 250000
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
	//if (parent[x] == x)
	//	return x;
	//else return parent[x] = findSet(parent[x]);
	if(x != parent[x]) parent[x] = findSet(parent[x]);
	return parent[x];
}
void  unionSet(int root1, int root2)
{
	int x = findSet(root1);
	int y = findSet(root2);
	if(x == y) return;
	if(rank[x] > rank[y]) parent[y] = x;
	else
	{
		parent[x] = y;
		if(rank[x] == rank[y]) rank[y]++;
	}
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
	int max, i;
	makeSet(n_v);
	qsort((void*)e, n_edge, sizeof(e[0]), cmp);
	max = 0;
	for(i = 0;i < n_edge; i++)
	{
		if(findSet(e[i].u) != findSet(e[i].v))
		{
			max = e[i].w > max ? e[i].w : max;
			unionSet(e[i].u, e[i].v);
		}
	}
	return max;
}

int main()
{
	int n_edge, n_v, res, i, j, w, t;
	scanf("%d", &t);
	while(t--)
	{
		for(i = 0;i < MAXV; i++)
			for(j = 0;j < MAXV; j++) flag[i][j] = '0';
		scanf("%d", &n_v);
		n_edge = 0;
		for(i = 1;i <= n_v; i++)
		{
			for(j = 1;j <= n_v; j++)
			{
				scanf("%d", &w);
				if(i != j && flag[i][j] == '0')
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
