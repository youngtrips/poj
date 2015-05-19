#include <stdio.h>
#include <string.h>
#define MAX 16
char ans[MAX * MAX];
char dir[] = "SENW";
char map[MAX][MAX];
int visited[MAX][MAX];
int pre[MAX][MAX];
int que[MAX * MAX][2];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int head, tail;
int stx, sty, edx, edy;
int init()
{
	int x1, y1;
	int x2, y2;
	int i, j;
	scanf("%d %d", &sty, &stx);
	if(stx == 0 && sty == 0) return 0;
	scanf("%d %d", &edy, &edx);
	memset(map, '0', sizeof(map));
	for(j = 1;j <= 3; j++)
	{
		scanf("%d %d %d %d", &y1, &x1, &y2, &x2);
		x1 <<= 1; y1 <<= 1; x2 <<= 1; y2 <<= 1;
		if(x1 == x2) for(i = y1;i <= y2; i++) map[x1][i] = '1';
		else for(i = x1;i <= x2; i++) map[i][y1] = '1';
	}
	return 1;
}
void debug()
{
	int i, j;
	for(i = 0;i <= 12; i++)
	{
		for(j = 0;j <= 12; j++) printf("%c", map[i][j]);
		printf("\n");
	}
}
void bfs()
{
	int tx, ty, x, y, i, k;
	memset(visited, 0, sizeof(visited));
	memset(pre, -1, sizeof(pre));
	stx = stx * 2 - 1; sty = sty * 2 - 1;
	edx = edx * 2 - 1; edy = edy * 2 - 1;
	visited[stx][sty] = 1;
	pre[stx][sty] = -1;
	que[0][0] = stx; que[0][1] = sty;
	head = 0; tail = 1;
	while(head < tail)
	{
		x = que[head][0]; y = que[head][1];
		for(i = 0;i < 4; i++)
		{
			tx = x + dx[i]; ty = y + dy[i];
			if(tx < 0 || tx > 12 || ty < 0 || ty > 12) continue;
			if(visited[tx][ty] == 1) continue;
			if(map[tx][ty] == '1') continue;
			
			visited[tx][ty] = 1;
			pre[tx][ty] = i;
			
			if(tx == edx && ty == edy) break;
			que[tail][0] = tx; que[tail][1] = ty;
			tail++;
		}
		head++;
	}
	ans[0] = '\n';
	i = 0;
	while(edx != stx || edy != sty)
	{
		k = pre[edx][edy];
		if(edx % 2 != 0 && edy % 2 != 0) ans[++i] = dir[k];
		edx -= dx[k];
		edy -= dy[k];
	}
	while(i >= 0) putchar(ans[i--]);
}
int main()
{
	while(init()) bfs();
	return 0;
}
