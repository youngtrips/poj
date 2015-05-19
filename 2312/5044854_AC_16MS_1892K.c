#include <stdio.h>
#define INF 100000000
#define MAX 502
int map[MAX][MAX];
int min[MAX][MAX];
int q_x[MAX * MAX];
int q_y[MAX * MAX];
int dx[4] = {1, 0, -1,  0};
int dy[4] = {0, 1,  0, -1};
int head, tail, startx, starty, endx, endy, m, n;
int init()
{
	char ch;
	int i, j;
	scanf("%d %d", &m, &n);
	
	if(m == 0 && n == 0) return 0;
	getchar();
	for(i = 0;i < m; i++)
	{
		for(j = 0;j < n; j++)
		{
			min[i][j] = INF;
			ch = getchar();
			switch(ch)
			{
				case 'Y': map[i][j] = 1; startx = i; starty = j; break;
				case 'S':
				case 'R': map[i][j] = INF; break;
				case 'B': map[i][j] = 2; break;
				case 'E': map[i][j] = 1 ;break;
				case 'T': map[i][j] = 0; endx = i; endy = j; break;
			}
		}
		getchar();
	}
	min[startx][starty] = map[startx][starty];
	q_x[0] = startx;
	q_y[0] = starty;
	tail = 1;
	return 1;
}
void bfs()
{
	int i, j, x1, y1, tx, ty;
	head = 0;
	while(head < tail)
	{
		x1 = q_x[head];
		y1 = q_y[head];
		for(i = 0;i < 4; i++)
		{
			tx = x1 + dx[i];
			ty = y1 + dy[i];
			if(tx >= 0 && tx < m && ty >= 0 && ty < n)
			{
				if(min[tx][ty] > min[x1][y1] + map[tx][ty])
				{
					q_x[tail] = tx;
					q_y[tail] = ty;
					tail++;
					min[tx][ty] = min[x1][y1] + map[tx][ty];
				}
			}
		}
		head++;
	}
}
int main()
{
	int res;
	while(init())
	{
		bfs();
		res = min[endx][endy];
		if(res == INF) printf("-1\n");
		else printf("%d\n", res);
	}
	return 0;
}
