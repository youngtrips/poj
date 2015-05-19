#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXM 102
#define MAXN 52
typedef struct
{
	int u;
	int v;
	int w;
}edge_t;
edge_t e[MAXM];
int parent[MAXN], rank[MAXN], tot, n;
void make_set(int n)
{
	int i;
	for(i = 0;i <= n; i++) {rank[i] = 0; parent[i] = i;}
}
int find_set(int x)
{
	if(x != parent[x]) parent[x] = find_set(parent[x]);
	return parent[x];
}
int union_set(int r1, int r2)
{
	int x = find_set(r1);
	int y = find_set(r2);
	if(x == y) return 0;
	if(rank[x] > rank[y]) parent[y] = x;
	else
	{
		parent[x] = y;
		if(rank[x] == rank[y]) rank[y]++;
	}
	return 1;
}
int cmp(const void* p1, const void* p2)
{
    edge_t* a = (edge_t*)p1;
    edge_t* b = (edge_t*)p2;
    return a->w - b->w;
}
int kruskal()
{
    int cnt = 0, i;
    qsort((void*)e, tot, sizeof(e[0]), cmp);
    make_set(n);
    for(i = 0;i < tot; i++) if(union_set(e[i].u, e[i].v)) cnt += e[i].w;
    return cnt;
}
int init()
{
    int m, i, j, k;
    scanf("%d %d", &n, &m); if(n == 0) return 0;
    tot = 0;
    while(m--)
    {
        scanf("%d %d %d", &i, &j, &k);
        e[tot].u = i; e[tot].v = j; e[tot].w = k;
        tot++;
    }
    return 1;
}
int main()
{
    while(init()) printf("%d\n", kruskal());
    return 0;
}
