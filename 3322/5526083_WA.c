#include <stdio.h>
#include <string.h>
#define MAX 502
#define S 0
#define E 1
#define N 2
#define W 3
int que[MAX * MAX * 3][4];
int has[MAX][MAX][3];
int map[MAX][MAX];
int dx[4] = {1, 0, -1,  0};
int dy[4] = {0, 1,  0, -1};
int pos[3][2];
int init_stat;
int head, tail;
int stx, sty, edx, edy;
int r, c, n;
int init()
{
	int i, j;
	scanf("%d %d", &r, &c);
	if(r == 0 && c == 0) return 0;
	getchar();
	n = 0;
	for(i = 1;i <= r; i++)
	{
		for(j = 1;j <= c; j++)
		{
			map[i][j] = getchar();
			if(map[i][j] == 'X')
			{
				++n;
				pos[n][0] = i;
				pos[n][1] = j;
			}
			else if(map[i][j] == 'O')
			{
				edx = i;
				edy = j;
			}
		}
		getchar();
	}
	if(n == 1)
	{
		init_stat = 0;
		stx = pos[1][0];
		sty = pos[1][1];
	}
	else
	{
		if(pos[1][0] == pos[2][0])
		{
			init_stat = 1;
			stx = pos[1][0];
			sty = pos[1][1] < pos[2][1] ? pos[1][1] : pos[2][1];
		}
		else 
		{
			init_stat = 2;
			stx = pos[1][0] < pos[2][0] ? pos[1][0] : pos[2][0];
			sty = pos[1][1];
		}
	}
	return 1;
}
int check(int x, int y)
{
	return x >= 1 && x <= r && y >= 1 && y <= c && map[x][y] != '#';
}
int bfs()
{
	int cur;
	int tx1, ty1;
	int tx2, ty2;
	int i, j, k;
	int x, y, z;
	memset(has, 0, sizeof(has));
	for(i = 1;i <= n; i++) has[pos[i][0]][pos[i][1]][init_stat] = 1;
	que[0][0] = stx; que[0][1] = sty;
	que[0][2] = init_stat; que[0][3] = 0;
	head = 0; tail = 1;
	while(head < tail)
	{
		x = que[head][0]; y = que[head][1];
		z = que[head][2]; k = que[head][3];
		for(i = 0;i < 4; i++)
		{
			if(z == 0) /*standing up */
			{
				tx1 = x + dx[i]; ty1 = y + dy[i];
				tx2 = x + 2 * dx[i]; ty2 = y + 2 * dy[i];
				if(i == W || i == E)
				{
					cur = 1;
					if(check(tx1, ty1) && check(tx2, ty2) && (has[tx1][ty1][cur] == 0 || has[tx2][ty2][cur] == 0))
					{
						has[tx1][ty1][cur] = 1;
						has[tx2][ty2][cur] = 1;
						que[tail][0] = tx1;
						que[tail][1] = ty1 < ty2 ? ty1 : ty2;
						que[tail][2] = cur;
						que[tail][3] = k + 1;
						tail++;
					}
				}
				else
				{
					cur = 2;
					if(check(tx1, ty1) && check(tx2, ty2) && (has[tx1][ty1][cur] == 0 || has[tx2][ty2][cur] == 0))
					{
						has[tx1][ty1][cur] = 1;
						has[tx2][ty2][cur] = 1;
						que[tail][0] = tx1 < tx2 ? tx1 : tx2;
						que[tail][1] = ty1;
						que[tail][2] = cur;
						que[tail][3] = k + 1;
						tail++;
					}
				}
			}
			else if(z == 1) /* lying down towards righ */
			{
				if(i == N || i == S)
				{
					tx1 = x + dx[i]; ty1 = y + dy[i];
					tx2 = tx1; ty2 = ty1 + 1;
					cur = 1;
					if(check(tx1, ty1) && check(tx2, ty2) && (has[tx1][ty1][cur] == 0 || has[tx2][ty2][cur] == 0))
					{
						has[tx1][ty1][cur] = 1;
						has[tx2][ty2][cur] = 1;
						que[tail][0] = tx1;
						que[tail][1] = ty1;
						que[tail][2] = cur;
						que[tail][3] = k + 1;
						tail++;
					}
				}
				else
				{
					tx1 = x + dx[i]; ty1 = y + dy[i];
					if(i == E) ty1++;
					cur = 0;
					if(check(tx1, ty1) && has[tx1][ty1][cur] == 0 && map[tx1][ty1] != 'E')
					{
						if(tx1 == edx && ty1 == edy) return k + 1;
						has[tx1][ty1][cur] = 1;
						que[tail][0] = tx1;
						que[tail][1] = ty1;
						que[tail][2] = cur;
						que[tail][3] = k + 1;
						tail++;
					}
				}
			}
			else /*lying down towards bottom */
			{
				if(i == W || i == E)
				{
					tx1 = x + dx[i]; ty1 = y + dy[i];
					tx2 = tx1 + 1; ty2= ty1;
					cur = 2;
					if(check(tx1, ty1) && check(tx2, ty2) && (has[tx1][ty1][cur] == 0 || has[tx2][ty2][cur] == 0))
					{
						has[tx1][ty1][cur] = 1;
						has[tx2][ty2][cur] = 1;
						que[tail][0] = tx1;
						que[tail][1] = ty1;
						que[tail][2] = cur;
						que[tail][3] = k + 1;
						tail++;
					}
				}
				else
				{
					tx1 = x + dx[i]; ty1 = y + dy[i];
					if(i == S) tx1++;
					cur = 0;
					if(check(tx1, ty1) && has[tx1][ty1][cur] == 0 && map[tx1][ty1] != 'E')
					{
						if(tx1 == edx && ty1 == edy) return k + 1;
						has[tx1][ty1][cur] = 1;
						que[tail][0] = tx1;
						que[tail][1] = ty1;
						que[tail][2] = cur;
						que[tail][3] = k + 1;
						tail++;
					}
				}
			}
		}
		head++;
	}
	return -1;
}
int main()
{
	int ans;
	while(init())
	{
		ans = bfs();
		if(ans == -1) printf("Impossible\n");
		else printf("%d\n", ans);
	}
	return 0;
}
