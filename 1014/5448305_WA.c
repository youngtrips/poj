#include <stdio.h>
#include <string.h>
#define MAXN 60002
#define MAXM 7
int dp[MAXN];
int w[MAXM];
int n[MAXM];
int v;
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
          k *= 2;
     }
     zeroone_pack(c * tot);
}
int main()
{
     int flag, sum, i, s;
     s = 1;
     while(1)
     {
          flag = 1;
          sum = 0;
          for(i = 1;i <= 6; i++)
          {
               scanf("%d", &n[i]);
               sum += n[i] * i;
               w[i] = i;
          }
          if(sum == 0) break;
          if(sum % 2 == 1) flag = 0;
          if(flag)
          {
               v = sum / 2;
               for(i = 1;i <= 6; i++)
                    if(n[i] && w[i] <= v) multiple_pack(w[i], n[i]);
               if(dp[v] != v) flag = 0;
          }
          printf("Collection #%d:\n", s++);
          if(flag == 1) printf("Can be divided.\n");
          else printf("Can't be divided.\n");
          printf("\n");
     }
     return 0;
}
