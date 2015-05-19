#include <stdio.h>
#define MAXN 3403
#define MAXM 12881
int V[MAXN][MAXM];
int w[MAXN];
int d[MAXN];
int n;
int m;
int max(int a, int b)
{
     return a > b ? a : b;
}
int knapsack(int n, int c, int w[], int v[])
{
     int i;
     int j;
     for(i = 0;i <= n; i++) V[i][0] = 0;
     for(j = 0;j <= c; j++) V[0][j] = 0;
     for(i = 1;i <= n; i++)
     {
          for(j = 1;j <= c; j++)
          {
               if(j < w[i]) V[i][j] = V[i-1][j];
               else V[i][j] = max(V[i-1][j], V[i-1][j - w[i]] + v[i]);
          }
     }
     return V[n][c];
}
int main()
{
     int i;
     scanf("%d %d", &n, &m);
     for(i = 1;i <= n; i++) scanf("%d %d", &w[i], &d[i]);
     printf("%d\n", knapsack(n, m, w, d));
     return 0;
}
