#include <stdio.h>
#include <string.h>
#define MAX 5
char board[MAX][MAX];
int max, n;
int init()
{
	int i, j;
	scanf("%d", &n);
	if(n == 0) return 0;
	memset(board, '0', sizeof(board));
	getchar();
	for(i = 1;i <= n; i++)
	{
		for(j = 1;j <= n; j++) if(getchar() == 'X') board[i][j] = 'w';
		getchar();
	}
	return 1;
}
int check(int x, int y)
{
	int i;
	for(i = x + 1;i <= n && board[i][y] != 'w'; i++) if(board[i][y] == '1') return 0;
	for(i = x - 1;i >= 1 && board[i][y] != 'w'; i--) if(board[i][y] == '1') return 0;
	for(i = y + 1;i <= n && board[x][i] != 'w'; i++) if(board[x][i] == '1') return 0;
	for(i = y - 1;i >= 1 && board[x][i] != 'w'; i--) if(board[x][i] == '1') return 0;
	return 1;
}
void dfs(int x, int y, int tot)
{
	if(tot > max) max = tot;
	if(x > n) return;
	if(y > n)
	{
		dfs(x + 1, 1, tot); 
		return;
	}
	if(board[x][y] == '0' && check(x, y))
	{
		board[x][y] = '1';
		dfs(x, y + 1, tot + 1);
		board[x][y] = '0';
	}
	dfs(x, y + 1, tot);
}
int main()
{
	while(init())
	{
		max = 0;
		dfs(1, 1, 0);
		printf("%d\n", max);
	}
	return 0;
}
