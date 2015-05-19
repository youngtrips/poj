#include <stdio.h>
int main()
{
	long long n, m, r;
	int i, t;
	scanf("%d", &t);
	for(i = 1;i <= t; i++)
	{
		scanf("%lld %lld", &n, &m);
		r = (n + m) * (m - n + 1) / 2;
		printf("Scenario #%d:\n", i);
		printf("%lld\n", r);
		printf("\n");
	}
	return 0;
}
