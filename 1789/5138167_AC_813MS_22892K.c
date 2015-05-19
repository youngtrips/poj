#include <stdio.h>
#include <stdlib.h>
#define MAXV 2002
#define MAXE 1999002
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
int diff(char* pstr1, char* pstr2)
{
	int cnt = 0;
	while(*pstr1)
		if(*pstr1++ != *pstr2++) cnt++;
	return cnt;
}
int build_graph(int n)
{
	char str[MAXV][8];
	int i, j, k = 0;
	for(i = 0;i < n; i++) scanf("%s", str[i]);
	for(i = 0;i < n; i++)
	{
		for(j = i + 1;j < n; j++)
		{
			e[k].u = i;
			e[k].v = j;
			e[k].w = diff(str[i], str[j]);
			k++;
		}
	}
	return k;
}
int main()
{
	char w;
	int n_edge, n_v, res, i, j;
	while(1)
	{
		scanf("%d", &n_v);
		if(n_v == 0) break;
		n_edge = build_graph(n_v);
		res = kruskal(e, n_edge, n_v);
		printf("The highest possible quality is 1/%d.\n", res);
	}
	return 0;
}
