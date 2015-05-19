#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define oo 999999999
#define MAX_NODE 100002
#define MAXM 40002
#define MAXN 202
typedef struct{int u; int v; int f; int c; int op; int next;}edge_t;
edge_t e[MAXM * 2];
int first[MAXN], tot;
int node[MAXN], n, k;
int x[MAXN], y[MAXN], l[MAXN], num;
int has[MAX_NODE];
int q[MAXN * MAXN], pre[MAXN], d[MAXN], head, tail;
void add(int u, int v, int f, int c)
{
    e[++tot].u = u; e[tot].v = v; e[tot].f = f; e[tot].c = c; e[tot].op = tot + 1;
    e[tot].next = first[u]; first[u] = tot;
    e[++tot].u = v; e[tot].v = u; e[tot].f = 0; e[tot].c = -c; e[tot].op = tot - 1;
    e[tot].next = first[v]; first[v] = tot;
}
int cmp(const void*p1, const void* p2) { return *(int*)p1 - *(int*)p2;}
void init()
{
    int i, u, v, w;
    scanf("%d %d", &num, &k);
    memset(has, 0, sizeof(has));
    n = 0;
    for(i = 1;i <= num; i++)
    {
        scanf("%d %d %d", &u, &v, &w);
        if(has[u] == 0) { has[u] = 1; node[++n] = u;}
        if(has[v] == 0) { has[v] = 1; node[++n] = v;}
        x[i] = u; y[i] = v; l[i] = w;
    }
    qsort((void*)&node[1], n, sizeof(node[1]), cmp);
    for(i = 1;i <= n; i++) has[node[i]] = i;
}
void build()
{
    int i, u, v, w;
    memset(first, -1, sizeof(first));
    tot = 0;
    for(i = 1;i < n; i++) add(i, i + 1, k, 0);
    for(i = 1;i <= num; i++)
    {
        u = has[x[i]]; v = has[y[i]]; w = l[i];
        add(u, v, 1, -w);
    }
    add(0, 1, k, 0);
    add(n, n + 1, k, 0);
    n++;
}
int spfa()
{
    int i, j, t;
	memset(has, 0, sizeof(has));
    memset(pre, -1, sizeof(pre));
    for(i = 1;i <= n; i++) d[i] = oo;
	has[0] = 1;
    d[0] = 0;
    q[0] = 0; head = 0; tail = 1;
    while(head < tail)
    {
        i = q[head];
		if(i == n) return 1;
		has[i] = 1;
        t = first[i];
        while(t != -1)
        {
            j = e[t].v;
            if(e[t].f > 0 && d[j] > d[i] + e[t].c)
            {
                d[j] = d[i] + e[t].c;
                pre[j] = t;
				if(has[j] == 0)
				{
					has[j] = 1;
                	q[tail++] = j;
				}
            }
            t = e[t].next;
        }
        head++;
    }
    return 0;
}
int mincost_maxflow()
{
    int max = 0, i, j, t;
    while(spfa())
    {
        i = n;
        while(pre[i] != -1)
        {
            t = pre[i];
            e[t].f--;
            e[e[t].op].f++;
            e[e[t].op].c = -e[t].c;
            max += e[t].c;
            i = e[t].u;
        }
    }
    return max;
}
int main()
{
    int res, t;
    scanf("%d", &t);
    while(t--)
    {
        init();
        build();
		res = mincost_maxflow();
        printf("%d\n", -res);
    }
    return 0;
}
