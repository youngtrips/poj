#include <stdio.h>
#include <string.h>
#define MAX 22
char map[MAX][MAX];
int dx[4] = {0, 1, -1,  0};
int dy[4] = {1, 0,  0, -1};
int flag[26] ,max, r, s;
int init()
{
	int i, j;
	if(scanf("%d %d", &r, &s) == EOF) return 0;
	getchar();
	for(i = 1;i <= r; i++)
	{
		for(j = 1;j <= s; j++) map[i][j] = getchar();
		getchar();
	}
	memset(flag, 0, sizeof(flag));
	max = 0;
	return 1;
}
int check(int x, int y){return x >= 1 && x <= r && y >= 1 && y <= s && flag[map[x][y] - 'A'] == 0;}
void dfs(int x, int y, int cnt)
{
	int tx, ty, i;
	if(cnt > max) max = cnt;
	for(i = 0;i < 4; i++)
	{
		tx = x + dx[i]; ty = y + dy[i];
		if(check(tx, ty))
		{
			flag[map[tx][ty] - 'A'] = 1;
			dfs(tx, ty, cnt + 1);
			flag[map[tx][ty] - 'A'] = 0;
		}
	}
}
int main()
{
	init();
	flag[map[1][1] -'A'] = 1;
	dfs(1, 1, 1);
	printf("%d\n", max);
	return 0;
}
