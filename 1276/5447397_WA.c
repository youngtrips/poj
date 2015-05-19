#include <stdio.h>
#include <string.h>
#define MAXN 100002
#define MAXM 12
int dp[MAXN];
int n[MAXM];
int w[MAXM];
int flag;
int v;
int m;
int init()
{
     int i;
     if(scanf("%d %d", &v, &m) == EOF) return 0;
     flag = 0;
     for(i = 1;i <= m; i++)
     {
          scanf("%d %d", &n[i], &w[i]);
          if(v == w[i]) flag = 1;
     }
     memset(dp, 0, sizeof(dp));
}
void complete_pack(int c)
{
     int i;
     for(i = c;i <= v; i++)
          if(dp[i] < dp[i-c] + c) dp[i] = dp[i-c] + c;
}
void zeroone_pack(int c)
{
     int i;
     for(i = v;i >= c; i--)
          if(dp[i] < dp[i-c] + c) dp[i] = dp[i-c] + c;
}
void multiple_pack(int c, int tot)
{
     int k = 1;
     if(c * tot >= v)
     {
          complete_pack(c);
          return;
     }
     while(k < tot)
     {
          zeroone_pack(k * c);
          tot -= k;
          k <<= 1;
     }
}
int main()
{
     int i;
     while(init())
     {
          if(flag == 0)
          {
               for(i = 1;i <= m; i++)
                    if(n[i] && w[i] <= v) multiple_pack(w[i], n[i]);
          }
          printf("%d\n", dp[v]);
     }
     return 0;
}
