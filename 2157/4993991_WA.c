#include <stdio.h>
#include <memory.h>
#define MAX 20
typedef struct
{
	int x;
	int y;
	int n;
}Door;
Door door[5];
char visited[MAX][MAX];
char map[MAX][MAX];
int q_x[MAX * MAX];
int q_y[MAX * MAX];
int keys[5];
int dx[4] = {1, 0, -1,  0};
int dy[4] = {0, 1,  0, -1};
int m, n, num, startx, starty, endx, endy, head, tail;
int init()
{
	int i, j;
	char ch;
	scanf("%d %d", &m, &n);
	if(m == 0 && n == 0) return 0;
	for(i = 0;i < 5; i++)
		door[i].n = 0;
	num = 0;
	for(i = 0;i < m; i++)
	{
		scanf("%s", map[i]);
		for(j = 0;j < n; j++)
		{
			ch = map[i][j];
			if(ch == 'S')
			{
				startx = i;
				starty = j;
			}
			if(ch == 'G')
			{
				endx = i;
				endy = j;
			}
			if(ch >= 'A' && ch <= 'E')
			{
				door[ch - 'A'].x = i;
				door[ch - 'A'].y = j;
				num++;
			}
			if(ch >= 'a' && ch <= 'e')
				door[ch - 'a'].n++;
		}
	}
	return 1;
}
int iskey(int x, int y){return map[x][y] >= 'a' && map[x][y] <= 'e';}
int check(int x, int y)
{
	if(x < 0 || x >= m || y < 0 || y >= n) return 0;
	if((iskey(x, y) || map[x][y] == '.' || map[x][y] == 'G') && visited[x][y] == '0') return 1;
	return 0;
}
void bfs()
{
	int i, x1, y1;
	char ch;
	memset(visited, '0', sizeof(visited));
	memset(keys, 0, sizeof(keys));
	visited[startx][starty] = '1';
	q_x[0] = startx;
	q_y[0] = starty;
	head = 0;
	tail = 1;
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
				ch = map[x1 + dx[i]][y1 + dy[i]];
				if(ch >= 'a' && ch <= 'e')
				{
					map[x1 + dx[i]][y1 + dy[i]] = '.';
					keys[ch - 'a']++;
				}
			}
		}
		head++;
	}
}
int main()
{
	int i, cnt, flag, open;
	while(init())
	{
		flag = 0;
		while(1)
		{
			bfs();
			if(visited[endx][endy] == '1')
			{
				flag = 1;
				break;
			}
			open = 0;
			for(i = 0;i < num; i++)
			{
				if(door[i].n != 0 && door[i].n == keys[i])
				{
					map[door[i].x][door[i].y] = '.';
					door[i].n = 0;
					keys[i] = 0;
					open = 1;
				}
			}
			if(open == 0) break;
		}
		printf("%s\n", flag == 1 ? "YES" : "NO");
	}
	return 0;
}
