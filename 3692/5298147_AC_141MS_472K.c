#include <stdio.h>
#include <string.h>
#define MAX 205
char adj[MAX][MAX], v[MAX];
int match[MAX], n, m;
int find(int i)
{
	int j;
	for(j = 1;j <= m; j++)
	{
		if(adj[i][j] == '1' && v[j] == '0')
		{
			v[j] = '1';
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
		memset(v, '0', sizeof(v));
		cnt += find(i);
	}
	return cnt;
}
int main()
{
	int p, i, j, s = 1;
	while(1)
	{
		scanf("%d %d %d", &n, &m, &p);
		if(n + m + p == 0) break;
		memset(adj, '1', sizeof(adj));
		while(p--)
		{
			scanf("%d %d", &i, &j);
			adj[i][j] = '0';
		}
		printf("Case %d: %d\n", s++, n + m - hungary());
	}
	return 0;
}
