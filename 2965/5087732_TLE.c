#include <stdio.h>
#include <memory.h>
#define CLS(x) memset(x, -1, sizeof(x))
#define MAX 65536
typedef struct
{
	int x;
	int y;
}Pt2D;
int map[5][5];
int q[MAX], v[MAX];
int head, tail, st;
Pt2D op[MAX], r[MAX];
void init()
{
	char ch;
	int i, j;
	for(i = 1;i <= 4; i++)
	{
		for(j = 1;j <= 4; j++)
		{
			ch = getchar();
			if(ch == '-') map[i][j] = 1;
			else map[i][j] = 0;
		}
		getchar();
	}
}
int map_to_stat()
{
	int res, i, j;
	res = 0;
	for(i = 1;i <= 4; i++)
	{
		for(j = 1;j <= 4; j++)
		{
			res <<= 1;
			res += map[i][j];
		}
	}
	return res;
}
void stat_to_map(int stat)
{
	int i, j;
	for(i = 4;i >= 1; i--)
	{
		for(j = 4;j >= 1; j--)
		{
			map[i][j] = stat & 1;
			stat >>= 1;
		}
	}
}
void change(int x, int y)
{
	int i, j;
	map[x][y] = !map[x][y];
	for(i = 1;i <= 4; i++)
	{
		if(i != x) map[i][y] = !map[i][y];
		if(i != y) map[x][i] = !map[x][i];
	}
}
void debug(int stat)
{
	int i, j;
	stat_to_map(stat);
	for(i = 1;i <= 4; i++)
	{
		for(j = 1;j <= 4; j++)
			printf("%d ", map[i][j]);
		printf("\n");
	}
	printf("\n");
}
int bfs(int start)
{
	int stat, i, j, k;
	CLS(v);
	q[0] = start;
	head = 0;
	tail = 1;
	v[start] = start;
	while(head < tail)
	{
		stat = q[head];
		for(i = 1;i <= 4; i++)
		{
			for(j = 1;j <= 4; j++)
			{
				stat_to_map(stat);
				change(i, j);
				k = map_to_stat();
				if(v[k] == -1)
				{
					q[tail++] = k;
					v[k] = stat;
					op[k].x = i;
					op[k].y = j;
				}
				if(k == 65535) return 1;
			}
		}
		head++;
	}
	return 0;
}
void findpath(int pre)
{
	int cnt = 0, i;
	r[cnt].x = op[pre].x;
	r[cnt].y = op[pre].y;
	cnt++;
	while(v[pre] != st)
	{
		r[cnt].x = op[v[pre]].x;
		r[cnt].y = op[v[pre]].y;
		pre = v[pre];
		cnt++;
	}
	printf("%d\n", cnt);
	for(i = cnt - 1;i >= 0; i--) printf("%d %d\n", r[i].x, r[i].y);
}
int main()
{
	int res;
	init();
	st = map_to_stat();
	res = bfs(st);
	if(res == 1) findpath(65535);
	return 0;
}
