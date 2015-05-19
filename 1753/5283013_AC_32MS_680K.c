#include <stdio.h>
#include <string.h>
int board[5][5], dx[4] = {0, 1,  0, -1}, dy[4] = {1, 0, -1,  0};
int dis[65536], q[65536], head, tail;
int encode()
{
	int res = 0, i, j;
	for(i = 1;i <= 4; i++)
		for(j = 1;j <= 4; j++) res = res * 2 + board[i][j];
	return res;
}
void decode(int n)
{
	int i, j;
	memset(board, 0, sizeof(board));
	for(i = 4;i >= 1; i--)
		for(j = 4;j >= 1; j--)
		{
			board[i][j] = n & 1;
			n >>= 1;
		}
}
void init()
{
	char ch;
	int i, j;
	for(i = 1;i <= 4; i++)
	{
		for(j = 1;j <= 4; j++)
		{
			ch = getchar();
			if(ch == 'b') board[i][j] = 1;
			else board[i][j] = 0;
		}
		getchar();
	}
	memset(dis, -1, sizeof(dis));
	i = encode();
	q[0] = i;
	head = 0;
	tail = 1;
	dis[i] = 0;
}
void flip(int x, int y)
{
	int i;
	board[x][y] ^= 1;
	for(i = 0;i < 4; i++) board[x + dx[i]][y + dy[i]] ^= 1;
}
int bfs()
{
	int cur, tmp, i, j, k;
	if(q[0] == 0 || q[0] == 65535) return 0;
	while(head < tail)
	{
		cur = q[head];
		k = dis[cur];
		for(i = 1;i <= 4; i++)
		{
			for(j = 1;j <= 4; j++)
			{
				decode(cur);
				flip(i, j);
				tmp = encode();
				if(dis[tmp] == -1)
				{
					dis[tmp] = k + 1;
					if(tmp == 0 || tmp == 65535) return dis[tmp];
					q[tail++] = tmp;
				}
			}
		}
		head++;
	}
	return -1;
}
int main()
{
	int res;
	init();
	res = bfs();
	if(res == -1) printf("Impossible\n");
	else printf("%d\n", res);
	return 0;
}
