#include <stdio.h>
#define MAXN 102
char bitmap[MAXN][MAXN];
int n, m, r, c;
int init()
{
	int i, j;
	scanf("%d %d %d %d", &n, &m, &r, &c);
	if(n == 0 && m == 0 && r == 0 && c == 0) return 0;
	getchar();
	for(i = 1;i <= n; i++)
	{
		for(j = 1;j <= m; j++) bitmap[i][j] = getchar() - '0';
		getchar();
	}
	return 1;
}
void solve()
{
	int cnt, ii, jj, i, j;
	cnt = 0;
	for(i = 1;i + r <= n + 1; i++)
	{
		for(j = 1;j + c <= m + 1; j++)
		{
			if(bitmap[i][j] == 0) continue;
			cnt++;
			for(ii = 0;ii < r && ii + i <= n; ii++)
			{
				for(jj = 0;jj < c && jj + j <= m; jj++) bitmap[i+ii][j+jj] ^= 1;
			}
		}
	}
	for(i = 1;i <= n; i++)
	{
		for(j = 1;j <= m; j++) if(bitmap[i][j]) { cnt = -1; break;}
		if(cnt == -1) break;
	}
	printf("%d\n", cnt);
}
int main()
{
	while(init()) solve();
	return 0;
}
