#include <stdio.h>
#define MAX 110
long long a[MAX][MAX];
long long b[MAX];
int n;
long long max_sum(int n, long long* x)
{
	long long sum;
	long long b;
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
long long max_sum2(int m, int n)
{
	long long sum = 0;
	long long max;
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
	long long ans;
	int i, j;
	scanf("%d", &n);
	for(i = 1;i <= n; i++)
		for(j = 1;j <= n; j++) scanf("%lld", &a[i][j]);
	ans = max_sum2(n, n);
	printf("%lld\n", ans);
	return 0;
}
