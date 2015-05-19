#include <stdio.h>
#include <stdlib.h>
#define MAXM 5002
#define MAXN 102
typedef struct
{
    int u;
    int v;
    int w;
}edge_t;
edge_t e[MAXM];
int parent[MAXN], rank[MAXN];
int tot, n;
int cmp(const void* p1, const void* p2) {return ((edge_t*)p1)->w - ((edge_t*)p2)->w;}
void make_set(int n)
{
    int i;
    for(i = 0;i <= n; i++)
    {
        parent[i] = i;
        rank[i] = 0;
    }
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
int init()
{
    int m, u, v, w;
    scanf("%d %d", &n, &m);
    if(n == 0 && m == 0) return 0;
    for(tot = 0;tot < m; tot++) scanf("%d %d %d", &e[tot].u, &e[tot].v, &e[tot].w);
    return 1;
}
int kruskal(int st)
{
    int max, cnt = 1, i;
    for(i = st + 1;i < tot; i++)
    {
        if(union_set(e[i].u, e[i].v))
        {
            cnt++;
            max = e[i].w;
        }
    }
    if(cnt == n - 1) return max;
    return -1;
}
int solve()
{
    int flag, ans, max, min, i;
    qsort((void*)e, tot, sizeof(e[0]), cmp);
    flag = 0;
    ans = 999999999;
    for(i = 0;i < tot; i++)
    {
        make_set(n);
        min = e[i].w;
        union_set(e[i].u, e[i].v);
        max = kruskal(i);
        if(max != -1)
        {
            flag = 1;
            if(ans > max - min) ans = max - min;
        }
    }
    if(flag) return ans;
    return -1;
}
int main()
{
    while(init()) printf("%d\n", solve());
    return 0;
}
