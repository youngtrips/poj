#include <stdio.h>
#include <string.h>

#define MAXN 3001

char buf[MAXN][MAXN];
char tpl[MAXN][MAXN];
int n;
int q;

void scale_one_level(char src[][MAXN], int n1, int n2, char dst[][MAXN])
{
	int ii;
	int jj;
	int i;
	int j;
	memset(dst, ' ', MAXN * MAXN);
	for(i = 0;i < n2; i += n1)
	{
		for(j = 0;j < n2; j += n1)
		{
			if(src[(i + 1) / n1][(j + 1) / n1] == ' ') continue;
			for(ii = 0;ii < n1; ii++)
				for(jj = 0;jj < n1; jj++)
					dst[i + ii][j + jj] = src[ii][jj];
		}
	}
}

void scale(char src[][MAXN], int n, int q, char dst[][MAXN])
{
	int n1 = n;
	int n2 = n * n;
	int i;
	if(q == 1)
	{
		for(i = 0;i < n; i++)
			puts(src[i]);
		return;
	}
	for(i = 1;i < q; i++)
	{
		if(i % 2 == 1)
			scale_one_level(src, n1, n2, dst);
		else
			scale_one_level(dst, n1, n2, src);
		n1 = n2;
		n2 *= n;
	}

	if(q % 2 == 0)
	{
		for(i = 0;i < n1; i++)
		{
			dst[i][n1] = '\0';
			printf("%s\n", dst[i]);
		}
	}
	else
	{
		for(i = 0;i < n1; i++)
		{
			src[i][n1] = '\0';
			printf("%s\n", src[i]);
		}
	}
}


int main()
{
	int i;
	while(scanf("%d", &n) != EOF)
	{
		if(n == 0) break;
		getchar();
		memset(tpl, ' ', MAXN * MAXN);
		for(i = 0;i < n; i++)
		{
			gets(tpl[i]);
		}
		scanf("%d", &q);
		if(q == 0)
			while(1);
		scale(tpl, n, q, buf);
	}
	return 0;
}
