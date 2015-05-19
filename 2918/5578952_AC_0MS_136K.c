#include <stdio.h>
#include <string.h>
#define MAX 10
char board[MAX][MAX];
int stp[10][2] = {{1, 1}, {1, 4}, {1, 7}, {4, 1}, {4, 4}, {4, 7}, {7, 1}, {7, 4}, {7, 4}};
int pos[MAX][MAX];
int que[MAX * MAX * MAX][2];
int head, tail;
void init()
{
	int ii, jj, i, j, k;
	memset(pos, 0, sizeof(pos));
	getchar();
	head = 0; tail = 0;
	k = 0;
	for(i = 1;i <= 9; i++)
	{
		for(j = 1;j <= 9; j++)
		{
			board[i][j] = getchar() - '0';
			if(board[i][j] == 0)
			{
				que[tail][0] = i;
				que[tail][1] = j;
				tail++;
			}
		}
		getchar();
	}
	for(i = 1;i <= 9; i++)
	{
		for(j = 1;j <= 9; j++)
		{
			if((i - 1) % 3 == 0 && (j - 1) % 3 == 0)
			{
				for(ii = 0;ii < 3; ii++)
					for(jj = 0;jj < 3; jj++) pos[i+ii][j+jj] = k;
				k++;
			}
		}
	}
}
void solve()
{
	int flag[10], tot, stx, sty, i, j, k, x, y;
	while(head < tail)
	{
		x = que[head][0]; y = que[head++][1];
		memset(flag, 0, sizeof(flag));
		for(j = 1;j <= 9; j++)
		{
			if(board[x][j] == 0) flag[0]++;
			else flag[board[x][j]] = 1;
		}
		if(flag[0] == 1)
		{
			for(i = 1;i <= 9; i++) if(flag[i] == 0) break;
			board[x][y] = i;
			continue;
		}
		memset(flag, 0, sizeof(flag));
		for(i = 1;i <= 9; i++)
		{
			if(board[i][y] == 0) flag[0]++;
			else flag[board[i][y]] = 1;
		}
		if(flag[0] == 1)
		{
			for(i = 1;i <= 9; i++) if(flag[i] == 0) break;
			board[x][y] = i;
			continue;
		}
		memset(flag, 0, sizeof(flag));
		stx = stp[pos[x][y]][0]; sty = stp[pos[x][y]][1];
		for(i = 0;i < 3; i++)
		{
			for(j = 0;j < 3; j++)
			{
				if(board[stx + i][sty + j] == 0) flag[0]++;
				else flag[board[stx + i][sty + j]] = 1;
			}
		}
		if(flag[0] == 1)
		{
			for(i = 1;i <= 9; i++) if(flag[i] == 0) break;
			board[x][y] = i;
			continue;
		}
		que[tail][0] = x; que[tail++][1] = y;
	}
}
void output()
{
	int i, j;
	for(i = 1;i <= 9; i++)
	{
		for(j = 1;j <= 9; j++) printf("%d", board[i][j]);
		printf("\n");
	}
	printf("\n");
}
int main()
{
	int t,s = 1;
	scanf("%d", &t);
	while(t--)
	{
		init();
		solve();
		printf("Scenario #%d:\n", s++);
		output();
	}
	return 0;
}
