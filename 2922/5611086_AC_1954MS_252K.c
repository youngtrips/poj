#include <stdio.h>
#include <string.h>
#define MAXN 102
char visited[MAXN][MAXN];
short int map[MAXN][MAXN];
short int high, low, n;
void init()
{
	int i, j;
	scanf("%d", &n);
	for(i = 1;i <= n; i++)
		for(j = 1;j <= n; j++) scanf("%d", &map[i][j]);
}
int find(int x, int y)
{
	if(x < 1 || x > n || y < 1 || y > n || visited[x][y] == 1 || map[x][y] < low || map[x][y] > high) return 0;
	visited[x][y] = 1;
	return ((x == n && y == n) || find(x, y + 1) || find(x, y - 1) || find(x + 1, y) || find(x - 1, y));
}
void solve(int s)
{
	short int ans, min, max;
	ans = 200;
	for(low = 0;low <= 200; low++)
	{
		min = low; max = 201;
		while(min < max)
		{
			high = (min + max)>>1;
			memset(visited, 0, sizeof(visited));
			if(find(1,1)) max = high;
			else min = ++high;
		}
		if(high < 201 && ans > high - low) ans = high - low;
	}
	printf("Scenario #%d:\n", s);
	printf("%d\n\n", ans);
}
int main()
{
	int t, i;
	scanf("%d", &t);
	for(i = 1;i <= t; i++)
	{
		init();
		solve(i);
	}
	return 0;
}
