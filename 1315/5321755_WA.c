#include <stdio.h>
char board[5][5], map[5][5];
int  n;
int init()
{
	int i, j;
	scanf("%d", &n);
	if(n == 0) return 0;
	getchar();
	for(i = 1;i <= n; i++)
	{
		for(j = 1;j <= n; j++) board[i][j] = getchar();
		getchar();
	}
	return 1;
}
void init_map()
{
	int i, j;
	for(i = 1;i <= n; i++)
		for(j = 1;j <= n; j++) map[i][j] = board[i][j];
}
int check(int x, int y)
{
	int i, j;
	for(i = x + 1;i <= n && map[i][y] != 'X'; i++) if(map[i][y] == '1') return 0;
	for(i = x - 1;i >= 1 && map[i][y] != 'X'; i--) if(map[i][y] == '1') return 0;
	for(i = y + 1;i <= n && map[x][i] != 'X'; i++) if(map[x][i] == '1') return 0;
	for(i = y - 1;i >= 1 && map[x][i] != 'X'; i--) if(map[x][i] == '1') return 0;
	return 1;
}
int find(int x, int y)
{
	int cnt = 1, i, j;
	map[x][y] = '1';
	for(i = 1;i <= n; i++)
	{
		for(j = 1;j <= n; j++)
		{
			if(map[i][j] == '.' && check(i, j))
			{
				map[i][j] = '1';
				cnt++;
			}
		}
	}
	return cnt;
}

int search()
{
	int ans = 0, res;
	int i, j;
	for(i = 1;i <= n; i++)
	{
		for(j = 1;j <= n; j++)
		{
			if(board[i][j] == '.')
			{
				init_map();
				res = find(i, j);
				if(ans < res) ans = res;
			}
		}
	}
	return ans;
}
int main()
{
	while(init()) printf("%d\n", search());
	return 0;
}
