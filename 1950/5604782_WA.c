#include <stdio.h>
#include <string.h>
#define MAXN 18
char op[MAXN][MAXN];
char str[MAXN * 10];
int cnt, n;
void dfs(int dp, int sum, int pre)
{
	int tmp, i, j;
	if(dp == n)
	{
		str[dp] = '\0';
		if(sum == 0)
		{
			if(cnt < 20) strcpy(op[cnt], str);
			cnt++;
		}
		return;
	}
	str[dp - 1] = '+';
	dfs(dp + 1, sum + dp + 1, dp + 1);
	str[dp - 1] = '-';
	dfs(dp + 1, sum - dp - 1, dp + 1);
	str[dp - 1] = '.';
	if(dp + 1 >= 10) tmp = 100 * pre + dp + 1;
	else tmp = 10 * pre + dp + 1;
	i = dp - 1;
	while(str[i] == '.' && i >= 0) i--;
	if(i < 0) j = tmp;
	else if(str[i] == '+') j = sum + tmp - pre;
	else j = sum - tmp + pre;
	dfs(dp + 1, j, tmp);
}
int main()
{
	int i, j;
	scanf("%d", &n);
	cnt = 0;
	dfs(1, 1, 1);
	for(i = 0;i < cnt; i++)
	{
		if(i >= 20) break;
		for(j = 1;j < n; j++) printf("%d %c ", j, op[i][j-1]);
		printf("%d\n", j);
	}
	printf("%d\n", cnt);
	return 0;
}
