#include <stdio.h>
#include <string.h>
#define oo 10000000
#define MAXV 5002
#define MAXN 2502
typedef struct{ int u; int v; int f; int c; int next;}edge_t;
edge_t e[MAXV * MAXV];
int first[MAXV];
int board[MAXN];
int que[MAXV];
int dis[MAXV];
int has[MAXV];
int cnt[MAXV];
int pre[MAXV];
int dx[2] = {1, 0};
int dy[2] = {0, 1};
int head, tail, top;
int tot;
int st, ed;
int n, k;
void add(int u, int v, int f, int c)
{
    e[++tot].u = u; e[tot].v = v; e[tot].f = f; e[tot].c = c; e[tot].next = first[u]; first[u] = tot;
    e[++tot].u = v; e[tot].v = u; e[tot].f = 0; e[tot].c = -c;e[tot].next = first[v]; first[v] = tot;
}
void init()
{
    int tx, ty, x, y, i, j, k;
    scanf("%d %d", &n, &k);
    for(i = 1;i <= n * n; i++) scanf("%d", board + i);
    memset(first, -1, sizeof(first)); tot = -1;
    st = 0; ed = n * n * 2 + 1;
    add(st, 1, k, 0);
    add(n * n * 2, ed, k, 0);
    for(i = 1;i <= n * n; i++)
    {
        add(2 * i - 1, 2 * i, 1, -board[i]);
        add(2 * i - 1, 2 * i, oo, 0);
    }
    for(i = 1;i <= n * n; i++)
    {
        x = (i - 1) / n + 1; y = (i - 1) % n + 1;
        for(k = 0;k < 2; k++)
        {
            tx = x + dx[k]; ty = y + dy[k];
            if(tx < 1 || tx > n || ty < 1 || ty > n) continue;
            j = (tx - 1) * n + ty;
            add(2 * i, 2 * j - 1, oo, 0);
        }
    }
}
int spfa()
{
    int i, j, t;
    for(i = st;i <= ed; i++) dis[i] = oo;
    memset(pre, -1, sizeof(pre));
    memset(has, 0,  sizeof(has));
    memset(cnt, 0,  sizeof(cnt));
    dis[st] = 0; has[st] = 1;
    que[0] = st; head = 0; tail = 1;
    top = 0;
    while(head != tail)
    {
        i = que[head]; has[i] = 0;
        cnt[i]++; if(cnt[i] > ed) break;
        t = first[i];
        while(t != -1)
        {
            j = e[t].v;
            if(e[t].f > 0 && dis[j] > dis[i] + e[t].c)
            {
                dis[j] = dis[i] + e[t].c;
                pre[j] = t;
                if(has[j] == 0)
                {
                    que[tail] = j;
                    has[j] = 1;
                    tail = (tail + 1) % MAXV;
                }
            }
            t = e[t].next;
        }
        head = (head + 1) % MAXV;
    }
    return dis[ed] != oo;
}
void mincost_maxflow()
{
    int ans, i;
    ans = 0;
    while(spfa())
    {
        i = ed;
        while(i != st)
        {
            e[pre[i]].f--;
            e[pre[i]^1].f++;
            i = e[pre[i]].u;
        }
        ans += dis[ed];
    }
    printf("%d\n", -ans);
}
int main()
{
    init();
    mincost_maxflow();
    return 0;
}
