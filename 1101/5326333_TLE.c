#include <stdio.h>
#include <string.h>
#define oo 99999999
#define MAX 80
char map[MAX][MAX];
int visited[MAX][MAX];
int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, 1, -1, 0};
int stx, sty, edx, edy, cnt, max, w, h;
int check(int x, int y)
{
	if(x == edx && y == edy) return 1;
	return x >= 0 && x <= h+1 && y >= 0 && y <= w+1 && map[x][y] != 'X' && visited[x][y] == 0;
}
void dfs(int x, int y, int d)
{
	int tx, ty, i;
	if(x == edx && y == edy) { if(max > cnt) max = cnt;return;}
	for(i = 0;i < 4; i++)
	{
		tx = x + dx[i];
		ty = y + dy[i];
		if(check(tx, ty))
		{
			if(d != -1 && d != i) cnt++;
			visited[x][y] = 1;
			dfs(tx, ty, i);
			visited[x][y] = 0;
			if(d != -1 && d != i) cnt--;
		}
	}
}
int main()
{
	int i, j, s = 1;
	while(1)
	{
		scanf("%d %d", &w, &h);
		if(w == 0 && h == 0) break;
		getchar();
		for(i = 1;i <= h; i++)
		{
			for(j = 1;j <= w; j++) map[i][j] = getchar();
			getchar();
		}
		printf("Board #%d:\n", s++);
		i = 1;
		while(1)
		{
			scanf("%d %d %d %d", &sty, &stx, &edy, &edx);
			if(stx == 0 && sty == 0 && edx == 0 && edy == 0) break;
			memset(visited, 0, sizeof(visited));
			cnt = 1; max = oo;
			dfs(stx, sty, -1);
			printf("Pair %d: ", i++);
			if(max == oo) printf("impossible.\n");
			else printf("%d segments.\n", max);
		}
		printf("\n");
	}
	return 0;
}
