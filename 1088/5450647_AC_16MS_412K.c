#include <stdio.h>
#include <string.h>
#define MAX 102
int flag[MAX][MAX];
int h[MAX][MAX];
int dx[4] = {0, -1,  0, 1};
int dy[4] = {1,  0, -1, 0};
int r;
int c;
void init()
{
     int i, j;
     scanf("%d %d", &r, &c);
     for(i = 1;i <= r; i++)
     {
          for(j = 1;j <= c; j++)
          {
               scanf("%d", &h[i][j]);
               flag[i][j] = -1;
          }
     }
}
int check(int x, int y){ return x >= 1 && x <= r && y >= 1 && y <= c; }
int search(int x, int y)
{
     int max;
     int tmp;
     int i;
     max = 1;
     if(flag[x][y] != -1) return flag[x][y];
     for(i = 0;i < 4; i++)
     {
          if(check(x + dx[i], y + dy[i]) && h[x][y] > h[x + dx[i]][y + dy[i]])
          {
               tmp = search(x + dx[i], y + dy[i]);
               if(max < tmp + 1) max = tmp + 1;
          }
     }
     flag[x][y] = max;
     return max;
}
int main()
{
     int max;
     int tmp;
     int i;
     int j;
     max = 1;
     init();
     for(i = 1;i <= r; i++)
     {
          for(j = 1;j <= c; j++)
          {
               tmp = search(i, j);
               if(max < tmp) max = tmp;
          }
     }
     printf("%d\n", max);
     return 0;
}
