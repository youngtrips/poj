#include <stdio.h>
#include <string.h>
#define MAXN 1120
#define MAXM 14
int dp[MAXN+1][MAXM + 1];
int prime[MAXN];
int flag[MAXN];
int tot;
void gen_prime()
{
     int i, j;
     memset(flag, 0, sizeof(flag));
     tot = 0;
     for(i = 2;i <= MAXN; i++)
     {
          if(flag[i] == 0)
          {
               prime[++tot] = i;
               for(j = 2;j * i <= MAXN; j++) flag[j * i] = -1;
          }
     }
}
int main()
{
     int n;
     int k;
     int i;
     int j;
     int t;
     gen_prime();
     while(1)
     {
          scanf("%d %d", &n, &k);
          if(n == 0 && k == 0) break;
          memset(dp, 0, sizeof(dp));
          dp[0][0] = 1;
          for(i = 1;i <= tot && prime[i] <= n; i++)
               for(j = n;j >= prime[i]; j--)
                    for(t = 1;t <= k; t++)
                         dp[j][t] += dp[j - prime[i]][t - 1];
          printf("%d\n", dp[n][k]);
     }
     return 0;
}
