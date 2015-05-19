#include <stdio.h>
#include <string.h>
#define MAX 102
int adj[MAX][MAX], n, m;
int match[MAX], v[MAX], f[MAX], d[MAX];
int find(int i)
{
	int j;
	for(j = 1;j <= m; j++)
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
	int nf, nd, k, i, j;
	while(scanf("%d %d %d", &k, &n, &m) != EOF)
	{
		memset(adj, 0, sizeof(adj));
		while(k--)
		{
			scanf("%d %d", &nf, &nd);
			for(i = 0;i < nf; i++) scanf("%d", f + i);
			for(i = 0;i < nd; i++) scanf("%d", d + i);
			for(i = 0;i < nf; i++)
				for(j = 0;j < nd; j++) adj[f[i]][d[j]] = 1;
		}
		printf("%d\n", hungary());
	}
	return 0;
}
