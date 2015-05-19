#include <stdio.h>
#include <string.h>
#define MAXN 3404
#define MAXM 12882
int dp[MAXM];
int w[MAXN];
int d[MAXN];
int n;
int m;
int max(int a, int b)
{
     return a > b ? a : b;
}
int knapsack()
{
     int i;
     int j;
     memset(dp, 0, sizeof(dp));
     for(i = 1;i <= n; i++)
     {
          for(j = m;j >= w[i]; j--)
          {
               if(dp[j] < dp[j - w[i]] + d[i])
                    dp[j] = dp[j - w[i]] + d[i];
          }
     }
     return dp[m];
}
int main()
{
     int i;
     scanf("%d %d", &n, &m);
     for(i = 1;i <= n; i++) scanf("%d %d", &w[i], &d[i]);
     printf("%d\n", knapsack(n, m, w, d));
     return 0;
}
