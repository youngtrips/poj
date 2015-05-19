#include <stdio.h>
#include <string.h>
#define MAXN 302
#define MAXM 86
int adj[MAXN][MAXN], n, m;
int match[MAXN], v[MAXN];
int find(int i)
{
	int j;
	for(j = 1;j <= m; j++)
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
	for(i = 1;i <= n; i++)
	{
		memset(v, 0, sizeof(v));
		cnt += find(i);
	}
	return cnt;
}
int main()
{
	int t, i, j, p, q;
	while(scanf("%d", &n) != EOF)
	{
		memset(adj, 0, sizeof(adj));
		m = 0;
		for(i = 1;i <= n; i++)
		{
			scanf("%d", &t);
			while(t--)
			{
				scanf("%d %d", &p, &q);
				j = (p - 1) * 12 + q;
				adj[i][j] = 1;
				if(m < j) m = j;
			}
		}
		printf("%d\n", hungary());
	}
	return 0;
}
