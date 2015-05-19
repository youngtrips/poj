#include <stdio.h>
#define MAXN 1002
int r[MAXN];
int n, t;
void init()
{
	int i;
	scanf("%d %d", &n, &t);
	for(i = 1;i <= n; i++) scanf("%d", &r[i]);
}
void solve()
{
	int maxj, max, d, p;
	int i, j, k;
	for(i = 1;i <= t; i++)
	{
		max = -1;
		for(j = 1;j <= n; j++)
		{
			if(max < r[j])
			{
				max = r[j];
				maxj = j;
			}
		}
		printf("%d\n", maxj);
		d = r[maxj] / (n - 1);
		p = r[maxj] % (n - 1);
		r[maxj] = 0;
		for(j = 1;j <= n; j++) if(j != maxj) r[j] += d;
		for(j = 1, k = 1;j <= p; j++, k++)
		{
			if(j == maxj) k++;
			r[k]++;
		}
	}
}
int main()
{
	init();
	solve();
	return 0;
}
