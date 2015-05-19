#include <stdio.h>
#define N 101
char visited[N][N];
char map[N][N];
int dx[8] = {0, 1, -1, 0, 1, -1,  1, -1};
int dy[8] = {1, 0,  0,-1, 1,  1, -1, -1};
int q_x[N * N];
int q_y[N * N];
int n, m;
int head, tail;
int init()
{
	int i, j;
	scanf("%d %d", &n, &m);
	if(n == 0 && m == 0)
		return 0;
	for(i = 0;i < n; i++)
	{
		scanf("%s", map[i]);
	}
	for(i = 0;i < n; i++)
		for(j = 0;j < m; j++)
			visited[i][j] = '0';
	return 1;
}
int check(int x, int y)
{
	return (x >= 0 && x < n && y >= 0 && y < m &&
			map[x][y] == '@' && visited[x][y] == '0');
}
void bfs()
{
	int i, x1, y1;
	head = 0;
	while(head < tail)
	{
		x1 = q_x[head];
		y1 = q_y[head];
		for(i = 0;i < 8; i++)
		{
			if(check(x1 + dx[i], y1 + dy[i]))
			{
				visited[x1 + dx[i]][y1 + dy[i]] = '1';
				q_x[tail] = x1 + dx[i];
				q_y[tail] = y1 + dy[i];
				tail++;
			}
		}
		head++;
	}
}
int search()
{
	int i, j, cnt = 0;
	for(i = 0;i < n; i++)
		for(j = 0;j < m; j++)
			if(map[i][j] == '@' && visited[i][j] == '0')
			{
				cnt++;
				visited[i][j] = '1';
				q_x[0] = i;
				q_y[0] = j;
				tail = 1;
				bfs();
			}
	return cnt;
}
int main()
{
	while(init())
		printf("%d\n", search());
	return 0;
}
