#include <stdio.h>
#define MAX 102
int a[MAX][MAX];
int b[MAX];
int n;
int max_sum(int n, int* x)
{
	int sum;
	int b;
	int i;
	sum = 0;
	b = 0;
	for(i = 1;i <= n; i++)
	{
		if(b > 0) b += x[i];
		else b = x[i];
		if(b > sum) sum = b;
	}
	return sum;
}
int max_sum2(int m, int n)
{
	int sum = 0;
	int max;
	int i;
	int j;
	int k;
	for(i = 1;i <= m; i++)
	{
		for(k = 1;k <= n; k++) b[k] = 0;
		for(j = i;j <= m; j++)
		{
			for(k = 1;k <= n; k++) b[k] += a[j][k];
			max = max_sum(n, b);
			if(max > sum) sum = max;
		}
	}
	return sum;
}
int main()
{
	int i, j;
	scanf("%d", &n);
	for(i = 1;i <= n; i++)
		for(j = 1;j <= n; j++) scanf("%d", &a[i][j]);
	printf("%d\n", max_sum2(n, n));
	return 0;
}
