#include <stdio.h>
#include <string.h>
#define MAXN 2002
int mat[MAXN][MAXN];
int stack[MAXN][2];
int h[MAXN][MAXN];
int top;
int m, n;
int init()
{
	int i, j;
	if(scanf("%d %d", &m, &n) == EOF) return 0;
	for(i = 1;i <= m; i++)
		for(j = 1;j <= n; j++) scanf("%d", &mat[i][j]);
	return 1;
}
void solve()
{
	int maxarea, area;
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
			if(top < 0 || h[x][i] > stack[top][0])
			{
				++top;
				stack[top][0] = h[x][i];
				stack[top][1] = i;
				continue;
			}
			if(stack[top][0] == h[x][i]) continue;
			while(h[x][i] < stack[top][0] && top > -1)
			{
				area = stack[top][0] * (i - stack[top][1]);
				if(area > maxarea) maxarea = area;
				top--;
			}
			if(top > -1 && stack[top][0] == h[x][i]) continue;
			j = stack[top--][1];
			top++;
			stack[top][0] = h[x][i];
			stack[top][1] = j;
		}
	}
	printf("%d\n", maxarea);
}
int main()
{
	while(init()) solve();
	return 0;
}
