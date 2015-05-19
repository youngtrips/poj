#include <stdio.h>
#include <string.h>
#define MAXN 1002
#define MAXM 202
int adj[MAXN][MAXM], match[MAXN], v[MAXN], n, m;
int find(int i)
{
	int j;
	for(j = 0;j < m; j++)
		if(adj[i][j] && v[j] == 0)
		{
			v[j] = 1;
			if(match[j] == -1 || find(match[j]))
			{
				match[j] = i;
				return 1;
			}
		}
	return 0;
}
int hungary()
{
	int cnt = 0, i;
	memset(match, -1, sizeof(match));
	for(i = 0;i < n; i++)
	{
		memset(v, 0, sizeof(v));
		cnt += find(i);
	}
	return cnt;
}
int main()
{
	int m1, m2, i, x, y, k;
	while(1)
	{
		scanf("%d", &m1); if(m1 == 0) break;
		scanf("%d %d", &m2, &n);
		memset(adj, 0, sizeof(adj));
		for(k = 0;k < n; k++)
		{
			scanf("%d %d %d", &i, &x, &y);
			if(x * y != 0) 
			{
				adj[x][y] = 1;
			}
		}
		n = m1;
		m = m2;
		k = hungary();
		printf("%d\n", k);
	}
	return 0;
}
