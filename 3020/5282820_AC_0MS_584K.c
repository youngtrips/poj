#include <stdio.h>
#include <string.h>
#define MAXN 402
char adj[MAXN][MAXN];
int x[MAXN], y[MAXN], n;
int myabs(int x){ return x < 0 ? (-x) : x;}
int dist(int i, int j){return myabs(x[i] - x[j]) + myabs(y[i] - y[j]);}
void init()
{
	char ch;
	int h, w, i, j;
	scanf("%d %d", &h, &w);
	getchar();
	n = 0;
	for(i = 1;i <= h; i++)
	{
		for(j = 1;j <= w; j++)
		{
			ch = getchar();
			if(ch == '*')
			{
				++n;
				x[n] = i;
				y[n] = j;
			}
		}
		getchar();
	}
	memset(adj, '0', sizeof(adj));
	for(i = 1;i <= n; i++)
		for(j = i + 1;j <= n; j++)
			if(dist(i, j) == 1) {adj[i][j] = '1'; adj[j][i] = '1';}
}
int find(int i)
{
	int j;
	for(j = 1;j <= n; j++)
	{
		if(adj[i][j] == '1' && x[j] == 0)
		{
			x[j] = 1;
			if(y[j] == -1 || find(y[j]))
			{
				y[j] = i;
				return 1;
			}
		}
	}
	return 0;
}
int hungary()
{
	int cnt = 0, i;
	memset(y, -1, sizeof(y));
	for(i = 1;i <= n; i++)
	{
		memset(x, 0, sizeof(x));
		cnt += find(i);
	}
	return cnt;
}
int main()
{
	int res, t;
	scanf("%d", &t);
	while(t--)
	{
		init();
		res = hungary()>>1;
		printf("%d\n", n - res);
	}
	return 0;
}
