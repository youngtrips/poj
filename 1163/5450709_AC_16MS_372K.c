#include <stdio.h>
#define MAX 102
int a[MAX][MAX];
int n;
void init()
{
     int i, j;
     scanf("%d", &n);
     for(i = 1;i <= n; i++)
     {
          for(j = 1;j <= i; j++) scanf("%d", &a[i][j]);
     }
}
void search()
{
     int i, j;
     for(i = n - 1;i >= 1; i--)
     {
          for(j = 1;j <= i; j++)
          {
               if(a[i][j] + a[i+1][j] < a[i][j] + a[i+1][j+1])
                    a[i][j] += a[i+1][j+1];
               else a[i][j] += a[i+1][j];
          }
     }
}
int main()
{
     init();
     search();
     printf("%d\n", a[1][1]);
     return 0;
}
