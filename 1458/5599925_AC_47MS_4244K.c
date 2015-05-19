#include <stdio.h>
#include <string.h>
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MAXN 1024
int max[MAXN][MAXN];
char a[MAXN], b[MAXN];
int main()
{
	int i, j;
	while(scanf("%s %s", a+1, b+1) != EOF)
	{
		memset(max, 0, sizeof(max));
		for(i = 1; a[i] != '\0'; i++)
		{
			for(j = 1; b[j] != '\0'; j++)
			{
				if(a[i] == b[j]) max[i][j] = max[i-1][j-1] + 1;
				else max[i][j] = MAX(max[i][j-1], max[i-1][j]);
			}
		}
		printf("%d\n", max[i-1][j-1]);
	}
	return 0;
}
