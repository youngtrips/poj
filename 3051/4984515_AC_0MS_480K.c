#include <stdio.h>
#define MAXH 1001
#define MAXW 81
char visited[MAXH][MAXW];
char map[MAXH][MAXW];
int q_x[MAXH * MAXW];
int q_y[MAXH * MAXW];
int dx[4] = {1, 0, -1,  0};
int dy[4] = {0, 1,  0, -1};
int head, tail, w, h;

void init()
{
	int i, j;
	scanf("%d %d", &w, &h);
	getchar();
	for(i = 0;i < h; i++)
	{
		for(j = 0;j < w; j++)
		{
			map[i][j] = getchar();
			visited[i][j] = '0';
		}
		getchar();
	}
}
int check(int x, int y)
{
	return (x >= 0 && x < h && y >= 0 && y < w && 
			map[x][y] == '*' && visited[x][y] == '0');
}
int bfs()
{
	int i, x1, y1, cnt = 1;
	head = 0;
	while(head < tail)
	{
		x1 = q_x[head];
		y1 = q_y[head];
		for(i = 0;i < 4; i++)
		{
			if(check(x1 + dx[i], y1 + dy[i]))
			{
				visited[x1 + dx[i]][y1 + dy[i]] = '1';
				q_x[tail] = x1 + dx[i];
				q_y[tail] = y1 + dy[i];
				tail++;
				cnt++;
			}
		}
		head++;
	}
	return cnt;
}
int search()
{
	int i, j, res, max = 0;
	for(i = 0;i < h; i++)
	{
		for(j = 0;j < w; j++)
		{
			if(map[i][j] == '*' && visited[i][j] == '0')
			{
				visited[i][j] = '1';
				q_x[0] = i;
				q_y[0] = j;
				tail = 1;
				res = bfs();
				if(max < res) max = res;
			}
		}
	}
	return max;
}
int main()
{
	init();
	printf("%d\n", search());
	return 0;
}
