#include <stdio.h>
#include <string.h>
#define MAXM 40002
#define MAXN 202
int adj[MAXN][MAXN];
int x[MAXM];
int y[MAXM];
int l[MAXM];
int n, p, t;
int q[MAXN], pre[MAXN], head, tail;
int low, high;
void init()
{
    int i;
    scanf("%d %d %d", &n, &p, &t);
    low = 99999999; high = 0;
    for(i = 0;i < p; i++)
    {
         scanf("%d %d %d", &x[i], &y[i], &l[i]);
         if(high < l[i]) high = l[i];
         if(low > l[i]) low = l[i];
    }
}
void build(int max)
{
    int i;
    memset(adj, 0, sizeof(adj));
    for(i = 0;i < p; i++)
    {
        if(l[i] <= max)
        {
            adj[x[i]][y[i]]++;
            adj[y[i]][x[i]]++;
        }
    }
}
int bfs()
{
    int i, j;
    memset(pre, -1, sizeof(pre));
    pre[1] = -2;
    q[0] = 1; head = 0; tail = 1;
    while(head < tail)
    {
        i = q[head];
        for(j = 1;j <= n; j++)
        {
            if(adj[i][j] > 0 && pre[j] == -1)
            {
                pre[j] = i;
                if(j == n) return 1;
                q[tail++] = j;
            }
        }
        head++;
    }
    return 0;
}
int ford()
{
    int cnt = 0, min, i;
    while(bfs())
    {
        i = n;
        min = 999999999;
        while(pre[i] != -2)
        {
            if(min > adj[pre[i]][i]) min = adj[pre[i]][i];
            i = pre[i];
        }
        i = n;
        while(pre[i] != -2)
        {
            adj[pre[i]][i] -= min;
            adj[i][pre[i]] += min;
            i = pre[i];
        }
        cnt += min;
    }
    return cnt;
}
void solve()
{
    int mid, res;
    while(low < high)
    {
        mid = (low + high)>>1;
        build(mid);
        res = ford();
        if(res >= t) high = mid - 1;
        else low = mid + 1;
    }
    printf("%d\n", low);
}
int main()
{
    init();
    solve();
    return 0;
}
