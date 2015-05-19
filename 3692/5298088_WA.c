#include <stdio.h>
#include <string.h>
#define MAX 405
int adj[MAX][MAX], n;
int match[MAX], v[MAX];
int find(int i)
{
	int j;
	for(j = 1;j <= n; j++)
	{
		if(adj[i][j] && v[j] == 0)
		{
			v[j] = 1;
			if(match[j] == -1 || find(match[j]))
			{
				match[j] = i;
				return 1;
			}
		}
	}
	return 0;
}
int hungary()
{
	int cnt = 0, i;
	memset(match, -1, sizeof(match));
	for(i = 1;i <= n; i++)
	{
		memset(v, 0, sizeof(v));
		cnt += find(i);
	}
	return cnt;
}
int main()
{
	int g, b, m, i, j, s = 1;
	while(1)
	{
		scanf("%d %d %d", &g, &b, &m);
		if(g == 0 && b == 0 && m == 0) break;
		memset(adj, 0, sizeof(adj));
		for(i = 1;i <= g; i++)
			for(j = 1;j <= g; j++) adj[i][j] = 1;
		for(i = 1;i <= b; i++)
			for(j = 1;j <= b; j++) adj[i + g][j + g] = 1;
		while(m--)
		{
			scanf("%d %d", &i, &j);
			adj[i][j + g] = 1;
		}
		n = g + b;
		for(i = 1;i <= n; i++)
			for(j = 1;j <= n; j++) adj[i][j] ^= 1;
		m = hungary()>>1;
		printf("Case %d: %d\n", s++, n - m);
	}
	return 0;
}
