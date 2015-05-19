#include <stdio.h>
#include <string.h>
#define F 0
#define L 1
#define B 2
#define R 3
#define MAX 42
int dx[4] = {0, -1,  0,  1};
int dy[4] = {1,  0, -1,  0};
int mv_l[4][4] = {{L, F, R, B}, {B, L, F, R}, {R, B, L, F}, {F, R, B, L}};
int mv_r[4][4] = {{R, F, L, B}, {F, L, B, R}, {L, B, R, F}, {B, R, F, L}};
char map[MAX][MAX];
int q_x[MAX * MAX], q_y[MAX * MAX], dis[MAX][MAX], head, tail;
int right, left, stx, sty, edx, edy, w, h;
void init()
{
	int i, j;
	scanf("%d %d", &w, &h);
	getchar();
	for(i = 1;i <= h; i++)
	{
		for(j = 1;j <= w; j++)
		{
			map[i][j] = getchar();
			if(map[i][j] == 'S') {stx = i; sty = j;}
			if(map[i][j] == 'E') {edx = i; edy = j;}
		}
		getchar();
	}
	memset(dis, -1, sizeof(dis));
}
int check(int x, int y){return (x >= 1 && x <= h && y >= 1 && y <= w && map[x][y] != '#');}
void bfs()
{
	int tx, ty, x, y, i, k;
	dis[stx][sty] = 1;
	q_x[0] = stx;
	q_y[0] = sty;
	head = 0;
	tail = 1;
	while(head < tail)
	{
		x = q_x[head];
		y = q_y[head];
		k = dis[x][y];
		for(i = 0;i < 4; i++)
		{
			tx = x + dx[i]; ty = y + dy[i];
			if(check(tx, ty) && dis[tx][ty] == -1)
			{
				dis[tx][ty] = k + 1;
				if(tx == edx && ty == edy) return;
				q_x[tail] = tx;
				q_y[tail] = ty;
				tail++;
			}
		}
		head++;
	}
}
int move(int stx, int sty, int edx, int edy, int method, int curd)
{
	int cnt, x, y, i, j, d;
	x = stx;
	y = sty;
	d = curd;
	cnt = 1;
	while(x != edx || y != edy)
	{
		cnt++;
		for(j = 0;j < 4; j++)
		{
			if(method == L) i = mv_l[d][j];
			else i = mv_r[d][j];
			if(check(x + dx[i], y + dy[i]))
			{
				x += dx[i];
				y += dy[i];
				d = i;
				break;
			}
		}
	}
	return cnt;
}
int main()
{
	int i, t;
	scanf("%d", &t);
	while(t--)
	{
		init();
		for(i = 0;i < 4; i++) if(check(stx + dx[i], sty + dy[i])) break;
		right = move(stx, sty, edx, edy, R, i);
		left = move(stx, sty, edx, edy, L, i);
		bfs();
		printf("%d %d %d\n", left, right, dis[edx][edy]);
	}
	return 0;
}
