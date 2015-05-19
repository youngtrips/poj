#include <stdio.h>
#include <string.h>
#include <math.h>
#define eps 1e-20
#define MAXM 499502
#define MAXN 1002
#define dis(i,j) sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]))
#define _cp(a,b) ((a).d+eps<(b).d)
typedef struct
{
	int u;
	int v;
	double w;
}Edge;
Edge e[MAXM];
char flag[MAXN][MAXN];
int rank[MAXN] ,parent[MAXN], tot, n;
double x[MAXN], y[MAXN];
typedef struct {double d;int v;}heap_t;
struct heap
{
	heap_t h[MAXN*MAXN];
	int n,p,c;
	void init(){n=0;}
	void ins(heap_t e)
	{
		for (p=++n;p>1&&_cp(e,h[p>>1]);h[p]=h[p>>1],p>>=1);
		h[p]=e;
	}
	int del(heap_t& e)
	{
		if (!n) return 0;
		for (e=h[p=1],c=2;c<n&&_cp(h[c+=(c<n-1&&_cp(h[c+1],h[c]))],h[n]);h[p]=h[c],p=c,c<<=1);
		h[p]=h[n--];return 1;
	}
};
heap queue;
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
int main()
{
	double cost;
	heap_t  tmp;
	int m, i, j;
	while(scanf("%d %d", &n, &m) != EOF){
	memset(flag, '0', sizeof(flag));
	for(i = 1;i <= n; i++)
	{
		rank[i] = 0;
		parent[i] = i;
		scanf("%lf %lf", &x[i], &y[i]);
	}
	while(m--)
	{
		scanf("%d %d", &i, &j);
		union_set(i, j);
		flag[i][j] = '1';
		flag[j][i] = '1';
	}
	tot = 0;
	queue.init();
	for(i = 1;i <= n; i++)
	{
		for(j = i + 1;j <= n; j++)
		{
			if(flag[i][j] == '0' && flag[j][i] == '0')
			{
				e[tot].u = i;
				e[tot].v = j;
				e[tot].w = dis(i, j);
				tmp.v = tot;
				tmp.d = e[tot].w;
				tot++;
				queue.ins(tmp);
			}
		}
	}
	cost = 0.0;
	while(queue.del(tmp)) 
	{
		i = tmp.v;
		if(union_set(e[i].u, e[i].v)) cost += e[i].w;
	}
	printf("%0.2lf\n", cost);
	}
	return 0;
}
