#include <stdio.h>
#define MAX 1001
char map[MAX][MAX];
int dis[MAX][MAX];
int dx[4] = {0, -1,  0, 1};
int dy[4] = {1, 0, -1,  0};
int curx, cury, r, c;
int check(int x, int y)
{
	return (x >= 1 && x <= r && y >= 1 && y <= c);
}
int dir(char ch)
{
	switch(ch)
	{
		case 'E': return 0;
		case 'N': return 1;
		case 'W': return 2;
		case 'S': return 3;
	}
}
int init()
{
	int i, j;
	scanf("%d %d %d", &r, &c, &cury);
	if(r == 0 && c == 0 && cury == 0) return 0;
	curx = 1;
	getchar();
	for(i = 1;i <= r; i++)
	{
		for(j = 1;j <= c; j++)
		{
			map[i][j] = getchar();
			dis[i][j] = -1;
		}
		getchar();
	}
	return 1;
}
void run()
{
	int res, cnt, k;
	dis[curx][cury] = 0;
	cnt = 0;
	while(1)
	{
		k = dis[curx][cury];
		res = dir(map[curx][cury]);
		curx += dx[res];
		cury += dy[res];
		if(!check(curx, cury)) break;
		else
		{
			if(dis[curx][cury] != -1)
			{
				cnt = k - dis[curx][cury];
				break;
			}
			dis[curx][cury] = k + 1;
		}
	}
	if(cnt == 0) printf("%d step(s) to exit\n", k + 1);
	else printf("%d step(s) before a loop of %d step(s)\n", dis[curx][cury], cnt + 1);
}
int main()
{
	while(init()) run();
	return 0;
}
