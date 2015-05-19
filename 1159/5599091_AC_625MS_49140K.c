#include <stdio.h>
#include <string.h>
#define MIN(a,b) ((a)<(b)?(a):(b))
#define MAXN 5002
short int min[MAXN][MAXN];
char str[MAXN];
int n;
int main()
{
	int i, j;
	while(scanf("%d", &n) != EOF)
	{
		scanf("%s", str+1);
		memset(min, 0, sizeof(min));
		for(i = n;i >= 1; i--)
		{
			for(j = i;j <= n; j++)
			{
				if(str[i] == str[j]) min[i][j] = min[i+1][j-1];
				else min[i][j] = 1 + MIN(min[i+1][j], min[i][j-1]);
			}
		}
		printf("%d\n", min[1][n]);
	}
	return 0;
}
