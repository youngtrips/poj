#include <stdio.h>
#include <string.h>
#define MAX 26
int dx[8] = { -2, -2, -1, -1,  1,  1,  2,  2 };
int dy[8] = { -1,  1, -2,  2, -2,  2, -1,  1 };
char board[MAX][MAX], path[MAX * 2];
int flag, m, n;
void jump(int x, int y, int cnt)
{
	int i;
	flag |= (cnt == n * m);
	if(flag || x < 0 || x >= m || y < 0 || y >= n || board[x][y] == '1') return;
	path[cnt * 2] = 'A' + x;
	path[cnt * 2 + 1] = '1' + y;
	board[x][y] = '1';
	for(i = 0;i < 8; i++) jump(x + dx[i], y + dy[i], cnt + 1);
	board[x][y] = '0';
}
int main()
{
	int t, s, i, j;
	scanf("%d", &t);
	for(s = 1;s <= t; s++)
	{
		scanf("%d %d", &n, &m);
		memset(board, '0', sizeof(board));
		flag = 0;
		for(i = 0;i < m; i++)
			for(j = 0;j < n; j++) jump(i, j, 0);
		printf("Scenario #%d:\n", s);
		if(flag == 0) printf("impossible\n");
		else
		{
			for(i = 0;i < 2 * m * n - 1; i++) printf("%c", path[i]);
			printf("%c\n", path[i]);
		}
		printf("\n");
	}
	return 0;
}
