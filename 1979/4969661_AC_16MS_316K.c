#include <stdio.h>
#define N 21
char visited[N][N];
char map[N][N];
int dx[4] = {1, 0, -1,  0};
int dy[4] = {0, 1,  0, -1};
int q_x[N * N];
int q_y[N * N];
int head, tail;
int w, h;
int init()
{
	int i, j;
	scanf("%d %d", &w, &h);
	if(w == 0 && h == 0)
		return 0;
	getchar();
	for(i = 0;i < h; i++)
	{
		for(j = 0;j < w; j++)
		{
			visited[i][j] = '0';
			map[i][j] = getchar();
			if(map[i][j] == '@')
			{
				visited[i][j] = '1';
				q_x[0] = i;
				q_y[0] = j;
				tail = 1;
			}
		}
		getchar();
	}
	return 1;
}
int check(int x, int y)
{
	return (x >= 0 && x < h && y >= 0 && y < w &&
			map[x][y] == '.' && visited[x][y] == '0');
}
int bfs()
{
	int i, x1, y1, cnt = 0;
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
int main()
{
	while(init())
		printf("%d\n", bfs() + 1);
	return 0;
}
