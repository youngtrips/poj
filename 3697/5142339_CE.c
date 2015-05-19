#include <stdio.h>
#include <string.h>
#define CLS(x) memset(x, '1', sizeof(x));
#define FOR(i,n) for((i)=0;(i)<(n);(i)++)
#define N 10001
char adj[N][N];
char v[N];
int q[N * N];
int head, tail, n;
int bfs()
{
    CLS(v);
    int cnt, i, k;
    q[0] = 1;
    v[1] = '0';
    head = 0;
    tail = 1;
    cnt = 0;
    while(head < tail)
    {
        k = q[head];
        for(i = 1;i <= n; i++)
        {
            if(adj[k][i] == '1' && v[i] == '1')
            {
                q[tail++] = i;
                v[i] = '0';
                cnt++;
            }
        }
        head++;
    }
    return cnt;
}
int main()
{
    int i, j, m, k;
    k = 1;
    while(1)
    {
        CLS(adj);
        scanf("%d %d", &n, &m);
        if(n == 0 && m == 0) break;
        while(m--)
        {
            scanf("%d %d", &i, &j);
            adj[i][j] = '0';
            adj[j][i] = '0';
            adj[i][i] = '0';
            adj[j][j] = '0';
        }
        printf("Case %d: %d\n", k++, bfs());
    }
    return 0;
}
