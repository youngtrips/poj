#include <stdio.h>
#include <string.h>
#define MAXN 2012
int mat[MAXN][MAXN];
int stack[MAXN * 2][2];
int h[MAXN][MAXN];
int top, m, n;
void solve()
{
	int maxarea, area, skip;
	int i, j, x;
	memset(h, 0, sizeof(h));
	maxarea = 0;
	for(x = 1;x <= m; x++)
	{
		for(i = 1;i <= n; i++)
		{
			if(x == 1 && mat[x][i] == 1) h[x][i] = 1;
			if(x > 1  && mat[x][i] == 1) h[x][i] = h[x-1][i] + 1;
		}
		h[x][n+1] = -1;
		top = -1;
		for(i = 1;i <= n + 1; i++)
		{
			j = i;
			skip = 0;
			while(top != -1)
			{
				if(stack[top][0] == h[x][i]) { skip = 1; break;}
				if(stack[top][0] < h[x][i]) break;
				area = stack[top][0] * (i - stack[top][1]);
				if(area > maxarea) maxarea = area;
				j = stack[top][1];
				top--;
			}
			if(skip == 0)
			{
				stack[++top][0] = h[x][i];
				stack[top][1] = j;
			}
		}
	}
	printf("%d\n", maxarea);
}
int main()
{
	int i, j;
	while(scanf("%d %d", &m, &n) != EOF)
	{
		for(i = 1;i <= m; i++)
			for(j = 1;j <= n; j++) scanf("%d", &mat[i][j]);
		solve();
	}
	return 0;
}
