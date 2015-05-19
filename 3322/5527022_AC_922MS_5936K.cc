#include <iostream>
#include <cstdio>
#include <string.h>
#include <vector>
#include <queue>
using namespace std;
unsigned char map[500][500];
unsigned int g[500][500][3];
int bx,by,bs,ex,ey;
int dx[3][4] = {-2,1,0,0,-1,1,0,0,-1,2,0,0}; //up down left right
int dy[3][4] = {0,0,-2,1,0,0,-1,2,0,0,-1,1};
int ds[3][4] = {2,2,1,1,1,1,0,0,0,0,2,2};
struct Node
{
int f,x,y,s;
};
struct cmp
{
bool operator()(const Node &a,const Node &b)
{
      return a.f > b.f;
}
};
inline int ABS(int x)
{
return x > 0 ? x : -x;
}
inline int h(const Node &a)    //估价函数
{
int t1 = ABS(ex-a.x);
int t2 = ABS(ey-a.y);
int v = 2*(t1 / 3 + t2 / 3);
if(t1 % 3) ++v;
if(t2 % 3) ++v;
return v;
}
inline bool Check(const Node &a)
{
if(a.x <= 0 || a.y <= 0 || map[a.x][a.y] == 0) return false;
if(a.s == 0 && map[a.x][a.y] == 2)           return false;
if(a.s == 1 && map[a.x][a.y+1] == 0)         return false;
if(a.s == 2 && map[a.x+1][a.y] == 0)         return false;
return true;
}
int Abfs()
{
memset(g,0xff,sizeof(g));
priority_queue<Node,vector<Node>,cmp> pq;
Node n1,n2;
n1.x = bx,n1.y = by,n1.s = bs;
g[n1.x][n1.y][n1.s] = 0;
n1.f = g[n1.x][n1.y][n1.s] + h(n1);
pq.push(n1);
while(!pq.empty())
{
      n1 = pq.top();pq.pop();
      if(n1.x == ex && n1.y == ey && n1.s == 0) return g[ex][ey][0];
      for(int i=0;i<4;++i)
      {
          n2.x = n1.x + dx[n1.s][i];
          n2.y = n1.y + dy[n1.s][i];
          n2.s = ds[n1.s][i];
          if(Check(n2) && g[n2.x][n2.y][n2.s] > g[n1.x][n1.y][n1.s] + 1)
          {
              g[n2.x][n2.y][n2.s] = g[n1.x][n1.y][n1.s] + 1;
              n2.f = g[n2.x][n2.y][n2.s] + h(n2);
              pq.push(n2);
          }
      }
}
return -1;
}
int main()
{
    int r,c;
while(scanf("%d%d",&r,&c),r+c)
{
      bool flag = true;
      for(int i=0;i<r;++i)
      {
          while(getchar() != '\n');
          for(int j=0;j<c;++j)
          {
              switch(getchar())
              {
                  case '#': map[i][j] = 0;break;
                  case '.': map[i][j] = 1;break;
                  case 'E': map[i][j] = 2;break;
                  case 'O': map[i][j] = 1;ex=i;ey=j;break;
                  default :
                          if(flag) map[i][j]=1,bx=i,by=j,bs=0,flag=false;                  //默认为状态0
                            else   map[i][j]=1,bs = j == by+1 ? 1 : 2;                       //判断是状态1还是状态2；
                }
          }
      }
      int min = Abfs();
      if(min == -1) printf("Impossible\n");
      else        printf("%d\n",min);
}
return 0;
}
