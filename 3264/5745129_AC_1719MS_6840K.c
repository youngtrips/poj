#include <stdio.h>
#include <math.h>
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define MAXN 50002
#define MAXM 17
int maxh[MAXN][MAXM];
int minh[MAXN][MAXM];
int n;
int rmq_min(int s, int e)
{
	int k = (int)((log(e - s + 1) * 1.0) / log(2.0));
	return MIN(minh[s][k], minh[e-(1<<k) + 1][k]);
}
int rmq_max(int s, int e)
{
	int k = (int)((log(e - s + 1) * 1.0) / log(2.0));
	return MAX(maxh[s][k], maxh[e-(1<<k) + 1][k]);
}
int main()
{
	int q, i, j, h;
	scanf("%d %d", &n, &q);
	for(i = 1;i <= n; i++)
	{
		scanf("%d", &h);
		maxh[i][0] = h;
		minh[i][0] = h;
	}
	for(j = 1;(1<<j) <= n; j++)
	{
		for(i = 1;i+(1<<j)-1 <= n; i++)
		{
			maxh[i][j] = MAX(maxh[i][j-1], maxh[i+(1<<(j-1))][j-1]);
			minh[i][j] = MIN(minh[i][j-1], minh[i+(1<<(j-1))][j-1]);
		}
	}
	while(q--)
	{
		scanf("%d %d", &i, &j);
		printf("%d\n", rmq_max(i, j) - rmq_min(i, j));
	}
	return 0;
}
