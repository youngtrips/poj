#include <stdio.h>
#include <string.h>
#define MAXN 24
char map[MAXN][MAXN];
int visited[MAXN][MAXN];
int cnt[MAXN][MAXN];
int que[MAXN * MAXN][2];
int dx[8] = {1, 1, 0, -1, -1, -1,  0,  1};
int dy[8] = {0, 1, 1,  1,  0, -1, -1, -1};
int head, tail;
int stx, sty, r, c;
int init()
{
	int i, j;
	scanf("%d %d %d %d", &r, &c, &stx, &sty);
	if(r == 0 && c == 0 && stx == 0 && sty == 0) return 0;
	memset(map, '.', sizeof(map));
	getchar();
	for(i = 1;i <= r; i++)
	{
		for(j = 1;j <= c; j++) map[i][j] = getchar();
		getchar();
	}
	return 1;
}
int check(int x, int y)
{
	return visited[x][y] == 0 && map[x][y] == 'X';
}
void bfs()
{
	int tx, ty, i, x, y;
	memset(visited, 0, sizeof(visited));
	memset(cnt, 0, sizeof(cnt));
	visited[stx][sty] = 1;
	que[0][0] = stx; que[0][1] = sty;
	head = 0; tail = 1;
	while(head < tail)
	{
		x = que[head][0];
		y = que[head][1];
		for(i = 0;i < 8; i++)
		{
			tx = x + dx[i];
			ty = y + dy[i];
			if((dx[i] == 0 || dy[i] == 0) && map[tx][ty] == '.') cnt[tx][ty]++;
			if(check(tx, ty) == 0) continue;
			visited[tx][ty] = 1;
			que[tail][0] = tx;
			que[tail][1] = ty;
			tail++;
		}
		head++;
	}
}
void solve()
{
	int ans, i, j;
	bfs();
	ans = 0;
	for(i = 0;i <= r + 1; i++)
		for(j = 0;j <= c + 1; j++) ans += cnt[i][j];
	printf("%d\n", ans);
}
int main()
{
	while(init()) solve();
	return 0;
}
