#include <stdio.h>
#include <string.h>
#define MAX 9
char board[MAX][MAX];
char row[MAX];
char col[MAX];
int tot, n, k;
int init()
{
	int i, j;
	scanf("%d %d", &n, &k);
	if(n == -1 && k == -1) return 0;
	getchar();
	for(i = 1;i <= n; i++)
	{
		for(j = 1;j <= n; j++) board[i][j] = getchar();
		getchar();
	}
	memset(row, '0', sizeof(row));
	memset(col, '0', sizeof(col));
	tot = 0;
}
void dfs(int r, int k)
{
	int i;
	if(r > n) return;
	if(k <= 0) {tot++; return;}
	for(i = 1;i <= n; i++)
	{
		if(board[r][i] == '#' && row[r] == '0' && col[i] == '0')
		{
			row[r] = '1'; col[i] = '1';
			dfs(r, k - 1);
			row[r] = '0'; col[i] = '0';
		}
	}
	dfs(r + 1, k);
}
int main()
{
	while(init())
	{
		dfs(1, k);
		printf("%d\n", tot);
	}
	return 0;
}
