#include <stdio.h>
#include <string.h>
#define oo 99999999
#define MAXN 10002
#define MAXM 1002
int dist[MAXM][MAXM];
int map[MAXM][MAXM];
int q_x[MAXM * MAXM];
int q_y[MAXM * MAXM];
int pos[MAXN][2];
int dx[4] = {0, 1,  0, -1};
int dy[4] = {1, 0, -1,  0};
int head, tail;
int stx, sty;
int edx, edy;
int n, r, c;
void init()
{
	int i;
	scanf("%d %d %d", &n, &r, &c);
	scanf("%d %d %d %d", &stx, &sty, &edx, &edy);
	for(i = 0;i < n; i++) scanf("%d %d", &pos[i][0], &pos[i][1]);
}
int check(int x, int y)
{
	return x >= 0 && x < r && y >= 0 && y < c;
}
void bfs_init()
{
	int tx, ty;
	int i, j, k;
	int x, y;
	for(i = 0;i < r; i++)
		for(j = 0;j < c; j++) map[i][j] = oo;
	head = 0;
	for(tail = 0;tail < n; tail++)
	{
		x = pos[tail][0]; y = pos[tail][1];
		q_x[tail] = x;
		q_y[tail] = y;
		map[x][y] = 0;
	}
	while(head < tail)
	{
		x = q_x[head];
		y = q_y[head];
		k = map[x][y];
		for(i = 0;i < 4; i++)
		{
			tx = x + dx[i];
			ty = y + dy[i];
			if(check(tx, ty) && k + 1 < map[tx][ty])
			{
				map[tx][ty] = k + 1;
				q_x[tail] = tx;
				q_y[tail] = ty;
				tail++;
			}
		}
		head++;
	}
}
int bfs_min(int min)
{
	int tx, ty;
	int x, y;
	int i, j, k;
	memset(dist, -1, sizeof(dist));
	dist[stx][sty] = 0;
	q_x[0] = stx;
	q_y[0] = sty;
	head = 0;
	tail = 1;
	if(map[stx][sty] < min) return -1;
	while(head < tail)
	{
		x = q_x[head];
		y = q_y[head];
		k = dist[x][y];
		for(i = 0;i < 4; i++)
		{
			tx = x + dx[i];
			ty = y + dy[i];
			if(check(tx, ty) && map[tx][ty] >= min && dist[tx][ty] == -1)
			{
				dist[tx][ty] = k + 1;
				if(tx == edx && ty == edy) return dist[tx][ty];
				q_x[tail] = tx;
				q_y[tail] = ty;
				tail++;
			}
		}
		head++;
	}
	return -1;
}
void bisearch()
{
	int high = r + c;
	int low = 0;
	int mid;
	while(low < high)
	{
		mid = (low + high + 1) / 2;
		if(bfs_min(mid) == -1) high = mid - 1;
		else low = mid;
	}
	if(dist[edx][edy] == -1) mid--;
	printf("%d %d\n", mid, bfs_min(mid));
}
int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		init();
		bfs_init();
		bisearch();
	}
	return 0;
}
