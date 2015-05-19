#include <stdio.h>
#include <string.h>
#define MAX 1002
int adj[MAX][MAX];
int indeg[MAX];
int n;
void cup()
{
    int i, j, k;
    for(k = 1;k <= n; k++)
        for(i = 1;i <= n; i++)
            for(j = 1;j <= n; j++) adj[i][j] |= (adj[i][k] & adj[k][j]);
}
int main()
{
    int flag, t, m, i, j;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d %d", &n, &m);
        memset(adj, 0, sizeof(adj));
        memset(indeg, 0, sizeof(indeg));
        while(m--)
        {
            scanf("%d %d", &i, &j);
            adj[i][j] = 1;
        }
        cup();
        flag = 1;
        for(i = 1;i <= n; i++)
            for(j = 1;j <= n; j++) indeg[j] += adj[i][j];
        for(i = 1;i <= n; i++) if(indeg[i] == 0) {flag = 0; break;}
        if(flag) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
