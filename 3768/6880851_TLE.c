#include <stdio.h>
#include <string.h>
#include <math.h>

#define MAXN 3000

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
	memset(buf, ' ', sizeof(buf));
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

int scale(char src[][MAXN], int n, int q, char dst[][MAXN])
{
	int n1 = n;
	int n2 = n * n;
	int i;
	if(q == 1)
	{
		memcpy(dst, src, MAXN * MAXN);
		return n;
	}
	for(i = 1;i < q; i++)
	{
		scale_one_level(src, n1, n2, dst);
		memcpy(src, dst, MAXN * MAXN);
		n1 = n2;
		n2 *= n;
	}
	return n1;
}


int main()
{
	int i;
	int j;
	while(scanf("%d", &n) != EOF)
	{
		if(n == 0) break;
		getchar();
		for(i = 0;i < n; i++)
		{
			for(j = 0;j < n; j++)
				tpl[i][j] = getchar();
			getchar();
		}
		scanf("%d", &q);
		n = scale(tpl, n, q, buf);
		for(i = 0;i < n; i++)
		{
			for(j = 0;j < n; j++)
				printf("%c", buf[i][j]);
			printf("\n");
		}
	}
	return 0;
}

