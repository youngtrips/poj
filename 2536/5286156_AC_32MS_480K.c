#include <stdio.h>
#include <string.h>
#define dis(i,j) ((gx[i]-hx[j])*(gx[i]-hx[j])+(gy[i]-hy[j])*(gy[i]-hy[j]))
#define eps 1e-20
#define MAX 102
int adj[MAX][MAX], n, m;
int match[MAX], v[MAX];
double gx[MAX], gy[MAX], hx[MAX], hy[MAX];
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
	double max, tmp;
	int s, v, i, j;
	while(scanf("%d %d %d %d", &n, &m, &s, &v) != EOF)
	{
		for(i = 1;i <= n; i++) scanf("%lf %lf", &gx[i], &gy[i]);
		for(i = 1;i <= m; i++) scanf("%lf %lf", &hx[i], &hy[i]);
		max = v * v * s * s * 1.0;
		memset(adj, 0, sizeof(adj));
		for(i = 1;i <= n; i++)
		{
			for(j = 1;j <= m; j++)
			{
				tmp = dis(i, j);
				if(tmp + eps <= max) adj[i][j] = 1;
			}
		}
		printf("%d\n", n - hungary());
	}
	return 0;
}
