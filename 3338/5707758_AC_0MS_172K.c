#include <stdio.h>
#include <string.h>
#define MAXN 42
char map[MAXN][MAXN];
int que[MAXN * MAXN][2];
int dx[4] = {0, 1, -1,  0};
int dy[4] = {1, 0,  0, -1};
int head, tail;
int w, h;
int init()
{
	int max, min, x1, y1, x2, y2, i, j, n;
	scanf("%d %d", &w, &h);
	if(w == 0 && h == 0) return 0;
	scanf("%d", &n);
	memset(map, '.', sizeof(map));
	while(n--)
	{
		scanf("%d %d %d %d", &y1, &x1, &y2, &x2);
		map[x1 * 2][y1 * 2] = '#';
		map[x2 * 2][y2 * 2] = '#';
		max = (y1 > y2 ? y1 : y2) << 1;
		min = (y1 < y2 ? y1 : y2) << 1;
		for(i = min;i <= max; i++)
		{
			map[x1<<1][i] = '#';
			map[x2<<1][i] = '#';
		}
		max = (x1 > x2 ? x1 : x2) << 1;
		min = (x1 < x2 ? x1 : x2) << 1;
		for(i = min;i <= max; i++)
		{
			map[i][y1<<1] = '#';
			map[i][y2<<1] = '#';
		}
	}
	return 1;
}
void bfs(int stx, int sty)
{
	int tx, ty, x, y, i;
	que[0][0] = stx;
	que[0][1] = sty;
	head = 0;
	tail = 1;
	while(head < tail)
	{
		x = que[head][0];
		y = que[head][1];
		for(i = 0;i < 4; i++)
		{
			tx = x + dx[i];
			ty = y + dy[i];
			if(map[tx][ty] != '.') continue;
			if(tx < 0 || tx > 2 * w || ty < 0 || ty > 2 * h) continue;
			map[tx][ty] = '*';
			que[tail][0] = tx;
			que[tail][1] = ty;
			tail++;
		}
		head++;
	}
}
void solve()
{
	int cnt, i, j;
	cnt = 0;
	for(i = 0;i <= 2 * w; i++)
		for(j = 0;j <= 2 * h; j++)
			if(map[i][j] == '.') { cnt++; bfs(i, j);}
	printf("%d\n", cnt);
}
int main()
{
	while(init()) solve();
	return 0;
}
