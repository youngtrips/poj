#include <stdio.h>
#include <string.h>
#define MAXN 102
int flag[MAXN][MAXN];
int d[MAXN][MAXN];
int n;
char str[MAXN];
void find(int i, int j)
{
	if(i > j) return;
	if(i == j)
	{
		if(str[i] == '[' || str[i] == ']') printf("[]");
		else printf("()");
	}
	else if(flag[i][j] == -1)
	{
		printf("%c", str[i]);
		find(i+1, j-1);
		printf("%c", str[j]);
	}
	else
	{
		find(i, flag[i][j]);
		find(flag[i][j]+1, j);
	}
}
void bracket()
{
	int i, j, k, p;
	memset(flag, 0, sizeof(flag));
	memset(d, 0, sizeof(d));
	n = strlen(str);
	for(i = 0;i < n; i++) d[i][i] = 1;
	for(p = 1;p < n; p++)
	{
		for(i = 0;i < n - p; i++)
		{
			j = i + p;
			d[i][j] = 999999999;
			if((str[i] == '(' && str[j] == ')') || (str[i] == '[' && str[j] == ']'))
			{
				if(d[i][j] > d[i+1][j-1])
				{
					d[i][j] = d[i+1][j-1];
					flag[i][j] = -1;
				}
			}
			for(k = i;k < j; k++)
			{
				if(d[i][j] > d[i][k] + d[k+1][j])
				{
					d[i][j] = d[i][k] + d[k+1][j];
					flag[i][j] = k;
				}
			}		
		}
	}
}
int main()
{
	while(gets(str))
	{
		if(strlen(str) == 0) {printf("\n"); continue;}
		bracket();
		find(0, n-1);
		printf("\n");
	}
	return 0;
}
