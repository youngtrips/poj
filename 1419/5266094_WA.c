#include <stdio.h>
#include <string.h>
#define MAX 102
int adj[MAX][MAX], n;
int color[MAX][MAX], cnt;
void init()
{
    int m, u, v;
    scanf("%d %d", &n, &m);
    memset(adj, 0, sizeof(adj));
    memset(color, -1, sizeof(color));
    while (m--)
    {
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        adj[v][u] = 1;
    }
}
void dfs(int st, int col, int no)
{
    int i, k = 1;
    color[no][st] = col;
    k ^= col;
    for(i = 1;i <= n; i++)
    {
        if(adj[st][i])
        {
            if(color[no][i] == col && col == 1)
            {
               color[no][i] = 0;
               return;
            }
            if(color[no][i] == -1) dfs(i, k, no);
        }
    }
}
void search()
{
    int i, j, p = 1, max = 0;
    for (i = 1;i <= n; i++)
    {
        cnt = 0;
        dfs(i, 1, i);
        for(j = 1;j <= n; j++) cnt += color[i][j];
        if(max < cnt)
        {
            max = cnt;
            p = i;
        }
    }
    printf("%d\n", max);
    for(i = 1;i <= n; i++) if(color[p][i]) printf("%d ", i);
    printf("\n");
}

int main()
{
    int t, i, j;
    scanf("%d", &t);
    while (t--)
    {
        init();
        search();
    }
    return 0;
}

