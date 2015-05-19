#include <stdio.h>
#include <string.h>
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MAXN 102
short int m[5][5] = {{ 5, -1, -2, -1, -3}, {-1,  5, -3, -2, -4}, {-2, -3,  5, -2, -2}, {-1, -2, -2,  5, -1}, {-3, -4, -2, -1,  0}};
short int max[MAXN][MAXN];
short int la, lb;
char a[MAXN], b[MAXN];
int getp(char ch)
{
	switch(ch)
	{
		case 'A': return 0;
		case 'C': return 1;
		case 'G': return 2;
		case 'T': return 3;
		case '-': return 4;
	}
}
int main()
{
	int t, i, j;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d %s", &la, a+1);
		scanf("%d %s", &lb, b+1);
		memset(max, 0, sizeof(max));
		for(i = 1;i <= la; i++) max[i][0] = max[i-1][0] + m[getp(a[i])][getp('-')];
		for(j = 1;j <= lb; j++) max[0][j] = max[0][j-1] + m[getp('-')][getp(b[j])];
		for(i = 1;i <= la; i++)
		{
			for(j = 1;j <= lb; j++)
			{
				max[i][j] = MAX(max[i-1][j-1] + m[getp(a[i])][getp(b[j])], max[i][j-1] + m[getp('-')][getp(b[j])]);
				max[i][j] = MAX(max[i][j], max[i-1][j] + m[getp(a[i])][getp('-')]);
			}
		}
		printf("%d\n", max[la][lb]);
	}
	return 0;
}
