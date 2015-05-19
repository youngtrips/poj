#include <stdio.h>
#define INFI 9999999
#define MAXN 105
int dist[MAXN], pre[MAXN], n, v, cost[MAXN][MAXN];
int M, N;
int rank[MAXN];
void Dijkstra( int xj, int sj )
{
	n = N+1;
	v = n;
	int s[MAXN], i, j, k, min, tmp;
	int cost1[MAXN][MAXN];
	for( i=1; i<=n; i++)
   		for(j=1; j<=n; j++)
    cost1[i][j] = cost[i][j];
for( i=1; i<=n; i++)
   if( rank[i]<xj || rank[i]>sj )
   {
    for( j=1; j<=n; j++)
    {
     cost1[i][j] = cost1[j][i] = INFI;
    }
   }

for( i=1; i<=n; i++)
{

   {
    dist[i] = cost1[v][i];
    s[i] = 0;
    if( dist[i] < INFI )
     pre[i] = v;
    else pre[i] = 0;
   }
}

s[v] = 1;
pre[v] = 0;
for( i=1; i<=n; i++)
{
   min = INFI;
   k = 0;
   for( j=1; j<=n; j++)
    if( s[j] == 0 && dist[j]<min )
    {
     min = dist[j];
     k = j;
    }
   if( k== 0 ) break;
   if( k== 1 ) break;
   s[k] = 1;
   for( j=1; j<=n; j++)
    if( s[j]==0 && cost1[k][j]<INFI && (tmp = dist[k] + cost1[k][j]) < dist[j] )
    {
     dist[j] = tmp;
     pre[j] = k;
    }

}
}

void read()
{
scanf("%d%d", &M, &N);
int i, j, a, p, t ;
for( i=1; i<=N+1; i++)
{
   for( j=1; j<=N+1; j++)
    cost[i][j] = INFI;
   cost[i][i] = 0;
}
for( i=1; i<=N; i++)
{
   scanf("%d%d%d", &p, &rank[i], &t);
   cost[N+1][i] = p;
   for( j=1; j<=t; j++)
   {
    scanf("%d%d", &a, &p);
    cost[a][i] = p;
   }
}
rank[N+1] = rank[1];
}

int solve()
{
int xj, sj, min;
min = INFI;
for( xj = rank[1]-M, sj=rank[1]; xj<=rank[1] /* && xj>=0 */ ; xj++, sj++ )
{
   Dijkstra( xj, sj);
   if( dist[1]<min )
    min = dist[1];
}
return min;
}
int main()
{
read();
printf("%d\n", solve() );
return 0;
}

